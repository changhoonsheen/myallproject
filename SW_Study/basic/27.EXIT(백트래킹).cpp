/*
EXIT는 두곳임 사람들은 1초에 한명씩 탈출 가능함.

ex)
MAP 상하좌우 1칸 이동에 1초.
0 0 0
0 2 1
이때 탈출시간은 2초 < exit까지 이동시간 1초 탈출에 1초> 
모든 사람이 탈출하는 시간을 구하라.

입력 
T      (test case)
NxN    (Max 10)
1은 사람 (MAX 10)
1는 Exit(2)

4
5
0 0 1 0 1
0 0 0 2 0
0 0 0 0 0
0 0 1 0 1
0 0 2 0 0
6
0 0 1 0 0 0
0 2 1 0 0 0
1 1 1 0 0 0
0 0 0 0 0 0
0 0 0 0 2 1
0 0 0 0 1 1
5
1 0 0 1 0
0 2 0 0 2
0 0 1 0 0
0 0 1 0 0
0 0 1 0 0
5
0 1 0 0 1
2 0 0 2 0
0 0 1 0 0
0 0 1 0 0
0 0 1 0 0



답
4
5
5
5


*/
///////////////////////////////////////////////////////////////

//최신 풀이 필기 
#include<stdio.h>
int TEST_CASE;

int MAP[20][20];
int N;

struct CORD
{
	int x;
	int y;
};

CORD HUMAN[10];
int HUMAN_COUNT;

CORD EXIT[3];
int EXIT_COUNT=1;

//사람들이 쌓일 배열
int EXIT_ARR[3][20];

int MIN_TIME=987654321;


int abs(int a)
{
	return a<0 ? a*(-1):a; 
}

int getDISTANCE(CORD a, CORD b)
{
	return abs(a.x - b.x) + abs(a.y - b.y);
}

void input()
{
scanf("%d",&N);

for(int i=0;i<N;i++)
for(int j=0;j<N;j++)
{
 scanf("%d",&MAP[i][j]);

 if(MAP[i][j]==1)
 {
	 HUMAN[HUMAN_COUNT].x=i;
	 HUMAN[HUMAN_COUNT].y=j;
	 HUMAN_COUNT++;
 }

 if(MAP[i][j]==2)
 {
	 EXIT[EXIT_COUNT].x=i;
	 EXIT[EXIT_COUNT].y=j;
	 EXIT_COUNT++;
 }
}

}

void init()
{
	HUMAN_COUNT=0;
	EXIT_COUNT=1;
	MIN_TIME=987654321;
}

void sort(int arr[], int len)
{

for(int i=0;i<len;i++)
for(int j=i+1;j<len;j++)
{
	if(arr[i]>arr[j])
	{
		int temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}
}

}


//하나의 path(BASE에 내려올때)의 상태공간에서 base까지 갔을때 모든 사람이 탈출하는데 걸리는 시간
//필기 참조
int getTime(int exit_1_num,int exit_2_num)
{
	    //copy human array
		//>>
		int EXIT_ARR_1[20]; //BASE에 저장해놓기
		int EXIT_ARR_2[20];

		int NEW_EXIT_ARR_1[20]; //BASE에 저장해놓기
		int NEW_EXIT_ARR_2[20];

		for(int i=0;i<exit_1_num;i++)
	    EXIT_ARR_1[i]=EXIT_ARR[1][i]; 

		for(int i=0;i<exit_2_num;i++)
	    EXIT_ARR_2[i]=EXIT_ARR[2][i];
		
		sort(EXIT_ARR_1,exit_1_num);
		sort(EXIT_ARR_2,exit_2_num);

		for(int i=0;i<exit_1_num;i++)
	    NEW_EXIT_ARR_1[i]=EXIT_ARR_1[i]+1; //출구에서 1초을 기달려야함으로 일괄적으로 1초를 더함.
		                                 //디폴트로 예상되어지는 시간

		for(int i=0;i<exit_2_num;i++)
	    NEW_EXIT_ARR_2[i]=EXIT_ARR_2[i]+1; //출구에서 1초을 기달려야함으로 일괄적으로 1초를 더함.
										 //디폴트로 예상되어지는 시간
		
		int exit_time1=0;
		for(int i=0;i<exit_1_num;i++)
		{
			if(i==0) exit_time1=NEW_EXIT_ARR_1[i];
			else
			{
				if(exit_time1 >= NEW_EXIT_ARR_1[i])  exit_time1++;
				else exit_time1=NEW_EXIT_ARR_1[i];
			}
		}

		int exit_time2=0;
		for(int i=0;i<exit_2_num;i++)
		{
			if(i==0) exit_time2=NEW_EXIT_ARR_2[i];
			else
			{
				if(exit_time2 >= NEW_EXIT_ARR_2[i])  exit_time2++;
				else exit_time2=NEW_EXIT_ARR_2[i];
			}
		}

		//for debugging
		/*
		printf(">>>>>>>>>>>>>>\n");
		printf("exit_1_num :%d\n",exit_1_num);
		for(int i=0;i<exit_1_num;i++) 
		printf(" %d",EXIT_ARR_1[i]);
		printf(" min time:%d\n",exit_time1);

		printf("\n");

		printf("exit_2_num :%d\n",exit_2_num);
		for(int i=0;i<exit_2_num;i++) 
		printf(" %d",EXIT_ARR_2[i]);
		printf(" min time:%d\n",exit_time2);

		printf("\n<<<<<<<<<<<<<<\n");
		*/

		if(exit_time1 > exit_time2) return exit_time1;
		else return exit_time2;

}

