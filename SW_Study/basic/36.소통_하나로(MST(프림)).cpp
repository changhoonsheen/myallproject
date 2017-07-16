







//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

/*
MST ���� �˰���
���� Page 66

7
0 32 31 0 0 60 51
32 0 21 0 0 0 0
31 21 0 0 46 0 25
0 0 0 0 34 18 0
0 0 46 34 0 40 51
60 0 0 18 40 0 0
51 0 25 0 51 0 0

�� 175

*/

#include<stdio.h>

#define INF 0xFFFFF  // ���� ū���� ��´�.

int N;
int MAP[10][10];

int CHECK[10];  //�湮 ���� üũ 
int DIST[10];   //�ż��� �˰��򿡼� �����Ǵ� ������ ���õ� �������� �߰��ɶ� ���ŵǴ� DIST �迭 
int PA[10];     //�� ������ �θ� ������ �ִ� �迭, �̰ɷ� Ʈ���� ����� �� �� �ִ�.


void input()
{
	freopen("input.txt", "r", stdin);

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		DIST[i] = INF;
		PA[i] = i;

		for (int j = 0; j < N; j++)
		{
			int temp = 0;
			scanf("%d", &temp);

			if (i == j)
			{
				MAP[i][j] = 0;
			}
			else if (temp == 0)
			{
				MAP[i][j] = INF;
			}
			else
			{
				MAP[i][j] = temp;
			}	
		}
	}
}

int isitpossible()
{
	for (int i = 0; i < N; i++)
	{
		if (CHECK[i] == 0) return 1; // �� ���� �ִ�.
	}

	return 0;
}


void main()
{
	int total_cost = 0;
	input();

	//��������� ���õǾ���? , ������ ������ ��ġ����
	while (isitpossible())
	{
		//<<  // getBestnode ���õ��� �ʴ� �������� ���� ������!!! �Ǽ�!!!
		int node = 0;
		int w = -1;

		for (int i = 0; i < N; i++)
		{
			if (CHECK[i] == 0)  //�Ǽ�!!! <�̰� ������!! >
			{
				if (w == -1)
				{
					node = i;
					w = DIST[i];

				}
				else
				{
					if (w > DIST[i])
					{
						node = i;
						w = DIST[i];
					}
				}
			}
		}

		//>>>>>>>>>>

		CHECK[node] = 1;
		if (w != INF) total_cost += w;

		for (int i = 0; i < N; i++)
		{
			if (CHECK[i] == 0 && DIST[i] > MAP[node][i])  // ��ȭ�� �Ǽ�!!  ���õ��� ���� ������ ��� distance�� �����Ѵ�. , DIST[i] > MAP[node][i]
			{
				DIST[i] = MAP[node][i];
				PA[i] = node;
			}
		}

	}

	printf("total_cost:%d\n", total_cost);
}


