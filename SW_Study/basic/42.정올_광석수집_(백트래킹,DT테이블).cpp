
// 창훈 최종 필기
// 이런 문제는 중복을 찾는게 중요하다. Base에 왔을때, 처리.
// 트리를 그려 봐야지 점화식을 찾을 수 있다. // 다양한 후고군 처리를 확인한다.

#include<stdio.h>

int n;
int m;

int map[200][200];
int DT[200][200];

int func_call;

int MAX(int a, int b)
{
	return a>b? a:b;
}


#if 1 //교재 방법

int solve(int x, int y)
{
	if(DT[x][y]!=-1) return DT[x][y];
	func_call++;
	
	if(n==x && m==y) return DT[x][y]=map[x][y]; //Base 도착 위치에서 자신 미네널을 올린다.  여기 중요!!! 
	else if(x>n || y>m) return DT[x][y]=0; //범위를 넘어 섰을 경우 여기 중요!!! 

	return DT[x][y] = map[x][y] + MAX(solve(x+1,y),solve(x,y+1)); //이 부분이 하이라이트
}

#else //창훈 방법 1

int solve(int x, int y)
{
	
	if(DT[x][y]!=-1) return DT[x][y];
	func_call++;
	
	if(n==x && m==y) return DT[x][y]=map[x][y]; //Base 도착 위치에서 자신 미네널을 올린다.  여기 중요!!! 
	
	int a=0;
	int b=0;
	
	if(x+1<=n) a=solve(x+1,y); //여기서 후보군 맞처 내려도된다.
	if(y+1<=m) b=solve(x,y+1);
	
	return DT[x][y]=map[x][y] + MAX(a,b);
}	


//창훈 방법 2
int solve(int x, int y)
{
	
	if(DT[x][y]!=-1) return DT[x][y];
	func_call++;
	
	if(n==x && m==y) return DT[x][y]=map[x][y]; //Base 도착 위치에서 자신 미네널을 올린다.  여기 중요!!! 
	

	int value[2]={0,};
	for(int k=0;k<2;k++)
	{
		int new_x=x+dx[k];
		int new_y=y+dy[k];

		if(new_x<=n && new_y<=m)
		{
			value[k]=solve(new_x,new_y);
		}

	}
	return DT[x][y]=map[x][y] + MAX(value[0],value[1]);
	
}	

#endif	



void input()
{
freopen("input.txt","r",stdin);
scanf("%d %d",&n,&m);

for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
		scanf("%d",&map[i][j]);
	}
}


void main()
{
	input();

	for(int i=0;i<200;i++)
		for(int j=0;j<200;j++)
		{
			DT[i][j]=-1;
		}

		printf("%d\n",solve(0,0));
		printf("func_call:%d",func_call);
}






















//아래껀 그냥 참조만해라.
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//////////////////////////////////////////////////////////////////////////


// Backtracking
// 창훈품
/*
5 4
1 1 0 0
1 0 1 100
1 1 0 0
0 0 1 0
1 0 0 1

5 4
1 1 0 0
1 0 1 1
1 1 0 0
0 0 1 0
1 0 0 1

5 4
0 1 0 0
0 0 1 0
1 1 0 0
1 0 1 0
1 1 0 0



*/


// Minelal이 1일경우
#include<stdio.h>

int map[201][201];
int xx,yy;

int dx[2]={0,1};  // 우,하 
int dy[2]={1,0};

int current;
int max;

void solve(int x, int y)
{

	if(x==xx && y==yy)
	{
		printf("bingo\n"); // 마지막 도착지에 위치했다.!!
		if(current > max) max=current;
		return;
	}	
	
	for(int i=0;i<=1;i++)
	{	
		int new_x = x+dx[i];
		int new_y = y+dy[i];
		
		if( xx < new_x || yy < new_y ) continue;  // 범의를 벗어나는 좌표는 후보군이 될 수 없다.

		if(map[new_x][new_y]==1)
		{	
		   current++;   // 획득한 자원의 흔적은 지울 필요가 있다.
		}
		
		solve(new_x,new_y);

		if(map[new_x][new_y]==1)
		{	
			current--;  // 획득한 자원의 흔적은 지울 필요가 있다.
		}	
	
	}
	
}	


void main(void)
{

	freopen("input.txt", "r", stdin);
	//freopen("output_allnight.txt", "w", stdout);

	scanf("%d %d",&xx,&yy);
	
	for(int  i=1;i<=xx;i++)
	for(int  j=1;j<=yy;j++)
	{
		scanf("%d",&map[i][j]);
	}

	if(map[1][1]==1) current++;

	solve(1,1);
	
	printf("%d",max);
}


//+++++++++++++++++
// Minelal이 가중치가 있는 경우

#include<stdio.h>

int map[201][201];
int xx,yy;

int dx[2]={0,1};  // 우,하 // 뒤돌아 오는경로가 없다. !! 좌표에 대한 흔적을 지울필요가 없다는 이야기임.
int dy[2]={1,0};

int current;
int max;

void solve(int x, int y)
{

	if(x==xx && y==yy)
	{
		printf("bingo\n"); // 마지막 도착지에 위치했다.!!
		if(current > max) max=current;
		return;
	}	
	
	for(int i=0;i<=1;i++)
	{	
		int new_x = x+dx[i];
		int new_y = y+dy[i];
		
		if( xx < new_x || yy < new_y ) continue;  // 범의를 벗어나는 좌표는 후보군이 될 수 없다.

		if(map[new_x][new_y]!=0)
		{	
		   current+=map[new_x][new_y];   // 획득한 자원의 흔적은 지울 필요가 있다.
		}
		
		solve(new_x,new_y);

		if(map[new_x][new_y]!=0)
		{	
			  current-=map[new_x][new_y];   // 획득한 자원의 흔적은 지울 필요가 있다.
		}	
	
	}
	
}	


