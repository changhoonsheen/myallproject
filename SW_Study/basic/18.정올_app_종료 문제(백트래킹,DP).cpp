/*
app ���� ���� 
*/
//��
//â��ǰ , ���� ���� �Ӹ� �ӿ� ���������� �ڵ�. ����!
// Cost�� �����ؼ� DT ���̺� ������� �����غ���.
// DT ���̺� ����� ����ϰ� ���������� �� Ǯ����. �ٽ� Ǯ�� ������.!
/*
5 60
30 10 20 35 40
3 0 3 5 4
->6

20 600
30 100 20 35 40 30 100 20 35 400 30 100 20 35 40 30 100 20 35 40
3 2 3 5 4 7 4 3 5 4 3 3 3 5 4 3 2 3 5 8
->8

20 754
30 100 20 35 40 30 100 20 35 400 30 100 20 35 40 30 100 20 35 40
3 2 3 5 4 7 4 3 5 4 3 3 3 5 4 3 2 3 5 8
->15


20 754
30 100 20 35 40 30 100 20 35 400 30 100 20 35 40 30 100 20 35 40
0 0 5 0 7 4 3 5 4 0 0 3 0 4 3 2 3 5 8 0
->3
*/


#include<stdio.h>

#define INF 987654321

int N;
int M;

int mi[100];
int ci[100];

int fun_call;

int DT[100][10000];


void input()
{
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &mi[i]);
	}

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &ci[i]);
	}

}

int MIN(int a, int b)
{
	return a > b ? b : a;
}

int solve(int i , int r)
{
	if (DT[i][r] != -1) return DT[i][r];

	fun_call++;

	if (i == N + 1)
	{
		if (r >= M) return DT[i][r]=0;
		else return DT[i][r]=INF;
	}

	return DT[i][r] = MIN(solve(i + 1, r + mi[i]) + ci[i], solve(i + 1, r));
}

void main()
{
	input();

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 10000; j++)
			DT[i][j] = -1;

	printf("%d\n", solve(1, 0));
	printf("%d\n", fun_call);
}


////////////////////////////////
// ���õ� app �����ϱ� 
////////////////////////////////


#include<stdio.h>

#define INF 987654321

int N;
int M;

int mi[100];
int ci[100];

int fun_call;

int DT[100][10000];

int item[10000];

void input()
{
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &mi[i]);
	}

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &ci[i]);
	}

}

int MIN(int a, int b)
{
	return a > b ? b : a;
}

int solve(int i, int r)
{
	if (DT[i][r] != -1) return DT[i][r];

	fun_call++;

	if (i == N + 1) // ��� app�� ��������� 
	{
		if (r <= 0) return DT[i][r] = 0;  // �޸𸮸� Ȯ��������
		else return DT[i][r] = INF;       // Ȯ�� �������� 
	}

	int a = solve(i + 1, r - mi[i]) + ci[i];
	int b = solve(i + 1, r);

	if (a < b)
	{
		item[r] = i;  //�ش� �޸� r�� �������� ���� ���õǾ����� �����ϱ� 
		DT[i][r] = a;
	}
	else
	{
		DT[i][r] = b;
	}

	return DT[i][r];

	//return DT[i][r] = MIN(solve(i + 1, r + mi[i]) + ci[i], solve(i + 1, r));
}

void main()
{
	input();

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 10000; j++)
			DT[i][j] = -1;

	printf("%d\n", solve(1, M));
	printf("%d\n", fun_call);

	//���õ� app �����ϱ� 
	for (int s = M; s > 0; s=s - mi[item[s]])
	{
		printf("selected app : %d\n", item[s]);
	}

}















////////////////////////////////////
//â�� �ʱ� �Ϲ����� Backtracking��� 
//ó�� ���� �ܼ��� ����� ����ġ�� , �׸��� ���õ� app ã�� ����
#include<stdio.h>

#define SIZE 100

int n; // app�� ����
int M; // �ʿ���ϴ� �޸�
int m[SIZE];
int c[SIZE];

int func_count;

//���õ� app�� �˱����ؼ�
int checked[SIZE];
int result_checked[SIZE]; 

