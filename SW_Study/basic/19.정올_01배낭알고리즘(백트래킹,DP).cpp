/*

첫째 줄에 물건의 개수 n(1<= n <= 100)과 배낭의 무게 w(1 <= w <= 10000)가
입력된다.
둘째 줄부터 n+1째줄 까지 물건들의 정보가 wi, vi가 한 줄에 하나씩 입력된다.
(1 <= wi, vi <= 100)

배낭의 무게 W를 초과하지 않으면서 물건의 가격의 총합의 최댓값을 출력한다.
입력 예 출력 예
4 5

2 3
1 2
3 3
2 2


7
*/


// 배낭 창훈의 백트래킹
/*

첫째 줄에 물건의 개수 n(1<= n <= 100)과 배낭의 무게 w(1 <= w <= 10000)가
입력된다.
둘째 줄부터 n+1째줄 까지 물건들의 정보가 wi, vi가 한 줄에 하나씩 입력된다.
(1 <= wi, vi <= 100)

배낭의 무게 W를 초과하지 않으면서 물건의 가격의 총합의 최댓값을 출력한다.
입력 예 출력 예
4 5
2 3
1 2
3 3
2 2

7


-
그냥 백트래킹시 결과










16 20
2 3
1 2
3 3
2 2
2 3
1 2
3 3
2 2
2 3
1 2
3 3
2 2
2 3
1 2
3 3
2 2

그냥 Backtracking 결과
max_value: 28
func_count: 131071


DT 테이블 이용시 결과
max_value: 28
func_count: 222

*/

//DT 테이블 버젼 

#include<stdio.h>

int wi[100];
int vi[100];

int N;
int W;

int fun_call;

int DT[100][10000];


void input()
{
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &W);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &wi[i], &vi[i]);
	}
}

int MAX(int a, int b)
{
	return a > b ? a : b;
}

int solve(int i , int r)
{
	fun_call++;

	if (DT[i][r] != -1 ) return DT[i][r];

	if (i == N + 1)
	{
		return 0;
	}

	int a = 0;
	int b = 0;

	if (W >= wi[i] + r)  //넣을 수 있을 경우!  이때도 자발적으로 넣지 않을 수있다.
	{
		a = MAX(solve(i + 1, wi[i] + r) + vi[i], solve(i + 1, r));
	}
	else   // 어쩔수 없이 못 넣는 경우
	{
		b = solve(i + 1, r);
	}

	return DT[i][r]=MAX(a, b);
}

void main()
{
	input();

	for (int i = 0; i < 100; i++)
	for (int j = 0; j < 10000; j++)
	{
		DT[i][j] = -1;
	}

	printf("%d\n", solve(1,0));
	printf("%d\n", fun_call);
}













///////////////////////////////////////////////////////////

// 창훈 최종 필기
// 그냥 Backracking으로 직접 품
#include<stdio.h>

//app의 갯수
#define SIZE 100

int n; // 물건의 갯수 
int w; // 배낭의 무게 
int wi[SIZE];
int vi[SIZE];

int func_count;

int max_value=0;

void f(int i,int weight, int value)
{
	func_count++;

if(i==n+1) //여기 실수 '=' 이 뭐냐? ㅡㅡ;;
{
	if(weight <= w ) //초과하면 안됨으로
	{
		if(value > max_value) max_value=value;
	}
	return;
}
	

f(i+1,weight+wi[i],value+vi[i]);
f(i+1,weight,value);	
}


void input()
{
	freopen("input.txt","r",stdin);
	
	scanf("%d %d",&n,&w);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&wi[i],&vi[i]);
	}

}


void main()
{
	input();
    f(1,0,0);
	printf("max_value: %d\n",max_value);
	printf("func_count: %d\n",func_count);
}




// 창훈 최종 필기
// 반환값 +  DT 테이블 

#include<stdio.h>

//app의 갯수
#define SIZE 100

int n; // 물건의 갯수 
int w; // 배낭의 무게 
int wi[SIZE];
int vi[SIZE];

