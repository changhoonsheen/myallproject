// 창훈 최종필기
// backtracking 방법. 가지치기을 사용할때 0~40까지는 답이 나온다.
// 하지만. 온도 갭이 더커지면 답이 나오지 않는다. 만약 0~100이면 가지치기를 해도 백트래킹은 답이 나오지 않는다. 

// BFS을 이용하면 가장 먼저 온도에 도달할때 탐색을 중지하는게 나오며되니깐, 제일 적합하다.

//백트래킹
#include<stdio.h>

int a; //현재 온도
int b; //원하는 온도
int min_pushcount=987654321;
int func_count;

void solve(int temp,int count)
{
	if(count > min_pushcount) return;

	func_count++;

	if(temp==b)
	{
		if(min_pushcount > count) min_pushcount=count;
		return;
	}

    if(temp > b)
	{
		solve(temp-1, count+1);
		solve(temp-5, count+1);
		solve(temp-10, count+1);
	}
	else
	{
		solve(temp+1, count+1);
		solve(temp+5, count+1);
		solve(temp+10, count+1);

	}
}

void main()
{
	//scanf("%d %d",&a,&b);
	a=7;
	b=34;

	solve(a,0);
	printf("min push count : %d\n",min_pushcount);
	printf("func_count:%d\n",func_count);
}



//BFS로 풀어보기
/*
백트래킹은 모든 호출이 끝아야지 해답을 얻을수 있다. 이러한 경우에는 깊이 우선 탐색이 비효율적이다.
너비 우선 탐색을 하면 버튼 누른 횟를 기준으로 먼저 목표 온도에 도달할때까지만 탐색하고 중단을 하면된다.!
*/


#include<stdio.h>

int a=7;
int b=34;

int f=-1;
int r=-1;

struct REMOTE
{
	int temp;
	int cnt;
};

REMOTE Q[10000000];

int solve(int temp)
{

	r++;
	Q[r].temp=temp;
	Q[r].cnt=0;

	while(f!=r)
	{	  

	  f++;
	  int new_temp=Q[f].temp;
	  int new_cnt=Q[f].cnt;

	  printf("- f:%d r:%d , new_temp:%d \n",f,r,new_temp);

	  if(new_temp == b) return new_cnt;
	  else if(new_temp < b)
	  {	
		r++;
		Q[r].temp=new_temp+1;
		Q[r].cnt=new_cnt+1;

		r++;
		Q[r].temp=new_temp+5;
		Q[r].cnt=new_cnt+1;

		r++;
		Q[r].temp=new_temp+10;
		Q[r].cnt=new_cnt+1;
	  }
	  else
	  {
		r++;
		Q[r].temp=new_temp-1;
		Q[r].cnt=new_cnt+1;

		r++;
		Q[r].temp=new_temp-5;
		Q[r].cnt=new_cnt+1;

		r++;
		Q[r].temp=new_temp-10;
		Q[r].cnt=new_cnt+1;
	   }
}
}


void main()
{
	freopen("out.txt","w",stdout);
	printf("%d",solve(a));
	
}




//백트래킹 눌린 흔적 남겨 보기
#include<stdio.h>

int s=7;
int e=30;

int MIN_CNT=987654321;
int func_call;

int check[40];
int result_check[40];

void solve(int temp , int cnt)
{

	if(MIN_CNT < cnt ) return;  //가지 치기를 해도 상관이 없다. 참조.15퍼즐은 스택을 이용해서 흔적을 남긴다.

	func_call++;


	if(temp==e)
	{
		if(MIN_CNT > cnt) 
		{
			MIN_CNT=cnt;

			for(int i=0;i<cnt;i++)
			result_check[i]=check[i];
		}
		return;
	}

	if(temp > e)
	{
		check[cnt]=-1;
		solve( temp-1 ,  cnt+1);

		check[cnt]=-5;
		solve( temp-5 ,  cnt+1);

		check[cnt]=-10;
		solve( temp-10 ,  cnt+1);
	}else
	{
		check[cnt]=1;
		solve( temp+1 ,  cnt+1);

		check[cnt]=5;
		solve( temp+5 ,  cnt+1);
		
		check[cnt]=10;
		solve( temp+10 ,  cnt+1);
	}
}

void main()
{
	solve(s , 0);
	printf("%d\n",MIN_CNT);
	printf("func_call:%d\n\n",func_call);

	for(int i=0;i<MIN_CNT;i++)
	printf("%d\n",result_check[i]);

}















