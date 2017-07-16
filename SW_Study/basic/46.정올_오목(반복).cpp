

//창훈 최종품// 교재 알고리즘 생각으로품.
#include<stdio.h>

#define N 19
int map[N+1][N+1];


void input()
{
	freopen("input.txt","r",stdin);

	for(int x=1;x<=N;x++)
	for(int y=1;y<=N;y++)
	scanf("%d",&map[x][y]);
}

int checkbound(int x, int y)
{
	if( x <= 0 || x > N ||
		y <= 0 || y > N
	  )
	  return 0;

	return 1;
}

int first(int i, int j)
{
	int x=i;
	int y=j;

	if(checkbound(x+1, y-1)) //역방향 후보군이 경계를 넘어서지 않을때만 사용함.
	if(map[x][y]==map[x+1][y-1]) return 0;
	
	int stone=map[x][y];
	int count=0; 

	do{
		x--;
		y++;
		count++;
	}while(map[x][y]==stone && checkbound(x, y) );

	//printf("x:%d y:%d stone:%d count:%d\n",i,j,stone,count);

	if(count==5){printf("%d\n%d %d\n",stone,i,j); return 1;}
    else return 0;
}


int second(int i, int j)
{
	int x=i;
	int y=j;

	if(checkbound(x, y-1)) //역방향 후보군이 경계를 넘어서지 않을때만 사용함.
	if(map[x][y]==map[x][y-1]) return 0;
	
	int stone=map[x][y];
	int count=0; 

	do{
		y++;
		count++;
	}while(map[x][y]==stone && checkbound(x, y) );

	//printf("x:%d y:%d stone:%d count:%d\n",i,j,stone,count);

	if(count==5){printf("%d\n%d %d\n",stone,i,j); return 1;}
    else return 0;
}



int third(int i, int j)
{
	int x=i;
	int y=j;

	if(checkbound(x-1, y-1)) //역방향 후보군이 경계를 넘어서지 않을때만 사용함.
	if(map[x][y]==map[x-1][y-1]) return 0;
	
	int stone=map[x][y];
	int count=0; 

	do{
		x++;
		y++;
		count++;
	}while(map[x][y]==stone && checkbound(x, y) );

	//printf("x:%d y:%d stone:%d count:%d\n",i,j,stone,count);

	if(count==5){printf("%d\n%d %d\n",stone,i,j); return 1;}
    else return 0;
}


int fourth(int i, int j)
{
	int x=i;
	int y=j;

	if(checkbound(x-1, y)) //역방향 후보군이 경계를 넘어서지 않을때만 사용함.
	if(map[x][y]==map[x-1][y]) return 0;
	
	int stone=map[x][y];
	int count=0; 

	do{
		x++;
		count++;
	}while(map[x][y]==stone && checkbound(x, y) );

	//printf("x:%d y:%d stone:%d count:%d\n",i,j,stone,count);

	if(count==5){printf("%d\n%d %d\n",stone,i,j); return 1;}
    else return 0;
}


void solve()
{
    for(int x=1;x<=N;x++)
	for(int y=1;y<=N;y++)
	{
		if(map[x][y])
		{
			//예약된 4방향에 대해서 체크
			int result=0;

			result=first(x,y);	
			if(result==1) return;

			result=second(x,y);	
			if(result==1) return;

			result=third(x,y);	
			if(result==1) return;

			result=fourth(x,y);		
			if(result==1) return;

		}
	}
}


void main()
{
	input();
	solve();

}



0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 1 2 0 0 2 2 2 1 0 0 0 0 0 0 0 0 0 0
0 0 1 2 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0
0 0 0 1 2 1 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 1 1 2 2 1 2 2 0 0 0 0 0 0 0 0 0
0 0 1 1 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 2 1 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0


->
1 
3 2
 




//창훈 최종 필기

//교재 알고리즘이다 깔끔하다.
//이 방법을 익혀 놓도록

#include<stdio.h>

int map[21][21]; //하나 더 크게 잡는다, 범위에 대해서 신경 안쓰기 위해서.

void input()
{
 freopen("input.txt","r",stdin);
 
 for(int i=1;i<=19;i++)
 for(int j=1;j<=19;j++)
 {
	 scanf("%d",&map[i][j]);
 }
	 
}

int check1(int i,int j,int stone)
{
	int count=0;
	for(;map[i][j]==stone;i--,j++) // 이 표현 깔끔하다.
	{
		count++;
	}
	if(count==5) return 1;
	else return 0;
}

int check2(int i,int j,int stone)
{
	int count=0;
	for(;map[i][j]==stone;j++)
	{
		count++;
	}
	if(count==5) return 1;
	else return 0;
}

