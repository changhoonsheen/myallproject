//â�� ���� ���Ҽ� ������
//���� ������ ������ �ѹ��� Ǯ�� ����


//�Լ� ���� 2��¥�� ����
#include<stdio.h>

int n;
int arr[30];

void f(int k, int sum)
{
	if(sum==n)
	{
		for(int i=0;i<k;i++)
		printf("%d ",arr[i]);

		printf("\n");
		return;
	}

	int l = n-sum; // �Է� ���� n - SUM�� ���� �ĺ����� ó�� ���� �˼� ����.
	for(int i=l;i>=1;i--)
	{
		if(i<=arr[k-1]) //�ĺ����� ���� ���õ� ������ ũ��ȵ�. , �̷��� �����ص���.
		{
			arr[k]=i;
			f(k+1,sum+i);
		}
	}

}


void solve()
{
	for(int i=n;i>=1;i--) //���� ù��° Ʈ���� ���� ��ȣ��. �Լ� �и�
	{
		arr[0]=i;
		f(1,i); //���� �Ǽ���.
	}
}

void main()
{
	scanf("%d",&n);
	solve();
}




//�Լ� ���� 3��¥�� ����
//////////////////////////////


#include<stdio.h>

int n;
int arr[30];

void f(int k, int p, int sum)
{
	if(sum==n)
	{
		for(int i=0;i<k;i++)
		printf("%d ",arr[i]);

		printf("\n");
		return;
	}

	int l = n-sum; // �Է� ���� n - SUM�� ���� �ĺ����� ó�� ���� �˼� ����.
	for(int i=l;i>=1;i--)
	{
		if(i<=p) //�ĺ����� ���� ���õ� ������ ũ��ȵ�.
		{
			arr[k]=i;
			f(k+1,i,sum+i);
		}
	}

}


void solve()
{
	printf("%d\n",n);
	for(int i=n-1;i>=1;i--) //���� ù��° ��ȣ��. �Լ� �и�
	{
		arr[0]=i;
		f(1,i,i); //���� �Ǽ���.
	}
}

void main()
{
	scanf("%d",&n);
	solve();
}






















//�Ʒ��� �׳� ������ �ϵ��� ������ ����
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
///////////////////////////////////////////////////////////

// â�� ���� ����ǰ. ��Ʈ��ŷ ���� ����. ���߿� ������ Ǯ�� ����
// 0. �Ǽ� �κ� �� üũ�ϵ���<���� ���� �κ�>
// 1. Ʈ���� �׷����ߵǰ�, ���� �ε����� ���ð��� ũ�� �ȵȴ�.
// 2. �����˰���� ����ϴ�.
// 3. ����ġ�Ⱑ �����߿��Ѵ�. printf�� �־ ���� ġ�� ������ �ݵ�� ������.!!


#include<stdio.h>

int N;
int arr[30]={0};

static int count;

int min(int a, int b)
{
	return a > b ? b : a;
}

void f(int arr[],int k, int rest,int sum )  // �Լ� �ΰ��� �и��ϴ� ��ũ�� 
{
   // printf("count:%d k:%d rest:%d sum:%d \n" , count,k,rest,sum);

	if(k>N) return;  //  ���� �Ǽ� 
	if(sum>N) return; // �߿��� ����ġ�� ���� ���� Printf�� �־ ����ġ�� ������ �ݵ�� Ȯ���Ѵ�.

	count++;

	if(sum==N)
	{	
		for(int i=0;i<k;i++)
	    {
			printf("%d ",arr[i]);
		}
		printf("\n");

		return;
	}

	for(int i=min(arr[k-1],rest) ; i >= 1 ;i--)
	{
		//if(arr[k-1]<i) continue;  // ���� �Ǽ� 

		arr[k]=i;
		sum+=i;
		f(arr,k+1,rest+i,sum);
		sum-=i;
	}
	
}

void solve(int arr[],int k,int n)  // �Լ� �ΰ��� �и��ϴ� ��ũ�� 
{
		for(int i=n;i>=1;i--)
		{	 
			 arr[k]=i;
			 f(arr,k+1,N-i,i);  // rest �κ� �Ǽ� 
		}
}

void main(void)
{


   freopen("output.txt","w",stdout);
	scanf("%d",&N);

	
	solve(arr,0,N);

//	printf("count :%d\n",count);
}

//////////////////////////////////////////////////


/*
�� ��ǰ.!

ù° �Ʒ��� ���� ���踦  ã�� ���ߴ�.
���ΰ��� ���踦 �����.!  �� ����. �̤�

1. ���踦 �����Ѵ�.
f(n,k)  // k������ �ڿ����� n�� ����� ����� �� 

f(n,k) = f(n-1,1) + f(n-2,2) + f(n-3,3) ....  + f(n-k,k)
       = 1�� ���� + 2�� ���� + 3�� ����  .... 5�� ���� 

2. Ʈ���� �׷� ����.
��Ʈ��ŷ���� �����ϱ� ���ؼ� Ʈ���� �׸��°� �߿��ϴ�.

3. ��Ģ�� ã�� �� �ִ��� Ȯ���Ѵ�.

4. ����� ���� ������ �����Ѵ�.

5
4 1
3 2
3 1 1
2 2 1
2 1 1 1
1 1 1 1 1

*/

#include<stdio.h>

int str[30];  // ����� ����� �迭
int cnt;      // ����� ���� 

/*
f(n,k)  // k������ �ڿ����� n�� ����� ����� �� 
f(n,k) = f(n-1,1) + f(n-2,2) + f(n-3,3) ....  + f(n-k,k)

*/

int min(int a, int b)
{
 return a > b ? b : a;
}

void solve(int n , int k , int p)
{
	if(n==0)
	{
		for(int i=0; i< p ; i++)
		printf("%d ",str[i]);
	
	    printf("\n");
		return;
	}
	
	for(int i=min(n,k) ; i >= 1 ; i--)
	{
	  str[p]=i; // �� ��� �˾� ������  // �������� �� ����� ����� �� �ִ�.
	  solve(n-i,i,p+1);  // ���� ���� ���� �Ʒ� �ܰ�� p
	}	
	
}
	   
void main()
{
	int n;
	scanf("%d",&n);
	solve(n,n,0);
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//���� Ǯ�� 

/*
partitioned ���� 
*/

#include<stdio.h>

int a[30], cnt;
int count;

int min(int a, int b)
{
	return a>b ? b : a;
}


void solve(int n,int k)
{
	if(n==0)
	{
		for(int i=0; i< cnt; i++)
		{
			printf("%d",a[i]);
		}
		count++;
		printf("\n");
		return;
	}

	for(int i=min(n,k) ; i>=1 ; i--)

	{	
		a[cnt++]=i;
		solve(n-i,i);
		cnt--;
	}
}

void main(void)
{
	int n;
	scanf("%d",&n);
	solve(n,n); // k������ �ڿ����� ������ n�� ����� �ִ� ����� ��

	printf("count:%d\n",count);
}