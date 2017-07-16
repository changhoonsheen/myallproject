//연결 성분
//전체 그래프를 서로 연결되지 않은 조각으로 나눌수 있는가?
//예제 설명은 노트 참고
/*

//3개의 compoent가 생김
compoent cnt :1
visited:1
visited:2
visited:3
visited:5
visited:4
compoent cnt :2
visited:6
compoent cnt :3
visited:7
visited:9
visited:8
visited:10

10
0 1 0 0 0 0 0 0 0 0
1 0 1 1 0 0 0 0 0 0
0 1 0 0 1 0 0 0 0 0
0 1 0 0 1 0 0 0 0 0
0 0 1 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 1 1 0 1
0 0 0 0 0 0 0 0 1 0


//2개의 연결성분
10
0 1 0 0 0 0 0 0 0 1
1 0 1 1 0 0 0 0 0 0
0 1 0 0 1 0 0 0 0 0
0 1 0 0 1 0 0 0 0 0
0 0 1 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 1 1 0 1
1 0 0 0 0 0 0 0 1 0


//1개의 연결성분 
6
0 1 1 0 0 0
1 0 0 1 1 0
1 0 0 0 0 1
0 1 0 0 0 0
0 1 0 0 0 0
0 0 1 0 0 0


*/

#include<stdio.h>

int N;
int MAP[11][11];
int visited[11];



void dfs(int v)
{

	printf("visited:%d \n", v);
	visited[v] = 1;


	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == 0 && MAP[v][i])   //process 처리를 안해도됨.
		{
			dfs(i);
		}
	}
}

//몇개의 연결성분인지 찾아 본다.
//예를 들면 하나의 그래프인지?

void solve()
{
	int cnt = 0;

	for (int i = 1; i <= N; i++)
	{
		if (visited[i]==0)
		{
			cnt++;
			printf("compoent cnt :%d\n", cnt);
			dfs(i);
		}
	}
}



void main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &MAP[i][j]);
		}
	}

	solve();
}
