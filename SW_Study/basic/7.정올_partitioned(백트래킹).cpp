//창훈 최종 분할수 문제임
//좋은 문제고 시험전 한번더 풀어 보기


//함수 인자 2개짜리 버젼
#include<stdio.h>

int n;
int arr[30];

void f(int k, int sum)
{
	if(sum==n)
	{
		for(int i=0;i<k;i++)
		printf("%d ",arr[i]);

		printf("\n");
		return;
	}

	int l = n-sum; // 입력 받은 n - SUM은 다음 후보군의 처음 값을 알수 있음.
	for(int i=l;i>=1;i--)
	{
		if(i<=arr[k-1]) //후보군이 이전 선택된 값보다 크면안됨. , 이렇게 참조해도됨.
		{
			arr[k]=i;
			f(k+1,sum+i);
		}
	}

}


void solve()
{
	for(int i=n;i>=1;i--) //제일 첫번째 트리의 래벨 부호군. 함수 분리
	{
		arr[0]=i;
		f(1,i); //여기 실수함.
	}
}

void main()
{
	scanf("%d",&n);
	solve();
}




//함수 인자 3개짜리 버젼
//////////////////////////////


#include<stdio.h>

int n;
int arr[30];

void f(int k, int p, int sum)
{
	if(sum==n)
	{
		for(int i=0;i<k;i++)
		printf("%d ",arr[i]);

		printf("\n");
		return;
	}

	int l = n-sum; // 입력 받은 n - SUM은 다음 후보군의 처음 값을 알수 있음.
	for(int i=l;i>=1;i--)
	{
		if(i<=p) //후보군이 이전 선택된 값보다 크면안됨.
		{
			arr[k]=i;
			f(k+1,i,sum+i);
		}
	}

}


void solve()
{
	printf("%d\n",n);
	for(int i=n-1;i>=1;i--) //제일 첫번째 부호군. 함수 분리
	{
		arr[0]=i;
		f(1,i,i); //여기 실수함.
	}
}

void main()
{
	scanf("%d",&n);
	solve();
}






















//아래는 그냥 참조만 하도록 위에만 보기
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
///////////////////////////////////////////////////////////

// 창훈 직접 최종품. 백트래킹 좋은 예제. 나중에 시험전 풀어 보자
// 0. 실수 부분 잘 체크하도록<내부 오더 부분>
// 1. 트리를 그려봐야되고, 뒤의 인덱스에 나올값이 크면 안된다.
// 2. 순열알고리즘과 비슷하다.
// 3. 가지치기가 제일중요한다. printf를 넣어서 가지 치기 조건을 반드시 따진다.!!


#include<stdio.h>

int N;
int arr[30]={0};

static int count;

int min(int a, int b)
{
	return a > b ? b : a;
}

void f(int arr[],int k, int rest,int sum )  // 함수 두개로 분리하는 테크닉 
{
   // printf("count:%d k:%d rest:%d sum:%d \n" , count,k,rest,sum);

	if(k>N) return;  //  여기 실수 
	if(sum>N) return; // 중요함 가지치기 위와 같이 Printf를 넣어서 가지치기 조건을 반드시 확인한다.

	count++;

	if(sum==N)
	{	
		for(int i=0;i<k;i++)
	    {
			printf("%d ",arr[i]);
		}
		printf("\n");

		return;
	}

	for(int i=min(arr[k-1],rest) ; i >= 1 ;i--)
	{
		//if(arr[k-1]<i) continue;  // 여기 실수 

		arr[k]=i;
		sum+=i;
		f(arr,k+1,rest+i,sum);
		sum-=i;
	}
	
}

void solve(int arr[],int k,int n)  // 함수 두개로 분리하는 테크닉 
{
		for(int i=n;i>=1;i--)
		{	 
			 arr[k]=i;
			 f(arr,k+1,N-i,i);  // rest 부분 실수 
		}
}

void main(void)
{


   freopen("output.txt","w",stdout);
	scanf("%d",&N);

	
	solve(arr,0,N);

//	printf("count :%d\n",count);
}

//////////////////////////////////////////////////


/*
난 못품.!

첫째 아래와 같은 관계를  찾지 못했다.
서로간의 관계를 만든다.!  못 만듦. ㅜㅜ

1. 관계를 생각한다.
f(n,k)  // k이하의 자연수로 n을 만드는 경우의 수 

f(n,k) = f(n-1,1) + f(n-2,2) + f(n-3,3) ....  + f(n-k,k)
       = 1의 가지 + 2의 가지 + 3의 가지  .... 5의 가지 

2. 트리를 그려 본다.
백트래킹으로 접근하기 위해선 트리를 그리는게 중요하다.

3. 규칙을 찾을 수 있는지 확인한다.

4. 출력을 위한 포맷을 생각한다.

5
4 1
3 2
3 1 1
2 2 1
2 1 1 1
1 1 1 1 1

*/

#include<stdio.h>

int str[30];  // 결과가 저장될 배열
int cnt;      // 결과의 갯수 

/*
f(n,k)  // k이하의 자연수로 n을 만드는 경우의 수 
f(n,k) = f(n-1,1) + f(n-2,2) + f(n-3,3) ....  + f(n-k,k)

*/

int min(int a, int b)
{
 return a > b ? b : a;
}

void solve(int n , int k , int p)
{
	if(n==0)
	{
		for(int i=0; i< p ; i++)
		printf("%d ",str[i]);
	
	    printf("\n");
		return;
	}
	
	for(int i=min(n,k) ; i >= 1 ; i--)
	{
	  str[p]=i; // 이 기법 알아 놓도록  // 전역말고 이 방법을 사용할 수 있다.
	  solve(n-i,i,p+1);  // 현재 값을 빼고 아래 단계로 p
	}	
	
}
	   
void main()
{
	int n;
	scanf("%d",&n);
	solve(n,n,0);
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//교재 풀이 

/*
partitioned 문제 
*/

#include<stdio.h>

int a[30], cnt;
int count;

int min(int a, int b)
{
	return a>b ? b : a;
}


void solve(int n,int k)
{
	if(n==0)
	{
		for(int i=0; i< cnt; i++)
		{
			printf("%d",a[i]);
		}
		count++;
		printf("\n");
		return;
	}

	for(int i=min(n,k) ; i>=1 ; i--)

	{	
		a[cnt++]=i;
		solve(n-i,i);
		cnt--;
	}
}

void main(void)
{
	int n;
	scanf("%d",&n);
	solve(n,n); // k이하의 자연수의 합으로 n을 만들수 있는 경우의 수

	printf("count:%d\n",count);
}