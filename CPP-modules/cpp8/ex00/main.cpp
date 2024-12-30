#include "Easyfind.hpp"

int main() {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	int value = 3;
	for (int i = 0; i < vec.size(); i++) {
		std::cout << "Index: " << i << ", Value: " << vec[i] << std::endl;
	}
	try {
    	std::vector<int>::iterator result = easyfind(vec, value);
        std::cout << "Value " << value << " found at index: " << std::distance(vec.begin(), result) << std::endl;
	} catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
	}
	value = -4;
	try {
		std::vector<int>::iterator result = easyfind(vec, value);
		std::cout << "Value found at index: " << std::distance(vec.begin(), result) << std::endl;
	} catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
	}

	std::list<int> myList;
	myList.push_back(10);
	myList.push_back(20);
	myList.push_back(30);
	myList.push_back(40);
	myList.push_back(50);
	value = 30;
	int i = 0;
    for (std::list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
        std::cout << "Index: " << i++ << ", Value: " << *it << std::endl;
    }
	try {
        std::list<int>::iterator result2 = easyfind(myList, value);
        std::cout << "Value " << value << " found at index: " << std::distance(myList.begin(), result2) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
	value = 35;
	try {
		std::list<int>::iterator result2 = easyfind(myList, value);
        std::cout << "Value found at index: " << std::distance(myList.begin(), result2) << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
    return 0;
}