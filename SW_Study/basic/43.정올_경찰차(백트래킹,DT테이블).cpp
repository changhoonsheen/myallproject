//창훈 최종 필기
//그래프를 그려야한다. 
//풀이 방법은 노트를 확인해라!!

//창훈 최종풀이

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int N; //map 크기 
int A; //전체 사건의 수

int func_call;

struct LOC
{
	int x;
	int y;
};


int DT[50][50];


LOC accidents[100];

int abs(int a)
{
	return a<0 ? a*(-1): a;
}

int MAX(int a, int b)
{
	return a > b ? a:b;
}

int MIN(int a, int b)
{
	return a < b ? a:b;
}


int getDistance(int a, int b)
{
	return abs(accidents[a].x - accidents[b].x) + abs(accidents[a].y - accidents[b].y);
}

int min_len=987654321;

#if 1
void f(int pol1, int pol2, int len)
{
	func_call++;
	if(min_len < len) return;

	int next_accident=MAX(pol1,pol2)+1;

	if(next_accident==A)
	{
		if(min_len > len ) min_len=len;
	}

	f(next_accident,pol2,len+getDistance(pol1,next_accident));
	f(pol1,next_accident,len+getDistance(pol2,next_accident));
}

#else


int f(int pol1, int pol2)
{

	if(DT[pol1][pol2]!=-1) return DT[pol1][pol2];

	func_call++;
	
	int next_accident=MAX(pol1,pol2)+1;

	if(next_accident==A)
	{
		return  DT[pol1][pol2]=0;	
	}

	return DT[pol1][pol2]=MIN ( f(next_accident,pol2) + getDistance(pol1,next_accident) ,
				                f(pol1,next_accident) + getDistance(pol2,next_accident));
}


#endif


void input()
{
freopen("input.txt","r",stdin);
scanf("%d",&N);//지도의 크기

//첫번째 사건
accidents[0].x=1;
accidents[0].y=1;

//두번째 사건
accidents[1].x=N;
accidents[1].y=N;

scanf("%d",&A);//총사건의 갯수
A=A+2;

for(int i=2;i<A;i++)
{
	scanf("%d %d",&accidents[i].x,&accidents[i].y);
}

}

void main()
{

	input();

#if 1
	int start;
	start=clock();
	f(0, 1, 0);
	printf("min_len:%d\n",min_len);
	printf("%f sec\n\n",(double)(clock()-start)/CLOCKS_PER_SEC);
	printf("func_call:%d",func_call);
#else
	int start;
	start=clock();

	for(int i=0;i<50;i++)
	for(int j=0;j<50;j++)
		DT[i][j]=-1;

	printf("min_len:%d\n",f(0, 1));
	printf("%f sec\n\n",(double)(clock()-start)/CLOCKS_PER_SEC);
	printf("func_call:%d",func_call);

#endif

}

















//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


#include<stdio.h>

int n; // map size
int m; // event

int func_count;

int DT[20][20];

struct Event
{
	int x;
	int y;
};

Event event[20];

int abs(int a)
{
	return a<0 ? a*(-1) : a;
}

int getDistance(Event a, Event b)
{
	int dist=abs(a.x-b.x) + abs(a.y-b.y);
	return dist;
}

int MIN(int a, int b)
{
	return a>b? b:a;
}

int MAX(int a, int b)
{
	return a<b? b:a;
}

int solve(int a, int b)
{
	//printf("a:%d b:%d\n",a,b); //동작이 안될때 이 로깅은 기본.

	if(DT[a][b]!=-1) return DT[a][b];

	func_count++;

	int next_event = MAX(a,b)+1;

	if(next_event >= m+2) return DT[a][b]=0;

#if 1 //똑같은 결과는 나오지만 콜스택이 다르게 호출된다. 놀라지 마라. 
	  // 이걸 사용하자
	int left = solve(next_event,b) + getDistance(event[a],event[next_event]);
	int right= solve(a,next_event) + getDistance(event[b],event[next_event]);

	return DT[a][b]=MIN(left,right);
#else
	 MIN(solve(next_event,b) + getDistance(event[a],event[next_event]),
		 solve(a,next_event) + getDistance(event[b],event[next_event]));
#endif
}

void input()
{
freopen("input.txt","r",stdin);
scanf("%d",&n);
scanf("%d",&m);

for(int i=2;i<m+2;i++)
{
	scanf("%d %d",&event[i].x,&event[i].y);
}
}


void main()
{
	input();

	for(int i=0;i<20;i++)
		for(int j=0;j<20;j++)
		{
			DT[i][j]=-1;
		}


//첫번째 사건
event[0].x=1; //여기 실수 했다. 0,0 으로 표기함, 최초 좌표는 1,1이다. 실수하지 말자.
event[0].y=1;

//두번째 사건
event[1].x=n;
event[1].y=n;

printf("%d\n",solve(0,1));
printf("func_count:%d",func_count);
}


















