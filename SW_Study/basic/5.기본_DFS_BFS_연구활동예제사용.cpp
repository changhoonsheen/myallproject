// 창훈 최종 필기하면서 구현한 소스
// 이걸 보도록 
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
*/

//규칙을 정하자
//자료구조(Stack,Queue)에 값이 들어갈때 방문을 표시하자.(check배열에 체킹하는 순간.) 

//DFS 재귀 함수 버젼
#include<stdio.h>

#define INF 987654321

int V;
int E;

int adj[10][10];
int check[10];

int dist[10];


void input()
{
	freopen("input.txt", "r", stdin);

	scanf("%d %d", &V, &E);

	for (int i = 1; i <= E; i++)
	{
		int a;
		int b;
		int c;

		scanf("%d %d %d", &a, &b, &c);
		adj[a][b] = adj[b][a] = c;
	}
}


void dfs(int v)
{
	check[v] = 1;   // 함수 방식의 DFS는 여기서 한번만 체크한다. 
	printf("%d\n", v);


	for (int i = 1; i <= V; i++)
	{
		if (check[i] == 0 && adj[v][i])
			dfs(i);
	}
}


void main()
{
	input();

	dfs(1);

}

//DFS 스택 버젼 
////////////////////////////


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
*/

#include<stdio.h>

#define INF 987654321

int V;
int E;

int adj[10][10];
int check[10];


int stack[1000];
int top = -1;



void input()
{
	freopen("input.txt", "r", stdin);

	scanf("%d %d", &V, &E);

	for (int i = 1; i <= E; i++)
	{
		int a;
		int b;
		int c;

		scanf("%d %d %d", &a, &b, &c);
		adj[a][b] = adj[b][a] = c;
	}
}


void dfs(int v)
{
	top++;
	stack[top] = v;

	check[v] = 1;
	printf("%d\n", v);  // 1번 방법으로 처리 가능 

	while (top != -1)
	{
		int new_v = stack[top];
		top--;

		//printf("%d\n", new_v);  //2번 방법으로 여기서 한번에 가능 

		for (int i = 1; i <= V; i++)
		{ 
			if (check[i] == 0 && adj[new_v][i])
			{
				top++;
				stack[top] = i;

				check[i] = 1;
				printf("%d\n", i);  // 1번 방법으로 처리 가능 

			}
		}
	}



}




void main()
{
	input();

	dfs(1);

}



//위의 똑같은 예제 BFS 구현 

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
*/

#include<stdio.h>

#define INF 987654321

int V;
int E;

int adj[10][10];
int check[10];


int Q[1000];
int f = -1;
int r = -1;


void input()
{
	freopen("input.txt", "r", stdin);

	scanf("%d %d", &V, &E);

	for (int i = 1; i <= E; i++)
	{
		int a;
		int b;
		int c;

		scanf("%d %d %d", &a, &b, &c);
		adj[a][b] = adj[b][a] = c;
	}
}


void bfs(int v)
{
	f++;
	Q[f] = v;

	check[v] = 1;
	//printf("%d", v);  // 1번 방법으로 처리 가능 두군데에서 가능

	while (f != r)
	{
		r++;
		int new_v = Q[r];

		//printf("%d\n", new_v);  //2번 방법으로 여기서 한번에 가능 

		for (int i = 1; i <= V; i++)
		{ 
			if (check[i] == 0 && adj[new_v][i])
			{
				f++;
				Q[f] = i;

				check[i] = 1;
				//printf("%d", i);  // 1번 방법으로 처리 가능  가능 두군데에서 가능

			}
		}
	}



}




void main()
{
	input();

	bfs(1);

}
