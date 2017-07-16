//â�� ���� Ǯ�� �ʱ⸦ �����ϵ���




//temp �迭 ���� �ѹ��� Ǯ��
#include<stdio.h>

int n; //���� 
int m; //����

int map[50][50];
int temp_map[50][50];


int dx[]={-1,0,1, 0};
int dy[]={ 0,1,0,-1};


#define I 0 //����
#define E 2 //�ܺ�
#define C 1 //ġ��
#define D 4 //������ ġ��

struct Node
{
	int i;
	int j;
};

Node node[1000000];

int f=-1;
int r=-1;


int result[1000];


void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	scanf("%d",&map[i][j]);	
}


//�ܺ� ����� ���� ���⸦ �����Ѵ�.
void checkExternal(int i, int j)
{
	map[i][j]=E;

	f=-1;
    r=-1;


	r++;
	node[r].i=i;
	node[r].j=j;

	while(f!=r)
	{
		f++;
		int new_i=node[f].i;
		int new_j=node[f].j;

		for(int k=0;k<4;k++)
		{
			if(map[new_i+dx[k]][new_j+dy[k]]==I &&
			  (new_i+dx[k]>=0 && new_j+dy[k]>=0) &&
			  (new_i+dx[k]<n && new_j+dy[k]<m))
			 {
				 map[new_i+dx[k]][new_j+dy[k]]=E;
				 r++;
				 node[r].i=new_i+dx[k];
				 node[r].j=new_j+dy[k];
			 }

		}
	}
}

void display()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			printf(" %d",map[i][j]);
		}
		printf("\n");
	}
}

void RemoveChesee()
{

//�ٲ�ġ�� �ϰ�üũ
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(map[i][j]==C)
			{
				int count=0;
				for(int k=0;k<4;k++)
				{
					if(map[i+dx[k]][j+dy[k]]==E) count++;
				}

				if(count>=2) map[i][j]=D;
			}
		}
	}

//���� �ٲٱ�
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(map[i][j]==D) map[i][j]=E;
		}
	}
}

int checkAllChesee()
{
	int count=0;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(map[i][j]==C) count++;
		}		
	}

	if(count>=1) return 1;
	return 0;
}

void doExternal()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(map[i][j]==E)
			{
				for(int k=0;k<4;k++)
				{
				  if(map[i+dx[k]][j+dy[k]]==I &&
				  (i+dx[k]>=0 && j+dy[k]>=0) &&
				  (i+dx[k]<n && j+dy[k]<m))
				 {
					 checkExternal(i+dx[k], j+dy[k]);
				 }
				}
			}
		}
	}
}

void main()
{
	input();

	int time=0;

	checkExternal(0,0);
	printf("%d sec\n",time);
	display();
    printf("---------\n");
	
	while(checkAllChesee())
	{
		time++;
		RemoveChesee();
		doExternal();

		printf("%d sec\n",time);
	    display();
		printf("---------\n");
	
	}
}
















//temp �迭 �̿� Ǯ��
/////////////////////////////////////////

#include<stdio.h>

struct Cord
{
	int x;
	int y;
};

Cord Q[1000000];

int f=-1;
int r=-1;

int n;
int m;

int map[100][100];
int temp_map[100][100];
int new_temp_map[100][100];

#define IN 0
#define CHEESE 1
#define OUT 2
#define DEL 3

// �� �κ� ����
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

void makeGroup()
{
	r++;
	Q[r].x=0;
	Q[r].y=0;
	map[0][0]=OUT; // �������� �� �����ڸ��� ġ� ����.
	
	while(f!=r)
	{
		f++;
		for(int i=0;i<4;i++)
		{
			int new_x=Q[f].x+dx[i];
			int new_y=Q[f].y+dy[i];
				
			if( map[new_x][new_y]==0 && // �ĺ����� ���� �̸鼭 ������ ���� �ȴ´ٸ�.
			   (new_x>=0 && new_y>=0) &&
			   (new_x<n && new_y<m))
			   {
				   map[new_x][new_y]=OUT; // �ܺΰ���� ǥ��
				   	
				   //�ٽ� ť�� ����			
				   r++;
				   Q[r].x=new_x;
				   Q[r].y=new_y;
			   }
	
		}
	}
}


