// Linkedlist.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include"Linkedlist.h"

int main()
{
	LinkedList<int *> list;
	LinkedList<int *>::Iterator iter;

	int a=10;
	int b = 9;
	int c = 8;
	int d = 7;
	int e = 6;
	int f = 5;

	int *p;

	list.Push_Front (&a);

	list.Push_Front (&b);

	list.Push_Front (&c);

	list.Push_Front (&d);

	list.Push_Front (&e);

	list.Push_Front (&f);



	for ( iter = list.Begin (); iter != list.End (); iter++ )
	{
		p = *iter;
		printf (" %d ", *p);
	}
	
	
	return 0;
}

