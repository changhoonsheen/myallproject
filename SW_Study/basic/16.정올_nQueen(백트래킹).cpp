

//창훈 최종 필기

//백트래킹의 아주 기본적인 문제
//N 퀸 문제 상하 좌우뿐만 아니라, Inc 대각선, dec 대각선까지 고려해야한다.
//inc,dec 대각선 처리는 더해보고 빼본다 무슨 규칙이 있을 것이다.


#include<stdio.h>

int N;

//이거 3개론 선택된거 복원 안됨.
int check[100];
int check_inc[100];
int check_dec[100];

int solve_map[1000][100][100]; //solution 수, x,y 좌표
int solve_count;

int map[100][100];

void solve(int r)
{
	if(r==N+1)
	{
		for(int x=1;x<=N;x++)
        for(int y=1;y<=N;y++)
		{
			solve_map[solve_count][x][y]=map[x][y];
		}

	    solve_count++;

		return;
	}

	for(int i=1;i<=N;i++)
	{
		if( check[i]==0 &&
			check_inc[r+i]==0 &&
			check_dec[i-r+N]==0   // 여기 더해주는 값음 상수가 아니다. 실수함 4x4 일땐 개산하면 3임
		  )
		{
			check[i]=1;
			check_inc[r+i]=1;
			check_dec[i-r+N]=1;
			map[r][i]=1; // 체스판 표시를 위해서

			solve(r+1);
				
			map[r][i]=0;
			check[i]=0;
			check_inc[r+i]=0;
			check_dec[i-r+N]=0;
		}
	}
}


void main()
{
	scanf("%d",&N);
	solve(1);
	printf("solution count:%d\n",solve_count);

	for(int k=0;k<solve_count;k++)
	{
		for(int x=1;x<=N;x++)
		{
			for(int y=1;y<=N;y++)
			{
				printf(" %d",solve_map[k][x][y]);
			}
			printf("\n");
		}
		printf("----------------------- \n");
	}


}





//창훈 최종
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/////////////////////////////////////////////////////////////


#include<stdio.h>

int check[10];
int check_inc[10];
int check_dec[10];

int N;

int solve_count;
void solve(int r)
{
	if(r==N+1)
	{
		solve_count++;
		return;
	}

	for(int i=1;i<=N;i++)
	{
		if( check[i]==0 &&
			check_inc[r+i]==0 &&
			check_dec[i-r+N]==0   // 여기 더해주는 값음 상수가 아니다. 실수!!!
		  )
		{
			check[i]=1;
			check_inc[r+i]=1;
			check_dec[i-r+N]=1;

			solve(r+1);

			check[i]=0;
			check_inc[r+i]=0;
			check_dec[i-r+N]=0;
		}
	}
}


void main()
{
	scanf("%d",&N);
	solve(1);
	printf("%d",solve_count);
}



//////////////////////////////////


#include<stdio.h>
int n, ans, col[10], inc[20], dec[20];

void solve(int r)
{
	if(r>n)
	{
		ans++;
		return;
	}
	
	for(int i=1; i<=n; i++)
	if(!col[i] && !inc[r+i] && !dec[n+(r-i)])
	{
		col[i]=inc[r+i]=dec[n+(r-i)]=1;
		solve(r+1);
		col[i]=inc[r+i]=dec[n+(r-i)]=0;
	}

}

int main()
{
	scanf("%d", &n);
	solve(1);
	printf("%d", ans);
}

////////////////////////////////////////
//퀸을 놓은 위치 출력
////////////////////////////////////////

#include<stdio.h>
int n, ans, col[10], inc[20], dec[20];
int col_hist[10];

int solultion;

void solve(int r)
{
	if(r>n)
	{
		printf("%d\n",++solultion);
   		for(int i=1; i<=n; i++)
		{
		 printf("row:%d  col:%d\n",i,col_hist[i]);
		}

		printf("\n");
		ans++;
		return;
	}
	
	for(int i=1; i<=n; i++)
	if(!col[i] && !inc[r+i] && !dec[n+(r-i)])
	{
		col_hist[r]=i; // row에 맞게 하나씩 col 값이 들어간다. 각 row별로 뭘 선택했는지 알수있다.
		col[i]=inc[r+i]=dec[n+(r-i)]=1;
		solve(r+1);
		col[i]=inc[r+i]=dec[n+(r-i)]=0;
	}

}

int main()
{
	scanf("%d", &n);
	solve(1);
	printf("%d", ans);
}
////////////////////////////////////////

/*
N퀸 문제 스택을 이용한 풀이
*/

#include<stdio.h>

struct Node{
	int row;
	int col;
	
	int checked; // 32 bit check
	int inc;
	int dec;
};

int n;

Node node[10000];
int top=-1;

int count;

void f(int row)
{
	top++;
	node[top].row=row;
	
	while(top!=-1)
	{

	int new_row = node[top].row;
	int new_col = node[top].col;
	
	int new_checked= node[top].checked;
	int new_inc= node[top].inc;
	int new_dec= node[top].dec;


	top--;
		
		if(new_row==n)
		{

			count++;
			continue;
		}
		
		for(int i=n-1;i>=0;i--)
		{
			if(  (new_checked & (1<<i))==0 &&
			     (new_inc & (1<<(i+new_row)))==0  &&
				 (new_dec & (1<<((n-1)+(new_row-i))))==0
			)
			{		
				
			  top++;	
			  node[top].row=new_row+1;			
			  node[top].col=i;	
			  node[top].checked=new_checked + (1<<i); 
			  node[top].inc=new_inc + (1<<(i+new_row));	
			  node[top].dec=new_dec + (1<<((n-1)+(new_row-i)));	
			 		
			}
		
		}
	}
}

void main()
{

n=4;

f(0);	

printf("%d",count);
	
}
