
//창훈 최종 필기
//백트래킹으로 풀어 보기(100x100)으론 답이 안나옴 / BFS로 풀어야 정답이 나온다 보기 
//인덱스 관련 실수한 부분이 있다. 이 부분 항상 주의하도록 
//DT테이블 적용 못한다.<못하는 이유는 필기 참조하도록>
//그래서 격자길,숙직선생님,광석 수집은 한쪽 방향으로 증가를한다. 그래서 DT테이블이 적용된다.


//미로 찾기는 목적지까지 최단 거리를 구하는데, 심장에서 피를 펌프질 한다고 생각한다.(가중치가 없기 때문에 가능하다. 가중치가 있으면 백트래킹으로 풀어야한다.)
//큐을 이용해서 BFS로 풀어야지 100 by 100이 풀린다.
#include<stdio.h>

struct LOCATION
{
	int x;
	int y;
};

int H;
int W;

char map[101][101];
int result[101][101];

LOCATION start;
LOCATION goal;

LOCATION Q[10000000];

int f=-1;
int r=-1;

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};


int solve(LOCATION start)
{
	r++;
	Q[r]=start;

	while(f!=r)
	{
		f++;

		if(Q[f].x==goal.x && Q[f].y==goal.y )
		{
			return result[goal.x][goal.y];
		}

		for(int k=0;k<4;k++)
		{
			int new_x=Q[f].x + dx[k];
			int new_y=Q[f].y + dy[k];

			if(map[new_x][new_y]=='.'  &&
               new_x >= 0 && new_x < H &&
			   new_y >= 0 && new_y < W &&  
			   result[new_x][new_y]==0
			  )
			{
			   result[new_x][new_y]=result[Q[f].x][Q[f].y]+1;
			   
			   r++;
			   Q[r].x=new_x;
			   Q[r].y=new_y;
			}
		}
	}
}

void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d %d",&H,&W);

	for(int i=0;i<H;i++)
	{
	  scanf("%s",&map[i]);
	}
}

void findLocation()
{
	for(int i=0;i<H;i++)
		for(int j=0;j<W;j++)
		{
			if(map[i][j]=='S'){start.x=i;start.y=j;}
			if(map[i][j]=='G'){goal.x=i;goal.y=j;map[i][j]='.';}
		}
}

void main()
{
    input();
	findLocation();
	printf("%d",solve(start));
	
}







//backtracking으로 풀이
//100 X 100 문제이다. Backtracking으로 답이 안나옴
#include<stdio.h>

int h;
int w;

struct Cord
{
	int x;
	int y;
};


Cord start;
Cord goal;

char map[100][100];

int dx[4]={-1,0,1,0};
int dy[4]={ 0,1,0,-1};

int min_dist=987654321;

void input()
{
	freopen("input.txt","r",stdin);
	
	scanf("%d %d",&h,&w);
	for(int x=0;x<h;x++)
	scanf("%s",&map[x]);
}

void findLocation()
{
	for(int x=0;x<h;x++)
	for(int y=0;y<w;y++)
	{
		if('S'==map[x][y]){start.x=x; start.y=y; map[x][y]='.';}
		if('G'==map[x][y]){goal.x=x; goal.y=y; map[x][y]='.';}
	}
}

void printMap()
{
	for(int x=0;x<h;x++)
	{
	  printf("%s\n",map[x]);
	}
}

void solve(Cord loc,int len)
{
	//printf("loc.x:%d loc.y:%d len:%d\n",loc.x,loc.y,len);

	if(loc.x == goal.x && loc.y == goal.y)
	{
		//printf("%d\n",len);
		//printMap();

		if( min_dist > len ) min_dist=len; 
		return;
	}

	for(int k=0;k<4;k++)
	{
		int new_x=loc.x+dx[k];
		int new_y=loc.y+dy[k];

		//printf("new_x.x:%d new_x.y:%d len:%d\n",new_x,new_y,len);

		if(map[new_x][new_y]=='.' &&  //여기 인덱스 실수 
          (new_x >= 0 && new_y >= 0) && 
		  (new_x < h && new_y < w)  
		)
		{
			map[new_x][new_y]='1'; // 여기 인덱스 실수 
			Cord new_loc;
			new_loc.x=new_x;
			new_loc.y=new_y;
			//printf("move new_x.x:%d new_x.y:%d len:%d\n",new_x,new_x,len);
			solve(new_loc,len+1);
			map[new_x][new_y]='.';
		}
	}
}

void main()
{
input();
findLocation();
map[start.x][start.y]='1';
solve(start,0);

if(min_dist==987654321)
printf("min_dist:-1");
else
printf("min_dist:%d",min_dist);

}
















//이후는 그냥 참조하도록 
///////////////////////////////////////////////////////////////////

문제 분석및 접근 방법
BFS, DFS로 풀수가 있음.

가장 효율적인 방법 
가중치가 없을경우 BFS가 제일 용이하다. 접근 이 문제는 특별한 가중치가 없이 이동하는 거리가 최단거리임.
(리모콘 문제하고 흡사함. 처음 해당(Goal이든 특정 위치이든) 위치를 터치한 녀석이 최단 거리인것임 Goal에 도착하면 break 함)
 
