#pragma once
#include <iostream>
#include <vector>
#include "SortTestBace.h"

// 퀵정렬
// 시간복잡도 O(n log n), 정렬 상태일 때는 O(n^2)
// 공간복잡도 O(n)

class QuickSort : public SortTestBace
{
public:
	void Sort(std::vector<int>& arr, int start, int end)
	{
		if (start < end)
		{
			int pivot = Division(arr, start, end);
			Sort(arr, start, pivot - 1);
			Sort(arr, pivot + 1, end);
		}
	}

	int Division(std::vector<int>& arr,int start, int end)
	{
		int left = start;
		int wall = start;
		int pivot = end;

		while (left < pivot)
		{
			if (arr[left] < arr[pivot])
				SwapValue(arr[left], arr[wall++]);
			left++;
		}
		SwapValue(arr[left], arr[wall]);
		pivot = wall;
		return pivot;
	}

	void Action(std::vector<int> arr) override
	{
		std::cout << "QuickSort" << std::endl;
		Sort(arr,0,arr.size()-1);
		PrintArr(arr);
	}
};