#pragma once
#include <iostream>
#include <vector>
#include "SortTestBace.h"

// ��������
// �ð����⵵ O(n^2)
// �������⵵ O(n)

class InsertionSort : public SortTestBace
{
public:
	void Sort(std::vector<int> arr)
	{
		for (int i = 0; i < arr.size() - 1; i++)
		{
			for (int j = i + 1; j > 0 && arr[j - 1] > arr[j]; j--)
			{
				SwapValue(arr[j], arr[j - 1]);
			}
		}

		PrintArr(arr);
	}

	void Action(std::vector<int> arr) override
	{
		std::cout << "InsertionSort" << std::endl;
		Sort(arr);
	}
};