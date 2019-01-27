#include <iostream>
#include <time.h>
#include"weight.h"
#define true 1
#define false 0 
#define MAXLENGTH 10000
using namespace std;


typedef struct chess
{
	int i;
	int j;
	int AIweight;
	int Playerweight;
} chess;

void updateweight(Board &B){
	int i ,j ;
	for(i =1 ; i <= B.length ; i++){
		for(j =1 ; j <= B.length ; j++){
			if(B.board[i][j]!=' '){
				B.AIweight[i][j]=0;
				B.Playerweight[i][j]=0;
			}
			else {
				B.AIweight[i][j]=weightcount(B, i, j , 0);
				B.Playerweight[i][j]=weightcount(B, i, j , 1);
			}
		}
	}
}

void AI(Board &B) {
	int i, j, AIMaxWeight = 0 , PlayerMaxWeight = 0 , a = 0, b = 0 ;
	chess che[MAXLENGTH];
	int count=0;
	updateweight(B);
	for(i=1;i<=B.length;i++){
		for(j=1;j<=B.length;j++){
			if(B.AIweight[i][j]>=AIMaxWeight){
				AIMaxWeight=B.AIweight[i][j];
			}
		}
	}
	for(i=1;i<=B.length;i++){
		for(j=1;j<=B.length;j++){
			if(B.Playerweight[i][j]>=PlayerMaxWeight){
				PlayerMaxWeight=B.Playerweight[i][j];
			}
		}
	}
	if(AIMaxWeight>=PlayerMaxWeight){//电脑大于玩家 落子在电脑和玩家都最大的位置
		PlayerMaxWeight=0;
		for(i=1;i<=B.length;i++){
			for(j=1;j<=B.length;j++){
				if(B.AIweight[i][j]==AIMaxWeight && B.Playerweight[i][j]>=PlayerMaxWeight){
					PlayerMaxWeight=B.Playerweight[i][j];
					a=i;
					b=j;
				}
			}
		}
		B.board[a][b]='@';
	}
	else{
		AIMaxWeight=0;
		for(i=1;i<=B.length;i++){
			for(j=1;j<=B.length;j++){
				if(B.Playerweight[i][j]==PlayerMaxWeight && B.AIweight[i][j]>=AIMaxWeight){
					AIMaxWeight=B.AIweight[i][j];
					a=i;
					b=j;
				}
			}
		}
		B.board[a][b]='@';
	}
}
