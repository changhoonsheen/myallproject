//중요!!
//입력이 {10,11,1,23,1} 이렇다고 해도 현혹되지마라 인덱스 {0,1,2,3,4}라고 생각하고 풀고 나중에 순서의 열이 만들어 지면  출력할때 매칭한다.

// 절대 코드를 못 외운다.
// {0,1,2} 순열의 트리를 그려본다. // 주의!! 순열은 인덱스를 처리하고 나중에 출력할때 입력된 배열에 맞게 바꿔서 출력한다.
// k=-1 부터 진행해야 깔끔하다.
// 최종 a[]배열에는 인덱스가 들어 간다. 이를 이용해서 외부 배열의 순서열을 출력한다.
// 중간에 permul 배열을 통해서 부호군을 만든다.

//창훈 최종 공책 최종 필기를 보도록 


#include<stdio.h>

int N=3;
int arr[]={10,20,30};

void f(int k, int a[])
{
	int permul[10]={0,};
	int candi[10]={0,};
	int candi_count=0;
	
	if(k==N)
	{
		printf("{");
		for(int i=0;i<N;i++)
		{
			printf(" %d",arr[a[i]]);
		}
		printf(" }");
		printf("\n");
		return;
	}

	for(int i=0;i<k;i++) permul[a[i]]=1; // 이 부분이 항상 틀린다.!! 주의!!

	for(int i=0;i<N;i++)
	{
		if(!permul[i])
		{
			candi[candi_count]=i;
			candi_count++;
		}
	}
	
	for(int i=0;i<candi_count;i++)
	{
		a[k]=candi[i];
		f(k+1,a);
	}
}

void main()
{
	int a[10]={0,};
	f(0,a);
}



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//재귀방법 (인덱스가 아니라 직접 각각의 위치의 요소를 Swap함 : 조합과 동일)
//이 방법은 그냥 참조만 해라.
/////////////////////////////////////////////////

#include<stdio.h>

int N = 3;
char arr[3] = { '1', '2', '3' };

void swap(char *a, char *b)
{
	char temp=*a;
	*a = *b;
	*b = temp;
}

void solve(int k)
{
	if (k == N)
	{
		for (int i = 0; i < N; i++)
			printf(" %c", arr[i]);

		printf("\n");
		return;
	}

	for (int i = k; i < N; i++)
	{
		swap(&arr[k], &arr[i]);  // Swap하고 
		solve(k + 1);
		swap(&arr[k], &arr[i]);  // 백트랙시 원래대로 돌려 놓음

	}
}

void main()
{
	solve(0);
}



//>>
//백트래킹 중복 순열 , 후보군만 차이가 있다.
//<<
#include<stdio.h>

int N = 3;
int arr[] = { 10, 20, 30 };
int cnt = 0;

void f(int k, int a[])
{
	int permul[10] = { 0, };
	int candi[10] = { 0, };
	int candi_count = 0;

	if (k == N)
	{
		printf("{");
		for (int i = 0; i<N; i++)
		{
			printf(" %d", arr[a[i]]);
		}
		printf(" }");
		printf("\n");

		cnt++;

		return;
	}


	//후보군에서 다시 모든 숫자들을 후보군으로 넣어둔다.
	for (int i = 0; i<N; i++)
	{
			candi[candi_count] = i;
			candi_count++;	
	}

	for (int i = 0; i<candi_count; i++)
	{
		a[k] = candi[i];
		f(k + 1, a);
	}
}

void main()
{
	int a[10] = { 0, };
	f(0, a);
	printf("%d\n", cnt);
}














