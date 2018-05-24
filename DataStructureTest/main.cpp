#include "TestFactory.h"
#include <vector>
void main()
{
	std::vector<int> arr = { 4,6,1,3,5,2 };
	TestFactory().CreateSortTest(SORT_TESTCASE::SORT_INSERTION)->Action(arr);
}