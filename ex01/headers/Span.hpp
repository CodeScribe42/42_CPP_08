#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <ctime>
# include <limits>
# include <algorithm>
# include <vector>

class Span
{
	private:
		std::vector<int> numbers;
		unsigned int max;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& obj);
		Span& operator=(const Span& other);
		~Span();
		void addNumber(int nb);
		void addNumbers(int nb);
		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);
		bool isSorted(void);

		class MaxAlreadyReached : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class TooFewElements : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif