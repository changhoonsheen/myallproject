
/*
10 1 
10 1000 
20 1000 
30 1000 
40 1000 
5000 5000 
1000 60 
1000 70 
1000 80 
1000 90 
7000 7000
*/


//실수한 부분 유념해라!!!!

#include<stdio.h>
#include<math.h>

int N; //비행장 갯수
int STOP;

struct CORD
{
	int x;
	int y;
	int stop;
};

CORD airport[10];
CORD start={0,0};
CORD end={10000,10000};

int check[10];

CORD Q[100000];
int f=-1;
int r=-1;


double getDistance(CORD a, CORD b)
{
	return sqrtf((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int isitpossible(CORD a, CORD b , int fuel)
{
	double result=getDistance(a,b);
	
	if(result <= (double)(fuel * 10.0)) return 1;
	
	return 0;

}


int solve(int fuel)
{
	f++;
	Q[f]=start;

	while(f!=r)
	{
		r++;
		CORD new_airport=Q[r];

	   if(new_airport.stop<=STOP &&
		  isitpossible(new_airport, end , fuel) 
		 )
	   {
		   return 1;
	   }

	   for(int i=0;i<N;i++)
	   {
		   if(isitpossible(new_airport, airport[i] , fuel) &&
			  check[i]==0 
			 )
		   {
			   check[i]=1;
			   f++;
			   Q[f]=airport[i];
			   Q[f].stop=new_airport.stop+1;// 실수!!!!! 여기 실수함.!! 
			   //Q[f].stop=Q[f].stop+1; //<- 이렇게 적었음!!!
			                               
		   }
	   }

	}

	return 0;
}

void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d %d",&N,&STOP);

	for(int i=0;i<N;i++)
	{
		scanf("%d %d",&airport[i].x,&airport[i].y);
	}
}

void init()
{
	f=-1;
	r=-1;

	for(int i=0;i<10;i++)
    check[i]=0;
}

int main(void)
{
	input();

	int lb=0;
	int ub=14400;

	while(lb<ub)
	{
		int m = (lb+ub-1)/2;

		init();
		if(solve(m))
		{
			ub=m;
		}
		else
		{
			lb=lb+1;
		}
	}

	printf("%d",ub);
}


////////////////////////////


//창훈 결정 문제 최종
//기름으로 풀기 
#include<stdio.h>
#include<math.h>

int N;
int K;

struct CORD
{
	int x;
	int y;
};

CORD airport[10];

struct NODE
{
	CORD airport;
	int count;
};

NODE Q[10000];

int f=-1;
int r=-1;

int check[10];

CORD start;
CORD end;

void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d %d",&N,&K);

	for(int i=0;i<N;i++)
	scanf("%d %d",&airport[i].x,&airport[i].y);

	
	start.x=0;
	start.y=0;

	end.x=10000;
	end.y=10000;
}


float getDIST(CORD a, CORD b)
{
	return sqrtf( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}

int getFuel(CORD a, CORD b)
{
	float dist =getDIST( a,  b);

	//printf("%f",dist);

	int temp= (int)dist;

	return  dist > (float)temp ? temp/10 + 1 : temp/10; 
}
	

void init()
{
	f=-1;
	r=-1;

	for(int i=0;i<N;i++)
	check[i]=0;
}

//해당 기름으로 갈수 있는가? K번 정차하고 
int solve(int m)
{
r++;
Q[r].airport=start;
Q[r].count=0;

while(f!=r)
{
	f++;
	NODE new_node=Q[f];

	if( getFuel(new_node.airport,end) <= m && new_node.count <= K ) return 1;

	for(int i=0;i<N;i++)
	{
		if(check[i]==0 &&
		   getFuel(new_node.airport,airport[i]) <= m  &&
		   new_node.count+1 <= K )
		{
			r++;
			Q[r].airport=airport[i];
			Q[r].count=new_node.count+1;
			check[i]=1;
		}
	}
}

return 0;
}


void main()
{
	input();

	int lb=0;
	int ub=getFuel(start, end);

	while(lb<ub)
	{
		init(); // 큐 위치 초기화 / check 배열 초기화 
		int m = (lb + ub -1) /2;
		if(solve(m)) ub=m;
		else lb=m+1;

	}

	printf("%d",ub);
}







//위하고 똑같은 문제 거리로 풀기 
//창훈 최종풀이 결정문제로 풀기 제일깔끔하게 풀었다.
//기름으로 바꿔도 되고, 거리로 풀어도 된다.
#include<stdio.h>
#include<math.h>

int N;
int K;

struct CORD
{
	int x;
	int y;
};

CORD airport[10];

struct NODE
{
	CORD airport;
	int count;
};

NODE Q[10000];

int f=-1;
int r=-1;

int check[10];

CORD start;
CORD end;

void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d %d",&N,&K);

	for(int i=0;i<N;i++)
	scanf("%d %d",&airport[i].x,&airport[i].y);

	
	start.x=0;
	start.y=0;

	end.x=10000;
	end.y=10000;
}


float getDIST(CORD a, CORD b)
{
	return sqrtf( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}

int getFuel(CORD a, CORD b) //소수점이 있으면 올림으로 처리한다.
{
	float dist =getDIST( a,  b);

	//printf("%f",dist);

	int temp= (int)dist;

	return  dist > (float)temp ? temp/10 + 1 : temp/10; 
}
	

void init()
{
	f=-1;
	r=-1;

	for(int i=0;i<N;i++)
	check[i]=0;
}

//해당 기름으로 갈수 있는가? K번 정차하고 
int solve(int m)
{
r++;
Q[r].airport=start;
Q[r].count=0;

while(f!=r)
{
	f++;
	NODE new_node=Q[f];

	if( getDIST(new_node.airport,end) <= m && new_node.count <= K ) return 1;

	for(int i=0;i<N;i++)
	{
		if(check[i]==0 &&
		   getDIST(new_node.airport,airport[i]) <= m  &&
		   new_node.count+1 <= K )
		{
			r++;
			Q[r].airport=airport[i];
			Q[r].count=new_node.count+1;
			check[i]=1;
		}
	}
}

return 0;
}


void main()
{
	input();

	int lb=0;
	int ub=getFuel(start, end);

	while(lb<ub)
	{
		init(); // 큐 위치 초기화 / check 배열 초기화 
		int m = (lb + ub -1) /2;
		if(solve(m*10)) ub=m;
		else lb=m+1;

	}

	printf("%d",ub);
}




























//////////////////////////////////////////////////////////////////

//창훈 최종필기.
//Backtracking.
//이전에 잘못풀었음. 이렇게 풀면안되면 
//만약 경유가 100까지 허용한다면?? 이때까지 잘못 풀었다.

10 10
10 1000
20 1000
30 1000
40 1000
5000 5000
1000 60
1000 70
1000 80
1000 90
7000 7000
-> 634



#include<stdio.h>
#include<math.h>

struct Cord
{
	int x;
	int y;
};

//배열의 구조
//인덱스 0: 제일 처음 시작 비행장
//중간 비행장들
//제일 마지막이 도착 비행장

Cord cord[10+2];
int check[10+2];

int drops;
int airports;

float min_distance=(float)99999.0;

float MAX(float a, float b)
{
	return a>b ? a:b;
}

void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d %d",&airports,&drops);
	for(int i=1;i<=airports;i++)
	{
		scanf("%d %d",&cord[i].x,&cord[i].y);
	}

	cord[0].x=0;
	cord[0].y=0;
	cord[airports+1].x=10000;
	cord[airports+1].y=10000;
}

float getDistance(Cord a, Cord b)
{
	return sqrt((float) ((a.x-b.x)*(a.x-b.x) +  (a.y-b.y)*(a.y-b.y)) );
}



void f(int k, Cord current,float distance)
{

	if(k==drops)
	{
		float new_distance=MAX(getDistance(current,cord[airports+1]),distance);

		if( min_distance > new_distance) min_distance=new_distance;
		return;
	}


	for(int i=1;i<=airports;i++)
	{
		if(check[i]==0)
		{
			check[i]=1;
			float new_distance=MAX(getDistance(current,cord[i]),distance);
			f(k+1,cord[i],new_distance);
			check[i]=0;
		}
	}
}

void main()
{
	input();
	
	//더 많은 정차가 있을수 있다. 트리를 그려보고 깊이를 어디까지 돌릴것인가?
	if(drops > airports) drops=airports; // 이부분 반드시 필요하다. 실수!!!
	//k는  0<=k<=1000
	
	f(0,cord[0],0.0);
	printf("distance:%f\n",min_distance);

	int fuel =  (int) min_distance/10.0;
	if( (float)fuel < (float) min_distance/10.0) printf("fuel :%d",fuel+1);
	else printf("fuel :%d",fuel);
}





//BFS + 결정문제로접근

#include<stdio.h>
#include<math.h>

struct Cord
{
	int x;
	int y;
	
	int deep;
};

//제일 처음 시작 비행장
//중간
//제일 마지막이 도착 비행장

Cord cord[10+2];
int check[10];

int drops;
int airports;

float min_distance=(float)99999.0;


Cord Q[5000];
int f=-1;
int r=-1;


void input()
{
	scanf("%d %d",&airports,&drops);
	for(int i=1;i<=airports;i++)
	{
		scanf("%d %d",&cord[i].x,&cord[i].y);
		cord[i].deep=0;
	}

	cord[0].x=0;
	cord[0].y=0;
	cord[airports+1].x=10000;
	cord[airports+1].y=10000;
}

float getDistance(Cord a, Cord b)
{
	return sqrt((float) ((a.x-b.x)*(a.x-b.x) +  (a.y-b.y)*(a.y-b.y)) );
}


//해당 기름으로 도착지까지 갈 수 있는가?
int solve(float distance)
{
	r++;
	Q[r]=cord[0];
	
	while(f!=r)
	{
		f++;
		Cord new_airport=Q[f];

		if(new_airport.x==cord[airports+1].x && new_airport.y==cord[airports+1].y &&
		   drops >= (new_airport.deep)-1)  //허용 경유횟수 >= 실제 도착지까지 올때 경유횟수
		   {
			   return 1;
		   }
		
		for(int i=1;i<=airports+1;i++)
		{
      		float new_dist=getDistance(new_airport,cord[i]);

			if(new_dist <= distance && cord[i].deep==0)
			{
				r++;
				Q[r]=cord[i];
				Q[r].deep=new_airport.deep+1;
				cord[i].deep=new_airport.deep+1;
			}
		}
	}
	
	return 0;
}

void init()
{
	f=-1;
	r=-1;

	for(int i=1;i<=airports+1;i++)
	{
		cord[i].deep=0;
	}
}

void main()
{
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);	

	input();
	
	//for debugging
	/*
	for(int i=500;i<950;i++)
	{
		init();
		printf("fule:%d possible:%d\n",i,solve((float)i*10.0));
	}
	*/
	int lb=0; 
	int ub=1415;
	while(lb<ub)
	{
		init(); //초기화 루티 실수 없도록
		int m=(lb+ub-1)/2;
		if(solve((float)m*10.0)) ub=m;
		else lb=m+1;
	}

	printf("%d\n",ub);
}





























