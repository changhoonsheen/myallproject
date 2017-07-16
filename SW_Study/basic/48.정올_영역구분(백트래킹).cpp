/*
51
Part
관계기반 알고리즘의 설계 Ⅰ
문제 6
영역 구분
아래 그림과 같이 여러 개의 정사각형 칸들로 이루어진 정사각형 모양의 영역이
주어져 있고, 각 정사각형 칸들은 정올이의 땅은 흰색으로 칠해져 있고 영재의 땅은
검은색으로 칠해져 있다. 주어진 땅을 일정한 규칙에 따라 나누어 다양한 크기를 가
진 정사각형 모양의 하얀색 또는 회색 영역으로 구분하려고 한다.
[그림 1]
전체 영역의 크기가 n*n (n=  , k는 1 이상 7 이하의 자연수) 이라면 영역을 구
분하는 규칙은 다음과 같다. 전체 영역이 모두 같은 색이 아니라면 가로와 세로로
중간 부분을 잘라서 <그림 2>의 Ⅰ, Ⅱ, Ⅲ, Ⅳ와 같이 똑같은 크기의 네 개의 n/2 *
n/2 영역으로 나눈다.
나누어진 영역 Ⅰ, Ⅱ, Ⅲ, Ⅳ 각각에 대해서도 앞에서와 마찬가지로 모두 같은 색
으로 이루어지지 않으면 같은 방법으로 똑같은 크기의 네 개의 영역으로 나눈다. 이
와 같은 과정을 구분되어진 영역이 모두 하얀색 또는 모두 회색으로 되거나, 하나의
정사각형 칸이 되어 더 이상 나눌 수 없을 때까지 반복한다.
[그림 2]
위와 같은 규칙에 따라 나누었을 때 [그림 3]은 [그림 1]의 영역을 처음 나눈 후의
상태를, [그림 4]는 두 번째 나눈 후의 상태를, [그림 5]는 최종적으로 만들어진 다양
한 크기의 9개의 하얀색 영역과 7개의 회색영역을 보여주고 있다.
*/
//////////////////>
// 창훈 풀이 
//////////////////>

8
1 1 1 1 0 0 0 0
1 1 1 1 0 0 0 0
1 1 1 1 0 0 0 0
1 1 1 1 0 0 0 0
0 0 0 0 1 1 1 1
0 0 0 0 1 1 1 1
0 0 1 1 1 1 1 1
0 0 1 1 1 1 1 1
4
3

8
1 1 1 1 0 0 0 0
1 1 1 1 0 0 0 0
1 1 1 1 0 0 0 0
1 1 1 1 0 0 0 0
0 0 0 0 1 1 1 1
0 0 0 0 1 1 1 1
0 0 0 0 1 1 1 1
0 0 0 0 1 1 1 1

2
2


8
1 1 1 1 0 0 0 0
1 1 1 1 0 0 0 0
1 1 1 1 0 0 0 0
1 1 1 1 0 0 0 0
0 0 0 0 1 1 1 1
0 0 0 0 1 1 1 1
0 0 0 0 1 1 0 0
0 0 0 0 1 1 0 0

3
4


8
1 1 0 0 0 0 1 1
1 1 0 0 0 0 1 1
0 0 0 0 1 1 0 0
0 0 0 0 1 1 0 0
1 0 0 0 1 1 1 1
0 1 0 0 1 1 1 1
0 0 1 1 1 1 1 1
0 0 1 1 1 1 1 1

9
7



//창훈 최종풀이


/*
8
1 1 0 0 0 0 1 1
1 1 0 0 0 0 1 1
0 0 0 0 1 1 0 0
0 0 0 0 1 1 0 0
1 0 0 0 1 1 1 1
0 1 0 0 1 1 1 1
0 0 1 1 1 1 1 1
0 0 1 1 1 1 1 1
*/

#include<stdio.h>
#define B 0
#define W 1

int N;

int MAP[10][10];