int min_cost=987654321;

void f(int i,int r,int cost)
{

	if(cost>= min_cost) return; 

	func_count++;
	if(i==n+1)
	{
		if(r<=0)
		{
			if(min_cost > cost)
			{
				min_cost=cost;

				for(int i=1;i<=n;i++)
				result_checked[i]=checked[i];
			}
		}
		return;
	}
	
	 checked[i]=1;
	 f(i+1,r-m[i],cost+c[i]); 
	 
	 checked[i]=0;
	 f(i+1,r     ,cost);

}


void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d %d",&n,&M);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m[i]);
	}
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
}


void main()
{
	input();
    f(1,M,0);
	printf("min_cost:%d\n",min_cost);
	printf("func_count:%d\n",func_count);


	printf("Selectd app : ");

	for(int i=1;i<=n;i++)
	{
      if(result_checked[i]==1) printf(" %d",i);
	}
	
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//â�� ���� �ʱ���. ��ȯ�� ���� 
#include<stdio.h>

//app�� ����
#define SIZE 100

int n; // app�� ����
int M; // �ʿ���ϴ� �޸�
int m[SIZE];
int c[SIZE];

int func_count;

int DT[100][100000];

//�� DT ���̺��� ��ƾ� ������ ũ�⸦ �ʰ���. ������ ����.
//�׷��� �̹����� �ٽ� ����Ʈ�� �� �κ��̴�.
//int DT[100][10000000];

//
int MIN(int a, int b)
{
	return a > b ? b : a;
}


int f(int i,int r)
{
	   if(DT[i][r]!=-1) return DT[i][r];

		if(i==n+1)
		{
			if(r<M) // �ٴڱ��� �� ���¿��� �޸𸮸� Ȯ������ ������. 
			{       // �ش� ��带 �������� ���ϰ� ��.
				return DT[i][r]=987654321;
			}
	
			//�Ϲ����� �ٴ��� ��� 0���� �÷��� Cost�� ���ؼ� �����ϰ� ��.
			return DT[i][r]=0;
		}

	
#if 1  // ������ �̰� ����ġ�� �����̴�. �� ���Ƶ� ����� ����.  Ȯ���� �ȵǾ��ٸ� �̰� �����ص� �ǰ� ���ص� �ǰ�,
		if(r<M) //�� ������ �ʿ��ϴٸ�, -> �̶� �ش� ��带 �����Ҽ��� �ְ� ���� ���� �ִ�.
		 return DT[i][r]=MIN( f(i+1,r+m[i])+c[i], f(i+1,r) );
		else   // �̹� �뷮Ȯ���� �� ���������� �׳� �Ѿ��.   
		 return DT[i][r]=f(i+1,r) ;	
#else  // ���ϴ� �뷮 �̻��� Ȯ���ϸ��.
		return DT[i][r]=MIN( f(i+1,r+m[i])+c[i], f(i+1,r) );
#endif

}


void input()
{
	freopen("input.txt","r",stdin);
	
	scanf("%d %d",&n,&M);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m[i]);
	}
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
}


void main()
{
	input();

	//�ʱ�ȭ
	//�޸� �뷮�� ��������� �����Ҷ� j�� ������ �ɼ��� �ִ�.�����ض�!!
	//�޸� �뷮�� DT ���̺��� ����ϱ� ���ؼ� ��������� �÷����Ѵ�.!! â�� �Ǽ� �ߴ�.
	for(int i=0; i<=100; i++)
	for(int j=0 ;j<=100000;j++)
	{
		DT[i][j]=-1;
	}

	printf("%d",f(1,0));
}


/////////
//3.DP Ǯ�� â�� �ʱ� ����ǰ.
//�Ҽ��ִ�.!!

//â���ʱ� ����ǰ.
//����� ���

#include<stdio.h>

//app�� ����
#define SIZE 100

int n; // app�� ����
int M; // �ʿ���ϴ� �޸�
int m[SIZE];
int c[SIZE];

//�׷��� ���⼭ ���ǿ��� 1000,0000�� ��ƾ�������, �Ұ���
int DT[SIZE][1000000];

