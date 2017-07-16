



/*

->6
8  
0 7 1
3 4 1
6 8 1
8 6 1
12 2 0
13 2 1
14 2 1
15 7 1

-> 0
7  
0 7 1
3 4 1
6 8 1
8 6 1
12 2 0
13 2 1
14 2 1

-> 0
6  
0 7 1
3 4 1
6 8 1
8 6 1
12 2 0
13 2 1



-> 0
5
0 7 1
3 4 1
6 8 1
8 6 1
12 2 0


-> 1
4
0 7 1
3 4 1
6 8 1
8 6 1



->  3
3
0 7 1
3 4 1
6 8 1


-> 0
15 
0 7 1
3 4 1
6 8 1
8 6 1
12 2 0
13 2 1
14 2 1
15 7 1
16 2 1
17 2 1
18 2 0
22 6 1
24 8 1
27 4 1
30 7 1


->18
11
0 7 1
3 4 1
6 8 1
8 6 1
12 2 0
13 2 1
14 2 1
15 7 0
16 9 1
17 5 1
18 9 1


-> 90
13
0 7 1
3 4 1
6 8 1
8 6 1
12 2 0
13 2 1
14 2 1
15 7 0
16 9 1
17 5 1
18 9 1
20 5 1
25 9 1


->0
15
0 7 1
3 4 1
6 8 1
8 6 1
12 2 0
13 2 1
14 2 1
15 7 0
16 9 1
17 5 1
18 9 0
20 5 1
25 9 1
30 2 1
33 3 1

*/

///////////////////
//창훈 최종 필기 직접품
///////////////////

//두방향 백트래킹 버젼
#include<stdio.h>

struct ISLAND
{
	int loc;
	int jump;
	int type;
};

ISLAND island[20];
int n;

int check[20];

void input()
{
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",&island[i].loc,&island[i].jump,&island[i].type);
	}
}

int count;

//a는 가능 다리오, b는 오는 다리오
void f(int k,int a, int b)
{
	  printf("k:%d a:%d b:%d\n",k,a,b);

      //마지막 후퍼섬을 제외하고
	  if(k==n-2)
	  {
		 if(
		  island[a].loc + island[a].jump >= island[n-1].loc &&
          island[b].loc >= island[n-1].loc - island[n-1].jump)
		 {
		  printf("base k:%d a:%d b:%d\n",k,a,b);
		  count++;
		 }
	      return;
	  }

	
    if(island[a].loc + island[a].jump >= island[k+1].loc) // 가능할때 가는 다리오가 선택가능
	f(k+1,k+1,b);  // 이부분 헷갈렸다.!!! 뭘 옮기는지 잘 봐라.!

	if((island[b].loc >= island[k+1].loc - island[k+1].jump) && island[k+1].type!=0) // 가능할때 오는 다리오가 선택가능
	f(k+1,a,k+1);

	
    f(k+1,a,b);  // 그냥 건너뜀
	
}



void main()
{
input();

f(0,0,0);
printf("%d",count);
}



//DT 테이블 버젼 

#include<stdio.h>

struct ISLAND
{
	int loc;
	int jump;
	int type;
};

ISLAND island[20];
int n;

int mod=1000;

int check[20];
int DT[21][21][21];

void input()
{
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",&island[i].loc,&island[i].jump,&island[i].type);
	}
}

int count;
int func_call;

//a는 가는 다리오, b는 오는 다리오의 섬의 인덱스 위치!
int f(int k,int a, int b)
{
	 // printf("%d %d %d\n",k,a,b);

	  if(DT[k][a][b]!=-1) return DT[k][a][b];

	  func_call++;

      //마지막 후퍼섬을 제외하고
	  if(k==n-2)
	  {
		 if(
		  island[a].loc + island[a].jump >= island[n-1].loc &&
          island[b].loc >= island[n-1].loc - island[n-1].jump)
		 {
			return DT[k][a][b]=1%mod;
		 }
	      return DT[k][a][b]=0%mod;
	  }

	int first=0;
	int second=0;
	int third=0;

    if(island[a].loc + island[a].jump >= island[k+1].loc) // 가능할때 가는 다리오가 선택가능
	first=f(k+1,k+1,b)%mod;

	if((island[b].loc >= island[k+1].loc - island[k+1].jump) && island[k+1].type!=0) // 가능할때 오는 다리오가 선택가능
	 second=f(k+1,a,k+1)%mod;

	
    third=f(k+1,a,b)%mod;  // 그냥 건너뜀

	return DT[k][a][b]=(first+second+third)%mod;
	
}



