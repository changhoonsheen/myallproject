/*

7
1 2
8 7
20 10
20 20
15 12
12 14
11 12

답 :6



11
1 2
8 7
20 10
20 20
15 12
12 14
11 12
20 15
20 5
20 10 
20 5

답:7

*/

#include<stdio.h>

int N;

struct PAPER
{
	int w;
	int h;
};


PAPER p[20];
int DT[20];

void SWAP(int *a, int *b)
{
	int temp=*a;
	*a = *b;
	*b = temp;
}

void input()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &p[i].w, &p[i].h);

		if (p[i].w > p[i].h) // hight 보다 width가 큰걸 앞으로
		{
			SWAP(&p[i].w, &p[i].h);
		}
	}

}


//한번도 생각해보지 못한 정렬 로직이다.
//선택정렬이기에 가능하다. w중에 제일큰게, w가 같다면 그중에서 h가 제일큰거 
//난 엉뚱하게 생각했다.

void sort()
{
	for (int i = 0; i < N; i++)
	{	
		for (int j = i + 1; j < N; j++)
		{
			if (p[i].w > p[j].w)
			{
				PAPER temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
			else
			{
				if (p[i].w == p[j].w)
				{
					if (p[i].h > p[j].h)
					{
						PAPER temp = p[i];
						p[i] = p[j];
						p[j] = temp;
					}
				}
			}

		}
	}
}

int MAX(int a, int b)
{
	return a > b ? a : b;
}

//백트래킹
int func_call = 0;
int solve(int k)
{
	if (DT[k] != 0) return DT[k];

	func_call++;

	int m = 0;

	if (k == 0)
	{
		return DT[k]=1;
	}


	for (int i = 0; i < k; i++)
	{
		if (p[k].w >= p[i].w && p[k].h >= p[i].h)
	//	if (p[k].h >= p[i].h)
		{ 
			m = MAX(m, solve(i)); // 이 부분 생각 잘못했다.
			                      // DP를 생각해서 solve(k-1)로 생각했다.;;;
		}
	}

	return DT[k] = m + 1;
}


void main()
{
	input();
	sort(); // width가 큰게 앞으로 witdth가 같다면 hight가 큰게 앞으로 
	        // 이런 정렬은 한번도 생각 못해봤다. 
	
	//+		DT	0x011d81d8 {1, 2, 3, 2, 4, 5, 3, 4, 5, 6, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0}	int[20]



#if 1
	printf("%d\n", solve(N - 1));
#else

	//DP 풀이 
	//노트 참조 
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (p[i].w >= p[j].w && p[i].h >= p[j].h && DT[i] < DT[j])
			{
				DT[i] = DT[j];
			}
		}
		DT[i]++;
	}



	int max = 0;
	for (int i = 0; i < N; i++)
	{
		if (DT[i] > max) max = DT[i];
	}

	printf("%d", max);

#endif
	
	printf("func_call:%d\n", func_call);

}
