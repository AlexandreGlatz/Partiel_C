#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 6

int Squared(int num)
{
	return num * num;
}

void RemoveFromTab(int* pTab, int iElement, int iTabSize)
{
	int index;
	for (int i = 0; i < iTabSize; i++)
	{
		if (pTab[i] == iElement)
		{
			index = i;
		}
	}

	for (int i = index; i < iTabSize -1; i++)
	{
		pTab[i] = pTab[i + 1];
	}
}

int AskInt( const char* sMessage )
{
	while( 1 )
	{
		printf( "%s\n", sMessage);

		int iValue;
		int iSuccess = scanf_s( "%d", &iValue );
		while( getchar() != '\n' );

		if( iSuccess == 1 )
			return iValue;

		printf( "Entrée non valide" );
	}
}

// ===========
// #TODO 1 pts
// ===========
typedef struct Grid
{
	//Mettre les attributs utiles pour representer, calculer et afficher la grille de jeu 

	int iSpaceLeft;
	int iSize;
	int iWidth;
	int iHeight;

	char* pTiles;

	int iColumnLeftAmount;
	int* pColumnsLeft;

} Grid;

// =============
// #TODO 0.5 pts
// =============
void Init( Grid* pGrid )
{
	//Initialise les attributs de la structure Grid

	pGrid->iSize = Squared(SIZE);
	pGrid->iWidth = SIZE;
	pGrid->iHeight = SIZE;
	pGrid->iSpaceLeft = pGrid->iSize;
	pGrid->pTiles = (char*)malloc(sizeof(char) * pGrid->iSize);

	if (pGrid->pTiles == NULL)
		exit(1);

	for (int i = 0; i < pGrid->iSize; i++)
		pGrid->pTiles[i] = ' ';


	pGrid->iColumnLeftAmount = pGrid->iWidth;
	pGrid->pColumnsLeft = (int*)malloc(sizeof(int) * pGrid->iWidth);

	if (pGrid->pColumnsLeft == NULL)
		exit(1);

	for (int i = 0; i < pGrid->iWidth; i++)
		pGrid->pColumnsLeft[i] = i;
}

// ===========
// #TODO 1 pts
// ===========
void Print( const Grid* pGrid )
{
	system("cls"); //Nettoie l'écran

	//Affiche la grille de jeu au format:
	
	/*
		[ ][ ][ ][ ][ ][ ]
		[ ][ ][ ][ ][ ][ ]
		[ ][ ][ ][ ][ ][ ]
		[ ][ ][ ][ ][ ][ ]
		[ ][ ][O][X][ ][ ]
		[O][O][X][X][O][ ]
	*/
	for (int i = 0; i < pGrid->iSize; i++)
	{
		if (i % pGrid->iWidth == 0)
			printf("\n");

		printf("[");
		printf("%c", pGrid->pTiles[i]);
		printf("]");
	}
	//Attention doit s'adapter si on change la valeur de SIZE (ligne 5)
}

// =============
// #TODO 0.5 pts
// =============
int AskValidColumn( const Grid* pGrid )
{
	//Demande à l'utilisateur de rentrer une colonne, 
	//si celle-ci est pleine il faudra re demander à l'utilisateur une colonne valide.

	int iColIndex = AskInt("Entrez une colonne :");
	while (pGrid->pTiles[iColIndex] != ' ')
	{
		printf("cette colonne est pleine \n");
		iColIndex = AskInt("Entrez une colonne :");
	}
	//renvoie l'index de la colonne
	return iColIndex;
}

// ===========
// #TODO 1 pts
// ===========
int FillColumn( Grid* pGrid, int iColumn, char cSymbol )
{
	//Rempli une case à partir d'une colonne en simulant la gravité:

	//Premier tour: la colonne 1 et le symbole 'O':
	/*
		[ ][ ][ ][ ][ ][ ]
		[ ][ ][ ][ ][ ][ ]
		[ ][ ][ ][ ][ ][ ]
		[ ][ ][ ][ ][ ][ ]
		[ ][ ][ ][ ][ ][ ]
		[O][ ][ ][ ][ ][ ]
	*/

	//Deuxième tour: la colonne 1 et le symbol 'X':
	/*
		[ ][ ][ ][ ][ ][ ]
		[ ][ ][ ][ ][ ][ ]
		[ ][ ][ ][ ][ ][ ]
		[ ][ ][ ][ ][ ][ ]
		[X][ ][ ][ ][ ][ ]
		[O][ ][ ][ ][ ][ ]
	*/

	//cSymbol represente le symbole à utiliser, 'X' ou 'O'

	int iIndexPlayed = 0;
	for (int i = pGrid->iHeight - 1; i >=0 ; i--)
	{
		if (pGrid->pTiles[iColumn + i * pGrid->iWidth] == ' ');
		{
			iIndexPlayed = iColumn + i * pGrid->iWidth;
			pGrid->pTiles[iIndexPlayed] = cSymbol;
			break;
		}
	}

	if (iIndexPlayed == iColumn)
	{
		RemoveFromTab(pGrid->pColumnsLeft, iColumn, pGrid->iColumnLeftAmount);
		pGrid->iColumnLeftAmount -= 1;
	}
		
	pGrid->iSpaceLeft -= 1;
	//renvoie l'index de la ligne sur laquelle le symbole a été mis
	return iIndexPlayed;
}

