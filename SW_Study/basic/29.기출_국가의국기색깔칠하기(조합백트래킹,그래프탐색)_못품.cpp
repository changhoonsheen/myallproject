

/*
아래와 같이 정보가 주어졌을때 최소한 국기의 색깔 정보를 변경하여, 이웃하는(인접한) 국기가 다른색깔이 되도록 
할때 최소한 변경된 국기의 횟수는?  

3         //<< 3개의 국가 
2 2 2     //각 국가별 국기 정보 (1~4) 
0 1 0     // 국가별로 연결된 그래프 정보 
1 0 1
0 1 0

3
2 2 2
0 1 0
1 0 1
0 1 0
답 1


4
2 2 2 2
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1

-> 3번 



// 현재 국가의 색깔이 칠해져 있다. 두번째 라인
// 이하값은 인접행렬이다.
// 이때 최소한 몇번의 값을 변동하면, 이웃하는 국가의 국기 색깔이 달라질까?

*/


#include<stdio.h>

int N;

int ORIGINAL_COLOR[11];
int COLOR[11];
int ADJ[11][11];

int check[11];

int new_color[11];

int MIN_CNT = 987654321;

void input()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &COLOR[i]);
		ORIGINAL_COLOR[i] = COLOR[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &ADJ[i][j]);
		}
	}
}

int MIN_COUNT = 987654321;

//전체 노드를 탐색을 하되, 특정 노드에 방문했을때, 이웃한 노드의 색깔이
//현재 노드의 색깔과 같은지 판별한다.
int NO_OK = 0;
void isitOK(int nation)
{
	int color = COLOR[nation];

	//printf("visit : %d \n", nation);

	for (int k = 1; k <= N; k++) // 컬러 체크를 위해서. 이웃하는 모든 노드를 체크한다.
	{
		if (ADJ[nation][k] && nation!=k)
				{
					int next_color = COLOR[k];
					if (color == next_color)
					{
						NO_OK = 1;
					}
				}
	}

	for (int i = 1; i <= N; i++)
	{
		if (ADJ[nation][i] && check[i]==0)  // 순회를 위한 제어 
		{
			check[i] = 1;
			isitOK(i);
		}
	}
}

void init()
{
	for (int i = 1; i <= N; i++)
	{
		check[i] = 0;
	}	
	NO_OK = 0;
}

void copy_color()
{
	for (int i = 1; i<= N; i++)
	{
		COLOR[i] = new_color[i];
	}
}

//몇개 변동이 필요한지 체크한다.
int check_CHANGES()
{
	int cnt = 0;

	for (int i = 1; i <= N; i++)
	{
		if (new_color[i] != ORIGINAL_COLOR[i]) cnt++;
	}

	return cnt;
}

//모든해의 상태공간의 값이다!!!
void solve(int i)
{
	if (i == N+1)
	{
		copy_color();

		init();
		check[1]=1;
		isitOK(1);

		/*
		for (int k = 1; k <= N; k++)
		{
			printf("%d ", new_color[k]);
		}

		printf(" : NO_OK %d \n", NO_OK);
		*/
		
		if (NO_OK == 0)
		{

			int changes = check_CHANGES();

			if (MIN_CNT > changes){
				/*
				for (int k = 1; k <= N; k++)
				{
					printf("%d ", new_color[k]);
				}

				printf(": %d \n", changes);		
				*/
				MIN_CNT = changes;
			}

		}
		
		return;
	}

	for (int k = 1; k <= 4; k++)
	{
		new_color[i] = k;
		solve(i + 1);
	}
}


int main(void)
{
	input();

    solve(1);
    printf("%d", MIN_CNT);
	
	/*
	COLOR[1] = 1;
	COLOR[2] = 2;
	COLOR[3] = 3;
	COLOR[4] = 4;

	init();
	check[1] = 1;
	isitOK(1);

	printf("NO_OK:%d\n", NO_OK);

	printf("-----------------\n");

	COLOR[1] = 1;
	COLOR[2] = 2;
	COLOR[3] = 1;
	COLOR[4] = 2;

	init();
	check[1] = 1;
	isitOK(1);

	printf("NO_OK:%d\n", NO_OK);
	*/

}
