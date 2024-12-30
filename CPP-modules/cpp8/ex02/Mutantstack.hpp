#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	private:
		MutantStack(const MutantStack &other);
		MutantStack& operator=(const MutantStack& other);
	public:
		typedef typename std::deque<T>::iterator iterator;
		MutantStack(){};
		~MutantStack(){};

	    iterator begin() { return this->c.begin(); }
	    iterator end() { return this->c.end(); }
};

#endif