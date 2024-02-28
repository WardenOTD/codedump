#include "Bureaucrat.hpp"

int	main(){
	AForm *Robotomy = new RobotomyRequestForm("Lobotomy");
	AForm *RoboTomy = new RobotomyRequestForm("Kaisen");
	AForm *Shrubbery = new ShrubberyCreationForm("HomeOwner");
	AForm *ShrubBery = new ShrubberyCreationForm("Association");
	AForm *President = new PresidentialPardonForm("GetDown");
	AForm *PresIdent = new PresidentialPardonForm("MrPresident");

	Bureaucrat *BAB = new Bureaucrat("BAB", 1);
	Bureaucrat *BEB = new Bureaucrat("BEB", 6);
	Bureaucrat *BIB = new Bureaucrat("BIB", 26);
	Bureaucrat *BOB = new Bureaucrat("BOB", 46);
	Bureaucrat *BUB = new Bureaucrat("BUB", 73);
	Bureaucrat *BHB = new Bureaucrat("BHB", 138);
	Bureaucrat *BLB = new Bureaucrat("BLB", 146);

	cout << endl << "Bureau" << endl;
	cout << BAB << endl << BEB << endl;
	cout << BIB << endl << BOB << endl;
	cout << BUB << endl << BHB << endl;
	cout << BLB << endl;

	cout << endl << "Form" << endl;
	cout << *Robotomy << endl << *RoboTomy << endl;
	cout << *Shrubbery << endl << *ShrubBery << endl;
	cout << *President << endl << *PresIdent << endl;
	cout << endl;

	cout << "BAB" << endl;
	cout << BAB << endl;
	BAB->signForm(*BAB, *Robotomy);
	BAB->signForm(*BAB, *RoboTomy);
	BAB->signForm(*BAB, *Shrubbery);
	BAB->signForm(*BAB, *ShrubBery);
	BAB->signForm(*BAB, *President);
	BAB->signForm(*BAB, *PresIdent);

	BAB->executeForm(*Robotomy);
	BAB->executeForm(*RoboTomy);
	BAB->executeForm(*Shrubbery);
	BAB->executeForm(*ShrubBery);
	BAB->executeForm(*President);
	BAB->executeForm(*PresIdent);

	delete BAB;

	cout << "BEB" << endl;
	cout << BEB << endl;
	BEB->signForm(*BEB, *Robotomy);
	BEB->signForm(*BEB, *RoboTomy);
	BEB->signForm(*BEB, *Shrubbery);
	BEB->signForm(*BEB, *ShrubBery);
	BEB->signForm(*BEB, *President);
	BEB->signForm(*BEB, *PresIdent);

	BEB->executeForm(*Robotomy);
	BEB->executeForm(*RoboTomy);
	BEB->executeForm(*Shrubbery);
	BEB->executeForm(*ShrubBery);
	BEB->executeForm(*President);
	BEB->executeForm(*PresIdent);

	delete BEB;

	cout << "BIB" << endl;
	cout << BIB << endl;
	BIB->signForm(*BIB, *Robotomy);
	BIB->signForm(*BIB, *RoboTomy);
	BIB->signForm(*BIB, *Shrubbery);
	BIB->signForm(*BIB, *ShrubBery);
	BIB->signForm(*BIB, *President);
	BIB->signForm(*BIB, *PresIdent);

	BIB->executeForm(*Robotomy);
	BIB->executeForm(*RoboTomy);
	BIB->executeForm(*Shrubbery);
	BIB->executeForm(*ShrubBery);
	BIB->executeForm(*President);
	BIB->executeForm(*PresIdent);

	delete BIB;

	cout << "BOB" << endl;
	cout << BOB << endl;
	BOB->signForm(*BOB, *Robotomy);
	BOB->signForm(*BOB, *RoboTomy);
	BOB->signForm(*BOB, *Shrubbery);
	BOB->signForm(*BOB, *ShrubBery);
	BOB->signForm(*BOB, *President);
	BOB->signForm(*BOB, *PresIdent);

	BOB->executeForm(*Robotomy);
	BOB->executeForm(*RoboTomy);
	BOB->executeForm(*Shrubbery);
	BOB->executeForm(*ShrubBery);
	BOB->executeForm(*President);
	BOB->executeForm(*PresIdent);

	delete BOB;

	cout << "BUB" << endl;
	cout << BUB << endl;
	BUB->signForm(*BUB, *Robotomy);
	BUB->signForm(*BUB, *RoboTomy);
	BUB->signForm(*BUB, *Shrubbery);
	BUB->signForm(*BUB, *ShrubBery);
	BUB->signForm(*BUB, *President);
	BUB->signForm(*BUB, *PresIdent);

	BUB->executeForm(*Robotomy);
	BUB->executeForm(*RoboTomy);
	BUB->executeForm(*Shrubbery);
	BUB->executeForm(*ShrubBery);
	BUB->executeForm(*President);
	BUB->executeForm(*PresIdent);

	delete BUB;

	cout << "BHB" << endl;
	cout << BHB << endl;
	BHB->signForm(*BHB, *Robotomy);
	BHB->signForm(*BHB, *RoboTomy);
	BHB->signForm(*BHB, *Shrubbery);
	BHB->signForm(*BHB, *ShrubBery);
	BHB->signForm(*BHB, *President);
	BHB->signForm(*BHB, *PresIdent);

	BHB->executeForm(*Robotomy);
	BHB->executeForm(*RoboTomy);
	BHB->executeForm(*Shrubbery);
	BHB->executeForm(*ShrubBery);
	BHB->executeForm(*President);
	BHB->executeForm(*PresIdent);

	delete BHB;

	cout << "BLB" << endl;
	cout << BLB << endl;
	BLB->signForm(*BLB, *Robotomy);
	BLB->signForm(*BLB, *RoboTomy);
	BLB->signForm(*BLB, *Shrubbery);
	BLB->signForm(*BLB, *ShrubBery);
	BLB->signForm(*BLB, *President);
	BLB->signForm(*BLB, *PresIdent);

	BLB->executeForm(*Robotomy);
	BLB->executeForm(*RoboTomy);
	BLB->executeForm(*Shrubbery);
	BLB->executeForm(*ShrubBery);
	BLB->executeForm(*President);
	BLB->executeForm(*PresIdent);

	delete BLB;

	cout << endl << "Form" << endl;
	cout << *Robotomy << endl << *RoboTomy << endl;
	cout << *Shrubbery << endl << *ShrubBery << endl;
	cout << *President << endl << *PresIdent << endl;
	cout << endl;

	delete Robotomy;
	delete RoboTomy;
	delete Shrubbery;
	delete ShrubBery;
	delete President;
	delete PresIdent;
}