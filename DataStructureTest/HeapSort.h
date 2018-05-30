#pragma once
#include <iostream>
#include <vector>
#include "Heap.h"
#include "SortTestBace.h"

class HeapSort : public SortTestBace
{
public:
	void Sort(std::vector<int>& arr)
	{
		Heap<int> heap(arr);
		heap.Heapify();
		for (size_t i = 0; i < arr.size(); i++)
		{
			heap.SwapValue(0, (arr.size() - 1) - i);
			heap.SiftDown(0, arr.size() - i );
		}
		arr = heap.GetDataArr();
	}

	void Action(std::vector<int> arr) override
	{
		std::cout << "HeapSort" << std::endl;
		Sort(arr);
		PrintArr(arr);
	}
};