/*
app 종료 문제 
*/
//앱
//창훈품 , 가장 쉽게 머리 속에 떠오른것을 코딩. 정답!
// Cost를 리턴해서 DT 테이블 적용까지 도전해본다.
// DT 테이블 방식은 비슷하게 접근했지만 못 풀었다. 다시 풀어 보도록.!
/*
5 60
30 10 20 35 40
3 0 3 5 4
->6

20 600
30 100 20 35 40 30 100 20 35 400 30 100 20 35 40 30 100 20 35 40
3 2 3 5 4 7 4 3 5 4 3 3 3 5 4 3 2 3 5 8
->8

20 754
30 100 20 35 40 30 100 20 35 400 30 100 20 35 40 30 100 20 35 40
3 2 3 5 4 7 4 3 5 4 3 3 3 5 4 3 2 3 5 8
->15


20 754
30 100 20 35 40 30 100 20 35 400 30 100 20 35 40 30 100 20 35 40
0 0 5 0 7 4 3 5 4 0 0 3 0 4 3 2 3 5 8 0
->3
*/


#include<stdio.h>

#define INF 987654321

int N;
int M;

int mi[100];
int ci[100];

int fun_call;

int DT[100][10000];


void input()
{
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &mi[i]);
	}

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &ci[i]);
	}

}

int MIN(int a, int b)
{
	return a > b ? b : a;
}

int solve(int i , int r)
{
	if (DT[i][r] != -1) return DT[i][r];

	fun_call++;

	if (i == N + 1)
	{
		if (r >= M) return DT[i][r]=0;
		else return DT[i][r]=INF;
	}

	return DT[i][r] = MIN(solve(i + 1, r + mi[i]) + ci[i], solve(i + 1, r));
}

void main()
{
	input();

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 10000; j++)
			DT[i][j] = -1;

	printf("%d\n", solve(1, 0));
	printf("%d\n", fun_call);
}


////////////////////////////////
// 선택된 app 추적하기 
////////////////////////////////


#include<stdio.h>

#define INF 987654321

int N;
int M;

int mi[100];
int ci[100];

int fun_call;

int DT[100][10000];

int item[10000];

void input()
{
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &mi[i]);
	}

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &ci[i]);
	}

}

int MIN(int a, int b)
{
	return a > b ? b : a;
}

int solve(int i, int r)
{
	if (DT[i][r] != -1) return DT[i][r];

	fun_call++;

	if (i == N + 1) // 모든 app을 고려했을때 
	{
		if (r <= 0) return DT[i][r] = 0;  // 메모리를 확보햇을때
		else return DT[i][r] = INF;       // 확보 못했을때 
	}

	int a = solve(i + 1, r - mi[i]) + ci[i];
	int b = solve(i + 1, r);

	if (a < b)
	{
		item[r] = i;  //해당 메모리 r이 남았을때 뭐가 선택되었는지 추적하기 
		DT[i][r] = a;
	}
	else
	{
		DT[i][r] = b;
	}

	return DT[i][r];

	//return DT[i][r] = MIN(solve(i + 1, r + mi[i]) + ci[i], solve(i + 1, r));
}

void main()
{
	input();

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 10000; j++)
			DT[i][j] = -1;

	printf("%d\n", solve(1, M));
	printf("%d\n", fun_call);

	//선택된 app 복원하기 
	for (int s = M; s > 0; s=s - mi[item[s]])
	{
		printf("selected app : %d\n", item[s]);
	}

}















////////////////////////////////////
//창훈 필기 일반적은 Backtracking방법 
//처음 가장 단순한 방법과 가지치기 , 그리고 선택된 app 찾아 보기
#include<stdio.h>

#define SIZE 100

int n; // app의 갯수
int M; // 필요로하는 메모리
int m[SIZE];
int c[SIZE];

int func_count;

//선택된 app을 알기위해서
int checked[SIZE];
int result_checked[SIZE]; 

int min_cost=987654321;

void f(int i,int r,int cost)
{

	if(cost>= min_cost) return; 

	func_count++;
	if(i==n+1)
	{
		if(r<=0)
		{
			if(min_cost > cost)
			{
				min_cost=cost;

				for(int i=1;i<=n;i++)
				result_checked[i]=checked[i];
			}
		}
		return;
	}
	
	 checked[i]=1;
	 f(i+1,r-m[i],cost+c[i]); 
	 
	 checked[i]=0;
	 f(i+1,r     ,cost);

}


void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d %d",&n,&M);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m[i]);
	}
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
}


