
//��Ʈ ���� // �׷���
/*
6
0 1 0 0 0 0
1 0 1 1 0 0
0 1 0 0 1 0
0 1 0 0 1 0
0 0 1 1 0 1
0 0 0 0 1 0

�� ���� ��� 

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

//��Ʈ ����  // Ʈ�� 
6
0 1 1 0 0 0
1 0 0 1 1 0
1 0 0 0 0 1
0 1 0 0 0 0
0 1 0 0 0 0
0 0 1 0 0 0


//��Ʈ ���� 
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

//����� �̰� �˾� ������ 
//�λ�ĥ�ϱ�� ����� ���� 


#include<stdio.h>

int N;
int MAP[11][11];

int visited[11];
int parents[11];
int processed[11];


void print_path(int start, int end)
{
	if (start == end || end == -1)  //���� ����
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

	//���� ó�� ������ ��� , �̿��ϴ� ��� ������ ���ؼ� Ȯ����.
	//process ó���� ���ص���.
	for (int i = 1; i <= N; i++)
	{
			//�̹� �̹� ��忡 ���ؼ�
			if (visited[i] == 1 && MAP[v][i])
			{
				if (parents[v] != i)
				{
					printf("deeps : %d - cycle start:%d ~ end:%d\n", k, i, v);  

					print_path(i, v); // �Է� ���۰� ���� 
				}
			}
	}


	for (int i = 1; i <= N; i++)
	{
			if (visited[i] == 0 && MAP[v][i])   //process ó���� ���ص���.
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

	int k = 0; // deeps; �˰��� ���� Ȯ���� ���ؼ� ���̸� �ѹ� �˾ƺ���.
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
	if (start == end || end == -1)  //���� ����
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
				//�̹� �̹� ��忡 ���ؼ� 

				if (processed[i]==0) //���� ��带 �ٶ󺸰� �̹� ó���� �Ǿ���?
				if (parents[v] != i)
				{
					printf("deeps : %d - cycle start:%d ~ end:%d\n",k, i, v);  // � ���̿��� �ߺ��� ����� �������� �̰� ���� �ߺ��� ����Ŭ�� ������ �ʰ� ó���ؾ���.
				
					print_path(i, v); // �Է� ���۰� ���� 
				}
			}
		}
	}

	processed[v] = 1;  // ���� �ٴڿ��� ó�� ��带 üũ�ϸ鼭 ������. �ߺ��� ���ϱ� ���ؼ� 
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

	int k = 0; // deeps; �˰��� ���� Ȯ���� ���ؼ� ���̸� �ѹ� �˾ƺ���.
	solve(1,k);
}






//���� ������ ��� for �κ��� �ٸ� 

//��Ʈ ���� // �׷���
/*
6
0 1 0 0 0 0
1 0 1 1 0 0
0 1 0 0 1 0
0 1 0 0 1 0
0 0 1 1 0 1
0 0 0 0 1 0

�� ���� ��� 

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

//��Ʈ ����  // Ʈ�� 
6
0 1 1 0 0 0
1 0 0 1 1 0
1 0 0 0 0 1
0 1 0 0 0 0
0 1 0 0 0 0
0 0 1 0 0 0


//��Ʈ ���� 
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



























//�Ʒ��� ���� ����
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


////////////////////////////////////////////////
//�Ʒ� ���α׷� ç���� ����
////////////////////////////////////////////////
/*
�ش� �׷����� ����Ŭ�� ������ �� ��θ� ����Ͻÿ�






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
		if (map[v][i])        //��ȿ�� ����ΰ�?
		{
			if (check[i] == 0) // �湮�� �� ����ΰ�?
			{
				parent[i] = v;
				solve(i);
			}
			else 
			{   //���� �ְ� �̹� �湮�� ��忡 ���ؼ�
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
