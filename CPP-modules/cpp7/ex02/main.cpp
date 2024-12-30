#include "Array.hpp"

int main() {
    std::cout << "Test construction with no parameter (empty array)" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;
	for (int i = 0; i < emptyArray.size(); i++) {
        std::cout << "Element at index " << i << ": " << emptyArray[i] << std::endl;
    }
	std::cout << std::endl;


    std::cout << "Test construction with an unsigned int n as a parameter" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
    Array<int> intArray(5);
    std::cout << "Initialized array size: " << intArray.size() << std::endl;
	for (int i = 0; i < intArray.size(); ++i) {
        std::cout << "Element at index " << i << ": " << intArray[i] << std::endl;
    }
	std::cout << std::endl;


    std::cout << "Test subscript operator and size function" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
    for (int i = 0; i < intArray.size(); ++i) {
        intArray[i] = i * 2;
        std::cout << "Element at index " << i << ": " << intArray[i] << std::endl;
    }
	std::cout << std::endl;


    std::cout << "Test copy construction and assignment operator" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
    Array<int> copyArray(intArray);
    std::cout << "Copied array size: " << copyArray.size() << std::endl;
	for (int i = 0; i < intArray.size(); ++i) {
        std::cout << "Element at index " << i << ": " << intArray[i] << std::endl;
    }
	std::cout << std::endl;


    std::cout << "Modify the original array and check if the copy remains unchanged" << std::endl;
	std::cout << "-----------------------------------------------------------------" << std::endl;
    intArray[0] = 100;
    std::cout << "Modified original array. Copy array first element: " << copyArray[0] << std::endl;
	for (int i = 0; i < copyArray.size(); ++i) {
        std::cout << "Element at index " << i << ": " << copyArray[i] << std::endl;
    }
	std::cout << std::endl;


	std::cout << "Test with strings" << std::endl;
	std::cout << "-----------------" << std::endl;
	Array<std::string> str(5);
	str[0] = "aaa";
	str[1] = "bbb";
	str[2] = "ccc";
	str[3] = "ddd";
	str[4] = "eee";

	for(int i = 0; i < 5; i++) {
		std::cout << "Element at index " << i << ": " << str[i] << std::endl;
	}
	std::cout << std::endl;


	std::cout << "Test with modifying last string" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	str[4] = "Hello World";
	for(int i = 0; i < 5; i++) {
		std::cout << "Element at index " << i << ": " << str[i] << std::endl;
	}
	std::cout << std::endl;


    std::cout << "Test exception handling for out-of-bounds access" << std::endl;
	std::cout << "------------------------------------------------" << std::endl;
    try {
        intArray[10] = 42;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}


/*
#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}
*/