int check3(int i,int j,int stone)
{
	int count=0;
	for(;map[i][j]==stone;i++,j++)
	{
		count++;
	}
	if(count==5) return 1;
	else return 0;
}

int check4(int i,int j,int stone)
{
	int count=0;
	for(;map[i][j]==stone;i++)
	{
		count++;
	}
	if(count==5) return 1;
	else return 0;
}


void main()
{
	input();

	for(int i=1;i<=19;i++)
	for(int j=1;j<=19;j++)
	{
		
		int stone=map[i][j];
		
		if(stone!=0)
		{
			//1번 방향 필기 참조
			if(map[i+1][j-1]!=stone && check1(i,j,stone))
			{
			   printf("%d\n%d %d",stone,i,j);
			   return;
			}
	
			//2번 방향 필기 참조
			if(map[i][j-1]!=stone && check2(i,j,stone))
			{
			   printf("%d\n%d %d",stone,i,j);	
			   return;
			}
		
			//3번 방향 필기 참조
			if(map[i-1][j-1]!=stone && check3(i,j,stone))
			{
			   printf("%d\n%d %d",stone,i,j);	
			   return;
			}

			//4번 방향 필기 참조
			if(map[i-1][j]!=stone && check4(i,j,stone))
			{
			   printf("%d\n%d %d",stone,i,j);	
			   return;
			}
			
		}
		
	}
	
   printf("0");
	
}





//창훈 다른 풀이
#include<stdio.h>
#define N 19

int MAP[N][N];


//해당 좌표가 경계를 넘어가나?
int checkBound(int x, int y)
{
	if(x>=0 && y>=0 &&
	   x<N	&& y<N)
	   return 1;

	return 0;
}


int func_1(int x, int y, int stone)
{
	int new_x=x;
	int new_y=y;
	int count=0;

	do
	{
		if(stone == MAP[new_x][new_y])
		{
			count++;
			new_x--;
			new_y++;
		}
		else
		{
			break;
		}
	}while(checkBound(new_x,new_y));

	return count;
}

int func_2(int x, int y, int stone)
{
	int new_x=x;
	int new_y=y;
	int count=0;

	do
	{
		if(stone == MAP[new_x][new_y])
		{
			count++;
			new_y++;
		}
		else
		{
			break;
		}
	}while(checkBound(new_x,new_y));

	return count;
}

int func_3(int x, int y, int stone)
{
	int new_x=x;
	int new_y=y;
	int count=0;

	do
	{
		if(stone == MAP[new_x][new_y])
		{
			count++;
			new_x++;
			new_y++;
		}
		else
		{
			break;
		}
	}while(checkBound(new_x,new_y));

	return count;
}

int func_4(int x, int y, int stone)
{
	int new_x=x;
	int new_y=y;
	int count=0;

	do
	{
		if(stone == MAP[new_x][new_y])
		{
			count++;
			new_x++;
		}
		else
		{
			break;
		}
	}while(checkBound(new_x,new_y));

	return count;
}

void main()
{
	freopen("input.txt","r",stdin);

	for(int x=0;x<N;x++)
	for(int y=0;y<N;y++)
	{
		scanf("%d",&MAP[x][y]);
	}


	for(int x=0;x<N;x++)
	for(int y=0;y<N;y++)
	{
		if(MAP[x][y]==1 || MAP[x][y]==2)
		{
			 int current_stone=MAP[x][y];

			//1
			 if(checkBound(x+1,y-1))
			 {
				 if(MAP[x+1][y-1]==current_stone) continue;
			 }
			
			 if(func_1(x,y,current_stone)==5){ 
			  printf("%d\n",current_stone);
			  printf("%d %d\n",x+1,y+1);
			  return;
			 }

			//2
			 if(checkBound(x,y-1))
			 {
				 if(MAP[x][y-1]==current_stone) continue;
			 }
			
			 if(func_2(x,y,current_stone)==5){ 
			  printf("%d\n",current_stone);
			  printf("%d %d\n",x+1,y+1);
			  return;
			 }

			//3
			 if(checkBound(x-1,y-1))
			 {
				 if(MAP[x-1][y-1]==current_stone) continue;
			 }
			
			 if(func_3(x,y,current_stone)==5){ 
			  printf("%d\n",current_stone);
			  printf("%d %d\n",x+1,y+1);
			  return;
			 }

			//4
			if(checkBound(x-1,y))
			 {
				 if(MAP[x-1][y]==current_stone) continue;
			 }
			
			 if(func_4(x,y,current_stone)==5){ 
			  printf("%d\n",current_stone);
			  printf("%d %d\n",x+1,y+1);
			  return;
			 }

		}
	}
}


































