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
	//������������
	char mine[COWS][COLS];
	//������ʾ����
	char show[COWS][COLS];
	//��ʼ������
	InitialBoard(mine, COWS, COLS, '0');
	InitialBoard(show, COWS, COLS, '*');
	//չʾ��Ϸ�ű�
	//DisplayBoard(mine, COW, COL);
	//չʾ��Ϸ����ҳ��
	DisplayBoard(show, COW, COL);
	//��������
	SetMine(mine,COW,COL,MINE);
	DisplayBoard(mine, COW, COL);
	//����
	//int easy_count = COW * COL - MINE;
	int x, y;
	do
	{

		printf("���ף��������꣺");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= COL && y >= 1 && y <= COW)
		{
			if (mine[x][y] == '1')
			{
				printf("�㱻ը��\n");
				DisplayBoard(mine, COW, COL);
				break;
			}

			else
				if (show[x][y] == '*')
				{
					show[x][y] = MineNumber(mine, x, y) + '0';
					//�����Χû���ף�����ʾ��Χһ�и���
					ExtendCell(mine,show, x, y);
					
					DisplayBoard(show, COW, COL);
					//easy_count--;//����Ҫ�ú������м��������и��Ӷ�����'*'��Ӯ��
				}
				else
					printf("���ӱ�ռ�����������룺");
		}
		else
			printf("���뷶Χ���ԣ���������");
	} while (1);// (easy_count);
	//if (easy_count == 0)
		//printf("��ϲ��ʤ����\n");
}

void test()
{
	int input;
	//�Ƿ������Ϸ
	do
	{
		//��ʾ�˵�
		meun();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			
			game();
			break;//�˴���break������switch������������do while��whileѭ������(input)����
		case 0:
			break;
		default:
			printf("��������������룺");
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}