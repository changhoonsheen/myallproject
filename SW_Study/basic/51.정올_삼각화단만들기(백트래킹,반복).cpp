주어진 화단 둘레의 길이를 이용하여 삼각형 모양의 화단을 만들려고 한다. 이 때
만들어진 삼각형 화단 둘레의 길이는 반드시 주어진 화단 둘레의 길이와 같아야 한
다. 또한, 화단 둘레의 길이와 각 변의 길이는 자연수이다. 예를 들어, 만들고자 하는
화단 둘레의 길이가 9m라고 하면,
? 한 변의 길이가 1m, 두 변의 길이가 4m인 화단
? 한 변의 길이가 2m, 다른 변의 길이가 3m, 나머지 변의 길이가 4m인 화단
? 세 변의 길이가 모두 3m인 3가지 경우의 화단을 만들 수 있다.

// 생각해보기.

0. 주어진 입력 , 제일 중요한 조건, 특히 비선형탐색의 바닥(base)의 조건이다.
a + b + c = 주어진 길이 

1. 삼각형의 정의
a + b > c

2. 중복을 없애기   // 0 , 1 만 고려할 경우 중복이 나옴,
a <= b <= c




//창훈 최종 필기
//그런데 100은 값이 안나온다. 그래서 선형으로 풀어야한다. 20도 답 안나옴.
/*
20
a:6 b:7 c:7
a:6 b:6 c:8
a:5 b:7 c:8
a:5 b:6 c:9
a:4 b:8 c:8
a:4 b:7 c:9
a:3 b:8 c:9
a:2 b:9 c:9
count : 8
func_count:935209305
*/
#include<stdio.h>

int N;
int count;

//똑같은 값이 나올때 체크 배열을 이용해서 이전 나온 내용을 막는다.
int check[100][100][100];

void solve(int a, int b ,int c)
{

		if(a+b+c==N) // 기본정의 
		{
			if(a+b > c && c >= b && b >= a)  // 중복제거를 하는 부분
			{
				if(check[a][b][c]==0)
				{
					check[a][b][c]=1;
					printf("a:%d b:%d c:%d\n",a,b,c);
					count++;
				}
			}
			return;		
		}


	solve(a+1,b,c);
	solve(a,b+1,c);
	solve(a,b,c+1);
}


void main()
{
	scanf("%d",&N);

	solve(0,0,0);
	printf("count : %d\n",count);
}


// 선형으로 풀어보기
// 이방식으로 풀어야지 답이 나온다.
/*
20
a:2 b:9 c:9
a:3 b:8 c:9
a:4 b:7 c:9
a:4 b:8 c:8
a:5 b:6 c:9
a:5 b:7 c:8
a:6 b:6 c:8
a:6 b:7 c:7
count : 8
*/

#include<stdio.h>

int N;
int check[101][101][101];
int count;

void main()
{
	scanf("%d",&N);

	for(int a=0;a<=N;a++)
	for(int b=0;b<=N;b++)
	for(int c=0;c<=N;c++)
	{

		if(a+b+c==N && a+b>c && c>=b && b>=a && check[a][b][c]==0)				
		{
			 check[a][b][c]=1;
			 printf("a:%d b:%d c:%d\n",a,b,c);
			 count++;
		}	
	}

	printf("count : %d\n",count);
}



































//++ 아래껀 그냥 참조하도록 
////////////////////////////////////////////////////////////////////////////////////////

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//전체 탐색 방법   -> 선형적인 탐색방법으로 접근함.
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#include <stdio.h>

int count;
int n;

void main()
{
printf("\n>>>>>>>>>>>>>>>>>>>>\n");


n=100;
count=0;

for(int a=1; a<=n; a++)
for(int b=a; b<=n; b++)
for(int c=b; c<=n; c++)
{
	if( (a+b+c==n) && (a+b > c) )
	{
		if(count%3 == 0) puts("");

		count++;
		printf("[%d %d %d]\t", a, b, c);
	}


}


printf("\n>>>>>>>>>>>>>>>>>>>>\n");

n=100;
count=0;


for(int a=1; a<=n; a++)
for(int b=1; b<=n; b++)
for(int c=1; c<=n; c++)
{
	if( a <= b && b <= c)  // 위에서 for loop시 1 부터 시작함으로 
	{
		if( (a+b+c==n) && (a+b > c) )
		{
			if(count%3 == 0) puts("");

			count++;
			printf("[%d %d %d]\t", a, b, c);
		}
	}
}
}


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//전체 탐색 방법   -> 비선형적인 방법으로 접근함.
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


//함수 방식 바꿔보기 

#include <stdio.h>

int checked[10][10][10];

void solve(int n, int a , int b , int c)
{
	if(a+b+c==n)  // Base의 조건이다. 아래 조건과 같이 뭍으면 안된다.
	{
		if(  (a <= b && b <=c ) && ( a+b > c ) && ( checked[a][b][c]==0) ) 
		{
			printf("a:%d , b:%d , c:%d\n",a,b,c);
			checked[a][b][c]=1;
		}
		
		return;
	}

	solve(n,a+1,b,c);
	solve(n,a,b+1,c);
	solve(n,a,b,c+1);
}


void main(void)
{
	int n=5;
	solve(n,0,0,0);
}



//Stack을 사용해서 바꿔보기 
#include <stdio.h>

int checked[10][10][10];

struct Node
{
	int a;
	int b;
	int c;
};

Node node[100000];
int top=-1;
int n;

//인자의 갯수는 상관없다. 구조체에 담아서 넘기면된다.!
void solve(int a , int b , int c)
{
	top++;
	node[top].a=a;
	node[top].b=b;
	node[top].c=c;
	
	while(top!=-1)
	{
		int new_a=node[top].a;
		int new_b=node[top].b;
		int new_c=node[top].c;
		top--;
		
		// 해당 루틴은 모든 해의 범위를 돈다. 이때 원하는 값을 하나씩 획득한다.
		//>> 반드시 방문시 조건 처리 여기서 한다.!!
		if(new_a+new_b+new_c==n)  // Base의 조건이다. 아래 조건과 같이 뭍으면 안된다.
		{
			if(  (new_a <= new_b && new_b <=new_c ) && ( new_a+new_b > new_c ) && ( checked[new_a][new_b][new_c]==0) ) 
			{
				printf("a:%d , b:%d , c:%d\n",new_a,new_b,new_c);
				checked[new_a][new_b][new_c]=1;
			}
		}
		//<<

	     if(new_a+new_b+new_c < n)  // 이 부분 정말 중요하다.!!  어떻게 조건을 정하면 모든 해의 범위를 무한루프 없이 전체탐색을 할 수 있을까?
			                        // 후보군 처리 트리을 그려본다. 어디가 바닥인지, 그리고 Stack에 후보군을 넣을때 후보군을 포함시킬 조건을 먼저 처리하고 확인한다. 
		 {	
				        	top++;                             
							node[top].a=new_a;
							node[top].b=new_b;
							node[top].c=new_c+1;

							top++;
							node[top].a=new_a;
							node[top].b=new_b+1;
							node[top].c=new_c;

							top++;                     //먼저 나올것을 맨 마지막에 넣는다.
							node[top].a=new_a+1;
							node[top].b=new_b;
							node[top].c=new_c;
		
		}			
	}

}
void main(void)
{
	n=9;
	solve(0,0,0);
}
