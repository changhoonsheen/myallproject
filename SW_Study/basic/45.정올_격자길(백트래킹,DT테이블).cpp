//창훈 최종 필기
//Backtracking으로 풀어 보고 Base에서 1을 올리고 이 모든 후보군을 계속 더해서 올리며됩니다.
//광석 수집과 유사한 문제임.


#include<stdio.h>

int n;//x
int m;//y;

int func_call;

int dx[]={0,1};
int dy[]={1,0};

int solve_count;
int DT[100][100];


void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d %d",&n,&m);
}

int Isitpossible(int x,int y)
{
	float new_y=(float)((float)m/(float)n)*(float)x;

	if((float) y <= new_y) return 1;
	else return 0;
}

int solve(int x, int y)
{
	if(DT[x][y]!=-1) return DT[x][y];
	func_call++;

	if(n==x && m==y)
	{
		return DT[x][y]=1;
	}

	int sum=0;
	for(int i=0;i<=1;i++)
	{
		int new_x=x+dx[i];
		int new_y=y+dy[i];

		if((new_x <=n && new_y<=m) &&   //경계 체크 
		    Isitpossible(new_x,new_y)	//y절편 체크 
			)
		sum=sum+solve(new_x,new_y); // 여기 실수했다. 트리 그려보도록 
	}

	return DT[x][y]=sum;
}

int main()
{
	input();

	for(int i=0;i<100;i++)
	for(int j=0;j<100;j++)
		DT[i][j]=-1;

	printf("%d\n",solve(0,0));
	printf("func_call:%d\n",func_call);
}