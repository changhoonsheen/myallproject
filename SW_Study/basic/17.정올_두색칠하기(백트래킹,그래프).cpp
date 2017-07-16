/*
�������İ��� �ٸ� �����̴�.
���� ������ ���� ���� �����̴�. 
Ʈ���� �׷����� �Լ��� �����غ���.(��� ����� ���� ����������) 



//�� �� ĥ�ϱ� (bicoloring)

�Է�
ù° �ٿ��� ������ ���� n(1 �� n �� 200)�� ������ �� m�� �Էµȴ�.
��° �ٺ��� m�ٿ� ���ļ� �� ������ �����ϴ� ������ ��ȣ�� �������� ���еǾ�
�Էµȴ�.

���
�Էµ� �׷����� �� ������ ĥ�� �� �ִ� �׷��������� �Ǵ��ϰ� �Ʒ� ���� ����
���Ŀ� �°� ����� ����϶�.

3
3
0 1
1 2
2 0

-> Impossible


9
8
0 1
0 2
0 3
0 4
0 5
0 6
0 7
0 8

-> OK


impossible
5 
5
0 1 
0 2
0 3
0 4
1 4

possible
4
4
0 1
0 2
1 3
2 3


impossible
4
5
0 1
0 2
1 3
2 3
1 2
*/



//â�� �����ʱ�
//�����ϰ�� �ٸ� ���� �� Ǯ����




#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define SIZE 10

#define RED 1
#define BLACK 2

int E;
int V;

int map[SIZE][SIZE];
int check[SIZE];



void input()
{
	freopen("input.txt","r",stdin);

	scanf("%d",&V);
	scanf("%d",&E);

	for(int i=0;i<E;i++)
	{
		int a;
		int b;
		scanf("%d %d",&a,&b);
		map[a][b]=map[b][a]=1;
	}

}

int impossilbe;

void f(int v, int c)
{
	//printf("v:%d c:%d\n",v,c);

	if(impossilbe==1) return;  //�߿�!! impossible������ �� �̻� �� �ʿ����. �� �̻� �׷����� Ž���� �ʿ䰡 ����.

	for(int i=0;i<V;i++)
	{
		if(map[v][i] && check[i]==c) impossilbe=1;
	}

	for(int i=0;i<V;i++)
	{
		if(map[v][i] && !check[i])
		{
			if(c==RED)
			{
				check[i]=BLACK;
				f(i,BLACK);
			}
			else
			{
				check[i]=RED;
				f(i,RED);
			}
		}
	}

}

void main()
{
	input();

	check[0]=RED; 
	f(0,RED);

	if(impossilbe==1) printf("IMPOSSIBLE\n");
	else  printf("POSSIBLE\n");
}






























#include<stdio.h>

int arr[10][10];
int checked[10];
int n;
int e;

//
#define R 1
#define B 2

int impossilbeFlag;

void solve(int v,int c)
{
	printf(" v : %d \n",v);
	for(int i=0;i<n;i++)
	{
		if(arr[v][i]) //���� ��带 Ȯ���ϰ�
		{
			if(checked[i]==c){ /*printf("impossilbe\n");*/impossilbeFlag=1;}
			//�α� �������� ���� ������ �ִٸ� 
		}
	}


	for(int i=0;i<n;i++)
	{
		if(checked[i]==0 && arr[v][i])
		{
			//���� ������ ���� �����.
			if(c==R)
			{
				checked[i]=B;
				solve(i,B);
			}
			else
			{
				checked[i]=R;
				solve(i,R);
			}

		}
	}
}


void main()
{
	freopen("input.txt","r",stdin);
	
	scanf("%d",&n);
	scanf("%d",&e);
	
	for(int i=0;i<e;i++)
	{
		int a;
		int b;
		
		scanf("%d %d",&a,&b);
		arr[a][b]=arr[b][a]=1;
	}	

	checked[0]=R;
	solve(0,R);

	if(impossilbeFlag==1) printf("impossilbe\n");
	else printf("possible\n");
}
















//�Ʒ��� ���� ������ 
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//////////////////////////////////////////////////////////////////////



