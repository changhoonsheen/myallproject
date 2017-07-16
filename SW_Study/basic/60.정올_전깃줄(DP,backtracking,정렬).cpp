/*
8
1 8
3 9
2 2
4 1
6 4
10 10
9 7
7 6

-> 책 3
*/

/*
8
1 2
2 10
3 3 
4 9
5 4
6 8 
7 5
8 7

답 4
*/

//최장증가수열 , 서로 연속해서 붙어 있을 필요가 없다!! 
//예제는 연속적이라서 헷갈림. 
//>>
#include<stdio.h>

int N;

struct BAR
{
	int a;
	int b;
};

BAR bar[10];
int DT[10];

int func_count;

void sort()
{
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
		{
			if (bar[i].a > bar[j].a)
			{
				BAR temp = bar[i];
				bar[i] = bar[j];
				bar[j] = temp;
			}
		}
}

void input()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &bar[i].a, &bar[i].b);
		DT[i] = -1;
	}
}


int MAX(int a, int b)
{
	return a > b ? a : b;
}

int getLIS(int i)
{

	if (DT[i] != -1) return  DT[i];
	func_count++;

	int max_value = 1;

	for (int k = 0; k < i; k++)
	{
		if (bar[k].b < bar[i].b)
		{
			max_value = MAX(max_value, getLIS(k) + 1);
		}
	}

	return DT[i] = max_value;
}

void main()
{
	input();
	sort();
	
	int max_value = 0;

	for (int i = N - 1; i >= 0; i--)
	{
		DT[i] = getLIS(i);
		if (max_value < DT[i]) max_value = DT[i];
	}

	printf("%d\n", N - max_value);
	printf("func_count:%d\n", func_count);

	/*
	for (int i = 1; i < N; i++)
	{
		DT[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (bar[i].b > bar[j].b && DT[i] < DT[j] + 1)
				DT[i] = DT[j] + 1;
		}
	}
	*/
}
//<<




//////////////////////////////////////


//창훈 최종 필기
//LIS 정의를 다시 생각해보자. 두번째 볼때 정의를 잘 몰랐다.

#include<stdio.h>

int n;

struct Bar
{
	int bar1;
	int bar2;
};

Bar b[500];
int DT[500];

void input()
{
	freopen("input.txt","r",stdin);
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&b[i].bar1,&b[i].bar2);
	}
}

//구조체 레퍼런스로 받는다.!! 실수!!
void swap(Bar &a, Bar &b)
{
	Bar temp;
	temp=a;
	a=b;
	b=temp;
}


int partition(int l, int r)
{
	int p=b[l].bar1;
	int i=l;
	int j=r;
	
	while(i<=j)
	{
		while(b[i].bar1<=p){i++; if(i==r) break;}
		while(b[j].bar1>=p){j--; if(j==l) break;}
		if(i<j) swap(b[i],b[j]);
	}
	
	swap(b[j],b[l]);
	return j;
}


void quicksort(int l, int r)
{
	if(l<r)
	{
		int s = partition(l,r);
		quicksort(l,s-1);
		quicksort(s+1,r);
	}
}

#if 1  // 
int getLIS()
{
	for(int i=1;i<n;i++)
	{
		DT[i]=1;
		for(int j=0;j<i;j++)
		{
			if ( (b[j].bar2 < b[i].bar2) && ( DT[j]+1 > DT[i] ) )
				DT[i]=DT[j]+1;
		}
	}
	
	int max=0;
	for(int i=1;i<n;i++)
	{
		if(max<DT[i]) max=DT[i];
	}
	
	return max;
}

#else  // 두번째 풀때 잘 못풀었음. LIS 정의를 생각해보자. 
int getLIS()
{
	for(int i=1;i<n;i++)
	{
		if(b[i-1].bar2 < b[i].bar2) DT[i]=DT[i-1]+1;
		else DT[i]=1;
	}
	
	int max=0;
	for(int i=1;i<n;i++)
	{
		if(max<DT[i]) max=DT[i];
	}
	
	return max;
}
#endif

