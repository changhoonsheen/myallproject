/*
6 5
0 1 0 0 0 0
1 0 0 0 0 0 
0 1 0 1 0 0
0 0 0 0 0 0 
0 0 0 0 0 1
답 1

7 7 
1 0 1 0 1 0 0
1 0 0 1 0 0 1
0 0 0 0 0 1 1
1 1 1 0 0 1 1 
0 0 0 1 1 0 1
1 0 1 1 0 1 0
0 0 1 0 0 0 0
답 6


2
6 5
0 1 0 0 0 0
1 0 0 0 0 0 
0 1 0 1 0 0
0 0 0 0 0 0 
0 0 0 0 0 1
7 7 
1 0 1 0 1 0 0
1 0 0 1 0 0 1
0 0 0 0 0 1 1
1 1 1 0 0 1 1 
0 0 0 1 1 0 1
1 0 1 1 0 1 0
0 0 1 0 0 0 0


*/




//Debugging 버젼으로 문제를 뜯어 보는 -  풀이 

#include<stdio.h>

#define SIZE 50
#define INF 987654321

int W;
int H;
int TEST_CASE;
int MIN_DIST=INF;

int MAP[SIZE][SIZE];
int CHECK[SIZE][SIZE];

struct CORD
{
	int x;
	int y;
};

CORD HOUSE[SIZE*SIZE];
int HOUSE_COUNT;

CORD POINT[SIZE*SIZE];
int POINT_COUNT;

int PAVE_COUNT;
int abs(int a)
{
	return a<0? a*(-1) : a;
}

int getDIST(int x, int y, int house_num)
{
	return abs( x - HOUSE[house_num].x) + abs(y - HOUSE[house_num].y);
}

int MAX(int a, int b)
{
	return a>b ? a:b;
}

int MIN(int a, int b)
{
	return a<b ? a:b;
}


//도로 포장후 최대로 먼거리의 반환
int getDISTANCE()
{
	int h_max_dist=0;

	for(int h=0;h<HOUSE_COUNT;h++)
	{
		int h_min_dist=987654321;

	 	for(int i=0;i<H;i++)
		for(int j=0;j<W;j++)
		{
			if(MAP[i][j]==2)
			h_min_dist=MIN(h_min_dist,getDIST(i,j,h));
		}
	
		h_max_dist=MAX(h_max_dist,h_min_dist);

	}

	return h_max_dist;
}


void input()
{
	scanf("%d %d",&W,&H);

	for(int i=0;i<H;i++)
	for(int j=0;j<W;j++)
	{
		scanf("%d",&MAP[i][j]);
		if(MAP[i][j]==1)
		{
			HOUSE[HOUSE_COUNT].x=i;
			HOUSE[HOUSE_COUNT].y=j;
			HOUSE_COUNT++;
		}
	}
}

void init()
{
 MIN_DIST=INF;
 HOUSE_COUNT=0;
 POINT_COUNT=0;
}

void display_pavedroad()
{
	for(int i=0;i<H;i++)
	{
	for(int j=0;j<W;j++)
	{
		printf("%d ",MAP[i][j]);
	}
	printf("\n");
	}
	printf("\n");
}

