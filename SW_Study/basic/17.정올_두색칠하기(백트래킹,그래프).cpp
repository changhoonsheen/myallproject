/*
기존형식과는 다른 문제이다.
결정 문제로 정말 좋은 문제이다. 
트리를 그려보고 함수를 정의해보자.(어떻게 경우의 수가 나눠지는지) 



//두 색 칠하기 (bicoloring)

입력
첫째 줄에는 정점의 개수 n(1 ≤ n ≤ 200)과 간선의 수 m이 입력된다.
둘째 줄부터 m줄에 걸쳐서 각 간선이 연결하는 정점의 번호가 공백으로 구분되어
입력된다.

출력
입력된 그래프가 두 색으로 칠할 수 있는 그래프인지를 판단하고 아래 예에 나온
형식에 맞게 결과를 출력하라.

3
3
0 1
1 2
2 0

-> Impossible


9
8
0 1
0 2
0 3
0 4
0 5
0 6
0 7
0 8

-> OK


impossible
5 
5
0 1 
0 2
0 3
0 4
1 4

possible
4
4
0 1
0 2
1 3
2 3


impossible
4
5
0 1
0 2
1 3
2 3
1 2
*/



//창훈 최종필기
//교재하고는 다른 접근 잘 풀었음




#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define SIZE 10

#define RED 1
#define BLACK 2

int E;
int V;

int map[SIZE][SIZE];
int check[SIZE];



void input()
{
	freopen("input.txt","r",stdin);

	scanf("%d",&V);
	scanf("%d",&E);

	for(int i=0;i<E;i++)
	{
		int a;
		int b;
		scanf("%d %d",&a,&b);
		map[a][b]=map[b][a]=1;
	}

}

int impossilbe;

void f(int v, int c)
{
	//printf("v:%d c:%d\n",v,c);

	if(impossilbe==1) return;  //중요!! impossible임으로 더 이상 볼 필요없다. 더 이상 그래프를 탐색할 필요가 없다.

	for(int i=0;i<V;i++)
	{
		if(map[v][i] && check[i]==c) impossilbe=1;
	}

	for(int i=0;i<V;i++)
	{
		if(map[v][i] && !check[i])
		{
			if(c==RED)
			{
				check[i]=BLACK;
				f(i,BLACK);
			}
			else
			{
				check[i]=RED;
				f(i,RED);
			}
		}
	}

}

void main()
{
	input();

	check[0]=RED; 
	f(0,RED);

	if(impossilbe==1) printf("IMPOSSIBLE\n");
	else  printf("POSSIBLE\n");
}






























#include<stdio.h>

int arr[10][10];
int checked[10];
int n;
int e;

//
#define R 1
#define B 2

int impossilbeFlag;

void solve(int v,int c)
{
	printf(" v : %d \n",v);
	for(int i=0;i<n;i++)
	{
		if(arr[v][i]) //연결 노드를 확인하고
		{
			if(checked[i]==c){ /*printf("impossilbe\n");*/impossilbeFlag=1;}
			//인근 연결노드중 같은 색깔이 있다면 
		}
	}


	for(int i=0;i<n;i++)
	{
		if(checked[i]==0 && arr[v][i])
		{
			//현재 색상을 보고 토글함.
			if(c==R)
			{
				checked[i]=B;
				solve(i,B);
			}
			else
			{
				checked[i]=R;
				solve(i,R);
			}

		}
	}
}


void main()
{
	freopen("input.txt","r",stdin);
	
	scanf("%d",&n);
	scanf("%d",&e);
	
	for(int i=0;i<e;i++)
	{
		int a;
		int b;
		
		scanf("%d %d",&a,&b);
		arr[a][b]=arr[b][a]=1;
	}	

	checked[0]=R;
	solve(0,R);

	if(impossilbeFlag==1) printf("impossilbe\n");
	else printf("possible\n");
}
















//아래껀 보지 말도록 
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//////////////////////////////////////////////////////////////////////