void main()
{
	input();
	quicksort(0,n-1);
	printf("%d",n-getLIS());
}



//재귀적인 접근 교재 방법
//창훈 최종 필기, 좋은 문제이다. DT 테이블도 적용해보자!!

#include<stdio.h>

int n;

int func_count;

struct Bar
{
	int bar1;
	int bar2;
};

Bar b[500];
int DT[500];

void input()
{
	freopen("input.txt","r",stdin);
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&b[i].bar1,&b[i].bar2);
	}
}

//구조체 레퍼런스로 받는다.!! 실수!!
void swap(Bar &a, Bar &b)
{
	Bar temp;
	temp=a;
	a=b;
	b=temp;
}


int partition(int l, int r)
{
	int p=b[l].bar1;
	int i=l;
	int j=r;
	
	while(i<=j)
	{
		while(b[i].bar1<=p){i++; if(i==r) break;}
		while(b[j].bar1>=p){j--; if(j==l) break;}
		if(i<j) swap(b[i],b[j]);
	}
	
	swap(b[j],b[l]);
	return j;
}


void quicksort(int l, int r)
{
	if(l<r)
	{
		int s = partition(l,r);
		quicksort(l,s-1);
		quicksort(s+1,r);
	}
}

int MAX(int a, int b)
{
	return a>b ? a : b;
}

int solve(int k)
{

if(DT[k]!=0) return DT[k];

func_count++;
int max=1;//초기화가 1임. 실수!!!
for(int i=k-1;i>=0;i--)
{
	if(b[i].bar2 < b[k].bar2) max=MAX(max,solve(i)+1);
}
return max;
}

//LIS backtracking
int getLIS()
{
	for(int i=0;i<n;i++)
	{
		DT[i]=solve(i);
	}

	int max=0;
	for(int i=1;i<n;i++)
	{
		if(max<DT[i]) max=DT[i];
	}
	
	return max;
}


void main()
{
	input();
	quicksort(0,n-1);
	printf("%d\n",n-getLIS());
	printf("func_count:%d\n",func_count);
}






























//++이는 나중에 참고만하고 위의 문제만 보도록
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
////////////////////////////////////////////////////////////////////////////////////////////////


/*
전깃줄 문제,


8
1 8
3 9
2 2
4 1
6 4
10 10
9 7
7 6


LIS 

index  0 1 2 3 4 5 6 7     
       8 2 9 1 4 6 7 10
---------------------------
LIS    1 1 2 1 1 1 1 1 
			   2 2 2 2 
                 3 3 3
				   4 4 
				     5


LIS 배열에서 MAX를 찾으면 5 임.
*/



#include<stdio.h>

struct bar
{
	int a;
	int b;
};

bar b[100];
int n;

void sort()
{
 
 for(int i=0; i < n ; i++)
 {
	 bar temp;
	 for(int j=i+1; j < n ; j++)
	 {
		 if(b[i].a > b[j].a)
		 {
		   temp=b[j];
		   b[j]=b[i];
		   b[i]=temp;
		 }
	 }

 }

}

int LIS[100];

void L()
{
	for(int i=0;i<n;i++)
	{
		LIS[i]=1;
		for(int j=0;j<i;j++)
		{
			if(b[j].b < b[i].b &&  LIS[j]+1  > LIS[i] )
			{
				LIS[i]=LIS[j]+1;
			}
		}
	}
}

void main()
{

 freopen("input.txt","r",stdin);
 scanf("%d",&n);

 for(int i=0;i<n;i++)
 {
   scanf("%d",&b[i].a);
   scanf("%d",&b[i].b);
 }
 
  sort();
  L();

 for(int i=0;i<n;i++)
 {
   printf("%d",LIS[i]);
 }

 
 int result=LIS[0];
 for(int i=1;i<n;i++)
 {
  if(result < LIS[i]) result = LIS[i];
 }

 printf("\n result : %d \n", result);
}


