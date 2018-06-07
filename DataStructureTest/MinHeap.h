#pragma once
#include "HeapBace.h"

template <typename T>
class MinHeap : public HeapBace<T>
{
public:
	MinHeap(std::vector<T> tempArr) : HeapBace<T>(tempArr) { this->Heapify(); }
	MinHeap(int size) : HeapBace<T>(size) {}

	void Add(T data)
	{
		if ((int)this->dataArr.size() <= this->cnt)
			assert(!"overflow");

		int idx = this->cnt++;
		this->dataArr[idx] = data;

		int parentIdx = (idx - 1) / 2;
		while (this->dataArr[idx] < this->dataArr[parentIdx])
		{
			this->SwapValue(idx, parentIdx);
			idx = parentIdx;
			parentIdx = (idx - 1) / 2;
		}
		
	}

	void SiftDown(int idx, int UntilCheck) override
	{
		int l = idx * 2 + 1;
		int r = l + 1;
		int min = idx;
		if (l < UntilCheck - 1 && this->dataArr[l] < this->dataArr[idx])
			min = l;
		if (r < UntilCheck - 1 && this->dataArr[r] < this->dataArr[min])
			min = r;
		if (min != idx)
		{
			this->SwapValue(idx, min);
			SiftDown(min, UntilCheck);
		}
	}

protected:
	void SiftDown(int idx)
	{
		int l = idx * 2 + 1;
		int r = l + 1;
		int min = idx;
		if (l <= this->cnt - 1 && this->dataArr[l] < this->dataArr[idx])
			min = l;
		if (r <= this->cnt - 1 && this->dataArr[r] < this->dataArr[min])
			min = r;
		if (min != idx)
		{
			this->SwapValue(idx, min);
			SiftDown(min);
		}
	}

};