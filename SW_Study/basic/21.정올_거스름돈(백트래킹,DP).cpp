
//â�� ���� �ʱ�


/*
//DT ���̺긦 ������� ������ �� �����ʹ� ���� ������ �ʴ´�.
9820
7
10 15 20 50 100 400 500



730
5
10 50 100 500 1250
�� 6


570
7
10 50 100 500 1000 5000 10000
�� 4

*/

/*
/*
730 5
10 50 100 500 1250
*/



// DT ���̺��� �̿��� ����� ���
// ���� ���� �ٿ�����.  ���� �ֽ� �����ϰ� ����ϴ�.

#include<stdio.h>

int m;
int n;
int coins[10];
int DT[20000];

void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d %d",&m,&n);

	for(int i=0;i<n;i++)
	{
		scanf("%d",&coins[i]);
	}

}

int MIN(int a, int b)
{
	return a > b ? b : a;
}

int f(int total)
{
	if(total==0) return DT[total]=0; //�Ǽ� Base ó��!!
	if(DT[total]!=-1) return DT[total];

	int min_value=987654321;
	for(int i=0;i<n;i++)
	{
	 if(total-coins[i]>=0) min_value=MIN(min_value,f(total-coins[i])+1);
	}

	return DT[total]=min_value;
}

void main(void)
{
input();

for(int i=0;i<=10000;i++)
{
	DT[i]=-1;
}

printf("%d\n",f(m));

}
*/


//���� �⺻ ��Ʈ��ŷ Ǯ��
#include<stdio.h>

int m; //�Ž�������ϴ� ��
int n; //������ ���� , �Ž�������ϴ� ������ ������ �ּҰ� �Ǿ���Ѵ�.

int money[11];
int min_count=987654321;

int func_count;

int check[11]; // ���õ� ���� ���� ǥ���ϱ�
int result_check[11]; // ���õ� ���� ���� ǥ���ϱ�


void input()
{
	freopen("input.txt","r",stdin);
//	freopen("output_changes.txt","w",stdout);

	scanf("%d",&m);
	scanf("%d",&n);

	for(int i=1;i<=n;i++)
	{
		scanf("%d",&money[i]);
	}
}


void solve(int total, int count)
{
	if(min_count < count) return; //����ġ��� �ʼ� , �ƴ� ��� �ȳ���

	func_count++;

	if(total>=m)
	{
		if(total==m)
		{
			if(min_count > count){ 
				min_count=count;
				
				for(int i=1;i<=n;i++)
				{
					result_check[i]=check[i];
				}
			}
		}
	    return;
	}

	for(int i=1;i<=n;i++)
	{
		check[i]=check[i]+1; // ���õ� ���� ���� ǥ���ϱ�
		solve(total+money[i],count+1);
		check[i]=check[i]-1; // ���õ� ���� ���� ǥ���ϱ�
	}
}

void main()
{
	input();
	solve(0,0);
	printf("min_count:%d\n",min_count);
	printf("func_count:%d\n",func_count);

	printf("\nselected coins : \n");
	for(int i=1;i<=n;i++)
	{
		if(result_check[i])
		{
			printf("conis:%d count:%d \n",money[i],result_check[i]);
		}
	}

}









//Greedy �ݿ��� �˰��� , ������ ���� ������.

#include<stdio.h>

int m; //�Ž�������ϴ� ��
int n; //������ ���� , �Ž�������ϴ� ������ ������ �ּҰ� �Ǿ���Ѵ�.

int money[11];
int min_count=987654321;

int func_count;

void input()
{
	freopen("input.txt","r",stdin);
//	freopen("output_changes.txt","w",stdout);

	scanf("%d",&m);
	scanf("%d",&n);

	for(int i=1;i<=n;i++)
	{
		scanf("%d",&money[i]);
	}
}

