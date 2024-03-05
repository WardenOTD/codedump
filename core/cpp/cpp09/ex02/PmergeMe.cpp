#include "PmergeMe.hpp"

//PMM class;;
//
PMM::PMM(){
	cout << "PMM class constructor" << endl;
}

PMM::PMM(const PMM &a){
	cout << "PMM class copy constructor" << endl;
	*this = a;
}

PMM &PMM::operator=(const PMM &a){
	cout << "PMM class equal operator overload" << endl;
	*this = a;
	return (*this);
}

PMM::~PMM(){
	cout << "PMM class destructor" << endl;
}

void	PMM::insertNum(vector<int> num){
	vector<int>::iterator	itr;
	for (itr = num.begin(); itr < num.end(); ++itr){
		pmmVector.setJohnson(*itr);
		pmmList.setJohnson(*itr);
	}
}

double	PMM::getTimeVec(){
	return (timeTaken_vec);
}

double	PMM::getTimeLst(){
	return (timeTaken_lst);
}

void	PMM::setTimeVec(double time){
	timeTaken_vec = time;
}

void	PMM::setTimeLst(double time){
	timeTaken_lst = time;
}

void	PMM::runPMM(){
	gettimeofday(&start, NULL);
	//run vec
	gettimeofday(&end, NULL);
	setTimeVec((end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec));

	gettimeofday(&start, NULL);
	//run lst
	gettimeofday(&end, NULL);
	setTimeLst((end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec));
}

//operator<< overloads
//
std::ostream &operator<<(std::ostream &out, const PMM::PmergeVector &vect){
	vector<pair<int, int>> ptmp = vect.getPairJohnson();
	vector<int> tmp = vect.getJohnson();

	vector<pair<int, int>>::iterator pitr = ptmp.begin();
	vector<int>::iterator itr = tmp.begin();

	for (; pitr < ptmp.end(); pitr++){
		out << " [ " << pitr->first << " , " << pitr->second << " ] " << endl;
	}
	for (; itr < tmp.end(); itr++){
		out << *itr << endl;
	}
	return (out);
}

std::ostream &operator<<(std::ostream &out, const PMM::PmergeList &lis){
	list<pair<int, int>> ptmp = lis.getPairJohnson();
	list<int> tmp = lis.getJohnson();

	list<pair<int, int>>::iterator pitr = ptmp.begin();
	list<int>::iterator itr = tmp.begin();

	for (; pitr != ptmp.end(); pitr++){
		out << " [ " << pitr->first << " , " << pitr->second << " ] " << endl;
	}
	for (; itr != tmp.end(); itr++){
		out << *itr << endl;
	}
	return (out);
}

// n'th Jacobsthal number finder...
// 0, 1, 1, 3, 5, 11, 21, 43, ...
// 0 = 0, 1 = 1, 2 = 1, 3 = 3, 4 = 5, ...
int Jacobsthal(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	return (Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2));
}

//PmergeVector class;;
//
PMM::PmergeVector::PmergeVector(){
	cout << "Vector class constructor" << endl;
}

PMM::PmergeVector::PmergeVector(const PmergeVector &a){
	cout << "Vector class copy constructor" << endl;
	this->Johnson = a.getJohnson();
	this->pairJohnson = a.getPairJohnson();
	this->itr = a.itr;
	this->pitr = a.pitr;
	this->oddeven = a.oddeven;
	this->straggler = a.straggler;
}

PMM::PmergeVector &PMM::PmergeVector::operator=(const PmergeVector &a){
	cout << "Vector class equal operator overload" << endl;
	this->Johnson = a.getJohnson();
	this->pairJohnson = a.getPairJohnson();
	this->itr = a.itr;
	this->pitr = a.pitr;
	this->oddeven = a.oddeven;
	this->straggler = a.straggler;
	return (*this);
}

PMM::PmergeVector::~PmergeVector(){
	cout << "Vector class destructor" << endl;
}