//������ ġ� üũ���� �ϰ������� �����.
void removeCheese()
{
	    //temp ���� ���� ������ ġ� üũ�Ѵ�.�������� �ʿ� �۾��� �ϸ� ����.
		for(int x=0;x<n;x++)
		for(int y=0;y<n;y++)
		{
			temp_map[x][y]=map[x][y];
		}


	    for(int x=0;x<n;x++)
		for(int y=0;y<n;y++)
		{
			int count=0;
			if(temp_map[x][y]==CHEESE)
			{
				//4���⿡ ���ؼ� üũ
				for(int i=0;i<4;i++)
				{
					int new_x=x+dx[i];
					int new_y=y+dy[i];
				
					if( map[new_x][new_y]==OUT &&
					   (new_x>=0 && new_y>=0) &&
					   (new_x<n && new_y<m))
					{
						count++;
					}
				}

			if(count>=2) { 
				map[x][y]=DEL;
			}

			}
		}

		//�ϰ�����
		for(int x=0;x<n;x++)
		for(int y=0;y<n;y++)
		{
			if(map[x][y]==DEL)
			{
				map[x][y]=OUT;
			}
		}
}

//���� ���Ⱑ �ܺ� ����� ������ �Ǿ��ִٸ�
#if 0  // �� �Լ��� ������ �ִ�. �� �׷��� �ʱ��س��� ��Ʈ�� �ʱ��س��Ҵ�.
void checkAir()
{
		for(int x=0;x<n;x++)
		for(int y=0;y<n;y++)
		{
			if(temp_map[x][y]==IN)
			{
				//4���⿡ ���ؼ� üũ
				for(int i=0;i<4;i++)
				{
					int new_x=x+dx[i];
					int new_y=y+dy[i];
				
					if( map[new_x][new_y]==OUT)
					{
						map[x][y]=OUT;
					}
				}
			}
		}
}
#else

//�ڱ� �ڽ��� �ٲٸ鼭 ���ϱ� Check �迭�� �ʿ����.
void checkAir(int a, int b)
{

		for(int i=0;i<4;i++)
		{
			int new_x=a+dx[i];
			int new_y=b+dy[i];
			if( map[new_x][new_y]==IN)
			{
			  map[new_x][new_y]=OUT;
			  checkAir(new_x, new_y);
			}
		}

}


void changeAir()
{
		for(int x=0;x<n;x++)
		for(int y=0;y<n;y++)
		{
			if(map[x][y]==OUT)
			{
				for(int i=0;i<4;i++)
				{
					int new_x=x+dx[i];
					int new_y=y+dy[i];

					 if( map[new_x][new_y]==IN &&
					   (new_x>=0 && new_y>=0) &&
					   (new_x<n && new_y<m))
					{
						map[new_x][new_y];
						checkAir(new_x,new_y);
					}
				}
			}
		}
}


#endif

int isEnd()
{
	int cheese_count=0;

	for(int x=0;x<n;x++)
		for(int y=0;y<n;y++)
		{
			if(map[x][y]==CHEESE)
			{
				cheese_count++;
			}
		}
		
		printf("cheese count:%d\n",cheese_count);

		if(!cheese_count) return 1; //end
		else return 0 ;// no end
}


void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&map[i][j]);
	
}

void printMatrix()
{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{	
				printf("%d ",map[i][j]);
			}	
			printf("\n");
		}

		printf("\n");
}

void main()
{
input();


#if 0
int time=0;

makeGroup();

while(!isEnd())
{
		removeCheese();
		changeAir();
		time++;
}
printf("%d",time);

#else
//debugging
int time=0;

makeGroup();
printMatrix();
printf("+++++++++++++++++++++++\n");

while(!isEnd())
{

	removeCheese();
	printMatrix();
	printf("********************\n");

	changeAir();
	 printMatrix();
	printf("-------------------------W\n");
	time++;
}

printf("%d",time);
#endif 



}





















//�Ʒ��� �׳� ������ �ϵ���
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/////////////////////////////////////////////////////////////////////////////////