//�� DT ���̺��� ��ƾ� ������ ũ�⸦ �ʰ���. ������ ����.
//�׷��� �̹����� �ٽ� ����Ʈ�� �� �κ��̴�.
//int DT[100][10000000];

//
int MIN(int a, int b)
{
	return a > b ? b : a;
}


void input()
{
	freopen("input.txt","r",stdin);
	
	scanf("%d %d",&n,&M);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m[i]);
	}
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
}


void main()
{
	input();

	//0��°�� ������ ���ǿ����� INF�� 
	for(int j=1 ;j<=M; j++)
	{
		DT[0][j]=987654321;
	}


	//���̺��� �׷����� ��ȭ���� ������Ѵ�.
	for(int i=1;i<=n;i++) //����ؾ��� app.
	{
		for(int j=1;j<=M;j++) //�޸��� ���� ������ �����ұ�? ���ǿ��� ���������� �����ؾ���.
		{
			if(m[i]>=j){ 
				DT[i][j]= MIN(c[i], DT[i-1][j]);
			}			
			else
			{
			  DT[i][j]= MIN( DT[i-1][j-m[i]]+c[i],DT[i-1][j])  ;
			}
			
		}
	}

	printf("%d",DT[n][M]);
}


/////////////////////////
//DP ���ǿ��� �ٲ� -> ���� �Ϻ�Ǯ��
////////////////////////
//â���ʱ� ����ǰ.
//����� ���, ���ǿ��� �ٲ㺸��
/*
DT[i][j] : 1~i app ���� ���������, �ش� ���(j)�� �̿��ؼ� Ȯ���� �� �ִ� �ִ� �޸𸮾�. 
*/

#include<stdio.h>

//app�� ����
#define SIZE 100

int n; // app�� ����
int M; // �ʿ���ϴ� �޸�
int m[SIZE];
int c[SIZE];

//���ǿ��� ������ �ٲ�.
//�׷��� ���⼭ ���ǿ��� 1000,0000�� ��ƾ�������, �Ұ���
int DT[SIZE][1000000]; // app���� * max cost

//
int MAX(int a, int b)
{
	return a > b ? a : b;
}


void input()
{
	freopen("input.txt","r",stdin);
	
	scanf("%d %d",&n,&M);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m[i]);
	}
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
}


void main()
{
	input();


	//���̺��� �׷����� ��ȭ���� ������Ѵ�.
	for(int i=1;i<=n;i++) //����ؾ��� app.
	{
		for(int j=0;j<=(n*100);j++) //����� ���� ������ �����ұ�? ���ǿ��� ���������� �����ؾ���.
			                       //���� �Ǽ� ���� ����� 0���� �����ؾ���.
		{
			if(c[i]<=j){ 
				DT[i][j]= MAX(DT[i-1][j-c[i]]+m[i], DT[i-1][j]); //��� �ؾ��� �� �������� �޸𸮸� Ȯ���ϴ�?
			}			
			else
			{
				DT[i][j]=DT[i-1][j];
			}
			
		}
	}

	int value=n*100;
	for(int j=1;j<=(n*100);j++)
	{
		if( M <= DT[n][j] )
		{
			value=j;
			break;
		}
	}

	if(value == n*100)
	{
		printf("No answer\n");
	}
	else
	{
		printf("%d",value);
	}
		
	
}






























//�Ʒ��� �׳� �������ϰ� ���� �͸� ��.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include<stdio.h>

int N;
int M;

int m[100];
int c[100];

int checked[100];

int min_cost=987654321;

static int func_call;

void solve(int memory, int cost)
{
	
	if(cost >= min_cost) return;

	func_call++;

	if(memory>=M)  // �Ѿ� ������ �ִ�. ����? �� �´�.
	{
		if(min_cost>cost) min_cost=cost;
		return;
	}

	for(int i=0;i<N;i++)
	{
		if(checked[i]==0) //�̷��� �ĺ����� ���Ҽ��� �ִ�. 
		                  //������, �ϳ��� �����ۿ� ���ؼ� �������� �ʰ�/�������� ���� �� ������ �������� �ִ�.
                          //���� ����� ���� ������.						  
		{	
			checked[i]=1;
			solve(memory+m[i] ,cost+c[i]);
			checked[i]=0;
		}
	}
}

