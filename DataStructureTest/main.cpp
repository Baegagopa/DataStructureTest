#include "TestFactory.h"
#include <vector>
#include "Queue.h"
#include "Stack.h"
#include "LinkedList.h"
#include "Heap.h"
#include "BinarySearchTree.h"

int main()
{
	/*std::vector<int> arr = { 7,6,5,4,2,1,3 };
	TestFactory().CreateSortTest(SORT_TESTCASE::QUICK)->Action(arr);

	Heap<int> a(arr);
	a.PrintAll();
	std::cout << std::endl;

	TestFactory().CreateSortTest(SORT_TESTCASE::HEAP)->Action(arr);*/

	BinarySearchTree<int> tree;
	tree.Add(3);
	tree.Add(5);
	tree.Add(6);
	tree.Add(1);

	std::cout << tree.Search(3);



	return 0;
}