8 9
0 0 0 0 0 0 0 0 0
0 0 0 1 1 0 0 0 0
0 0 0 1 1 0 1 1 0
0 0 1 1 1 1 1 1 0
0 0 1 1 1 1 1 0 0
0 0 1 1 0 1 1 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0

->  4 �� 


8 9
0 0 0 0 0 0 0 0 0
0 0 0 1 1 1 1 0 0
0 0 0 1 1 0 1 1 0
0 0 1 1 0 0 1 1 0
0 0 1 1 1 1 1 0 0
0 0 1 1 0 1 1 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0

-> 3�� 


8 9
0 0 0 0 0 0 0 0 0
0 1 1 1 1 1 1 0 0
0 1 0 1 1 0 1 1 0
0 1 0 1 0 0 1 1 0
0 1 0 1 1 1 1 0 0
0 1 1 1 0 1 1 0 0
0 1 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 0
->4 ��

16 9
0 0 0 0 0 0 0 0 0
0 1 1 1 1 1 1 1 0
0 1 0 0 0 0 0 1 0
0 1 0 1 1 1 0 1 0
0 1 0 1 0 1 0 1 0
0 1 0 1 0 1 0 1 0
0 1 0 1 0 1 0 1 0
0 1 0 1 0 1 0 1 0
0 1 0 1 1 1 0 1 0
0 1 0 1 0 1 0 1 0
0 1 0 1 0 1 0 1 0
0 1 0 1 0 1 0 1 0
0 1 0 1 1 1 0 1 0
0 1 0 0 0 0 0 1 0
0 1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0 0

-> 6 �� 




#include<stdio.h>
int N;
int M;

int MAP[20][20];

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

int time=0;
int isFinished()
{
	for(int i=0;i<N;i++)
	for(int j=0;j<M;j++)
	{
		if(MAP[i][j]==1) return 0;
	}

	return 1;
}



void changeExtAir(int x, int y)
{
	for(int k=0;k<4;k++)
	{
		int new_x=x+dx[k];
		int new_y=y+dy[k];
		if(MAP[new_x][new_y]==0 &&
		   new_x>=0 && new_y>=0 &&
		   new_x<N  && new_y<M )
		{
			MAP[new_x][new_y]=2;
			changeExtAir(new_x, new_y);
		}
	}
}

void checkDel()
{
	for(int i=0;i<N;i++)
	for(int j=0;j<M;j++)
	{
		    if(MAP[i][j]==1)
			{
				int count=0;
				for(int k=0;k<4;k++)
				{
					int new_x=i+dx[k];
					int new_y=j+dy[k];

					if(MAP[new_x][new_y]==2) count++;
				}

				if(count>=2) MAP[i][j]=3;
			}
	}


	for(int i=0;i<N;i++)
	for(int j=0;j<M;j++)
	{
		if(MAP[i][j]==3) MAP[i][j]=2;
	}
}

void mergeAir()
{
	for(int i=0;i<N;i++)
	for(int j=0;j<M;j++)
	{
				if(MAP[i][j]==2)
				for(int k=0;k<4;k++)
				{
					int new_x=i+dx[k];
					int new_y=j+dy[k];

					if(MAP[new_x][new_y]==0)
					{
						MAP[new_x][new_y]=2;
						changeExtAir(new_x, new_y);
					}
				}
	}
}

void display()
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			printf(" %d",MAP[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void main()
{
	freopen("input.txt","r",stdin);
	scanf("%d %d",&N,&M);

	for(int i=0;i<N;i++)
	for(int j=0;j<M;j++)
	scanf("%d",&MAP[i][j]);
	
	//display();
	while(!isFinished())
	{
		//�ܺ� ���� ���� 
		//>>
		MAP[0][0]=2;
		changeExtAir(0,0);
		//<<
		//�ܺ� ����� ���˵� ���� ã��, �̸� ����
		checkDel();
		
		//�ܺ� ����� ����� ���� ���⸦ üũ��,
		mergeAir();
		time++;
	}

	printf("time:%d\n",time);
}


//â�� ����
//�迭�ϳ��� ����ϰ� Ǯ����. �̰� �����ϵ��� 

#include<stdio.h>

#define IN_AIR '0'
#define CHEESE '1'
#define OUT_AIR '2'
#define DEL 'c'

int N;
int M;


char map[100][100];

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};


void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d %d",&N,&M);

	for(int i=0;i<N;i++)
	for(int j=0;j<M;j++)
	scanf(" %c",&map[i][j]);
}

