//â�� ����ǰ ���� Ǯ�� �� �ʱ�
//�ʱ� ��Ʈ�� �˰����� ����.




//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#include<stdio.h>

int N;
int K;

void input()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	//scanf("%d",&N);
	//scanf("%d",&K);
}

int f(int n, int k,int first)
{

//����� �� Base�ϰ� ���� Base�� ����.
#if 1   // â�� Base
	if(k==K) return 1;
	if(first &&  n > N-1) return 0;
	if(!first && n > N ) return 0;
#else   //���� Base
   if( n >= N+1 || k==K)
   {
	   return (int)( k==K && (!first || n <= N+1) );
   }
#endif

	return f(n+1,k,first) + f(n+2,k+1,first); // ó���� ���� �������� + ó���� ����������
}

void main(void)
{
    	input();

	 // N (4<=n<=1,000)
	//  K (1<=k<=n)

	for(int i=4;i<20;i++)
    for(int j=1;j<20;j++)
	{
		printf("n:%d k:%d=",i,j);		
		N=i;
		K=j;
		printf("%d\n",f(2,0,0) + f(3,1,1));
	}
}

//////////////////////////////////////

#include<stdio.h>
#define MOD 1000000003

int N;
int K;

int DT[1000][1000][2];

int f(int n, int k,int first)
{
	if(DT[n][k][first]!=-1) return DT[n][k][first]%MOD ;
	
	if(k==0) return DT[n][k][first]=1%MOD;
	else if(first && N-2 < n) return DT[n][k][first]=0%MOD;  // ���⸦ ������ �� �ְ� �������. base ��ġ �ٽ��ѹ� �����غ���. N-2 <= n �̷��� �����ؼ� ���� �ȳ���
		 if(!first && N-1 < n) return DT[n][k][first]=0%MOD; // ���⸦ ������ �� �ְ� �������. N-1<=n �̷��� �����ؼ� ���� �ȳ���
	
	//�Ʒ� ��ȭ�� ��ƾ�� ���ؼ�
	return DT[n][k][first]=(f(n+2,k-1,first)+f(n+1,k,first))%MOD;
}

void main()
{
	N=5;
	K=2;
	
	for(int i=0;i<1000;i++)
		for(int j=0;j<1000;j++)
			for(int p=0;p<2;p++)
				DT[i][j][p]=-1;
	
	//�Ʒ� �ΰ��� ��쿡�� ���� �����Ѵ�.
	int result1=f(2,K-1,1); //���� ó���� �����Ѵٴ� ���� 2�� �����ϰ�(0���� ����������), �����ؾߵ� ���� �ϳ� ���̰� , ó���� ǥ���Ѵ�. 
	int result2=f(1,K,0);   //���� ó���� ���� ���Ѵٴ� ���� 1�� ����ȣ�� �׳� K�� ������ ó���� �ƴѰ��� ǥ����.
	printf("%d",(result1+result2)%MOD);
}








//���� �˰���
#include<stdio.h>

int N;
int K;

void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d",&N);
	scanf("%d",&K);
}

int f(int n, int k,int first)
{
	printf("n:%d k:%d first:%d\n",n,k,first);


   if( n >= N+1 || k==K)
   {
	   return (int)( k==K && (!first || n <= N+1) ); // ������ firstó���� �̷��� �Ǵ°� �ͺ��ϰ� ���ذ� ���� ����.
   }


	return f(n+1,k,first) + f(n+2,k+1,first); // ó���� ���� �������� + ó���� ����������
}

void main(void)
{
	input();
	//(4<=n<=1,000), (1<=k<=n)

	printf("%d",f(2,0,0) + f(3,1,1));

}