void main()
{
	input();
    f(1,M,0);
	printf("min_cost:%d\n",min_cost);
	printf("func_count:%d\n",func_count);


	printf("Selectd app : ");

	for(int i=1;i<=n;i++)
	{
      if(result_checked[i]==1) printf(" %d",i);
	}
	
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//창훈 최종 필기함. 반환값 버젼 
#include<stdio.h>

//app의 갯수
#define SIZE 100

int n; // app의 갯수
int M; // 필요로하는 메모리
int m[SIZE];
int c[SIZE];

int func_count;

int DT[100][100000];

//이 DT 테이블을 잡아야 되지만 크기를 초과함. 컴파일 에러.
//그러나 이문제의 핵심 포인트는 이 부분이다.
//int DT[100][10000000];

//
int MIN(int a, int b)
{
	return a > b ? b : a;
}


int f(int i,int r)
{
	   if(DT[i][r]!=-1) return DT[i][r];

		if(i==n+1)
		{
			if(r<M) // 바닥까지 온 상태에서 메모리를 확보하지 못했음. 
			{       // 해당 노드를 선택하지 못하게 함.
				return DT[i][r]=987654321;
			}
	
			//일반적인 바닥의 경우 0으로 올려서 Cost에 의해서 선택하게 함.
			return DT[i][r]=0;
		}

	
#if 1  // 솔직히 이건 가지치기 조건이다. 다 돌아도 상관은 없다.  확보가 안되었다면 이건 선택해도 되고 안해도 되고,
		if(r<M) //더 선택이 필요하다면, -> 이때 해당 노드를 선택할수도 있고 안할 수도 있다.
		 return DT[i][r]=MIN( f(i+1,r+m[i])+c[i], f(i+1,r) );
		else   // 이미 용량확보가 된 상태임으로 그냥 넘어간다.   
		 return DT[i][r]=f(i+1,r) ;	
#else  // 원하는 용량 이상을 확보하면됨.
		return DT[i][r]=MIN( f(i+1,r+m[i])+c[i], f(i+1,r) );
#endif

}


void input()
{
	freopen("input.txt","r",stdin);
	
	scanf("%d %d",&n,&M);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m[i]);
	}
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
}


void main()
{
	input();

	//초기화
	//메모리 용량을 하향식으로 감소할땐 j가 음수가 될수가 있다.주의해라!!
	//메모리 용량을 DT 테이블을 사용하기 위해서 상향식으로 올려야한다.!! 창훈 실수 했다.
	for(int i=0; i<=100; i++)
	for(int j=0 ;j<=100000;j++)
	{
		DT[i][j]=-1;
	}

	printf("%d",f(1,0));
}


/////////
//3.DP 풀이 창훈 필기 직접품.
//할수있다.!!

//창훈필기 직접품.
//상향식 방법

#include<stdio.h>

//app의 갯수
#define SIZE 100

int n; // app의 갯수
int M; // 필요로하는 메모리
int m[SIZE];
int c[SIZE];

//그런데 여기서 정의역을 1000,0000을 잡아야하지만, 불가능
int DT[SIZE][1000000];

//이 DT 테이블을 잡아야 되지만 크기를 초과함. 컴파일 에러.
//그러나 이문제의 핵심 포인트는 이 부분이다.
//int DT[100][10000000];

//
int MIN(int a, int b)
{
	return a > b ? b : a;
}


void input()
{
	freopen("input.txt","r",stdin);
	
	scanf("%d %d",&n,&M);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m[i]);
	}
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
}


void main()
{
	input();

	//0번째를 마지막 정의역까지 INF로 
	for(int j=1 ;j<=M; j++)
	{
		DT[0][j]=987654321;
	}


	//테이블을 그려보고 점화식을 끌어내야한다.
	for(int i=1;i<=n;i++) //고려해야할 app.
	{
		for(int j=1;j<=M;j++) //메모리의 증가 어디까지 증가할까? 정의역의 마지막까지 증가해야함.
		{
			if(m[i]>=j){ 
				DT[i][j]= MIN(c[i], DT[i-1][j]);
			}			
			else
			{
			  DT[i][j]= MIN( DT[i-1][j-m[i]]+c[i],DT[i-1][j])  ;
			}
			
		}
	}

	printf("%d",DT[n][M]);
}


/////////////////////////
//DP 정의역을 바꿈 -> 최종 완벽풀이
////////////////////////
//창훈필기 직접품.
//상향식 방법, 정의역을 바꿔보기
/*
DT[i][j] : 1~i app 까지 고려했을때, 해당 비용(j)를 이용해서 확보할 수 있는 최대 메모리양. 
*/

#include<stdio.h>

//app의 갯수
#define SIZE 100

int n; // app의 갯수
int M; // 필요로하는 메모리
int m[SIZE];
int c[SIZE];

//정의역의 범위를 바꿈.
//그런데 여기서 정의역을 1000,0000을 잡아야하지만, 불가능
int DT[SIZE][1000000]; // app갯수 * max cost

