//----------------------------------------------------------------------------
// File:		TheGameOfLife_IW.c
//
// Functions:
//				calculateNextGeneration()
//				printGeneration()
//				swapGenerations()
//----------------------------------------------------------------------------

#include "TheGameOfLife.h"

//----------------------------------------------------------------------------
// Function:	calculateNextGeneration()
//
// Title:		Calculate the Next Generation
//
// Description:
//				Goes through cells of the old generation (with 1 cell margin
//				around the array), counts the neighbors around each cell, and
//				sets a corresponding cell in the new generation, according to
//				the rules of the game.
//
// Programmer:	Isaac Wang
//
// Date:		11/19/11
//
// Version:		1.0
//
// Environment:	Intel Xeon PC
//              Software:	MS Windows 7 for execution;
//				Compiles under Microsoft Visual Studio.Net 2010
//
// Parameters:	oldArray: const char; the old generation to read the state of
//				newArray: char; the new generation to put the future state in
//
// Called By:	main()
//
// Calls:		countNeighbors()
//
// History Log:
//				11/19/11	IW completed version 1.0
//----------------------------------------------------------------------------
void calculateNextGeneration(const char oldArray[][COLS],
							 char newArray[][COLS], int rows)
{
	int i = 0;
	int j = 0;
	for(i = 1; i < rows - 1; i++)
	{
		for(j = 1; j < COLS - 1; j++)
		{
			switch(countNeighbors(oldArray, i, j))
			{
				case 2:	 // Cell remains static
					newArray[i][j] = oldArray[i][j];
					break;
				case 3:	 // Live cell no matter what
					newArray[i][j] = LIVE_CELL;	// defined in header file
					break;
				default: // Dead cell
					newArray[i][j] = DEAD_CELL;
					break;
			}
		}
	}
}

//----------------------------------------------------------------------------
// Function:	printGeneration()
//
// Title:		Print the Generation
//
// Description:
//				Goes through cells of a generation, and prints each cell,
//				adding a newline after a row of cells is printed.
//
// Programmer:	Isaac Wang
//
// Date:		11/21/11
//
// Version:		1.0
//
// Environment:	Intel Xeon PC
//              Software:	MS Windows 7 for execution;
//				Compiles under Microsoft Visual Studio.Net 2010
//
// Output:		Prints out an entire generation of live and dead cells.
//
// Parameters:	generation[][]: const char; the generation to print out
//				rows: int; the number of rows in the generation array
//
// Called By:	main()
//
// History Log:
//				11/21/11	IW completed version 1.0
//----------------------------------------------------------------------------
void printGeneration(const char generation[][COLS], int rows)
{
	int i = 0;
	int j = 0;
	for(i = 1; i < rows - 1; i++)
	{
		for(j = 1; j < COLS - 1; j++)
		{
			printf("%c", generation[i][j]);
		}
		puts("");
	}
}

//----------------------------------------------------------------------------
// Function:	swapGenerations()
//
// Title:		Swap Two Generations
//
// Description:
//				Swaps the pointers of two arrays.
//
// Programmer:	Isaac Wang
//
// Date:		11/22/11
//
// Version:		1.0
//
// Environment:	Intel Xeon PC
//              Software:	MS Windows 7 for execution;
//				Compiles under Microsoft Visual Studio.Net 2010
//
// Parameters:	oldArray[][]: char; array one to be swapped
//				newArray[][]: char; array two to be swapped
//
// Called By:	main()
//
// History Log:
//				11/22/11	IW completed version 1.0
//----------------------------------------------------------------------------
void swapGenerations(char oldArray[][COLS], char newArray[][COLS])
{
	char (*temp)[COLS] = oldArray;
	oldArray = newArray;
	newArray = temp;
}