/*
//>>>>>>>>>>>>>
첫째 줄에는 두 전봇대 사이의 전깃줄의 개수가 주어진다. 전깃줄의 개수는 100이
하의 자연수이다.
둘째 줄부터 한 줄에 하나씩 전깃줄이 A전봇대와 연결되는 위치의 번호와 B전봇
대와 연결되는 위치의 번호가 차례로 주어진다.
위치의 번호는 500 이하의 자연수이고, 같은 위치에 두 개 이상의 전깃줄이 연결
될 수 없다.

첫째 줄에 남아있는 모든 전깃줄이 서로 교차하지 않게 하기 위해 없애야 하는 전
깃줄의 최소 개수를 출력한다.


8
1 8
3 9
2 2
4 1
6 4
10 10
9 7
7 6
*/

//DP 풀어 보기
//LIS (최장중가수열)

// DP 알고리즘 <그림참조> 
// 이번기회에 정리하도록!
/*
for 1 -> N
LIS[i]=1
for 1 ->  i-j  
aj < ai && lis[j]+1>list[i]
list[i]=lis[j]+1
*/


#include<stdio.h>

int n;
struct w{
	int a;
	int b;
};

w wire[100];
int LIS[100];

//선택 정렬!
void sort()
{
 for(int i=0; i<n-1;i++)
	 for(int j=i+1; j < n ;j++)
	 {
		 w temp;
		 if(wire[i].a > wire[j].a)
		 {
			 temp=wire[i];
			 wire[i]=wire[j];
			 wire[j]=temp;  //여기 실수 많이 한다. 조심!!
		 }
	 }
}

// 이 알고리즘은 n^2의 성능이지만 교재의 Index 트리를 이용하면 nlogn의 성능을 발휘함.
void getLIS()
{
	for(int i=0; i < n ; i++)  // LIS 인덱스 0부터 시작해도 상관없다.
	{
	    LIS[i]=1;	//초기값은 자기자신 1부터 
		for(int j=0;j<i-j;j++)
		{
			if( wire[j].b < wire[i].b &&
			    LIS[j]+1 > LIS[i]  
			)
			LIS[i]=LIS[j]+1; 
		}	
	}	
}

int findmax()
{		
	int max = LIS[0]; 	
	for(int i=1;i<n;i++)	
	{
	  if(max < LIS[i]) max=LIS[i];	
	}	
	return max;
}

void main(void)
{
	freopen("input.txt","r",stdin);
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	 scanf("%d %d",&wire[i].a,&wire[i].b);
	}
	
	sort();
    getLIS();
	printf("%d",findmax());
}



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// IDT를 이용한 방벙 창훈 머리속에서 작성
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>



/*
비트 연산 정리

1 << n     -> 2 ^n

3 << 1     -> 3 *2

3 >> 1    ->  3/2

n>>=1    -> n=n/2;

n<<=1   -> n=n*2;


*/



#include<stdio.h>

int n;
struct w{
	int a;
	int b;
};

w wire[100];
int LIS[100];

int IDT[100];
//실질적으로 배열크기  1<<n 딱 넘어는 값이 배열의 크기다.  


//선택 정렬!
void sort()
{
 for(int i=0; i<n-1;i++)
	 for(int j=i+1; j < n ;j++)
	 {
		 w temp;
		 if(wire[i].a > wire[j].a)
		 {
			 temp=wire[i];
			 wire[i]=wire[j];
			 wire[j]=temp;  //여기 실수 많이 한다. 조심!!
		 }
	 }
}

int MAX(int a, int b)
{
	return a>b ? a:b;
}

