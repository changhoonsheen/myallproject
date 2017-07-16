/*
집에 IoT환경 구축하기
- 집의 크기 N은(정사각형) 5<=N<=20
- AP는 포트에 설치할 수 있고, 각 포트에는 하나의 AP만 설치 가능하다.
- 포트의 갯수는 1~25개임(9라고 표시) AP의 갯수는 최대 5개이며, AP의 통신 거리는 Rap 2<=Rap<=5
- IoT 기기의 갯수는 1~40개이며, 통신 거리는 R은 1<=R<=3(해당 위치에 숫자값으로 표현됨.)

모든 IoT는 기기는 하나 이상의 AP에 연결되어야한다. IoT 환경 구축을 위한 최소 AP 갯수는 몇개인가?

통신거리계산 ㅣ (Xa,Ya)-(Xb,Yb) -> |Xa-Xb|+|Ya-Yb|


입력>
Test case수
N Rap
NxN의 Map이 주어지고
Iot기기는 통신거리로,포트는 9로 표시됨


출력>
최소 AP 갯수 또는 불가능시 -1을 출력할것



/*
5
5 2
0 0 0 0 0
0 0 0 9 0
2 0 0 9 0
0 0 0 0 0
0 0 0 0 0
5 2
0 0 0 0 0
0 0 0 0 0
1 0 0 0 9
0 0 0 0 9
0 0 0 0 0
6 2
0 0 0 0 0 9
9 0 0 0 0 0 
0 0 0 0 1 0
0 0 0 0 0 0
1 0 0 0 0 0
0 0 0 9 0 0
6 2
9 0 0 0 0 0
9 0 0 0 0 0 
0 0 0 0 1 0
0 0 0 0 0 0
1 0 0 0 0 0
0 0 0 9 0 0
7 2
0 0 1 0 0 0 1
0 0 0 0 0 0 0
0 9 0 9 9 0 0
0 1 0 0 0 0 9
0 3 0 0 0 0 0
0 0 0 0 0 0 0 
0 0 0 0 0 0 1


답 
1
-1 
2
-1
2
*/


#include<stdio.h>
#define INF 987654321

struct CORD
{
	int x;
	int y;
	int r;
};

int MAP[20][20];
int SIZE;

int RAP;

CORD PORT[25]; //9라는 숫자
int PORT_COUNT;

CORD IOT[40];
int IOT_COUNT;

int CHECK[40];

int TEST_CASE;
int MIN_AP=INF;

int abs(int a)
{
	return a<0? a*(-1):a;  // 여기 a>0 으로 실수함!!!!
}

int getLength(CORD a, CORD b)
{
	return abs(a.x - b.x) + abs(a.y - b.y);
}

//해당 포트에 IOT가 연결이 가능하니?
int isitpossible(int pt, int t)
{
	int coverage=PORT[pt].r+IOT[t].r;
	int length=getLength(PORT[pt],IOT[t]);

	//printf("port:%d, iot:%d - coverage:%d , length:%d\n",pt,t,coverage,length);
	
	if(coverage>=length) return 1;  // >=까지 되는거다. 그려서 생각하자.!!
	
	return 0;
}

//모든 iot가 연결이 되었을때
int alloccupied()
{
	for(int i=0;i<IOT_COUNT;i++)
	{
		if(CHECK[i]==0) return 0;
	}

	return 1;
}

int check_all_iot_devices(int port,int selected_port_arr[])
{
	int selected_port_count=0;
	for(int t=0;t<IOT_COUNT;t++)
	{
		if(isitpossible(port,t) && CHECK[t]==0)
		{
			CHECK[t]=1;
			selected_port_arr[selected_port_count]=t;
			selected_port_count++;
		}
	}
	return selected_port_count;
}

void uncheck_all_iot_devices(int selected_port_arr[],int selected_port_count)
{
	for(int t=0;t<selected_port_count;t++)
	{
		CHECK[selected_port_arr[t]]=0;
	}
}

void solve(int port,int s_port)
{

	if(s_port > 6) return;  //할당된 AP가 5개임으로  변수명 실수함!! 

	if(MIN_AP <= s_port) return;



	int selected_port_count=0;
	int selected_port_arr[40]={0,};

	//모든 iot가 전부 연결이 되었을때가 해가될수 있는것이다.
	if(alloccupied())
	{
		if(MIN_AP>s_port) MIN_AP=s_port;
		return;
	}

	//모든 port를 고려했을때 base일때 
	if(port==PORT_COUNT)
	{
		return;
	}


	selected_port_count=check_all_iot_devices(port,selected_port_arr);

	if(selected_port_count)
	{
		solve(port+1,s_port+1);
		
		uncheck_all_iot_devices(selected_port_arr,selected_port_count);

		solve(port+1,s_port); // 선택할수 있지만 자발적인 양보
	}
	else
	{
		solve(port+1,s_port);
	}
}

void input()
{
	scanf("%d %d",&SIZE,&RAP);

	for(int i=0;i<SIZE;i++)
	for(int j=0;j<SIZE;j++)
	{
		scanf("%d",&MAP[i][j]);

		if(MAP[i][j])
		{
			if(MAP[i][j]==9)
			{
				PORT[PORT_COUNT].x=i;
				PORT[PORT_COUNT].y=j;
				PORT[PORT_COUNT].r=RAP;
				PORT_COUNT++;
			}
			else
			{
				IOT[IOT_COUNT].x=i;
				IOT[IOT_COUNT].y=j;
				IOT[IOT_COUNT].r=MAP[i][j];	
				IOT_COUNT++;
			}
		}
	}
}

void init()
{
	PORT_COUNT=0;
	IOT_COUNT=0;
	MIN_AP=INF;
}

int main(void)
{
	freopen("input.txt","r",stdin);
	scanf("%d",&TEST_CASE);

	for(int t=1;t<=TEST_CASE;t++)
	{
		init();
		input();
		solve(0,0);

		if(MIN_AP==INF) printf("-1\n");
		else printf("%d\n",MIN_AP);
	}
}
