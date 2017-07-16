/*
다이젝트라 알고리즘 이때까지 잘못 알고 있었다.
*/

연구할동 가는길
정올이는 GSHS에서 연구활동 교수님을 뵈러 A대학교를 가려고 한다. 
출발점과 도착점을 포함하여 경유하는 지역 n개, 
한 지역에서 다른 지역으로 가는 방법이 총 m 개이며 GSHS는 지역 1이고 
A대학교는 지역 n이라고 할 때 대학까지 최소 비용을 구하시오.

단, n은 10 이하, m은 30 이하, 그리고 한 지역에서 다른 지역으로 가는 
데에 필요한 비용은 모두 200 이하 양의 정수이며 
한 지역에서 
다른 지역으로 가는 어떠한 방법이 존재하면 같은 방법과 
비용을 통해 역방향으로 갈 수 있다.

다음 그래프는 예를 보여준다.(
단, 정점a->정점b로의 간선이 여러 개 있을 수 있으
며, 자기 자신으로 가는 정점을 가질 수도 있다.)
최소 비용이 드는 경로 : 1→3→5→7, 최소 비용 : 69+59+21=149
입력
첫 번째 줄에는 정점의 수 n과 간선의 수 m이 공백으로 구분되어 입력된다. 
다음
줄부터 m개의 줄에 걸쳐서 두 정점의 번호와 가중치가 입력된다. (
자기 간선, 멀티
간선이 있을 수 있다.)

출력
대학까지 가는 데 드는 최소 비용을 출력한다. 만약 갈 수 없다면 “-1”을 출력.


7 11
1 2 47
1 3 69
2 4 57
2 5 124
3 4 37
3 5 59
3 6 86
4 6 27
4 7 94
5 7 21
6 7 40



7 8
1 2 47
1 3 69
2 4 57
2 5 124
3 4 37
3 5 59
3 6 86
4 6 27

답 : 무한대 

8 8
1 2 2
1 3 2 
1 4 1
4 8 1
2 5 3 
2 6 4
5 7 5 
6 7 6


>>>>>>>>>>>>>>>>
#include<stdio.h>

int G;
int E;

int weight=0xffffff;
int map[100][100];
int check[100];

void solve(int g, int w)
{
	if(g==G) // 어떻게든 돌다가 끝까지 왔다면.
	{
		if( weight > w )  weight=w;
		return;
	}
	
	for(int i=1;i<=E;i++)
	{
	  if(check[i]==0 && map[g][i])
	  {
		  check[i]=1;
		  solve(i,w+ map[g][i]);
		  check[i]=0; // 흔적 지우기 
	  }
	}	

}

void main()
{

freopen("input.txt", "r", stdin);
setbuf(stdout, NULL);

scanf("%d %d",&G,&E);

for(int i=1;i<=E;i++)
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	map[a][b]=map[b][a]=c;
}	

solve(1,0); // 1번 도시부터 자기자신이니깐 w가 없다.
printf("%d",weight);
}


//////////////////////////
// 다이젝트라 
//////////////////////////

#include<stdio.h>


#define INF 987654321
int N;
int E;
int adj[10][10];

/*
7 11
1 2 47
1 3 69
2 4 57
2 5 124
3 4 37
3 5 59
3 6 86
4 6 27
4 7 94
5 7 21
6 7 40

//
0 47 69 104 128 131 149
*/

/*

7 8
1 2 47
1 3 69
2 4 57
2 5 124
3 4 37
3 5 59
3 6 86
4 6 27

//0 47 69 104 128 131 987654321
*/

int MIN_DIST = INF;

int DIST[10];
int check[10];

int isitpossible()
{
	for (int i = 1; i <= N; i++)
	{
		if (check[i] == 0) return 1;
	}

	return 0;
}


// 이 부분 이때까지 실수했다. 꼭 다시한번 보도록 
int getBestNode()
{
	int node;
	int weight = -1;// 사용되지 않는 값으로 조건을 건다.

	for (int i = 1; i <= N; i++)
	{
		if (check[i] == 0)
		{		
			if (weight == -1) // 처음 선택한 경우이다. 이걸로 최초 초기화함.
			{
				weight = DIST[i];
				node = i;
			}
			else
			{
				if (weight > DIST[i]){
					weight = DIST[i];
					node = i;
				}
			}
		}
	}

	return node;
}



void solve()
{


	for (int i = 1; i <= N; i++)
	{
		DIST[i] = adj[1][i];
	}


	check[1] = 1;  // DIST  배열을 복사함과 동시에 체크한다. 시작 정점을 체크한다.

	while (isitpossible())
	{
		int w = getBestNode();
		check[w] = 1;

		
		for (int i = 1; i <= N; i++)
		{
			printf("%d ", DIST[i]);
		}
		printf("\n");
	

		printf("w: %d \n", w);

		for (int v = 1; v <= N; v++)
		{
			if (DIST[v] > DIST[w] + adj[w][v])
			{
				DIST[v] = DIST[w] + adj[w][v];
			}
		}
	}
}