void display()
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			printf(" %c",map[i][j]);
		}
		printf("\n");
	}
		printf("\n");
}

//�ܺ� ����� ���� ���� �и�
void checkair(int x, int y)
{
	for(int k=0;k<4;k++)
	{
		int new_x=x+dx[k];
		int new_y=y+dy[k];

		if( map[new_x][new_y]==IN_AIR &&
			new_x >= 0 && new_x < N &&
			new_y >= 0 && new_y < M 
			)
		{
			map[new_x][new_y]=OUT_AIR;
			checkair(new_x,new_y);
		}
	}
}

//�ܺ� ���⿡ ����� ���� ġ� ã�´�.
void check_remove_cheese()
{
	for(int x=0;x<N;x++)
	{
		for(int y=0;y<M;y++)
		{
			if(map[x][y]==CHEESE)
			{
				int count=0;
				for(int k=0;k<4;k++)
				{
					int new_x=x+dx[k];
					int new_y=y+dy[k];

					if(map[new_x][new_y]==OUT_AIR)
					{
						count++;
					}
				}

				if(count>=2) map[x][y]=DEL;
			}
		}
	}
}

//������ ������ ġ�� �����
void remove_cheese()
{
	    for(int x=0;x<N;x++)
		for(int y=0;y<M;y++)
		{
			if(map[x][y]==DEL) map[x][y]=OUT_AIR;
		}
}

//���� ���� �ִ� ġ���� ����?
int checkALLCheese()
{
	int cheese_count=0;
    
	for(int x=0;x<N;x++)
	for(int y=0;y<M;y++)
	{
		if(map[x][y]==CHEESE) cheese_count++;
	}

	return cheese_count;
}


//�ܺη� ����� ���ΰ��⸦ �ܺ�ȭ�Ѵ�. 
void merge_air()
{

	for(int x=0;x<N;x++)
	for(int y=0;y<M;y++)
	{
		if(map[x][y]==IN_AIR) //���� �����?
		{
			//�ܺ� ����� �����ִ�?
			for(int k=0;k<4;k++)
			{
				int new_x=x+dx[k];
				int new_y=y+dy[k];

				if(map[new_x][new_y]==OUT_AIR) // ��ó �ִ� �ܺ� ���Ⱑ �ִٸ� 
				{
					map[x][y]=OUT_AIR; // ���� ��ǥ�� ���⸦ �ܺ� ����� �ٲٰ� 
					checkair(x,y); //�ֺ� ������ �ܺ�ȭ ���� 
				}
			}
		}
	}

}


void main()
{
	input();
	
	display();
	map[0][0]=OUT_AIR;
	checkair(0,0);

	printf("---------------------------------\n");

	int time=0;

	while(checkALLCheese())
	{
		time++;
		check_remove_cheese();

		remove_cheese();

		merge_air();
		display();
	}

	printf("\n time: %d\n",time);
}


































//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// ���� ���� �ذ� - â��Ǯ�� 
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#include<stdio.h>


int map[100][100];
int temp_map[100][100];
int min_time;
int n,m;


void input(void)
{
	scanf("%d %d", &n,&m);
	
	for(int i=0; i<n; i++)
	for(int j=0; j<m; j++)
	scanf("%d", &map[i][j]);
}


//����� ���Ѹ��� ����Ͽ� c�� ǥ���Ѵ�. 
void check_cheese()
{
	int count=0;

	for(int i=0; i<n; i++)
	for(int j=0; j<m; j++)
	{
	   count=0;
 
      if(map[i][j]==1)  //cheese?
	  {
		if(map[i-1][j]==2) count++; 
		if(map[i][j+1]==2) count++;
		if(map[i+1][j]==2) count++;
		if(map[i][j-1]==2) count++;
	  }
	  	if(count >= 2) map[i][j]=5;  // ���������� �� 
	}
}