// 해당 구간에서 max 값을 가지고 온다.
int getMax(int s, int e)
{
	int max=0;
	
	while(s<e)
	{
		max=MAX(max,IDT[e]);
		if((e%2)==0 )  e--; //짝수면 , 그리고 요게 문제라면 while 이런거 돌릴필요가 없다. 이 다음 바로 홀수로 바뀌니깐...
		s>>=1;  // s=s/2;
		e>>=1;
	}	
	

	if(s==e) max=MAX(max,IDT[s]);
	
	return max;
	//s는 홀수 일때 문제가 된다 , 여기서 S는 고정임
	//e는 짝수 일때 문제가 된다.
}

void update(int l)
{
	while(l>1) // 1은 루트 
	{	
	  if( IDT[l]  >  IDT[l/2] ) IDT[l/2]=IDT[l];
	  l=l/2;
	}
}

void main(void)
{
	int m=-1;
	freopen("input.txt","r",stdin);
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	 scanf("%d %d",&wire[i].a,&wire[i].b);
	 if(m < wire[i].b ) m = wire[i].b;
	}
	
    // 여기 중요하다. 왜 m이 필요한지 1~m까지을 넣을 수 있는 배열이 필요함. 여기에 따라서 Base가 바뀔 것이고.
	int k=0;
	for(k=0; m > 1<<k  ; k++ ); // 세미콜론 주의!!	
	int base = 1<<k; // base  이걸 기준으로 계산을 한다.
	

	sort();
		
	for(int i=0; i < n ;i++)
	{
	    IDT[base+wire[i].b-1]=getMax( base, base+wire[i].b-2)+1;
	    update(base+wire[i].b-1); // 루트쪽으로 올라 가면서 지금 내값이 크다면 큰값으로 갱신한다.
	}

	printf("%d\n",n-IDT[1]);
}

////////////////////////////////////////////
// 창훈 직접품
// 코드가 아닌 그림 형태의 알고리즘으로 풀어야 한다.
// 이해가 되고 까먹지 않는다.

#include<stdio.h>

//#define N 7
//int a[N]={3,2,6,4,5,1};

#define N 8
int a[N]={8,2,3,1,4,6,7,5};
int LIS[N];

void main()
{

	for(int i=0;i<N;i++)
	{
		LIS[i]=1;  // 현재 1로 시작함.1
		for(int j=0;j<i;j++)
		{
			if(a[j]<a[i]) // 지금 내보다 작은값에 연결을 해야됨으로
			{
				if(LIS[j]+1 > LIS[i] ) LIS[i]=LIS[j]+1; // LIS[j]+1 ->이 말은 내가 포함됐을때 현재(이전에 연결된) 값보다 크냐?
			}
		}
	}
	
	for(int i=0;i<N;i++)  //여기에서 제일 큰값을 찾으면됨.
	printf(" %d",LIS[i]);
}


///////////////////////////////////////////////////////////
//전깃줄 재귀방법



#include<stdio.h>

int n=8;
int d[9]={0,8,2,9,1,4,6,7,10};

int result[9];
static int fun_call;

int max(int p, int q)
{
  return p>q ? p:q;
}

int solve(int k)
{

fun_call++;
printf("solve(%d)\n",k);

if(result[k]) return result[k];  // memorizatoin. 중복 함수콜을 제거하기 위해서 

int i, count=1;
for(i=k-1; i>=1 ; i--)
{
  printf("k:%d i:%d\n",k,i);
  if(d[k] > d[i]) count = max(count,solve(i)+1);
}

result[k]=count;

return count;

}

int main()
{
int i,t,m=0;
 for(i=1;i<=n;i++)
 {
  t=solve(i);
  printf("%d index - LIS %d\n ",i,t);
  if(m<t) m=t;
 } 

 printf("func_call:%d LIS:%d\n",fun_call,m);
 return;
}

/*
int d[9]={0,8,2,9,1,4,6,7,10};

int main()
{

  int n=8;

  for(int k=1;k<=n;k++)
 {
 	int count=0;
	for(int i=k-1; i>=1 ; i--)
    {
	  printf("k:%d i:%d\n",k,i);
	  if(d[k] < d[i]) count++;
	}
	printf("\n<%d>\n\n",count);
 }

	return;
}

*/