void main()
{
	freopen("input.txt","r",stdin);
	
	scanf("%d %d",&N,&M);

	for(int i=0;i<N;i++)
	{
		scanf("%d",&m[i]);
	}

	for(int i=0;i<N;i++)
	{
		scanf("%d",&c[i]);
	}

	solve(0,0);

	printf("%d\n",min_cost);
	printf("func_call:%d\n",func_call);
}

///////////////////////////////////////////

//��

//DT ���̺� ������

//�߿��� ���� 

//1.
//Ž���� ��� app�� ����ؾ��Ѵ�.
//2.
//���鼭 r�� 0�� �ɼ����ִ�. �̶� ������ ���Ѵ�.!
//3.
//�⺻���� ��ƾ�� �ش� app�� ������ �Ѵ�/ ���Ѵ�. ���⼭ �ּҴ�.

/*
5 60
30 10 20 35 40
3 0 3 5 4
*/

#include<stdio.h>

int N;
int M;

int m[100];
int c[100];

//int DT[100][10000000]; // �̷��� ����´�, DT ���̺��� ��� ���� ����??

int MAX=987654321;
int min_cost;

static int func_call;

int MIN(int a, int b)
{
	return a>b ? b : a;
}

int solve(int i, int r)
{

 // printf("i:%d r:%d\n",i,r);
	func_call++;

if(i==N) //��� app�� �� �����ߴ�.!! ������ �ͼ�  < �Ǽ�!!! �� �κ� �� ���� �´�. >
{
	if(r>0) return MAX;  // �޸𸮰� Ȯ���� �ȵƴ�. �̰� �ذ� �ƴϴ�. ���� �ø��� ������ �ȵǰ��Ѵ�.
	else return 0;       // �޸𸮰� Ȯ���� �ƴ�. �ϴ� �ر� �ϴ�.!!
}
		
if(r<0)  // ���� ��忡�� �ʿ��� �޸𸮰� ���ٸ�, �������� ����. // �Ǽ�!! �� ��� 
 return solve(i+1,r);  // �� ����ġ�� ��� ��� ����. ���귮�� ������ ��ġ��, r�� �����̸� DT ���̺� ���� ����.
else
 return MIN(solve(i+1,r),solve(i+1,r-m[i])+c[i]);

}

void main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	scanf("%d %d",&N,&M);

	for(int i=0;i<N;i++)
	{
		scanf("%d",&m[i]);
	}

	for(int i=0;i<N;i++)
	{
		scanf("%d",&c[i]);
	}

	min_cost=solve(0,M);

	printf("%d\n",min_cost);
	printf("func_call:%d\n",func_call);
}


////////////////////////////////////////////////

#include<stdio.h>

int N;
int M;

int m[100];
int c[100];

int MAX=987654321;
int min_cost;

static int func_call;

int MIN(int a, int b)
{
	return a>b ? b : a;
}

int solve(int i, int r)
{

//printf("i:%d r:%d\n",i,r);
	func_call++;

if(i==N) //��� app�� �� �����ߴ�.!! ������ �ͼ�  // �Ǽ�!!! �� �κ� �� ���� �´�.
{
	if(r>0) return MAX;  // �޸𸮰� Ȯ���� �ȵƴ�. �ذ� �ƴϴ�. ���� �ȵǰ��Ѵ�.!!
	else return 0;       // �޸𸮰� Ȯ���� �ƴ�. �ϴ� �ر��ϴ�.!!
}
		
if(r<0)  // ���� ��忡�� �ʿ��� �޸𸮰� ���ٸ�, �������� ����. // �Ǽ�!! �� ���  ���� ���´�.
 return solve(i+1,r);  // �� ����ġ�� ��� ��� ����. ���귮�� ������ ��ġ��, r�� �����̸� DT ���̺� ���� ����.
else
 return MIN(solve(i+1,r),solve(i+1,r-m[i])+c[i]);

}

