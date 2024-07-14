#include "Span.hpp"

std::vector<unsigned int> ctos(char *argv){

	for (int i = 0; argv[i]; i++){
		if (!isdigit(argv[i]) && argv[i] != ' ')
			throw Invalid();
	}

	char	*ptr;
	std::vector<unsigned int> ret;
	ptr = strtok(argv, " ");
	while (ptr){
		ret.push_back(atoi(ptr));
		ptr = strtok(NULL, " ");
	}
	// for (std::vector<int>::iterator i = ret.begin(); i < ret.end(); i++){
	// 	cout << *i << endl;
	// }
	return (ret);
}

int main(int argc, char **argv){
	if (argc > 1){
		std::vector<unsigned int> user = ctos(argv[1]);
		Span span(user.size());
		// cout << "past construct" << endl;
		try{
			span.addMoreNumber(user);
			try{
				cout << "longest span : " << span.longestSpan() << endl;
			}
			catch (std::exception &e){
				cout << e.what() << endl;
			}
			try{
				cout << "shortest span : " << span.shortestSpan() << endl;
			}
			catch (std::exception &e){
				cout << e.what() << endl;
			}
		}
		catch (std::exception &e){
			cout << e.what() << endl;
		}
		try{
			span.addNumber(999999999);
		}
		catch (std::exception &e){
			cout << e.what() << endl;
		}

		cout << endl << "contain list: " << endl;
		for (std::vector<unsigned int>::iterator i = span.getContain().begin(); i < span.getContain().end(); i++){
			cout << *i << endl;
		}
		cout << endl;
	}

	else{
		char tmp[] = "10 9 8 7 6 5 4 3 2 1 0 987 876 765 654 543 432 321 210 100";
		std::vector<unsigned int> user = ctos(tmp);
		Span span(user.size() + 5);

		try{
			span.addMoreNumber(user);
			try{
				cout << "longest span : " << span.longestSpan() << endl;
			}
			catch (std::exception &e){
				cout << e.what() << endl;
			}
			try{
				cout << "shortest span : " << span.shortestSpan() << endl;
			}
			catch (std::exception &e){
				cout << e.what() << endl;
			}
		}
		catch (std::exception &e){
			cout << e.what() << endl;
		}
		try{
			char tmp[] = "11 12 13 14 15";
			std::vector<unsigned int> user = ctos(tmp);
			span.addMoreNumber(user);
			// span.addNumber(11);
			// span.addNumber(12);
			// span.addNumber(13);
			// span.addNumber(14);
			// span.addNumber(15);
			try{
				span.addNumber(16);
			}
			catch (std::exception &e){
				cout << e.what() << endl;
			}
		}
		catch (std::exception &e){
			cout << e.what() << endl;
		}

		cout << endl << "contain list: " << endl;
		for (std::vector<unsigned int>::iterator i = span.getContain().begin(); i < span.getContain().end(); i++){
			cout << *i << endl;
		}
		cout << endl;
	}

	return (1);
}
