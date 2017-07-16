/*
2
4
0100
1110
1011
1010
6
011001
010100
010011
101001
010101
111010

답 
2
2

*/

//2차원 다이젝트라.
/*
2
4
0100
1110
1011
1010
4
0100
1110
1011
1010

*/

//2차원 다이젝트라.
#include<stdio.h>

#define INF 987654321

//관용적인거 말고는 전역은 다 대문자로
int TEST_CASE;
int N;
int MAP[150][150];
int DIST[150][150]; // 시작점 부터 각각의 포인트 마다 최소 비용이 저장된다.

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

struct NODE
{
	int x;
	int y;
};

NODE Q[2000000]; //최대한 크게 잡는다. 이거 작게 잡아서 잘못된 Access가 발생하면 Segment fault 가 발생함.

int f=-1;
int r=-1;

int main(void)
{
	freopen("input.txt","r",stdin);
	
	scanf("%d",&TEST_CASE);
	for(int t=1;t<=TEST_CASE;t++)
	{
		
		scanf("%d",&N);
		for(int x=0;x<N;x++)
		for(int y=0;y<N;y++)
		{
			scanf("%1d",&MAP[x][y]); //연결된 int 한 문자씩 받기
			DIST[x][y]=INF; // 전부 무한대로 1차원 다이젝트라하고 똑같음, 1차원 대각선이 0이 되어야함.
		}
		
		DIST[0][0]=MAP[0][0]; // 중요!!! 반드시 위운다. // 중요!!! 반드시 위운다. 
		
		f=-1;
		r=-1;
		
		r++;
		Q[r].x=0;
		Q[r].y=0;
		
		while(f!=r)
		{
			
			f++;
			int xx = Q[f].x;
			int yy = Q[f].y;
			
			for(int k=0;k<4;k++)
			{
				int new_x=xx+dx[k];
				int new_y=yy+dy[k];
				
				#if 0 //둘다 가능 , 난 아래껄 선호하지만 잘 알아 두자.
				if(new_x < 0 || new_y < 0 || new_x >= N || new_y >= N ) continue;
				#else
				if(new_x>=0 && new_x<N &&
				   new_y>=0 && new_y<N)
				#endif	
				if(DIST[new_x][new_y] > DIST[xx][yy]+MAP[new_x][new_y] )
				{
					DIST[new_x][new_y] = DIST[xx][yy]+MAP[new_x][new_y];
					
					r++;   // 이부분이 하이라트임, 값을 갱신하고 그 후보군을 다시 넣어준다. 그렇게 BFS을 진행함!!
					Q[r].x=new_x;
					Q[r].y=new_y;	
				}
			}	
		}
		printf("#%d %d\n",t,DIST[N-1][N-1]);
	}
	
}




//물론 큰 배열에서 답은 나오지 않지만 백트래킹
/*
2
4
0100
1110
1011
1010
4
0100
1110
1011
1010

*/

//백트래킹으로 접근 
#include<stdio.h>

#define INF 987654321

//관용적인거 말고는 전역은 다 대문자로
int TEST_CASE;
int N;
int MAP[150][150];
int CHECK[150][150]; 

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

int min_dist=INF;

void solve(int x, int y, int sum)
{
	if(min_dist<sum) return;

	if(x==N-1 && y==N-1)
	{
		if(min_dist > sum)  min_dist=sum;
		return;
	}

	for(int k=0;k<4;k++)
	{
		int new_x=x+dx[k];
		int new_y=y+dy[k];

		if(new_x>=0 && new_x<N &&
		   new_y>=0 && new_y<N) 
		{
			if(CHECK[new_x][new_y]==0)
			{
				CHECK[new_x][new_y]=1;
				solve(new_x,new_y,sum+MAP[new_x][new_y]);
				CHECK[new_x][new_y]=0;
			}
		}
	}
}

int main(void)
{
	freopen("input.txt","r",stdin);
	
	scanf("%d",&TEST_CASE);
	for(int t=1;t<=TEST_CASE;t++)
	{
		
		scanf("%d",&N);
		for(int x=0;x<N;x++)
		for(int y=0;y<N;y++)
		{
			scanf("%1d",&MAP[x][y]); //연결된 int 한 문자씩 받기
			CHECK[x][y]=0;
		}

		CHECK[0][0]=1;
		solve(0,0,0);
		printf("#%d %d\n",t,min_dist);
	}
}




