void main()
{
	freopen("input.txt","r",stdin);
	
	scanf("%d %d",&N,&M);

	for(int i=0;i<N;i++)
	{
		scanf("%d",&m[i]);
	}

	for(int i=0;i<N;i++)
	{
		scanf("%d",&c[i]);
	}

	min_cost=solve(0,M);

	printf("%d\n",min_cost);
	printf("func_call:%d\n",func_call);
}


///////////////////////////////////////////////////////////////
/*
DT ���̺� â�� �ӽ�����
20 754
30 100 20 35 40 30 100 20 35 400 30 100 20 35 40 30 100 20 35 40
3 2 3 5 4 7 4 3 5 4 3 3 3 5 4 3 2 3 5 8
->15
2090�� ȣ��
*/

#include<stdio.h>

int N;
int M;

int m[100];
int c[100];

int DT[100][100000]; // �̷��� ����´�, DT ���̺��� ��� ���� ����?? ������ ���ǿ��� �ʰ���. AD���� �ذ�å����

int MAX=987654321;
int min_cost;

static int func_call;

int MIN(int a, int b)
{
	return a>b ? b : a;
}

int solve(int i, int r)
{

 if(DT[i][r]!=-1) return DT[i][r];
 
 //printf("i:%d r:%d\n",i,r);
	func_call++;

if(i==N) //��� app�� �� �����ߴ�.!! ������ �ͼ�  < �Ǽ�!!! �� �κ� �� ���� �´�. >
{
	if(r<M) return  DT[i][r]=MAX;  // �޸𸮰� Ȯ���� �ȵƴ�. �̰� �ذ� �ƴϴ�. ���� �ø��� ������ �ȵǰ��Ѵ�.
	else return DT[i][r]=0;       // �޸𸮰� Ȯ���� �ƴ�. �ϴ� �ر� �ϴ�.!!
}
		
if(r>M) 
 return DT[i][r]=solve(i+1,r); 
else
 return DT[i][r]=MIN(solve(i+1,r),solve(i+1,r+m[i])+c[i]); // DT ���̺� �����ϱ� ���ؼ� ������ �ٲ�.,�Ϻ��� Ǯ�̰� �ƴ� ���ǿ� ������ ���.

}

void main()
{
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
	scanf("%d %d",&N,&M);

	for(int i=0;i<N;i++)
	{
		scanf("%d",&m[i]);
	}

	for(int i=0;i<N;i++)
	{
		scanf("%d",&c[i]);
	}

	//-1�� DT ���̺� �ʱ�ȭ
	for(int i=0; i< 100; i++)
		for(int j=0;j<100000;j++)
			DT[i][j]=-1;

	min_cost=solve(0,0);

	printf("%d\n",min_cost);
	printf("func_call:%d\n",func_call);
}





















///////////////////////////////////////////////////////////////

//���� Ǯ��
#include<stdio.h>
#define MAXV 99999

int M,n,i,m[101],c[101];

int min(int a, int b) {return a<b ? a:b;}

//1~i ������ app�� ��������� �䱸�ϴ� �޸𸮰� r�� ����� �ּ� ��� 
int f(int i, int r)
{
 if(i==0) //�ٴڱ��� �Դٸ� 
 {
    if(r<=0) return 0;
	else return MAXV;
 }
 else if(r<=0)   f(i-1,r);  // �ٴڱ��� �������� ��� �޸𸮸� Ȯ���ߴٸ�, ���� I��° APP �� �������� ����.  
                            // r<=0�� �� ���� �ʳ�? 0�̸� �̹� �޸𸮸� �� Ȯ���� �����ε�, ���� Ǯ�̰� �̻��Ѱ� ����.  
	  else min( f(i-1,r) , f(i-1,r-m[i])+c[i] );
}

int main()
{
 freopen("input.txt","r",stdin);
 scanf("%d %d",&n,&M);
 for(i=1;i<=n;i++) scanf("%d",&m[i]);
 for(i=1;i<=n;i++) scanf("%d",&c[i]);
 printf("%d",f(n,M));
 return 0;
}