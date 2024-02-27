#include "Bureaucrat.hpp"

int	main(){
	cout << "initial test" << endl << endl;
	try{
		Bureaucrat *bozo = new Bureaucrat("Bozo", 135);
		cout << "bozo created" << endl;
		cout << *bozo << endl;
		bozo->increment();
		cout << *bozo << endl;
		bozo->decrement();
		cout << *bozo << endl;
		delete bozo;
	}
	catch (const std::exception& e){
		std::cerr << e.what() << endl;
	}
	cout << endl << "min max test" << endl << endl;
	try{
		Bureaucrat *buzu = new Bureaucrat("Buzu", 135);
		cout << "buzu created" << endl;
		cout << *buzu << endl;
		for (int i = 134; i > 0; --i){
			buzu->increment();
			//cout << *buzu << endl;
		}
		cout << *buzu << endl;
		for (int i = 1; i < 150; ++i){
			buzu->decrement();
			//cout << *buzu << endl;
		}
		cout << *buzu << endl;
		delete buzu;
	}
	catch (const std::exception& e){
		std::cerr << e.what() << endl;
	}
	cout << endl << "high test" << endl << endl;
	try{
		Bureaucrat *bizi = new Bureaucrat("Bizi", 1);
		cout << "bizi created" << endl;
		cout << *bizi << endl;
		bizi->increment();
		cout << *bizi << endl;
		delete bizi;
	}
	catch (const std::exception& e){
		std::cerr << e.what() << endl;
	}
	cout << endl << "low test" << endl << endl;
	try{
		Bureaucrat *beze = new Bureaucrat("Beze", 150);
		cout << "beze created" << endl;
		cout << *beze << endl;
		beze->decrement();
		cout << *beze << endl;
		delete beze;
	}
	catch (const std::exception& e){
		std::cerr << e.what() << endl;
	}
	//ex01
	cout << endl << "ex01" << endl << endl;
	cout << endl << "initial test" << endl << endl;
	try{
		Bureaucrat *bozo = new Bureaucrat("Bozo", 135);
		cout << "bozo created" << endl;
		cout << *bozo << endl;
		Form *ab2 = new Form("ab2", 135, 150);
		cout << "form created" << endl;
		cout << *ab2 << endl;
		bozo->signForm(*bozo, *ab2);
		delete bozo;
	}
	catch (const std::exception& e){
		std::cerr << e.what() << endl;
	}
	cout << endl << "grade too low to sign" << endl << endl;
	try{
		Bureaucrat *bozo = new Bureaucrat("Bozo", 135);
		cout << "bozo created" << endl;
		cout << *bozo << endl;
		Form *ab2 = new Form("ab2", 134, 150);
		cout << "form created" << endl;
		cout << *ab2 << endl;
		bozo->signForm(*bozo, *ab2);
		delete bozo;
	}
	catch (const std::exception& e){
		std::cerr << e.what() << endl;
	}
	cout << endl << "already signed" << endl << endl;
	try{
		Bureaucrat *bozo = new Bureaucrat("Bozo", 135);
		cout << "bozo created" << endl;
		cout << *bozo << endl;
		Form *ab2 = new Form("ab2", 135, 150);
		cout << "form created" << endl;
		cout << *ab2 << endl;
		bozo->signForm(*bozo, *ab2);
		bozo->signForm(*bozo, *ab2);
		delete bozo;
	}
	catch (const std::exception& e){
		std::cerr << e.what() << endl;
	}
}