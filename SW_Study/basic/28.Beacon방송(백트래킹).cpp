/*
test case 1

7 1 2 3 1 2 3 
2 2
6 4
3 3
7 2
1 1
2 1
1 10

-> 12 포인트

4 3 2 1 6 4 3
1 5 
1 3
2 4
2 2

->18 포인트

*/

#include<stdio.h>

int TEST_CASE;

int GUEST_NUM;
int MAX_TIME=10;

struct BROADCAST
{
	int start;   //이 시간에 송출해서 
	int period;  //이 시간간 만큼 송출
	int point;   //이때의 포인트 
};

BROADCAST broadcast[3];

struct GUEST
{
	int start;  // 이 시간에 들어와서 
	int period; // 이 시간 만큼 상주.
};

GUEST guest[10];

int TIME_TABLE[100];

int MAX_POINT=-987654321;

void init()
{
	MAX_TIME=10;
	MAX_POINT=-987654321;
}

void input()
{
	scanf("%d %d %d %d %d %d %d",&GUEST_NUM,&broadcast[0].period,&broadcast[1].period,&broadcast[2].period,
					            &broadcast[0].point,&broadcast[1].point,&broadcast[2].point);

	for(int i=0;i<GUEST_NUM;i++)
	{
		scanf("%d %d",&guest[i].start,&guest[i].period);
	}

}

int isitpossible(int start, int b_num)
{
	int end=start+broadcast[b_num].period-1;
	for(int i=start;i<=end;i++)
	{
		if(TIME_TABLE[i]!=0) return 0;
	}

	return 1;
}

void getTime(int start, int b_num)
{
	int end=start+broadcast[b_num].period-1;
	for(int i=start;i<=end;i++)
	{
		TIME_TABLE[i]=b_num+1;
	}

	broadcast[b_num].start=start;
}


void releaseTime(int start,int b_num)
{
	int end=start+broadcast[b_num].period-1;
	for(int i=start;i<=end;i++)
	{
		TIME_TABLE[i]=0;
	}

	broadcast[b_num].start=0;
}

int MAX(int a, int b)
{
	return a>b? a:b;
}

int getMAXPOINT()
{
	
	int point_sum=0;

	for(int i=0;i<GUEST_NUM;i++)
	{
		int guest_in=guest[i].start;  
		int guest_out=guest[i].start+guest[i].period-1;

		int max=0;
		for(int j=0;j<3;j++)
		{
		  int broadcast_in=broadcast[j].start;
		  int broadcast_out=broadcast[j].start+broadcast[j].period-1;
		  if(broadcast_in!=0) 
		  {
			  if(broadcast_in >=  guest_in && guest_out >= broadcast_out )
			  {
				  max=MAX(max,broadcast[j].point);
			  }
		  }
		}
		point_sum+=max;
	}

	return point_sum;


}

//b 방송을 고려했을때 확보되는 타임
void solve(int b)
{

if(b==3) //최대 방송까지 왔을때 
{

	for(int t=1;t<=MAX_TIME;t++)
	{
		printf("%d ",TIME_TABLE[t]);
	}
	printf("\n");


	//현재 타임테이블에서 최대로 얻을 수 있는 포인트
	int point=getMAXPOINT();
	if(MAX_POINT<point) MAX_POINT=point;

	return;
}

for(int t=1;t<=MAX_TIME;t++)
{
	if(isitpossible(t,b))
	{
		getTime(t,b);
		solve(b+1);
		releaseTime(t,b);
		
	//	solve(b+1); //양보가 필요없다....
	}
	else
	{
		//solve(b+1); //양보가 필요없다....
	}

}

}

void main()
{
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
		init();
		input();
		solve(0);

	printf("%d\n",MAX_POINT);
}


//창훈 최종 마지막 풀이.
//타임테이블 후보군 만들때, 조금 유의하자.
#include<stdio.h>

int N;

struct GUEST
{
	int start;
	int end;
	int period;
};

GUEST guest[10];

struct BROADCAST
{
	int start;
	int end;
	int period;
	int point;
};

int check[3];

int timetable[20];
int max_time=10;

BROADCAST broadcast[3];

void input()
{
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	scanf("%d %d %d %d %d %d %d",&N,&broadcast[0].period,&broadcast[1].period,&broadcast[2].period //방송송출시간
		                           ,&broadcast[0].point,&broadcast[1].point,&broadcast[2].point);

	for(int i=0;i<N;i++)
	{
		scanf("%d %d",&guest[i].start,&guest[i].period);
		guest[i].end=(guest[i].start+guest[i].period - 1);
	}

}

//시작 시간, 방송번호
int possible(int t, int num)
{
	for(int i=t;i<=t+broadcast[num].period-1;i++)
	{
		if(timetable[i]) return 0;
	}
	return 1;
}