int black_count;
int white_count;

int check_area(int x, int y, int len, int &color)
{
	color=MAP[x][y];
	for(int xx=x;xx<x+len;xx++)
	for(int yy=y;yy<y+len;yy++)
	{
		if(MAP[xx][yy]!=color) return 0;
	}
	return 1;
}

void solve(int x, int y, int len)
{
	int color=0;

	if(len==1)  //첫번째 Base 조건
	{
		color=MAP[x][y];

		if(color==1) white_count++;
		else black_count++;

		return;
	}

	if(check_area( x,  y,  len,  color))  //두번째 Base 조건
	{

		if(color==1) white_count++;
		else black_count++;

		return;
	}


	solve(x     ,y      ,len/2);
	solve(x     ,y+len/2,len/2);
	solve(x+len/2,y     ,len/2);
	solve(x+len/2,y+len/2,len/2);

}

int main(void)
{
	freopen("input.txt","r",stdin);
	scanf("%d",&N);

	for(int x=0;x<N;x++)
	for(int y=0;y<N;y++)
	{
		scanf("%d",&MAP[x][y]);
	}

	solve(0, 0, N);

	printf("%d\n",black_count);
	printf("%d\n",white_count);
}













//////////////////////

#include<stdio.h>
int n;
int map[128][128];

int white_count;//0
int gray_count;//1

void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d",&n);

	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		scanf("%d",&map[i][j]);
	}
}


//현재, start_x,start_y의 size 영역에서 색깔을 판정한다.
//-1은 전체가 같은색이 아님, 
int check(int start_x,int start_y, int size)
{
	int color=map[start_x][start_y];
	for(int i=start_x;i<start_x+size;i++)
    for(int j=start_y;j<start_y+size;j++)
	{
		if(color!=map[i][j]) return -1;
	}
	return color;
}

void solve(int start_x,int start_y,int size)
{
	if(size==1)  // 굳이 필요 없음.  아래에서 하나의 색을 걸러줌.
	{
		int color=map[start_x][start_y];
		if(color==0) white_count++;
		else gray_count++;
		return;
	}

	int color=check(start_x,start_y,size);
	if(color!=-1)
	{
		if(color==0) white_count++;
		else gray_count++;
		return;
	}

	solve(start_x,	start_y,	size/2);
	solve(start_x,	start_y+size/2,	size/2);
	solve(start_x+size/2,start_y,	size/2);
	solve(start_x+size/2,start_y+size/2,	size/2);
}



void main()
{
	input();
	solve(0,0,n);
	printf("%d\n",white_count);
	printf("%d\n",gray_count);
}



///////////////////

#include<stdio.h>

int white;
int black;

int map[10][10];

int n;

int check(int x, int y, int len, int &color)
{
	int temp_color=map[x][y];

	for(int i=x; i<x+len; i++)
	for(int j=y; j<y+len; j++)
	{
		if(temp_color!=map[i][j]) return 0;
	}

	color=temp_color;
	return 1;
}

void f(int x, int y, int len)
{
	int color=0;
	if(check(x,y,len,color))
	{
		if(color==0) black++;
		else white++;

		return;
	}

	f(x,y,len/2);
	f(x,y+len/2,len/2);
	f(x+len/2,y,len/2);
	f(x+len/2,y+len/2,len/2);
}

void main()
{

	freopen("input.txt","r",stdin);

	scanf("%d",&n);

	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	scanf("%d",&map[i][j]);

	f(0,0,n);

	printf("w:%d\n",white);
	printf("b:%d\n",black);
}




















//아래 풀이는 그냥 참조만 하도록

/////////////////////////////////////////////////////////////////////////////////////////////////////////

// 창훈 최종풀이
// 잘 풀었다. 이 풀이를 보도록!
//////////////////////////////////////////////

#include <cstdio>

#define B 0
#define W 1

int map[10][10];
int N;

int b_count;
int w_count;

