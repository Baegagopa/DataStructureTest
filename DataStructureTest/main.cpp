#include "TestFactory.h"
#include <vector>
int main()
{
	std::vector<int> arr = { 6,4,1,3,5,2 };
	TestFactory().CreateSortTest(SORT_TESTCASE::QUICK)->Action(arr);
	return 0;
}