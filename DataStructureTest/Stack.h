#pragma once
#include <assert.h>

template <typename T>
class Stack : public DataStructureBace
{
public:
	Stack(int size)
	{
		cnt = 0;
		dataArr = new T[size];
		this->size = size;
	}

	void Push(T data)
	{
		if (size > cnt)
			dataArr[cnt++] = data;
		else
			assert(!"overflow");

	}

	T Pop()
	{
		if (cnt > 0)
			return dataArr[--cnt];
		else
			assert(!"underflow");
		return NULL;
	}

	int Size()
	{
		return size;
	}


private:
	T * dataArr;
	int size;
	int cnt;
};