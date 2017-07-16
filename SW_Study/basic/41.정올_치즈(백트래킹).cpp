//창훈 최종 풀이 필기를 참조하도록




//temp 배열 없이 한번에 풀기
#include<stdio.h>

int n; //가로 
int m; //세로

int map[50][50];
int temp_map[50][50];


int dx[]={-1,0,1, 0};
int dy[]={ 0,1,0,-1};


#define I 0 //내부
#define E 2 //외부
#define C 1 //치즈
#define D 4 //지워질 치즈

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


//외부 공기와 내부 공기를 구분한다.
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

//바뀔치즈 일괄체크
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

//실제 바꾸기
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
















//temp 배열 이용 풀이
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

// 이 부분 조심
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

void makeGroup()
{
	r++;
	Q[r].x=0;
	Q[r].y=0;
	map[0][0]=OUT; // 모눈중이의 맨 가장자리는 치즈가 없다.
	
	while(f!=r)
	{
		f++;
		for(int i=0;i<4;i++)
		{
			int new_x=Q[f].x+dx[i];
			int new_y=Q[f].y+dy[i];
				
			if( map[new_x][new_y]==0 && // 후보군이 공기 이면서 영역을 넘지 안는다면.
			   (new_x>=0 && new_y>=0) &&
			   (new_x<n && new_y<m))
			   {
				   map[new_x][new_y]=OUT; // 외부공기로 표시
				   	
				   //다시 큐에 놓고			
				   r++;
				   Q[r].x=new_x;
				   Q[r].y=new_y;
			   }
	
		}
	}
}


//없어질 치즈를 체크한후 일괄적으로 지운다.
void removeCheese()
{
	    //temp 맵을 보고 없어질 치즈를 체크한다.오리지널 맵에 작업을 하면 꼬임.
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
				//4방향에 대해서 체크
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

		//일괄삭제
		for(int x=0;x<n;x++)
		for(int y=0;y<n;y++)
		{
			if(map[x][y]==DEL)
			{
				map[x][y]=OUT;
			}
		}
}

//내부 공기가 외부 공기와 연결이 되어있다면
#if 0  // 이 함수는 오류가 있다. 왜 그런지 필기해놓기 노트에 필기해놓았다.
void checkAir()
{
		for(int x=0;x<n;x++)
		for(int y=0;y<n;y++)
		{
			if(temp_map[x][y]==IN)
			{
				//4방향에 대해서 체크
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

//자기 자신이 바꾸면서 들어가니깐 Check 배열이 필요없다.
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





















//아래껀 그냥 참조만 하도록
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

->  4 초 


8 9
0 0 0 0 0 0 0 0 0
0 0 0 1 1 1 1 0 0
0 0 0 1 1 0 1 1 0
0 0 1 1 0 0 1 1 0
0 0 1 1 1 1 1 0 0
0 0 1 1 0 1 1 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0

-> 3초 


8 9
0 0 0 0 0 0 0 0 0
0 1 1 1 1 1 1 0 0
0 1 0 1 1 0 1 1 0
0 1 0 1 0 0 1 1 0
0 1 0 1 1 1 1 0 0
0 1 1 1 0 1 1 0 0
0 1 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 0
->4 초

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

-> 6 초 




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
		//외부 공기 변형 
		//>>
		MAP[0][0]=2;
		changeExtAir(0,0);
		//<<
		//외부 공기와 접촉된 면을 찾고, 이를 없앰
		checkDel();
		
		//외부 공기와 연결된 내부 공기를 체크함,
		mergeAir();
		time++;
	}

	printf("time:%d\n",time);
}


//창훈 최종
//배열하나로 깔끔하게 풀었다. 이거 참조하도록 

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

//외부 공기와 내부 공기 분리
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

//외부 공기에 노출된 지울 치즈를 찾는다.
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

//지우기로 선정된 치즈 지우기
void remove_cheese()
{
	    for(int x=0;x<N;x++)
		for(int y=0;y<M;y++)
		{
			if(map[x][y]==DEL) map[x][y]=OUT_AIR;
		}
}

//현재 남아 있는 치즈의 수는?
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


//외부로 노출된 내부공기를 외부화한다. 
void merge_air()
{

	for(int x=0;x<N;x++)
	for(int y=0;y<M;y++)
	{
		if(map[x][y]==IN_AIR) //내부 공기니?
		{
			//외부 공기와 접해있니?
			for(int k=0;k<4;k++)
			{
				int new_x=x+dx[k];
				int new_y=y+dy[k];

				if(map[new_x][new_y]==OUT_AIR) // 걸처 있는 외부 공기가 있다면 
				{
					map[x][y]=OUT_AIR; // 현재 좌표의 공기를 외부 공기로 바꾸고 
					checkair(x,y); //주변 공기의 외부화 시작 
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
// 최종 문제 해결 - 창훈풀이 
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


//공기와 접한면을 계산하여 c로 표시한다. 
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
	  	if(count >= 2) map[i][j]=5;  // 없어져야할 값 
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
		if(map[i][j]==5)  // 없어져야할 부분
		{
			map[i][j]=0;  // 초기화 시키기 위해서 0으로 설정
		}

		if(map[i][j]==2) // 외부 공기 
		{
			map[i][j]=0;  // 초기화 시키기 위해서 0으로 설정
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
 
   while(1) //치즈가 없을때까지
   {
	display();

	  
	//치즈체크 
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
//교재풀이 
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




풀이 방법 첫번째 
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
	
//외부 공기만을 2로 채워라 
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




//외부 공기와 노출됐는지?
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
두번째 방법 한시간 마다 바깥 공기 덩어리를 체크 하지 않고
녹을때만 그자리에서 다시 연결된 공기를 체크 한다.


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


//외부 공기만을 2로 채워라 
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

//외부 공기만을 2로 채워라 
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


//외부 공기와 노출됐는지?
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


