#pragma once
#include "DataStructureBace.h"
#include <assert.h>

template<typename T>
struct Node_List
{
	T data;
	Node_List* next;
};

template<typename T>
class LinkedList : public DataStructureBace
{
public:
	LinkedList()
	{
		cnt = 0;
		head = new Node_List<int>;
		head->next = nullptr;
		head->data = NULL;
	}

	~LinkedList()
	{
		Erase();
		delete head;
	}

	void ADD(T data)
	{
		Node_List<T>* temp = new Node_List<int>;
		temp->data = data;
		if (head == NULL)
		{
			head->next = temp;
		}
		else
		{
			temp->next = head->next;
			head->next = temp;
		}
		cnt++;
	}

	void Delete(T data)
	{
		Node_List<T>* temp = head;
		while (temp->next != NULL)
		{
			if (temp->next->data == data)
			{
				Node_List<T>* deleteNode = temp->next;
				temp->next = temp->next->next;
				delete deleteNode;
				cnt--;
				return;
			}
			temp = temp->next;
		}
		assert(!"NoData");
	}

	void Erase()
	{
		Node_List<T>* deleteNode;
		while (head->next != NULL)
		{
			deleteNode = head->next;
			if (head->next->next != NULL)
				head->next = head->next->next;
			else
				head->next = NULL;
			delete deleteNode;
		}
		cnt = 0;
	}

	int Size()
	{
		return cnt;
	}
private:
	Node_List<T> * head;
	int cnt;
};