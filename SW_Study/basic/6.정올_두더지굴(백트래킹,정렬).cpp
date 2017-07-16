//창훈 최종 필기
//이런 문제의 풀이 방법은 
// 1.재귀방법
// 2.스텍
// 3.큐
// 가 있다. 모두 동일하게 풀수 있고, 깊이가 너무 크다고 생각되면
// 2번 3번으로 풀이한다.





/*
7
0 1 1 0 1 0 0
0 1 1 0 1 0 1
1 1 1 0 1 0 1
0 0 0 0 1 1 1
0 1 0 0 0 0 0
0 1 1 1 1 1 0
0 1 1 1 0 0 0
*/

#include<stdio.h>

int N;
int MAP[30][30];

int dx[] = {-1,0,1,0};
int dy[] = { 0,1,0,-1};


void input()
{
	freopen("input.txt", "r", stdin);

	scanf("%d",&N);

	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
		{
			scanf("%d", &MAP[x][y]);
		}
	}
}

int result[1000];

void dfs(int x, int y , int count)
{
	MAP[x][y] = count;

	for (int i = 0; i < 4; i++)
	{
		int new_x = x + dx[i];
		int new_y = y + dy[i];

		if (MAP[new_x][new_y] == 1 &&
			(new_x >= 0 && new_x < N  && new_y >= 0 && new_y < N)
			)
		{
			dfs(new_x, new_y, count);
		}
	}
}


void sort(int SIZE)
{

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = i + 1; j < SIZE; j++)
		{
			if (result[i] < result[j])
			{
				int temp = result[i];
				result[i] = result[j];
				result[j] = temp;
			}
		}
	}
}

void solve()
{
	int count = 1;
	int real_coount = 0;


	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
		{
			
			if (MAP[x][y] == 1)
			{	
				count++;
				dfs(x,y,count);
			
			}

		}
	}



	if (count == 1)
	{
		printf("0");
	}
	else
	{
		real_coount = count - 1;

		for (int x = 0; x < N; x++)
		{
			for (int y = 0; y < N; y++)
			{
				int type=MAP[x][y];

				if (type!=0) result[type-2]++;

			}
		}

		sort(real_coount);

		printf("%d\n", real_coount);

		for (int i = 0; i < real_coount; i++)
		{
			printf("%d\n", result[i]);
		}
	}



}


void display()
{
	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
		{
			printf(" %d", MAP[x][y]);
		}

		printf("\n");
	}

	printf("\n");
}

void main()
{
	input();
	//display();
	solve();
	//display();


}











>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#include<stdio.h>

int n;
int map[30][30];

int dx[]={-1,0,1, 0};
int dy[]={ 0,1,0,-1};

struct Node
{
	int i;
	int j;
};

Node node[1000000];

int f=-1;
int r=-1;


int result[1000];


void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	scanf("%d",&map[i][j]);	
}

void bfs(int i, int j, int c)
{
	r++;
	node[r].i=i;
	node[r].j=j;

	while(f!=r)
	{
		f++;
		int new_i=node[f].i;
		int new_j=node[f].j;

		for(int k=0;k<4;k++)
		{
			if(map[new_i+dx[k]][new_j+dy[k]]==1 &&
			   (new_i+dx[k]>=0 && new_j+dy[k]>=0) &&
			   (new_i+dx[k]<n && new_i+dx[k]<n)
			  )
			{
				map[new_i+dx[k]][new_j+dy[k]]=c;
				
				r++;
				node[r].i=new_i+dx[k];
				node[r].j=new_j+dy[k];
			}
		}
	}
}

void display()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf(" %d",map[i][j]);
		}
		printf("\n");
	}

	printf("------------------\n");
}

int label=1;
void solve()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(map[i][j]==1) 
			{
				label++;
				bfs(i,j,label);
//				display();
			}
		}
}

void sort(int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(result[i]<result[j])
			{
				int temp=result[i];
				result[i]=result[j];
				result[j]=temp;
			}
		}
	}
}

void main()
{
	input();
	solve();
	
	int real_count=label-1;

	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		result[map[i][j]-2]++;
	}

	sort(real_count);  // 정렬해야한다!! 실수!!
	printf("%d\n",real_count);

	for(int i=0;i<real_count;i++)
    printf("%d\n",result[i]);
}


//두더지굴 Backtracking 반환값 버젼
#include<stdio.h>

int map[30][30];
int N;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

int color=1;
int area_arr[1000];

void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d",&N);

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			scanf("%d",&map[i][j]);
}


