
//노트 참고 // 그래프
/*
6
0 1 0 0 0 0
1 0 1 1 0 0
0 1 0 0 1 0
0 1 0 0 1 0
0 0 1 1 0 1
0 0 0 0 1 0

이 예제 결과 

visited:1 deeps:0
visited:2 deeps:1
visited:3 deeps:2
visited:5 deeps:3
visited:4 deeps:4
deeps : 4 - cycle start:2 ~ end:4
processed:4
visited:6 deeps:4
processed:6
processed:5
processed:3
deeps : 1 - cycle start:4 ~ end:2
processed:2
processed:1

>>>>>>>>>>>>>>>>>>>>>>>

//노트 참조  // 트리 
6
0 1 1 0 0 0
1 0 0 1 1 0
1 0 0 0 0 1
0 1 0 0 0 0
0 1 0 0 0 0
0 0 1 0 0 0


//노트 참조 
10
0 1 0 0 0 0 0 0 0 0
1 0 1 1 0 0 0 0 0 0
0 1 0 0 1 0 0 0 0 0
0 1 0 0 1 0 0 0 0 0
0 0 1 1 0 1 0 0 0 0
0 0 0 0 1 0 1 1 0 0
0 0 0 0 0 1 0 0 1 0
0 0 0 0 0 1 0 0 1 0
0 0 0 0 0 0 1 1 0 1
0 0 0 0 0 0 0 0 1 0


10
0 1 0 0 0 0 0 0 0 1
1 0 1 1 0 0 0 0 0 0
0 1 0 0 1 0 0 0 0 0
0 1 0 0 1 0 0 0 0 0
0 0 1 1 0 1 0 0 0 0
0 0 0 0 1 0 1 1 0 0
0 0 0 0 0 1 0 0 1 0
0 0 0 0 0 1 0 0 1 0
0 0 0 0 0 0 1 1 0 1
1 0 0 0 0 0 0 0 1 0
*/

//내방법 이걸 알아 놓도록 
//두색칠하기와 비슷한 로직 


#include<stdio.h>

int N;
int MAP[11][11];

int visited[11];
int parents[11];
int processed[11];


void print_path(int start, int end)
{
	if (start == end || end == -1)  //종료 조건
	{
		printf(" %d", start);
	}
	else
	{
		print_path(start, parents[end]);
		printf(" %d", end);
	}

	printf("\n");
}



void solve(int v, int k)
{

	printf("visited:%d deeps:%d\n", v,k);
	visited[v] = 1;

	//제일 처음 생각한 방식 , 이웃하는 모든 정점에 대해서 확인함.
	//process 처리를 안해도됨.
	for (int i = 1; i <= N; i++)
	{
			//이미 이미 노드에 대해서
			if (visited[i] == 1 && MAP[v][i])
			{
				if (parents[v] != i)
				{
					printf("deeps : %d - cycle start:%d ~ end:%d\n", k, i, v);  

					print_path(i, v); // 입력 시작과 종료 
				}
			}
	}


	for (int i = 1; i <= N; i++)
	{
			if (visited[i] == 0 && MAP[v][i])   //process 처리를 안해도됨.
			{
				parents[i] = v;
				solve(i,k+1);
			}
	}
}

void main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		parents[i] = -1;
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &MAP[i][j]);
		}
	}

	int k = 0; // deeps; 알고리즘 동작 확인을 위해서 깊이를 한번 알아보자.
	solve(1,k);
}






//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>













#include<stdio.h>

int N;
int MAP[11][11];

int visited[11];
int parents[11];
int processed[11];


void print_path(int start, int end)
{
	if (start == end || end == -1)  //종료 조건
	{
		printf(" %d", start);
	}
	else
	{
		print_path(start, parents[end]);
		printf(" %d", end);
	}

	printf("\n");
}



