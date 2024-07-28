#include "MutantStack.hpp"

int main(void)
{
	MutantStack<int>::iterator it, ite;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	it = mstack.begin();
	ite = mstack.end();	
	
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	//Use copy constructor
	MutantStack<int> cp1_mstack(mstack);

	it = cp1_mstack.begin();
	ite = cp1_mstack.end();
	
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	cp1_mstack.pop();

	//Use assignment operator
	MutantStack<int> cp2_mstack;

	cp2_mstack = cp1_mstack;
	it = cp2_mstack.begin();
	ite = cp2_mstack.end();
	
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	return 0;
}
