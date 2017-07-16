/*
2 3 4 0
1 5 7 8
9 6 10 12
13 14 11 15


답
이동횟수 9회
L L L D R D R D R 
























*/
//백트래킹 접근
#include<stdio.h>

#define SIZE 4

int MAP[SIZE][SIZE];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

char dir[]={'U','R','D','L'};

int start_x;
int start_y;

int stack[100000];
int top=-1;

int result_stack[100000];
int result_top=987654321;

void input()
{
	freopen("input.txt","r",stdin);
	
	for(int i=0;i<SIZE;i++)
	for(int j=0;j<SIZE;j++)
	{
		scanf("%d",&MAP[i][j]);
		if(MAP[i][j]==0)
		{
				start_x=i;
				start_y=j;
		}	
	}		
}

int Isitsolution()
{
	if(MAP[0][0]==1 && MAP[0][1]==2 && MAP[0][2]==3 && MAP[0][3]==4 &&
	   MAP[1][0]==5 && MAP[1][1]==6 && MAP[1][2]==7 && MAP[1][3]==8 && 
	   MAP[2][0]==9 && MAP[2][1]==10 && MAP[2][2]==11 && MAP[2][3]==12 &&
	   MAP[3][0]==13 && MAP[3][1]==14 && MAP[3][2]==15 && MAP[3][3]==0
	)
	{
		return 1;
	}

	   return 0;
}

void solve(int i,int x, int y)
{
	if(result_top < top) return;
	
	if(Isitsolution())
	{
		if(result_top > top)
		{
			result_top=top;
			for(int k=0;k<=top;k++)
			result_stack[k]=stack[k];
		}
		return; 
	}
	
	if(i>=20)
	{
		return;
	}
	
	for(int k=0;k<4;k++)
	{
		int new_x=x+dx[k];
		int new_y=y+dy[k];
		
		if(new_x<0 || new_x>=SIZE ||
		   new_y<0 || new_y>=SIZE 
		  ) continue;
		
		if(top>=0) // history 보관을 위해서
		{
			int previous_dir=stack[top]; //이 부분 실수함!! 삽질했음.. 난 Top--이라고함.
			
			if(previous_dir==0 && k==2) continue;    // 왔던길 못가게 하기 위해서.
			if(previous_dir==2 && k==0) continue;
			if(previous_dir==1 && k==3) continue;
			if(previous_dir==3 && k==1) continue;
		}
		
		MAP[x][y]=MAP[new_x][new_y];
		MAP[new_x][new_y]=0;
		
		top++;   //히스토리 저장을 위한 기법 익혀 놓도록 
		stack[top]=k;
		
		solve(i+1,new_x,new_y);
		
		top--;
		
		MAP[new_x][new_y]=MAP[x][y];
		MAP[x][y]=0;
	}	
}


void main()
{
	input();
	solve(0,start_x,start_y);
	
	for(int k=0;k<=result_top;k++)
	printf("%c",dir[result_stack[k]]);

	printf("\nMove count:%d\n",result_top+1);
}


///////////////////////////////////////////////////>>>


/*

/*
2 3 4 0
1 5 7 8
9 6 10 12
13 14 11 15


답
이동횟수 9회
L L L D R D R D R

*/

#include<stdio.h>

int N=4;

int map[4][4];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

struct CORD
{
	int x;
	int y;
};

int stack[100000];
int top = 0;

int result[100000];

CORD start;

void input()
{
	freopen("input.txt", "r", stdin);

	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
	{
		scanf("%d", &map[i][j]);

		if (map[i][j] == 0){ start.x = i; start.y = j; }
	}

}

int isitbase()
{
	if (
		map[0][0] == 1 && map[0][1] == 2 && map[0][2] == 3 && map[0][3] == 4 &&
		map[1][0] == 5 && map[1][1] == 6 && map[1][2] == 7 && map[1][3] == 8 &&
		map[2][0] == 9 && map[2][1] == 10 && map[2][2] == 11 && map[2][3] == 12 &&
		map[3][0] == 13 && map[3][1] == 14 && map[3][2] == 15 && map[3][3] == 0
		)
		return 1;

	return 0;
}

int check_bound(int new_x, int new_y)
{

	if (new_x >= 0 && new_y >= 0 && new_x < N && new_y < N)
	{
		return 1;
	}
	
	return 0;

}

int ABS(int a)
{
	return a < 0 ? a*(-1) : a;
}

int MIN_LEN = 987654321;

void solve(int x, int y , int count)
{

	if (count > 15) return;

	if (isitbase())
	{
		if (MIN_LEN > count)
		{
			MIN_LEN = count;

			for (int i = 0; i <= count; i++)
			{
				result[i] = stack[i];
			}
		}
		return;
	}


		for (int i = 0; i < 4; i++)
		{
			int new_x = x + dx[i];
			int new_y = y + dy[i];

			if (top >= 1)  //이부분이 명료하게 생각이 안남.!!!
				if (ABS(stack[top] - i) == 2) continue;


			if (check_bound(new_x, new_y))
			{
				top++;
				stack[top] = i;

				map[x][y] = map[new_x][new_y];
				map[new_x][new_y] = 0;

				solve(new_x, new_y, count + 1);

				top--;
				map[new_x][new_y] = map[x][y];
				map[x][y] = 0;

			}

		}



}

void main()
{
	input();
	solve(start.x , start.y , 0);

	for (int i = 1; i <= MIN_LEN; i++)
	{
		if (result[i] == 0){ printf("U "); continue; }
		if (result[i] == 1){ printf("R "); continue; }
		if (result[i] == 2){ printf("D "); continue; }
		if (result[i] == 3){ printf("L "); continue; }
	}

	printf("\n");

}