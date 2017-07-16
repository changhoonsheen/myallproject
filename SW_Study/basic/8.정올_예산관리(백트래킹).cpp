/*
첫째 줄에 남은 예산(B)이 입력된다. ( 10 <= B <= 35,000 )
둘째 줄에 예산을 사용할 수 있는 활동의 수(n)가 입력된다. (1 <= n <= 21 )
셋째 줄에 공백을 기준으로 n개의 활동비가 양의 정수로 입력된다.

40
6
7 13 17 19 29 31

10
7
3 1 2 4 1 9 30 

*/











/*

140
18
7 13 17 19 29 31 7 13 17 19 29 31 7 13 17 19 29 31

*/

#include<stdio.h>

int M;
int N;
int WORK[21];

int MAX_VALUE=0;

int func_count;


void solve(int i, int budget)
{
	
	if(M < budget)
	{
		return;
	}
	
	func_count++;

	if(i==N)
	{
		if(budget<=M)
		{
			if(MAX_VALUE < budget) MAX_VALUE=budget;
		}

		return;
	}

	solve(i+1,budget+WORK[i]);
	solve(i+1,budget);
}


void main()
{
	freopen("input.txt","r",stdin);
	scanf("%d",&M);
	scanf("%d",&N);

	for(int i=0;i<N;i++)
	{
		scanf("%d",&WORK[i]);
	}

	solve(0,0);

	printf("%d\n",MAX_VALUE);
	printf("func_count:%d\n", func_count);
}
















//////////////////////////////////////////////////////////////////////////
// 최종풀이 
// Backtracking의 쉬운 유형이다.
//////////////////////////////////////////////////////////////////////////
#include<stdio.h>

int B;
int n;
int work[100];

int max_cost;

void input()
{
	freopen("input.txt","r",stdin);
//	freopen("output_changes.txt","w",stdout);

	scanf("%d",&B);
	scanf("%d",&n);

	for(int i=1;i<=n;i++)
	{
		scanf("%d",&work[i]);
	}
}


void solve(int i ,int total)
{
	if(i==n+1) return;
	if(total>B) return;
	
	//값을 가지고 가기.
	if(max_cost < total) max_cost=total;

	solve(i+1,total+work[i]);
	solve(i+1,total);
}

void main()
{
	input();
	solve(1,0);
	printf("%d",max_cost);
}