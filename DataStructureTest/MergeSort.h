#pragma once
#include <iostream>
#include <vector>
#include "SortTestBace.h"

// 삽입정렬
// 시간복잡도 O(n log n)
// 공간복잡도 O(n)

class MergeSort : public SortTestBace
{
public:

	void Division(std::vector<int>& arr, int start, int end)
	{
		if (start < end)
		{
			int mid = (start + end) / 2;
			Division(arr, start, mid);
			Division(arr, mid + 1, end);

			Merge(arr, start, mid, end);
		}
	}

	void Merge(std::vector<int>& arr, int start, int mid, int end)
	{
		int left = start;
		int right = mid + 1;
		int cur = 0;
		

		std::vector<int> tempArr;
		tempArr.resize(end - start + 1);
		while (left <= mid && right <= end)
		{
			if (arr[left] < arr[right])
				tempArr[cur++] = arr[left++];
			else
				tempArr[cur++] = arr[right++];
		}
		
		while (left <= mid)
			tempArr[cur++] = arr[left++];
		while (right <= end)
			tempArr[cur++] = arr[right++];

		cur = 0;
		for (int i = start; i <= end; i++)
			arr[i] = tempArr[cur++];

	}

	void Action(std::vector<int> arr) override
	{
		std::cout << "MergeSort" << std::endl;
		Division(arr, 0, arr.size()-1);
		PrintArr(arr);
	}
};