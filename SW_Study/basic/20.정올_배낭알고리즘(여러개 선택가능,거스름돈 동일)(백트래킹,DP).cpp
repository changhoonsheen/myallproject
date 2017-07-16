/*
그냥 
배낭 알고리즘 (중복가능) 이는 거스름돈 알고리즘하고 흡사하다.
//5개의 항목이 있으며, 8kg의 배낭을(무게를 초과하지 않으면서) 가지고 있다. 최대 이익이 되게 가방에
//물건을 넣으며, 얼마를 넣을 수 있겠는가?
//그리고 무슨 물건을 선택했는지? 

5 8
4 4500
5 5700
2 2250
1 1100
6 6700

답은 9050

MAX value : 9050
func_call : 17
w:8 item:2
w:7 item:2
w:6 item:2
w:5 item:2
w:4 item:1
w:3 item:3
w:2 item:3
w:1 item:4
w:0 item:0
item:2 price:5700
item:3 price:2250
item:4 price:1100


////////////////////////////////


5 8
2 2250
1 1100
6 6700
4 4500
2 10000

MAX value : 40000
func_call : 16
w:8 item:5
w:7 item:2
w:6 item:5
w:5 item:2
w:4 item:5
w:3 item:2
w:2 item:5
w:1 item:2
w:0 item:0
item:5 price:10000
item:5 price:10000
item:5 price:10000
item:5 price:10000





*/

#include<stdio.h>

int wi[100];
int vi[100];

int N;
int W;

int func_call;

int DT[100000]; // 배낭의 크기 

int item[10];


void input()
{
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &W);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &wi[i], &vi[i]);
	}
}

int MAX(int a, int b)
{
	return a > b ? a : b;
}

//가방의 무게가 weight일때 최대로 많이 담을 수 있는 가치는?
int solve(int WEIGHT)
{

	if (DT[WEIGHT] != 0) return DT[WEIGHT];

	func_call++;

	if (WEIGHT == 0)
	{
		return DT[WEIGHT] = 0;
	}

	//int VALUE = -987654321;
	int VALUE = 0; // 아무것도 못 넣는 경우가 있기 때문에 0이 맞음 
	
	for (int i = 1; i <= N; i++)
	{
		if (WEIGHT - wi[i] >= 0)
		{
			if (VALUE < solve(WEIGHT - wi[i]) + vi[i])
			{
				VALUE = solve(WEIGHT - wi[i]) + vi[i];
				item[WEIGHT] = i;
			}
			else
			{
				VALUE = VALUE;
			}
		}
	}

	return DT[WEIGHT] = VALUE;
}

void main()
{
	input();


	printf("MAX value : %d\n", solve(W));

	printf("func_call : %d\n", func_call);


	for (int i = W; i >= 0; i--)
	{
		printf("w:%d item:%d\n", i, item[i]);
	}


	//선택된 물건 찾아보기. 신기하게 찾는다 알아 놓도록, 맞을꺼 같다 알아 놓도록 
	//>>
	int limit = W;
	int min = 0;  // 초과할 수 없기 때문에!!! 
	// 배낭에 들어가는 물건의 총 무게가 제한 무게와 같아지지 않는 경우를 고려하면
	// 조합에 따라서 같지 않을 경우가 있다. 그래서 종료 조건이 s >= 1 이다. 또는 s > 0


	//제일 마지막에 선택된것으로 기준으로 무게를 빼서 나간다. 그런식으로 바닥까지 간다. 이때 선택된 아이템을 알 수가 있다.
	for (int s = limit; s > min; s = s - wi[item[s]])
	{
		printf("s:%d item:%d price:%d\n", s, item[s], vi[item[s]]);
	}
	//<<
}








