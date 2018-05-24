#pragma once
#include <iostream>
#include <vector>
#include "SortTestBace.h"

// ��������
// �ð����⵵ O(n^2)
// �������⵵ O(n)

class SelectionSort : public SortTestBace
{
public:
	void Sort(std::vector<int> arr)
	{
		int minimumValue; 
		int minimumIdx;
		for (int i = 0; i < arr.size() - 1; i++)
		{
			minimumValue = arr[i];
			minimumIdx = i;
			for (int j = i + 1; j < arr.size(); j++)
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