/*
2
1 2 60 60
10 20 30 40 10
5 20 59 59 5

29
/////////////////

2
2 2 60 60 
10 20 30 40 1
5 20 59 59 10

33
/////////////////

5
1 2 70 70
11 20 31 40 10
12 30 12 40 20
13 20 33 40 10
14 30 14 40 30 
15 20 35 40 40 

backtracking min time :107
0.033000 sec

Dijacktra min time :107
0.000000 sec


*/




#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct LOC
{
	int x;
	int y;
};

int times[20];

int worm_N;//입력받은 웜홀 수
int N;     //전체 노드의 수(worm_N*2 + 2(시작노드+도착노드))

LOC loc[20]; //시작 노드 , ... <웜홀 노드> ..., 도착노드
int check[20];

int map[20][20];

int abs(int a)
{
	return a<0 ? a*(-1):a;
}

int getTime(int a, int b)
{
	return ( abs(loc[a].x-loc[b].x) + abs(loc[a].y-loc[b].y) );
}


void display_map()
{
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				printf("%d ",map[i][j]);
			}
			printf("\n");
		}

		printf(">>>>>>>>>>>>>>>\n");
}


void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d",&worm_N);
	N=(worm_N*2)+2;

	//시작점을 처음과 도착점을 마지막에 위치한다.
	scanf("%d %d %d %d",&loc[0].x,&loc[0].y,&loc[N-1].x,&loc[N-1].y);


	//웜홀을 하나의 노드로 입력받는다.
	int k=0;
	for(int i=1;i<N-1;i+=2)
	{
		int time; // 시간을 다른 배열에 입력받는다.
		scanf("%d %d %d %d %d",&loc[i].x,&loc[i].y,&loc[i+1].x,&loc[i+1].y,&times[k]);
		k++;
	}

	//모든 거리를 계산함.
	for(int i=0; i<N; i++)
	for(int j=0; j<N; j++)
	{
			if(i==j) continue;
			map[i][j]=map[j][i]=getTime(i,j);
	}

	//display_map();


	//웜홀 업데이트 // 여기 실수했음 , 찍어 보고 써봐라 실수한다.
	int node_count=1;
	for(int i=0;i<worm_N;i++)
	{
		 int node1=node_count++; //1번 노드 부터 웜홀 임 
		 int node2=node_count++; //이렇게찍어 봐야 알듯

		//printf("update ->  node : %d -  node :%d  time :%d\n",node1,node2,times[i]);

		map[node1][node2]=map[node2][node1]=times[i];
	}

	//display_map();

}


int min_backtracking_time=987654321;
void f(int v, int t)
{
	if(min_backtracking_time < t) return;

	if(v==N-1)
	{
		if(min_backtracking_time > t) min_backtracking_time=t;

		return;
	}

	for(int i=0;i<N;i++)
	{
		if(check[i]==0 && map[v][i])
		{
			check[i]=1;
			f(i,t+map[v][i]);
			check[i]=0;
		}

	}

}


int DIST[20];
int check_v[20];

int IsitPossible()
{
	for(int i=0;i<N;i++)
	{
		if(check_v[i]==0) return 1;
	}

	return 0;
}

int getNode()
{
	int min_value=987654321;
	int node=0;

	for(int i=0;i<N;i++)
	{
		if(check_v[i]==0 && min_value > DIST[i] )
		{
			min_value=DIST[i];
			node=i;
		}
	}

	return node;
}

int MIN(int a, int b)
{
	return a>b?b:a;
}

void dijtra()
{
	//copy
	for(int i=0;i<N;i++)
	DIST[i]=map[0][i];

	while(IsitPossible())
	{
		int w=getNode();
		check_v[w]=1;

		for(int v=0;v<N;v++)
		{
			DIST[v]=MIN(DIST[v],DIST[w]+map[w][v]);
		}
	}

}


void main()
{
	input();

	int start;

	start=clock();
	//Backtracking
	f(0,0);
	printf("backtracking min time :%d\n",min_backtracking_time);
	printf("%f sec\n\n",(double)(clock()-start)/CLOCKS_PER_SEC);

	//Dijactra
	start=clock();
	dijtra();
	printf("Dijacktra min time :%d\n",DIST[N-1]);
	printf("%f sec\n\n",(double)(clock()-start)/CLOCKS_PER_SEC);
}








