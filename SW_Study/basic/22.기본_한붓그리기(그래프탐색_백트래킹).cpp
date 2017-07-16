/*
한붓 그리기 <예를 들면 집배원이 모든 경로를 돌아야될 경우, 인접행렬은 그래프의 간선수로 표현된다.>

해당 정점의 여러번 방문 유무에 상관없이
모든 경로의 path(간선)을 방문하는 모든 경로는? <한붓 그리기는 원래 출발했던 정점으로 다시 돌아 와야한다.>
이 알고리즘은 모든 경로를 다 방분한다는것이다.

한붓 그리기는 어느 위치에서 출발했는가에 따라서 여러해가 존재할수 있다.


4
0 1 0 1
1 0 1 2
0 1 0 1
1 2 1 0



답 : 시작하는 위치에 따라 결과가 다르다.

1번 부터 출발했을때의 모든 경로
1 2 3 4 2 4 1
1 2 4 2 3 4 1
1 2 4 3 2 4 1
1 4 2 3 4 2 1
1 4 2 4 3 2 1
1 4 3 2 4 2 1

2번 부터 출발했을때의 모든 경로
2 1 4 2 3 4 2
2 1 4 2 4 3 2
2 1 4 3 2 4 2
2 3 4 1 2 4 2
2 3 4 2 1 4 2
2 3 4 2 4 1 2
2 4 1 2 3 4 2
2 4 1 2 4 3 2
2 4 2 1 4 3 2
2 4 2 3 4 1 2
2 4 3 2 1 4 2
2 4 3 2 4 1 2


*/



#include<stdio.h>

int N;
int MAP[10][10];
int check[10];

int stack[1000];
int top = -1;

int E;


void input()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &MAP[i][j]);
			E += MAP[i][j];
		}

	E = E / 2;
}

int isitfinished()
{
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			if (MAP[i][j]) return 0;
		}
	return 1;
}

void solve(int start_v, int v)
{


#if 0	// 모든 인접 행렬을 확인해서 처리 
	if (isitfinished() && start_v == v)
	{
		for (int i = 0; i <= top; i++)
		{
			printf(" %d", stack[i]);
		}

		printf("\n");
		return;
	}
#else //간선의 수로 Base 처리 
	if (E==0 && start_v == v)
	{
		for (int i = 0; i <= top; i++)
		{
			printf(" %d", stack[i]);
		}

		printf("\n");
		return;
	}

#endif


	for (int i = 1; i <= N; i++)
	{
		if (MAP[v][i] > 0)
		{
			MAP[v][i]--;
			MAP[i][v]--;

			top++;  //스택을 이용해서 이동한 위치 저장 
			stack[top] = i;

			E--;  // 간선의 갯수로 Base를 처리하기 위해서

			solve(start_v, i);

			E++;  // 간선의 갯수로 Base를 처리하기 위해서 


			top--;
			MAP[v][i]++;
			MAP[i][v]++;
		}
	}

}




void main(void)
{
	input();

	int start_v = 1;
	solve(start_v, start_v);
}



//////////////////////////////////////////////////
//방향성이 있는 한붓그리기

4
0 1 0 1
0 0 1 1
0 0 0 1
0 1 0 0

//이건 해가 없음

4
0 1 0 0
0 0 1 1
0 0 0 1
1 1 0 0

//1번에서 부터 출발시 
1 2 3 4 2 4 1
1 2 4 2 3 4 1


#include<stdio.h>

int N;
int MAP[10][10];

int edge_count;
int vertex_start;

int top = -1;
int stack[10000];

void input()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);

	for(int i = 1;i<=N;i++)
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &MAP[i][j]);
			
			if (MAP[i][j] >=0) edge_count += MAP[i][j];

		}
}


void solve(int v)
{
	if (edge_count == 0 && vertex_start == v)
	{
		for (int i = 0; i <= top; i++)
		{
			printf("%d ", stack[i]);
		}
		printf("\n");

		return;
	}


	for (int i = 1; i <= N; i++)
	{
		if (MAP[v][i] != 0)
		{
			MAP[v][i]--;
			edge_count--;

			top++;
			stack[top] = i;

			solve(i);

			top--;

			edge_count++;
			MAP[v][i]++;
		}
	}

}

void main()
{
	input();

	vertex_start = 1; // 1번 부터 출발했을때 방향성 있는 한붓 그리기 

	top++;
	stack[top] = vertex_start;

	solve(vertex_start);


}