void input()
{
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &E);


	for (int i = 1; i <= N; i++)
	for (int j = 1; j <= N; j++)
	{
		if (i == j) adj[i][j] = 0;
		else
		{
			adj[i][j] = INF;
		}

	}


	for (int i = 1; i <= E; i++)
	{
		int a;
		int b;
		int c;

		scanf("%d %d %d", &a, &b, &c);
		adj[a][b] = adj[b][a] = c;
	}


}

void main(void)
{
	input();
	
	solve();

	printf("-------------------------\n");
	for (int i = 1; i <= N; i++)
	{
		printf("%d ", DIST[i]);
	}
}


//
//모든쌍 최단거리 알고리즘 
//

/*
7 11
1 2 47
1 3 69
2 4 57
2 5 124
3 4 37
3 5 59
3 6 86
4 6 27
4 7 94
5 7 21
*/

//모든쌍 최단경로 알고리즘, 그리고 경로 표시하기 

#include<stdio.h>

#define INF 0xFFFFF

int V;
int E;

int MAP[10][10];
int PATH[10][10];


void input()
{
	scanf("%d %d", &V, &E);

	for (int i = 1; i <= V; i++)
	for (int j = 1; j <= V; j++)
	{
		if (i == j) MAP[i][j] = 0;
		else MAP[i][j] = INF;
	}


	for (int i = 1; i <= E; i++)
	{
		int a;
		int b;
		int c;

		scanf("%d %d %d", &a, &b, &c);
		MAP[a][b] = MAP[b][a] = c;
	}

}

void printf_allPath(int start, int end)
{
	if (PATH[start][end] != 0)
	{
		printf_allPath(start, PATH[start][end]);
		printf(" %d ->", PATH[start][end]);
		printf_allPath(PATH[start][end], end);
	}
}



void main(void)
{
	freopen("input.txt", "r", stdin);
	input();

	for (int k = 1; k <= V; k++)
		for (int i = 1; i <= V; i++)
		{
			if (i != k)	
			{
				for (int j = 1; j <= V; j++)
				{
					if (j != k && i != k)
					{
						if (MAP[i][j] > MAP[i][k] + MAP[k][j])
						{
							MAP[i][j] = MAP[i][k] + MAP[k][j];
							PATH[i][j] = k;
						}
					}
				}

			}
		}

//
	int start = 1;
	int end = 7;

	if (MAP[start][end]!=INF)
	{
		printf("distance :%d \n", MAP[start][end]);

		printf("%d -> ", start);

		printf_allPath(start, end);

		printf("%d \n ", end);

	}
	else
	{
		printf("start:%d ~ end:%d  No Path\n", start, end);
	}



}


















//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//DFS Stack
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


#include<stdio.h>

int n; //정점 
int m; //간선
int map[10][10];
int min_cost=0x7fffffff;

struct Node
{
	int v;
	int w;
	int chk;  //check 배열을 내부에 넣을경우 
};

Node node[100000];
int top=-1;

void solve(int v, int w)
{
 top++;
 node[top].v=v;
 node[top].w=w;

 while(top!=-1)
 {
	 int new_v  =node[top].v;
     int new_w  =node[top].w;
	 int new_chk=node[top].chk;  //여기서 내가 남긴 흔적도 끄집어 내줘야한다.!!
	 top--;

	 if(new_v==n)
	 {
		if(min_cost > new_w) min_cost=new_w;
		continue;
	 }

	 for(int i=1;i<=n;i++)
	 {
		//if(!checked[i] && map[v][i])
		 if( (new_chk & (1<<i))==0 && map[new_v][i] )
		{
		  new_chk+=(1<<i); // 헷갈림!! 스텍을 만들어서 사용하면 흔적을 가지고 내려가고 올라올대 복원해야된다..!! 실수 
		
		  //solve(i,  w+map[v][i]);
		  top++;
  		  node[top].v=i;
		  node[top].w=new_w+map[new_v][i];
		  node[top].chk=new_chk;

		  new_chk-=(1<<i);  // 헷갈림!! 스텍을 만들어서 사용하면 흔적을 가지고 내려가고 올라올대 복원해야된다..!! 실수 

		}
	 }
 }
}

void input()
{
 scanf("%d %d",&n,&m);

 for(int i=0;i<m;i++)
 {
  int a;
  int b;
  int w;
  scanf("%d %d %d", &a,&b,&w);
  map[a][b]=map[b][a]=w;
 }
 
}


void main()
{
	freopen("input.txt","r",stdin);
	input();
	solve(1, 0);
	printf("%d",min_cost);
}


