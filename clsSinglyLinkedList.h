#pragma once
#include <iostream>
using namespace std;


template <typename T> class clsNode
{
public:
	T Data;

	clsNode* Next;

	void InsertAtBeginning(clsNode*& Head, T Data)
	{
		clsNode* NewNode = new clsNode(); // saves address of Node object
		NewNode->Data = Data;
		NewNode->Next = Head; // saves head node's address
		Head = NewNode; // each new node's address will be saved here for head starts list from it
	}

	void PrintList(clsNode* Head)
	{
		if (Head == NULL)
		{
			cout << "\nOops, list is empty!\n";
			return;
		}

		while (Head != NULL)
		{
			cout << Head->Data << "   ";
			Head = Head->Next;
		}
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

	bool IsNodeExist(clsNode* SearchResult)
	{
		return SearchResult != NULL;
	}

	void InsertAfter(clsNode* NodeToInsertAfter, T NewNodeData)
	{
		// NodeToInsertAfter -> Node
		if (IsNodeExist(FindNode(NodeToInsertAfter, NodeToInsertAfter->Data)))
		{
			clsNode* New_Node = new clsNode();
			New_Node->Data = NewNodeData;
			New_Node->Next = NodeToInsertAfter->Next; // Node After NodeToInsertAfter
			NodeToInsertAfter->Next = New_Node;
		}
		else
		{
			cout << "\nCannot insert, previous node is null.";
			return;
		}
	}

	void InsertAtEnd(clsNode*& Head, T NewNodeData)
	{
		clsNode* New_Node = new clsNode();
		New_Node->Data = NewNodeData;
		New_Node->Next = NULL;

		// empty List
		if (Head == NULL)
		{
			Head = New_Node; // Start new List by Head Node
			return;
		}

		// List has nodes
		clsNode* LastNode = Head;
		while (LastNode->Next != NULL)
		{
			LastNode = LastNode->Next;
		}
		LastNode->Next = New_Node;
	}

	void DeleteNode(clsNode*& Head, T Data)
	{
		if (Head == NULL)
		{
			cout << "\nList is empty!\n";
			return;
		}

		clsNode* Previous = Head, * Current = Head;

		if (Current->Data == Data) // Head Node is deleted
		{
			Head = NULL;
			delete Current;
			return;
		}

		while (Current != NULL && Current->Data != Data)
		{
			Previous = Current;
			Current = Current->Next;
		}

		if (Current == NULL) // loop is broken by Current == NULL
		{
			cout << "\nNode " << Data << " is not found!\n";
			return;
		}

		Previous->Next = Current->Next; // loop is broken by Current->Data == Data
		delete Current;
		cout << "\nNode " << Data << " is deleted!\n";
	}

	void DeleteFirstNode(clsNode*& Head)
	{
		if (Head == NULL)
		{
			cout << "\nList is empty!\n";
			return;
		}

		clsNode* FirstNode = Head;
		Head = FirstNode->Next; // Head pointer will point to second node
		delete FirstNode;
		cout << "\nFirst Node is deleted!\n";
	}

	void DeleteLastNode(clsNode*& Head)
	{
		if (Head == NULL)
		{
			cout << "\nList is empty!\n";
			return;
		}

		clsNode* Previous = Head, * LastNode = Head;

		if (LastNode->Next == NULL) // Delete Head Node
		{
			Head = NULL;
			delete LastNode;
			return;
		}

		while (LastNode->Next != NULL) // find tail node
		{
			Previous = LastNode;
			LastNode = LastNode->Next;
		}

		Previous->Next = NULL;
		delete LastNode;
		cout << "\n\ntail Node is deleted!\n\n";
	}
};