void get(int t, int num)
{
	for(int i=t;i<=t+broadcast[num].period-1;i++)
	{
		timetable[i]=num+1;
	}

	broadcast[num].start=t;   //여기 틀린다. 주의!!
	broadcast[num].end=t+broadcast[num].period-1;
}

void release(int t, int num)
{
	for(int i=t;i<=t+broadcast[num].period-1;i++)
	{
		timetable[i]=0;
	}
	
	broadcast[num].start=0;
	broadcast[num].end=0;
}

int sentALLBroadcast()
{
  if(check[0]==1 && check[1]==1 && check[2]==1) return 1;
  else return 0;
}

int getMaxtime(int num)
{
	int max_value=0;

	for(int i=0;i<3;i++)
	{
		if(broadcast[i].start >= guest[num].start &&  broadcast[i].end <= guest[num].end) //이부분 세번 풀때도 여기 틀린다. 주의!!
		{ //고객이 포인트를 받을려면 방송보도 길게 있어야한다. 
			//printf("possible : %d \n",broadcast[i].point );
			if( max_value < broadcast[i].point ) max_value= broadcast[i].point;
		}
	}

	return max_value;
}


int last_total_point=0;

void solve(int i)
{
	  if(i==3)  // 마지막 방송이 송출됨
	  {
/*	
		  for(int i=1;i<max_time;i++)
		  printf(" %d",timetable[i]);
		  printf("\n");
*/		
		  int total_point=0;
		  for(int i=0;i<N;i++) // 0번 손님부터 마지막 손님까지..
		  {
			  int guest_max_time = getMaxtime(i);
			 // printf("guest:%d guest_max_time:%d\n",i,guest_max_time);
			  total_point+=guest_max_time;
		  }

		  if(last_total_point < total_point) last_total_point=total_point;

		  return; 
	  }

	 

		for(int t=1; t < max_time ; t++) // 시작시간
		{
			if(possible(t,i))
			{
				get(t,i);
				solve(i+1);
				release(t,i);
			 }
		}
}


void main()
{
	input();
	solve(0);
	printf("%d",last_total_point);
}





//제일 첫번째풀이
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


#include<stdio.h>

int N;
int TIME=50;

struct ADV
{
	int s;  //광고 시작 시간
	int l;  //광고 방송의 길이
	int p;  //포인트 
};

ADV g_adv[4]; //1~3  3개의 방송을 송출

struct GUEST{
	int s;   //손님이 매장에 들어온 시간
	int d;   //손님이 매장에 채류한 시간
};

GUEST g_guest[11];//1~10 10명의 손님

void input()
{
	freopen("input.txt","r",stdin);
	//freopen("output_beacod.txt","w",stdout);


	scanf("%d",&N); // 손님의 수

	scanf("%d %d %d %d %d %d",&g_adv[1].l,&g_adv[2].l,&g_adv[3].l,
		                     &g_adv[1].p,&g_adv[2].p,&g_adv[3].p);

	for(int i=1; i<=N;i++)
	{
		scanf("%d %d",&g_guest[i].s,&g_guest[i].d);
	}
}

int chk[100];
int result_chk[100];

//adv 번째 해당 광고, 시작 시간은 i
int Isitpossible(int adv,int i)
{
	for(int t=i;t<i+g_adv[adv].l;t++)
	{
		if(chk[t]) return 0;
	}

	return 1;
}

void get(int adv,int i)
{
	for(int t=i;t<i+g_adv[adv].l;t++)
	{
		chk[t]=adv;
	}

	g_adv[adv].s=i;
}


void relese(int adv,int i)
{

	for(int t=i;t<i+g_adv[adv].l;t++)
	{
		chk[t]=0;
	}

	g_adv[adv].s=0;
}

int check(int g_s,int g_e, int b_s,int b_e)
{
	if(b_s >= g_s && g_e >= b_e) return 1; // 이 부분을 실수했음. 그림을 그려봐야된다.. 머리속을 풀다가 못풀었음!!! 

	return 0;
}

int MAX(int a , int b)
{
	return a > b ? a : b;
}

int getPoint()
{
//	printf(">>\n");
	int sum=0;
	for(int g=1;g<=N;g++)
	{
		int local_point=0;

		for(int b=1;b<=3;b++)
		{
			int g_s=g_guest[g].s;
			int g_e=g_s+g_guest[g].d-1; //여기실수함.!! 이런류의 문제는 반드시 찍어본다. 손님 채류 시간임
			int b_s=g_adv[b].s;
			int b_e=b_s+g_adv[b].l-1;  //여기실수함.!! 이런류의 문제는 반드시 찍어본다. 방송의 길이

			//printf("%d %d %d %d\n",g_s,g_e,b_s,b_e);

			if(check( g_s, g_e,  b_s, b_e))
			{
				local_point=MAX(local_point,g_adv[b].p);
				//local_point+=g_adv[b].p;
			}
		}

		//printf("local_point: %d \n",local_point);

		sum+=local_point;
	}

//	printf(" sum:%d \n",sum);
//	printf("<<\n");
	return sum;
}

