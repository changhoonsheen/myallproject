//이 알고리즘의 특징은 요소가 인덱스가 아님,  트리를 그려라.
//직접 Item를 복사하는 구조이다. 재귀 방식은 순열이든, 조합이든 요소들을 보따리(신규 배열을 tr을 만든다.)에 넣는다고 생각한다.
//점화식은 nPr, nCr  p(n,r) c(n,r)로 생각한다.
//그리고 항상 하향식 설계를 한다.




//1. 순열 , 중복순열(전자도어락)

#include<stdio.h>

int N = 3;
int R = 3;

char arr[3] = { '1', '2', '3' };  // 백트래킹 방법과 다르게 요소가 들어간다.
char tr[3];

int CNT;

void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

//일반 순열
void P(int n, int r)
{

	if (r == 0)
	{
		printf("{ ");
		for (int i = 0; i < R; i++)
		{
			printf(" %c", tr[i]);
		}
		printf("}\n");

		CNT++;
		return;
	}


	for (int i = n - 1; i >= 0; i--)
	{
		swap(&arr[n - 1], &arr[i]);
		tr[r - 1] = arr[n - 1];
		P(n - 1, r - 1);
		swap(&arr[n - 1], &arr[i]);
	}
}


//중복 순열
void PI(int n, int r)
{

	if (r == 0)
	{
		printf("{ ");
		for (int i = 0; i < R; i++)
		{
			printf(" %c", tr[i]);
		}
		printf("}\n");
		CNT++;
		return;
	}


	for (int i = n - 1; i >= 0; i--)  // i-- 상향식임 잘못 실수함.!!
	{
		swap(&arr[n - 1], &arr[i]);  //실수!! 자기 자신도 swap함을 잊지 말도록, 상태공간트리를 그리고도 유추 못함!!
		tr[r - 1] = arr[n - 1];
		PI(n , r - 1);
		swap(&arr[n - 1], &arr[i]);
	}
}

void main()
{

	P(N, R);
//	PI(N, R);

	printf("CNT %d \n", CNT);
}


//2. 조합(로또), 중복조합(냉장고에서 사과,배,감을 꺼냄 , 이때 똑같은것을 몇개라도 꺼내도 됨.)

#include<stdio.h>

int N = 3;
int R = 2;

char arr[3] = { '1', '2', '3' };  
char tr[3];

int CNT;



//일반 조합

void C(int n, int r)
{
	if (r == 0)
	{

		printf("{ ");
		for (int i = 0; i < R; i++)
			printf(" %c", tr[i]);

		printf("}\n");

		CNT++;
		return;
	}

	if (n < r) return;

	tr[r - 1] = arr[n-1];
	C(n - 1, r - 1);  // 실수 주의 !! 순서 상관 있음, 선택한 점화식을 먼저 적는다.
	C(n - 1, r);
}


//중복 조합
void H(int n, int r)
{
	if (r == 0)
	{

		printf("{ ");
		for (int i = 0; i < R; i++)
			printf(" %c", tr[i]);

		printf("}\n");

		CNT++;
		return;
	}

	if (n == 0) return;  // 선택할께 더 이상 없는 상태 , 조합하고 이 부분 다름

	tr[r - 1] = arr[n - 1];
	H(n , r - 1);  // 실수 주의 !! 순서 상관 있음, 선택한 점화식을 먼저 적는다. 중복 조합은 이 부분이 N 만 다름
	H(n - 1, r);
}



void main()
{
	//C(3, 2);
	H(3, 2);
	printf("CNT %d \n", CNT);
}



