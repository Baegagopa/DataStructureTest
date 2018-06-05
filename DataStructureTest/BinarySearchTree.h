#pragma once
#include "DataStructureBace.h"


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
	BinarySearchTree();
	~BinarySearchTree();

	void Add(T data);
	bool Search(T data);
	void Delete(T data);
	int Size() { return size; }
	void PrintAll() { print_t(head);}

	void PreorderTraversal();
	void InorderTraversal();

	void PostorderTraversal();


private:
	void addNode(Node_Tree<T> *curNode, T data);
	bool SearchNode(Node_Tree<T> *curNode, T data);
	void SearchNode_ForDelete(Node_Tree<T> *curNode, Node_Tree<T> *prvNode, T data);
	void DeleteNode(Node_Tree<T> *curNode, Node_Tree<T> *prvNode);
	void DeleteNode_ChildBothSides(Node_Tree<T> *curNode, Node_Tree<T> *prvNode);

	void Search_Preorder(Node_Tree<T>* curNode);
	void Search_Inorder(Node_Tree<T>* curNode);
	void Search_Postorder(Node_Tree<T>* curNode);

	int _print_t(Node_Tree<T> *tree, int is_left, int offset, int depth, char s[20][255]);
	void print_t(Node_Tree<T> *tree);

private:
	Node_Tree<T> * head;
	int size;
};

#include "BinarySearchTree.hpp"