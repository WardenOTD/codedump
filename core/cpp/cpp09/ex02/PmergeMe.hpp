#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <iterator>
# include <list>
# include <vector>
# include <utility>
# include <sys/time.h>
# include <algorithm>
# include <iomanip>

using std::cout;
using std::endl;
using std::string;
using std::list;
using std::vector;
using std::pair;

class	PMM{
	public:
		//occf
		PMM();
		PMM(const PMM &a);
		PMM &operator=(const PMM &a);
		~PMM();

		//others
		void	insertNum(vector<int> num);

		double	getTimeVec();
		double	getTimeLst();
		void	setTimeVec(double time);
		void	setTimeLst(double time);

		void	runPMM();

	private:
		struct timeval start;
		struct timeval end;
		double timeTaken_vec;
		double timeTaken_lst;

	public:
		class	PmergeVector{
			public:
				//occf
				PmergeVector();
				PmergeVector(const PmergeVector &a);
				PmergeVector &operator=(const PmergeVector &a);
				~PmergeVector();

				//others
				vector<pair<int, int> >	getPairJohnson() const;
				void		setPairJohnson(int num1, int num2);
				vector<int>	getJohnson() const;
				void		setJohnson(int num);
				void		createPairs();
				void		recurSortPair();
				bool		checkPairSort();
				// bool		checkSeen(vector<int> small);
				void		runVec();

			private:
				vector<pair<int, int> > pairJohnson;
				vector<pair<int, int> >::iterator pitr;
				vector<int> Johnson;
				vector<int>::iterator itr;
				bool	oddeven;
				int		straggler;
				// vector<int>	seen;
				
		}	pmmVector;

		class	PmergeList{
			public:
				//occf
				PmergeList();
				PmergeList(const PmergeList &a);
				PmergeList &operator=(const PmergeList &a);
				~PmergeList();

				//others
				list<pair<int, int> >	getPairJohnson() const;
				void		setPairJohnson(int num1, int num2);
				list<int>	getJohnson() const;
				void		setJohnson(int num);
				void		createPairs();
				void		recurSortPair();
				bool		checkPairSort();
				void		runLst();
			private:
				list<pair<int, int> > pairJohnson;
				list<pair<int, int> >::iterator pitr;
				list<int> Johnson;
				list<int>::iterator itr;
				bool	oddeven;
				int		straggler;
		}	pmmList;
};

int	Jacobsthal(int n);
std::ostream &operator<<(std::ostream &out, const PMM::PmergeVector &vect);
std::ostream &operator<<(std::ostream &out, const PMM::PmergeList &lis);
std::ostream &operator<<(std::ostream &out, vector<int> vect);
std::ostream &operator<<(std::ostream &out, list<int> lis);

#endif