#include"game.h"

void meun()
{
	printf("*************************\n");
	printf("***** Play:1   No:0 *****\n");
	printf("*************************\n");
}



void game()
{
	srand((unsigned)time(NULL));
	//创建雷区数组
	char mine[COWS][COLS];
	//创建显示数组
	char show[COWS][COLS];
	//初始化数组
	InitialBoard(mine, COWS, COLS, '0');
	InitialBoard(show, COWS, COLS, '*');
	//展示游戏脚本
	//DisplayBoard(mine, COW, COL);
	//展示游戏操作页面
	DisplayBoard(show, COW, COL);
	//放置雷区
	SetMine(mine,COW,COL,MINE);
	DisplayBoard(mine, COW, COL);
	//排雷
	//int easy_count = COW * COL - MINE;
	int x, y;
	do
	{

		printf("排雷：输入坐标：");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= COL && y >= 1 && y <= COW)
		{
			if (mine[x][y] == '1')
			{
				printf("你被炸死\n");
				DisplayBoard(mine, COW, COL);
				break;
			}

			else
				if (show[x][y] == '*')
				{
					show[x][y] = MineNumber(mine, x, y) + '0';
					//如果周围没有雷，则显示周围一切格子
					ExtendCell(mine,show, x, y);
					
					DisplayBoard(show, COW, COL);
					//easy_count--;//满了要用函数进行检索，所有格子都不是'*'则赢了
				}
				else
					printf("格子被占，请重新输入：");
		}
		else
			printf("输入范围不对，重新输入");
	} while (1);// (easy_count);
	//if (easy_count == 0)
		//printf("恭喜，胜利！\n");
}

void test()
{
	int input;
	//是否进入游戏
	do
	{
		//显示菜单
		meun();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			
			game();
			break;//此处的break是跳出switch函数，而不是do while，while循环是由(input)控制
		case 0:
			break;
		default:
			printf("输入错误，重新输入：");
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}