//옛날 풀이
//아래 그냥 참조만하도록

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
///////////////////////////////////////////////////////////////////////////

//>>>>>>>>>>>>>
// 전체 탐색 문제 창훈 md에서 품 
/*
10 3
10 1000
20 1000
30 1000
40 1000
5000 5000
1000 60
1000 70
1000 80
1000 90
7000 7000
-> 634

10 10
10 1000
20 1000
30 1000
40 1000
5000 5000
1000 60
1000 70
1000 80
1000 90
7000 7000
->634


6 4
10 1000
20 1000
30 1000
1000 80
1000 90
7000 7000
-> 916


6 3
10 1000
20 1000
2000 2000
1000 80
1000 90
7000 7000
-> 708

6 2
10 1000
20 1000
2000 2000
1000 80
1000 90
7000 7000
-> 708


20 3
10 1000
20 1000
30 1000
40 1000
5000 5000
1000 60
1000 70
1000 80
1000 90
7000 7000
11 1000
21 1000
31 1000
41 1000
5001 5000
1001 60
1001 70
1001 80
1001 90
7001 7000


Backtracking으로 
이런건 값이 안나옴.
40 10
10 1000
20 1000
30 1000
40 1000
5000 5000
1000 60
1000 70
1000 80
1000 90
7000 7000
11 1000
21 1000
31 1000
41 1000
5001 5000
1001 60
1001 70
1001 80
1001 90
7001 7000
10 1001
20 1001
30 1001
40 1001
5000 5001
1000 61
1000 71
1000 81
1000 91
7000 7001
11 1001
21 1001
31 1001
41 1001
5001 5001
1001 61
1001 71
1001 81
1001 91
7001 7001

*/