//아래 이전 내 알고리즘은 비효율적임
//위의 교재 알고리즘으로 익혀 놓는다.


//////////////////////////////////////////////////////////////

오목은 바둑판에 검은 바둑알과 흰 바둑알을 교대로 놓아서 겨루는 게임이다. 
바둑판에는 가로, 세로 19개의 선으로 이루어져 있다.

오목은 위의 그림에서와 같이 같은 색의 바둑알이 연속적으로 다섯 알이 놓이면
그 색이 이기게 된다. 

여기서 연속적이란 가로, 세로 또는 대각선 방향 모두를 뜻한다.

즉, 위의 그림은 검은색이 이긴 경우이다. 하지만 여섯 알 이상이 연속적으로 놓인

경우에는 이긴 것이 아니다. 입력으로 바둑판의 어떤 상태가 주어졌을 때, 검은색이

이겼는지, 흰색이 이겼는지 또는 아직 승부가 결정되지 않았는지를 판단하는 프로그

램을 작성하시오.

단, 검은색과 흰색이 동시에 이기거나 검은색 또는 흰색이 두 군데 이상에서 동시
에 이기는 경우는 입력으로 들어오지 않는다.

입력
입력 파일은 19줄에 각 줄마다 19개의 숫자로 표현되는데, 검은 바둑알은 1, 흰 바
둑알은 2, 알이 놓이지 않은 자리는 0으로 표시되며, 숫자는 한 칸씩 띄어서 표시된다.
출력
첫 번째 줄에 검은색이 이겼을 경우에는 1을, 흰색이 이겼을 경우에는 2를, 아직
승부가 결정되지 않았을 경우에는 0을 출력한다. 검은색 또는 흰색이 이겼을 경우에
는 둘째 줄에 연속된 다섯 개의 바둑알 중에서 가장 왼쪽에 있는 바둑알(연속된 다
섯 개의 바둑알이 세로로 놓인 경우, 그중 가장 위에 있는 것)의 가로줄 번호와 세로
줄 번호를 순서대로 출력한다.
입력 예 출력 예
위 그림과 같은 경우
1
3 2
출처: 한국정보올림피아드(2003 전국본선 초등부)

//>>

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
2 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 1 2 1 2 2 2 1 2 0 0 0 0 0 0 0 0 0 0
0 0 1 2 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0
0 0 0 2 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 2 2 1 2 2 0 0 0 0 0 0 0 0 0
0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 2 0 0 2 1 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

//<<

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//창훈품. 어렵지 않음, 책에 필기 참조
//오목 
#include<stdio.h>
#define SIZE 19

int map[SIZE+1][SIZE+1];

void main()
{
	freopen("input.txt","r",stdin);
	
	for(int i=1;i<=SIZE;i++)
		for(int j=1;j<=SIZE;j++)
		{ 
			scanf(" %d",&map[i][j]);
		}
	
	for(int i=1;i<=SIZE;i++)
		for(int j=1;j<=SIZE;j++)
		{
			if(map[i][j]==1 || map[i][j]==2)
			{
				int stone=map[i][j];

				int new_i=i;
				int new_j=j;
				int stone_count=1;

				int return_new_i;
				int return_new_j;

				//1
				//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
				while(1)
				{
					new_i--;
					new_j++;

					if(new_i<0 || new_j>SIZE) break;

					if(stone!=map[new_i][new_j]) break;
				}

				//real cord  // 하나를 빼줘야함.
				new_i++;
				new_j--;

				while(1)
				{
					new_i++;
					new_j--;

					if(new_i>SIZE || new_j<0) break;

					if(stone==map[new_i][new_j])stone_count++;
					else break;
				}
					
				new_i--;
				new_j++;

				return_new_i=new_i;
				return_new_j=new_j;

				 //printf("#1 stone:%d count:%d \n",stone,stone_count);
				if(stone_count==5) {
					printf("%d\n%d %d\n",stone,return_new_i,return_new_j);
					return;
				}
				//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

				 new_i=i;
				 return_new_j=new_j=j;
                 stone_count=1;

				//2
				//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
				 while(1)
				{
					new_i--;
			
					if(new_i<0 ) break;

					if(stone!=map[new_i][new_j]) break;
				}

				//real cord  // 하나를 빼줘야함.
				new_i++;

				return_new_i=new_i;

				while(1)
				{
					new_i++;

					if(new_i>SIZE ) break;

					if(stone==map[new_i][new_j])stone_count++;
					else break;
				}
					
				new_i--;
				
				// printf("#2 stone:%d count:%d \n",stone,stone_count);
				if(stone_count==5) {
					printf("%d\n%d %d\n",stone,return_new_i,return_new_j);
					return;
				}


				 new_i=i;
				 new_j=j;
                 stone_count=1;

				//3
				//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
				 while(1)
				{
					new_i--;
					new_j--;
			
					if(new_i<0 || new_j<0) break;

					if(stone!=map[new_i][new_j]) break;
				}

				//real cord  // 하나를 빼줘야함.
				new_i++;
				new_j++;

				 return_new_i=new_i;
				 return_new_j=new_j;

				while(1)
				{
					new_i++;
					new_j++;

					if(new_i>SIZE || new_j>SIZE) break;

					if(stone==map[new_i][new_j])stone_count++;
					else break;
				}
					
				new_i--;
				new_j--;
				
				//printf("#3 stone:%d count:%d \n",stone,stone_count);
				if(stone_count==5) {
					printf("%d\n%d %d\n",stone,return_new_i,return_new_j);
					return;
				}


				 new_i=new_i=i;
				 new_j=j;
                 stone_count=1;

				//4
				//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
				 while(1)
				{
					new_j--;
			
					if(new_j<0) break;

					if(stone!=map[new_i][new_j]) break;
				}

				//real cord  // 하나를 빼줘야함.
				new_j++;

				return_new_j=new_j;

				while(1)
				{
					new_j++;

					if( new_j>SIZE) break;

					if(stone==map[new_i][new_j])stone_count++;
					else break;
				}
					
				new_j--;
				
				//printf("#4 stone:%d count:%d \n",stone,stone_count);
				if(stone_count==5) {
					printf("%d\n%d %d\n",stone,return_new_i,return_new_j);
					return;
				}

			}
		}
}



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//교재 방법
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#include<stdio.h>


