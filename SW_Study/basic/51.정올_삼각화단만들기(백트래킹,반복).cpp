�־��� ȭ�� �ѷ��� ���̸� �̿��Ͽ� �ﰢ�� ����� ȭ���� ������� �Ѵ�. �� ��
������� �ﰢ�� ȭ�� �ѷ��� ���̴� �ݵ�� �־��� ȭ�� �ѷ��� ���̿� ���ƾ� ��
��. ����, ȭ�� �ѷ��� ���̿� �� ���� ���̴� �ڿ����̴�. ���� ���, ������� �ϴ�
ȭ�� �ѷ��� ���̰� 9m��� �ϸ�,
? �� ���� ���̰� 1m, �� ���� ���̰� 4m�� ȭ��
? �� ���� ���̰� 2m, �ٸ� ���� ���̰� 3m, ������ ���� ���̰� 4m�� ȭ��
? �� ���� ���̰� ��� 3m�� 3���� ����� ȭ���� ���� �� �ִ�.

// �����غ���.

0. �־��� �Է� , ���� �߿��� ����, Ư�� ����Ž���� �ٴ�(base)�� �����̴�.
a + b + c = �־��� ���� 

1. �ﰢ���� ����
a + b > c

2. �ߺ��� ���ֱ�   // 0 , 1 �� ����� ��� �ߺ��� ����,
a <= b <= c




//â�� ���� �ʱ�
//�׷��� 100�� ���� �ȳ��´�. �׷��� �������� Ǯ����Ѵ�. 20�� �� �ȳ���.
/*
20
a:6 b:7 c:7
a:6 b:6 c:8
a:5 b:7 c:8
a:5 b:6 c:9
a:4 b:8 c:8
a:4 b:7 c:9
a:3 b:8 c:9
a:2 b:9 c:9
count : 8
func_count:935209305
*/
#include<stdio.h>

int N;
int count;

//�Ȱ��� ���� ���ö� üũ �迭�� �̿��ؼ� ���� ���� ������ ���´�.
int check[100][100][100];

void solve(int a, int b ,int c)
{

		if(a+b+c==N) // �⺻���� 
		{
			if(a+b > c && c >= b && b >= a)  // �ߺ����Ÿ� �ϴ� �κ�
			{
				if(check[a][b][c]==0)
				{
					check[a][b][c]=1;
					printf("a:%d b:%d c:%d\n",a,b,c);
					count++;
				}
			}
			return;		
		}


	solve(a+1,b,c);
	solve(a,b+1,c);
	solve(a,b,c+1);
}


void main()
{
	scanf("%d",&N);

	solve(0,0,0);
	printf("count : %d\n",count);
}


// �������� Ǯ���
// �̹������ Ǯ����� ���� ���´�.
/*
20
a:2 b:9 c:9
a:3 b:8 c:9
a:4 b:7 c:9
a:4 b:8 c:8
a:5 b:6 c:9
a:5 b:7 c:8
a:6 b:6 c:8
a:6 b:7 c:7
count : 8
*/

#include<stdio.h>

int N;
int check[101][101][101];
int count;

void main()
{
	scanf("%d",&N);

	for(int a=0;a<=N;a++)
	for(int b=0;b<=N;b++)
	for(int c=0;c<=N;c++)
	{

		if(a+b+c==N && a+b>c && c>=b && b>=a && check[a][b][c]==0)				
		{
			 check[a][b][c]=1;
			 printf("a:%d b:%d c:%d\n",a,b,c);
			 count++;
		}	
	}

	printf("count : %d\n",count);
}



































//++ �Ʒ��� �׳� �����ϵ��� 
////////////////////////////////////////////////////////////////////////////////////////

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//��ü Ž�� ���   -> �������� Ž��������� ������.
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#include <stdio.h>

int count;
int n;