int MAX_POINT=-987654321;

void sendBroadcast(int adv)
{
	if(adv==4)
	{
		
	//	for(int i=1;i<=TIME;i++)
	//	printf(" %d",chk[i]);
	//	printf("\n");
		
		int value=getPoint();

	//	printf("value:%d\n",value);

		if(MAX_POINT < value){
			MAX_POINT=value;

			for(int i=1;i<=TIME;i++)
			result_chk[i]=chk[i];
		}
		return;
	}


	for(int i=1;i<=TIME;i++)
	{
		if(Isitpossible(adv,i))
		{
			get(adv,i);
			sendBroadcast(adv+1);
			relese(adv,i);
		}
	}

}

void main()
{
	input();

	sendBroadcast(1);

	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	for(int i=1;i<=TIME;i++)
	printf(" %d",result_chk[i]);
	printf("\n");

	printf("%d",MAX_POINT);
}





//두번째 품
//이렇게 풀면 후보군은 중복이 나온다. 이렇게 풀면 안된다. 일단 답은 나온다. - Core연결하고 동일하게 Check 배열을 사용할 필요가 업다.
//첫번째 푸는 방식으로 후보군을 만들어서 풀어야 한다. 최종 풀이는 후보군을 바꾼 방법
/////////////////////////////////////


#include<stdio.h>

/*
4 3 2 1 6 4 3
1 5
1 3
2 4
2 2
*/

int N;

struct GUEST
{
	int start;
	int end;
	int period;
};

GUEST guest[10];

struct BROADCAST
{
	int start;
	int end;
	int period;
	int point;
};

int check[3];

int timetable[20];
int max_time=10;

BROADCAST broadcast[3];

void input()
{
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	scanf("%d %d %d %d %d %d %d",&N,&broadcast[0].period,&broadcast[1].period,&broadcast[2].period //방송송출시간
		                           ,&broadcast[0].point,&broadcast[1].point,&broadcast[2].point);

	for(int i=0;i<N;i++)
	{
		scanf("%d %d",&guest[i].start,&guest[i].period);
		guest[i].end=(guest[i].start+guest[i].period - 1);
	}

}

//시작 시간, 방송번호
int possible(int t, int num)
{
	for(int i=t;i<=t+broadcast[num].period-1;i++)
	{
		if(timetable[i]) return 0;
	}
	return 1;
}

void get(int t, int num)
{
	for(int i=t;i<=t+broadcast[num].period-1;i++)
	{
		timetable[i]=num+1;
	}

	broadcast[num].start=t;   //여기 틀린다. 주의!!
	broadcast[num].end=t+broadcast[num].period-1;
}

void release(int t, int num)
{
	for(int i=t;i<=t+broadcast[num].period-1;i++)
	{
		timetable[i]=0;
	}
	
	broadcast[num].start=0;
	broadcast[num].end=0;
}

int sentALLBroadcast()
{
  if(check[0]==1 && check[1]==1 && check[2]==1) return 1;
  else return 0;
}

int getMaxtime(int num)
{
	int max_value=0;

	for(int i=0;i<3;i++)
	{
		if(broadcast[i].start >= guest[num].start &&  broadcast[i].end <= guest[num].end) //이부분 두번째 풀때도 여기 틀린다. 주의!!
		{
			//printf("possible : %d \n",broadcast[i].point );
			if( max_value < broadcast[i].point ) max_value= broadcast[i].point;
		}
	}

	return max_value;
}


int last_total_point=0;

void solve()
{
	  if(sentALLBroadcast())
	  {
/*	
		  for(int i=1;i<max_time;i++)
		  printf(" %d",timetable[i]);
		  printf("\n");
*/		
		  int total_point=0;
		  for(int i=0;i<N;i++) // 0번 손님부터 마지막 손님까지..
		  {
			  int guest_max_time = getMaxtime(i);
			 // printf("guest:%d guest_max_time:%d\n",i,guest_max_time);
			  total_point+=guest_max_time;
		  }

		  if(last_total_point < total_point) last_total_point=total_point;

		  return; 
	  }

	 
	   for(int i=0;i<3;i++)
	   {
		   if(check[i]==0)
		   {
			   check[i]=1;
				for(int t=1; t < max_time ; t++) // 시작시간
				{
					if(possible(t,i))
					{
						get(t,i);
						solve();
						release(t,i);
					}
				}
			   check[i]=0;
		   }
	   }
}


void main()
{
	input();
	solve();
	printf("%d",last_total_point);
}