//
int MAX(int a, int b)
{
	return a > b ? a : b;
}


void input()
{
	freopen("input.txt","r",stdin);
	
	scanf("%d %d",&n,&M);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m[i]);
	}
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
}


void main()
{
	input();


	//테이블을 그려보고 점화식을 끌어내야한다.
	for(int i=1;i<=n;i++) //고려해야할 app.
	{
		for(int j=0;j<=(n*100);j++) //비용의 증가 어디까지 증가할까? 정의역의 마지막까지 증가해야함.
			                       //여기 실수 했음 비용은 0부터 증가해야함.
		{
			if(c[i]<=j){ 
				DT[i][j]= MAX(DT[i-1][j-c[i]]+m[i], DT[i-1][j]); //어떻게 해야지 더 많은양의 메모리를 확보하니?
			}			
			else
			{
				DT[i][j]=DT[i-1][j];
			}
			
		}
	}

	int value=n*100;
	for(int j=1;j<=(n*100);j++)
	{
		if( M <= DT[n][j] )
		{
			value=j;
			break;
		}
	}

	if(value == n*100)
	{
		printf("No answer\n");
	}
	else
	{
		printf("%d",value);
	}
		
	
}






























//아래껀 그냥 참조만하고 위의 것만 봄.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include<stdio.h>

int N;
int M;

int m[100];
int c[100];

int checked[100];

int min_cost=987654321;

static int func_call;

void solve(int memory, int cost)
{
	
	if(cost >= min_cost) return;

	func_call++;

	if(memory>=M)  // 넘어 설수도 있다. 맞제? 엉 맞다.
	{
		if(min_cost>cost) min_cost=cost;
		return;
	}

	for(int i=0;i<N;i++)
	{
		if(checked[i]==0) //이렇게 후보군을 정할수도 있다. 
		                  //하지만, 하나의 아이템에 대해서 선택하지 않고/선택했을 경우로 두 갈래를 나눌수도 있다.
                          //지금 방법이 제일 느리다.						  
		{	
			checked[i]=1;
			solve(memory+m[i] ,cost+c[i]);
			checked[i]=0;
		}
	}
}

void main()
{
	freopen("input.txt","r",stdin);
	
	scanf("%d %d",&N,&M);

	for(int i=0;i<N;i++)
	{
		scanf("%d",&m[i]);
	}

	for(int i=0;i<N;i++)
	{
		scanf("%d",&c[i]);
	}

	solve(0,0);

	printf("%d\n",min_cost);
	printf("func_call:%d\n",func_call);
}

///////////////////////////////////////////

//앱

//DT 테이블 고려방식

//중요한 조건 

//1.
//탐색시 모든 app을 고려해야한다.
//2.
//돌면서 r가 0이 될수도있다. 이땐 선택을 안한다.!
//3.
//기본적인 루틴은 해당 app을 선택을 한다/ 안한다. 여기서 최소다.

/*
5 60
30 10 20 35 40
3 0 3 5 4
*/

#include<stdio.h>

int N;
int M;

int m[100];
int c[100];

//int DT[100][10000000]; // 이렇게 못잡는다, DT 테이블을 어떻게 끌어 내지??

int MAX=987654321;
int min_cost;

static int func_call;

int MIN(int a, int b)
{
	return a>b ? b : a;
}

int solve(int i, int r)
{

 // printf("i:%d r:%d\n",i,r);
	func_call++;

if(i==N) //모든 app을 다 교려했다.!! 끝까지 와서  < 실수!!! 이 부분 못 끌어 냈다. >
{
	if(r>0) return MAX;  // 메모리가 확보가 안됐다. 이건 해가 아니다. 위로 올릴때 선택이 안되게한다.
	else return 0;       // 메모리가 확보가 됐다. 일단 해긴 하다.!!
}
		
if(r<0)  // 현재 노드에서 필요한 메모리가 없다면, 선택하지 마라. // 실수!! 못 끌어냄 
 return solve(i+1,r);  // 폭 가지치기 없어도 상관 없다. 연산량에 영향을 미치고, r가 음수이면 DT 테이블 적용 못함.
else
 return MIN(solve(i+1,r),solve(i+1,r-m[i])+c[i]);

}

void main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	scanf("%d %d",&N,&M);

	for(int i=0;i<N;i++)
	{
		scanf("%d",&m[i]);
	}

	for(int i=0;i<N;i++)
	{
		scanf("%d",&c[i]);
	}

	min_cost=solve(0,M);

	printf("%d\n",min_cost);
	printf("func_call:%d\n",func_call);
}


////////////////////////////////////////////////

#include<stdio.h>

int N;
int M;

int m[100];
int c[100];

int MAX=987654321;
int min_cost;

static int func_call;

