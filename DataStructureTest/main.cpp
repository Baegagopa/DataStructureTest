#include "TestFactory.h"
#include <vector>
#include "Queue.h"
#include "Stack.h"
#include "LinkedList.h"
#include "Heap.h"
int main()
{
	//std::vector<int> arr = { 6,4,1,3,5,2 };
	//TestFactory().CreateSortTest(SORT_TESTCASE::QUICK)->Action(arr);

	Heap<int> b(10);

	b.Add(8);
	b.Add(5);
	b.Add(7);
	b.Add(9);
	b.Add(4);
	b.Add(2);
	b.Add(6);

	TestFactory().CreateSortTest(SORT_TESTCASE::HEAP)->Action(b.TransDataArrVector());


	return 0;
}