#pragma once
#include <vector>
class SortTestBace
{
public:
	virtual void Action(std::vector<int> arr) = 0;
	void PrintArr(std::vector<int> arr)
	{
		for (int i : arr)
		{
			std::cout << i << " ";
		}
	}
	void SwapValue(int& a, int& b)
	{
		int temp;
		temp = a;
		a = b;
		b = temp;
	}
};
