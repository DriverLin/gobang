#include <iostream>
#include<windows.h>
#define true 1
#define false 0 
#define MAXLENGTH 100


/************************************
返回值代表的判断
2000002 成5
200002  活4
100002  死4
100001  低死4
10001   死3
20001   活3
2002    活2
20012   跳活3
1001    死2
2001    低活2
1       死
************************************/
int SDCPJ(char cheese[10]){
	int left=5 , right=5 , a , count ;
	char yes , no ;
	if(cheese[5] == '*'){
		yes = '*';
		no = '@';
	}
	else{
		yes = '@';
		no = '*';
	}

	for( a = 1 ; a <= 9 ; a++ ){
		if( cheese[a] != yes && cheese[a] != no && cheese[a] != ' ' )
			cheese[a] = no;//把棋盘边缘当作敌方棋子看
	}
	while( cheese[right] == yes )
		right++;
	while( cheese[left] == yes)
		left--;
	count =right-left-1;
	if(count >= 5)
		return 2000002;//成5
	if(count == 4){
		if(cheese[left] == ' ' && cheese[right] == ' ')
			return 200002;//活4
		if( (cheese[left] == ' '&& cheese[right] == no) || (cheese[left] == no && cheese[right] == ' '))//一边空 一边被堵
			return 100002;//死4
		if( cheese[left] == no && cheese[right] == no )
			return 1;//不可能成
	}
	if(count == 3){
		if(cheese[left] == ' ' && cheese[right] == ' '){//左右都空
			if( cheese[left-1] == no && cheese[right+1] == no){
				return 10001;//死3
			}
			if( cheese[left-1] == ' ' || cheese[right+1] == ' ' ){
				return 20001;//活3
			}
			if( cheese[left-1] == yes || cheese[right+1] == yes ){
				return 100002;
			}
		}

		else if ( cheese[left] == no && cheese[right] == no )//两边断开位置均非空
            return 1;//不可能成

        else if (cheese[left] == ' ' || cheese[right] == ' ')//两边断开位置只有一个空
        {

            if (cheese[left] == no) {//左边被对方堵住
                if (cheese[right+1] == no)//右边也被对方堵住
                    return 1;//不可成
                if (cheese[right+1] == ' ')//右边均空
                    return 10001;
                if (cheese[right+1] == yes)
                    return 100001;//低死4

            }
            if (cheese[right] == no) {//右边被对方堵住
                if (cheese[left-1] == no)//左边也被对方堵住
                    return 1;//不可成
                if (cheese[left-1] == ' ')//左边均空
                    return 10001;
                if (cheese[left-1] == yes)//左边还有自己的棋子
                    return 100001;//低死4
            }
        }
	}
	if (count == 2) {
        if (cheese[left] == ' ' && cheese[right] == ' '){//两边断开位置均空
            if ((cheese[right+1] == ' ' && cheese[right+2] == yes) || (cheese[left-1] == ' ' && cheese[left-2] == yes))
                return 10001;//死3
            else if (cheese[left-1] == ' ' && cheese[right+1] == ' ')
                return 2002;//活2
            if ((cheese[right+1] == yes && cheese[right+2] == no) || (cheese[left-1] == yes && cheese[left-2] == no))
                return 10001;//死3
            if ((cheese[right+1] == yes && cheese[right+2] == yes) || (cheese[left-1] == yes && cheese[left-2] == yes))
                return 100001;//低死4
            if ((cheese[right+1] == yes && cheese[right+2] == ' ') || (cheese[left-1] == yes && cheese[left-2] == ' '))
                return 20012;//跳活3
        }
        else if (cheese[left] == no && cheese[right] == no)//两边断开位置均非空
            return 1;
        else if (cheese[left] == ' ' || cheese[right] == ' '){//两边断开位置只有一个空
            if (cheese[left] == no) {//左边被对方堵住
                if (cheese[right+1] == no || cheese[right+2] == no)//只要有对方的一个棋子
                    return 1;//没有威胁
                else if (cheese[right+1] == ' ' && cheese[right+2] == ' ')//均空
                    return 1001;//死2
                else if (cheese[right+1] == yes && cheese[right+2] == yes)//均为自己的棋子
                    return 100001;//低死4
                else if (cheese[right+1] == yes || cheese[right+2] == yes)//只有一个自己的棋子
                    return 10001;//死3
            }
            if (cheese[right] == no) {//右边被对方堵住
                if (cheese[left-1] == no || cheese[left-2] == no)//只要有对方的一个棋子
                    return 1;//没有威胁
                else if (cheese[left-1] == ' ' && cheese[left-2] == ' ')//均空
                    return 1001;//死2
                else if (cheese[left-1] == yes && cheese[left-2] == yes)//均为自己的棋子
                    return 100001;//低死4
                else if (cheese[left-1] == yes || cheese[left-2] == yes)//只有一个自己的棋子
                    return 10001;//死3
            }
        }
}
	if(count == 1){
        if (cheese[left] == no && cheese[left-1] == yes && cheese[left-2] == yes && cheese[left-3] == yes)
            return 100001;//低死4
        if (cheese[right] == no && cheese[right+1] == yes && cheese[right+2] == yes && cheese[right+3] == yes)
            return 100001;//低死4
        if (cheese[left] == no && cheese[left-1] == yes && cheese[left-2] == yes && cheese[left-3] == no && cheese[right] == no)
            return 20012;//跳活3
        if (cheese[right] == no && cheese[right+1] == yes && cheese[right+2] == yes && cheese[right+3] == no && cheese[left] == no)
            return 20012;//跳活3
        if (cheese[left] == no && cheese[left-1] == yes && cheese[left-2] == yes && cheese[left-3] == no && cheese[right] == no)
            return 10001;//死3
        if (cheese[right] == no && cheese[right+1] == yes && cheese[right+2] == yes && cheese[right+3] == no && cheese[left] == no)
            return 10001;//死3
        if (cheese[left] == no && cheese[left-1] == no && cheese[left-2] == yes && cheese[left-3] == yes)
            return 10001;//死3
        if (cheese[right] == no && cheese[right+1] == no && cheese[right+2] == yes && cheese[right+3] == yes)
            return 10001;//死3
        if (cheese[left] == no && cheese[left-1] == yes && cheese[left-2] == no && cheese[left-3] == yes)
            return 10001;//死3
        if (cheese[right] == no && cheese[right+1] == yes && cheese[right+2] == no && cheese[right+3] == yes)
            return 10001;//死3
        if (cheese[left] == no && cheese[left-1] == yes && cheese[left-2] == no && cheese[left-3] == no && cheese[right] == no)
            return 2001;//低活2
        if (cheese[right] == no && cheese[right+1] == yes && cheese[right+2] == no && cheese[right+3] == no && cheese[left] == no)
            return 2001;//低活2
        if (cheese[left] == no && cheese[left-1] == no && cheese[left-2] == yes && cheese[left-3] == no && cheese[right] == no)
            return 2001;//低活2
        if (cheese[right] == no && cheese[right+1] == no && cheese[right+2] == yes && cheese[right+3] == no && cheese[left] == no)
            return 2001;//低活2
    }
	return 1;//其他全部返回1	
}