void check(int dir)
{
	int max_distance=0;

	// H증가방향
	if(dir==0)
	{
		for(int i=0;i<W;i++)
		{
			//포장 가능유무
			int sum=0;
			for(int j=0;j<H;j++)
			{
				if(MAP[j][i]==1) sum++;
			}

			if(sum>0) continue;

			//도로 포장
			for(int j=0;j<H;j++)
			{
				MAP[j][i]=2; 
			}

			PAVE_COUNT++;
			printf("PAVE_COUNT:%d\n",PAVE_COUNT);
			display_pavedroad();

			max_distance=getDISTANCE();
			printf("MAX distance:%d\n\n",max_distance);


			MIN_DIST=MIN(MIN_DIST,max_distance);


			//돌려 놓기
			for(int j=0;j<H;j++)
			{
				MAP[j][i]=0; 
			}
		}
	}


	//W증가 방향
	if(dir==1)
	{
		for(int i=0;i<H;i++)
		{
			//포장 가능유무
			int sum=0;
			for(int j=0;j<W;j++)
			{
				if(MAP[i][j]==1) sum++;
			}

			if(sum>0) continue;

			//도로 포장
			for(int j=0;j<W;j++)
			{
				MAP[j][i]=2; 
			}

			PAVE_COUNT++;
			printf("PAVE_COUNT:%d\n",PAVE_COUNT);
			display_pavedroad();

			max_distance=getDISTANCE();
			printf("MAX distance:%d\n\n",max_distance);

			MIN_DIST=MIN(MIN_DIST,max_distance);


			//돌려 놓기
			for(int j=0;j<W;j++)
			{
				MAP[j][i]=0; 
			}
		}
	}

	//음의 기울기
	if(dir==2)
	{
		int max_value=0;
		for(int i=0;i<H;i++)
		for(int j=0;j<W;j++)
		{
			CHECK[i][j]=i+j;
			max_value=MAX(max_value,CHECK[i][j]);
		}

		for(int index=1;index<max_value;index++)
		{
			int sum=0;
			for(int i=0;i<H;i++)
			for(int j=0;j<W;j++)
			{   
				if(index==CHECK[i][j])
				{
					if(MAP[i][j]==1) sum++;
				}
			}	

			if(sum>0) continue;

			//도로 포장
			for(int i=0;i<H;i++)
			for(int j=0;j<W;j++)
			{   
				if(index==CHECK[i][j])
				{
					MAP[i][j]=2;
				}
			}

			PAVE_COUNT++;
			printf("PAVE_COUNT:%d\n",PAVE_COUNT);
			display_pavedroad();

			max_distance=getDISTANCE();
			printf("MAX distance:%d\n\n",max_distance);


			MIN_DIST=MIN(MIN_DIST,max_distance);
/*
			for(int i=0;i<H;i++)
			{
			for(int j=0;j<W;j++)
			printf(" %d",MAP[i][j]);

			printf("\n");
			}
			printf("max_distance:%d\n",max_distance);
*/
			//원래대로
			for(int i=0;i<H;i++)
			for(int j=0;j<W;j++)
			{   
				if(index==CHECK[i][j])
				{
					MAP[i][j]=0;
				}
			}

		}

	}  //음의 방향 기울기 끝		

	//양의 기울기 
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	if(dir==3)
	{
		int min_value=INF;
		int max_value=-INF;
		for(int i=0;i<H;i++)
		for(int j=0;j<W;j++)
		{
			CHECK[i][j]=i-j;
			max_value=MAX(max_value,CHECK[i][j]);
			min_value=MIN(min_value,CHECK[i][j]);
		}

		//제일 모퉁이를 제외하기 위해서
		for(int index=min_value+1;index<max_value-1;index++)
		{
			int sum=0;
			for(int i=0;i<H;i++)
			for(int j=0;j<W;j++)
			{   
				if(index==CHECK[i][j])
				{
					if(MAP[i][j]==1) sum++;
				}
			}	

			if(sum>0) continue;

			//도로 포장
			for(int i=0;i<H;i++)
			for(int j=0;j<W;j++)
			{   
				if(index==CHECK[i][j])
				{
					MAP[i][j]=2;
				}
			}

			PAVE_COUNT++;
			printf("PAVE_COUNT:%d\n",PAVE_COUNT);
			display_pavedroad();

			max_distance=getDISTANCE();
			printf("MAX distance:%d\n\n",max_distance);

			MIN_DIST=MIN(MIN_DIST,max_distance);
/*
			for(int i=0;i<H;i++)
			{
			for(int j=0;j<W;j++)
			printf(" %d",MAP[i][j]);

			printf("\n");
			}
			printf("max_distance:%d\n",max_distance);
*/


			//원래대로
			for(int i=0;i<H;i++)
			for(int j=0;j<W;j++)
			{   
				if(index==CHECK[i][j])
				{
					MAP[i][j]=0;
				}
			}

		}

	}  //양의 방향 기울기 끝	



}