int MIN(int a, int b)
{
	return a>b ? b : a;
}

int solve(int i, int r)
{

//printf("i:%d r:%d\n",i,r);
	func_call++;

if(i==N) //모든 app을 다 교려했다.!! 끝까지 와서  // 실수!!! 이 부분 못 끌어 냈다.
{
	if(r>0) return MAX;  // 메모리가 확보가 안됐다. 해가 아니다. 선택 안되게한다.!!
	else return 0;       // 메모리가 확보가 됐다. 일단 해긴하다.!!
}
		
if(r<0)  // 현재 노드에서 필요한 메모리가 없다면, 선택하지 마라. // 실수!! 못 끌어냄  답은 나온다.
 return solve(i+1,r);  // 폭 가지치기 없어도 상관 없다. 연산량에 영향을 미치고, r가 음수이면 DT 테이블 적용 못함.
else
 return MIN(solve(i+1,r),solve(i+1,r-m[i])+c[i]);

}

void main()
{
	freopen("input.txt","r",stdin);
	
	scanf("%d %d",&N,&M);

	for(int i=0;i<N;i++)
	{
		scanf("%d",&m[i]);
	}

	for(int i=0;i<N;i++)
	{
		scanf("%d",&c[i]);
	}

	min_cost=solve(0,M);

	printf("%d\n",min_cost);
	printf("func_call:%d\n",func_call);
}


///////////////////////////////////////////////////////////////
/*
DT 테이블 창훈 임시적용
20 754
30 100 20 35 40 30 100 20 35 400 30 100 20 35 40 30 100 20 35 40
3 2 3 5 4 7 4 3 5 4 3 3 3 5 4 3 2 3 5 8
->15
2090번 호출
*/

#include<stdio.h>

int N;
int M;

int m[100];
int c[100];

int DT[100][100000]; // 이렇게 못잡는다, DT 테이블을 어떻게 끌어 내지?? 문제의 정의역을 초과함. AD에서 해결책있음

int MAX=987654321;
int min_cost;

static int func_call;

int MIN(int a, int b)
{
	return a>b ? b : a;
}

int solve(int i, int r)
{

 if(DT[i][r]!=-1) return DT[i][r];
 
 //printf("i:%d r:%d\n",i,r);
	func_call++;

if(i==N) //모든 app을 다 교려했다.!! 끝까지 와서  < 실수!!! 이 부분 못 끌어 냈다. >
{
	if(r<M) return  DT[i][r]=MAX;  // 메모리가 확보가 안됐다. 이건 해가 아니다. 위로 올릴때 선택이 안되게한다.
	else return DT[i][r]=0;       // 메모리가 확보가 됐다. 일단 해긴 하다.!!
}
		
if(r>M) 
 return DT[i][r]=solve(i+1,r); 
else
 return DT[i][r]=MIN(solve(i+1,r),solve(i+1,r+m[i])+c[i]); // DT 테이블 적용하기 위해서 양으로 바꿈.,완벽한 풀이가 아님 정의역 범위를 벗어남.

}

void main()
{
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
	scanf("%d %d",&N,&M);

	for(int i=0;i<N;i++)
	{
		scanf("%d",&m[i]);
	}

	for(int i=0;i<N;i++)
	{
		scanf("%d",&c[i]);
	}

	//-1로 DT 테이블 초기화
	for(int i=0; i< 100; i++)
		for(int j=0;j<100000;j++)
			DT[i][j]=-1;

	min_cost=solve(0,0);

	printf("%d\n",min_cost);
	printf("func_call:%d\n",func_call);
}





















///////////////////////////////////////////////////////////////

//교재 풀이
#include<stdio.h>
#define MAXV 99999

int M,n,i,m[101],c[101];

int min(int a, int b) {return a<b ? a:b;}

//1~i 까지의 app을 고려했을때 요구하는 메모리가 r일 경우의 최소 비용 
int f(int i, int r)
{
 if(i==0) //바닥까지 왔다면 
 {
    if(r<=0) return 0;
	else return MAXV;
 }
 else if(r<=0)   f(i-1,r);  // 바닥까지 가기전에 모든 메모리를 확보했다면, 현재 I번째 APP 을 선택하지 마라.  
                            // r<=0이 더 맞지 않나? 0이면 이미 메모리를 다 확보한 상태인데, 교재 풀이가 이상한것 같다.  
	  else min( f(i-1,r) , f(i-1,r-m[i])+c[i] );
}

int main()
{
 freopen("input.txt","r",stdin);
 scanf("%d %d",&n,&M);
 for(i=1;i<=n;i++) scanf("%d",&m[i]);
 for(i=1;i<=n;i++) scanf("%d",&c[i]);
 printf("%d",f(n,M));
 return 0;
}