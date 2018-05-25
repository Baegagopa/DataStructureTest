#pragma once
#include <iostream>
#include <vector>
#include "SortTestBace.h"

// 선택정렬
// 시간복잡도 O(n^2)
// 공간복잡도 O(n)

class SelectionSort : public SortTestBace
{
public:
	void Sort(std::vector<int> arr)
	{
		int minimumValue; 
		int minimumIdx;
		for (size_t i = 0; i < arr.size() - 1; i++)
		{
			minimumValue = arr[i];
			minimumIdx = i;
			for (size_t j = i + 1; j < arr.size(); j++)
			{
				if (minimumValue > arr[j])
				{
					minimumValue = arr[j];
					minimumIdx = j;
				}
			}
			SwapValue(arr[i], arr[minimumIdx]);
		}
		
		PrintArr(arr);
	}

	void Action(std::vector<int> arr) override
	{
		std::cout << "SelectionSort" << std::endl;
		Sort(arr);
	}
};