void main()
{
printf("\n>>>>>>>>>>>>>>>>>>>>\n");


n=100;
count=0;

for(int a=1; a<=n; a++)
for(int b=a; b<=n; b++)
for(int c=b; c<=n; c++)
{
	if( (a+b+c==n) && (a+b > c) )
	{
		if(count%3 == 0) puts("");

		count++;
		printf("[%d %d %d]\t", a, b, c);
	}


}


printf("\n>>>>>>>>>>>>>>>>>>>>\n");

n=100;
count=0;


for(int a=1; a<=n; a++)
for(int b=1; b<=n; b++)
for(int c=1; c<=n; c++)
{
	if( a <= b && b <= c)  // ������ for loop�� 1 ���� ���������� 
	{
		if( (a+b+c==n) && (a+b > c) )
		{
			if(count%3 == 0) puts("");

			count++;
			printf("[%d %d %d]\t", a, b, c);
		}
	}
}
}


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//��ü Ž�� ���   -> �������� ������� ������.
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


//�Լ� ��� �ٲ㺸�� 

#include <stdio.h>

int checked[10][10][10];

void solve(int n, int a , int b , int c)
{
	if(a+b+c==n)  // Base�� �����̴�. �Ʒ� ���ǰ� ���� ������ �ȵȴ�.
	{
		if(  (a <= b && b <=c ) && ( a+b > c ) && ( checked[a][b][c]==0) ) 
		{
			printf("a:%d , b:%d , c:%d\n",a,b,c);
			checked[a][b][c]=1;
		}
		
		return;
	}

	solve(n,a+1,b,c);
	solve(n,a,b+1,c);
	solve(n,a,b,c+1);
}


void main(void)
{
	int n=5;
	solve(n,0,0,0);
}



//Stack�� ����ؼ� �ٲ㺸�� 
#include <stdio.h>

int checked[10][10][10];

struct Node
{
	int a;
	int b;
	int c;
};

Node node[100000];
int top=-1;
int n;

//������ ������ �������. ����ü�� ��Ƽ� �ѱ��ȴ�.!
void solve(int a , int b , int c)
{
	top++;
	node[top].a=a;
	node[top].b=b;
	node[top].c=c;
	
	while(top!=-1)
	{
		int new_a=node[top].a;
		int new_b=node[top].b;
		int new_c=node[top].c;
		top--;
		
		// �ش� ��ƾ�� ��� ���� ������ ����. �̶� ���ϴ� ���� �ϳ��� ȹ���Ѵ�.
		//>> �ݵ�� �湮�� ���� ó�� ���⼭ �Ѵ�.!!
		if(new_a+new_b+new_c==n)  // Base�� �����̴�. �Ʒ� ���ǰ� ���� ������ �ȵȴ�.
		{
			if(  (new_a <= new_b && new_b <=new_c ) && ( new_a+new_b > new_c ) && ( checked[new_a][new_b][new_c]==0) ) 
			{
				printf("a:%d , b:%d , c:%d\n",new_a,new_b,new_c);
				checked[new_a][new_b][new_c]=1;
			}
		}
		//<<

	     if(new_a+new_b+new_c < n)  // �� �κ� ���� �߿��ϴ�.!!  ��� ������ ���ϸ� ��� ���� ������ ���ѷ��� ���� ��üŽ���� �� �� ������?
			                        // �ĺ��� ó�� Ʈ���� �׷�����. ��� �ٴ�����, �׸��� Stack�� �ĺ����� ������ �ĺ����� ���Խ�ų ������ ���� ó���ϰ� Ȯ���Ѵ�. 
		 {	
				        	top++;                             
							node[top].a=new_a;
							node[top].b=new_b;
							node[top].c=new_c+1;

							top++;
							node[top].a=new_a;
							node[top].b=new_b+1;
							node[top].c=new_c;

							top++;                     //���� ���ð��� �� �������� �ִ´�.
							node[top].a=new_a+1;
							node[top].b=new_b;
							node[top].c=new_c;
		
		}			
	}

}
void main(void)
{
	n=9;
	solve(0,0,0);
}
