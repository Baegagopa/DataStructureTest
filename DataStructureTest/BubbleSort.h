#pragma once
#include <iostream>
#include <vector>
#include "SortTestBace.h"

// 버블정렬
// 시간복잡도 O(n^2)
// 공간복잡도 O(n)

class BubbleSort : public SortTestBace
{
public:
	void Sort(std::vector<int> arr)
	{
		for (size_t i = 0; i < arr.size()-1; i++)
		{
			for (size_t j = 0; j < arr.size()-1; j++)
			{
				if (arr[j] > arr[j+1])
				{
					SwapValue(arr[j], arr[j + 1]);
				}
			}
		}
		PrintArr(arr);
	}

	void Action(std::vector<int> arr) override
	{
		std::cout << "BubbleSort" << std::endl;
		Sort(arr);
	}
};