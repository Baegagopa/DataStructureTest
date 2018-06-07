#pragma once
#include <iostream>
#include <vector>
#include "DataStructureBace.h"
#include <assert.h>

template <typename T>
class HeapBace : public DataStructureBace
{
protected:
	std::vector<T> dataArr;
	int cnt;

public:
	HeapBace(std::vector<T> tempArr)
	{
		cnt = tempArr.size();
		dataArr = tempArr;
	}

	HeapBace(int size)
	{
		cnt = 0;
		dataArr.resize(size);
	}

	void SwapValue(T idxA, T idxB)
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

	void Delete()
	{
		SwapValue(0, --cnt);
		dataArr[cnt] = NULL;

		SiftDown(0);
	}

	std::vector<T>& GetDataArr() { return dataArr; }

	int Size() { return dataArr.size(); }

	void PrintAll() override
	{
		for (int i = 0; i < cnt; i++)
		{
			std::cout << dataArr[i] << " ";
		}
		std::cout << std::endl;
	}


	virtual void Add(T data) = 0;

	virtual void SiftDown(int idx, int UntilCheck) = 0;

protected:
	virtual void SiftDown(int idx) = 0;

private:
		HeapBace();
};

