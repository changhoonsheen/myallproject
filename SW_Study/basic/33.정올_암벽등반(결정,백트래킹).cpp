//창훈 필기 최종!!
//노트 보도록 

#include<stdio.h>

int N;
int dx[4]={-1,0,1 ,0};
int dy[4]={ 0,1,0,-1};

int map[500][500];
int chk[500][500];

int abs(int a)
{
	return a < 0 ? a*(-1) : a;
}

int getAltitude(int a, int b)
{
	return abs(a-b);
}

//반드시 이런류의 문제는 Return 값 버젼으로 풀어본다.
//정말 엄청난 실수가 일어 난다.!!! 전역변수를 사용하게 되면 꼬일 수 있다.

int Doclimb(int x, int y, int H)
{
	int sum=0;
	
	for(int i=0;i<4;i++)
	{
		int new_x=x+dx[i];
		int new_y=y+dy[i];
		
		if( chk[new_x][new_y]==0 &&
		    getAltitude(map[x][y],map[new_x][new_y])<=H &&
		    ( new_x < N && new_y < N ) &&
			( new_x >=0 && new_y >=0 )
		  )
		  {
			chk[new_x][new_y]=1; // 
			sum=sum+Doclimb(new_x,new_y,H)+1;  // 바닥에서 올라면서 더해간다.			
		  }
	}
	
	return sum;
}

int CanClimb(int H)
{
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			for(int x=0;x<N;x++)
			for(int y=0;y<N;y++)
			chk[x][y]=0;
		
			chk[i][j]=1;               //여기 체크해두고
		    int area=Doclimb(i,j,H)+1; //마지막에 올라 올때 자기자신꺼 더해준다.
			
			if(area >= (int) N*N*3/4) return 1; //정복함.
		}
	return 0;	//정복 못함.
}


void input()
{
	freopen("input.txt","r",stdin);
	
	scanf("%d",&N);
	
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	scanf("%d",&map[i][j]);		
}

void main()
{
	input();
	
	int lb=0;
	int ub=1000000;
	
#if 0  //테스트
	printf("%d",CanClimb(3));
#else
	while(lb<ub)
	{
		int m=(lb+ub-1)/2;
		if(CanClimb(m)) ub=m;
		else lb=m+1;
	}
	
	printf("%d",ub);
#endif
}






//++++++++++++++++++++++++++++++++++++++++++++++++++++++
///////////////////////////////////////////////////////////

/*
처음 보는 유형이라서 잘 이해가 안된다.  꼽싶어서 보도록. 


임금이 생각하는 상금을 맞추는 문제  임금은 내가 말하는 것 보다 적을때 상금을 준다.
임금이 생각하는 돈을 총 몇 번 임금에게 물어서 맞출 수 있을까?

*/



5 
9 9 9 3 3 
0 0 0 0 3 
0 9 9 3 3 
0 0 0 3 3 
9 0 0 9 3


//창훈 최종 잘 풀었다.
//잘 기억했고, 다음에 연습삼아서 또 풀어 보자.

#include <cstdio>

int N;

int map[500][500];
int chk[500][500];

//맵을 돌아 다릴 땐 항상 이 방식을 사용해야된다.
int dx[]={-1, 0, 1, 0};
int dy[]={ 0, 1, 0,-1};

int abs(int a)
{
	return a<0 ? a*(-1) : a;
}

int getDiff(int a, int b)
{
	return abs( a - b);	
}

int max(int a, int b)
{

	return a > b ? a : b;
}

// 이 함수는 반환값 버젼
// 전역변수 버젼으로 만들수있다.
int solve(int i, int j, int h)
{
	    int a=0;
		for(int k=0;k<4;k++)
		{
			int new_i=i+dx[k];  //여기 실수 
			int new_j=j+dy[k];

           if( new_i < N && new_j < N && new_i >=0 && new_j >=0 ) 
		   {
			    int d=getDiff( map[i][j] , map[new_i][new_j]);
				if( d <= h && !chk[new_i][new_j])
				{
					chk[new_i][new_j]=1;
					a=a+solve(new_i, new_j, h)+1;
				}			
		   }
		}			
		return a;
}