//다른 풀이 참조하도록 
//>>>>>>>>>>>>>>>>>>>


#include<stdio.h>

struct Cord
{
	int x;
	int y;
};

struct Wormhole
{
	Cord e[2];     //두 출입구
	int vertex[2]; //정점으로 할당될때 번호 이걸 보고 인접행렬의 time을 할당한다.
	int time;
};

Cord vertex[100];
Wormhole worm[10];

int arr[100][100];

int n;  //wormhole의 갯수
int v;  //정점들의 수

int dist[100];
int chk[100];


int abs(int a)
{
	return a<0 ? a*(-1) : a;
}


int getDistance(Cord a, Cord b)
{
	return abs(a.x-b.x) + abs(a.y-b.y);
}

void makeMatrix()
{
	for(int i=0;i<v;i++)
	for(int j=0;j<v;j++)
	{
		arr[i][j]=getDistance(vertex[i],vertex[j]);
	}
	
	//set wormhole time
	for(int i=0;i<n;i++)
	{
		arr[worm[i].vertex[0]][worm[i].vertex[1]]=worm[i].time;
		arr[worm[i].vertex[1]][worm[i].vertex[0]]=worm[i].time;	
	}
}

void printMatrix()
{
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			printf(" %d ",arr[i][j]);
		}
		printf("\n");
	}
	printf("---------------\n");
}

void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	
	int startx,starty,endx,endy;
	
	scanf("%d %d %d %d",&startx,&starty,&endx,&endy);
	
	v=0;
	vertex[v].x=startx;
	vertex[v].y=starty;
	
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d %d %d",
		       &worm[i].e[0].x,&worm[i].e[0].y,&worm[i].e[1].x,&worm[i].e[1].y,&worm[i].time);
			   
		v++;
		vertex[v].x=worm[i].e[0].x;
		vertex[v].y=worm[i].e[0].y;
		worm[i].vertex[0]=v;  //여기 실수했다. 해당 정점의 인덱스가 필요
		
		v++;
		vertex[v].x=worm[i].e[1].x;
		vertex[v].y=worm[i].e[1].y;
		worm[i].vertex[1]=v; //여기 실수했다.
	}
	
	v++;
	vertex[v].x=endx;
	vertex[v].y=endy;
	
	v++;
}


//u!=v , 아직 선택될 노드가 남아 있다면
int ispossible()
{
	for(int i=0;i<v;i++)
	{
		if(chk[i]==0) return 1;
	}
	return 0;
}

int getBestNode()
{
	int w=0;
	int min_dist=987654321;

	for(int i=0;i<v;i++)
	{
		if(!chk[i])
		{
			if(min_dist > dist[i])
			{
				min_dist=dist[i];
				w=i;
			}
		}
	}

	return w;
}

int MIN (int a, int b)
{
	return a > b ? b : a;
}


int shortest_time()
{
	for(int i=0;i<v;i++)
	{
		dist[i]=arr[0][i];
	}

	while(ispossible())
	{
		int w=getBestNode();
		chk[w]=1;

		for(int i=0;i<v;i++)
		{
			dist[i]=MIN(dist[i],dist[w]+arr[w][i]);
		}
	}

	return dist[v-1];
}

int chk_backtracking[100];
int mintime=987654321;
void backtracking(int k, int w)
{
	if(k==v-1)
	{
		if(mintime>w) mintime=w;
		return;
	}

	for(int i=0;i<v;i++)
	{
		if(!chk_backtracking[i] && arr[k][i])
		{
			chk_backtracking[i]=1;
			backtracking(i,w+arr[k][i]);
			chk_backtracking[i]=0;
		}
	}
}


void main()
{
	input();
	makeMatrix();
	printMatrix();

	backtracking(0,0);
	printf("backtracking min time:%d\n",mintime);
	
	printf("dijktra min time:%d\n",shortest_time());
	
}