int getArea(int i, int j, int c)
{

	printf("i:%d j:%d k:%d \n",i,j,c);

	int area=0;

	for(int k=0;k<4;k++)
	{
		int new_i=i+dx[k];
		int new_j=j+dy[k];

		if( map[new_i][new_j]==1 &&
			new_i>=0 && new_j>=0 &&
			new_i<N  && new_j<N )
		{
			map[new_i][new_j]=c;
			area = area+getArea(new_i,new_j,c)+1;
		}
	}

	return area;
}


void f()
{
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			if(map[i][j]==1)
			{
				color++;
				map[i][j]=color;
				area_arr[color-2]=getArea(i,j,color)+1;
			}
		}
}

void main(void)
{
	input();
	f();

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			printf("%d ",map[i][j]);
		}
		printf("\n");
	}


	for(int i=0;i<color-1;i++)
	{
		for(int j=1;j<color-1;j++)
		{
			int temp;	
			if(area_arr[i] < area_arr[j])
			{
				temp=area_arr[i];
				area_arr[i] = area_arr[j];
				area_arr[j]=temp;
			}	
		}
	}

	printf("%d\n",color-1);
	for(int i=0;i<color-1;i++)
	{
	  printf("%d\n",area_arr[i]);
	}
}




























//아래껀 참조만 하기.
//이런류의 문제는 다 풀수있다. 실수하지 말자.!!
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//////////////////////////////////////////////////////////////////////////////

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
입력
7
0 1 1 0 1 0 0
0 1 1 0 1 0 1
1 1 1 0 1 0 1
0 0 0 0 1 1 1
0 1 0 0 0 0 0
0 1 1 1 1 1 0
0 1 1 1 0 0 0




 
>>>>>>>>>>>>>>>

출력 결과

 0 2 2 0 3 0 0
 0 2 2 0 3 0 3
 2 2 2 0 3 0 3
 0 0 0 0 3 3 3
 0 4 0 0 0 0 0
 0 4 4 4 4 4 0
 0 4 4 4 0 0 0



>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// BFS를 이용한 접근방식
// Queue의 큰장점 엄청나게 큰수를 두고 작업을 할 수 있다.
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#include <stdio.h>

struct VERTEX{ int i; 
			   int j; };
//VERTEX Q[100000000]; // 큐
VERTEX Q[200000000]; // 큐   // 2억까지는 되는 걸로 보임 

int front=-1;   // 큐의 초기 위치
int rear=-1;

int n, A[101][101],Size[101];
int cnt=1; 

// 4방향에 대해서
int dx[4]={-1,0,1,0}, dy[4]={0,1,0,-1};


void input()
{	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
	scanf("%d", &A[i][j]);
}

void outputArray()
{
	freopen("output.txt", "w", stdout);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		printf(" %d", A[i][j]);
	
	printf("\n");
	}
	/*
	printf("%d\n", cnt);
	for(int i=0; i<cnt; i++)
	printf("%d\n", Size[i]);
	*/
}

void output()
{
	freopen("output.txt", "w", stdout);
	
	int itemcount = cnt-1;
	printf("%d\n", itemcount);
	for(int i=0; i<itemcount; i++)
	printf("%d\n", Size[i]);
	
}

// 1 safe, 0 nonsafe out of bound.
int safe(int i , int j)
{
	return   (0 <= i &&  i< n ) &&  (0 <= j &&  j < n )  ;    
}

void bfs(int i, int j, int c)
{
	int r=++rear;
	Q[r].i=i;  // 큐에 넣으면서 방문했다고 표시 
	Q[r].j=j;
	A[i][j]=c; // 큐에 넣은 것을 표시함.
	
	while(front != rear)  // 큐가 빌때까지 헷갈리지마라!!
	{
		int f = ++front;
	    int newi=Q[f].i;  // 큐에서 하나를 끄집어 내고 유망한 Vertex를 검사함
		int newj=Q[f].j;
	
		for(int k=0 ; k<5 ; k++) // 4방향에 대해서.
		{
			if( safe( newi+dx[k] , newj+dy[k] ) && 
				A[newi+dx[k]][newj+dy[k]] == 1 ) // 이제 이 방법을 사용함.
				{
					int r=++rear;
					Q[r].i=newi+dx[k];
					Q[r].j=newj+dy[k];
					A[newi+dx[k]][newj+dy[k]]=c;
				}
		}	
	}

}