void checkAir(int i, int j)
{	
	if( i<0 || j<0 || i >=n || j>= m  ) return;
	
	if(map[i][j]==0) //air
	{
		map[i][j]=2;
		checkAir(i-1,j);
		checkAir(i,j+1);
		checkAir(i+1,j);
		checkAir(i,j-1);
	}		
}

void trimmap()
{
	for(int i=0; i<n; i++)
	for(int j=0; j<m; j++)
	{
		if(map[i][j]==5)  // ���������� �κ�
		{
			map[i][j]=0;  // �ʱ�ȭ ��Ű�� ���ؼ� 0���� ����
		}

		if(map[i][j]==2) // �ܺ� ���� 
		{
			map[i][j]=0;  // �ʱ�ȭ ��Ű�� ���ؼ� 0���� ����
		}
	}
}

int checkfinish()
{
	int count=0;
	for(int i=0; i<n; i++)
	for(int j=0; j<m; j++)
	{
		if(map[i][j]==1) count++;
	}
	 
	 return count;
}


void display()
{
	printf("\n\n %d\n",min_time);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			printf(" %d",map[i][j]);
		}
	printf("\n");
	}
}


void solve()
{
 
   while(1) //ġ� ����������
   {
	display();

	  
	//ġ��üũ 
    if(checkfinish()==0) break;

	checkAir(0,0);	
	check_cheese();
	trimmap();
	 
     min_time++;

   }
}

int main()
{
	freopen("input.txt","r",stdin);
	input();
	solve();
	printf("%d", min_time);
	return 0;
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//����Ǯ�� 
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#include <stdio.h>
int a1[101][101], a2[101][101];
int n, m;
void copy()
{
int i, j;
for(i=1; i<=n; i++)
for(j=1; j<=m; j++)
a1[i][j]=a2[i][j];
}
void fill1(int x, int y)
{
if(x<1 || y<1 || x>n || y>m) return;
if(a1[x][y]==0)
{
a1[x][y]=2;
fill1(x+1,y);
fill1(x-1,y);
fill1(x,y+1);
fill1(x,y-1);
}
}
int check(int x, int y)
{
int t=0;
if(a1[x+1][y]==2) t++;
if(a1[x-1][y]==2) t++;
if(a1[x][y+1]==2) t++;
if(a1[x][y-1]==2) t++;
return t;
}
int main()
{
int i, j, hour=0, count;

freopen("input.txt","r",stdin);
scanf("%d %d",&n, &m);
for(i=1; i<=n; i++)
for(j=1; j<=m; j++)
{
scanf("%d",&a1[i][j]);
a2[i][j]=a1[i][j];
}
while(1)
{
fill1(1,1);
count=0;
for(i=1; i<=n; i++)
for(j=1; j<=m; j++)
{
if(a1[i][j]==1 && check(i,j)>=2)
{
a2[i][j]=0;
count++;
}
}
if(count==0)
{
printf("%d", hour);
break;
}
hour++;
copy();
}
return 0;
}

/////////////////////////////////////////////////////




Ǯ�� ��� ù��° 
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#include<stdio.h>

int a1[101][101], a2[101][101];
int n,m;

void copy()
{
 int i,j;
 for(i=1;i<=n;i++)
 for(j=1;j<=m;j++)
 a1[i][j]=a2[i][j];
}


#if 1

int dx[4]={-1,0,1,0}, dy[4]={0,1,0,-1};

int check(int i, int j)
{
	return  ( 1 <= i && i < n ) && ( 1 <= j && j < m );	
}

void fill1(int x , int y)
{
 
 for(int k=0;k<4;k++)
 if(a1[x+dx[k]][y+dy[k]]==0 && check(x+dx[k],y+dy[k]))
 {
   a1[x+dx[k]][y+dy[k]]=2;	 
   fill1(x+dx[k],y+dy[k]);
 }
}


#else 
	
//�ܺ� ���⸸�� 2�� ä���� 
void fill1(int x , int y)
{
 if(x<1 || y<1 || x > n || y > m) return;
 if(a1[x][y]==0)
 {
   a1[x][y]=2;
   fill1(x+1,y);
   fill1(x-1,y);
   fill1(x,y+1);
   fill1(x,y-1);
 }
}

#endif




//�ܺ� ����� ����ƴ���?
int check(int x, int y)
{
 int t=0;
 if(a1[x+1][y]==2) t++;
 if(a1[x-1][y]==2) t++;
 if(a1[x][y+1]==2) t++;
 if(a1[x][y-1]==2) t++;
 return t;
}

void printfOutput()
{
 int i,j;
 for(i=1; i <=n ; i++)
 {
  for(j=1; j <=m ; j++)
  {
   printf(" %d",a1[i][j]);
  }
  printf("\n");
 }
 
}

int main()
{
  int i,j, hour=0, count;
  freopen("input.txt","r",stdin);

  scanf("%d %d",&n,&m);
  
  for(i=1; i <=n ; i++)
  for(j=1; j <=m ; j++)
  {
   scanf("%d",&a1[i][j]);
   a2[i][j]=a1[i][j];
  }
  
  while(1)
  {
	//hoony
	//>>
	#if 1
	a1[1][1]=2;
    fill1(1,1);
	//<<
	#else 
	fill1(1,1);
	#endif
	
	count=0;
	
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
	  if(a1[i][j]==1 && check(i,j)>=2)
	  {
	    a2[i][j]=0;
		count++;
	  }
	}

	if(count==0)
    { 
		printf("result : %d hour",hour);
		break;
	}
	hour++;

    printf("%d hours\n", hour);
	printfOutput();

	copy();
  }
  
  return 0;
}


