

//창훈 최종 필기

#include<stdio.h>

int n;
int mod;
int DT[100000];

int func_call;

void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	scanf("%d",&mod);
}

//data가 정의역 한계치인 100000건 (10000건만해도 Stack overflow가 발생) 정도 되면 답이 안나옴. Stack overflow가 발생함.
//그래서 가능하다고 생각하는 건 상향으로 바꾼다.
#if 1  //하향식 설계
int f(int i)
{
	if(DT[i]!=-1) return DT[i];

	func_call++;

	if(i==1) return DT[i]=1%mod;
	if(i==2) return DT[i]=3%mod;
	
	return DT[i]=(f(i-1) + 2*f(i-2))%mod;
}

#else //상향식 설계가 필요함. 가능하다면 상향식 방법으로 가야됨.

int f(int i)
{

	DT[1]=1%mod;
	DT[2]=3%mod;
	
	for(int i=3;i<=n;i++)
    DT[i]=(DT[i-1] + 2*DT[i-2])%mod;

	return DT[n];
}

#endif


void main()
{
 input();

 for(int i=0;i<100000;i++)
	 DT[i]=-1;

 printf("%d\n",f(n)%mod);
 printf("func_call:%d\n",func_call);
}





























/////////////////////////////////////////////////////////////////////////////
//+


/*
타일 채우기
2x1 1x2 2x2 의 직사각형을 이용해서 2xN 틀에 넣는 경우의 수 

1.
하향식 설계, <부메랑>

2. 아래와 같은 관계

f(n) = f(n-1)   .....   바로 해결할 사례까지 끌고 감.
중요! 마지막에 올 수 있는 타일의 조건은  n이 1일경우 n이 2일경우 가있다.

f(1) = 1
f(2) = 3 

아래 3개의 아이템을 기준으로 마지막으로 사용할 수 있는 타일은 3가지 이다.

2x1

1x2

2x2

(1<=n<=100,000, 1<=m<=40,000)



>>>>>>>>>>>>>>>

f(n) = f(n-1) + 2f(n-2) 


f(3) = f(2) + 2 f(1) 

첫 줄에는 직사각형 틀의 가로 길이 n이 주어진다.
둘째 줄에는 m이 주어진다. (1<=n<=100,000, 1<=m<=40,000)
 
하향식 설계방식

20
10000

9051  -> answer
13529  -> fun cnt


*/
#include<stdio.h>

int mod;  // 숫자가 커질경우 나눠질 값
int n;

int array_count[100];

int f(int n)
{
	array_count[n]++;
	
	if(n==1) return 1%mod;
	else if(n==2) return 3%mod;
	else
	{
		return  ( f(n-1) + 2 * f(n-2) ) %mod;
	}
}

int main()
{

  freopen("input.txt", "r", stdin);
  scanf("%d",&n);
  scanf("%d",&mod);

  printf("%d" , f(n) % mod);
}


/////////////////////////////////////////
// 중복 호출을 줄이기 위해서 DP 테이블을 이용함.
/////////////////////////////////////////



20
10000

9051  -> answer
51  -> fun cnt


//이 알고리즘은 n이 10000이 되면 뻗음
//실제 입력은 이 값을 넘음


/////////////////////////////////////////

#include<stdio.h>

int mod;  // 숫자가 커질경우 나눠질 값
int n;

//int array_count[100000];
int DT[100000];
static int fun_count;

int f(int n)
{
	//array_count[n]++;  // 실제 조금한 데이터를 가지고 중복이 얼마나 일어나는지 확인가능 
	
	fun_count++;

	if(n==1) return DT[n]= (1%mod);
	else if(n==2) return DT[n]=(3%mod);
	else
	{
		if(DT[n]==0) DT[n] = ( ( f(n-1) + 2 * f(n-2) ) ) %mod;
	}
	
	return DT[n];
}

int main()
{

  freopen("input.txt", "r", stdin);
  scanf("%d",&n);
  scanf("%d",&mod);

  printf("answer:%d\n" , f(n) % mod);
  printf("fun count : %d", fun_count);
}

/////////////////////////////////////////////
// 상향식으로 점화식+반복문형태로 표현함.
// 최종 알고리즘 목적이기도 함.
/////////////////////////////////////////////


#include<stdio.h>

int mod;  // 숫자가 커질경우 나눠질 값
int n;


int DT[100000];
static int fun_count;

int main()
{

  freopen("input.txt", "r", stdin);
  scanf("%d",&n);
  scanf("%d",&mod);
  
  DT[1]=(1%mod);
  DT[2]=(3%mod);
  
  for(int i=3; i<=n;i++)
	   DT[i]=( DT[i-1] + 2 * DT[i-2] )%mod;

  printf("answer:%d\n" ,DT[n]);

}


/////////////////////////////////////////////
// 분할정복 방식은 나중에 AD 따고 봅시다....
/////////////////////////////////////////////