>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#include<stdio.h>

int n,m,G[200][200],visited[200];

void solve(int v,int c) // 현재 정점 V를 C로 칠한다/
{
  visited[v]=c;
  int can=1;
  int i;
  
  for(i=0;i<n;i++)
  if(G[v][i] && visited[i]==c) can=0;  // 연결 노드중 같은 색이 있다면 끝 
  
  if(!can)
  {
	printf("cannot -- v:%d - c:%d \n",v,c);
    visited[v]=0;
	return;
  }
  
  for(i=0;i<n;i++)
  {
    if(!visited[i] && G[v][i]) // 후보군의 경우의 수가 있다.
	{
	  solve(i,1);  // red 1을 칠해본다.
	  solve(i,2);  // black 2을 칠해본다.
	}
  }
}

void main()
{
  freopen("input.txt","r",stdin);
  int i;

  scanf("%d %d",&n,&m);
  for(i=0;i<m;i++)
  {
    int s,e;
	scanf("%d %d",&s,&e);
	G[s][e]=G[e][s]=1;
  }
  
  solve(0,1);


  for(i=0; i<n ; i++)
  {
	 printf("%d ",visited[i]);
  }
  
  for(i=0; i<n ; i++)
  {
    if(visited[i]==0)  // 방문하지 않는 정점이 하나라도 있다면.
	{
	  printf("IMPOSSIBLE\n");
	  
	  return;
	}
  }
  
  printf("OK\n");
  
  return;
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// 최종 창훈 접근 , 못품. 좋은 문제.
// DFS/BFS로 모든 정점을 방문한다.
// 자식 정점으로 방문할때 경우의 수가 두개가 된다.1번 컬러 2번 컬러.

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


#include<stdio.h>

int map[200][200];
int n;
int m;

int chk[200];

void input()
{

	freopen("input.txt", "r", stdin);
	
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=0;i<=n;i++)
	{
	    int a;
		int b;
		scanf("%d %d",&a,&b);
		map[a][b]=map[b][a]=1;
	}		
}


void solve(int k,int c)
{
	
	chk[k]=c; //color가 들어 있음.
	int can=1;

	for(int i=0;i<n;i++)
	{
		if( map[k][i] && chk[i]==c ) can=-1;  // 조건 위반 
	}
	
	if(can==-1) { chk[k]=0; return; } // 이 조건의 바닥까지와서는 해당 정점을 색칠을 못하고 (방문하지 못하고)
                                      // 올려 보낸다. 	여기서 바닥 처리해야함.
	
	for(int i=0;i<n;i++)
	{
		if(!chk[i] && map[k][i])  // 재방문 없이 한번씩 방문하는 DFS 탐색이다. 원리를 생각하고 그림을 그려보자.
		{	
		 solve(i,1); //모든 후보군은 또한 두가지 경우의 수가 있다.
		 solve(i,2);
		}
	}
	
}

void main()
{
	input();
	
	solve(0,1); // 최종적으로 방문하지 못한 정점이 있으며 impossible이다.
	
	for(int i=0;i<n;i++)
	{
		printf(" %d",chk[i]);
	}
	printf("\n");
	
	for(int i=0;i<n;i++)
	{
		if(chk[i]==0) {  printf("Impossible\n"); return;}
	}
	printf("\n");
	
	printf("OK");
}


//>>>>>>>>>>>>>>
// 다른 버젼 
//>>>>>>>>>>>>>>


#include<stdio.h>

int map[200][200];
int n;
int m;

int chk[200];

void input()
{

	freopen("input.txt", "r", stdin);
	
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=0;i<=n;i++)
	{
	    int a;
		int b;
		scanf("%d %d",&a,&b);
		map[a][b]=map[b][a]=1;
	}		
}


