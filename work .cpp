﻿#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<time.h>
#include<windows.h>
#include"Gobang.h"
#include"AI.h"
#define MAXLENGTH 100
void loading(){//显示效果 只有67行用了 不要可以注释掉
	int i;
	printf("Loading");
	for(i=1;i<=5;i++){
		printf("* ");
		Sleep(150);
	}
	printf("\n");
}


int main()
{
	int i = 0, j = 0;
	Board B;

head:
	system("cls");
	printf("设定棋盘大小");
	scanf("%d",&i);
	if(i<=5){
		goto head;
	}
	B.length=i;
	B.number=5;
start:
	for (i = 1; i <= B.length; i++) {
		for (j = 1; j <= B.length; j++){
			B.board[i][j] = ' ';//棋盘初始化为空格
			B.AIweight[i][j] = 0;//权值初始化为0
			B.Playerweight[i][j] = 0;
		}
	}
	system("cls");
	printf("1.玩家先手\t2.电脑先手\n请输入:");
	scanf("%d",&i);	
	while(i!=1&&i!=2){
		printf("请输入:");
		scanf("%d",&i);
	}
	if(i==2)
		B.board[B.length/2][B.length/2]='@';
	PrintfBoard(B);
	while (1) {
		printf("玩家的回合,输入坐标\n");
		scanf("%d", &i);
		scanf("%d", &j);
		while (player(B, i, j) != true) {
			printf("Error,重新输入\n");
			scanf("%d", &i);
			scanf("%d", &j);
		}

		PrintfBoard(B);
		
		if (judge(B) != -1) {
			printf("输入0退出,输入1重新开始,输入2重新设棋盘:");
			scanf("%d", &i);
			if (i == 0)
				return 0;
			else if (i == 1)
				goto start;
			else if (i == 2)
				goto head;
			else
				goto scan;
		}
		loading();
		printf("\n\n");
		AI(B);
		printf("\n\n");
		PrintfBoard(B);
		
		if (judge(B) != -1) {
			printf("输入0退出,输入1重新开始,输入2重新设棋盘:");
		scan:
			scanf("%d", &i);
			if (i == 0)
				return 0;
			else if (i == 1)
				goto start;
			else if (i == 2)
				goto head;
			else
				goto scan;
		}
	}
	return 0;
}