//�ݵ�� ������ ���ĵǾ� �־���Ѵ�. ū �� ���� ���� �ٲ��� ����
//Ž�������� ū���� ����ؼ� �شٰ� ����.
void greedy()
{
	int change_count=0;
	int tot=m;
	for(int i=n; i >= 1; i--)
	{
		if ( tot >= money[i] ) // ���� ū������ �Ž��� �༭... ���� ���� ���� ����Ѵ�. 
		{

			while(1)
			{
				if ( tot - money[i] >= 0  )// �� ������ ����ɼ� �ִ�. 
				{
					 tot-=money[i];   // ��ü ������ ���ָ鼭 
					 change_count++;  // ������ ������ ������Ų��.
				}
				else
				{
					printf("money : %d  total change_count:%d \n" , money[i] ,change_count );
					break;
				}
			}
	}
	
}

//greedy�ظ� ã�� ���
if(tot==0)
{
	min_count=change_count;
}
else // greedy�ظ� �� ã�� ���
{
	min_count=987654321;
}

printf("greedy count:%d\n",min_count);
}


//â�� �׸��� �˰��� ���� �ʱ���.
void greedy2()
{
	int r=m;
	int money_count=0;
	for(int i=n-1;i>=0;i--)
	{
		while(r>=money[i])
		{
			r=r-money[i];
			money_count++;
		}
	}
	
	//greedy�� �ذ� �մ��Ѱ�? r�� 0�� �����.
	if(r==0) 
	min_cnt=money_count;
	else
	min_cnt=987654321;

}


void solve(int total, int count)
{
	if(min_count < count) return; //����ġ��� �ʼ�

	func_count++;

	if(total>=m)
	{
		if(total==m)
		{
			if(min_count > count) min_count=count;
		}
	    return;
	}

	for(int i=1;i<=n;i++)
	{
		solve(total+money[i],count+1);
	}
}

void main()
{
	input();
	greedy();

	if(min_count==987654321)
	{
		printf("No solution\n");
	}
	else
	{
		solve(0,0);
		printf("min_count:%d\n",min_count);
		printf("func_count:%d\n",func_count);
	}
}




//����� DT ���̺� �ݿ� 

#include<stdio.h>

int m; //�Ž�������ϴ� ��
int n; //������ ���� , �Ž�������ϴ� ������ ������ �ּҰ� �Ǿ���Ѵ�.

int money[11];
int min_count=987654321;

int func_count;

int DT[10000];

void input()
{
	freopen("input.txt","r",stdin);
//	freopen("output_changes.txt","w",stdout);

	scanf("%d",&m);
	scanf("%d",&n);

	for(int i=1;i<=n;i++)
	{
		scanf("%d",&money[i]);
	}
}



int MIN(int a, int b)
{
	return a>b?b:a;
}

int solve(int total)
{
	if(DT[total]!=-1) return DT[total];

	if(total==m) return DT[total]=0;

	int result=987654321;

	for(int i=1;i<=n;i++)
	{
		if(total+money[i] <= m)  //�߿�!! ���� ����ġ�� �߿���.  ���ʺ��� �ٴ��� ���� �ʰ��� ���� ���� ������. Base�� �ֵ� ������, DT ���̺� ũ�Ⱑ �ֱ⿡ ��ȿ����
		result=MIN(result,solve(total+money[i])+1);
	}

	return DT[total]=result;
}

void main()
{
	input();

	for(int i=0;i<10000;i++)
	{
		DT[i]=-1;
	}

	printf("min_count:%d\n",solve(0));
	printf("func_count:%d\n",func_count);
}






//DP Ǯ��
#include<stdio.h>

int m; //�Ž�������ϴ� ��
int n; //������ ���� , �Ž�������ϴ� ������ ������ �ּҰ� �Ǿ���Ѵ�.

int money[11];
int DT[11][10001]; //1~10���� ������ ��������� 10000�� ����������� �ּ� ������ ����

void input()
{
	freopen("input.txt","r",stdin);
//	freopen("output_changes.txt","w",stdout);

	scanf("%d",&m);
	scanf("%d",&n);

	for(int i=1;i<=n;i++)
	{
		scanf("%d",&money[i]);
	}
}

int MIN(int a, int b)
{
	return a>b ? b:a ;
}


void printMatrix()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			printf(" %d",DT[i][j]);
		}
		printf("\n");
	}

}


void main()
{
	input();

	for(int j=1;j<=m;j++)
	{
		DT[0][j]=0xffff;
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(money[i] > j) DT[i][j]=DT[i-1][j];
			else
			{
				DT[i][j]=MIN(DT[i][j-money[i]]+1,DT[i-1][j]);
			}
		}
	}

	printMatrix();
	printf("%d",DT[n][m]);
}







////////////////////////////////////////////////////////////////////////////
