//숙직선생님
//창훈 최종 노트 정리,
//Backtracking+가치치기 , BFS 방식은 데이터가 적을땐 답이 나오지만.
//해당 정의역이 1000까지 임으로 DT 테이블을 안쓰면 정확한 결과를 얻을 수 없다.


//창훈 최종 필기 backtracking
//데이터

/*
1 15
2 5 7

1 25 
2 5 7

//가지치기를 해도 아래와 같이 데이터 껀수가 커지면 답이 나오지 않음.!!!!
1 200
2 5 7 

*/

#include<stdio.h>

#define INF 987654321

int T;
int S;
int CAN[3];

int DT[1001];

int func_call;

int MIN(int a,int b)
{
	return a>b? b:a;
}


int solve(int t)
{

	if(DT[t]!=-1) return DT[t];

	func_call++;

	int min=INF;

	if(t>S)
	{
		return DT[t]=INF;
	}

	if(t==S)
	{
		return DT[t]=0;
	}

	for(int i=0; i< 3; i++)
	min=MIN(min,solve(t+CAN[i])+1);

	return DT[t]=min;
}

void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d %d",&T,&S);

	scanf("%d %d %d",&CAN[0],&CAN[1],&CAN[2]);
}

void main()
{
	input();

	for(int i=0;i<=1000;i++)
	DT[i]=-1;

	int result=solve(T);
	if(result==INF)
		printf("-1\n");
	else
		printf("%d\n",result);

	printf("func_call %d\n",func_call);
}






//backtracking 풀이
#include<stdio.h>

// 1<=a<=b<=1000 
int a;  //선생님 위치
int b;  //도둑 위치
int can[3];
int min_sec=987654321;

int func_count;

void solve(int k,int a_loc)
{
	if(k>min_sec) return;

	func_count++;

	if(a_loc >= b)
	{
		if(a_loc == b) { 
		   if(min_sec > k )
		   {
			   min_sec=k;
		   }
		}
		return;
	}
	
		
	for(int i=0;i<3;i++)
	{
		solve(k+1,a_loc+can[i]);
	}
	
}


void main()
{
	freopen("input.txt","r",stdin);
	scanf("%d %d",&a,&b);
	
	for(int i=0;i<3;i++)
	{
		scanf("%d",&can[i]);
	}	
	
	solve(0,a);
	
	if(min_sec==987654321)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n",min_sec);
	}
	printf("func_count:%d\n",func_count);
}




//BFS
//시간 안에 올바른 답을 얻지 못한다.
//결국 이 방법도 안된다.

#include<stdio.h>

// 1<=a<=b<=1000 
int a;  //선생님 위치
int b;  //도둑 위치
int can[3];
int min_sec=987654321;
int func_count;

struct node
{
	int sec;
	int loc;
};

node Q[10000000];
int f=-1;
int r=-1;

int worst_time;

int solve()
{
	r++;
	Q[r].sec=0;
	Q[r].loc=a;

	while(f!=r)
	{
		f++;
		int new_sec=Q[f].sec;
		int new_loc=Q[f].loc;

		if(new_loc==b) return new_sec; 
		if(new_sec>=worst_time) return -1;

		//printf("sec : %d\n",new_sec);

		for(int i=0;i<3;i++)
		{
          r++;
		  Q[r].sec=new_sec+1;
		  Q[r].loc=new_loc+can[i];
		}
	}
}


void main()
{
	freopen("input.txt","r",stdin);
	//freopen("output_teacher.txt","w",stdout);

	scanf("%d %d",&a,&b);
	
	
	int temp=987654321;
	for(int i=0;i<3;i++)
	{
		scanf("%d",&can[i]);
		if(temp>can[i]) temp=can[i];
	}	
	
	 worst_time=( (b-a) / temp ) +1;

	printf("%d",solve());
}


/////////////////
//창훈 필기 DT 테이블 방법 창훈 창의적으로 직접 풀었음.
//창훈 직접 품.
//필기 알고리즘 참조

#include<stdio.h>

#define TEST_SIZE 1000

int DT[2000]; //여기 같은 1000보다 커야한다. 왜냐면 1000을 넘어서기 때문이다.

int a;
int b;
int can[3];

//깔끔하게 전역변수 분리

int MIN(int a1,int b1,int c1)
{
	int mid = a1 > b1 ? b1 : a1;
	return mid > c1 ? c1 : mid;
}


int f(int a_loc)
{
	//답이 안나오면 여기에 로그를 한번 넣어 본다.
	if(DT[a_loc]!=-1) return DT[a_loc];

	if(a_loc >= b)
	{
		if(a_loc==b)
		{
			return DT[a_loc]=0;
		}
		return DT[a_loc]=987654321;
	}

	return DT[a_loc]=MIN( f(a_loc+can[0])+1,
						 f(a_loc+can[1])+1,
						 f(a_loc+can[2])+1
					    );
}

void main()
{
  freopen("input.txt","r",stdin);
  //freopen("output_teacher_hoony.txt","w",stdout);
	

	  scanf("%d %d",&a,&b);
	  scanf("%d %d %d",&can[0],&can[1],&can[2]);
  
	  for(int i=0;i<2000;i++)
	  DT[i]=-1;

	  int result=f(a);
	  if(result>=987654321) 
	  {
		  printf("-1\n");
	  }
	  else
	  {
		  printf("%d\n",result);
	  }
}






//////////////////////////////
//교재풀이 참조하길 상향식 방법
//최종 정답확인을 위해서 

#include <stdio.h> 
#define TEST_SIZE 1000
#define MIN(a,b) ((a)>(b)?(b):(a)) 
int a, b, able[3], d[1001]; 

int main() {  
	
    freopen("input_teacher.txt","r",stdin);
	 freopen("output_teacher_book.txt","w",stdout);

    for(int k=0;k<TEST_SIZE;k++)
    {

	scanf("%d%d", &a, &b);  
	for(int i=0; i<3; i++)    
	scanf("%d", &able[i]);

    if(a==b) printf("0");  
    else  
	{    
	      for(int i=a; i<=b; i++)      
		  d[i]=123456789;    
	  
		  d[a]=0;
    
		  for(int i=a+1; i<=b; i++)    
	      {      
			int temp=123456789;     
			for(int k=0; k<3; k++)     
			{        
			  if(i-able[k]>=a) temp=MIN(temp, d[i-able[k]]+1);      
			}     
			d[i]=temp;    
		  }

		 if(d[b]!=123456789) printf("%d\n", d[b]);     
		 else printf("-1\n");  
	}  
	
	}

  return 0; 
}





