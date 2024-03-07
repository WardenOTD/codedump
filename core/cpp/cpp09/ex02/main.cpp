#include "PmergeMe.hpp"

bool	isNumber(string arv){
	if (arv.find_first_not_of("0123456789") == string::npos)
		return (true);
	else
		return (false);
}

int	main(int argc, char **argv){
	if (argc == 1){
		cout << "Error: provide list of numbers as seperate arguements" << endl;
		exit (1);
	}
	if (argc == 2){
		cout << "Error: only 1 number" << endl;
		exit (1);
	}

	string	arv;
	vector<int>	ori;	//original order of numbers passed into the program;;

	for	(int i = 1; i < argc; i++){
		arv = argv[i];
		if (isNumber(arv) == true)
			ori.push_back(std::stoi(arv));
		else{
			cout << "Error: invalid arguments" << endl;
			exit (1);
		}
	}

	PMM	pmm;
	pmm.insertNum(ori);
	pmm.runPMM();
	cout << endl;
	cout << "before :\t " << ori << endl;
	cout << "after  :\t " << pmm.pmmVector.getJohnson() << endl;
	cout << "Time to process a range of " << ori.size() << " using std::vector : "
		<< std::fixed << pmm.getTimeVec() << " µs" << endl;
	
	cout << endl << endl;

	cout << "before :\t " << ori << endl;
	cout << "after  :\t " << pmm.pmmList.getJohnson() << endl;
	cout << "Time to process a range of " << ori.size() << " using std::list : "
		<< std::fixed << pmm.getTimeLst() << " µs" << endl;
	cout << endl;
}