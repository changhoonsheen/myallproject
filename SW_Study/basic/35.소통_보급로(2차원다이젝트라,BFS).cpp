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

�� 
2
2

*/

//2���� ������Ʈ��.
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

//2���� ������Ʈ��.
#include<stdio.h>

#define INF 987654321

//�������ΰ� ����� ������ �� �빮�ڷ�
int TEST_CASE;
int N;
int MAP[150][150];
int DIST[150][150]; // ������ ���� ������ ����Ʈ ���� �ּ� ����� ����ȴ�.

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

struct NODE
{
	int x;
	int y;
};

NODE Q[2000000]; //�ִ��� ũ�� ��´�. �̰� �۰� ��Ƽ� �߸��� Access�� �߻��ϸ� Segment fault �� �߻���.

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
			scanf("%1d",&MAP[x][y]); //����� int �� ���ھ� �ޱ�
			DIST[x][y]=INF; // ���� ���Ѵ�� 1���� ������Ʈ���ϰ� �Ȱ���, 1���� �밢���� 0�� �Ǿ����.
		}
		
		DIST[0][0]=MAP[0][0]; // �߿�!!! �ݵ�� �����. // �߿�!!! �ݵ�� �����. 
		
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
				
				#if 0 //�Ѵ� ���� , �� �Ʒ��� ��ȣ������ �� �˾� ����.
				if(new_x < 0 || new_y < 0 || new_x >= N || new_y >= N ) continue;
				#else
				if(new_x>=0 && new_x<N &&
				   new_y>=0 && new_y<N)
				#endif	
				if(DIST[new_x][new_y] > DIST[xx][yy]+MAP[new_x][new_y] )
				{
					DIST[new_x][new_y] = DIST[xx][yy]+MAP[new_x][new_y];
					
					r++;   // �̺κ��� ���̶�Ʈ��, ���� �����ϰ� �� �ĺ����� �ٽ� �־��ش�. �׷��� BFS�� ������!!
					Q[r].x=new_x;
					Q[r].y=new_y;	
				}
			}	
		}
		printf("#%d %d\n",t,DIST[N-1][N-1]);
	}
	
}




//���� ū �迭���� ���� ������ ������ ��Ʈ��ŷ
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

//��Ʈ��ŷ���� ���� 
#include<stdio.h>

#define INF 987654321

//�������ΰ� ����� ������ �� �빮�ڷ�
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
			scanf("%1d",&MAP[x][y]); //����� int �� ���ھ� �ޱ�
			CHECK[x][y]=0;
		}

		CHECK[0][0]=1;
		solve(0,0,0);
		printf("#%d %d\n",t,min_dist);
	}
}




