int func_count;

int DT[101][10001];

int MAX(int a, int b)
{
	return a > b ? a : b;
}

int max_value=0;

int f(int i,int weight)
{
	//printf(" i : %d , weight: %d\n",i,weight);
	if(DT[i][weight] != -1) return DT[i][weight];
	
	func_count++;

	if(i==n+1)
	{
	   return DT[i][weight]=0; //아래에서 조건 처리가 됨으로 여기서 따로 할필요가 없다.
	}

	
	if(weight+wi[i] > w) //여기 실수!! 한번 더 생각하자, 노드의 Weight를 보고 결정해야지 
                         //Base처리가 자유롭다.
	{
		return DT[i][weight]=f(i+1,weight);
	}	
	else
	{
		return DT[i][weight]=MAX( f(i+1,weight+wi[i]) + vi[i]  , f(i+1,weight) );
	}
}


void input()
{
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
	scanf("%d %d",&n,&w);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&wi[i],&vi[i]);
	}

	for(int i=0;i<=n;i++)
		for(int j=0;j<=w;j++)  //여기실수 했다. 0부터 들어 가야한다. 
		{                      //DT테이블 이용해서 값이 안나오면 재귀함수 앞단에 로깅을 넣고보자
			DT[i][j]=-1;
		}
}


void main()
{
	input();
    max_value=f(1,0);
	printf("max_value: %d\n",max_value);
	printf("func_count: %d\n",func_count);

}






//DT 테이블 창훈 버젼 
#include<stdio.h>

int N; //물건의 갯수
int W; //무게

int w[20];
int v[20];

int max_value=-987654321;
int func_count;

int DT[100][10000];


int MAX(int a, int b)
{
	return a>b ? a : b;
}

int f(int i,int r)
{

	if(DT[i][r]!=-1) return DT[i][r];

		func_count++;

	if(i==N)
	{
		return DT[i][r]=0;
	}

	int a=0;
    int b=0;
	
	if(r+w[i]<=W) // 트리를 그려보고 내려 보내지 말아야될 조건,
	a=f(i+1,r+w[i])+v[i];
   
	b=f(i+1,r);

	return DT[i][r]=MAX(a,b);
}


void input()
{
	freopen("input.txt","r",stdin);

	scanf("%d %d",&N,&W);

	for(int i=0;i<N;i++)
	{
		scanf("%d %d",&w[i],&v[i]);
	}
}

void main()
{

	input();

	for(int i=0;i<100;i++)
		for(int j=0;j<10000;j++)
			DT[i][j]=-1;


	printf("%d\n",f(0,0));
	printf("%d \n",func_count);
}











//for 루프에 의한 상향식 방법
// 창훈 최종 필기
// 반환값 +  DT 테이블 
#include<stdio.h>

//app의 갯수
#define SIZE 100

int n; // 물건의 갯수 
int w; // 배낭의 무게 
int wi[SIZE];
int vi[SIZE];

int DT[100][10000];

int MAX(int a, int b)
{
	return a > b ? a : b;
}

void input()
{
	freopen("input.txt","r",stdin);
	
	scanf("%d %d",&n,&w);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&wi[i],&vi[i]);
	}

}


void main()
{
	input();

	for(int i=1;i<=n;i++)
	for(int j=1;j<=w;j++)
	{
		if(wi[i]<=j)  // 이 부등호 매번 틀린다. 주의!!!!
		{
		  DT[i][j]=MAX(DT[i-1][j-wi[i]]+vi[i] , DT[i-1][j]);	
		}
		else
		{
		  DT[i][j]= DT[i-1][j];
		}
	}	

	printf("%d",DT[n][w]);
}


















































//아래꺼 그냥 보지 말고 참조만 하기.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++



// 배낭 창훈의 백트래킹 29번 함수콜
// 비선형 구조의 전체 탐색.

#include<stdio.h>

int C;  // 아이템의 수 
int W;  // 배낭의 무게 

