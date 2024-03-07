#include "PmergeMe.hpp"

//PMM class;;
//
PMM::PMM(){
	cout << "PMM class constructor" << endl;
}

PMM::PMM(const PMM &a){
	cout << "PMM class copy constructor" << endl;
	this->pmmList = a.pmmList;
	this->pmmVector = a.pmmVector;
	this->start = a.start;
	this->end = a.end;
	this->timeTaken_vec = a.timeTaken_vec;
	this->timeTaken_lst = a.timeTaken_lst;
}

PMM &PMM::operator=(const PMM &a){
	cout << "PMM class equal operator overload" << endl;
	this->pmmList = a.pmmList;
	this->pmmVector = a.pmmVector;
	this->start = a.start;
	this->end = a.end;
	this->timeTaken_vec = a.timeTaken_vec;
	this->timeTaken_lst = a.timeTaken_lst;
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
	pmmVector.runVec();
	gettimeofday(&end, NULL);
	setTimeVec(((end.tv_sec - start.tv_sec) * 1000) + ((end.tv_usec - start.tv_usec) % 1000));

	gettimeofday(&start, NULL);
	pmmList.runLst();
	gettimeofday(&end, NULL);
	setTimeLst(((end.tv_sec - start.tv_sec) * 1000) + ((end.tv_usec - start.tv_usec) % 1000));
}

//operator<< overloads
//
std::ostream &operator<<(std::ostream &out, const PMM::PmergeVector &vect){
	vector<pair<int, int> > ptmp = vect.getPairJohnson();
	vector<int> tmp = vect.getJohnson();

	vector<pair<int, int> >::iterator pitr = ptmp.begin();
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
	list<pair<int, int> > ptmp = lis.getPairJohnson();
	list<int> tmp = lis.getJohnson();

	list<pair<int, int> >::iterator pitr = ptmp.begin();
	list<int>::iterator itr = tmp.begin();

	for (; pitr != ptmp.end(); pitr++){
		out << " [ " << pitr->first << " , " << pitr->second << " ] " << endl;
	}
	for (; itr != tmp.end(); itr++){
		out << *itr << endl;
	}
	return (out);
}

std::ostream &operator<<(std::ostream &out, vector<int> vect){
	vector<int>::iterator itr;
	for (itr = vect.begin(); itr != vect.end(); ++itr)
		out << *itr << " ";
	return (out);
}

std::ostream &operator<<(std::ostream &out, list<int> lis){
	list<int>::iterator itr;
	for (itr = lis.begin(); itr != lis.end(); ++itr)
		out << *itr << " ";
	return (out);
}

// n'th Jacobsthal number finder...
// 0, 1, 1, 3, 5, 11, 21, 43, ...
// 0 = 0, 1 = 1, 2 = 1, 4 = 3, 5 = 5, ...
int Jacobsthal(int n)
{
	int dp[n + 1];

	dp[0] = 0;
	if (n == 0)
		return dp[n];
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
		dp[i] = dp[i - 1] + 2 * dp[i - 2];

	return dp[n];
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
	// this->seen = a.seen;
}

PMM::PmergeVector &PMM::PmergeVector::operator=(const PmergeVector &a){
	cout << "Vector class equal operator overload" << endl;
	this->Johnson = a.getJohnson();
	this->pairJohnson = a.getPairJohnson();
	this->itr = a.itr;
	this->pitr = a.pitr;
	this->oddeven = a.oddeven;
	this->straggler = a.straggler;
	// this->seen = a.seen;
	return (*this);
}

PMM::PmergeVector::~PmergeVector(){
	cout << "Vector class destructor" << endl;
}

//others
vector<pair<int, int> >	PMM::PmergeVector::getPairJohnson() const{
	return (pairJohnson);
}

void		PMM::PmergeVector::setPairJohnson(int num1, int num2){
	pairJohnson.push_back(pair<int, int> (num1, num2));
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
	// vector<pair<int, int> >::iterator tmp = pitr;
	if (checkPairSort() == true)
		return ;
	int	num1 = pitr->first;
	int num2 = pitr->second;
	// cout << "pitr->second     : " << pitr->second << endl;
	pitr++;
	int num3 = pitr->first;
	int num4 = pitr->second;
	// cout << "pitr->second + 1 : " << pitr->second << endl;
	if (num2 > num4){
		pitr->first = num1;
		pitr->second = num2;
		(pitr - 1)->first = num3;
		(pitr - 1)->second = num4;
	}
	if (pitr == pairJohnson.end() - 1){
		if (checkPairSort() == true)
			return ;
		else
			pitr = pairJohnson.begin();
	}
	// cout << *this << endl;
	recurSortPair();
}

bool		PMM::PmergeVector::checkPairSort(){
	vector<pair<int, int> >::iterator tmp = pairJohnson.begin();
	while (tmp != pairJohnson.end()){
		int	num = tmp->second;
		tmp++;
		if (tmp == pairJohnson.end())
			break ;
		if (num > tmp->second){
			return (false);
		}
	}
	return (true);
}

//depreciated
// bool		PMM::PmergeVector::checkSeen(vector<int> small){
// 	if (seen.empty())
// 		return (false);
// 	vector<int> str;
// 	int	flag = 0;
// 	for (int size = (small.size() - 1); size >= 0; size--){
// 		str.push_back(size);
// 	}
// 	reverse(str.begin(), str.end());
// 	for (vector<int>::iterator i = seen.begin(); i < seen.end(); i++){
// 		if (std::binary_search(str.begin(), str.end(), *i) == false)
// 			return (false);
// 		flag++;
// 	}
// 	if (flag != (int)str.size())
// 		return (false);
// 	return (true);
// }

