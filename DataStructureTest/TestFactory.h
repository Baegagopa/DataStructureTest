#pragma once
#include <iostream>
#include "SortTestBace.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "HeapSort.h"

enum SORT_TESTCASE
{
	BUBBLE,
	SELECTION,
	INSERTION,
	MERGE,
	QUICK,
	HEAP,
};

class TestFactory
{
public :
	SortTestBace* CreateSortTest(SORT_TESTCASE testCase)
	{
		switch (testCase)
		{
			case SORT_TESTCASE::BUBBLE : return new BubbleSort();
			case SORT_TESTCASE::SELECTION : return new SelectionSort();
			case SORT_TESTCASE::INSERTION: return new InsertionSort();
			case SORT_TESTCASE::MERGE: return new MergeSort();
			case SORT_TESTCASE::QUICK: return new QuickSort();
			case SORT_TESTCASE::HEAP: return new HeapSort();
		}
		return NULL;
	}
};