void solve(int human_num, int exit_1_num, int exit_2_num)
{
	if(human_num==HUMAN_COUNT)
	{
		int time=getTime(exit_1_num,exit_2_num);

		if(MIN_TIME>time) MIN_TIME=time;

		return;
	}

	 int dist=0;
	 //1번 출입구
	 dist=getDISTANCE(HUMAN[human_num],EXIT[1]);
	 EXIT_ARR[1][exit_1_num]=dist;
	 solve(human_num+1,exit_1_num+1, exit_2_num);

	 //2번 출입구
	 dist=getDISTANCE(HUMAN[human_num],EXIT[2]);
	 EXIT_ARR[2][exit_2_num]=dist;
	 solve(human_num+1,exit_1_num, exit_2_num+1);
}

void main()
{
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d",&TEST_CASE);
	
	for(int t=1;t<=TEST_CASE;t++)
	{
		init();
		input();
		solve(0,0,0);
		printf("MIN_TIME:%d\n",MIN_TIME);
	}
}















///////////////////////////////////////////////////////////////////

#include<stdio.h>

int TEST_CASE;
int N;
int MAP[10][10];

struct CORD
{
	int x;
	int y;
};

struct NODE
{
	int time;
	int num;
	CORD cord;
};

NODE EXIT[2][10];


CORD MAN_CORD[10];
CORD EXIT_CORD[2];

int MAN_COUNT;
int EXIT_COUNT;

int MIN_TIME=987654321;

NODE RESULT_EXIT[2][10];
int RESULT_FIRST_EXIT_INDEX;
int RESULT_SECOND_EXIT_INDEX;


int abs(int a)
{
	return a<0? a*(-1):a;
}

int getTIME(CORD a, CORD b)
{
	return abs(a.x - b.x) + abs(a.y - b.y);
}


void input()
{
	scanf("%d",&N);

	for(int x=0;x<N;x++)
	for(int y=0;y<N;y++)
	{
		scanf("%d",&MAP[x][y]);

		if(MAP[x][y]==1){
			MAN_CORD[MAN_COUNT].x=x;
			MAN_CORD[MAN_COUNT].y=y;
			MAN_COUNT++;
		}

		if(MAP[x][y]==2){
			EXIT_CORD[EXIT_COUNT].x=x;
			EXIT_CORD[EXIT_COUNT].y=y;
			EXIT_COUNT++;
		}
	}
}

void init()
{
 MAN_COUNT=0;
 EXIT_COUNT=0;
 MIN_TIME=987654321;  //여기 매번 실수함!!!
}