void main(void)
{
	freopen("input.txt","r",stdin);
	freopen("output_pavedroad.txt","w",stdout);


	scanf("%d",&TEST_CASE);
	for(int t=1;t<=TEST_CASE;t++)
	{
		init();
		input();

		check(0);//H방향으로 올라가며
		//printf("0 direction:%d\n",MIN_DIST);
		check(1);//W방향으로 올라가며
		//printf("1 direction:%d\n",MIN_DIST);
		check(2);//음의 기울기
		//printf("2 direction:%d\n",MIN_DIST);
		check(3);//양의 기울기
		//printf("3 direction:%d\n",MIN_DIST);
		
		printf("%d\n",PAVE_COUNT);

		if(MIN_DIST==INF)
		{
			printf("#%d %d\n",t,-1);
		}
		else
		{
			printf("#%d %d\n",t,MIN_DIST);
		}
	}
}












//일반 풀이
////////////////////////////////

#include<stdio.h>

#define INF 987654321

int W;
int H;
int TEST_CASE;
int MIN_DIST=INF;

int MAP[20][20];
int CHECK[20][20];


struct CORD
{
	int x;
	int y;
};

CORD HOUSE[400];
int HOUSE_COUNT;

CORD POINT[400];
int POINT_COUNT;

int abs(int a)
{
	return a<0? a*(-1) : a;
}

int getDIST(int x, int y, int house_num)
{
	return abs( x - HOUSE[house_num].x) + abs(y - HOUSE[house_num].y);
}

int MAX(int a, int b)
{
	return a>b ? a:b;
}

int MIN(int a, int b)
{
	return a<b ? a:b;
}

int getDISTANCE()
{
	int h_max_dist=0;

	for(int h=0;h<HOUSE_COUNT;h++)
	{
		int h_min_dist=987654321;

	 	for(int i=0;i<H;i++)
		for(int j=0;j<W;j++)
		{
			if(MAP[i][j]==2)
			h_min_dist=MIN(h_min_dist,getDIST(i,j,h));
		}
	
		h_max_dist=MAX(h_max_dist,h_min_dist);

	}

	return h_max_dist;
}


void input()
{
	scanf("%d %d",&W,&H);

	for(int i=0;i<H;i++)
	for(int j=0;j<W;j++)
	{
		scanf("%d",&MAP[i][j]);
		if(MAP[i][j]==1)
		{
			HOUSE[HOUSE_COUNT].x=i;
			HOUSE[HOUSE_COUNT].y=j;
			HOUSE_COUNT++;
		}
	}
}

void init()
{
 MIN_DIST=INF;
 HOUSE_COUNT=0;
 POINT_COUNT=0;
}