void		PMM::PmergeVector::runVec(){
	if (Johnson.size() == 2){
		vector<int>::iterator it = Johnson.begin();
		if (*it > *(it + 1)){
			int num = *it;
			*it = *(it + 1);
			*(it + 1) = num;
		}
		return ;
	}

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
	vector<int> big, small;

	for (pitr = pairJohnson.begin(); pitr != pairJohnson.end(); pitr++){
		big.push_back(pitr->second);
		small.push_back(pitr->first);
	}

	//push small[0] to big[0] because it will always be smaller than the smallest large number
	big.insert(big.begin(), small.front());
	small.erase(small.begin());

	//using jacobsthal numbers to determine which index to access
	//after operation, decrement by 1 and repeat
	//until reaching the previous jacobsthal number
	//go to the next jacobsthal number and repeat this process
	int	n = 1, jacob = Jacobsthal(n);

	//created a new vector to hold the sorted small vector
	vector<int> tmp;
	vector<int>::iterator sitr;

	while (true){
		sitr = small.begin();
		// if (checkSeen(small))
		// 	break ;
		if (tmp.size() == small.size())
			break ;
		if (jacob == Jacobsthal(n - 1)){
			jacob = Jacobsthal(++n);
			continue ;
		}
		if (jacob > (int)small.size()){
			jacob--;
			continue ;
		}
		std::advance(sitr, jacob - 1);
		tmp.push_back(*sitr);
		// seen.push_back((jacob - 1));
		jacob--;
	}

	//binary search to find where to insert sorted smaller numbers
	for (sitr = tmp.begin(); sitr < tmp.end(); ++sitr)
		big.insert(std::lower_bound(big.begin(), big.end(), *sitr), *sitr);

	//binary search to insert straggler if there is any
	if (oddeven == true)
		big.insert(std::lower_bound(big.begin(), big.end(), straggler), straggler);
	
	//clear and set Johnson ( my main vector ) with big, which has the sorted vector
	Johnson.clear();
	Johnson = big;
	return ;
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
list<pair<int, int> >	PMM::PmergeList::getPairJohnson() const{
	return (pairJohnson);
}

void		PMM::PmergeList::setPairJohnson(int num1, int num2){
	pairJohnson.push_back(pair<int, int> (num1, num2));
}

list<int>	PMM::PmergeList::getJohnson() const{
	return (Johnson);
}

void		PMM::PmergeList::setJohnson(int num){
	Johnson.push_back(num);
}

void		PMM::PmergeList::createPairs(){
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

void		PMM::PmergeList::recurSortPair(){
	if (checkPairSort() == true)
		return ;
	int	num1 = pitr->first;
	int num2 = pitr->second;
	pitr++;
	int num3 = pitr->first;
	int num4 = pitr->second;
	if (num2 > num4){
		pitr->first = num1;
		pitr->second = num2;
		--pitr;
		pitr->first = num3;
		pitr->second = num4;
	}
	++pitr;
	if (pitr == pairJohnson.end()){
		if (checkPairSort() == true)
			return ;
		else{
			pitr = pairJohnson.begin();
		}
	}
	else
		--pitr;
	recurSortPair();
}

bool		PMM::PmergeList::checkPairSort(){
	list<pair<int, int> >::iterator tmp = pairJohnson.begin();
	while (tmp != pairJohnson.end()){
		int	num = tmp->second;
		tmp++;
		if (tmp == pairJohnson.end())
			break ;
		if (num > tmp->second){
			return (false);
		}
	}
	return (true);
}

void		PMM::PmergeList::runLst(){
	if (Johnson.size() == 2){
		list<int>::iterator it = Johnson.begin();
		int num = *it++;
		if (num > *it){
			int num2 = *it;
			*it-- = num;
			*it = num2;
		}
		return ;
	}

	//split list into pairs
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
	//larger list is also the "return value" meaning work will be done on it
	list<int> big, small;

	for (pitr = pairJohnson.begin(); pitr != pairJohnson.end(); pitr++){
		big.push_back(pitr->second);
		small.push_back(pitr->first);
	}

	//push small[0] to big[0] because it will always be smaller than the smallest large number
	big.insert(big.begin(), small.front());
	small.erase(small.begin());

	//using jacobsthal numbers to determine which index to access
	//after operation, decrement by 1 and repeat
	//until reaching the previous jacobsthal number
	//go to the next jacobsthal number and repeat this process
	int	n = 1, jacob = Jacobsthal(n);

	//created a new list to hold the sorted small vector
	list<int> tmp;
	list<int>::iterator sitr;

	while (true){
		sitr = small.begin();
		if (tmp.size() == small.size())
			break ;
		if (jacob == Jacobsthal(n - 1)){
			jacob = Jacobsthal(++n);
			continue ;
		}
		if (jacob > (int)small.size()){
			jacob--;
			continue ;
		}
		std::advance(sitr, jacob - 1);
		tmp.push_back(*sitr);
		jacob--;
	}

	//binary search to find where to insert sorted smaller numbers
	for (sitr = tmp.begin(); sitr != tmp.end(); ++sitr)
		big.insert(std::lower_bound(big.begin(), big.end(), *sitr), *sitr);

	//binary search to insert straggler if there is any
	if (oddeven == true)
		big.insert(std::lower_bound(big.begin(), big.end(), straggler), straggler);
	
	//clear and set Johnson ( my main vector ) with big, which has the sorted vector
	Johnson.clear();
	Johnson = big;
	return ;
}