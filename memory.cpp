#include <stdio.h>
#include <stdlib.h>

// 1)
// ====================================
int main()
{
	int i = 5;
	int j = 10;

	if( i == 0 )
	{
		int k = 15;
	}

	int l = 20;

	return 0;
}

// =============
// #TODO 0.5 Pts
// =============
/*
	Adresse		Valeur	Allocation
	1000		5		Pile
	1001		10      Pile
	1002		0		Libre
	1003        0		Libre
	1004		0		Libre
*/

// ====================================

// 2)
// ====================================
int main()
{
	int i = 5;
	int* pi = &i;
	*pi = 10;

	return 0;
}

// =============
// #TODO 0.5 Pts
// =============
/*
	Addresse	Valeur	Allocation
	1000		10		Pile
	1001		1000    Tas
	1002		0		Libre
	1003        0		Libre
	1004		0		Libre
*/

// ====================================

// 3)
// ====================================
int main()
{
	int i = 5;
	int j = 10;
	int* pi = &i;
	int** ppi = &pi;

	**ppi = 10;
	*ppi = &j;
	**ppi = 20;

	return 0;
}

// ===========
// #TODO 1 Pts
// ===========
/*
	Addresse	Valeur	Allocation
	1000		20		Pile
	1001		10      Pile
	1002		1001	Tas
	1003        1002	Tas
	1004		0		Libre
*/
// ====================================

// 4)
// ====================================
int main()
{
	int* p = (int*) malloc( sizeof( int ) );
	*p = 5;

	return 0;
}

// =============
// #TODO 0.5 Pts
// =============
/*
	Addresse	Valeur	Allocation
	1000		1001	Tas
	1001		5       Tas
	1002		0		Libre
	1003        0		Libre
	1004		0		Libre
*/
// ====================================

// 5)
// ====================================
int main()
{
	int* p = (int*) malloc( sizeof( int ) );
	*p = 5;

	free(p);

	int i = 10;

	return 0;
}

// =============
// #TODO 0.5 Pts
// =============
/*
	Addresse	Valeur	Allocation
	1000		10		Pile
	1001		0       Libre
	1002		0		Libre
	1003        0		Libre
	1004		0		Libre
*/
// ====================================

// 6)
// ====================================
int main()
{
	int* p1 = (int*) malloc( sizeof( int ) );
	int* p2 = (int*) malloc( sizeof( int ) );
	*p1 = 5;
	*p2 = 10;

	int* pSwap = p1;
	p1 = p2;
	p2 = pSwap;

	*p1 = 15;
	*p2 = 20;

	return 0;
}

// ===========
// #TODO 1 Pts
// ===========
/*
	Addresse	Valeur	Allocation
	1000		1003	Tas
	1001		20      Tas
	1002		1001	Tas
	1003        15		Tas
	1004		1001	Tas
*/
// ====================================

// 7)
// ====================================
int main()
{
	int* p = (int*) malloc( sizeof( int ) * 2 );

	return 0;
}

// =============
// #TODO 0.5 Pts
// =============
/*
	Addresse	Valeur	Allocation
	1000		0		Libre
	1001		999     Tas
	1002		1004	Tas
	1003        0		Libre
	1004		0		Libre
*/
// ====================================

// 8)
// ====================================
int main()
{
	int* p = (int*) malloc( sizeof( int ) * 4 );
	*( p + 2 ) = 5;

	return 0;
}

// =============
// #TODO 0.5 Pts
// =============
/*
	Addresse	Valeur	Allocation
	1000		1004	Tas
	1001		0       Libre
	1002		0		Libre
	1003        5		Tas
	1004		0		Libre
*/
// ====================================


// 9)
// ====================================
int main()
{
	int* p = (int*) malloc( sizeof( int ) * 4 );
	p = p + 2;
	*( p + 2 ) = 5;

	return 0;
}

// ===========
// #TODO 1 Pts
// ===========
/*
	Addresse	Valeur	Allocation
	1000		1004	Libre
	1001		0       Libre
	1002		0		Libre
	1003        0		Libre
	1004		5		Tas
*/
// ====================================