#include<stdio.h>

int N;
int MAP[21][21];
int CHK;  //해당 행/열의 선택 유무를 하나의 변수에 비트로 표현한다.

int DT[1 << 20];
int func_cnt;

void input()
{
	scanf("%d", &N);
	for (int x = 0; x < N;x++)
		for (int y = 0; y < N; y++)
		{
			scanf("%d", &MAP[x][y]);
		}
}

int MIN(int a, int b)
{
	return a > b ? b : a;
}

//r번째 라인에서의 최소합
int solve(int r)
{

	if (DT[CHK]) return DT[CHK];
	func_cnt++;

	int value = 0x7FFFFFFF;

	if (r == N) return  DT[CHK] = 0;

	for (int i = 0; i < N; i++)
	{
		if ((CHK & (1 << i)) == 0)
		{
			CHK += (1 << i);
			//트리로 표현현다. 트리의 바닥에서 부터 최적해을 끄집고 올라온다.(최소합)
			value = MIN(value, solve(r + 1) + MAP[r][i]);
			CHK -= (1 << i);
		}
	}

	return DT[CHK]=value;
}

void main()
{
	freopen("input.txt", "r", stdin);
	input();

	printf("%d\n", solve(0));
	printf("func_cnt:%d\n", func_cnt);
}
















/////////////////////////////////////////////


//1.DT 테이블을 이용하기
#include<stdio.h>

int n; // map size
int map[20][20];
int chk; //전역으로 해도 상관없음.
int DT[1<<20];

int func_call;

int solve(int r)
{
	if(DT[chk]!=-1) return DT[chk];
	func_call++;

	if(r==n)
	{
		return DT[chk]=0;
	}

	int min_value=987654321;
	for(int i=0;i<n;i++)
	{
		if( (chk&(1<<i)) == 0)
		{
			chk+=(1<<i);
			int temp=solve(r+1)+map[r][i];
			if(min_value > temp) min_value=temp;
			chk-=(1<<i);
		}
	}

	return DT[chk]=min_value;
}

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


void main()
{
	input();

	for(int i=0;i<(1<<20);i++)
	DT[i]=-1;

	printf("%d\n",	solve(0));
	printf("func_count:%d\n",func_call);
}











//2.백트래킹으로 풀기
//창훈 최종 필기,
//가장 기본적인 백트레킹 예제이다.
//그러나 아무리 가지치기를 해도 정의역의 크기가 20임으로 정해진 시간에 답이 나오지 않는다.
//DT 테이블을 이용해한다.

#include<stdio.h>

int n; // map size
int map[20][20];
int chk[20];
int min_value=987654321;

int func_call;

void solve(int r, int sum)
{
	if(sum>min_value) return;
	func_call++;

	if(r==n)
	{
		if(min_value > sum){min_value=sum;}
		return;
	}

	for(int i=0;i<n;i++)
	{
		if(chk[i]==0)
		{
			chk[i]=1;
			solve(r+1,sum+map[r][i]);
			chk[i]=0;
		}
	}
}

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


void main()
{
	input();
	solve(0,0);
	printf("%d\n",min_value);
	printf("func_count:%d\n",func_call);
}









//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
/*
n*n개의 수가 주어진다(1<=n<=20).
이때 겹치지 않는 각 열과 각 행에서 수를 하나씩 뽑는다.
(즉, 총 n개의 수를 뽑을 것이다. 그리고 각 수는 100 이하의 값이다.)
이 n개의 수의 합을 구할 때 최솟값을 구하시오.
입력
첫 줄에 n이 입력된다. 다음 줄 부터 n+1줄 까지 n개씩의 정수가 입력된다.

전체 탐색

3
1 2 5
2 4 3
5 4 3

-> 7

func_call : 16   
가지치기 func_call : 10

구한 최소의 합 출력 
*/


//창훈 최종 분석
//기본적으로 backtracking+가지치기를 이용해서 정답을 풀었다.
//하지만 n이 10이하에서만 적용이 된다. 20까지 된다면 불가능하다.
//무조건 중복이 일어나는 부분을 찾아서 DT 테이블을 적용해야된다. 이 부분은 생각 나지도 않고 풀지도 못했다.
//해당 문제는 엄청 좋은 문제이다. 다음에 또 다시 접근해보도록 하자.









/////////////////////////////////////////////////////////////////////////


#include<stdio.h>

#define INF 987654321

int DT[21][21];
int n;
int min_sum=INF;
int check[21];

static int func_count;

void f(int sum, int k)  
{

 //if( sum >= min_sum ) return;  // 가지치기 들어가면 조금 좋아짐.
 
 func_count++;

  if(k==n+1)
  {
	if(sum<min_sum)
	  { 
		  printf("bingo: %d\n",  sum);
		  min_sum=sum;
	  }
  }
  
  for(int i=1; i<=n; i++)
  {
	  if(check[i]==0)
	  {
		  check[i]=1;
		  f(sum+DT[k][i],k+1);
		  check[i]=0;  // i 를 현재 노드에서 다른 녀석이 선택할 수있게 흔적을 지워준다.
	  } 
  }
	
}


void main()
{

freopen("input.txt","r",stdin);
scanf("%d",&n);

for(int i=1; i<=n ; i++)
{
	for(int j=1;j<=n;j++)
	scanf("%d", &DT[i][j]);
}

f(0,1);

printf("sum:%d\n",min_sum );
printf("func_count:%d\n",func_count );
}



// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//  반환값 버젼
//  창훈 못 풀었음. 트리  그림을 그려 보고 구조를 잘 확인해라.
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#include<stdio.h>

#define INF 987654321

int DT[21][21];
int n;
int min_sum=INF;
int check[21];

static int func_count;