int f(int h) 
{  
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	{		
	    for(int x=0;x<N;x++)
		for(int y=0;y<N;y++)
			chk[x][y]=0;
		
		int area=0;
		chk[i][j]=1;
		
		//printf("i:%d,j:%d ",i,j);		
		area=solve(i,j,h)+1;
		//printf("- area:%d\n",area);
		
		if(area >= (int)N*N*3/4) return 1;
	}

	return 0;
}


int main() {  

	int lb,ub,m;
	lb=0;
	ub=0;
	//ub=1000000; // ub는 지도의 최대 높이로 하면된다.

	freopen("input.txt","r",stdin);
	
	scanf("%d",&N);

	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	{
		scanf("%d",&map[i][j]);
		ub=max(ub,map[i][j]);
	}


	while(lb<ub)
	{
		m = (lb+ub-1)/2;

		if(f(m)) ub=m;
		else lb=m+1;
	}

	printf("result : %d\n" , ub);

    return 0; 
}









////////////////////////////////////////////////////////////


#include<stdio.h>
#define SOL 81  // 임금이 생각 하는 돈 


int f(int x)
{
 //return (SOL >= x) ;
   return (x <= SOL) ;
}



int main()
{
//	freopen("output.txt","w",stdout);


int lb=0,ub=100 , m;

while(lb < ub) // 하한값 이 상한을 넘어 설때 종료함.
{
  m =(lb + ub -1 ) /2;  // 결정 문제의 정의가 결정 되면 -1 
  if(f(m)) ub =m;  // 교재 참조. 논리적으로 합당한지 생각한다.
  else lb=m+1; // 결정 문제의 정의가 결정 되면 +1
  
  printf("lb:%d m:%d ub:%d\n",lb,m,ub);
}
 printf("%d\n",ub);

}

////////////
//암벽등반 문제 
////////////

////////////
//창훈품
////////////

#include<stdio.h>

int n;

int map[500][500];
int checked[500][500];

int dx[4]={-1,0,1, 0};
int dy[4]={ 0,1,0,-1};


int can(int x, int y)
{
 return (0<=x && x<n ) && (0<=y && y<n) ;
}

int abs(int a)
{
 return a < 0 ? (-1)* a : a;
}


int getArea(int x ,int y, int h)
{
  checked[x][y]=1; // 처음 떨어진 장소 
  int area=1;  // 처음 떨어진 장소도 하나 카운트 

  for(int i=0;i<4;i++)
  {
      if(
	   checked[x+dx[i]][y+dy[i]]==0 &&
	   can(x+dx[i],y+dy[i]) &&
	   h >=abs(map[x+dx[i]][y+dy[i]]-map[x][y])
	   )
	   {
		   checked[x+dx[i]][y+dy[i]]=1;
		   area+=getArea(x+dx[i],y+dy[i],h);  // 여러 갈래에서 오는 값들이 있을껀데 이걸 		                                      
		                                      // 누적을 해야지!!! 틀렸다. 못해서 전역으로 했다. 
	  }
  }
 
  return area;  // area를 전역을 뺄수도 있지만 이걸 분석하자.
}

void clearhistory()
{
 for(int i=0; i<n;i++)  
 for(int j=0; j<n;j++)
 {
  checked[i][j]=0;
 }
}

//정올이가 int 
int f(int h)
{

 int current_area=0;
 int cond = (n * n) * 3/4;  /// 여기 주의 해야한다. !!! 잘못하면 0이 나온다

 
 for(int i=0; i<n;i++)  // 임의 모든 위치에서 출발 시키기 
 for(int j=0; j<n;j++)
 {
     clearhistory();
     current_area=getArea(i,j,h);
//	 printf("start: i:%d , j:%d  current area :%d\n", i, j ,current_area);

	if(cond <= current_area)  return 1;
 }

	return 0;
}


int ub=-987654321;
int lb;

void main()
{
		
 freopen("input.txt","r",stdin);

 scanf("%d",&n);
 
 for(int i=0; i< n ; i++)
 for(int j=0; j< n ; j++)
 {
  scanf("%d",&map[i][j]);
  if(ub<=map[i][j]) ub=map[i][j];
 }

/*
  //test;
  for(i=0; i<=9;i++)
  {
   printf("health %d  pass: %d \n",i, f(i));
  }
*/


while(lb<ub)
{
 int m = (ub+lb-1)/2;
 if(f(m)) ub=m;  // 이게 결정되면 , 아래 위 +1, -1을 정할수 있음 
 else lb=m+1 ;
}
 
printf("%d",ub);

}


