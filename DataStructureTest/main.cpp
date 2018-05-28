#include "TestFactory.h"
#include <vector>
#include <list>
#include "Queue.h"
#include "Stack.h"
#include "LinkedList.h"
int main()
{
	//std::vector<int> arr = { 6,4,1,3,5,2 };
	//TestFactory().CreateSortTest(SORT_TESTCASE::QUICK)->Action(arr);

	LinkedList<int> list;
	list.ADD(3);
	list.ADD(4);
	std::cout << list.Size() << std::endl;
	list.Erase();
	std::cout << list.Size() << std::endl;

	return 0;
}