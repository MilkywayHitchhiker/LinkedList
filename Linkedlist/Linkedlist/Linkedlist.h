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
	//���� Iterator �������̽�
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

		//���� ��带 ���� ���� �̵���Ŵ
		Iterator operator ++(int)
		{
			node = node->pNext;
			return *this;
		}

		//���� ��带 ���� ���� �̵���Ŵ
		Iterator operator --(int)
		{
			node = node->pPrev;
			return *this;
		}

		//�������� �����͸� ��ȯ����
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

	
	//ù��° ��带 ����Ű�� ���ͷ����� ��ȯ
	Iterator Begin (void)
	{
		Iterator iter (Head.pNext);
		return iter;
	}

	//������ ��带 ����Ű�� ���ͷ����� ��ȯ
	Iterator End (void)
	{
		Iterator iter (&Tail);
		return iter;
	}

	//���� ����� �� ������ ��ȯ������
	int Size (void)
	{
		return NodeSize;
	}

	//���� ����� �տ� ����.
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

	//���� ����� �ڿ� ����.
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

	//���� ���ͷ����� ���� ��忡 ���� �����ϰ� �ش� ����� �հ� �ڸ� �̾���.
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

	//��� ��带 ������.
	void AllDelete (void)
	{

		Iterator iter;
		for ( iter = Begin (); iter != End ();)
		{
			Delete (iter);

		}
	}

};