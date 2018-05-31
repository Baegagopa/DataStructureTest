#pragma once

#include "DataStructureBace.h"
#include <assert.h>
#include <iostream>
#include <utility>
#include <algorithm>
#include <list>

template <typename T>
struct Node_Tree
{
	Node_Tree() 
	{
		this->left = nullptr;
		this->right = nullptr;
		this->data = NULL;
	}
	Node_Tree(T data)
	{ 
		this->data = data; 
		this->left = nullptr;
		this->right = nullptr;
	}

	T data;
	Node_Tree* left;
	Node_Tree* right;
};

template<typename T>
class BinarySearchTree : public DataStructureBace
{
public:
	BinarySearchTree()
	{
		size = 0;
		head = new Node_Tree<T>();
	}


	~BinarySearchTree()
	{
		delete head;
	}

	void Add(T data)
	{
		if (size == 0)
			head->data = data;
		else
			addNode(head, data);

		size++;
	}

	bool Search(T data)
	{
		if (size == 0)
			return false;
		else
			return SearchNode(head, data);	
	}

	void Delete(T data)
	{
		if (size != 0)
		{
			SearchNode_ForDelete(head, NULL, data);
			size--;
		}
	}

	int Size()
	{
		return size;
	}

	void PrintAll()
	{
		print_t(head);
	}


private:
	void addNode(Node_Tree<T> *curNode, T data)
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

	bool SearchNode(Node_Tree<T> *curNode, T data)
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

	void SearchNode_ForDelete(Node_Tree<T> *curNode, Node_Tree<T> *prvNode, T data)
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

	void DeleteNode(Node_Tree<T> *curNode, Node_Tree<T> *prvNode)
	{
		if (curNode->left != NULL)
		{
			if (curNode->right != NULL) // 자식이 양쪽 다 있음
			{
				DeleteNode_ChildBothSides(curNode,prvNode);
			}
			else  // 자식이 왼쪽에만 있음
			{
				if (prvNode->left == curNode)
					prvNode->left = curNode->left;
				else
					prvNode->right = curNode->left;

				delete curNode;
			}
		}
		else if (curNode->right != NULL) // 자식이 오른쪽에만 있음
		{

			if (prvNode->left == curNode)
				prvNode->left = curNode->right;
			else
				prvNode->right = curNode->right;

			delete curNode;
		}
		else // 자식 없음
		{
			if (prvNode->left == curNode)
				prvNode->left = curNode->right;
			else
				prvNode->right = nullptr;

			delete curNode;
		}
			

	}

	/**********************************************************************************
	　　　　　　　　2　　　　　　　　　　5를 삭제할 때 자식이 두 개일 경우 (4, 8)
	　　　　　　　/　　\
				1　　　　5　　　　　　　5의 자식인 8의 자손 중
	　　　　　　　　　　/　\　　　　　　가장 좌측끝 단말 노드와 교환
	　　　　　　　　　4　　　8　　　　　(5와 6 swap)
	　　　　　　　　　　　　/　\
	　　　　　　　　　　　7　　10　　　　prvNode     : 2
	　　　　　　　　　　/　　　　　　　　curNode 	 : 5
	　　　　　　　　　6　　　　　　　　　moveNode	 : 8　　　　　　　　　　　　　　　　　　 
	***********************************************************************************/
	void DeleteNode_ChildBothSides(Node_Tree<T> *curNode, Node_Tree<T> *prvNode)
	{
		Node_Tree<T> *moveNode = curNode->right;

		if(moveNode->left == NULL)
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

	/**************************************************************************** Print ****************************************************************************
	   작동 확인을 위해 print 함수 가져왔음
	  https://stackoverflow.com/questions/801740/c-how-to-draw-a-binary-tree-to-the-console?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
	 ***************************************************************************************************************************************************************/

	int _print_t(Node_Tree<T> *tree, int is_left, int offset, int depth, char s[20][255])
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

	void print_t(Node_Tree<T> *tree)
	{
		char s[20][255];
		for (int i = 0; i < 20; i++)
			sprintf_s(s[i], "%80s", " ");

		_print_t(tree, 0, 0, 0, s);

		for (int i = 0; i < 20; i++)
			printf("%s\n", s[i]);
	}
	

private:
	Node_Tree<T> * head;
	int size;
};