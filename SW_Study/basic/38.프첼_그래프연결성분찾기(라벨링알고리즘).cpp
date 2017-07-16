//���� ����
//��ü �׷����� ���� ������� ���� �������� ������ �ִ°�?
//���� ������ ��Ʈ ����
/*

//3���� compoent�� ����
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


//2���� ���Ἲ��
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


//1���� ���Ἲ�� 
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
		if (visited[i] == 0 && MAP[v][i])   //process ó���� ���ص���.
		{
			dfs(i);
		}
	}
}

//��� ���Ἲ������ ã�� ����.
//���� ��� �ϳ��� �׷�������?

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