void main()
{
input();

for(int i=0;i<20;i++)
for(int j=0;j<20;j++)
for(int k=0;k<20;k++)
	DT[i][j][k]=-1;

printf("%d\n",f(0,0,0)%mod);
printf("func_call:%d\n",func_call);
}














//아랜 그냥 참조만 하도록
////////////////////////////////////////////////////////////////////////////////////
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++






































//이전 풀이는 단방향 백트래킹 소스가 복잡하다.
//아래껀 그냥 참조만 하도록 
////////////////

////
// 최종풀이  -> 교재 창훈 그림 참조
// 교재 방법도 알아 놓도록한다.
///////////////////////

#include<stdio.h>

int n;
int loc_arr[20];
int jump_arr[20];
int type_arr[20];

int checked[20];

int count;

// solve(진행방향,섬의위치)
void solve(int dir,int island) 
{	
	printf("dir : %d , island:%d \n",dir,island);

	if(island==(n-1) && dir==0)  // 후퍼섬에서 방향이 순->역
	{
        dir=1;
	}

/*	// 이게 필요가 없다는 이유를 증명해라!! // 백트래킹시 자연스렵게 방향이 바뀐다.
	if(island==(n-1) && dir==1)  // 후퍼섬에서 방향이 역->순
	{
        dir=0;
	}
*/

	if(dir==1 && island==0)
	{
		count++;
		return;
	}

	if(dir==0) //순방향
	{
		int max_location=loc_arr[island]+jump_arr[island];
		for(int i=island+1;i<n;i++) //유시섬에서~후퍼섬까지
		{
			if(checked[i]==0 &&
			   loc_arr[i]<=max_location
			   //type_arr 상관없음.
			   )
			{
				checked[i]=1;
				solve(0,i); 
				checked[i]=0;
			}
		}
	}
	else  //역방향
	{
		int max_location=loc_arr[island]-jump_arr[island];
		for(int i=island-1;i>=0;i--) // 후퍼섬에서~유시섬까지
		{
			if(checked[i]==0 &&
			   loc_arr[i]>=max_location &&
			   type_arr[i]==1 //역방향일땐 1인거만 밟을 수 있다.
			   )
			{
				checked[i]=1;
				solve(1,i); 
				checked[i]=0;
			}
		}
	}
}

void main()
{
  freopen("input.txt","r",stdin);
  scanf("%d",&n);
  
  for(int i=0;i<n;i++)
  {
	  scanf("%d",&loc_arr[i]);
	  scanf("%d",&jump_arr[i]);
	  scanf("%d",&type_arr[i]);
  }

  solve(0,0); // 현재 방향은 순방향, 현재 위치는 0
 
  printf("count:%d",count);
}




//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// 이전에 너무 복잡하게 풀었다.!!!  이걸 보지 말도록!!
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#include<stdio.h>

int n;

struct island
{
 int dist;
 int jump;
 int toward;
};

island is[31];     // 1번섬 유시섬 , 마지막 섬 후퍼섬  
int checked[31];   // 1번섬 유시섬 , 마지막 섬 후퍼섬  

int solution;
static int func_count;