int weightcount(Board B ,int i ,int j , int kind){
	int count,left_i,left_j,right_i,right_j;
	int a,b,weight[5];
	char yes,no;
	char cheese[10];

	if(kind==1){
		yes='*';
		no='@';
	}
	else{
		yes='@';
		no='*';
	}
	B.board[i][j]=yes;
	//说明下 count为填上之后的连成数 left right ij是连城的两个端点
	//====================================================================================
	count=0;
	for( left_i = i , left_j = j ;count<5; left_i++ , left_j++ , count++ ){//斜下
		cheese[5+count]=B.board[left_i][left_j];
	}
	count=0;
	for( right_i = i , right_j = j ; count<5 ; right_i-- , right_j-- , count++ ){
		cheese[5-count]=B.board[right_i][right_j];
	}
	weight[1]=SDCPJ(cheese);
	//printf("SDCPJ=%d\n",SDCPJ(cheese));
	//====================================================================================
	count=0;
	for( left_i = i , left_j = j ;count<5; left_i++ , left_j , count++ ){//竖
		cheese[5+count]=B.board[left_i][left_j];
	}
	count=0;
	for( right_i = i , right_j = j ; count<5 ; right_i-- , right_j , count++ ){
		cheese[5-count]=B.board[right_i][right_j];
	}
	weight[2]=SDCPJ(cheese);
	//====================================================================================
	count=0;
	for( left_i = i , left_j = j ;count<5; left_i++ , left_j-- , count++ ){//斜上
		cheese[5+count]=B.board[left_i][left_j];
	}
	count=0;
	for( right_i = i , right_j = j ; count<5 ; right_i-- , right_j++ , count++ ){
		cheese[5-count]=B.board[right_i][right_j];
	}
	weight[3]=SDCPJ(cheese);
	//====================================================================================
	count=0;
	for( left_i = i , left_j = j ;count<5; left_i , left_j++ , count++ ){//横 
		cheese[5+count]=B.board[left_i][left_j];
	}
	count=0;
	for( right_i = i , right_j = j ; count<5 ; right_i , right_j-- , count++ ){
		cheese[5-count]=B.board[right_i][right_j];
	}
	weight[4]=SDCPJ(cheese);
	//====================================================================================

	B.board[i][j]=' ';//改回去

	for(count=1;count<=4;count++){
		if(weight[count]==2000002)
			return 100000;//成5 100000
	}
	for(count=1;count<=4;count++){
		if(weight[count]==200002)
			return 10000;//活4  10000 
	}
	//if(( weight[1] == 100002 && weight[3] == 100002 )||( weight[2] == 100002 && weight[4] == 100002 ))
	//	return 10000;//双死4
	for(i=1;i<=4;i++){
		for(j=i+1;j<=4;j++){
			if(weight[i]==100002&&weight[j]==100002)
				return 10000;//双死4
		}
	}
	//if(( weight[1] == 100002 && weight[3] == 20001 ) || ( weight[3] == 100002 && weight[1] == 20001 ) || ( weight[2] == 100002 && weight[4] == 20001 ) || ( weight[4] == 100002 && weight[2] == 20001 ))
	//	return 10000;//死4活3
	for(i=1;i<=4;i++){
		for(j=i+1;j<=4;j++){
			if((weight[i]==100002&&weight[j]==20001)||(weight[j]==100002&&weight[i]==20001))
				return 10000;//死4活3
		}
	}
	//if(( weight[1] == 20001 && weight[3] == 20001 )||( weight[2] == 20001 && weight[4] == 20001 ))
	//	return 5000;//双活3

	for(i=1;i<=4;i++){
		for(j=i+1;j<=4;j++){
			if((weight[i]==20001&&weight[j]==20001))
				return 5000;//双活3
		}
	}
	//if(( weight[1] ==  && weight[3] == 20001 ) || ( weight[3] == 10001 && weight[1] == 20001 ) || ( weight[2] == 10001 && weight[4] == 20001 ) || ( weight[4] == 10001 && weight[2] == 20001 ))
	//	return 1000;//死3活3
	for(i=1;i<=4;i++){
		for(j=i+1;j<=4;j++){
			if((weight[i]==10001&&weight[j]==20001)||(weight[j]==10001&&weight[i]==20001))
				return 1000;//死3活3
		}
	}
	for(count=1;count<=4;count++){
		if(weight[count]==100002)
			return 500;//死4  500 
	}
	for(count=1;count<=4;count++){
		if(weight[count]==100001)
			return 400;//低死4  500 
	}
	for(count=1;count<=4;count++){
		if(weight[count]==20001)
			return 100;//单活3  100 
	}
	for(count=1;count<=4;count++){
		if(weight[count]==20001)
			return 90;//跳活3  90 
	}
	//if( ( weight[1]==2002&&weight[3]==2002)||(weight[2]==2002&&weight[4]==2002))   //已修正
	//	return 50;//双活2 50
	for(i=1;i<=4;i++){
		for(j=i+1;j<=4;j++){
			if(weight[i]==2002&&weight[j]==2002)
				return 50;//双活2 50
		}
	}
	for(count=1;count<=4;count++){
		if(weight[count]==2002)
			return 10;//活2  10 
	}	
	for(count=1;count<=4;count++){
		if(weight[count]==2001)
			return 9;//低活2  9 
	}
	for(count=1;count<=4;count++){
		if(weight[count]==10001)
			return 5;//死3  5
	}
	for(count=1;count<=4;count++){
		if(weight[count]==1001)
			return 2;//死2  2
	}
	return 1;
}
