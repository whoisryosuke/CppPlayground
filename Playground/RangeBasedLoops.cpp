#pragma once
#include <vector>
#include <iostream>


/// Example of Range Based Loops (aka for loops using "ranges" like vectors)
class RangeBasedLoops {
private:
	std::vector<int> getRates() { return std::vector<int> {1, 1, 2, 3, 5, 8, 13}; }

public:

	void Example() {
		auto rates = getRates();
		for (int rate : rates) {
			std::cout << rate << '\n';
		}
		for (int& rate : rates)
		{
			rate *= 2;
		}
	};
};