//섬 번호  , 방향 
void f(int l , int t)  
{

	printf("Island Locaiotn:%d , toward:%d\n", l,t);

	if(l==n) // 후퍼섬에 도착했다면  방향 토글 준비
	{	 
		printf("hopper! \n");
		if (t==0){ t=1; checked[1]=1;}  // 역방향에서 순방향으로  돌아 왔기 때문에 유시섬을 닫음 
		else     { t=0; checked[1]=0;}  // 순방향에서 역방향 으로  유시섬을 갈 수 있도록 열어둠
	}

	if(l==1 && t ==0)
	{
		printf("compte!! : %d \n",solution);
		solution++;
		return;
	}

	int position = is[l].dist;
	   
	int backward = position - is[l].jump; // 여기 값은 좌표계 좌표값이다 
	int forward  = position + is[l].jump;
	
	if(backward<=0) 	backward=0;// 음으로 갈수 없다. // 여기 값은 좌표계 좌표값이다 
   		
	for(int i=1; i <= n ; i++ )
	{
		if(checked[i]==0)  // 방문한 섬 빼고
		{
			 if(t==0) // 역방향일때 
			 {
				 if( backward <= is[i].dist && is[i].dist < is[l].dist)  // 현재 위치에서 앞으로는 가지마라. , 한 방향만 이동함으로 
				 {				
					 if(is[i].toward==1)   // 역방향일때 1만 밟을수 있다.
					 {
					   checked[i]=1; 
					   f(i ,t); 
					   checked[i]=0;
					 }
				 }				 
			 }
			 else // 순방향일때  아무꺼나 상관 없이 밟을수있다. 
			 {
				 
				 if(is[i].dist <= forward  && is[i].dist > is[l].dist)  // 현재 위치에서 뒤로는 가지마라 . . , 한 방향만 이동함으로 
				 {					 
					 checked[i]=1; 
					 f(i ,t); 
					 checked[i]=0;
				 }
			 }

		
		}
	}
	
	
}


void main()
{

freopen("input.txt","r",stdin);
//freopen("output_princess_saving.txt","w",stdout);

scanf("%d",&n);

for(int i=1; i<=n ; i++)
{
	scanf("%d %d %d", &is[i].dist,&is[i].jump, &is[i].toward);
}

checked[1]=1;
f(1,1);  // 유시섬에서 시작 , 방향은 순방향으로 

printf("%d \n" , solution);

}



// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// 교재대로 풀기 No return 값 버젼 
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#include<stdio.h>

char distance[20];
char jump[20];
char kind[20];
int cnt;
int n;

//순방향 
int canA(int a, int k)
{
 
 //현재 위치에서 점프해서 , K 섬이 인바운드 안에 있나?
 if(  distance[k] <= jump[a]+distance[a]   )
 {
	 return 1;
 }	 
 
 return 0;
 
}

/*
//역방향일경우다 조심해라.
//실제는 이게 역방향이다.

보이긴  아래와 같지만
b   ->  K

실제론 아래이다.
b  <-  k   

distance[b] >= distance[K] - jump[K]
->
distance[k] <= distance[b] + jump[K]
*/

int canB(int b, int k)
{
 
 if(  distance[k] <=  distance[b] +jump[k] )
 {
	 if(kind[k]==0) return 0;   
	 return 1;
 }	 
 
 return 0;
 
}

void solve(int a, int b, int k)
{
	
	if(k==n-1) // 
	{
		if( canA(a,k) && canB(b,k) )	cnt++;  // 두 다리오가 마지막 섬을 같이 도달한다면 이것이 해이다.
		return;
	}
	
	if(canA(a,k)) solve(k,b,k+1);
	if(canB(b,k)) solve(a,k,k+1);
	solve(a,b,k+1);
}


void main()
{

freopen("input.txt","r",stdin);

scanf("%d",&n);

for(int i=0; i < n ; i++)
scanf("%d %d %d",&distance[i] ,&jump[i] ,&kind[i]);


//현재 위치, 방향

solve(0,0,1);

printf("%d",cnt);

}


////////////////
// 교재 풀이 
////////////////

#include <stdio.h>
int n, m=1000;
int p[500],d[500],g[500];
bool ca(int a, int k)
{
return p[k]<=p[a]+d[a];
}
bool cb(int b, int k)
{
return (p[k]<=p[b]+d[k])&&g[k];
}
int f(int a, int b, int k)
{
int c=0;
if(k==n-1)
{
if(ca(a,k)&&cb(b,k)) c=1;
else c=0;
}
else
{
if(ca(a,k)) c+=f(k,b,k+1)%m;
if(cb(b,k)) c+=f(a,k,k+1)%m;
c+=f(a,b,k+1)%m;
}
return c;
}
int main()
{
freopen("input.txt","r",stdin);
scanf("%d", &n);
for(int i=0; i<n; i++)
scanf("%d %d %d", &p[i], &d[i], &g[i]);
printf("%d\n", f(0,0,1));
return 0;
}


////////////////
// 교재 풀이 DP

//DT[a][b]= “가는 다리오는 a 위치의 섬에, 오는 다리오가 ?b 위치의 섬이라고 있을 수 있는 모든 경우의 수”
->6
8  
0 7 1
3 4 1
6 8 1
8 6 1
12 2 0
13 2 1
14 2 1
15 7 1

