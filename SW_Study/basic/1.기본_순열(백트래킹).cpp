//�߿�!!
//�Է��� {10,11,1,23,1} �̷��ٰ� �ص� ��Ȥ�������� �ε��� {0,1,2,3,4}��� �����ϰ� Ǯ�� ���߿� ������ ���� ����� ����  ����Ҷ� ��Ī�Ѵ�.

// ���� �ڵ带 �� �ܿ��.
// {0,1,2} ������ Ʈ���� �׷�����. // ����!! ������ �ε����� ó���ϰ� ���߿� ����Ҷ� �Էµ� �迭�� �°� �ٲ㼭 ����Ѵ�.
// k=-1 ���� �����ؾ� ����ϴ�.
// ���� a[]�迭���� �ε����� ��� ����. �̸� �̿��ؼ� �ܺ� �迭�� �������� ����Ѵ�.
// �߰��� permul �迭�� ���ؼ� ��ȣ���� �����.

//â�� ���� ��å ���� �ʱ⸦ ������ 


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

	for(int i=0;i<k;i++) permul[a[i]]=1; // �� �κ��� �׻� Ʋ����.!! ����!!

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
//��͹�� (�ε����� �ƴ϶� ���� ������ ��ġ�� ��Ҹ� Swap�� : ���հ� ����)
//�� ����� �׳� ������ �ض�.
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
		swap(&arr[k], &arr[i]);  // Swap�ϰ� 
		solve(k + 1);
		swap(&arr[k], &arr[i]);  // ��Ʈ���� ������� ���� ����

	}
}

void main()
{
	solve(0);
}



//>>
//��Ʈ��ŷ �ߺ� ���� , �ĺ����� ���̰� �ִ�.
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


	//�ĺ������� �ٽ� ��� ���ڵ��� �ĺ������� �־�д�.
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