DFS 접근 흔적 지우기 기법을 사용함으로 최단 거리를 구할 수 있다.


>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
입력
5 5
#S###
#...#
#.#.#
#....
###G#

-> 6


10 10
#S####...#
#...##...#
#.#.##.#.#
#.........
######...#
#G####...#
#...##...#
#.#.##...#
#........#
######...#

->21


입력
첫 번째 줄에 h와 w가 공백으로 구분되어 입력된다.
(단, h, w는 5 이상 100 이하의 자연수이다.)
두 번째 줄부터 h줄에 걸쳐서 w개로 이루어진 문자열이 입력된다.
문자열은 길은 ".", 벽은 "#", 출발점은 "S", 도착점은 "G"로 표시된다. 그리고 S와
G의 위치는 서로 다르다

출력
출발지로부터 도착지까지의 최단거리를 출력한다.
단, 도달할 수 없는 미로일 경우에는 -1을 출력한다


>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// 교재 방식 BFS를 이용한 접근방식
// Queue의 큰장점 엄청나게 큰수를 두고 작업을 할 수 있다.
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//미로찾기
/*
10 10
#S####...#
#...##...#
#.#.##.#.#
#.........
######...#
#G####...#
#...##...#
#.#.##...#
#........#
######...#
*/


#include<stdio.h>

char map[100][100];
int result[100][100];

int h;
int w;

struct Cord 
{
	int i;
	int j;
} ;

Cord node[10000];
int f=-1;
int r=-1;

Cord start;
Cord goal;

// 4방향에 대해서
int dx[4]={-1,0,1,0}, dy[4]={0,1,0,-1};

int check(int i, int j)
{
	return (i>= 0 && i<h) && (j>=0 && j<w); 	
}

void display()
{
		for(int i=0;i<h; i++)
		{
			for(int j=0;j<w; j++)
			{
				printf(" %d",result[i][j]);
			}
			printf("\n");
		}
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
}

void solve(int i,int j)
{
	r++;
	node[r].i=i;
	node[r].j=j;
	
	while(f!=r)
	{
		f++;
		if(node[f].i==goal.i && node[f].j==goal.j)
		{
			display();
			break;
		}
		
		for(int k=0;k<4;k++)
		{
			int new_i=node[f].i+dx[k];
		    int new_j=node[f].j+dy[k];
		
            if( result[new_i][new_j]==0 &&
				map[new_i][new_j]=='.' &&
				check(new_i,new_j)==1
			  )		
			  {
				  	r++;
					node[r].i=new_i;
					node[r].j=new_j;
					
					result[new_i][new_j]=result[node[f].i][node[f].j]+1;
					
				  
			  }
		
		}
	}
	
}

void main()
{
	freopen("input.txt","r",stdin);
	scanf("%d %d",&h,&w);
	
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
		{ 
			scanf(" %c",&map[i][j]);
			
			if(map[i][j]=='S'){start.i=i;start.j=j;}
			if(map[i][j]=='G'){goal.i=i;goal.j=j;}
		}
	
	map[goal.i][goal.j]='.';
	result[start.i][start.j]=0;
	solve(start.i,start.j);

	if(result[goal.i][goal.j]==0)
	printf("-1");
	else 
    printf("%d",result[goal.i][goal.j]);
}

///////////////////////////////////////////////////////////
//백트레킹
//창훈이 직접품.
///////////////////////////////////////////////////////////

//미로찾기
#include<stdio.h>

char map[100][100];

int h;
int w;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

struct Cord{
	int i;
	int j;
};

void getFindS(Cord *start,Cord *goal)
{

		for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
		{
			if(map[i][j]=='S')
			{
				start->i=i;
				start->j=j;
			}

			if(map[i][j]=='G')
			{
				goal->i=i;
				goal->j=j;
			}
		}
}

int check(int i,int j)
{
	return ( (i >= 0 && i< h ) && ( j >= 0 && j < w ) ); 
}

void display()
{
	for(int i=0;i<h;i++)
	{
	    for(int j=0;j<w;j++)
		{ 
			printf("%c",map[i][j]);
	    }
		printf("\n");
	}
	printf(">>>>>>>>>>>>>>>>>>>>>>\n");
}


int min_count=987654321;
Cord start;
Cord goal;

void solve(int i, int j,int count)
{

	if(goal.i==i && goal.j==j)
	{
		if( min_count > count) min_count=count;
	    return;
	}

	for(int k=0;k<4;k++)
	{
		if( map[i+dx[k]][j+dy[k]] != '#' &&  // 벽이 아니고
			map[i+dx[k]][j+dy[k]] != '2' &&  // 왔던길이 아니고
		    check(i+dx[k],j+dy[k]) == 1      // 경계를 벗어나지 않았다면
		)
		{
			//printf("%d\n",count);
			//display();
			map[i+dx[k]][j+dy[k]] = '2'; 
		    solve(i+dx[k],j+dy[k],count+1);
			map[i+dx[k]][j+dy[k]] = '.';
		}
	}

}


