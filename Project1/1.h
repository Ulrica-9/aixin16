#pragma once
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3

void text(void);
void menu(void);
void unlook(char ch[ROW][COL], int row, int  col);
void display(char ch[ROW][COL], int row, int  col);
void player(char ch[ROW][COL], int row, int col);
void computer(char ch[ROW][COL], int row, int col);
char Isright(char ch[ROW][COL], int row, int col);
//���ܻ������ֽ��
//����Ӯ..........#
//���Ӯ..........*
//ƽ��............P(�������˶�û�зֳ�ʤ��)
//����............Q