//others
vector<pair<int, int>>	PMM::PmergeVector::getPairJohnson() const{
	return (pairJohnson);
}

void		PMM::PmergeVector::setPairJohnson(int num1, int num2){
	pairJohnson.push_back(pair<int, int> {num1, num2});
}

vector<int>	PMM::PmergeVector::getJohnson() const{
	return (Johnson);
}

void		PMM::PmergeVector::setJohnson(int num){
	Johnson.push_back(num);
}

void		PMM::PmergeVector::createPairs(){
	int	num1 = 0, num2 = 0;

	for (itr = Johnson.begin(); itr != Johnson.end(); itr++){
		num1 = *itr;
		itr++;
		if (itr == Johnson.end()){
			oddeven = true;
			straggler = num1;
			break ;
		}
		num2 = *itr;
		setPairJohnson(num1, num2);
	}
}

void		PMM::PmergeVector::recurSortPair(){
	vector<pair<int, int>>::iterator tmp = pitr;
	int	num1 = pitr->first;
	int num2 = pitr->second;
	pitr++;
	if (num2 > pitr->second){
		tmp->first = pitr->first;
		tmp->second = pitr->second;
		pitr->first = num1;
		pitr->second = num2;
	}
	if (pitr == pairJohnson.end()){
		if (checkPairSort())
			return ;
		else
			pitr = pairJohnson.begin();
	}
	recurSortPair();
}

bool		PMM::PmergeVector::checkPairSort(){
	vector<pair<int, int>>::iterator tmp = pairJohnson.begin();
	while (tmp < pairJohnson.end()){
		int	num = tmp->second;
		tmp++;
		if (num > tmp->second)
			return (false);
	}
	return (true);
}

void		PMM::PmergeVector::runVec(){
	//split vector into pairs
	createPairs();

	//sorting the individual pairs
	for (pitr = pairJohnson.begin(); pitr != pairJohnson.end(); pitr++){
		int num1 = pitr->first;
		if (num1 > pitr->second){
			pitr->first = pitr->second;
			pitr->second = num1;
		}
	}

	//recursive sorting of all the pairs by the larger number (  itr->second  )
	pitr = pairJohnson.begin();
	recurSortPair();

	//splitting the pairs into 2 seperate vectors
	//first containing all smaller numbers (  itr->first  )
	//second containing all larger numbers (  itr->second  )
	//larger vector is also the "return value" meaning work will be done on it
	vector<int>big, small;
	for (pitr = pairJohnson.begin(); pitr != pairJohnson.end(); pitr++){
		big.push_back(pitr->second);
		small.push_back(pitr->first);
	}

	
}

//PmergeList class;;
//
PMM::PmergeList::PmergeList(){
	cout << "List class constructor" << endl;
}

PMM::PmergeList::PmergeList(const PmergeList &a){
	cout << "List class copy constructor" << endl;
	this->Johnson = a.getJohnson();
	this->pairJohnson = a.getPairJohnson();
	this->itr = a.itr;
	this->pitr = a.pitr;
	this->oddeven = a.oddeven;
	this->straggler = a.straggler;
}

PMM::PmergeList &PMM::PmergeList::operator=(const PmergeList &a){
	cout << "List class equal operator overload" << endl;
	this->Johnson = a.getJohnson();
	this->pairJohnson = a.getPairJohnson();
	this->itr = a.itr;
	this->pitr = a.pitr;
	this->oddeven = a.oddeven;
	this->straggler = a.straggler;
	return (*this);
}

PMM::PmergeList::~PmergeList(){
	cout << "List class destructor" << endl;
}

//others
list<pair<int, int>>	PMM::PmergeList::getPairJohnson() const{
	return (pairJohnson);
}

void		PMM::PmergeList::setPairJohnson(int num1, int num2){
	pairJohnson.push_back(pair<int, int> {num1, num2});
}

list<int>	PMM::PmergeList::getJohnson() const{
	return (Johnson);
}

void		PMM::PmergeList::setJohnson(int num){
	Johnson.push_back(num);
}