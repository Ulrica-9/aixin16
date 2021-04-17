#include "1.h"
void player(char ch[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("��Ϸ��ʼ��");
	while (1)
	{

		printf("�����--->");
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
				printf("��λ���Ѿ���ռ��,����������.\n");

			}

		}
		else
		{
			printf("��ʽΥ��,����������:--->\n");
		}
	}

}
void computer(char ch[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("������:-->\n");

	while (1)
	{
		i = rand() % row;
		j = rand() % col;
		if (ch[i][j] == ' ')
		{
			ch[i][j] = '#';
			break;
		}
		//����
		/*else
		{
			printf ("��λ���Ѿ���ռ��\n");
		}*/

	}


}
char Isright(char ch[ROW][COL], int row, int col)
{
	int i, j;

	//�����
	for (i = 0; i < row; i++)
	{
		if (ch[i][0] == ch[i][1] && ch[i][1] == ch[i][2] && ch[i][1] != ' ')
		{
			return ch[i][0];
		}
	}
	//�����
	for (i = 0; i < row; i++)
	{
		if (ch[0][i] == ch[1][i] && ch[0][i] == ch[2][i] && ch[1][i] != ' ')
		{
			return ch[0][i];
		}
	}
	//�������
	if (ch[0][0] == ch[1][1] && ch[1][1] == ch[2][2] && ch[1][1] != ' ')
	{
		return ch[0][0];
	}
	if (ch[0][2] == ch[1][1] && ch[1][1] == ch[2][0] && ch[1][1] != ' ')
	{
		return ch[0][2];
	}
	//ƽ��
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
	printf("*      1.>>>>>������Ϸ   0.>>>>> �˳���Ϸ     *\n");
	printf("***********************************************\n");
}
//�������麯��
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
//��ӡ���麯��
void display(char ch[ROW][COL], int row, int  col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{

		//1.��ӡÿһ��
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
		//2.�зָ�;
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
	printf("���Եȼ���������Ϸ:");
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
	/*��������:*/
	unlook(ch, ROW, COL);
	//��ӡ����
	   /* __ | __ | __
		__ | __ | __
		__ | __ | __*/
	display(ch, ROW, COL);
	//��ʼ����
	while (1)
	{
		//�����
		player(ch, ROW, COL);
		//��ʾ������ʽ
		sc = Isright(ch, ROW, COL);
		if (sc != 'Q')
		{
			break;
		}

		display(ch, ROW, COL);
		//������
		computer(ch, ROW, COL);
		/*��ʾ����������ʽ*/
		sc = Isright(ch, ROW, COL);
		if (sc != 'Q')
		{
			break;
		}
		display(ch, ROW, COL);
	}
	if (sc == '*')
	{
		printf("******���WIN******\n\n\n\n");
		printf("�����˳���Ϸ:\n\n\n");


	}
	else
	{
		if (sc == '#')
		{
			printf("******����WIN******\n\n\n\n");
			printf("�����˳���Ϸ:\n\n\n");

		}
		else
		{
			printf("******ƽ��******\n\n\n\n");

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
		printf("��ѡ��:----->");
		scanf_s("%d", &num);
		switch (num)
		{
		case 1:
			printf("������.\n");
			game();

			break;
		case 0:
			printf("�˳�����.\n");
			Sleep(1000);
			system("cls");
			break;
		default:
			Sleep(1000);
			printf(">>>>>>>>>>>>�޷�ʶ��:%d\n", num);
			printf("������0��1�����˳��������Ϸ:\n");

		}
	} while (num);
}