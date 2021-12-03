#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#define COW 9
#define COL 9
#define COWS COW+2
#define COLS COL+2
#define MINE 10

void InitialBoard(char arr[COWS][COLS], int cows, int cols, char set);
void DisplayBoard(char arr[COWS][COLS], int cows, int cols);
void SetMine(char mine[COWS][COLS], int cow, int col, int min);
int MineNumber(char mine[][COLS], int x, int y);
void ExtendCell(char mine[COWS][COLS], char show[COWS][COLS], int x, int y);
