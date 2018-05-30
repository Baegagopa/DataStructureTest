#pragma once
#include <iostream>
#include <vector>
#include "DataStructureBace.h"
#include <assert.h>

template <typename T>
class Heap : public DataStructureBace
{
private:
	std::vector<T> dataArr;
	int cnt;

public:
	Heap(std::vector<T> tempArr)
	{
		cnt = tempArr.size();
		dataArr = tempArr;

		Heapify();
	}

	Heap(int size)
	{
		cnt = 0;
		dataArr.resize(size);
	}

	void SwapValue(int idxA, int idxB)
	{
		int temp;
		temp = dataArr[idxA];
		dataArr[idxA] = dataArr[idxB];
		dataArr[idxB] = temp;
	}

	void Heapify()
	{
		int idx = (cnt - 1) / 2;
		while (idx >= 0)
		{
			SiftDown(idx);
			idx--;
		}
	}

	void SiftDown(int idx, int UntilCheck)
	{
		int l = idx * 2 + 1;
		int r = l + 1;
		int max = idx;
		if (l < UntilCheck -1&& dataArr[l] > dataArr[idx])
			max = l;
		if (r < UntilCheck -1&& dataArr[r] > dataArr[max])
			max = r;
		if (max != idx)
		{
			SwapValue(idx, max);
			SiftDown(max, UntilCheck);
		}
	}

	void Add(int data) 
	{
		if (dataArr.size() <= cnt)
			assert(!"overflow");

		int idx = cnt++;
		dataArr[idx] = data;

		int parentIdx = (idx - 1) / 2;
		while (dataArr[idx] > dataArr[parentIdx])
		{
			SwapValue(idx, parentIdx);
			idx = parentIdx;
			parentIdx = (idx - 1) / 2;
		}
		
	}

	void Delete()
	{
		SwapValue(0, --cnt);
		dataArr[cnt] = NULL;

		SiftDown(0);
	}

	std::vector<T>& GetDataArr()
	{
		return dataArr;
	}

	int Size()
	{
		return dataArr.size();
	}

	void PrintAll() override
	{
		for (int i = 0; i < cnt; i++)
		{
			std::cout << dataArr[i] << " ";
		}
		std::cout << std::endl;
	}

private:
	Heap();

	void SiftDown(int idx)
	{
		int l = idx * 2 + 1;
		int r = l + 1;
		int max = idx;
		if (l <= cnt - 1 && dataArr[l] > dataArr[idx])
			max = l;
		if (r <= cnt - 1 && dataArr[r] > dataArr[max])
			max = r;
		if (max != idx)
		{
			SwapValue(idx, max);
			SiftDown(max);
		}
	}
};