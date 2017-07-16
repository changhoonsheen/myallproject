//창훈 필기 최종 접근해보기
/*
6 
6 -7 3 -1 5 2 
*/


//backtracking 접근
#include<stdio.h>

int N;
int arr[100];
int func_call;
int MAX(int a, int b)
{
	return a > b ? a : b;
}

int DT[100];
int f(int n)
{
	printf("n:%d\n",n);

	if(n==0) return DT[n]=arr[0];

	return DT[n]=MAX(f(n-1)+arr[n],arr[n]);

}

void main()
{
	freopen("input.txt","r",stdin);

	scanf("%d",&N);

	for(int i=0;i<N;i++)
		scanf("%d",&arr[i]);

	f(N-1);

	int max=DT[0];
	for(int i=1;i<N;i++)
	if(max<DT[i]) max=DT[i]; // 해당 DT 테이블은 해당 원소를 마지막으로 하는 최대 원소의 합

	printf("%d\n",max);
}





//DP로 접근
#include<stdio.h>

int n; 
int DT[10000];
int arr[10000];

int MAX(int a, int b)
{
	return a<b? b:a;
}

void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d",&n);

	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
}


void main()
{
	input();

	//배열을 직접 그려보고 계산해본다.
	DT[0]=arr[0];
	for(int i=1;i<n;i++)
	{
		DT[i]=MAX(arr[i],DT[i-1]+arr[i]);
	}

	//실수 이게 답이 아니다. 왜냐면 앞의 숫자를 고려 안하고 자기가 큰 수가 될 수 있기때문이다.
	//printf("%d",DT[n-1]);
	
	//실수!!! 이 부분 빼먹었음.
	int max=-987654321; //제일 작은값의 -INF이다.
	for(int i=0;i<n;i++)
	if(max < DT[i]) max=DT[i];

	printf("%d",max);
}






//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//////////////////////////////////////////////////////////////////
/*
부분합이란 n개의 원소 중 i번째 원소로부터 j번째 원소까지의 연속적인 합을 의미
한다. (단, 1 <= i <= j <= n) 만약 다음과 같이 6개의 원소로 이루어진 집합이 있
다고 가정하자.
6 -7 3 -1 5 2


입력
첫 줄에 원소의 수를 의미하는 정수 n이 입력되고, 둘째 줄에 n개의 정수가 공백
으로 구분되어 입력된다.
(단, 2 <= n <= 100,000; 각 원소의 크기는 -1000에서 1000 사이의 정수이다.)

6
6 -7 3 -1 5 2

전체 검색 접근 
*/

//창훈 최종 - 창훈 DP 개념으로 생각
//for 2개로 접근해보기.(10만까지는 답이 나오긴한데 너무 늦음.) 이거 보고, 교재 풀이법을 익힌다.
//교재 내가 그림 참조.
#include<stdio.h>

int n;
int DT[100000];
int input[100000];

void main()
{
	freopen("input.txt","r",stdin);
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	scanf("%d",&input[i]);
	
	
	int max=input[0];
	for(int i=0;i<n;i++)
	{
		DT[i]=input[i];
		for(int j=i;j<n;j++)
		{
			DT[j+1]=DT[j]+input[j+1];
			if(max < DT[j+1]) max=DT[j+1];
		}
	}	
	
	printf("max:%d\n",max);	
}







//전체 검색
//3중 for문에 대한 표를 그려봐야지 프로그램할 수 있다.
// 그냥 머리속에선 프로그램이 어렵다.

#include<stdio.h>

int n;
int arr[100000];

int main()
{

  freopen("input.txt", "r", stdin);
  scanf("%d",&n);

  for(int i=1; i<=n;i++)
  scanf("%d",&arr[i]);


  int max=arr[1];
  for(int i=1; i<=n;i++)
  { 
	  for(int j=i; j<=n;j++)  
	  {
          //printf("%d %d \n" , i, j);  // 이걸 출력해보고 틀을 잡는다.
		  //printf("++++++++++++\n");	 
		  int sum=0;
		  for(int k=i ; k <=j ; k++)
		  {
			  sum=sum+arr[k];
			  printf(" %d " ,k);
		  }

		  if(max < sum) max =sum;

		  printf("\n");
	  }
	 printf("===\n");
  }

  printf("max : %d \n" ,  max);
	
  return 0;
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// 관계형 기반 풀이 NON DP table
// 21번 호출함
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#include<stdio.h>

int n;
int arr[100000];

int arr_times[100];

static int fun_count;

int max(int a, int b)
{
	return  a > b ? a : b;
}

//n을 마지막 원소로 하는 최대합
//마지막 원소에  arrr[n]을 붙이나, 안붙이나 최대 값을 찾아 나감.
 
int func(int n)
{
	//>> 얼마나 많은 중복호출이 되나? 
	arr_times[n]++;
	printf(" %d",n );
	//<<
	
	fun_count++;

	if(n==0)
	{
	  return arr[0];  //교재 그림. 그려 놓은거 참조하삼.
	}
	else
	{
	  return max(func(n-1)+arr[n],arr[n]);
	}
}


int main()
{

  freopen("input.txt", "r", stdin);
  scanf("%d",&n);

  for(int i=0; i<n;i++)
  scanf("%d",&arr[i]);

  int max_value=-987654321;
  for(int i=0; i<n;i++)
  {	 
    int value=func(i);
    if(max_value < value ) max_value = value;
  }  
  printf("answer:%d",max_value);
  printf("func_count:%d",fun_count);

}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// 관계형 기반 풀이  DP table
//
// 

// 11 번 호출함
6
6 -7 3 -1 5 2

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#include<stdio.h>

#define INF 987654321 

int n;
int arr[100000];
int DP_table[100000];

int arr_times[100];

static int fun_count;

int max(int a, int b)
{
	return  a > b ? a : b;
}

//n을 마지막 원소로 하는 최대합
//마지막 원소에  arrr[n]을 붙이나, 안붙이나 최대 값을 찾아 나감.
 
int func(int n)
{
	//>> 얼마나 많은 중복호출이 되나? , 분명히 이런 문제들은 중복이 있다. 이걸 DP table로 줄여야한다.
//	arr_times[n]++;
//	printf(" %d",n );
	//<<

	fun_count++;

	if(n==0)
	{
	  return DP_table[0]=arr[0];  //교재 그림. 그려 놓은거 참조하삼.
	}
	else
	{
	  if(DP_table[n]==-INF)  //  값이 없다면, 알고리즘을 돌아서 찾는다.
	  {
	     DP_table[n]=max(func(n-1)+arr[n],arr[n]);
	  }
	}
	
	return DP_table[n];
}


int main()
{

  freopen("input.txt", "r", stdin);
  scanf("%d",&n);

  for(int i=0; i<n;i++)
  {	  
    scanf("%d",&arr[i]);
	DP_table[i]=-INF;
  }
  
  int max_value=-INF;
  for(int i=0; i<n;i++)
  {	 
    int value=func(i);
    if(max_value < value ) max_value = value;
  }  
  printf("answer:%d",max_value);
  printf("func_count:%d",fun_count);

}

