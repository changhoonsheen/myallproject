







//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

/*
MST 프림 알고리즘
교재 Page 66

7
0 32 31 0 0 60 51
32 0 21 0 0 0 0
31 21 0 0 46 0 25
0 0 0 0 34 18 0
0 0 46 34 0 40 51
60 0 0 18 40 0 0
51 0 25 0 51 0 0

답 175

*/

#include<stdio.h>

#define INF 0xFFFFF  // 대충 큰값을 잡는다.

int N;
int MAP[10][10];

int CHECK[10];  //방문 여부 체크 
int DIST[10];   //매순간 알고리즘에서 선정되는 정점이 선택된 집합으로 추가될때 갱신되는 DIST 배열 
int PA[10];     //각 정점의 부모를 가지고 있는 배열, 이걸로 트리의 모양을 알 수 있다.


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
		if (CHECK[i] == 0) return 1; // 더 돌수 있다.
	}

	return 0;
}


void main()
{
	int total_cost = 0;
	input();

	//모든정점이 선택되었나? , 정점의 갯수로 대치가능
	while (isitpossible())
	{
		//<<  // getBestnode 선택되지 않는 정점들중 제일 작은거!!! 실수!!!
		int node = 0;
		int w = -1;

		for (int i = 0; i < N; i++)
		{
			if (CHECK[i] == 0)  //실수!!! <이거 빼먹음!! >
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
			if (CHECK[i] == 0 && DIST[i] > MAP[node][i])  // 점화식 실수!!  선택되지 않은 정점의 모든 distance를 갱신한다. , DIST[i] > MAP[node][i]
			{
				DIST[i] = MAP[node][i];
				PA[i] = node;
			}
		}

	}

	printf("total_cost:%d\n", total_cost);
}


