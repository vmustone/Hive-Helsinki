#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("Teppo", 2);
		Bureaucrat bureaucrat20("alice", 2);
        Form form("FormA", 2, 2);

        bureaucrat.signForm(form);
        std::cout << form << std::endl;
		bureaucrat20.signForm(form);
		std::cout << form << std::endl;
		Bureaucrat bureaucrat2("Matti", 150);
        Form form2("FormB", 150, 151);

        bureaucrat2.signForm(form2);
		std::cout << form2 << std::endl;

		Bureaucrat bureaucrat3("Seppo", 0);
		Form form3("FormC", 150, 120);

		bureaucrat3.signForm(form3);
		std::cout << form3 << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
