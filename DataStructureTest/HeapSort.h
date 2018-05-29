#pragma once
#include <iostream>
#include <vector>
#include "SortTestBace.h"

class HeapSort : public SortTestBace
{
public:
	void Sort(std::vector<int> arr)
	{
		
	}

	void Action(std::vector<int> arr) override
	{
		std::cout << "HeapSort" << std::endl;
		Sort(arr);
		PrintArr(arr);
	}
};