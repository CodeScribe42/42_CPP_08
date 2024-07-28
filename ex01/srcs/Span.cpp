#include "../headers/Span.hpp"

Span::Span() : max(5)
{
	std::cout << "Span default constructor called." << std::endl;
}

Span::Span(unsigned int N) : max(N)
{
	std::cout << "Span constructor called." << std::endl;
}

Span::Span(const Span& obj)
{
	std::cout << "Span copy constructor called." << std::endl;
	*this = obj;
}

Span& Span::operator=(const Span& other)
{
	std::cout << "Span assignment operator called." << std::endl;
	if (this != &other)
	{
		numbers = other.numbers;
		max = other.max;
	}
	return (*this);
}

Span::~Span()
{
	std::cout << "Span destructor called." << std::endl;
}

void Span::addNumber(int nb)
{
	if (numbers.size() == max)
		throw MaxAlreadyReached();
	else
		numbers.push_back(nb);
}

void Span::addNumbers(int nb)
{
	try
	{
		for (int i = 0 ; i < nb ; i++)
			addNumber(std::rand());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

unsigned int Span::longestSpan(void)
{
	if (numbers.size() >= 2)
	{
		if (!isSorted())
			std::sort(numbers.begin(), numbers.end());
		return (numbers.back() - numbers.front());
	}
	else
		throw TooFewElements();
}

unsigned int Span::shortestSpan(void)
{
	std::vector<int>::iterator it;
	int min, last;

	if (numbers.size() >= 2)
	{
		if (!isSorted())
			std::sort(numbers.begin(), numbers.end());
		if (numbers.size() == 2)
			return (numbers.back() - numbers.front());
		min = *(numbers.begin() + 1) - numbers.front();
		last = *(numbers.begin() + 1);
		for (it = numbers.begin() + 2 ; it != numbers.end() ; it++)
		{
			if ((*it - last) < min)
				min = *it - last;
			last = *it;
		}
		return (min);
	}
	else 
		throw TooFewElements();
}

bool Span::isSorted(void)
{
	if (numbers.size() < 2)
		return (true);

	std::vector<int>::iterator it1, it2;

	for (it1 = numbers.begin() ; it1 != numbers.end() - 1 ; it1++)
	{
		for (it2 = it1 + 1 ; it2 != numbers.end(); it2++)
		{
			if (*it1 > *it2)
				return (false);
		}
	}
	return (true);
}

const char* Span::MaxAlreadyReached::what() const throw()
{
	return ("Maximum of numbers already reached.");
}

const char* Span::TooFewElements::what() const throw()
{
	return ("Too few elements in the container to determine the span.");
}
