#pragma once
#include <iostream>
#include <vector>
#include "DataStructureBace.h"
#include <assert.h>

template <typename T>
class Heap : public DataStructureBace
{
public:
	Heap(int size)
	{
		cnt = 0;
		dataArr = new T[size];
		this->size = size;
	}
	~Heap()
	{
		delete[] dataArr;
	}

	void SwapValue(int& a, int& b)
	{
		int temp;
		temp = a;
		a = b;
		b = temp;
	}


	void Add(int data) 
	{
		if (size <= cnt)
			assert(!"overflow");

		int idx = cnt++;
		dataArr[idx] = data;

		int parentIdx = (idx - 1) / 2;
		while (dataArr[idx] > dataArr[parentIdx]) {

			SwapValue(dataArr[idx], dataArr[parentIdx]);
			idx = parentIdx;
			parentIdx = (idx - 1) / 2;

		}

		PrintAll();
		
	}

	void Delete()
	{
		
		SwapValue(dataArr[0], dataArr[--cnt]);
		dataArr[cnt] = NULL;

		int idx = 0;
		int child = idx * 2 + 1;
		while (cnt >= idx * 2)
		{
			if (dataArr[idx] > dataArr[child] && dataArr[idx] > dataArr[child + 1])
				break;
			else if (dataArr[idx] < dataArr[child] && dataArr[idx] < dataArr[child + 1])
			{
				if (dataArr[child] > dataArr[child + 1])
					SwapValue(dataArr[idx], dataArr[child]);
				else
					SwapValue(dataArr[idx], dataArr[child + 1]);
			}
			else
			{
				if (dataArr[idx] < dataArr[child])
					SwapValue(dataArr[idx], dataArr[child]);
				else if (dataArr[idx] < dataArr[child + 1])
					SwapValue(dataArr[idx], dataArr[child + 1]);
				else
					break;
			}
			idx = idx * 2 + 1;
			child = idx * 2 + 1;
		}
	}

	std::vector<T> TransDataArrVector()
	{		
		std::vector<T> tempArr(cnt);
		memcpy(&tempArr[0], dataArr, sizeof(T) * cnt);
		return tempArr;
	}

	int Size()
	{
		return size;
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
	T * dataArr;
	int cnt;
	int size;
};