>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
�ι�° ��� �ѽð� ���� �ٱ� ���� ����� üũ ���� �ʰ�
�������� ���ڸ����� �ٽ� ����� ���⸦ üũ �Ѵ�.


#include<stdio.h>

int a1[101][101], a2[101][101];
int n,m;

void copy()
{
 int i,j;
 for(i=1;i<=n;i++)
 for(j=1;j<=m;j++)
 a1[i][j]=a2[i][j];
}


//�ܺ� ���⸸�� 2�� ä���� 
void fill1(int x , int y)
{
 if(x<1 || y<1 || x > n || y > m) return;
 if(a1[x][y]==0)
 {
   a1[x][y]=2;
   fill1(x+1,y);
   fill1(x-1,y);
   fill1(x,y+1);
   fill1(x,y-1);
 }
}

//�ܺ� ���⸸�� 2�� ä���� 
void fill2(int x , int y)
{
 if(x<1 || y<1 || x > n || y > m) return;
 if(a2[x][y]==0)
 {
   a2[x][y]=2;
   fill2(x+1,y);
   fill2(x-1,y);
   fill2(x,y+1);
   fill2(x,y-1);
 }
}


//�ܺ� ����� ����ƴ���?
int check(int x, int y)
{
 int t=0;
 if(a1[x+1][y]==2) t++;
 if(a1[x-1][y]==2) t++;
 if(a1[x][y+1]==2) t++;
 if(a1[x][y-1]==2) t++;
 return t;
}

void printfOutput()
{
 int i,j;
 for(i=1; i <=n ; i++)
 {
  for(j=1; j <=m ; j++)
  {
   printf(" %d",a1[i][j]);
  }
  printf("\n");
 }
 
}

int main()
{
  int i,j, hour=0, count;
  freopen("input.txt","r",stdin);

  scanf("%d %d",&n,&m);
  
  for(i=1; i <=n ; i++)
  for(j=1; j <=m ; j++)
  {
   scanf("%d",&a1[i][j]);
   a2[i][j]=a1[i][j];
  }
  
  fill1(1,1);
  fill2(1,1);
	
  while(1)
  {
    count=0;
	
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
	  if(a1[i][j]==1 && check(i,j)>=2)
	  {
	    a2[i][j]=0;
		count++;
	  }
	}

	if(count==0)
    { 
		printf("result : %d hour",hour);
		break;
	}
	hour++;

    printf("%d hours\n", hour);
	printfOutput();

	copy();
  }
  
  return 0;
}


