//송전탑 기출 문제 
//부분 집합 문제임.
/*
5
1000 300 200 50 100
0 1 1 0 1
1 0 0 0 0
1 0 0 0 1
0 0 0 0 0
1 0 1 0 0 
답 : 450


5
1000 300 200 50 100
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
답 50


5
1000 300 200 50 100
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
답 1650


*/

#include<stdio.h>

int N;
int MONEY[20];
int MAP[20][20];

int CHECK[20]; //전기가 들어 오는 여부를 파악하는 체크 배열 
int BUILT_CHECK[20];  // 현재 어느 도시에 송전탑을 설치했는지 나타내는 배열 
int RESULT_BUILT_CHECK[20];

int MIN_MONEY = 987654321;

void input()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	scanf("%d",&MONEY[i]);

	for (int i = 1; i <= N;i++)
	for (int j = 1; j <= N;j++)
	{
		scanf("%d", &MAP[i][j]);
	}
}


void check_city(int k, int candi_arr[], int &candi_cnt)
{
	candi_arr[candi_cnt] = k;
	CHECK[k] = CHECK[k] + 1;
	candi_cnt++;

	for (int i = 1; i <= N; i++)
	{
		if (MAP[k][i]==1)
		{
			candi_arr[candi_cnt] = i;
			CHECK[i] = CHECK[i] + 1;  // 이부분 하이라이트임.
			candi_cnt++;
		}
	}
}

void uncheck_city(int candi_arr[], int candi_cnt)
{
	for (int i = 0; i < candi_cnt; i++)
	{
		CHECK[candi_arr[i]] = CHECK[candi_arr[i]] - 1;   // 이부분 하이라이트임.
	}
}


int isfinished()
{
	for (int i = 1; i <= N; i++)
	{
		if (CHECK[i] == 0) return 0;
	}

	return 1;
}

void solve(int k , int money)
{
	int candi_arr[20] = { 0 };
	int candi_cnt = 0;

	if (k == N + 1)
	{
		if (isfinished())
		{
			if (MIN_MONEY > money)
			{
				MIN_MONEY = money;

				for (int i = 1; i <= N; i++)
				RESULT_BUILT_CHECK[i] = BUILT_CHECK[i];
			}
		}

		return;
	}


	//해당 도시에 짓게 될경우
	check_city(k, candi_arr, candi_cnt);
	BUILT_CHECK[k] = 1;
	solve(k+1, money + MONEY[k]);
	BUILT_CHECK[k] = 0;
	uncheck_city(candi_arr, candi_cnt);


	//안지을 경우
	solve(k+1, money);

}



void main()
{
	input();

	solve(1, 0);

	printf("min money:%d\n", MIN_MONEY);

	printf("selected city: \n");
	for (int i = 1; i <= N; i++)
	{
		if (RESULT_BUILT_CHECK[i] == 1) 
			printf("%d city\n", i);
	}

}



//잘못 풀이함. 시험때 이렇게 풀었음.....
//
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//송전탑 기출 문제
/*
5
1000 300 200 50 100
0 1 1 0 1
1 0 0 0 0
1 0 0 0 1
0 0 0 0 0
1 0 1 0 0 

답 : 450

*/

#include<stdio.h>

int N;
int MONEY[20];
int MAP[20][20];

int CHECK[20];
int BUILT_CHECK[20];
int RESULT_CHECK[20];

int MIN_MONEY = 987654321;

void input()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	scanf("%d",&MONEY[i]);

	for (int i = 1; i <= N;i++)
	for (int j = 1; j <= N;j++)
	{
		scanf("%d", &MAP[i][j]);
	}
}

int pre_built()
{
	int money = 0;
	for (int i = 1; i <= N; i++)
	{
		int connected_cnt = 0;

		for (int j = 1; j <= N; j++)
		{
			if (MAP[i][j] == 1) connected_cnt++;
		}

		if (connected_cnt == 0)
		{
			money += MONEY[i];
			CHECK[i] = 1;
		}
	}

	return money;
}

void check_city(int k, int candi_arr[], int &candi_cnt)
{
	candi_arr[candi_cnt] = k;
	CHECK[k] = 1;
	candi_cnt++;

	for (int i = 1; i <= N; i++)
	{
		if (MAP[k][i]==1 && CHECK[i] == 0)
		{
			candi_arr[candi_cnt] = i;
			CHECK[i] = 1;
			candi_cnt++;
		}
	}
}

void uncheck_city(int candi_arr[], int candi_cnt)
{
	for (int i = 0; i < candi_cnt; i++)
	{
		CHECK[i] = 0;
	}
}


int isfinished()
{
	for (int i = 1; i <= N; i++)
	{
		if (CHECK[i] == 0) return 0;
	}

	return 1;
}

void solve(int k , int money)
{
	int candi_arr[20] = { 0 };
	int candi_cnt = 0;

	if (isfinished())
	{
		if (MIN_MONEY > money)
		{
			MIN_MONEY = money;

			//	for (int i = 1; i <= N; i++)
			//		RESULT_CHECK[i] = CHECK[i];
		}
	}

	if (k == N + 1)
	{
		if (isfinished())
		{
			if (MIN_MONEY > money)
			{
				MIN_MONEY = money;

			//	for (int i = 1; i <= N; i++)
			//		RESULT_CHECK[i] = CHECK[i];
			}
		}

		return;
	}



	if (CHECK[k] == 0)
	{
		check_city(k, candi_arr, candi_cnt);
		solve(k + 1, money+MONEY[k]);
		uncheck_city(candi_arr, candi_cnt);

		solve(k + 1, money);
	}
	else
	{
		solve(k + 1, money);
	}
}



void main()
{
	input();

	int money = pre_built();  //연결이 안된 도시는 먼저 연결한다.
	solve(1, money);

	printf("%d", MIN_MONEY);
}