int map[19+2][19+2];  //전역변수라서 0으로 초기 

int check1(int i,int j,int c)
{
  int cnt=0;
  for(;map[i][j]==c;i--,j++)
  {
	  cnt++;
  } 
  //printf("check 1 %d \n",cnt);
  return cnt;
}

int check2(int i,int j,int c)
{
  int cnt=0;
  for(;map[i][j]==c;j++)
  {
	  cnt++;
  } 
 // printf("check 2 %d \n",cnt);
  return cnt;
}

int check3(int i,int j,int c)
{
  int cnt=0;
  for(;map[i][j]==c;i++,j++)
  {
	  cnt++;
  } 
 // printf("check 3 %d \n",cnt);
  return cnt;
}

int check4(int i,int j,int c)
{
  int cnt=0;
  for(;map[i][j]==c;i++)
  {
	  cnt++;
  } 
//  printf("check 4 %d \n",cnt);
  return cnt;
}


void solve()
{
	for(int i=1; i <= 19 ; i++)
	for(int j=1; j <= 19 ; j++)
	{	
	  if(map[i][j]==1 || map[i][j] ==2)
	  {	  
		 //1 
		if(map[i+1][j-1]!=map[i][j]) //이전 방향에서 같은 색깔이 아니어야지 첨으로 체크하는 방향이다.
		{
			if(check1(i,j,map[i][j])==5)
			{
				printf("%d\n%d %d",map[i][j],i,j); // real postion.
				return;
			}	
		}

		 //2 
		if(map[i][j-1]!=map[i][j]) //이전 방향에서 같은 색깔이 아니어야지 첨으로 체크하는 방향이다.
		{
			if(check2(i,j,map[i][j])==5)
			{
				printf("%d\n%d %d",map[i][j],i,j); // real postion.
				return;
			}	
		}

		//3 
		if(map[i-1][j-1]!=map[i][j]) //같은 색깔이 아니어야지 첨으로 체크하는 방향이다.
		{
			if(check3(i,j,map[i][j])==5)
			{
				printf("%d\n%d %d",map[i][j],i,j); // real postion.
				return;
			}	
		}

		//4 
		if(map[i-1][j]!=map[i][j]) //같은 색깔이 아니어야지 첨으로 체크하는 방향이다.
		{
			if(check4(i,j,map[i][j])==5)
			{
				printf("%d\n%d %d",map[i][j],i,j); // real postion.
				return;
			}	
		}				
		  
		
	  }
	}

	printf("0"); // real postion.
}

int main(void)
{	
	//freopen("input.txt", "r", stdin);
	//setbuf(stdout, NULL);
	
	int i, j;
	for(i=1; i<=19; i++)
	{
		for(j=1; j<=19; j++)
		{
		   scanf("%d",&map[i][j]);
		//   printf("%d",map[i][j]);
		}
		//printf("\n");
	}
	solve();
}



