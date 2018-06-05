#include "TestFactory.h"
#include <vector>
#include "Queue.h"
#include "Stack.h"
#include "LinkedList.h"
#include "Heap.h"
#include "BinarySearchTree.h"
#include "DFS.h"
int main()
{
	/*std::vector<int> arr = { 7,6,5,4,2,1,3 };
	TestFactory().CreateSortTest(SORT_TESTCASE::QUICK)->Action(arr);

	Heap<int> a(arr);
	a.PrintAll();
	std::cout << std::endl;

	TestFactory().CreateSortTest(SORT_TESTCASE::HEAP)->Action(arr);*/

	BinarySearchTree<int> tree;

	tree.Add(2);
	tree.Add(1);
	tree.Add(5);
	tree.Add(4);
	tree.Add(8);
	tree.Add(7);
	tree.Add(10);
	tree.Add(6);
	tree.Add(11);

	tree.PrintAll();

	tree.Delete(5);
	tree.PrintAll();
	std::cout << std::endl;

	tree.PostorderTraversal();

	std::vector<std::vector<int>> arr = { {1, 2},{0, 3},{ 0,4,5},{1},{2,6},{2},{4} };
	DFS dfs;
	std::vector<int> temp = dfs.VisitVertex(arr);

	return 0;
}