void sort(NODE* arr, int len)
{

	for(int i=0; i<len ; i++)
	for(int j=i+1; j<len ; j++)
	{
		if(arr[i].time > arr[j].time )
		{
			NODE temp;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
}

//현재 첫번째, 두번째 배열엔 모든 경우의수의 탈출을 원하는 사람들이 들어 있다. 
//이를 정렬해서 최대 소요 시간을 찾는다.
int check_time(int first_exit_index, int second_exit_index)
{
	    NODE NEW_EXIT[2][10]={0,};

		for(int i=0;i<first_exit_index;i++)
			NEW_EXIT[0][i]=EXIT[0][i];

		for(int i=0;i<second_exit_index;i++)
			NEW_EXIT[1][i]=EXIT[1][i];

		sort(&NEW_EXIT[0][0],first_exit_index);
		sort(&NEW_EXIT[1][0],second_exit_index);

		int first_exit_maxtime=0;
		for(int i=0;i<first_exit_index;i++)
		{
			if(i==0) { first_exit_maxtime = NEW_EXIT[0][i].time+1; continue;}
			if(first_exit_maxtime >= NEW_EXIT[0][i].time) { first_exit_maxtime++; continue;}
			if(first_exit_maxtime < NEW_EXIT[0][i].time) { first_exit_maxtime= NEW_EXIT[0][i].time+1; continue;}
	
		}

		int second_exit_maxtime=0;
		for(int i=0;i<second_exit_index;i++)
		{
			if(i==0) { second_exit_maxtime = NEW_EXIT[1][i].time+1; continue;}
			if(second_exit_maxtime >= NEW_EXIT[1][i].time) { second_exit_maxtime++; continue;}
			if(second_exit_maxtime < NEW_EXIT[1][i].time) { second_exit_maxtime= NEW_EXIT[1][i].time+1; continue;}
		}


		return first_exit_maxtime < second_exit_maxtime ?  second_exit_maxtime : first_exit_maxtime;
}




//solve함수 : 최대 소요 시간중 최소임으로 이를 Backtracking에서 원하는 최소 시간을 찾는다.
void solve(int man_num , int first_exit_index, int second_exit_index)
{

	if(man_num==MAN_COUNT)
	{
		int time=check_time(first_exit_index,second_exit_index);

		if(MIN_TIME > time) 
		{	
			MIN_TIME=time;

#if 1  // debug
			for(int i=0;i<first_exit_index;i++)
			RESULT_EXIT[0][i]=EXIT[0][i];

		    for(int i=0;i<second_exit_index;i++)
			RESULT_EXIT[1][i]=EXIT[1][i];

			sort(&RESULT_EXIT[0][0],first_exit_index);
			sort(&RESULT_EXIT[1][0],second_exit_index);

			RESULT_FIRST_EXIT_INDEX=first_exit_index;
			RESULT_SECOND_EXIT_INDEX=second_exit_index;
#endif

		}
		return; 
	}



	int time=0;
	//1번출구 이용
	time=getTIME(MAN_CORD[man_num], EXIT_CORD[0]);
	EXIT[0][first_exit_index].num=man_num;
	EXIT[0][first_exit_index].cord=MAN_CORD[man_num];
	EXIT[0][first_exit_index].time=time;
	solve(man_num+1,first_exit_index+1,second_exit_index);


	//2번출구 이용
	time=getTIME(MAN_CORD[man_num], EXIT_CORD[1]);
	EXIT[1][second_exit_index].num=man_num;
	EXIT[1][second_exit_index].cord=MAN_CORD[man_num];
	EXIT[1][second_exit_index].time=time;
	solve(man_num+1,first_exit_index,second_exit_index+1);

}


void display()
{

	    printf("first gate:\n");
		for(int i=0;i<RESULT_FIRST_EXIT_INDEX;i++)
		{
			printf("num:%d\n",RESULT_EXIT[0][i].num);
			printf("cord x:%d , cord y:%d \n",RESULT_EXIT[0][i].cord.x,RESULT_EXIT[0][i].cord.y);
			printf("time :%d \n",RESULT_EXIT[0][i].time);
		}

		printf("---------------------\n");
	    printf("second gate:\n");
		for(int i=0;i<RESULT_SECOND_EXIT_INDEX;i++)
		{
			printf("num:%d\n",RESULT_EXIT[1][i].num);
			printf("cord x:%d , cord y:%d \n",RESULT_EXIT[1][i].cord.x,RESULT_EXIT[1][i].cord.y);
			printf("time :%d \n",RESULT_EXIT[1][i].time);
		}

}


void main()
{
	freopen("input.txt","r",stdin);
	scanf("%d",&TEST_CASE);

	for(int t=1;t<=TEST_CASE;t++)
	{
			init();
			input();
			solve(0,0,0);

			printf("%d\n",MIN_TIME);

#if 0 // debug
			display();
#endif

	}
}