>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#include<stdio.h>

int n,m,G[200][200],visited[200];

void solve(int v,int c) // ���� ���� V�� C�� ĥ�Ѵ�/
{
  visited[v]=c;
  int can=1;
  int i;
  
  for(i=0;i<n;i++)
  if(G[v][i] && visited[i]==c) can=0;  // ���� ����� ���� ���� �ִٸ� �� 
  
  if(!can)
  {
	printf("cannot -- v:%d - c:%d \n",v,c);
    visited[v]=0;
	return;
  }
  
  for(i=0;i<n;i++)
  {
    if(!visited[i] && G[v][i]) // �ĺ����� ����� ���� �ִ�.
	{
	  solve(i,1);  // red 1�� ĥ�غ���.
	  solve(i,2);  // black 2�� ĥ�غ���.
	}
  }
}

void main()
{
  freopen("input.txt","r",stdin);
  int i;

  scanf("%d %d",&n,&m);
  for(i=0;i<m;i++)
  {
    int s,e;
	scanf("%d %d",&s,&e);
	G[s][e]=G[e][s]=1;
  }
  
  solve(0,1);


  for(i=0; i<n ; i++)
  {
	 printf("%d ",visited[i]);
  }
  
  for(i=0; i<n ; i++)
  {
    if(visited[i]==0)  // �湮���� �ʴ� ������ �ϳ��� �ִٸ�.
	{
	  printf("IMPOSSIBLE\n");
	  
	  return;
	}
  }
  
  printf("OK\n");
  
  return;
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// ���� â�� ���� , ��ǰ. ���� ����.
// DFS/BFS�� ��� ������ �湮�Ѵ�.
// �ڽ� �������� �湮�Ҷ� ����� ���� �ΰ��� �ȴ�.1�� �÷� 2�� �÷�.

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


#include<stdio.h>

int map[200][200];
int n;
int m;

int chk[200];

void input()
{

	freopen("input.txt", "r", stdin);
	
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=0;i<=n;i++)
	{
	    int a;
		int b;
		scanf("%d %d",&a,&b);
		map[a][b]=map[b][a]=1;
	}		
}


void solve(int k,int c)
{
	
	chk[k]=c; //color�� ��� ����.
	int can=1;

	for(int i=0;i<n;i++)
	{
		if( map[k][i] && chk[i]==c ) can=-1;  // ���� ���� 
	}
	
	if(can==-1) { chk[k]=0; return; } // �� ������ �ٴڱ����ͼ��� �ش� ������ ��ĥ�� ���ϰ� (�湮���� ���ϰ�)
                                      // �÷� ������. 	���⼭ �ٴ� ó���ؾ���.
	
	for(int i=0;i<n;i++)
	{
		if(!chk[i] && map[k][i])  // ��湮 ���� �ѹ��� �湮�ϴ� DFS Ž���̴�. ������ �����ϰ� �׸��� �׷�����.
		{	
		 solve(i,1); //��� �ĺ����� ���� �ΰ��� ����� ���� �ִ�.
		 solve(i,2);
		}
	}
	
}

void main()
{
	input();
	
	solve(0,1); // ���������� �湮���� ���� ������ ������ impossible�̴�.
	
	for(int i=0;i<n;i++)
	{
		printf(" %d",chk[i]);
	}
	printf("\n");
	
	for(int i=0;i<n;i++)
	{
		if(chk[i]==0) {  printf("Impossible\n"); return;}
	}
	printf("\n");
	
	printf("OK");
}


//>>>>>>>>>>>>>>
// �ٸ� ���� 
//>>>>>>>>>>>>>>


#include<stdio.h>

int map[200][200];
int n;
int m;

int chk[200];

void input()
{

	freopen("input.txt", "r", stdin);
	
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=0;i<=n;i++)
	{
	    int a;
		int b;
		scanf("%d %d",&a,&b);
		map[a][b]=map[b][a]=1;
	}		
}