void check(int dir)
{
	int max_distance=0;

	// H증가방향
	if(dir==0)
	{
		for(int i=0;i<W;i++)
		{
			//포장 가능유무
			int sum=0;
			for(int j=0;j<H;j++)
			{
				if(MAP[j][i]==1) sum++;
			}

			if(sum>0) continue;

			//도로 포장
			for(int j=0;j<H;j++)
			{
				MAP[j][i]=2; 
			}


			max_distance=getDISTANCE();

			MIN_DIST=MIN(MIN_DIST,max_distance);


			//돌려 놓기
			for(int j=0;j<H;j++)
			{
				MAP[j][i]=0; 
			}
		}
	}


	//W증가 방향
	if(dir==1)
	{
		for(int i=0;i<H;i++)
		{
			//포장 가능유무
			int sum=0;
			for(int j=0;j<W;j++)
			{
				if(MAP[i][j]==1) sum++;
			}

			if(sum>0) continue;

			//도로 포장
			for(int j=0;j<W;j++)
			{
				MAP[j][i]=2; 
			}


			max_distance=getDISTANCE();

			MIN_DIST=MIN(MIN_DIST,max_distance);


			//돌려 놓기
			for(int j=0;j<W;j++)
			{
				MAP[j][i]=0; 
			}
		}
	}

	//음의 기울기
	if(dir==2)
	{
		int max_value=0;
		for(int i=0;i<H;i++)
		for(int j=0;j<W;j++)
		{
			CHECK[i][j]=i+j;
			max_value=MAX(max_value,CHECK[i][j]);
		}

		//제일 모퉁이를 제외하기 위해서
		for(int index=1;index<max_value;index++)
		{
			int sum=0;
			for(int i=0;i<H;i++)
			for(int j=0;j<W;j++)
			{   
				if(index==CHECK[i][j])
				{
					if(MAP[i][j]==1) sum++;
				}
			}	

			if(sum>0) continue;

			//도로 포장
			for(int i=0;i<H;i++)
			for(int j=0;j<W;j++)
			{   
				if(index==CHECK[i][j])
				{
					MAP[i][j]=2;
				}
			}

			max_distance=getDISTANCE();
			MIN_DIST=MIN(MIN_DIST,max_distance);
/*
			for(int i=0;i<H;i++)
			{
			for(int j=0;j<W;j++)
			printf(" %d",MAP[i][j]);

			printf("\n");
			}
			printf("max_distance:%d\n",max_distance);
*/
			//원래대로
			for(int i=0;i<H;i++)
			for(int j=0;j<W;j++)
			{   
				if(index==CHECK[i][j])
				{
					MAP[i][j]=0;
				}
			}

		}

	}  //음의 방향 기울기 끝		

	//양의 기울기 
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	if(dir==3)
	{
		int min_value=INF;
		int max_value=-INF;
		for(int i=0;i<H;i++)
		for(int j=0;j<W;j++)
		{
			CHECK[i][j]=i-j;
			max_value=MAX(max_value,CHECK[i][j]);
			min_value=MIN(min_value,CHECK[i][j]);
		}

		//제일 모퉁이를 제외하기 위해서
		for(int index=min_value+1;index<max_value-1;index++)
		{
			int sum=0;
			for(int i=0;i<H;i++)
			for(int j=0;j<W;j++)
			{   
				if(index==CHECK[i][j])
				{
					if(MAP[i][j]==1) sum++;
				}
			}	

			if(sum>0) continue;

			//도로 포장
			for(int i=0;i<H;i++)
			for(int j=0;j<W;j++)
			{   
				if(index==CHECK[i][j])
				{
					MAP[i][j]=2;
				}
			}

	
			max_distance=getDISTANCE();
			MIN_DIST=MIN(MIN_DIST,max_distance);
/*
			for(int i=0;i<H;i++)
			{
			for(int j=0;j<W;j++)
			printf(" %d",MAP[i][j]);

			printf("\n");
			}
			printf("max_distance:%d\n",max_distance);
*/


			//원래대로
			for(int i=0;i<H;i++)
			for(int j=0;j<W;j++)
			{   
				if(index==CHECK[i][j])
				{
					MAP[i][j]=0;
				}
			}

		}

	}  //양의 방향 기울기 끝	



}

void main(void)
{
	freopen("input.txt","r",stdin);
	scanf("%d",&TEST_CASE);
	for(int t=1;t<=TEST_CASE;t++)
	{
		init();
		input();

		check(0);//H방향으로 올라가며
		//printf("0 direction:%d\n",MIN_DIST);
		check(1);//W방향으로 올라가며
		//printf("1 direction:%d\n",MIN_DIST);
		check(2);//음의 기울기
		//printf("2 direction:%d\n",MIN_DIST);
		check(3);//양의 기울기
		//printf("3 direction:%d\n",MIN_DIST);
		

		if(MIN_DIST==INF)
		{
			printf("#%d %d\n",t,-1);
		}
		else
		{
			printf("#%d %d\n",t,MIN_DIST);
		}
	}
}