//BFS 

#include<stdio.h>

int n; //정점 
int m; //간선
int map[10][10];
int min_cost=0x7fffffff;

struct Node
{
	int v;
	int w;
	int chk;
};

Node node[100000];
int f=-1;
int r=-1;

void solve(int v, int w)
{
 r++;
 node[r].v=v;
 node[r].w=w;

 while(f!=r)
 {
	 f++;
	 int new_v  =node[f].v;
     int new_w  =node[f].w;
	 int new_chk=node[f].chk;
	
	 if(new_v==n)
	 {
		if(min_cost > new_w) min_cost=new_w;
		continue;
	 }

	 for(int i=1;i<=n;i++)
	 {
		//if(!checked[i] && map[v][i])
		 if( (new_chk & (1<<i))==0 && map[new_v][i] )
		{
		  new_chk+=(1<<i); // 방문한 노드 체크 
		
		  //solve(i,  w+map[v][i]);
		  r++;
  		  node[r].v=i;
		  node[r].w=new_w+map[new_v][i];
		  node[r].chk=new_chk;  // 저장하고 

		  new_chk-=(1<<i);  // 원래대로 돌려 놓기!

		}
	 }
 }
}

void input()
{
 scanf("%d %d",&n,&m);

 for(int i=0;i<m;i++)
 {
  int a;
  int b;
  int w;
  scanf("%d %d %d", &a,&b,&w);
  map[a][b]=map[b][a]=w;
 }
 
}


void main()
{
	freopen("input.txt","r",stdin);
	input();
	solve(1, 0);
	printf("%d",min_cost);
}


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//다이젝트라를 이용해서 지나온 경로 표시해보기 


#include<stdio.h>


#define INF 987654321
int N;
int E;
int adj[10][10];

int index[10];

/*
7 11
1 2 47
1 3 69
2 4 57
2 5 124
3 4 37
3 5 59
3 6 86
4 6 27
4 7 94
5 7 21
6 7 40

//
0 47 69 104 128 131 149
*/

/*

7 8
1 2 47
1 3 69
2 4 57
2 5 124
3 4 37
3 5 59
3 6 86
4 6 27

//0 47 69 104 128 131 987654321
*/

int MIN_DIST = INF;

int DIST[10];
int check[10];

int isitpossible()
{
	for (int i = 1; i <= N; i++)
	{
		if (check[i] == 0) return 1;
	}

	return 0;
}


// 이 부분 이때까지 실수했다. 꼭 다시한번 보도록 
int getBestNode()
{
	int node;
	int weight = -1;// 사용되지 않는 값으로 조건을 건다.

	for (int i = 1; i <= N; i++)
	{
		if (check[i] == 0)
		{
			if (weight == -1) // 처음 선택한 경우이다. 이걸로 최초 초기화함.
			{
				weight = DIST[i];
				node = i;
			}
			else
			{
				if (weight > DIST[i]){
					weight = DIST[i];
					node = i;
				}
			}
		}
	}

	return node;
}



void solve()
{


	for (int i = 1; i <= N; i++)
	{
		DIST[i] = adj[1][i];
	}


	check[1] = 1;  // DIST  배열을 복사함과 동시에 체크한다. 시작 정점을 체크한다.

	while (isitpossible())
	{
		int w = getBestNode();
		check[w] = 1;

		/*
		for (int i = 1; i <= N; i++)
		{
			printf("%d ", DIST[i]);
		}
		printf("\n");
		*/

		printf("w: %d \n", w);

		for (int v = 1; v <= N; v++)
		{
			if (DIST[v] > DIST[w] + adj[w][v])
			{
				DIST[v] = DIST[w] + adj[w][v];
				index[v] = w;  // 현재 갱신되는 V정점은 W를 통해서 들어 왔다.!
			}
		}
	}
}


void input()
{
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &E);


	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			if (i == j) adj[i][j] = 0;
			else
			{
				adj[i][j] = INF;
			}

		}


	for (int i = 1; i <= E; i++)
	{
		int a;
		int b;
		int c;

		scanf("%d %d %d", &a, &b, &c);
		adj[a][b] = adj[b][a] = c;
	}


}

void main(void)
{
	input();
	solve();

	for (int i = 1; i <= N; i++)
	{
		printf("%d ", DIST[i]);
	}

	printf("\n-------------------------\n");

	int p = 0;
	for (int v = 1; v <= N; v++)
	{

		p = v;
		printf(" %d : %d ", DIST[v],v);

		if (DIST[v] == INF)
		{
			printf("No path\n");
			continue;
		}

		while (index[p] != 0)
		{
			printf("<--- %d", index[p]);
			p = index[p];
		}

		printf(" <--- 1");

		printf("\n");
	}


}







