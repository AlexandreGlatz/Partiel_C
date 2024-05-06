#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 6

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

		printf( "Entr�e non valide" );
	}
}

// ===========
// #TODO 1 pts
// ===========
typedef struct Grid
{
	//Mettre les attributs utiles pour representer, calculer et afficher la grille de jeu 

} Grid;

// =============
// #TODO 0.5 pts
// =============
void Init( Grid* pGrid )
{
	//Initialise les attributs de la structure Grid
}

// ===========
// #TODO 1 pts
// ===========
void Print( const Grid* pGrid )
{
	system("cls"); //Nettoie l'�cran

	//Affiche la grille de jeu au format:
	
	/*
		[ ][ ][ ][ ][ ][ ]
		[ ][ ][ ][ ][ ][ ]
		[ ][ ][ ][ ][ ][ ]
		[ ][ ][ ][ ][ ][ ]
		[ ][ ][O][X][ ][ ]
		[O][O][X][X][O][ ]
	*/
	
	//Attention doit s'adapter si on change la valeur de SIZE (ligne 5)
}

// =============
// #TODO 0.5 pts
// =============
int AskValidColumn( const Grid* pGrid )
{
	//Demande � l'utilisateur de rentrer une colonne, 
	//si celle-ci est pleine il faudra re demander � l'utilisateur une colonne valide.
	
	//renvoie l'index de la colonne
}

// ===========
// #TODO 1 pts
// ===========
int FillColumn( Grid* pGrid, int iColumn, char cSymbol )
{
	//Rempli une case � partir d'une colonne en simulant la gravit�:

	//Premier tour: la colonne 1 et le symbole 'O':
	/*
		[ ][ ][ ][ ][ ][ ]
		[ ][ ][ ][ ][ ][ ]
		[ ][ ][ ][ ][ ][ ]
		[ ][ ][ ][ ][ ][ ]
		[ ][ ][ ][ ][ ][ ]
		[O][ ][ ][ ][ ][ ]
	*/

	//Deuxi�me tour: la colonne 1 et le symbol 'X':
	/*
		[ ][ ][ ][ ][ ][ ]
		[ ][ ][ ][ ][ ][ ]
		[ ][ ][ ][ ][ ][ ]
		[ ][ ][ ][ ][ ][ ]
		[X][ ][ ][ ][ ][ ]
		[O][ ][ ][ ][ ][ ]
	*/

	//cSymbol represente le symbole � utiliser, 'X' ou 'O'

	//renvoie l'index de la ligne sur laquelle le symbole a �t� mis
}

// ===========
// #TODO 4 pts
// ===========
bool IsWin( const Grid* pGrid, int iLine, int iColumn )
{
	//Detecte si le dernier coup jou� est un coup gagnant
	//4 symboles � la suite sur une ligne, une colonne ou une diagonale (gauche ou droite)

	//renvoie true si le dernier coup est gagnant, false sinon
}

// ===========
// #TODO 1 pts
// ===========
bool IsFull( const Grid* pGrid )
{
	//renvoie true si la grille est pleine, false sinon
}

// ===========
// #TODO 3 pts
// ===========
int GetValidRandomColumn( const Grid* pGrid )
{
	//Choisi une colonne al�atoire, celle-ci ne doit pas �tre pleine
	
	//Attention: 
	//l'al�atoire doit �tre uniforme et ne doit pas intervenir dans le temps d'execution de l'algorithme

	//renvoie l'index de la colonne
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

	while( 1 )
	{	
		// =============
		// Boucle de jeu
		// =============

		/*
			-Affiche la grille
			
			-Alterne 1 tour sur 2: 
				-Demande � l'utilisateur de choisir une colonne
				-Choisi une colonne al�atoirement (pour simuler le coup adversaire)
			
			-Met � jour la grille avec le symbole correspondant ('O' pour le joueur 'X' pour l'adversaire)
			
			-V�rifie l'�tat de la grille:
				-Si le coup est gagnant: affiche "Vous avez gagn�" ou "L'adversaire a gagn�" et quitte la boucle
				-Si la grille est pleine: affiche "Match nul" et quitte la boucle
		*/
	}

	return 0;
}