void solve()
{
	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
	{
	    if(A[i][j]==1)
		{
			cnt++;
			bfs(i,j,cnt);
		}
	}
	
	
	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
	{
		if(A[i][j]!=0)
		{
			Size[A[i][j]-2]++;  // 0 인덱스 부터 값을 채운다.
		}
	}
	
	int itemcount = cnt-1;
	for(int i=0; i< itemcount ; i++ )
	{	
		for(int j=i+1; j < itemcount ; j++)
		{
			if(Size[i] < Size[j])
			{
				int temp;	
				temp=Size[i];
				Size[i]=Size[j];
				Size[j]=temp;
			}
		}
	}
	
	
}

void main()
{
input();
solve();
output();
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// 위에껀 교재 기반이고 아래껀 내가 푼것임.
// 중요한 결론이다!  BFS,DFS(Stack,function) 모두 Tree,graph 탐색이 가능하다. 알고리즘에 맞게 사용하면 되는거다.
// 아래 풀이가 증명이다.
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


////////////////////////////////////////////
//두더지 문제 최종 접근 
////////////////////////////////////////////

7
0 1 1 0 1 0 0
0 1 1 0 1 0 1
1 1 1 0 1 0 1
0 0 0 0 1 1 1
0 1 0 0 0 0 0
0 1 1 1 1 1 0
0 1 1 1 0 0 0

// BFS(Queue),DFS(스텍/함수콜)  
// 위의 세 방식으로 모두 가능하다.


//BFS
#include<stdio.h>

struct Cord
{
	int i;
	int j;
};

int map[30][30];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int N;
int count=2;

Cord Q[10000];
int f=-1;
int r=-1;


int result[100];


int check(int i, int j)
{
	return  ( 0 <= i && i < N ) && ( 0 <= j && j < N );	
}


void input()
{
	freopen("input.txt", "r", stdin);
	
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			scanf("%d",&map[i][j]);
		}			
}


void BFS(int i, int j)
{
	
	map[i][j]=count;
	r++;  //증가 위치 값 주의 
	Q[r].i=i;
	Q[r].j=j;
	
	while(f!=r)
	{
	   f++; // 증가 위치 값 주의 
	   int new_i = Q[f].i;
	   int new_j = Q[f].j;
		
	   for(int k=0;k<4;k++)	
		if( map[new_i+dx[k]][new_j+dy[k]]==1 &&
            check(new_i+dx[k] , new_j+dy[k])		
		  )
		  {
			map[new_i+dx[k]][new_j+dy[k]]=count;
			r++;
			Q[r].i=new_i+dx[k]; //실수 주의! 
			Q[r].j=new_j+dy[k]; //실수 주의!   
		  }			
	}	
}


void solve()
{
	for(int i=0;i<N;i++)
	{	
		for(int j=0;j<N;j++)
		{
			if(map[i][j]==1) 
			{	
		      BFS(i,j);
			  count++;  // 컬러 증가 
			  f=-1;     // 큐 초기화
			  r=-1;
			}
		}	
	}	
}

void display()
{
	for(int i=0;i<N;i++)
	{	
		for(int j=0;j<N;j++)
		{
		 printf(" %d",map[i][j]);
		}	
		printf("\n");
	}	
}

void countArea()
{
	for(int i=0;i<N;i++)
	{	
		for(int j=0;j<N;j++)
		{
			if(map[i][j]!=0) result[map[i][j]]++;
		}
	}
}

void sort()
{
	for(int i=0;i<=count;i++)
	for(int j=i+1;j<=count-1;j++)
	{
		if(result[i] < result[j])
		{
			int temp=result[i];
			result[i]=result[j];
			result[j]=temp;
		}
	}
	
}

