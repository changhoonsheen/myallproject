




//����� DT ���̺�
#include<stdio.h>

int func_call;
int DT[1000];

//�Ž�����,�ֽ������ϰ� ����� �˰���

int solve(int steps)
{

if(DT[steps]!=-1) return DT[steps];

func_call++;

if(steps==0) 
{
	return  DT[steps]=1;
}

int a=0;
int b=0;

if(steps-1>=0)
a=solve(steps-1);  

if(steps-2>=0)
b=solve(steps-2);

return DT[steps]=a+b;
}


void main()
{
    int steps=20;
	
	for(int i=0;i<=steps;i++)
	DT[i]=-1;

	printf("%d\n",solve(steps));
	printf("func_call:%d\n",func_call);
}












//�����
//â�� ���� �ʱ�
//��ܿ����� , ���� �����ϰ� Backtracking �غ��� DT ���̺� �����غ���

#include<stdio.h>

int count;
int n;

int func_count;

unsigned _int64 DT[1000];

unsigned _int64 solve(int k)
{
	if(DT[k]!=-1) return DT[k];

	func_count++;

	if(k>=n)
	{
		if(k==n) return DT[k]=1;
		return DT[k]=0;
	}

	return DT[k]=solve(k+1)+solve(k+2);
}

void main()
{
	scanf("%d",&n);

	for(int i=0;i<1000;i++)
	{
		DT[i]=-1;
	}

	printf("%I64d\n",solve(0));
	printf("func_count:%d\n",func_count);
}
//�Ϲ� ��Ʈ��ŷ ���� 
//�׷��� ��� n�� 40���ǵ� ����� ������ �ʴ´�.
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


#include<stdio.h>

int count;
int n;

void solve(int k)
{
	if(k>=n)
	{
		if(k==n) count++;
		return;
	}

	solve(k+1);
	solve(k+2);
}

void main()
{
	scanf("%d",&n);
	solve(0);
	printf("%d",count);
}


