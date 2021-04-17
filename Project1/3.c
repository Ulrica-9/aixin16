#include "1.h"
void player(char ch[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("游戏开始：");
	while (1)
	{

		printf("玩家走--->");
		scanf_s("%d %d", &i, &j);
		if (i >= 1 && j <= col)
		{
			if (ch[i - 1][j - 1] == ' ')
			{
				ch[i - 1][j - 1] = '*';
				break;
			}
			else
			{
				printf("该位置已经被占用,请重新输入.\n");

			}

		}
		else
		{
			printf("格式违法,请重新输入:--->\n");
		}
	}

}
void computer(char ch[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("电脑走:-->\n");

	while (1)
	{
		i = rand() % row;
		j = rand() % col;
		if (ch[i][j] == ' ')
		{
			ch[i][j] = '#';
			break;
		}
		//测试
		/*else
		{
			printf ("该位置已经被占用\n");
		}*/

	}


}
char Isright(char ch[ROW][COL], int row, int col)
{
	int i, j;

	//行相等
	for (i = 0; i < row; i++)
	{
		if (ch[i][0] == ch[i][1] && ch[i][1] == ch[i][2] && ch[i][1] != ' ')
		{
			return ch[i][0];
		}
	}
	//列相等
	for (i = 0; i < row; i++)
	{
		if (ch[0][i] == ch[1][i] && ch[0][i] == ch[2][i] && ch[1][i] != ' ')
		{
			return ch[0][i];
		}
	}
	//队列相等
	if (ch[0][0] == ch[1][1] && ch[1][1] == ch[2][2] && ch[1][1] != ' ')
	{
		return ch[0][0];
	}
	if (ch[0][2] == ch[1][1] && ch[1][1] == ch[2][0] && ch[1][1] != ' ')
	{
		return ch[0][2];
	}
	//平局
	for (i = 0; i < row; i++)
	{
		j = 0;
		for (j = 0; j < col; j++)
		{
			if (ch[i][j] == ' ')
			{
				return 'Q';
			}
		}
	}
	return 'P';
}


void menu(void)
{
	printf("***********************************************\n");
	printf("*      1.>>>>>进行游戏   0.>>>>> 退出游戏     *\n");
	printf("***********************************************\n");
}
//重置数组函数
void unlook(char ch[ROW][COL], int row, int  col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		j = 0;
		for (j = 0; j < col; j++)
		{
			ch[i][j] = ' ';
		}
	}
}
//打印数组函数
void display(char ch[ROW][COL], int row, int  col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{

		//1.打印每一行
		j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", ch[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}

		}

		printf("\n");
		//2.行分割;
		if (i < row - 1)
		{
			j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}

			}

		}
		printf("\n");



	}
}
void game()
{
	char sc;
	char ch[ROW][COL] = { 0 };
	printf("请稍等即将进入游戏:");
	Sleep(1000);
	printf("-");
	Sleep(1000);
	printf("-");
	Sleep(1000);
	printf("-");
	Sleep(1000);
	printf("-");
	Sleep(1000);
	printf(">\n");
	Sleep(1000);
	/*重置数组:*/
	unlook(ch, ROW, COL);
	//打印棋盘
	   /* __ | __ | __
		__ | __ | __
		__ | __ | __*/
	display(ch, ROW, COL);
	//开始下棋
	while (1)
	{
		//玩家走
		player(ch, ROW, COL);
		//显示数组形式
		sc = Isright(ch, ROW, COL);
		if (sc != 'Q')
		{
			break;
		}

		display(ch, ROW, COL);
		//电脑走
		computer(ch, ROW, COL);
		/*显示电脑数组形式*/
		sc = Isright(ch, ROW, COL);
		if (sc != 'Q')
		{
			break;
		}
		display(ch, ROW, COL);
	}
	if (sc == '*')
	{
		printf("******玩家WIN******\n\n\n\n");
		printf("即将退出游戏:\n\n\n");


	}
	else
	{
		if (sc == '#')
		{
			printf("******电脑WIN******\n\n\n\n");
			printf("即将退出游戏:\n\n\n");

		}
		else
		{
			printf("******平局******\n\n\n\n");

		}
	}


}



void text(void)
{

	int num = 0;
	srand((unsigned int)time(NULL));

	do
	{

		menu();
		printf("请选择:----->");
		scanf_s("%d", &num);
		switch (num)
		{
		case 1:
			printf("五子棋.\n");
			game();

			break;
		case 0:
			printf("退出程序.\n");
			Sleep(1000);
			system("cls");
			break;
		default:
			Sleep(1000);
			printf(">>>>>>>>>>>>无法识别:%d\n", num);
			printf("请输入0或1用以退出或进行游戏:\n");

		}
	} while (num);
}