void main()
{
	input();
	solve();
	//display();
	countArea();
	sort();
	
	int dodugi=count-2; // 탐색 나올때 한번더 증가함. 
	printf("%d\n",dodugi);
	for(int i=0 ; i<dodugi ; i++ )
	{
	 printf("%d\n",result[i]);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////
// DFS Stack
////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>

struct Cord
{
	int i;
	int j;
};

int map[30][30];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int N;
int count=2;

Cord stack[10000];
int top=-1;


int result[100];


int check(int i, int j)
{
	return  ( 0 <= i && i < N ) && ( 0 <= j && j < N );	
}


void input()
{
	freopen("input.txt", "r", stdin);
	
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			scanf("%d",&map[i][j]);
		}			
}


void DFS(int i, int j)
{
	
	map[i][j]=count;
	top++;  //증가 위치 값 주의 
	stack[top].i=i;
	stack[top].j=j;
	
	while(top!=-1)  //여기 주의 
	{	
	   int new_i = stack[top].i;
	   int new_j = stack[top].j;
	   top--;	
		
	   for(int k=0;k<4;k++)	
		if( map[new_i+dx[k]][new_j+dy[k]]==1 &&  // 방문한 녀석 coloring , 이렇게 함으로 담것이 방문하지 않는다.
            check(new_i+dx[k] , new_j+dy[k])		
		  )
		  {
			map[new_i+dx[k]][new_j+dy[k]]=count;
			
			top++;  //증가 위치 값 주의 
			stack[top].i=new_i+dx[k]; //실수 주의! 
			stack[top].j=new_j+dy[k]; //실수 주의!   
		  }			
	}	
}


void solve()
{
	for(int i=0;i<N;i++)
	{	
		for(int j=0;j<N;j++)
		{
			if(map[i][j]==1) 
			{	
		      DFS(i,j);
			  count++;  // 컬러 증가 
			  top=-1;  //위치 초기화
			}
		}	
	}	
}

void display()
{
	for(int i=0;i<N;i++)
	{	
		for(int j=0;j<N;j++)
		{
		 printf(" %d",map[i][j]);
		}	
		printf("\n");
	}	
}

void countArea()
{
	for(int i=0;i<N;i++)
	{	
		for(int j=0;j<N;j++)
		{
			if(map[i][j]!=0) result[map[i][j]]++;
		}
	}
}

void sort()
{
	for(int i=0;i<=count;i++)
	for(int j=i+1;j<=count-1;j++)
	{
		if(result[i] < result[j])
		{
			int temp=result[i];
			result[i]=result[j];
			result[j]=temp;
		}
	}
	
}

void main()
{
	input();
	solve();
	//display();
	countArea();
	sort();
	
	int dodugi=count-2; // 탐색 나올때 한번더 증가함. 
	printf("%d\n",dodugi);
	for(int i=0 ; i<dodugi ; i++ )
	{
	 printf("%d\n",result[i]);
	}
}


////////////////////////////////////////////////////////////////////////////////////////////
// DFS function call
////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

struct Cord
{
	int i;
	int j;
};

int map[30][30];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int N;
int count=2;

Cord stack[10000];
int top=-1;


int result[100];


int check(int i, int j)
{
	return  ( 0 <= i && i < N ) && ( 0 <= j && j < N );	
}


void input()
{
	freopen("input.txt", "r", stdin);
	
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			scanf("%d",&map[i][j]);
		}			
}


void DFS(int i, int j)
{

	int new_i=i;
	int new_j=j;
		
	   for(int k=0;k<4;k++)	
		if( map[new_i+dx[k]][new_j+dy[k]]==1 &&  // 방문한 녀석 coloring , 이렇게 함으로 담것이 방문하지 않는다.
            check(new_i+dx[k] , new_j+dy[k])		
		  )
		  {
			map[new_i+dx[k]][new_j+dy[k]]=count;
			DFS(new_i+dx[k], new_j+dy[k]);
		  }			
}


void solve()
{
	for(int i=0;i<N;i++)
	{	
		for(int j=0;j<N;j++)
		{
			if(map[i][j]==1) 
			{
			  map[i][j]=count;	//함수방식 DFS는 이렇게 되야됨  시작점에 대한 처리가 없음.		 
		      DFS(i,j);
			  count++;  // 컬러 증가 
			  top=-1;  //위치 초기화
			}
		}	
	}	
}

void display()
{
	for(int i=0;i<N;i++)
	{	
		for(int j=0;j<N;j++)
		{
		 printf(" %d",map[i][j]);
		}	
		printf("\n");
	}	
}

void countArea()
{
	for(int i=0;i<N;i++)
	{	
		for(int j=0;j<N;j++)
		{
			if(map[i][j]!=0) result[map[i][j]]++;
		}
	}
}

void sort()
{
	for(int i=0;i<=count;i++)
	for(int j=i+1;j<=count-1;j++)
	{
		if(result[i] < result[j])
		{
			int temp=result[i];
			result[i]=result[j];
			result[j]=temp;
		}
	}
	
}

void main()
{
	input();
	solve();
	//display();
	countArea();
	sort();
	
	int dodugi=count-2; // 탐색 나올때 한번더 증가함. 
	printf("%d\n",dodugi);
	for(int i=0 ; i<dodugi ; i++ )
	{
	 printf("%d\n",result[i]);
	}
}