//+++++++++++++++++++++++++++++++++++++++++++++++++++++
////////////////////////////////////////////////////////
/*
창훈, 좌표 중심 전체 검색을 이용한 방법 가장 쉬운 방법 

100
6
3 5
5 5
2 3
13 15
25 25
32 33

ans 73
func count 7



500
14
3 5
5 5
2 3
13 15
25 25
32 33
250 250 
499 499
225 225
275 275
100 100
200 200
300 300
400 400

ans 1608
func count에 따른 알고리즘 성능 비교
32767  그냥 백트레킹
317 가지치기
288 greed+가지치기
211 사건중심+DT table


가지치기만 잘해도 좋은 결과를 얻는다.
*/

/*
창훈 최종 잘 풀었다.
그러나, DT를 적용하기 위해서 사건 중심으로 풀이를 해야된다.

*/

#include<stdio.h>

int n; // map 크기 
int m; // 사건수

int func_count;

struct Cord
{
	int x;
	int y;
};

Cord acc[100];
int value=987654321;

int abs(int a)
{
 return a < 0 ? a*(-1) : a;
}

int getDistance(Cord a, Cord b)
{
	 return abs(a.x - b.x) + abs(a.y - b.y) ;
}

int greedy()
{
 Cord pol1;
 pol1.x=1;
 pol1.y=1;

 Cord pol2;
 pol2.x=n;
 pol2.y=n;

 int greedydistance=0;

 int i=1;
 while(i<=m)
 {
	 int a=getDistance(pol1,acc[i]);
	 int b=getDistance(pol2,acc[i]);

	 if(a<b){
		 greedydistance+=a;
		 pol1=acc[i];
	 }else
	 {
		 greedydistance+=b;
		 pol2=acc[i];
	 }
	 i++;
 }

 return greedydistance;
}



void f(int i,Cord pol1,Cord pol2,int dist)
{
	//printf("acc:%d , pol1(%d,%d), pol2(%d,%d) dist:%d\n",i,pol1.x,pol1.y,pol2.x,pol2.y,dist);
    if(dist >= value ) return;

	func_count++;

	if(i==m+1)
	{
		if(value > dist ) value=dist;
		return;
	}

	//경찰차1
	int d1 = getDistance(acc[i],pol1); 
	f(i+1,acc[i],pol2,dist+d1);

	//경찰차2
	int d2 = getDistance(acc[i],pol2); 
	f(i+1,pol1,acc[i],dist+d2);

}



void main()
{

freopen("input.txt","r",stdin);
scanf("%d",&n);
scanf("%d",&m);

for(int i=1;i<=m;i++)
{
	scanf("%d %d",&acc[i].x,&acc[i].y);
}

Cord pol1;
Cord pol2;

pol1.x=1;
pol1.y=1;

pol2.x=n;
pol2.y=n;

value=greedy();
f(1,pol1,pol2,0);

printf("%d\n",value);
printf("func_count:%d\n",func_count);
}


/////////////////////////////////////


//창훈 최종 사건 중심 DT 테이블 적용
#include<stdio.h>

int n; // map 크기 
int m; // 사건수

int func_count;

struct Cord
{
	int x;
	int y;
};

int DT[100][100];


Cord acc[100]; // 100개의 사건과 x,y값

int value=987654321;

int abs(int a)
{
 return a < 0 ? a*(-1) : a;
}


int getDistance(int start_acc,int end_acc)
{
	 return abs(acc[start_acc].x-acc[end_acc].x) + abs(acc[start_acc].y-acc[end_acc].y); 
}


int max(int a,int b)
{
	return a>b ? a:b;
}

int min(int a,int b)
{
	return a<b ? a:b;
}


int f(int a, int b)
{

	if(DT[a][b]!=-1) return DT[a][b];
	func_count++;

	int next_acc= max(a,b)+1;

	if(next_acc==m+2) return DT[a][b]=0;  //여기 실수 했음. 이건 아래와 같이 콜스텍을 찍어봐야지 실수가 없다.
	//printf("a:%d b:%d \n",a,b);

	int a_dist=f(next_acc,b) + getDistance(a,next_acc);
	int b_dist=f(a,next_acc) + getDistance(b,next_acc);

	return DT[a][b]=min(a_dist,b_dist);
}



void main()
{

freopen("input.txt","r",stdin);
scanf("%d",&n);
scanf("%d",&m);

for(int i=2;i<=m+1;i++)
{
	scanf("%d %d",&acc[i].x,&acc[i].y);
}

for(int i=0;i<100;i++)
for(int j=0;j<100;j++)
DT[i][j]=-1;

acc[0].x=1;  //중요!! 이 부분 틀렸다. 0 번 사건 , 1번 사건을 이렇게 집어 넣는다. 아이디어가 중요함.
acc[0].y=1;

acc[1].x=n;
acc[1].y=n;

printf("%d\n",f(0,1)); // 설계를 틀렸다. 중요하다. a는 0번 사건위치에,b는 1번 사건 위치에.
printf("func_count: %d\n",func_count);
}




