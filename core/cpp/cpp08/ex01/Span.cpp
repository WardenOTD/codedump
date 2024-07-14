#include "Span.hpp"

Span::Span(unsigned int N){
	cout << "constructor" << endl;
	setN(N);
}

Span::Span(const Span &a){
	cout << "copy constructor" << endl;
	this->N = a.getN();
	this->contain = a.getContain();
}

Span &Span::operator=(const Span &a){
	cout << "equal operator overload" << endl;
	this->N = a.getN();
	this->contain = a.getContain();
	return (*this);
}

Span::~Span(){
	cout << "destructor" << endl;
}


void	Span::addNumber(unsigned int i){
	if (contain.size() >= N)
		throw Full();
	contain.push_back(i);
}

void	Span::addMoreNumber(std::vector<unsigned int> input){
	if (contain.size() + input.size() > N)
		throw Full();
	if (contain.empty() == false){
		// std::copy(input.begin(), input.end(), contain.end());

		for (std::vector<unsigned int>::iterator i = input.begin(); i < input.end(); i++){
			contain.push_back(*i);
		}
	}
	else{
		// contain.push_back(*input.begin());
		// std::copy(input.begin() + 1, input.end(), contain.end());

		for (std::vector<unsigned int>::iterator i = input.begin(); i < input.end(); i++){
			contain.push_back(*i);
		}
	}

	// for (std::vector<int>::iterator i = input.begin(); i < input.end(); i++){
	// 	cout << "input: " << *i << endl;
	// }
	// for (std::vector<int>::iterator i = contain.begin(); i < contain.end(); i++){
	// 	cout << "contain: " << *i << endl;
	// }
}

int	Span::shortestSpan(){
	if (contain.size() <= 1)
		throw NoSpan();

	std::sort(contain.begin(), contain.end());
	std::vector<int> diff;
	for (std::vector<unsigned int>::iterator i = contain.begin(); i < (contain.end() - 1); i++){
		(*i > *(i + 1)) ? diff.push_back((*i - *(i + 1))) : diff.push_back((*(i + 1) - *i));
	}
	return (*std::min_element(diff.begin(), diff.end()));
}

int	Span::longestSpan(){
	if (contain.size() <= 1)
		throw NoSpan();

	std::sort(contain.begin(), contain.end());
	return (*(contain.rbegin()) - *(contain.begin()));
}


unsigned int	Span::getN() const{
	return (this->N);
}

void	Span::setN(unsigned int N){
	this->N = N;
}

std::vector<unsigned int>	Span::getContain() const{
	return (this->contain);
}

void	Span::setContain(std::vector<unsigned int> contain){
	std::copy(contain.begin(), contain.end(), this->contain.begin());
}
