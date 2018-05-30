#pragma once
#include "DataStructureBace.h"
#include <assert.h>

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
		head = new Node_Tree<T>;
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

	/*******************************************************************************
	                2                 5�� ������ �� �ڽ��� �ΰ��� ���
				  /   \	              
				1       5			  5�� �ڽ��� 8�� �ڼ� �� 
				       /  \           ���� ������ �ܸ� ���� ��ȯ
				     4      8         (5�� 6 swap)
					       /  \       
					     7     10     prvNode     : 2
						/			  curNode 	  : 5
                       6			  moveNode	  : 8
					                  movePrvNode : 8 (moveNode�� 7�� �̵��� ���)
	********************************************************************************/
	void DeleteNode_ChildBothSides(Node_Tree<T> *curNode, Node_Tree<T> *prvNode)
	{
		Node_Tree<T> *moveNode = curNode->right;
		if (moveNode->left == NULL)
		{
			if (prvNode->data > curNode->data)
				prvNode->left = moveNode;
			else
				prvNode->right = moveNode;
			
			delete curNode;
		}
		else
		{
			////////////////// update next time ///////////////////
			Node_Tree<T> *movePrvNode = moveNode;
			moveNode = moveNode->left;

			while (moveNode->left != NULL)
			{
				movePrvNode = moveNode;
				moveNode = moveNode->left;
			}

			moveNode->left = curNode->left;
			moveNode->right = curNode->right;
			movePrvNode->left = nullptr;

		}
	}

	void DeleteNode(Node_Tree<T> *curNode, Node_Tree<T> *prvNode)
	{
		if (curNode->left != NULL)
		{
			if (curNode->right != NULL) // �ڽ��� ���� �� ����
			{
				DeleteNode_ChildBothSides();
			}
			else  // �ڽ��� ���ʿ��� ����
			{
				if (prvNode->data > curNode->data)
					prvNode->left = curNode->left;
				else
					prvNode->right = curNode->left;

				delete curNode;
			}
		}
		else if (curNode->right != NULL) // �ڽ��� �����ʿ��� ����
		{
			
			if (prvNode->data > curNode->data)
				prvNode->left = curNode->right;
			else
				prvNode->right = curNode->right;

			delete curNode;
		}
		else // �ڽ� ����
			delete curNode;
		
	}

	int Size()
	{
		return size;
	}

private:
	void addNode(Node_Tree<T> *curNode, T data)
	{
		if (curNode->data > data)
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

private:
	Node_Tree<T> * head;
	int size;
};