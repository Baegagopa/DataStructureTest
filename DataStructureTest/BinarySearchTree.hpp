#include <assert.h>
#include <iostream>
#include <utility>
#include <algorithm>
#include <list>
#include "BinarySearchTree.h"

template<typename T>
inline BinarySearchTree<T>::BinarySearchTree()
{
	size = 0;
	head = new Node_Tree<T>();
}

template<typename T>
inline BinarySearchTree<T>::~BinarySearchTree()
{
	delete head;
}

template<typename T>
inline void BinarySearchTree<T>::Add(T data)
{
	if (size == 0)
		head->data = data;
	else
		addNode(head, data);

	size++;
}

template<typename T>
inline bool BinarySearchTree<T>::Search(T data)
{
	if (size == 0)
		return false;
	else
		return SearchNode(head, data);
}

template<typename T>
inline void BinarySearchTree<T>::Delete(T data)
{
	if (size != 0)
	{
		SearchNode_ForDelete(head, NULL, data);
		size--;
	}
}

template<typename T>
inline void BinarySearchTree<T>::PreorderTraversal()
{
	if (head != NULL)
		Search_Preorder(head);
	std::cout << "end" << std::endl;
}

template<typename T>
inline void BinarySearchTree<T>::InorderTraversal()
{
	if (head != NULL)
		Search_Inorder(head);
	std::cout << "end" << std::endl;
}

template<typename T>
inline void BinarySearchTree<T>::PostorderTraversal()
{
	if (head != NULL)
		Search_Postorder(head);
	std::cout << "end" << std::endl;
}

template<typename T>
inline void BinarySearchTree<T>::addNode(Node_Tree<T>* curNode, T data)
{
	if (curNode->data >= data)
	{
		if (curNode->left == NULL)
			curNode->left = new Node_Tree<T>(data);
		else
			addNode(curNode->left, data);
	}
	else
	{
		if (curNode->right == NULL)
			curNode->right = new Node_Tree<T>(data);
		else
			addNode(curNode->right, data);
	}
}

template<typename T>
inline bool BinarySearchTree<T>::SearchNode(Node_Tree<T>* curNode, T data)
{
	if (curNode->data == data)
		return true;
	else
	{
		if (curNode->data > data)
		{
			if (curNode->left == NULL)
				return false;
			else
				SearchNode(curNode->left, data);
		}
		else
		{
			if (curNode->right == NULL)
				return false;
			else
				SearchNode(curNode->right, data);
		}
	}
}

template<typename T>
inline void BinarySearchTree<T>::SearchNode_ForDelete(Node_Tree<T>* curNode, Node_Tree<T>* prvNode, T data)
{
	if (curNode->data == data)
	{
		DeleteNode(curNode, prvNode);
	}
	else
	{
		if (curNode->data > data)
		{
			if (curNode->left == NULL)
				assert(!"NoData");
			else
				SearchNode_ForDelete(curNode->left, curNode, data);
		}
		else
		{
			if (curNode->right == NULL)
				assert(!"NoData");
			else
				SearchNode_ForDelete(curNode->right, curNode, data);
		}
	}
}

template<typename T>
inline void BinarySearchTree<T>::DeleteNode(Node_Tree<T>* curNode, Node_Tree<T>* prvNode)
{
	if (curNode->left != NULL)
	{
		if (curNode->right != NULL) // �ڽ��� ���� �� ����
		{
			DeleteNode_ChildBothSides(curNode, prvNode);
		}
		else  // �ڽ��� ���ʿ��� ����
		{
			if (prvNode->left == curNode)
				prvNode->left = curNode->left;
			else
				prvNode->right = curNode->left;

			delete curNode;
		}
	}
	else if (curNode->right != NULL) // �ڽ��� �����ʿ��� ����
	{

		if (prvNode->left == curNode)
			prvNode->left = curNode->right;
		else
			prvNode->right = curNode->right;

		delete curNode;
	}
	else // �ڽ� ����
	{
		if (prvNode->left == curNode)
			prvNode->left = curNode->right;
		else
			prvNode->right = nullptr;

		delete curNode;
	}


}

	/**********************************************************************************
	����������������2��������������������5�� ������ �� �ڽ��� �� ���� ��� (4, 8)
	��������������/����\
				1��������5��������������5�� �ڽ��� 8�� �ڼ� ��
	��������������������/��\���������������� ������ �ܸ� ���� ��ȯ
	������������������4������8����������(5�� 6 swap)
	������������������������/��\
	����������������������7����10��������prvNode     : 2
	��������������������/����������������curNode 	 : 5
	������������������6������������������moveNode	 : 8������������������������������������ 
	***********************************************************************************/

