#pragma once
#include <iostream>
#include "SortTestBace.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"

enum SORT_TESTCASE
{
	SORT_BUBBLE,
	SORT_SELECTION,
	SORT_INSERTION,
};

class TestFactory
{
public :
	SortTestBace* CreateSortTest(SORT_TESTCASE testCase)
	{
		switch (testCase)
		{
			case SORT_TESTCASE::SORT_BUBBLE : return new BubbleSort();
			case SORT_TESTCASE::SORT_SELECTION : return new SelectionSort();
			case SORT_TESTCASE::SORT_INSERTION: return new InsertionSort();
		}
		return NULL;
	}
};