#pragma once
#include"stdafx.h"

template <typename T>
class LinkedList
{
public:
	struct Node
	{
		T Data;
		Node *pPrev;
		Node *pNext;
	};

	////////////////////////////////////////////
	//내부 Iterator 인터페이스
	////////////////////////////////////////////
	class Iterator
	{
	private:
		Node *node;

	public:
		Iterator (Node *pNode = nullptr)
		{
			node = pNode;
		}

		~Iterator ()
		{
		}

		//현재 노드를 다음 노드로 이동시킴
		Iterator operator ++(int)
		{
			node = node->pNext;
			return *this;
		}

		//현재 노드를 이전 노드로 이동시킴
		Iterator operator --(int)
		{
			node = node->pPrev;
			return *this;
		}

		//현재노드의 데이터를 반환해줌
		T& operator *(void)
		{
			return node->Data;
		}

		bool operator  !=(const Iterator&i)
		{
			return (node != i.node);
		}

		Node *returnNode (void)
		{
			return node;
		}

	};

private:
	int NodeSize;
	Node Head;
	Node Tail;


public:
	LinkedList(void){
		NodeSize = 0;

		Head.pPrev = NULL;
		Head.pNext = &Tail;
		Tail.pPrev = &Head;
		Tail.pNext = NULL;
		
	}
	~LinkedList (void)
	{
		AllDelete ();
	}

	
	//첫번째 노드를 가르키는 이터레이터 반환
	Iterator Begin (void)
	{
		Iterator iter (Head.pNext);
		return iter;
	}

	//마지막 노드를 가르키는 이터레이터 반환
	Iterator End (void)
	{
		Iterator iter (&Tail);
		return iter;
	}

	//현재 노드의 총 개수를 반환시켜줌
	int Size (void)
	{
		return NodeSize;
	}

	//현재 노드의 앞에 넣음.
	void Push_Front (T Data)
	{
		
			Node *pNewNode = new Node;

			pNewNode->Data = Data;
			pNewNode->pNext = Head.pNext;
			pNewNode->pPrev = &Head;
		
			Head.pNext->pPrev = pNewNode;
			Head.pNext = pNewNode;

			NodeSize++;

			return;
		
	}

	//현재 노드의 뒤에 넣음.
	void Push_Back (T Data)
	{
		Node *pNewNode = new Node;

		pNewNode->Data = Data;
		pNewNode->pPrev = Tail.pPrev;
		pNewNode->pNext = &Tail;
		
		Tail.pPrev->pNext = pNewNode;
		Tail.pPrev = pNewNode;
		
		NodeSize++;

		return;
	}

	//받은 이터레이터 안의 노드에 대해 삭제하고 해당 노드의 앞과 뒤를 이어줌.
	void Delete (Iterator &iter)
	{
		Node *pNode;
		pNode = iter.returnNode ();


		if ( (pNode == &Head) || (pNode == &Tail) || (pNode == NULL) )
		{
			return;
		}

		pNode->pPrev->pNext = pNode->pNext;
		pNode->pNext->pPrev = pNode->pPrev;


		NodeSize--;

		iter++;

		delete pNode;

		return;
	}

	//모든 노드를 삭제함.
	void AllDelete (void)
	{

		Iterator iter;
		for ( iter = Begin (); iter != End ();)
		{
			Delete (iter);

		}
	}

};