void main(void)
{

	freopen("input.txt", "r", stdin);
	//freopen("output_allnight.txt", "w", stdout);

	scanf("%d %d",&xx,&yy);
	
	for(int  i=1;i<=xx;i++)
	for(int  j=1;j<=yy;j++)
	{
		scanf("%d",&map[i][j]);
	}

	if(map[1][1]==1) current++;

	solve(1,1);
	
	printf("%d",max);
}




//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//  DP
//  창훈 풀이  정답!
/////////////////////////////////
#include<stdio.h>

int map[201][201];
int result[201][201];

int dx[2]={-1,0};  // 좌,상  과거를 꺼내서 계산하기 위해서.
int dy[2]={0,-1};

int xx;
int yy;

int max(int a, int b)
{
	return a>b ? a:b;
}

void main(void)
{

	freopen("input.txt", "r", stdin);
	freopen("output_minelalDP.txt", "w", stdout);

	scanf("%d %d",&xx,&yy);
	
	for(int  i=1;i<=xx;i++)
	for(int  j=1;j<=yy;j++)
	{
		scanf("%d",&map[i][j]);
	}

	
	for(int  i=1;i<=xx;i++)
	for(int  j=1;j<=yy;j++)
	{
			int current_max=0;
			
			for(int k=0;k<=1;k++)
			{
			   int new_x=i+dx[k];
			   int new_y=j+dy[k];

			   if(current_max < result[new_x][new_y]+map[i][j]) current_max=result[new_x][new_y]+map[i][j];
			   // result 배열을 이용해야된다.!!!

			   
			}	
			
		result[i][j]=current_max;
			
	}

	for(int  i=1;i<=xx;i++)
	{
		for(int  j=1;j<=yy;j++)
		{
			printf("   %d",result[i][j]);
		}
		printf("\n");
	}
}


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>




////////////////////////////////////////
// 최종 DT 테이블이 가능하도록 변경 1단계.
// func_call :181





15 12
0 1 0 0 0 1 0 0 0 1 0 0
0 0 1 0 0 0 1 0 0 0 1 0
1 1 0 0 1 1 0 0 1 1 0 0
1 0 1 0 1 0 1 0 1 0 1 0
1 1 0 0 1 1 0 0 1 1 0 0
0 1 0 0 0 1 0 0 0 1 0 0
0 0 1 0 0 0 1 0 0 0 1 0
1 1 0 0 1 1 0 0 1 1 0 0
1 0 1 0 1 0 1 0 1 1 0 0
1 1 0 0 1 1 0 0 1 1 0 0
0 1 0 0 0 1 0 0 0 1 0 0
0 0 1 0 0 0 1 0 0 0 1 0
1 1 0 0 1 1 0 0 1 1 0 0
1 0 1 0 1 0 1 0 1 0 1 0
1 1 0 0 1 1 0 0 1 1 0 0

-> func_call 25852919 

////////////////////////////////////////

#include<stdio.h>

int n;
int i;

int m;
int j;

int map[200][200];

static int func_count;

void input()
{
	freopen("input.txt", "r", stdin);
	
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
		scanf("%d",&map[i][j]);
	}
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int f(int i, int j)
{
  func_count++;
  if(i==(n-1) && j==(m-1)) return map[n-1][m-1] ;
  else if( i > (n-1) || j > ( m-1 ) ) return 0;
       else return  map[i][j] + max(f(i+1,j),f(i,j+1));
}


void main()
{
	input();
	printf("%d\n",f(0,0));	
	printf("func_count:%d",func_count);
}

////////////////////////////////////////
// 최종 DT 테이블 적용
// func_call :    0 도 사용되는 값이다. 그러므로 아무것두 사용하지 않게 -1로 DT 배열을 초기화함.
// DT[i][j]!=0  -> func_call 46
// DT[i][j]!=0  -> func_call 20


15 12
0 1 0 0 0 1 0 0 0 1 0 0
0 0 1 0 0 0 1 0 0 0 1 0
1 1 0 0 1 1 0 0 1 1 0 0
1 0 1 0 1 0 1 0 1 0 1 0
1 1 0 0 1 1 0 0 1 1 0 0
0 1 0 0 0 1 0 0 0 1 0 0
0 0 1 0 0 0 1 0 0 0 1 0
1 1 0 0 1 1 0 0 1 1 0 0
1 0 1 0 1 0 1 0 1 1 0 0
1 1 0 0 1 1 0 0 1 1 0 0
0 1 0 0 0 1 0 0 0 1 0 0
0 0 1 0 0 0 1 0 0 0 1 0
1 1 0 0 1 1 0 0 1 1 0 0
1 0 1 0 1 0 1 0 1 0 1 0
1 1 0 0 1 1 0 0 1 1 0 0

-> func_call 180

////////////////////////////////////////

#include<stdio.h>

int n;
int i;

int m;
int j;

int map[200][200];
int DT[200][200];

static int func_count;

void input()
{
	freopen("input.txt", "r", stdin);
	
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
		scanf("%d",&map[i][j]);
	}
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int f(int i, int j)
{
  if(DT[i][j]!=-1) return DT[i][j];
	  
  func_count++;
  if(i==(n-1) && j==(m-1)) return DT[i][j]=map[n-1][m-1] ;
  else if( i > (n-1) || j > ( m-1 ) ) return 0;  // 여긴 DT 테이블 필요없음 인덱스가 넘어감.
       else return  DT[i][j]=map[i][j] + max(f(i+1,j),f(i,j+1));
}


void main()
{
	input();
	
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
		DT[i][j]=-1;
	}
		
	printf("%d\n",f(0,0));	
	printf("func_count:%d",func_count);
}



