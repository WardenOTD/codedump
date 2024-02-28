#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : target("Robotomy"){
	cout << "Home owners association" << endl;
	this->setname(target);
	this->setgradeSig(145);
	this->setgradeReq(137);
	this->setSign(false);
}

ShrubberyCreationForm::ShrubberyCreationForm(string target) : target(target){
	cout << "Home owners association at your house" << endl;
	this->setname(target);
	this->setgradeSig(145);
	this->setgradeReq(137);
	this->setSign(false);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &a){
	cout << "Association rebranding" << endl;
	this->target = a.target;
	this->setname(target);
	this->setgradeSig(145);
	this->setgradeReq(137);
	this->setSign(false);
}

ShrubberyCreationForm &ShrubberyCreationForm::operator= (const ShrubberyCreationForm &a){
	cout << "Same association, different name" << endl;
	if (this != &a)
		this->target = a.getTarget();
	this->setname(target);
	this->setgradeSig(145);
	this->setgradeReq(137);
	this->setSign(false);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	cout << "Association abolished" << endl;
}

string	ShrubberyCreationForm::getTarget() const{
	return (this->target);
}

void	ShrubberyCreationForm::smtg() const{
	std::ofstream	out;
	/*
	c_str() returns pointer to the string.
	(string(target).append("_shrubbery")).c_str()
	creates a string with <target>_shrubbery and returns the pointer to this string
	*/
	out.open((string(target).append("_shrubbery")).c_str(), std::ios::trunc | std::ios::out);
	/*
                     ; ; ;
                   ;        ;  ;     ;;    ;
                ;                 ;         ;  ;
                                ;
                               ;                ;;
               ;          ;            ;              ;
               ;            ';,        ;               ;
               ;              'b      *
                ;              '$    ;;                ;;
               ;    ;           $:   ;:               ;
             ;;      ;  ;;      *;  @):        ;   ; ;
                          ;     :@,@):   ,;**:'   ;
              ;      ;,         :@@*: ;;**'      ;   ;
                       ';o;    ;:(@';@*"'  ;
               ;  ;       'bq,;;:,@@*'   ,*      ;  ;
                          ,p$q8,:@)'  ;p*'      ;
                   ;     '  ; '@@Pp@@*'    ;  ;
                    ;  ; ;;    Y7'.'     ;  ;
                              :@):.
                             .:@:'.
                           .::(@:.
	*/
	/*
	 >>writes ASCII trees inside it<<
	 so im guessing i need a forest ?
	*/
	for (int i = 0; i < 6; i++){
		out << "                     ; ; ;\n                   ;        ;  ;     ;;    ;" << endl;
		out << "                ;                 ;         ;  ;\n                                ;" << endl;
		out << "                               ;                ;;\n               ;          ;            ;              ;" << endl;
		out << "               ;            ';,        ;               ;\n               ;              'b      *" << endl;
		out << "                ;              '$    ;;                ;;\n               ;    ;           $:   ;:               ;" << endl;
		out << "             ;;      ;  ;;      *;  @):        ;   ; ;\n                          ;     :@,@):   ,;**:'   ;" << endl;
		out << "              ;      ;,         :@@*: ;;**'      ;   ;\n                       ';o;    ;:(@';@*\"'  ;" << endl;
		out << "               ;  ;       'bq,;;:,@@*'   ,*      ;  ;\n                          ,p$q8,:@)'  ;p*'      ;" << endl;
		out << "                   ;     '  ; '@@Pp@@*'    ;  ;\n                    ;  ; ;;    Y7'.'     ;  ;" << endl;
		out << "                              :@):.\n                             .:@:'." << endl;
		out << "                           .::(@:." << endl << endl << endl;
	}
}	