int min(int a, int b)
{
	return a > b ? b : a;
}

int f(int k)    // k 는 row
{
 
  int answer=INF;

  if(k==n+1)
  {
	return 0;
  }
  
  for(int i=1; i<=n; i++)
  {
	  if(check[i]==0)
	  {
		  check[i]=1;
		  answer = min ( answer, f(k+1)+DT[k][i] ); // 현재 노드에서 후보군들 사이에서 제일 작은 값을 올림.
		  check[i]=0;
	  } 
  }
  
   return answer;	
}


void main()
{

freopen("input.txt","r",stdin);
scanf("%d",&n);

for(int i=1; i<=n ; i++)
{
	for(int j=1;j<=n;j++)
	scanf("%d", &DT[i][j]);
}

printf("sum:%d\n",f(1) );
printf("func_count:%d\n",func_count );
}


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//  checked 배열이 하던걸 비트로 컨트롤하기 , 비트를 전역으로 관리하기,
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#include<stdio.h>

#define INF 987654321

int map[21][21];
int n;
int min_sum=INF;

static int func_count;

int bit;


int DT[1<<21];

int min(int a, int b)
{
	return a > b ? b : a;
}

int f(int k)    // k 는 row
{
 
  if(k==n)
  {
	return 0;
  }
  
  if(DT[bit]==0)
  {
	  int answer=INF;

	  for(int i=0; i<n; i++)
	  {
		  if( (bit & 1 << i ) ==0)
		  {
			 bit+=(1<<i);
			 answer = min ( answer, f(k+1)+map[k][i] ); // 현재 노드에서 후보군들 사이에서 제일 작은 값을 올림.
			 bit-=(1<<i);
		  } 
	  }
	  
	  DT[bit]=answer;
  }
   return DT[bit];	
}


void main()
{

freopen("input.txt","r",stdin);
scanf("%d",&n);

for(int i=0; i<n ; i++)
{
	for(int j=0;j<n;j++)
	scanf("%d", &map[i][j]);
}

printf("sum:%d\n",f(0) );
printf("func_count:%d\n",func_count );
}





//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//  checked 배열이 하던걸 비트로 컨트롤하기 
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#include<stdio.h>

#define INF 987654321

int DT[21][21];
int n;
int min_sum=INF;
//int check[21];

static int func_count;

int bit;

int min(int a, int b)
{
	return a > b ? b : a;
}

int f(int k)    // k 는 row
{
 
  int answer=INF;

  if(k==n+1)
  {
	return 0;
  }
  
  for(int i=1; i<=n; i++)
  {
	 // if(check[i]==0)
	  if( (bit & 1 << i ) ==0)
	  {
		 // check[i]=1;
		 bit+=(1<<i);
		  answer = min ( answer, f(k+1)+DT[k][i] ); // 현재 노드에서 후보군들 사이에서 제일 작은 값을 올림.
		 //  check[i]=0;
	  	bit-=(1<<i);
	  } 
  }
  
   return answer;	
}


void main()
{

freopen("input.txt","r",stdin);
scanf("%d",&n);

for(int i=1; i<=n ; i++)
{
	for(int j=1;j<=n;j++)
	scanf("%d", &DT[i][j]);
}

printf("sum:%d\n",f(1) );
printf("func_count:%d\n",func_count );
}



// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//   내 소소 변경 배열이 하던걸 비트로 컨트롤하기 
//   최종 교재 소스를 반영함  #1
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


#include<stdio.h>

#define INF 987654321

int table[21][21];
int n;
int min_sum=INF;
//int check[21];

static int func_count;
int DT[1<<21];

int min(int a, int b)
{
	return a > b ? b : a;
}

int f(int k, int bit)    // k 는 row
{
 
 if(DT[bit]==0)
 {	 
	  if(k==n+1)
	  {
		return 0;
	  }
	  
	  DT[bit]=INF;
	  for(int i=1; i<=n; i++)
	  {  
		  if( (bit & 1 << i ) ==0)
		  {
			 DT[bit] = min ( DT[bit], f(k+1, bit+(1<<i))+table[k][i] ); // 현재 노드에서 후보군들 사이에서 제일 작은 값을 올림.
		  } 
	  }
 }
 
   return DT[bit];	
}


void main()
{

freopen("input.txt","r",stdin);
scanf("%d",&n);

for(int i=1; i<=n ; i++)
{
	for(int j=1;j<=n;j++)
	scanf("%d", &table[i][j]);
}

int bit=0;  // 기존 checked[] 배열 상태를 DT 테이블을 작성할 수 있다. 좋은 아이디어!7

printf("sum:%d\n",f(1,bit));
printf("func_count:%d\n",func_count );
}





// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//   배열이 하던걸 비트로 컨트롤하기 
//   최종 교재 소스 
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
/*
3
1 2 5
2 4 3
5 4 3
-> 7
func count : 13 번 호출

*/

#include<stdio.h>
#define INF 987654321

int m[21][21], n;
int DT[1<<20];

void input()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
	scanf("%d", &m[i][j]);
}

int min(int a, int b) { return a>b ? b:a;}

int f(int row, int bit)
{
	if(row==n) return 0;
	if(DT[bit]==0)   // DT 테이블에 값이 없다면 ...
		             // bit 안에 기존 사용했던 checked 배열의 정보가  다 들어 있음,  
	{
		DT[bit]=INF;
		for(int i=0; i<n; i++)
		if((bit&(1<<i))==0) DT[bit]=min(DT[bit], f(row+1,bit+(1<<i))+ m[row][i]);  
	}
	else
	{
		printf("hit!\n");
	}
	return DT[bit]; 
}

int main()
{
	freopen("input.txt","r",stdin);
	input();
	printf("%d", f(0,0));
	return 0;
}