// ===========
// #TODO 4 pts
// ===========
bool IsWin( const Grid* pGrid, int iLine, int iColumn )
{
	if (pGrid->iSize - pGrid->iSpaceLeft < 8)
		return false;

	int iSpaceAvailableLeft = 0 - iLine;
	if (iSpaceAvailableLeft < -3)
		iSpaceAvailableLeft = -3;

	int iSpaceAvailableBottom = 0 - iColumn;
	if (iSpaceAvailableBottom < -3)
		iSpaceAvailableBottom = -3;

	int iSpaceAvailableTop = pGrid->iHeight - iColumn;
	if (iSpaceAvailableTop > 3)
		iSpaceAvailableTop = 3;

	int iSquareToCheck[4][2] = { {iLine + iSpaceAvailableLeft, iColumn + iSpaceAvailableBottom}, {iLine + iSpaceAvailableLeft, 0},
								 {iLine + iSpaceAvailableLeft, iColumn + iSpaceAvailableTop}, {0, iColumn + iSpaceAvailableTop} };

	int iLineCheck[4][2] = { {1, 1}, {1, 0}, {1, -1}, {0, -1} };

	//Detecte si le dernier coup joué est un coup gagnant
	//4 symboles à la suite sur une ligne, une colonne ou une diagonale (gauche ou droite)
	char cSymbolTested = pGrid->pTiles[iLine + iColumn * pGrid->iWidth];

	int count = 0;
	for (int i = 0; i < 4 ; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (!(j > pGrid->iWidth))
			{
				int currentIndex = iSquareToCheck[i][0] + j * iLineCheck[i][0] + (iSquareToCheck[i][1] + j * iLineCheck[i][1] * pGrid->iWidth);

				if (pGrid->pTiles[currentIndex] == cSymbolTested)
					count += 1;
				else
					count = 0;

				if (count == 4)
					return true;
			}
		}
	}
	return false;
	//renvoie true si le dernier coup est gagnant, false sinon
}

// ===========
// #TODO 1 pts
// ===========
bool IsFull( const Grid* pGrid )
{
	return pGrid->iSpaceLeft == 0;
}

// ===========
// #TODO 3 pts
// ===========
int GetValidRandomColumn( const Grid* pGrid )
{
	//Choisi une colonne aléatoire, celle-ci ne doit pas être pleine
	int irandomColIndex = rand() % pGrid->iColumnLeftAmount -1;
	
	//Attention: 
	//l'aléatoire doit être uniforme et ne doit pas intervenir dans le temps d'execution de l'algorithme

	//renvoie l'index de la colonne
	return pGrid->pColumnsLeft[irandomColIndex];
}

// ===========
// #TODO 3 pts
// ===========
int main()
{
	// =====================
	// Initialisation du jeu
	// =====================

	srand( time( NULL ) );

	Grid oGrid;
	Init( &oGrid );

	
	/*
		Ajouter toutes les variables necessaires au fonctionnement du jeu
	*/
	bool isRunning = true;
	while( isRunning )
	{	
		// =============
		// Boucle de jeu
		// =============
		Print(&oGrid);
		
		int iPlayerPlay = AskValidColumn(&oGrid);
		FillColumn(&oGrid, iPlayerPlay, 'O');

		int iCpuPlay = GetValidRandomColumn(&oGrid);
		FillColumn(&oGrid, iCpuPlay, 'X');
		Print(&oGrid);

		if (IsWin(&oGrid, iPlayerPlay % oGrid.iWidth, iPlayerPlay / oGrid.iWidth))
		{
			printf("Vous avez gagne");
			isRunning = false;
		}
		else if (IsWin(&oGrid, iCpuPlay % oGrid.iWidth, iCpuPlay / oGrid.iWidth))
		{
			printf("L'adversaire a gagne");
			isRunning = false;
		}
		else if (IsFull(&oGrid))
		{
			printf("Match nul");
			isRunning = false;
		}
		/*
			-Affiche la grille
			
			-Alterne 1 tour sur 2: 
				-Demande à l'utilisateur de choisir une colonne
				-Choisi une colonne aléatoirement (pour simuler le coup adversaire)
			
			-Met à jour la grille avec le symbole correspondant ('O' pour le joueur 'X' pour l'adversaire)
			
			-Vérifie l'état de la grille:
				-Si le coup est gagnant: affiche "Vous avez gagné" ou "L'adversaire a gagné" et quitte la boucle
				-Si la grille est pleine: affiche "Match nul" et quitte la boucle
		*/
	}

	return 0;
}