void solve(int k)  // ���ڸ� �÷��� �ȳѰ����� 
{
	
	int can=1;

	for(int i=0;i<n;i++)
	{
		if( map[k][i] && chk[i]==chk[k] ) can=-1;  // ���� ���� k�� Set�� �����̱� ������ ���������� üũ�Ѵ�.
	}
	
	if(can==-1) { chk[k]=0; return; } // �� ������ �ٴڱ����ͼ��� �ش� ������ ��ĥ�� ���ϰ� 
                                              // �÷� ������. 	��Ʈ���Ѵ�.
	
	for(int i=0;i<n;i++)
	{
		if(!chk[i] && map[k][i])  // ��湮 ���� �ѹ��� �湮�ϴ� DFS Ž���̴�. ������ �����ϰ� �׸��� �׷�����.
		{	
         chk[i]=1;  //�̷���쿡 ���� �����ó�� �������ȴ�.!
		 solve(i);  //��� �ĺ����� ���� �ΰ��� ����� ���� �ִ�. �׸��� ���� ���� ���� �� ���� �غ���, 
		            //�� �Լ��������� chk[i]=1�� solve �Լ��� ���� ���ö����� chk[i]=1�� ���� �ǰ� �ִ�. �Լ� ���ؿ� ���ؼ� ������ �ȴٴ� ��.
		            //���� ���� ���鶩 �� ���� ���ÿ� �־ �����ؾ��Ѵ�.
	
		 chk[i]=2; //�̷���쿡 ������ ���鶧 ���� �����ó�� �������ȴ�.! ��ȣ�� �ȵȴ�. DFS ó�� ����ϰ� �ѹ��� �ϳ��� �������Ǵ°��� ������ ����.
		 solve(i);
		}
	}
	
}

void main()
{
	input();
	
	chk[0]=1; //color�� ��� ����.
	solve(0); // ���������� �湮���� ���� ������ ������ impossible�̴�.
	
	for(int i=0;i<n;i++)
	{
		printf(" %d",chk[i]);
	}
	printf("\n");
	
	for(int i=0;i<n;i++)
	{
		if(chk[i]==0) {  printf("Impossible\n"); return;}
	}
	printf("\n");
	
	printf("OK");
}


//DFS Stack version OK

#include<stdio.h>

int map[200][200];
int n;
int m;

int chk[200];

struct Node
{
	int k;
	int c;
};

Node node[20000];
int top=-1;

void input()
{

	freopen("input.txt", "r", stdin);
	
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=0;i<=n;i++)
	{
	    int a;
		int b;
		scanf("%d %d",&a,&b);
		map[a][b]=map[b][a]=1;
	}		
}


void solve(int k,int c)
{
	
	top++;
	node[top].k=k;
	node[top].c=c;
		
	while(top!=-1)
	{

		int new_k =node[top].k;
	    int new_c =node[top].c;
		top--;

		chk[new_k]=new_c; //color�� ��� ����.

		printf("top:%d  k:%d  c:%d\n",top,new_k,new_c);
		
		int can=1;

		for(int i=0;i<n;i++)
		{
			if( map[new_k][i] && chk[i]==new_c ) can=-1;  // ���� ���� 
		}
		
		if(can==-1) { chk[new_k]=0;  continue; } // �� ������ �ٴڱ����ͼ��� �ش� ������ ��ĥ�� ���ϰ� (�湮���� ���ϰ�)
										                    // �÷� ������. 	
		
		for(int i=0;i<n;i++)
		{
			if(!chk[i] && map[new_k][i])  // ��湮 ���� �ѹ��� �湮�ϴ� DFS Ž���̴�. ������ �����ϰ� �׸��� �׷�����.
			{	

				top++;
				node[top].k=i;
				node[top].c=2;

				top++;
				node[top].k=i;
				node[top].c=1;
			}
		}
	}
	
}

void main()
{
	input();
	
	solve(0,1); // ���������� �湮���� ���� ������ ������ impossible�̴�.
	
	for(int i=0;i<n;i++)
	{
		printf(" %d",chk[i]);
	}
	printf("\n");
	
	for(int i=0;i<n;i++)
	{
		if(chk[i]==0) {  printf("Impossible\n"); return;}
	}
	printf("\n");
	
	printf("OK");
}