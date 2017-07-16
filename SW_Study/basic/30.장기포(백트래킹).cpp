/*
5
0 1 0 0 1
1 1 0 0 0
0 1 1 0 1
0 0 2 0 0
1 0 1 1 0


5
0 0 1 0 0
0 0 1 0 0
1 1 2 1 1
0 0 1 0 0
0 0 1 0 0

--> 결과 
0 0 1 0 0
0 0 2 0 0
1 2 0 2 1
0 0 2 0 0
0 0 1 0 0


7
0 0 0 1 0 0 0
0 0 0 1 0 0 0
0 0 0 1 0 0 0
1 1 1 2 1 1 1
0 0 0 1 0 0 0
0 0 0 1 0 0 0
0 0 0 1 0 0 0

-->결과
0 0 0 3 0 0 0
0 0 0 1 0 0 0
0 0 0 2 0 0 0
3 1 2 0 2 1 3
0 0 0 2 0 0 0
0 0 0 1 0 0 0
0 0 0 3 0 0 0




7
1 1 0 0 0 1 1
1 0 0 1 0 0 1
0 0 0 0 0 0 0
1 1 1 2 1 1 1
0 0 0 1 0 0 0
1 0 0 1 0 0 1
1 1 0 1 0 1 1


--> 결과
2 3 0 0 0 3 2
0 0 0 2 0 0 0
0 0 0 0 0 0 0
3 1 2 0 2 1 3
0 0 0 2 0 0 0
0 0 0 1 0 0 0
0 0 0 3 0 0 0

*/



#include<stdio.h>

int N;
int MAP[10][10];

int CHECK[10][10];

struct CORD
{
	int x;
	int y;
};

CORD START_PO;


void input()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &MAP[i][j]);
			if (MAP[i][j] == 2)
			{
				START_PO.x = i;
				START_PO.y = j;
			}
		}
}


// 이문제의 중심은 이 함수이고, 장기 포의 이동에 따른 모든 후보군을 뽑아내는 것이다.
void get_all_path(CORD po, CORD *path, int &path_cnt)
{
	int new_x = po.x;
	int new_y = po.y;

	int cnt = 0;
	CORD horse_cnt[100] = { 0 };


	//dir 0
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>


	cnt = 0;
	for (int i = new_x - 1; i >= 0; i--)
	{
		if (MAP[i][new_y] == 1){
			horse_cnt[cnt].x = i;
			horse_cnt[cnt].y = new_y;
			cnt++;
		}
	}

	if (cnt == 0) goto dir_1;
	if (cnt == 1 && MAP[0][new_y]) goto dir_1;

	if (cnt == 1)
	{
		for (int i = horse_cnt[0].x - 1; i >= 0; i--)
		{

			path[path_cnt].x = i;
			path[path_cnt].y = new_y;
			path_cnt++;
		}
	}
	else
	{
		for (int i = horse_cnt[0].x - 1; i >= horse_cnt[1].x; i--)  // 이 부분이 하이라이트! 주의깊게 봐라~
		{

			path[path_cnt].x = i;
			path[path_cnt].y = new_y;
			path_cnt++;
		}

	}


dir_1:

	//dir 1
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	cnt = 0;
	for (int i = new_y + 1; i < N; i++)
	{
		if (MAP[new_x][i] == 1){
			horse_cnt[cnt].x = new_x;
			horse_cnt[cnt].y = i;
			cnt++;
		}
	}

	if (cnt == 0) goto dir_2;
	if (cnt == 1 && MAP[new_x][N - 1])goto dir_2;

	if (cnt == 1)
	{
		for (int i = horse_cnt[0].y + 1; i < N; i++)
		{

			path[path_cnt].x = new_x;
			path[path_cnt].y = i;
			path_cnt++;
		}
	}
	else
	{
		for (int i = horse_cnt[0].y + 1; i <= horse_cnt[1].y ; i++)
		{

			path[path_cnt].x = new_x;
			path[path_cnt].y = i;
			path_cnt++;
		}
	}


dir_2:
	//dir 2
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	cnt = 0;
	for (int i = new_x + 1; i < N; i++)
	{
		if (MAP[i][new_y] == 1){
			horse_cnt[cnt].x = i;
			horse_cnt[cnt].y = new_y;
			cnt++;
		}
	}

	if (cnt == 0) goto dir_3;
	if (cnt == 1 && MAP[N - 1][new_y])goto dir_3;

	if (cnt == 1)
	{
		for (int i = horse_cnt[0].x + 1; i < N; i++)
		{

			path[path_cnt].x = i;
			path[path_cnt].y = new_y;
			path_cnt++;
		}
	}
	else
	{
		for (int i = horse_cnt[0].x + 1; i <= horse_cnt[1].x; i++)
		{

			path[path_cnt].x = i;
			path[path_cnt].y = new_y;
			path_cnt++;
		}
	}


dir_3:
	//dir 3
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	cnt = 0;
	for (int i = new_y - 1; i >= 0; i--)
	{
		if (MAP[new_x][i] == 1){
			horse_cnt[cnt].x = new_x;
			horse_cnt[cnt].y = i;
			cnt++;
		}
	}

	if (cnt == 0) return;
	if (cnt == 1 && MAP[new_x][0]) return;

	if (cnt == 1)
	{
		for (int i = horse_cnt[0].y - 1; i >= 0; i--)
		{

			path[path_cnt].x = new_x;
			path[path_cnt].y = i;
			path_cnt++;
		}
	}
	else
	{
		for (int i = horse_cnt[0].y - 1; i >= horse_cnt[1].y ; i--)
		{

			path[path_cnt].x = new_x;
			path[path_cnt].y = i;
			path_cnt++;
		}

	}
}

