#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy Request Form", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& other) {
    ( void )other;
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (executor.getGrade() > this->getGradeExecute())
        throw AForm::GradeTooLowException();
    else {
		std::srand(std::time(0));
        if ((rand() % 2))
            std::cout << "BZZZZZT! " << _target << " has been robotomized!" << std::endl;
        else
            std::cout << "Robotomy failed!" << std::endl;
    }
}