int w[101];
int v[101]; 
int max_weight; 

static int function_count=0;

void solve(int weight, int value , int k)
{
	function_count++;
	
	//if ( weight < max_weight ) return;
	// 깊이를 가지고Prouning 할수 없다. 정렬된 형태가 아니다. 언제 최적의 아이템이 나올지 모른다.!!
	// 끝까지 가봐야지 안다.!
	
	if ( weight > W ) return;  // 당연히 처리해야함.

	if( max_weight < value ) max_weight=value;   // 여기 위치 중요함!!
	printf("k:%d  , weight:%d , value: %d \n", k, weight ,value);
	
	if(k==C) {return;}  // 여기 위치 중요함 !! 리턴을 먼저했을경우 달리진다.
	                    // 여기에서 처리를 해주고 리턴을 해줘야한다.
	k++;
	
	solve(weight+w[k], value+v[k],k);  // 아이템을 선택햇을때 
	solve(weight,value,k); // 아이템을 선택하지 않을때 
	
}


void main()
{
 int i;
 freopen("input.txt","r",stdin);

 scanf("%d",&C);
 scanf("%d",&W);

 for(int i=1;i<=C;i++)
 {	 
   scanf("%d %d",&w[i],&v[i]);  
 }
 
 solve(0,0,0);

 printf("ans: %d , function_count :%d",max_weight,function_count);

} 


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//교재 알고리즘 나름 DP를 조금 따라 만든 Backtracking.
// 26번 호출
////>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


#include<stdio.h>

int C;  // 아이템의 수 
int W;  // 배낭의 무게 

int w[101];
int v[101]; 
int max_weight; 

static int function_count=0;

int max(int a,int b) { return a > b ? a : b; }

//1~i 까지 고려할때, 배낭 용량 r가 남았을때 최적의 int을 반환하는 함수

int solve(int i, int r)
{
	function_count++;
	
	if(i == C+1  || r < 0) return 0;
	 
	if(w[i] > r)
	return solve(i+1,r); // 트리를 확장하다가, 현재 Item이 r 보다 크다고 한다면 이 아이템은 선택되지 않는다. 
	else  return max( solve(i+1,r) ,  solve( i+1 , r-w[i] )+v[i] ) ;    // 바닥까지 도착하면 결과를 올리면서 최적의 해를 찾는다.
}


void main()
{
 int i;
 freopen("input.txt","r",stdin);

 scanf("%d",&C);
 scanf("%d",&W);

 for(int i=1;i<=C;i++)
 {	 
   scanf("%d %d",&w[i],&v[i]);  
 }

 int ans=solve(1,W); 

 printf("ans: %d , function_count :%d \n",ans ,function_count);

} 

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// DP로 01 knapsanp 풀이 
////>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#include<stdio.h>

int C;  // 아이템의 수 
int W;  // 배낭의 무게 

int w[101];
int v[101]; 
int values[100][10000];

int max(int a,int b) { return a > b ? a : b; }

void main()
{
 int i;
 freopen("input.txt","r",stdin);

 scanf("%d",&C);
 scanf("%d",&W);

 for(int i=1;i<=C;i++)
 {	 
   scanf("%d %d",&w[i],&v[i]);  
 }
 
 for(i=1;i<=C;i++)   // items;
 for(int j=1;j<=W;j++) // 무게를 0~원하는 용량까지 늘려감.
 {
	if(w[i] > j) // 현재의 항목이 j의 용량 보다 크다면 
     values[i][j] = values[i-1][j]; // 이전 항목의 결과 값을 가지고 온다.
    else		 
	 values[i][j] = max( values[i-1][j] , values[i-1][j-w[i]] + v[i]  ) ;
 }
 
 for(i=0;i<=C;i++) 
 {
  for(int j=0;j<=W;j++) 
  {
   printf(" %d",values[i][j]);
  }
  printf("\n");  
} 

 printf("\n ans : %d\n",values[C][W]);
}






