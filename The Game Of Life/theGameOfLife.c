#include <stdio.h>
#include <stdlib.h>
#define ROWS 22
#define COLS 42

void readFile(char oldArray[][COLS], int rows, FILE *fileHandle);
int countNeighbors(const char oldArray[][COLS], int i, int j);
void calculateNextGeneration(const char oldArray[][COLS], char newArray[][COLS], int rows);

int main(void)
{
	char oldArray[ROWS][COLS];
	char newArray[ROWS][COLS];


	char testArray[ROWS][COLS] = 
	{{"                                         "},
	{"                                         "},
	{"                                         "},
	{"                                         "},
	{"        ***                              "},
	{"        ***                              "},
	{"        ***                              "},
	{"                                         "},
	{"                                         "},
	{"                                         "},
	{"                                         "},
	{"                                         "},
	{"                                         "},
	{"                                         "},
	{"                                         "},
	{"                                         "},
	{"                                         "},
	{"                                         "},
	{"                                         "},
	{"                                         "},
	{"                                         "},
	{"                                         "}};

	printf("%d",countNeighbors(testArray, 5, 9));

	getchar();
	return EXIT_SUCCESS;
}

int countNeighbors(const char oldArray[][COLS], int i, int j)
{
	int row = i - 1; //the row above row i
	int column = j - 1; // the column left of column j
	int neighborCount = 0;
	char lifeChar = '*';

	// go through each row and column on the 3x3 grid of neighbors. 
	// Keep count of the neighbors
	// ignoring the center (or origional point i,j)
	for (row = (i - 1); row <= (i + 1); row++)
	{
		for (column = (j - 1); column <= (j + 1); column++)
		{
			if (row == i && column == j)
				;//do nothing
			else if (oldArray[row][column] == lifeChar)
				neighborCount++;
		}
	}
	return neighborCount;	
}