void display()
{
	printf(">>>>>>>>>>>>\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf(" %d", MAP[i][j]);
		}
		printf("\n");
	}

}

void display_check()
{
	printf(">>>>>>>>>>>>\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf(" %d", CHECK[i][j]);
		}
		printf("\n");
	}

}



void solve(int jump, CORD po)
{
	CORD all_path[100] = { 0 };
	int all_path_cnt = 0;

	int sum = 0;

	if (jump == 3)
	{
		return;
	}

	//포가 갈수 있는 모든 경로를 뽑는 함수
	get_all_path(po, all_path, all_path_cnt);

	//printf("all_path_cnt : %d \n", all_path_cnt);

	//
	
	//레이더 함수
	//MAP에 말이 있고, 방문한 이력이 없다면 현재 jump에다 1을 더해서 Check배열을 설정한다.
	for (int j = 0; j < all_path_cnt; j++)
	{
		if (MAP[all_path[j].x][all_path[j].y] == 1 && CHECK[all_path[j].x][all_path[j].y] == 0)
		{
			CHECK[all_path[j].x][all_path[j].y] = jump + 1; // 체크배열에 매회 잡을 수 있는 말의 위치를 갱신한다.
		}
	}

	for (int j = 0; j < all_path_cnt; j++)
	{

		int new_x = all_path[j].x;
		int new_y = all_path[j].y;

		//	printf("%d - new_x :%d , new_y :%d \n", j, new_x, new_y);

		if (MAP[new_x][new_y] == 1) //현재 가야할 자리에 말이 있다면, 15 퍼즐과 흡사한 루틴으로 백트래킹한다.
		{
			MAP[new_x][new_y] = 2;
			MAP[po.x][po.y] = 0;

			solve(jump + 1, all_path[j]);

			MAP[new_x][new_y] = 1;
			MAP[po.x][po.y] = 2;

		}
		else
		{
			MAP[new_x][new_y] = 2;
			MAP[po.x][po.y] = 0;

			solve(jump + 1, all_path[j]);

			MAP[new_x][new_y] = 0;
			MAP[po.x][po.y] = 2;

		}

	}
}



void main(void)
{
	input();
	solve(0, START_PO);
	display_check();

	//문제가 3회 이동의 기회가 주어졌을때 잡을 수 있는 모든 말의 갯수는??

	int total_cnt=0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{

			if (CHECK[i][j]>=1)
			{
				total_cnt++;
			}
		}

	printf("%d\n", total_cnt);

}