void main()
{
	freopen("input.txt","r",stdin);
	scanf("%d %d",&h,&w);
	
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
		{ scanf(" %c",&map[i][j]);}

	display();

	getFindS(&start,&goal);
	
	map[start.i][start.j]='2';
	map[goal.i][goal.j]='0';
	//display();
	solve(start.i,start.j,0);

	if(min_count==987654321) printf("-1");
	else printf("%d",min_count);
}

//////////////////////////////////////////////////////
//아래 미로 문제는 미로를 마스터 하기위한 응용 문제 !! 나중에 로봇 만들때 응용하자.!
//  1. 가중치가 있고 최단거리와 최단경로 ,S와 G는 위치만 주어지고 가중치는 0임.
// BFS 풀이. - 가중치가 있기 때문에 최초 터치가 아니라, 전체를 다 뒤져 봐야한다. 즉 흔적 지우기가 들어 가야함. 
//            구조체 안에 checked를 유지해야함. 그래서 관리가 불편함.
// DFS 풀이. - 아래 풀이,
//////////////////////////////////////////////////////

1.
1~9까지 가중치가 존재한다.

2.
S,G 자리는 가중치가 0이다.


10 10
#S####111#
#115##111#
#1#5##1#1#
#122111111
#1####111#
#1####1###
#111#1111#
#1#1##155#
#1111G111#
######111#


16 16
#S####111#1##1#1
#115##111#1##1#1
#1#5##1#1#1##1#1
#122111111111111
#1####111#1##1#1
#1###########1#1
#111#1111#1##1#1
#1#1##15G#5##5#5
#111#5111#1##1#1
##2###999#1##1#1
##2###111#1##1#1
##22#1999#1##1#1
##2###991111#111
##99#9991#1##1#1
##2###9911111111
##9919991#1##1#1

#include<stdio.h>

char map[100][100];

int checked[100][100];
int result[100][100];

int freq[10000];

int h;
int w;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

struct Cord{
	int i;
	int j;
};

void getFindS(Cord *start,Cord *goal)
{

		for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
		{
			if(map[i][j]=='S')
			{
				start->i=i;
				start->j=j;
			}

			if(map[i][j]=='G')
			{
				goal->i=i;
				goal->j=j;
			}
		}
}

int check(int i,int j)
{
	return ( (i >= 0 && i< h ) && ( j >= 0 && j < w ) ); 
}

void display(int arr[][100])
{
	for(int i=0;i<h;i++)
	{
	    for(int j=0;j<w;j++)
		{ 
			printf("   %d",arr[i][j]);
	    }
		printf("\n");
	}
	printf(">>>>>>>>>>>>>>>>>>>>>>\n");
}

void display_map(char arr[][100])
{
	for(int i=0;i<h;i++)
	{
	    for(int j=0;j<w;j++)
		{ 
			printf(" %c",arr[i][j]);
	    }
		printf("\n");
	}
	printf(">>>>>>>>>>>>>>>>>>>>>>\n");
}



int min_count=987654321;
Cord start;
Cord goal;

void solve(int i, int j,int count)
{
	if(min_count < count) return;

	if(goal.i==i && goal.j==j)
	{
		if( min_count > count)
		{
			min_count=count;

			freq[count]++; 
			
			for(int i=0;i<h;i++)
			{
				for(int j=0;j<w;j++)
				{ 
					result[i][j]=checked[i][j];
				}
			}

		}
	    return;
	}

	for(int k=0;k<4;k++)
	{
		if( map[i+dx[k]][j+dy[k]] != '#' &&       // 벽이 아니고
			checked[i+dx[k]][j+dy[k]] == 0 &&    // 왔던길이 아니고
		    check(i+dx[k],j+dy[k]) == 1      // 경계를 벗어나지 않았다면
		)
		{
			checked[i+dx[k]][j+dy[k]] = count+ ( map[i+dx[k]][j+dy[k]] - '0'); // 길은 1~9까지 가중치 존재한다.
		    solve(i+dx[k],j+dy[k],count+ ( map[i+dx[k]][j+dy[k]] - '0'));
			checked[i+dx[k]][j+dy[k]] = 0;
		}
	}

}


void main()
{
	freopen("input.txt","r",stdin);
	scanf("%d %d",&h,&w);
	
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
		{ scanf(" %c",&map[i][j]);}

	//display();

	getFindS(&start,&goal);
	
	//checked[goal.i][goal.j]=1; // 마지막 골인 지점을 방문했다고 표시하면 절대 안됨!! 
	                             // 0 으로 방문 가능해야함

	map[start.i][start.j]='0';  // 이거 실수했다. 가중치는 입력 아스키다. 후보군 설정시 아스키를 숫자를 바꾼다!!! 
    map[goal.i][goal.j]='0';    //


	display_map(map);

	solve(start.i,start.j,0);

	if(min_count==987654321) printf("cost : -1\n");
	else printf("cost : %d\n",min_count);  
	// 동일한 최소비용의 여러 해가 있을 수 있는데 이중 하나를 표시한다.

	display(result);
}