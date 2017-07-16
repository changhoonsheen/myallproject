

//â�� ���� �ʱ�

#include<stdio.h>

int n;
int mod;
int DT[100000];

int func_call;

void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	scanf("%d",&mod);
}

//data�� ���ǿ� �Ѱ�ġ�� 100000�� (10000�Ǹ��ص� Stack overflow�� �߻�) ���� �Ǹ� ���� �ȳ���. Stack overflow�� �߻���.
//�׷��� �����ϴٰ� �����ϴ� �� �������� �ٲ۴�.
#if 1  //����� ����
int f(int i)
{
	if(DT[i]!=-1) return DT[i];

	func_call++;

	if(i==1) return DT[i]=1%mod;
	if(i==2) return DT[i]=3%mod;
	
	return DT[i]=(f(i-1) + 2*f(i-2))%mod;
}

#else //����� ���谡 �ʿ���. �����ϴٸ� ����� ������� ���ߵ�.

int f(int i)
{

	DT[1]=1%mod;
	DT[2]=3%mod;
	
	for(int i=3;i<=n;i++)
    DT[i]=(DT[i-1] + 2*DT[i-2])%mod;

	return DT[n];
}

#endif


void main()
{
 input();

 for(int i=0;i<100000;i++)
	 DT[i]=-1;

 printf("%d\n",f(n)%mod);
 printf("func_call:%d\n",func_call);
}





























/////////////////////////////////////////////////////////////////////////////
//+


/*
Ÿ�� ä���
2x1 1x2 2x2 �� ���簢���� �̿��ؼ� 2xN Ʋ�� �ִ� ����� �� 

1.
����� ����, <�θ޶�>

2. �Ʒ��� ���� ����

f(n) = f(n-1)   .....   �ٷ� �ذ��� ��ʱ��� ���� ��.
�߿�! �������� �� �� �ִ� Ÿ���� ������  n�� 1�ϰ�� n�� 2�ϰ�� ���ִ�.

f(1) = 1
f(2) = 3 

�Ʒ� 3���� �������� �������� ���������� ����� �� �ִ� Ÿ���� 3���� �̴�.

2x1

1x2

2x2

(1<=n<=100,000, 1<=m<=40,000)



>>>>>>>>>>>>>>>

f(n) = f(n-1) + 2f(n-2) 


f(3) = f(2) + 2 f(1) 

ù �ٿ��� ���簢�� Ʋ�� ���� ���� n�� �־�����.
��° �ٿ��� m�� �־�����. (1<=n<=100,000, 1<=m<=40,000)
 
����� ������

20
10000

9051  -> answer
13529  -> fun cnt


*/
#include<stdio.h>

int mod;  // ���ڰ� Ŀ����� ������ ��
int n;

int array_count[100];

int f(int n)
{
	array_count[n]++;
	
	if(n==1) return 1%mod;
	else if(n==2) return 3%mod;
	else
	{
		return  ( f(n-1) + 2 * f(n-2) ) %mod;
	}
}

int main()
{

  freopen("input.txt", "r", stdin);
  scanf("%d",&n);
  scanf("%d",&mod);

  printf("%d" , f(n) % mod);
}


/////////////////////////////////////////
// �ߺ� ȣ���� ���̱� ���ؼ� DP ���̺��� �̿���.
/////////////////////////////////////////



20
10000

9051  -> answer
51  -> fun cnt


//�� �˰����� n�� 10000�� �Ǹ� ����
//���� �Է��� �� ���� ����


/////////////////////////////////////////

#include<stdio.h>

int mod;  // ���ڰ� Ŀ����� ������ ��
int n;

//int array_count[100000];
int DT[100000];
static int fun_count;

int f(int n)
{
	//array_count[n]++;  // ���� ������ �����͸� ������ �ߺ��� �󸶳� �Ͼ���� Ȯ�ΰ��� 
	
	fun_count++;

	if(n==1) return DT[n]= (1%mod);
	else if(n==2) return DT[n]=(3%mod);
	else
	{
		if(DT[n]==0) DT[n] = ( ( f(n-1) + 2 * f(n-2) ) ) %mod;
	}
	
	return DT[n];
}

int main()
{

  freopen("input.txt", "r", stdin);
  scanf("%d",&n);
  scanf("%d",&mod);

  printf("answer:%d\n" , f(n) % mod);
  printf("fun count : %d", fun_count);
}

/////////////////////////////////////////////
// ��������� ��ȭ��+�ݺ������·� ǥ����.
// ���� �˰��� �����̱⵵ ��.
/////////////////////////////////////////////


#include<stdio.h>

int mod;  // ���ڰ� Ŀ����� ������ ��
int n;


int DT[100000];
static int fun_count;

int main()
{

  freopen("input.txt", "r", stdin);
  scanf("%d",&n);
  scanf("%d",&mod);
  
  DT[1]=(1%mod);
  DT[2]=(3%mod);
  
  for(int i=3; i<=n;i++)
	   DT[i]=( DT[i-1] + 2 * DT[i-2] )%mod;

  printf("answer:%d\n" ,DT[n]);

}


/////////////////////////////////////////////
// �������� ����� ���߿� AD ���� ���ô�....
/////////////////////////////////////////////

