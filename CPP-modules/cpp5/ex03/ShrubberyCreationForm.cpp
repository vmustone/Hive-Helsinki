#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( ShrubberyCreationForm& other) {
    (void)other;
    return *this;
}

void    ShrubberyCreationForm::execute( const Bureaucrat& executor ) const {
    if ( this->getSigned() == false )
        throw AForm::FormNotSignedException();
    else if ( executor.getGrade() > this->getGradeExecute() ) {
        throw AForm::GradeTooLowException();
    }

    std::ofstream file(this->getName() + "_shrubbery");
    file <<	"      66       " << std::endl;
 	file <<	"     6  6      " << std::endl;
	file << "    6    6     " << std::endl;
	file << "   6   0  6    " << std::endl;
	file << "  6  0     6   " << std::endl;
	file << " 6       0  6  " << std::endl;
	file << "6____________6 " << std::endl;
	file << "     1111      " << std::endl;
 
    file.close();
}