//>>>>>>>>>>>>>
//0.창훈 최종 결정 문제로 접근하기
//아래 백트래킹 방법 1하고 , 이 결정 문제만 다시 풀어 본다.


#include<stdio.h>
#include<math.h>

struct Cord{
	int x;
	int y;
	int stop_count;
};

int K;
int N;

Cord airport[100];
Cord target;

Cord Q[10000];

//두 공항 사이의 거리
double getDistance(Cord a, Cord b)
{
	double d = sqrt ((double)( (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
	return d;
}

//거리에 대한 연료량
int getFuel(double a)
{
	int result = (int) (a/(double)10.0);
	if( a > (double)result) return result+1;
	else return result;
}

//결정함수는 L용량의 기름통으로 K번 이하로 stop해서 T 목적지까지 갈수가 있는가?
int f(int x)
{
	//>> // 초기화 이 부분 중요
	int f=-1;
	int r=-1;
	
	for(int i=1;i<=N;i++)
	{
		airport[i].stop_count=0;
	}
	//<<
	
	r++;
	Q[r]=airport[0];
	
	while(f!=r)
	{
		f++;
		Cord new_airport=Q[f];
		int new_stop_count=Q[f].stop_count;
		
		//큐에서 가지고 올때 매번 해당 공항에서 부터 도착지까지 주어진 x 연료를 가지고 갈 수 있나?
		if( getFuel(getDistance(new_airport,target)) <= x) return 1;		
		
		//모든 후보군에 대해서.
		for(int i=1;i<=N;i++)
		{
			if(airport[i].stop_count==0 &&  //방문하지 않은 공항이며.
			   getFuel(getDistance(new_airport,airport[i])) <= x && // 주어진 기름으로 갈수 있고.
			   new_stop_count < K // 정차 횟수를 만족한다면
			)
			{
			   r++;
			   airport[i].stop_count=new_stop_count+1; //정차 횟수를 기록한다.
			   Q[r]=airport[i];
			}
		}
	}
	
	return 0;
}

void main(void)
{
	//시작 공항
	airport[0].x=0;
	airport[0].y=0;
	
	//도착 공항
	target.x=10000;
	target.y=10000;
	
	freopen("input.txt","r",stdin);
	
	scanf("%d %d",&N,&K);

	for(int i=1;i<=N;i++)
	scanf("%d %d",&airport[i].x,&airport[i].y);
	
	//최대거리에 대한 연료 : 처음 점과 끝점을 연결하고 연료를 구함. 
	int ub=getFuel(getDistance(airport[0],target));
	int lb=0;
	
	//해의 집합은 뭐냐? 교재 참조.
	while(lb < ub)
	{
		//printf("lb:%d  ub:%d\n",lb,ub);
		int m = (ub + lb -1) /2;
		if(f(m)) ub=m;
		else lb = m+1;
	}
	
	printf("%d",ub);
}





// 창훈 최종,
// 백트래킹 1, check 배열에 방문한 공항을 체크하고 이를 Base에서 복원하는 방법.
// 교재 그림 참조.

#include<stdio.h>
#include<math.h>

struct Cord{
	int x;
	int y;
};

Cord start,end;

Cord airport[50];
Cord selected_airport[50];


int arr[50];
int chk[50];

double min_distance=987654321.0;

int n;
int drop;

int func_call;

int getFuel(double result)
{
	int oil = (int )( (double)result/(double)10.0);
	
	if((double)oil * (double)10.0 < result) return oil+1;
	else return oil;
}

double getDistance(Cord a,Cord b)
{
	double result = (double)sqrt((double)( (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y) ));
	return result;
}

void f(int k)
{

	func_call++;
	
if(k==drop)
{	

	selected_airport[0].x=0;
	selected_airport[0].y=0;

	for(int i=0;i<drop;i++)
	{
		//printf("%d ",arr[i]);

		selected_airport[i+1]=airport[arr[i]];
	}

	selected_airport[drop+1].x=10000;
	selected_airport[drop+1].y=10000;


	double dist=0.0;
	for(int i=1;i<=drop+1;i++)
	{
		double d=getDistance(selected_airport[i-1] , selected_airport[i]); 
		if(dist < d) dist=d;
	}

	if(dist < min_distance) min_distance=dist;

	return;
}

for(int i=0;i<n;i++)
{
	if(chk[i]==0)
	{
		chk[i]=1;
		arr[k]=i;
		f(k+1);
		chk[i]=0;
	}
}

	
}

void main()
{

freopen("input.txt","r",stdin);
scanf("%d %d",&n,&drop);

for(int i=0;i<n;i++)
{
 scanf("%d %d",&airport[i].x,&airport[i].y);
}

f(0);

printf("func_call:%d\n",func_call);
printf("oil:%d",getFuel(min_distance));

}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


// 창훈 최종
// 2. 백트레킹으로 풀어보기 , 가장 긴 구간을 계산하면서 내려가기. 그리고 바닥에서 MIN을 갱신하기

#include<stdio.h>
#include<math.h>

struct cord
{
	int x;
	int y;
};

cord airport[10];
int checked[10];


int n;    // 비행장의 수
int stop; // 정차 횟수

double min_distance=0xffffff;

static int fuction_call;

//>> 인터넷상에 아래 함수 쓰면 결과가 안나옴.
//>> math 라이브러리를 사용해야함.
double SQRT(double input)
{
	 double x=2.0;
     for(int i=0; i<10; i++) {  x = (x + (input / x)) / 2 ; }    
     return x ;
}
//<<



void solve(int x,int y, double d, int k)
{
	    fuction_call++;

		if(k==stop)
		{
			double mid =  (double) ( (10000 - x) * (10000 - x) + (10000 - y) * (10000 - y) );
			double dist= sqrt(mid); // last path
			double distance=0.0;

    	    if( dist > d ) distance=dist;
			else  distance=d;		

		//	printf("last %f\n",distance);
		
		    if( distance < min_distance )  min_distance=distance;		
			
 		    return;
		}	

	
		for(int i=0;i<n;i++)
		{
			if(checked[i]==0)
			{
              double mid =  (double) ( (airport[i].x - x) * (airport[i].x - x) + (airport[i].y - y) * (airport[i].y - y) );
			  double dist= sqrt(mid);
			  double distance=0.0;
			  
			  //위에서 내려온 값이 작으면 현재 계산된 값을 아래로 내려준다.
			  //교재 트리 그림 참조 이렇게 바닥까지 내려간다.
			  if( dist > d ) distance=dist;
			  else  distance=d;

			 // printf("k:%d, i:%d -  %f \n",k,i,distance );
			  
			  checked[i]=1;	
			  solve(airport[i].x,airport[i].y,distance,k+1);
			  checked[i]=0;
			}	
			
		}
	
	
}


void main()
{
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

    scanf("%d %d",&n,&stop);
	
	for(int i=0;i<n;i++)
	scanf("%d %d",&airport[i].x,&airport[i].y);	
	
	solve(0,0, 0.0 ,0);
	
	
	
	printf("%f\n",min_distance);
	printf("%d\n",fuction_call);


	int fuel = min_distance /10;  // 1리터당 10km 숫자 자름 
	 
	if( (double) (fuel*10) <  min_distance )  printf("%d", fuel+1);
	else  printf("%d", fuel);

}


//AD 결정 문제로 접근하기.
///////////////////////////////////
//>>>>>>>>>>>>>
// 결정 문제로 접근하기 from 교재  , 창훈이 BFS 로 접근함
/*
 L 리터의 연료통으로 k개 이하의 경유지를 거쳐 목적지에 도달할 수 있는가?
 도착할수 있다면 이때 최소 연료통의 크기는?
 아래 교재 정답하고 똑같음.

10 3
10 1000
20 1000
30 1000
40 1000
5000 5000
1000 60
1000 70
1000 80
1000 90
7000 7000
-> 634

10 10
10 1000
20 1000
30 1000
40 1000
5000 5000
1000 60
1000 70
1000 80
1000 90
7000 7000
->634


6 10
10 1000
20 1000
30 1000
1000 80
1000 90
7000 7000
->916


6 15
10 1000
20 1000
2000 2000
1000 80
1000 90
7000 7000
->708

6 30
10 1000
20 1000
2000 2000
1000 80
1000 90
7000 7000
->708
 
 
 */	


//>>>>>>>>>>>>>>>>>>>>>>>>>>
// 교재를 응용해서 내가 결정 문제로 풀기 
// Backtracking은 데이터 껀수가 많아 지면 결과가 나오지 않는다.

#include<stdio.h>
#include<math.h>

struct Cord
{
	int x;
	int y;
	int step;
};


Cord airport[50]; // 경유 공항
Cord end;         // 도착지 위치 

Cord Q[100000];

int n;    // 비행장의 수
int stop; // 정차 횟수

double min_distance=0xffffff;


int getdist(Cord a, Cord b)
{
 	return  (int)sqrt( (double) (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) ); 
}

int getFuel(double result)
{
	int oil = (int )( (double)result/(double)10.0);
	
	if((double)oil * (double)10.0 < result) return oil+1;
	else return oil;
}


int front=-1;
int rear=-1;

int f(int x)
{
	front=-1;  // 이 함수는 매번 호출됨으로 초기가 들어 올때마다 초기가 필요함.
	rear=-1;
	
	rear++;
	Q[rear].x=0; // 시작공항 그냥 들어감 
	Q[rear].y=0;
	Q[rear].step=0;
		
	while(front!=rear)
	{
	  
		 front++;
		 Cord newairport=Q[front];
		
		if( newairport.step <= stop ) // 경유 횟수 체크 
		{
			 if( getdist(newairport, end) <= (x*10))  return 1;  // 현재 해당 기름으로 마지막 경유공항에서 바로 목적지가 도착이 되나? 
		
			 for(int i=0 ; i<n ; i++)  
			 {		 
				int dist=getdist(newairport,airport[i]);
				
				if(dist <= (x*10) && airport[i].step==0 )  // 그림을 그려 보면 해당 기름에 따라 가능 유무을 알아 보는것이기 때문에  step이 0인 공항만 방문한다. 
				{
				   rear++;
				   airport[i].step=newairport.step+1;
				   Q[rear]=airport[i];	
				} 
			 }
		}

	}

	return 0;
}



void main()
{
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

    scanf("%d %d",&n,&stop);
	
	for(int i=0;i<n;i++)
	scanf("%d %d",&airport[i].x,&airport[i].y);	
	
	end.x=10000; 
	end.y=10000;

// 이제 이진탐색으로 접근 
int ub=getFuel(sqrt( (double)( 10000*10000 + 10000*10000) )); // 최대 거리에 대한 기름용량으로 변경
int lb = 0;

int m=0;
while(lb < ub)
{
	m=(ub+lb-1)/2;
	for(int i=0;i<10;i++) airport[i].step=0;  // 초기화 해줘야함. 다음 스텝에 사용하기 위해서 
	if(f(m))  ub=m;
	else lb=m+1;
}
printf("%d\n",ub);


}

//////////////////////////////////////////////////////////////////
//교재 풀이 
//////////////////////////////////////////////////////////////////

#include <cstdio>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;
struct P{int x, y;};
int N, K, T, chk[1013], D[1013][1013];
P S[1013];
int f(int t)
{
queue<int> Q;
memset(chk,-1, sizeof(chk));
Q.push(0), chk[0]=0;
while(!Q.empty())
{
int i;
T=Q.front(), Q.pop();
if(chk[T]>K+1) return 0;
else if(T==N+1) return 1;
for(i=0; i<=N+1; i++)
{
if(chk[i]==-1 && D[T][i]<t*10)
{
chk[i]=chk[T]+1;
Q.push(i);
}
}
}
return 0;
}
int main()
{
int i, j, lb=0, ub=14142, m, x, y;
	
freopen("input.txt","r",stdin);
scanf("%d %d", &N, &K);
S[0].x=S[0].y=0,S[N+1].x=S[N+1].y=10000;
for(i=1; i<=N; i++) scanf("%d%d",&S[i].x,&S[i].y);
for(i=0; i<=N+1; i++)
for(j=0; j<=N+1; j++)
D[i][j]=(int)sqrt((double)(S[i].x-S[j].x)*(S[i].x-S[j].x)+(S[i].y-S[j].y)*(S[i].y-S[j].y));
while(lb<ub)
{
m=(ub+lb-1)/2;
if(f(m)) ub=m;
else lb = m+1;
}
printf("%d\n", ub);
return 0;
}






//+++++++++++++++++++++++++++++++++++++++++++
//MD 풀이

//>>>>>>>>>>>>>
//창훈풀이 
//교재 풀이도 나와 동일하게  풀었다.
//입력 교재 것을 쓰면 제대로 안나옴.<히든 문자때문에>

10 5
10 1000
20 1000
30 1000
40 1000
5000 5000
1000 60
1000 70
1000 80
1000 90
7000 7000


//////////////////////////////////////////////////////////////////////////
// 최종 접근, 좋은 문제이다.
// DFS로 접근한다. 도착할때 거리중 가장긴게 그 경로의 연료통의 크기이다.
//////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<math.h>

int k;
int n;

struct Cord
{
	int x;
	int y;
};

Cord cord[10];
int checked[10];

Cord end={10000,10000};

int min=987654321;

float getdistance(Cord a,Cord b)
{
	return sqrt((float)((a.x - b.x)*(a.x - b.x)) + (float)((a.y - b.y)*(a.y - b.y)));
}

void solve(int p,int airport,int dist) // p 선택된 공항수, 현재 노드의 공항, 현재까지 깊에 있어서 가장긴 경로,
{	

	if(p==k)
	{
		 int new_dist=getdistance(cord[airport],end);
		 if(new_dist < dist) new_dist=dist; 

		 if(min > new_dist) min=new_dist;

		 return;
	}
 

	for(int i=1;i<=n;i++)
	{
		if(checked[i]==0)
		{
		 checked[i]=1;

		 int new_dist=getdistance(cord[airport],cord[i]);
		 if(new_dist < dist) new_dist=dist; 

		 solve(p+1,i,new_dist);
		 checked[i]=0;
		}

	}
		
 
}

void main()
{
  freopen("input.txt","r",stdin);
  
  scanf("%d %d",&n,&k); 
  for(int i=1;i<=n;i++) // 첫번째는 시작 공항이다.
  {
	 scanf("%d %d",&cord[i].x,&cord[i].y);
  }

  solve(0,0,0);
  
  printf("min %d\n",min);
 
  int fuel=0;
  if(min%10) { fuel=min/10;  fuel+=1;}  // 나머지가 존재 한다면
  else fuel=min/10; // 딱 떨어진다면

   printf("fuel %d",fuel);
}

//>>>>>>>>>>>>>

#include<stdio.h>
#include<math.h>

struct cord
{
	int x;
	int y;
};

cord airport[10];
int checked[10];


int n;    // 비행장의 수
int stop; // 정차 횟수

double min_distance=0xffffff;

static int fuction_call;

//>> 인터넷상에 아래 함수 쓰면 결과가 안나옴.
//>> math 라이브러리를 사용해야함.
double SQRT(double input)
{
	 double x=2.0;
     for(int i=0; i<10; i++) {  x = (x + (input / x)) / 2 ; }    
     return x ;
}
//<<



void solve(int x,int y, double d, int k)
{
	    fuction_call++;

		if(k==stop)
		{
			double mid =  (double) ( (10000 - x) * (10000 - x) + (10000 - y) * (10000 - y) );
			double dist= sqrt(mid); // last path
			double distance=0.0;

    	    if( dist > d ) distance=dist;
			else  distance=d;		

		//	printf("last %f\n",distance);
		
		    if( distance < min_distance )  min_distance=distance;		
			
 		    return;
		}	

	
		for(int i=0;i<n;i++)
		{
			if(checked[i]==0)
			{
              double mid =  (double) ( (airport[i].x - x) * (airport[i].x - x) + (airport[i].y - y) * (airport[i].y - y) );
			  double dist= sqrt(mid);
			  double distance=0.0;
			  
			  if( dist > d ) distance=dist;
			  else  distance=d;

			 // printf("k:%d, i:%d -  %f \n",k,i,distance );
			  
			  checked[i]=1;	
			  solve(airport[i].x,airport[i].y,distance,k+1);
			  checked[i]=0;
			}	
			
		}
	
	
}


void main()
{
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

    scanf("%d %d",&n,&stop);
	
	for(int i=0;i<n;i++)
	scanf("%d %d",&airport[i].x,&airport[i].y);	
	
	solve(0,0, 0.0 ,0);
	
	
	
	printf("%f\n",min_distance);
	printf("%d\n",fuction_call);


	int fuel = min_distance /10;  // 1리터당 10km 숫자 자름 
	 
	if( (double) (fuel*10) <  min_distance )  printf("%d", fuel+1);
	else  printf("%d", fuel);

}





