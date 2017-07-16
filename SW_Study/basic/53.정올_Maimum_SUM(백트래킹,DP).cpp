//â�� �ʱ� ���� �����غ���
/*
6 
6 -7 3 -1 5 2 
*/


//backtracking ����
#include<stdio.h>

int N;
int arr[100];
int func_call;
int MAX(int a, int b)
{
	return a > b ? a : b;
}

int DT[100];
int f(int n)
{
	printf("n:%d\n",n);

	if(n==0) return DT[n]=arr[0];

	return DT[n]=MAX(f(n-1)+arr[n],arr[n]);

}

void main()
{
	freopen("input.txt","r",stdin);

	scanf("%d",&N);

	for(int i=0;i<N;i++)
		scanf("%d",&arr[i]);

	f(N-1);

	int max=DT[0];
	for(int i=1;i<N;i++)
	if(max<DT[i]) max=DT[i]; // �ش� DT ���̺��� �ش� ���Ҹ� ���������� �ϴ� �ִ� ������ ��

	printf("%d\n",max);
}





//DP�� ����
#include<stdio.h>

int n; 
int DT[10000];
int arr[10000];

int MAX(int a, int b)
{
	return a<b? b:a;
}

void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d",&n);

	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
}


void main()
{
	input();

	//�迭�� ���� �׷����� ����غ���.
	DT[0]=arr[0];
	for(int i=1;i<n;i++)
	{
		DT[i]=MAX(arr[i],DT[i-1]+arr[i]);
	}

	//�Ǽ� �̰� ���� �ƴϴ�. �ֳĸ� ���� ���ڸ� ��� ���ϰ� �ڱⰡ ū ���� �� �� �ֱ⶧���̴�.
	//printf("%d",DT[n-1]);
	
	//�Ǽ�!!! �� �κ� ���Ծ���.
	int max=-987654321; //���� �������� -INF�̴�.
	for(int i=0;i<n;i++)
	if(max < DT[i]) max=DT[i];

	printf("%d",max);
}






//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//////////////////////////////////////////////////////////////////
/*
�κ����̶� n���� ���� �� i��° ���ҷκ��� j��° ���ұ����� �������� ���� �ǹ�
�Ѵ�. (��, 1 <= i <= j <= n) ���� ������ ���� 6���� ���ҷ� �̷���� ������ ��
�ٰ� ��������.
6 -7 3 -1 5 2


�Է�
ù �ٿ� ������ ���� �ǹ��ϴ� ���� n�� �Էµǰ�, ��° �ٿ� n���� ������ ����
���� ���еǾ� �Էµȴ�.
(��, 2 <= n <= 100,000; �� ������ ũ��� -1000���� 1000 ������ �����̴�.)

6
6 -7 3 -1 5 2

��ü �˻� ���� 
*/

//â�� ���� - â�� DP �������� ����
//for 2���� �����غ���.(10�������� ���� �������ѵ� �ʹ� ����.) �̰� ����, ���� Ǯ�̹��� ������.
//���� ���� �׸� ����.
#include<stdio.h>

int n;
int DT[100000];
int input[100000];

void main()
{
	freopen("input.txt","r",stdin);
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	scanf("%d",&input[i]);
	
	
	int max=input[0];
	for(int i=0;i<n;i++)
	{
		DT[i]=input[i];
		for(int j=i;j<n;j++)
		{
			DT[j+1]=DT[j]+input[j+1];
			if(max < DT[j+1]) max=DT[j+1];
		}
	}	
	
	printf("max:%d\n",max);	
}







//��ü �˻�
//3�� for���� ���� ǥ�� �׷������� ���α׷��� �� �ִ�.
// �׳� �Ӹ��ӿ��� ���α׷��� ��ƴ�.

#include<stdio.h>

int n;
int arr[100000];

int main()
{

  freopen("input.txt", "r", stdin);
  scanf("%d",&n);

  for(int i=1; i<=n;i++)
  scanf("%d",&arr[i]);


  int max=arr[1];
  for(int i=1; i<=n;i++)
  { 
	  for(int j=i; j<=n;j++)  
	  {
          //printf("%d %d \n" , i, j);  // �̰� ����غ��� Ʋ�� ��´�.
		  //printf("++++++++++++\n");	 
		  int sum=0;
		  for(int k=i ; k <=j ; k++)
		  {
			  sum=sum+arr[k];
			  printf(" %d " ,k);
		  }

		  if(max < sum) max =sum;

		  printf("\n");
	  }
	 printf("===\n");
  }

  printf("max : %d \n" ,  max);
	
  return 0;
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// ������ ��� Ǯ�� NON DP table
// 21�� ȣ����
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#include<stdio.h>

int n;
int arr[100000];

int arr_times[100];

static int fun_count;

int max(int a, int b)
{
	return  a > b ? a : b;
}

//n�� ������ ���ҷ� �ϴ� �ִ���
//������ ���ҿ�  arrr[n]�� ���̳�, �Ⱥ��̳� �ִ� ���� ã�� ����.
 
int func(int n)
{
	//>> �󸶳� ���� �ߺ�ȣ���� �ǳ�? 
	arr_times[n]++;
	printf(" %d",n );
	//<<
	
	fun_count++;

	if(n==0)
	{
	  return arr[0];  //���� �׸�. �׷� ������ �����ϻ�.
	}
	else
	{
	  return max(func(n-1)+arr[n],arr[n]);
	}
}


int main()
{

  freopen("input.txt", "r", stdin);
  scanf("%d",&n);

  for(int i=0; i<n;i++)
  scanf("%d",&arr[i]);

  int max_value=-987654321;
  for(int i=0; i<n;i++)
  {	 
    int value=func(i);
    if(max_value < value ) max_value = value;
  }  
  printf("answer:%d",max_value);
  printf("func_count:%d",fun_count);

}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// ������ ��� Ǯ��  DP table
//
// 

// 11 �� ȣ����
6
6 -7 3 -1 5 2

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#include<stdio.h>

#define INF 987654321 

int n;
int arr[100000];
int DP_table[100000];

int arr_times[100];

static int fun_count;

int max(int a, int b)
{
	return  a > b ? a : b;
}

//n�� ������ ���ҷ� �ϴ� �ִ���
//������ ���ҿ�  arrr[n]�� ���̳�, �Ⱥ��̳� �ִ� ���� ã�� ����.
 
int func(int n)
{
	//>> �󸶳� ���� �ߺ�ȣ���� �ǳ�? , �и��� �̷� �������� �ߺ��� �ִ�. �̰� DP table�� �ٿ����Ѵ�.
//	arr_times[n]++;
//	printf(" %d",n );
	//<<

	fun_count++;

	if(n==0)
	{
	  return DP_table[0]=arr[0];  //���� �׸�. �׷� ������ �����ϻ�.
	}
	else
	{
	  if(DP_table[n]==-INF)  //  ���� ���ٸ�, �˰����� ���Ƽ� ã�´�.
	  {
	     DP_table[n]=max(func(n-1)+arr[n],arr[n]);
	  }
	}
	
	return DP_table[n];
}


int main()
{

  freopen("input.txt", "r", stdin);
  scanf("%d",&n);

  for(int i=0; i<n;i++)
  {	  
    scanf("%d",&arr[i]);
	DP_table[i]=-INF;
  }
  
  int max_value=-INF;
  for(int i=0; i<n;i++)
  {	 
    int value=func(i);
    if(max_value < value ) max_value = value;
  }  
  printf("answer:%d",max_value);
  printf("func_count:%d",fun_count);

}

