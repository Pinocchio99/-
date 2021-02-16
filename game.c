#include"game.h"

void InitialBoard(char arr[COWS][COLS], int cows, int cols, char set)
{
	for (int i = 0; i < cows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = set;
		}
	}
}

void DisplayBoard(char arr[COWS][COLS], int cow, int col)
{
	for (int i = 0; i <= cow; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 1; i <= cow; i++)
	{
		printf("%d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char mine[COWS][COLS], int cow, int col,int min)
{
	int count = min;
	while (count > 0)
	{
		int x, y;
		x = rand() % col + 1;
		y = rand() % cow + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}
int MineNumber(char mine[COWS][COLS],int x,int y)
{
	return mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x - 1][y] +
		mine[x + 1][y] +
		mine[x - 1][y - 1] +
		mine[x + 1][y - 1] +
		mine[x - 1][y + 1] +
		mine[x + 1][y + 1]-8*'0';
}
void ExtendCell(char mine[COWS][COLS],char show[COWS][COLS], int x, int y)
{
	if (show[x][y] == '0')
	{
		if (x - 1 > 0 && x - 1 < COWS&&y-1>0&&y-1<COLS&& show[x - 1][y - 1]=='*')
		{
			show[x - 1][y - 1] = MineNumber(mine, x - 1, y - 1) + '0';
			ExtendCell(mine, show, x - 1, y - 1);
			//DisplayBoard(show, COW, COL);
		}
		if (x > 0 && x < COWS && y - 1 > 0 && y - 1 < COLS&&show[x][y - 1] == '*')
		{
			show[x][y - 1] = MineNumber(mine, x, y - 1) + '0';
			ExtendCell(mine, show, x, y - 1);
			//DisplayBoard(show, COW, COL);
		}
		if (x + 1 > 0 && x + 1 < COWS && y - 1 > 0 && y - 1 < COLS && show[x + 1][y - 1] == '*')
		{
			show[x + 1][y - 1] = MineNumber(mine, x + 1, y - 1) + '0';
			ExtendCell(mine, show, x + 1, y - 1);
			//DisplayBoard(show, COW, COL);
		}
		if (x - 1 > 0 && x - 1 < COWS && y > 0 && y < COLS && show[x - 1][y] == '*')
		{
			show[x - 1][y] = MineNumber(mine, x - 1, y) + '0';
			ExtendCell(mine, show, x - 1, y);
			//DisplayBoard(show, COW, COL);
		}
		if (x + 1 > 0 && x + 1 < COWS && y > 0 && y < COLS && show[x + 1][y] == '*')
		{
			show[x + 1][y] = MineNumber(mine, x + 1, y) + '0';
			ExtendCell(mine, show, x + 1, y);
			//DisplayBoard(show, COW, COL);
		}
		if (x - 1 > 0 && x - 1 < COWS && y + 1 > 0 && y + 1 < COLS && show[x - 1][y + 1] == '*')
		{
			show[x - 1][y + 1] = MineNumber(mine, x - 1, y + 1) + '0';
			ExtendCell(mine, show, x - 1, y + 1);
			//DisplayBoard(show, COW, COL);
		}
		if (x > 0 && x < COWS && y + 1 > 0 && y + 1 < COLS && show[x][y + 1] == '*')
		{
			show[x][y + 1] = MineNumber(mine, x, y + 1) + '0';
			ExtendCell(mine, show, x, y + 1);
			//DisplayBoard(show, COW, COL);
		}
		if (x + 1 > 0 && x + 1 < COWS && y + 1 > 0 && y + 1 < COLS && show[x + 1][y + 1] == '*')
		{
			show[x + 1][y + 1] = MineNumber(mine, x + 1, y + 1) + '0';
			ExtendCell(mine, show, x + 1, y + 1);
			//DisplayBoard(show, COW, COL);
		}
		else
			return;
	}
}