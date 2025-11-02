#pragma once
#include <iostream>
using namespace std;


template <typename T> class clsNode
{
public:
	clsNode* Previous;
	T Data;
	clsNode* Next;

	void PrintListFromLeft(clsNode* Head)
	{
		while (Head != NULL)
		{
			cout << Head->Data << "   ";
			Head = Head->Next;
		}
	}

	void PrintListFromRight(clsNode* Head)
	{
		clsNode* temp = Head;
		while (temp->Next != NULL) // find tail node
		{
			temp = temp->Next;
		}

		while (temp != NULL) // traverse from right by previous pointer
		{
			cout << temp->Data << "   ";
			temp = temp->Previous;
		}
	}

	void PrintListWithArrows(clsNode* Head)
	{
		cout << "NULL <--> ";
		while (Head != NULL)
		{
			cout << Head->Data << " <--> ";
			Head = Head->Next;
		}
		cout << "NULL";
	}

	void PrintNodeDetails(clsNode* Head)
	{
		if (Head->Previous != NULL)
			cout << Head->Previous->Data;
		else
			cout << "NULL";

		cout << " <--> " << Head->Data << " <--> ";

		if (Head->Next != NULL)
			cout << Head->Next->Data << "\n";
		else
			cout << "NULL";
	}

	void PrintListDetails(clsNode* Head)
	{
		cout << "\n\n";
		while (Head != NULL)
		{
			PrintNodeDetails(Head);
			Head = Head->Next;
		}
	}

	void InsertAtBeginning(clsNode*& Head, T Data)
	{
		clsNode* New_Node = new clsNode();
		New_Node->Previous = NULL;
		New_Node->Data = Data;
		New_Node->Next = Head; // Head: Previous Head Node
		if (Head != NULL)
		{
			Head->Previous = New_Node;
		}
		Head = New_Node; // points to new node
	}

	clsNode* FindNode(clsNode* Head, T Data)
	{
		while (Head != NULL)
		{
			if (Head->Data == Data)
				return Head;
			Head = Head->Next;
		}
		return NULL;
	}

	bool IsNodeExist(clsNode* NodeToSearch)
	{
		return NodeToSearch != NULL;
	}

	void InsertAfter(clsNode* NodeToInsertAfter, T Data)
	{
		clsNode* New_Node = new clsNode();
		New_Node->Previous = NodeToInsertAfter;
		New_Node->Data = Data;
		New_Node->Next = NodeToInsertAfter->Next;
		if (NodeToInsertAfter->Next != NULL)
		{
			NodeToInsertAfter->Next->Previous = New_Node;
		}

		NodeToInsertAfter->Next = New_Node;
	}

	void InsertAtEnd(clsNode*& Head, T Data)
	{
		clsNode* New_Node = new clsNode();
		New_Node->Data = Data;
		New_Node->Next = NULL; // always you add tail node, so its Next always points to NULL

		if (Head == NULL) // empty double list
		{
			New_Node->Previous = NULL;
			Head = New_Node; // Head Node
			return;
		}

		clsNode* tail_node = Head;
		while (tail_node->Next != NULL) // find tail node
		{
			tail_node = tail_node->Next;
		}
		tail_node->Next = New_Node;
		New_Node->Previous = tail_node;
	}

	void DeleteNode(clsNode*& Head, clsNode* NodeToDelete)
	{
		// List is empty
		if (Head == NULL)
		{
			cout << "\n\nOops, list is empty!\n\n";
			return;
		}

		// Node is not found
		if (NodeToDelete == NULL)
		{
			cout << "\n\nOops, node is not found!\n\n";
			return;
		}

		// 1 Node:
		// Case1: list has 1 node
		if (NodeToDelete->Next == NULL)
		{
			if (NodeToDelete->Previous == NULL)
			{
				Head = NULL;
				cout << "\n\nNode " << NodeToDelete->Data << " is deleted and list becomes empty.\n\n";
			}
			// Case2: tail node
			else
			{
				// set new tail node
				NodeToDelete->Previous->Next = NULL;
				cout << "\n\ntail node " << NodeToDelete->Data << " is deleted.\n\n";
			}
		}

		// Head Node
		if (NodeToDelete->Previous == NULL)
		{
			// set new Head Node
			Head = NodeToDelete->Next;
			NodeToDelete->Next->Previous = NULL;
			cout << "\n\nHead Node " << NodeToDelete->Data << " is deleted.\n\n";
		}

		// Middle node
		if (NodeToDelete->Previous != NULL && NodeToDelete->Next != NULL)
		{
			NodeToDelete->Previous->Next = NodeToDelete->Next;
			NodeToDelete->Next->Previous = NodeToDelete->Previous;
			cout << "\n\nNode " << NodeToDelete->Data << " is deleted.\n\n";
		}

		NodeToDelete = NULL;
		delete NodeToDelete;
	}

	void DeleteAtFirst(clsNode*& Head)
	{
		if (Head == NULL)
		{
			cout << "\n\nOops, list is empty!\n\n";
			return;
		}

		clsNode* OldHeadNode = new clsNode();
		OldHeadNode = Head;

		if (OldHeadNode->Next == NULL)
		{
			Head = NULL;
			cout << "\n\nNode " << OldHeadNode->Data << " is deleted and list becomes empty.\n\n";
		}

		else
		{
			// set new Head Node
			Head = OldHeadNode->Next;
			OldHeadNode->Next->Previous = NULL;
			cout << "\n\nHead Node " << OldHeadNode->Data << " is deleted!\n\n";
		}

		OldHeadNode = NULL;
		delete OldHeadNode;
	}

	void DeleteAtEnd(clsNode*& Head)
	{
		if (Head == NULL)
		{
			cout << "\n\nOops, list is empty!\n\n";
			return;
		}

		clsNode* tail_Node = new clsNode();
		tail_Node = Head;

		while (tail_Node->Next != NULL) // find tail_Node
		{
			tail_Node = tail_Node->Next;
		}

		if (tail_Node->Previous == NULL)
		{
			Head = NULL;
			cout << "\n\nNode " << tail_Node->Data << " is deleted and list becomes empty.\n\n";
		}

		else
		{
			// set new tail node
			tail_Node->Previous->Next = NULL;
			cout << "\n\ntail node " << tail_Node->Data << " is deleted.\n\n";
		}

		tail_Node = NULL;
		delete tail_Node;

		/*
		Another solution: find node before tail node
		while(tail_Node->Next->Next != NULL)
		{
			tail_Node = tail_Node->Next;
		}
		Node* temp = tail_Node->Next;
		tail_Node->Next = NULL;
		delete temp;
		*/
	}
};