void solve(int v, int k)
{

	printf("visited:%d deeps:%d\n", v,k);
	visited[v] = 1;


	for (int i = 1; i <= N; i++)
	{
		if (MAP[v][i])
		{
			if (visited[i] == 0)
			{
				parents[i] = v;
				solve(i,k+1);
			}
			else
			{
				//이미 이미 노드에 대해서 

				if (processed[i]==0) //시작 노드를 바라보고 이미 처리가 되었나?
				if (parents[v] != i)
				{
					printf("deeps : %d - cycle start:%d ~ end:%d\n",k, i, v);  // 어떤 깊이에서 중복된 결과가 나오는지 이걸 보고 중복된 사이클이 나오지 않게 처리해야함.
				
					print_path(i, v); // 입력 시작과 종료 
				}
			}
		}
	}

	processed[v] = 1;  // 제일 바닥에서 처리 노드를 체크하면서 나간다. 중복을 피하기 위해서 
	printf("processed:%d\n", v);
}

void main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		parents[i] = -1;
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &MAP[i][j]);
		}
	}

	int k = 0; // deeps; 알고리즘 동작 확인을 위해서 깊이를 한번 알아보자.
	solve(1,k);
}






//내가 생각한 방식 for 부분이 다름 

//노트 참고 // 그래프
/*
6
0 1 0 0 0 0
1 0 1 1 0 0
0 1 0 0 1 0
0 1 0 0 1 0
0 0 1 1 0 1
0 0 0 0 1 0

이 예제 결과 

visited:1 deeps:0
visited:2 deeps:1
visited:3 deeps:2
visited:5 deeps:3
visited:4 deeps:4
deeps : 4 - cycle start:2 ~ end:4
processed:4
visited:6 deeps:4
processed:6
processed:5
processed:3
deeps : 1 - cycle start:4 ~ end:2
processed:2
processed:1

>>>>>>>>>>>>>>>>>>>>>>>

//노트 참조  // 트리 
6
0 1 1 0 0 0
1 0 0 1 1 0
1 0 0 0 0 1
0 1 0 0 0 0
0 1 0 0 0 0
0 0 1 0 0 0


//노트 참조 
10
0 1 0 0 0 0 0 0 0 0
1 0 1 1 0 0 0 0 0 0
0 1 0 0 1 0 0 0 0 0
0 1 0 0 1 0 0 0 0 0
0 0 1 1 0 1 0 0 0 0
0 0 0 0 1 0 1 1 0 0
0 0 0 0 0 1 0 0 1 0
0 0 0 0 0 1 0 0 1 0
0 0 0 0 0 0 1 1 0 1
0 0 0 0 0 0 0 0 1 0


10
0 1 0 0 0 0 0 0 0 1
1 0 1 1 0 0 0 0 0 0
0 1 0 0 1 0 0 0 0 0
0 1 0 0 1 0 0 0 0 0
0 0 1 1 0 1 0 0 0 0
0 0 0 0 1 0 1 1 0 0
0 0 0 0 0 1 0 0 1 0
0 0 0 0 0 1 0 0 1 0
0 0 0 0 0 0 1 1 0 1
1 0 0 0 0 0 0 0 1 0
*/



























//아래는 교재 위주
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


////////////////////////////////////////////////
//아래 프로그램 챌린지 예제
////////////////////////////////////////////////
/*
해당 그래프의 사이클의 갯수와 그 경로를 출력하시오






*/

#include<stdio.h>

int V;

int map[100][100];
int check[100];

int parent[100];
int processed[100];

int finished;

void find_path(int start, int end)
{
	if (start == end || end == -1)
	{
		printf("\n%d", start);
	}
	else
	{
		find_path(start, parent[end]);
		printf(" %d", end);
	}

}

void process_edge(int v, int y)
{
	if (parent[v] != y)
	{
		printf("\ncycle from %d to %d\n",y,v);
		//find_path(y,x);
		finished = 1;
	}
}


void solve(int v)
{
	//if (finished) return;
	check[v] = 1;
	printf("visited:%d\n", v);


	for (int i = 1; i <= V; i++)
	{
		if (map[v][i])        //유효한 노드인가?
		{
			if (check[i] == 0) // 방문을 한 노드인가?
			{
				parent[i] = v;
				solve(i);
			}
			else 
			{   //갈수 있고 이미 방문한 노드에 대해서
				if (processed[i] == 0)
				{
					process_edge(v, i);
				}
			}
		}
	}

	processed[v] = 1;

}

void main()
{

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &V);

	for (int i = 1; i <= V; i++)
	{
		parent[i] = -1;
		for (int j = 1; j <= V; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	solve(1); 

}