/*
  1  1  2  3  0  0  0  3
  1  0  1  1  0  0  0  1
  2  1  0  1  0  0  0  1
  2  1  0  0  0  0  0  0
  4  2  0  1  0  0  0  1
  8  4  0  2  0  0  0  2
 16  8  0  4  0  0  0  4
 24 12  0  6  0  0  0  6
6

*/
////////////////

#include <cstdio>
#define MOD 1000
int n, D[501], S[501], A[501], DT[501][501];

void display()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("  %d",DT[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output_save_princess.txt","w",stdout);
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	scanf("%d %d %d", D+i, S+i, A+i);


	for(int i=0; i<n; i++)  // 가는 다리오 증가 
	{
		for(int j=0; j<n; j++) // 오는 다리오 증가 
		{
			if(i==0 && j==0) DT[i][j]=1; // 유시섬에서 시작하고 끝나야 함. 가는 다리오, 오는 다리오는 한가지임.
			else if(i!=j || (i==n-1 && j==n-1) ) //  가는 다리오 / 오는 다리오는 같은 위치에 있을 수 없다. 그러나  마지막 섬에선 후퍼섬에는 두 다리오는  같이 있다. 
				{
					if(i>j)  //가는 다리오 
					{
						for(int k=0; k<i; k++)  // k~i까지의 값들을 모두 더함 교재 그림 참조 
						if(D[k]+S[k]>=D[i]) DT[i][j]+=DT[k][j];
					}
					else if(A[j]) // 오는 다리오는 A[j]가 1일때만 가능함. // k~i까지의 값들을 모두 더함 교재 그림 참조 
					{
						for(int k=0; k<j; k++)
						if(D[k]+S[j]>=D[j]) DT[i][j]+=DT[i][k];
					}
				}
				
			DT[i][j] %=MOD;
		}
	}
	
	display();
	
printf("%d\n", DT[n-1][n-1]);
return 0;
}

//////////////////////
// 위의 알고리즘을 이해할려면 틀을 알아야한다.  어떤 틀인지는 아래를 참조한다.
//////////////////////
//결과 
  0  2  2  2  2
  1  0  2  2  2
  1  1  0  2  2
  1  1  1  0  2
  1  1  1  1  2
  
////////////////


int DT[5][5];

int main()
{
	int n=5;

	freopen("outddddput.txt","w",stdout);

	for(int i=0; i<n; i++)  // 가는 다리오 증가 
	{
		for(int j=0; j<n; j++) // 오는 다리오 증가 
		{
			if(i!=j || (i==n-1 && j==n-1) )
			{
					if(i>j)  //가는 다리오 
					{
						DT[i][j]=1;
						printf("go : i :%d , j:%d \n" ,i,j);
					}
					else 
					{
						DT[i][j]=2;
						printf("come : i :%d , j:%d \n" ,i,j);
					}
			}
		}
	}


	for(int i=0; i<n; i++)  // 가는 다리오 증가 
	{
		for(int j=0; j<n; j++) // 오는 다리오 증가 
		{
			printf("  %d",DT[i][j]);
		}
		printf("\n");
	}
  
}
  
  













////////////////////////////////////////


/*

->6
8  
0 7 1
3 4 1
6 8 1
8 6 1
12 2 0
13 2 1
14 2 1
15 7 1

-> 0
7  
0 7 1
3 4 1
6 8 1
8 6 1
12 2 0
13 2 1
14 2 1

-> 0
6  
0 7 1
3 4 1
6 8 1
8 6 1
12 2 0
13 2 1



-> 0
5
0 7 1
3 4 1
6 8 1
8 6 1
12 2 0


-> 1
4
0 7 1
3 4 1
6 8 1
8 6 1



->  3
3
0 7 1
3 4 1
6 8 1


-> 0
15 
0 7 1
3 4 1
6 8 1
8 6 1
12 2 0
13 2 1
14 2 1
15 7 1
16 2 1
17 2 1
18 2 0
22 6 1
24 8 1
27 4 1
30 7 1


->18
11
0 7 1
3 4 1
6 8 1
8 6 1
12 2 0
13 2 1
14 2 1
15 7 0
16 9 1
17 5 1
18 9 1

*/

#include<stdio.h>

int n;

struct island
{
 int dist;
 int jump;
 int toward;
};

island is[31];     // 1번섬 유시섬 , 마지막 섬 후퍼섬  
int checked[31];   // 1번섬 유시섬 , 마지막 섬 후퍼섬  

int solution;
static int func_count;


//섬 번호  , 방향 
void f(int l , int t)  
{

	printf("Island Locaiotn:%d , toward:%d\n", l,t);

	if(l==n) // 후퍼섬에 도착했다면  방향 토글 준비
	{	 
		printf("hopper! \n");
		if (t==0){ t=1; checked[1]=1;}  // 역방향에서 순방향으로  돌아 왔기 때문에 유시섬을 닫음 
		else     { t=0; checked[1]=0;}  // 순방향에서 역방향 으로  유시섬을 갈 수 있도록 열어둠
	}

	if(l==1 && t ==0)
	{
		printf("compte!! : %d \n",solution);
		solution++;
		return;
	}

	int position = is[l].dist;
	   
	int backward = position - is[l].jump; // 여기 값은 좌표계 좌표값이다 
	int forward  = position + is[l].jump;
	
	if(backward<=0) 	backward=0;// 음으로 갈수 없다. // 여기 값은 좌표계 좌표값이다 
   		
	for(int i=1; i <= n ; i++ )
	{
		if(checked[i]==0)  // 방문한 섬 빼고
		{
			 if(t==0) // 역방향일때 
			 {
				 if( backward <= is[i].dist && is[i].dist < is[l].dist)  // 현재 위치에서 앞으로는 가지마라.
				 {				
					 if(is[i].toward==1)   // 역방향일때 1만 밟을수 있다.
					 {
					   checked[i]=1; 
					   f(i ,t); 
					   checked[i]=0;
					 }
				 }				 
			 }
			 else // 순방향일때  아무꺼나 상관 없이 밟을수있다. 
			 {
				 
				 if(is[i].dist <= forward  && is[i].dist > is[l].dist)  // 현재 위치에서 뒤로는 가지마라 .
				 {					 
					 checked[i]=1; 
					 f(i ,t); 
					 checked[i]=0;
				 }
			 }

		
		}
	}
	
	
}


void main()
{

freopen("input.txt","r",stdin);
//freopen("output_princess_saving.txt","w",stdout);

scanf("%d",&n);

for(int i=1; i<=n ; i++)
{
	scanf("%d %d %d", &is[i].dist,&is[i].jump, &is[i].toward);
}

checked[1]=1;
f(1,1);  // 유시섬에서 시작 , 방향은 순방향으로 

printf("%d \n" , solution);

}



// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// 교재대로 풀기 No return 값 버젼 
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#include<stdio.h>

char distance[20];
char jump[20];
char kind[20];
int cnt;
int n;

//순방향 
int canA(int a, int k)
{
 
 //현재 위치에서 점프해서 , K 섬이 인바운드 안에 있나?
 if(  distance[k] <= jump[a]+distance[a]   )
 {
	 return 1;
 }	 
 
 return 0;
 
}

/*
//역방향일경우다 조심해라.
//실제는 이게 역방향이다.

보이긴  아래와 같지만
b   ->  K

실제론 아래이다.
b  <-  k   

distance[b] >= distance[K] - jump[K]
->
distance[k] <= distance[b] + jump[K]
*/

int canB(int b, int k)
{
 
 if(  distance[k] <=  distance[b] +jump[k] )
 {
	 if(kind[k]==0) return 0;   
	 return 1;
 }	 
 
 return 0;
 
}

void solve(int a, int b, int k)
{
	
	if(k==n-1) // 한단계 이전 단계에서 
	{
		if( canA(a,k) && canB(b,k) )	cnt++;  // 두 다리오가 마지막 섬을 같이 도달한다면 이것이 해이다.
		return;
	}
	
	if(canA(a,k)) solve(k,b,k+1);
	if(canB(b,k)) solve(a,k,k+1);
	solve(a,b,k+1);
}


void main()
{

freopen("input.txt","r",stdin);

scanf("%d",&n);

for(int i=0; i < n ; i++)
scanf("%d %d %d",&distance[i] ,&jump[i] ,&kind[i]);


//현재 위치, 방향

solve(0,0,1);

printf("%d",cnt);

}


////////////////
// 교재 풀이 
////////////////

#include <stdio.h>
int n, m=1000;
int p[500],d[500],g[500];
bool ca(int a, int k)
{
return p[k]<=p[a]+d[a];
}
bool cb(int b, int k)
{
return (p[k]<=p[b]+d[k])&&g[k];
}
int f(int a, int b, int k)
{
int c=0;
if(k==n-1)
{
if(ca(a,k)&&cb(b,k)) c=1;
else c=0;
}
else
{
if(ca(a,k)) c+=f(k,b,k+1)%m;
if(cb(b,k)) c+=f(a,k,k+1)%m;
c+=f(a,b,k+1)%m;
}
return c;
}
int main()
{
freopen("input.txt","r",stdin);
scanf("%d", &n);
for(int i=0; i<n; i++)
scanf("%d %d %d", &p[i], &d[i], &g[i]);
printf("%d\n", f(0,0,1));
return 0;
}


////////////////
// 교재 풀이 DP

//DT[a][b]= “가는 다리오는 a 위치의 섬에, 오는 다리오가 ?b 위치의 섬이라고 있을 수 있는 모든 경우의 수”
->6
8  
0 7 1
3 4 1
6 8 1
8 6 1
12 2 0
13 2 1
14 2 1
15 7 1

/*
  1  1  2  3  0  0  0  3
  1  0  1  1  0  0  0  1
  2  1  0  1  0  0  0  1
  2  1  0  0  0  0  0  0
  4  2  0  1  0  0  0  1
  8  4  0  2  0  0  0  2
 16  8  0  4  0  0  0  4
 24 12  0  6  0  0  0  6
6

*/
////////////////

#include <cstdio>
#define MOD 1000
int n, D[501], S[501], A[501], DT[501][501];

void display()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("  %d",DT[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output_save_princess.txt","w",stdout);
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	scanf("%d %d %d", D+i, S+i, A+i);


	for(int i=0; i<n; i++)  // 가는 다리오 증가 
	{
		for(int j=0; j<n; j++) // 오는 다리오 증가 
		{
			if(i==0 && j==0) DT[i][j]=1; // 유시섬에서 시작하고 끝나야 함. 가는 다리오, 오는 다리오는 한가지임.
			else if(i!=j || (i==n-1 && j==n-1) ) //  가는 다리오 / 오는 다리오는 같은 위치에 있을 수 없다. 그러나  마지막 섬에선 후퍼섬에는 두 다리오는  같이 있다. 
				{
					if(i>j)  //가는 다리오 
					{
						for(int k=0; k<i; k++)  // k~i까지의 값들을 모두 더함 교재 그림 참조 
						if(D[k]+S[k]>=D[i]) DT[i][j]+=DT[k][j];
					}
					else if(A[j]) // 오는 다리오는 A[j]가 1일때만 가능함. // k~i까지의 값들을 모두 더함 교재 그림 참조 
					{
						for(int k=0; k<j; k++)
						if(D[k]+S[j]>=D[j]) DT[i][j]+=DT[i][k];
					}
				}
				
			DT[i][j] %=MOD;
		}
	}
	
	display();
	
printf("%d\n", DT[n-1][n-1]);
return 0;
}

//////////////////////
// 위의 알고리즘을 이해할려면 틀을 알아야한다.  어떤 틀인지는 아래를 참조한다.
//////////////////////
//결과 
  0  2  2  2  2
  1  0  2  2  2
  1  1  0  2  2
  1  1  1  0  2
  1  1  1  1  2
  
////////////////


int DT[5][5];

int main()
{
	int n=5;

	freopen("outddddput.txt","w",stdout);

	for(int i=0; i<n; i++)  // 가는 다리오 증가 
	{
		for(int j=0; j<n; j++) // 오는 다리오 증가 
		{
			if(i!=j || (i==n-1 && j==n-1) )
			{
					if(i>j)  //가는 다리오 
					{
						DT[i][j]=1;
						printf("go : i :%d , j:%d \n" ,i,j);
					}
					else 
					{
						DT[i][j]=2;
						printf("come : i :%d , j:%d \n" ,i,j);
					}
			}
		}
	}


	for(int i=0; i<n; i++)  // 가는 다리오 증가 
	{
		for(int j=0; j<n; j++) // 오는 다리오 증가 
		{
			printf("  %d",DT[i][j]);
		}
		printf("\n");
	}
  
}
  
  


