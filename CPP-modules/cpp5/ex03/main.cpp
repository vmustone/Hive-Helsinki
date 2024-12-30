#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    {
        Intern  someRandomIntern;
		Bureaucrat matti("Matti", 2);
        AForm*   rrf;

        rrf = someRandomIntern.makeForm("robotomy", "Bender");
		if (rrf != nullptr)
			delete rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf != nullptr) {
			matti.signAForm(*rrf);
			matti.executeForm(*rrf);
			delete rrf;
		}
    }
    return 0;
}