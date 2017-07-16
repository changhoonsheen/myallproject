




//하향식 DT 테이블
#include<stdio.h>

int func_call;
int DT[1000];

//거스름돈,주식투자하고 비슷한 알고리즘

int solve(int steps)
{

if(DT[steps]!=-1) return DT[steps];

func_call++;

if(steps==0) 
{
	return  DT[steps]=1;
}

int a=0;
int b=0;

if(steps-1>=0)
a=solve(steps-1);  

if(steps-2>=0)
b=solve(steps-2);

return DT[steps]=a+b;
}


void main()
{
    int steps=20;
	
	for(int i=0;i<=steps;i++)
	DT[i]=-1;

	printf("%d\n",solve(steps));
	printf("func_call:%d\n",func_call);
}












//상향식
//창훈 최종 필기
//계단오르기 , 가장 간단하게 Backtracking 해보고 DT 테이블 적용해보자

#include<stdio.h>

int count;
int n;

int func_count;

unsigned _int64 DT[1000];

unsigned _int64 solve(int k)
{
	if(DT[k]!=-1) return DT[k];

	func_count++;

	if(k>=n)
	{
		if(k==n) return DT[k]=1;
		return DT[k]=0;
	}

	return DT[k]=solve(k+1)+solve(k+2);
}

void main()
{
	scanf("%d",&n);

	for(int i=0;i<1000;i++)
	{
		DT[i]=-1;
	}

	printf("%I64d\n",solve(0));
	printf("func_count:%d\n",func_count);
}
//일반 백트래킹 버젼 
//그러나 계단 n이 40만되도 결과가 나오지 않는다.
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


#include<stdio.h>

int count;
int n;

void solve(int k)
{
	if(k>=n)
	{
		if(k==n) count++;
		return;
	}

	solve(k+1);
	solve(k+2);
}

void main()
{
	scanf("%d",&n);
	solve(0);
	printf("%d",count);
}