template<typename T>
inline void BinarySearchTree<T>::DeleteNode_ChildBothSides(Node_Tree<T>* curNode, Node_Tree<T>* prvNode)
{
	Node_Tree<T> *moveNode = curNode->right;

	if (moveNode->left == NULL)
	{
		if (prvNode->left == curNode)
			prvNode->left = curNode->right;
		else
			prvNode->right = curNode->right;

		moveNode->left = curNode->left;
		delete curNode;
		return;
	}

	while (moveNode->left != NULL)
	{
		prvNode = moveNode;
		moveNode = moveNode->left;
	}

	prvNode->left = NULL;
	curNode->data = moveNode->data;
	delete moveNode;
}

template<typename T>
inline void BinarySearchTree<T>::Search_Preorder(Node_Tree<T>* curNode)
{
	std::cout << curNode->data << " -> ";
	if (curNode->left != NULL)
		Search_Preorder(curNode->left);
	if (curNode->right != NULL)
		Search_Preorder(curNode->right);
}

template<typename T>
inline void BinarySearchTree<T>::Search_Inorder(Node_Tree<T>* curNode)
{
	if (curNode->left != NULL)
		Search_Inorder(curNode->left);

	std::cout << curNode->data << " -> ";

	if (curNode->right != NULL)
		Search_Inorder(curNode->right);
}

template<typename T>
inline void BinarySearchTree<T>::Search_Postorder(Node_Tree<T>* curNode)
{
	if (curNode->left != NULL)
		Search_Postorder(curNode->left);

	if (curNode->right != NULL)
		Search_Postorder(curNode->right);

	std::cout << curNode->data << " -> ";
}

/**************************************************************************** Print ****************************************************************************
	�۵� Ȯ���� ���� print �Լ� ��������
https://stackoverflow.com/questions/801740/c-how-to-draw-a-binary-tree-to-the-console?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
***************************************************************************************************************************************************************/
template<typename T>
inline int BinarySearchTree<T>::_print_t(Node_Tree<T>* tree, int is_left, int offset, int depth, char s[20][255])
{
	char b[20];
	int width = 5;

	if (!tree) return 0;

	sprintf_s(b, "(%03d)", tree->data);

	int left = _print_t(tree->left, 1, offset, depth + 1, s);
	int right = _print_t(tree->right, 0, offset + left + width, depth + 1, s);

#ifdef COMPACT
	for (int i = 0; i < width; i++)
		s[depth][offset + left + i] = b[i];

	if (depth && is_left) {

		for (int i = 0; i < width + right; i++)
			s[depth - 1][offset + left + width / 2 + i] = '-';

		s[depth - 1][offset + left + width / 2] = '.';

	}
	else if (depth && !is_left) {

		for (int i = 0; i < left + width; i++)
			s[depth - 1][offset - width / 2 + i] = '-';

		s[depth - 1][offset + left + width / 2] = '.';
	}
#else
	for (int i = 0; i < width; i++)
		s[2 * depth][offset + left + i] = b[i];

	if (depth && is_left) {

		for (int i = 0; i < width + right; i++)
			s[2 * depth - 1][offset + left + width / 2 + i] = '-';

		s[2 * depth - 1][offset + left + width / 2] = '+';
		s[2 * depth - 1][offset + left + width + right + width / 2] = '+';

	}
	else if (depth && !is_left) {

		for (int i = 0; i < left + width; i++)
			s[2 * depth - 1][offset - width / 2 + i] = '-';

		s[2 * depth - 1][offset + left + width / 2] = '+';
		s[2 * depth - 1][offset - width / 2 - 1] = '+';
	}
#endif

	return left + width + right;
}

template<typename T>
inline void BinarySearchTree<T>::print_t(Node_Tree<T>* tree)
{
	char s[20][255];
	for (int i = 0; i < 20; i++)
		sprintf_s(s[i], "%80s", " ");

	_print_t(tree, 0, 0, 0, s);

	for (int i = 0; i < 20; i++)
		printf("%s\n", s[i]);
}