void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d",&N);

	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	{
		scanf("%d",&map[i][j]);
	}
}

//c는 색깔을 받기위해서
int check(int x,int y,int n,int *c)
{
	*c = map[x][y];

	for(int i=x;i<x+n;i++)
	for(int j=y;j<y+n;j++)
	{
		if(map[x][y] != map[i][j]) return 1;
	}

	return 0;
}

void solve(int x,int y,int n)
{
	int c;

	if(check(x,y,n,&c))
	{
		solve(x,y,n/2);
		solve(x+(n/2),y,n/2);
		solve(x,y+(n/2),n/2);
		solve(x+(n/2),y+(n/2),n/2);
	}
	else
	{
		if(c==B) b_count++;
		else w_count++;
	}
}

void main()
{
	input();
	solve(0,0,N);
	printf("%d\n%d\n",b_count,w_count); // 문제와 다르게 위치가 바뀌었음.
}



//
// 너무 어렵게 풀었다. 이 풀이는 보지 마라.
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#include<stdio.h>

int arr[100][100];
int arr_new[100][100];
int n;

int graycount;
int whithecount;

void printfMarix()
{
	for(int i=0;i<n;i++)
	{	
		for(int j=0;j<n;j++)
		{
		 printf(" %d",arr_new[i][j]);
		}	
		printf("\n");
	}	
}


void input()
{
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
	 scanf("%d",&arr[i][j]);
	}	

	
}

int isFinished(int x, int y,int width)
{
	int temp=0;
	
	if(arr[x][y]==0 || arr[x][y]==1)
	{
		temp=arr[x][y];
	}
		
   for(int i=x; i < x+width ; i++)
   for(int j=y; j < y+width ; j++)
   {
		if(temp!=arr[i][j])
		{
		  return -1;
		}	
   }	

   
   for(int i=x; i < x+width ; i++)  // 다녀온 장소를 확인하기 위해서
   for(int j=y; j < y+width ; j++)
   {
	  arr_new[i][j]=2;
   }
   
   
   if(temp==0) whithecount++;  // 카운팅을 한다.
   else graycount++;

   return 1;
}

void solve(int x, int y,int width)
{
		
	if( isFinished(x,y,width)== 1) return;  // 현재 status에서 블럭이 있다면. 이 조건을 만족한다면  더이상 들어갈 필요가 없다.
	
	solve(x,y,width/2);          // 이 계산 매번 틀림.!! 주의해라!!
	solve(x,y+width/2,width/2);  // 내가 접근하는 방법도 관계기반이다.  width/2씩 줄어든다.  f(n) = f(n/2) 
	solve(x+width/2,y,width/2);
	solve(x+width/2,y+width/2,width/2);

}

void main()
{	
 freopen("input.txt", "r", stdin);
 input();
 solve(0,0,n);
 
 printfMarix();
  
 printf("%d\n%d\n",whithecount,graycount);
 
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//교재풀이
//교재 로직하고 똑같이 풀었음. 잘했음 ^^

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#include <cstdio>

int P[1<<7][1<<7], n;

bool isOne(int a, int b, int s, int v)
{
for(int i=a; i<a+s; i++)
for(int j=b; j<b+s; j++)
if(P[i][j]!=v) return false;
return true;
}

int f(int a, int b, int s, int v)
{
	
if(s==1) return P[a][b]==v;  //폭이 1이라면 바닥이라면. 최대한 깊이 들어 왔다면. 마지막 남아 있는 요소가 내가 원하는 값이면 1을 return 함.
if(isOne(a,b,s,v)) return 1; //전체가 하나의 색 v라면.

return f(a,b,s/2,v)+f(a+s/2,b,s/2,v)+f(a,b+s/2,s/2,v)+f(a+s/2,b+s/2,s/2,v);
}

int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
	scanf("%d", &P[i][j]);
	printf("%d\n%d\n", f(0,0,n,0), f(0,0,n,1));
}
