#include <stdio.h>
#include <stdlib.h>
#define ROWS 22
#define COLS 42

void readFile(char oldArray[][COLS], int rows, FILE *fileHandle);
int coundNeighbors(const oldArray[][COLS], int i, int j);
void calculateNextGeneration(const oldArray[][COLS], newArray[][COLS], int rows);

int main(void)
{
	char oldArray[ROWS][COLS];
	char newArray[ROWS][COLS];



	return EXIT_SUCCESS;
}