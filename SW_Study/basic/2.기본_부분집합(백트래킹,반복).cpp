
//â�� ����
//��Ʈ �ʱ⸦ ����, 1. �ݺ����� ���� ���, 2. Backtracking�� ���� ����� �˾� ������ 

#include<stdio.h>

#define SIZE 4
int arr[SIZE]={10,20,30,40}; // ����迭 

int a[SIZE];

void backtracking(int k)
{


if(k==SIZE)
{
	printf("{ ");
	for(int i=0;i<SIZE;i++)
	{
		if(a[i]) printf("%d ",arr[i]);
	}
	printf("}\n");
	return;
}


a[k]=0;
backtracking(k+1);

a[k]=1;
backtracking(k+1);

}

void main()
{
	backtracking(0);
}





/////////////////////////////////////////////////////////////////

//�ݺ����� �̿�
#include<stdio.h>

int a[5]={100,200,300,400,500};


void main()
{
	int n=sizeof(a)/sizeof(int);//�迭��ũ��
	
	for(int i=0;i<(1<<n);i++)
	{
		printf("{ ")
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j)) printf("%d",a[j]);
		}
	    printf(" }")
		
	}
}


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//�׸��� �׷����� ���ذ� ����
//backtracking

#include<stdio.h>

int DATA[5]={100,200,300,400,500};
static int count;

void solve(int a[] , int k , int n)
{

 if(k==n-1)
 {
	printf("%d : { ",count++); 
	 for(int i=0;i<n;i++)
	 {
		 if(a[i]==1)
		 printf(" %d",DATA[i]);
	 }
	printf(" }\n");
	
	return;
 }

 k++;
 
 a[k]=0;
 solve(a,k,n);

 a[k]=1;
 solve(a,k,n);

}

void main()
{
	int a[5]={0,};
	int n=sizeof(a)/sizeof(int);//�迭��ũ��
	
	solve(a,-1,n);
	
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// ����ġ�� 
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#include<stdio.h>

int arr[]={1,2,3,4,5,6,7,8,9,10};

static int func_call;

void solve(int a[],int k, int n)
{

if(k==n-1)
{

	int sum=0;

	for(int i=0;i<n;i++)
	{
	  if(a[i]) {
				   // printf("	%d",i);
				   sum+=arr[i];
			   }
	}

	
	if(sum==10)
	{
	  printf("{ ");
	  for(int i=0;i<n;i++)
	  {
		if(a[i]) {
	    printf(" %d",arr[i]);
		}
	  }
	  printf(" }\n");
	}

return;
}

// �κ��� ����ġ�� 
#if 1  // �̷��� ������ ������ ����� �����ϱ� �����̴�.
    int temp_sum=0;
	for(int i=0;i<k;i++)  // a �迭�� ���� �迭�̱� ������ n ���� ����ϸ� �����Ⱑ ��� ����. 
	{                     // �� �κ� �Ǽ��ߴ�. <���������� ���� a �迭�� ������ k�� �̿��߾���.>
		if(a[i]) { 
				   // printf("	%d",i);
				   temp_sum+=arr[i];
			   }
	}

	if(temp_sum > 11) return;  // 10�� ��� ���Ѿ��Ѵ�.
#endif


func_call++;


k++;
a[k]=0;
solve(a,k,n);  // �Ǽ� k+1;

a[k]=1;
solve(a,k,n);


}

void main()
{
 int a[10]={0};
 int n=10;


 solve(a,-1,n);
 printf("func_call : %d \n",func_call);

}