void solve(int k)  // 인자를 컬러를 안넘겻을때 
{
	
	int can=1;

	for(int i=0;i<n;i++)
	{
		if( map[k][i] && chk[i]==chk[k] ) can=-1;  // 조건 위반 k를 Set한 상태이기 때문에 조건위반을 체크한다.
	}
	
	if(can==-1) { chk[k]=0; return; } // 이 조건의 바닥까지와서는 해당 정점을 색칠을 못하고 
                                              // 올려 보낸다. 	백트랙한다.
	
	for(int i=0;i<n;i++)
	{
		if(!chk[i] && map[k][i])  // 재방문 없이 한번씩 방문하는 DFS 탐색이다. 원리를 생각하고 그림을 그려보자.
		{	
         chk[i]=1;  //이런경우에 흔적 지우기처럼 문제가된다.!
		 solve(i);  //모든 후보군은 또한 두가지 경우의 수가 있다. 그리고 스텍 버젼 만들 잘 생각 해보자, 
		            //이 함수버젼에슨 chk[i]=1은 solve 함수가 빠져 나올때까지 chk[i]=1가 유지 되고 있다. 함수 스텍에 의해서 유지가 된다는 뜻.
		            //스텍 버젼 만들땐 이 값을 스택에 넣어서 유지해야한다.
	
		 chk[i]=2; //이런경우에 스택을 만들때 흔적 지우기처럼 문제가된다.! 보호가 안된다. DFS 처럼 깔끔하게 한번에 하나씩 엑세스되는것은 문제가 없다.
		 solve(i);
		}
	}
	
}

void main()
{
	input();
	
	chk[0]=1; //color가 들어 있음.
	solve(0); // 최종적으로 방문하지 못한 정점이 있으며 impossible이다.
	
	for(int i=0;i<n;i++)
	{
		printf(" %d",chk[i]);
	}
	printf("\n");
	
	for(int i=0;i<n;i++)
	{
		if(chk[i]==0) {  printf("Impossible\n"); return;}
	}
	printf("\n");
	
	printf("OK");
}


//DFS Stack version OK

#include<stdio.h>

int map[200][200];
int n;
int m;

int chk[200];

struct Node
{
	int k;
	int c;
};

Node node[20000];
int top=-1;

void input()
{

	freopen("input.txt", "r", stdin);
	
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=0;i<=n;i++)
	{
	    int a;
		int b;
		scanf("%d %d",&a,&b);
		map[a][b]=map[b][a]=1;
	}		
}


void solve(int k,int c)
{
	
	top++;
	node[top].k=k;
	node[top].c=c;
		
	while(top!=-1)
	{

		int new_k =node[top].k;
	    int new_c =node[top].c;
		top--;

		chk[new_k]=new_c; //color가 들어 있음.

		printf("top:%d  k:%d  c:%d\n",top,new_k,new_c);
		
		int can=1;

		for(int i=0;i<n;i++)
		{
			if( map[new_k][i] && chk[i]==new_c ) can=-1;  // 조건 위반 
		}
		
		if(can==-1) { chk[new_k]=0;  continue; } // 이 조건의 바닥까지와서는 해당 정점을 색칠을 못하고 (방문하지 못하고)
										                    // 올려 보낸다. 	
		
		for(int i=0;i<n;i++)
		{
			if(!chk[i] && map[new_k][i])  // 재방문 없이 한번씩 방문하는 DFS 탐색이다. 원리를 생각하고 그림을 그려보자.
			{	

				top++;
				node[top].k=i;
				node[top].c=2;

				top++;
				node[top].k=i;
				node[top].c=1;
			}
		}
	}
	
}

void main()
{
	input();
	
	solve(0,1); // 최종적으로 방문하지 못한 정점이 있으며 impossible이다.
	
	for(int i=0;i<n;i++)
	{
		printf(" %d",chk[i]);
	}
	printf("\n");
	
	for(int i=0;i<n;i++)
	{
		if(chk[i]==0) {  printf("Impossible\n"); return;}
	}
	printf("\n");
	
	printf("OK");
}