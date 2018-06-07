#pragma once
#include "HeapBace.h"

template <typename T>
class MaxHeap : public HeapBace<T>
{
public:
	MaxHeap(std::vector<T> tempArr) : HeapBace<T>(tempArr) { this->Heapify(); }
	MaxHeap(int size) : HeapBace<T>(size) {}

	void Add(T data)
	{
		if ((int)this->dataArr.size() <= this->cnt)
			assert(!"overflow");

		int idx = this->cnt++;
		this->dataArr[idx] = data;

		int parentIdx = (idx - 1) / 2;
		while (this->dataArr[idx] > this->dataArr[parentIdx])
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
		int max = idx;
		if (l < UntilCheck - 1 && this->dataArr[l] > this->dataArr[idx])
			max = l;
		if (r < UntilCheck - 1 && this->dataArr[r] > this->dataArr[max])
			max = r;
		if (max != idx)
		{
			this->SwapValue(idx, max);
			SiftDown(max, UntilCheck);
		}
	}

protected:
	void SiftDown(int idx)
	{
		int l = idx * 2 + 1;
		int r = l + 1;
		int max = idx;
		if (l <= this->cnt - 1 && this->dataArr[l] > this->dataArr[idx])
			max = l;
		if (r <= this->cnt - 1 && this->dataArr[r] > this->dataArr[max])
			max = r;
		if (max != idx)
		{
			this->SwapValue(idx, max);
			SiftDown(max);
		}
	}

};