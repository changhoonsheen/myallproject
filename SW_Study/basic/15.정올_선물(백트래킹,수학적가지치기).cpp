

//창훈 최종필기
//제약조건에서 최소값중에 다시 최소값을 찾는 부분은 잘 생각해보자
//이 부분 모호했다. 필기 노트를 보자.


//1.Backtracking 

#include<stdio.h>

int N;
int arr[10];
int min_d=987654321;

int result_a;
int result_b;
int result_c;

int func_call;

int sum;

void f(int i, int a, int b, int c)
{
	
	//1.원 그려보기
	if(sum/3 < c || sum/2 < b) return;
	
	//2.투표 생각하기 
	int rest = sum - (a+b+c);
	if( b > rest+a || c > rest+b) return;
	
	//3.diff 조건 
	if( a - (c+rest) > min_d ) return;

	func_call++;


	if(i==N)
	{
		if(a>=b && b>=c)
		{

			int d=a-c;
			if(min_d>=d)// 같은 d가 있을때도.
			{
				if(min_d==d)
				{
					if(result_a > a)
					{
						result_a=a;
					    result_b=b;
					    result_c=c;
					}
				}
				else
				{
					min_d=d;
					result_a=a;
					result_b=b;
					result_c=c;
				}
	
			}
		}

		return;
	}

	f(i+1,a+arr[i],b,c);
	f(i+1,a,b+arr[i],c);
	f(i+1,a,b,c+arr[i]);
}

void main()
{
	freopen("input.txt","r",stdin);
	scanf("%d",&N);

	for(int i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}

	f(0,0,0,0);

	printf("func_call:%d\n",func_call);
	printf("%d %d %d",result_a,result_b,result_c);
}




//상향식 DP로 풀어 보기
#include<stdio.h>

int n;
int present[20];

int real_first=987654321;
int real_second;
int real_third;

int min_diff=987654321;
int sum;
int func_call;

//정의역의 크기는 조금더 생각해보자.
//SUM까지하면안되는가?
int DT[20][2000][2000];

int bound = 2000/3+1; // 이 부분 더 생각해보자. sum까지 돌면 안되나?
                   // 안된다.!! 20개의 item이 100이라고 생각해보자.비효율적이다.
                   // 논리적으로 합당하지 못하다. 
void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&present[i]);
		sum+=present[i];
	}
}

//마지막 DT 테이블이 만들어진 2x2배열을 확인해보자.
void printMatrix(int n)
{
		for(int j=0;j<=bound;j++)
		{
			for(int k=0;k<=bound;k++)
			{
				printf(" %d",DT[n][j][k]);
			}
			printf("\n");
		}

}

void solve()
{

	DT[0][0][0]=1;
	//마지막 Item n 배열에 나올수 있는 모든 수의 조합이 저장되었다.
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=bound;j++)
		{
			for(int k=0;k<=bound;k++)
			{
				if(DT[i-1][j][k])
				{
					DT[i][j][k]=DT[i-1][j][k];
					DT[i][j+present[i]][k]=1;
					DT[i][j][k+present[i]]=1;
				}
			}
		}
	}

	int count=1; //해의 집합의 갯수 3개 갈래가 존재하고 n개의 아이템이 있음으로 3^n 이다.
	for(int j=0;j<=bound;j++)
	{
		for(int k=0;k<=bound;k++)
		{
			if(DT[n][j][k])
			{
				int first= sum-(j+k) ;
				int second=j;
				int third=k;

				//printf("%d - first : %d , second:%d , third:%d\n",count++,first,second,third);

				if(first >= second && second >= third)
				{
					int diff=first-third; //실수!!! 미쳤니??? first-second가 뭐니?
					if(min_diff >= diff)
					{
						if(min_diff!=diff) real_first=987654321;
						min_diff=diff;

						if(real_first > first)
						{
							real_first=first;
							real_second=second;
							real_third=third;  //실수 == 라고 계산함.
						}
					}

				}
			}
		}
	}

}


void main()
{
	input();
	solve();
	//printMatrix(n);

   printf("%d %d %d\n",real_first,real_second,real_third);
	
}








































//이 아랜 보지 말도록
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// 창훈 전체 검색으로 문제 해결   // 강의 있음 

/*


순수 전체탐색 알고리즘
6
6 4 4 4 6 9
->
12 12 9
fun_call 1093


3
2 10 1
fun_call 40


9
1 1 1 4 6 1 1 1 1
6 6 5
fun_call 29524


18
1 1 1 4 6 1 1 1 1 1 1 1 4 6 1 1 1 1
12 11 11


18
10 1 1 40 60 10 10 51 41 21 31 11 40 60 15 12 10 100 
175 175 174

입력
1. 첫 줄에 선물의 개수를 나타내는 정수 n이 입력된다. (3≤n≤20)
2. 다음 줄에 선물의 부피를 나타내는 n개의 정수가 공백으로 분리되어 입력된다.
3. 선물의 부피는 0보다 크고 100보다 작다
출력
1. 길동 3남매가 가지게 될 선물의 합계 부피를 출력한다.
2. 길동, 길순, 길삼의 순으로 3개의 정수를 하나의 공백으로 분리하여 출력한다
*/
////////////////////////////////////////////


//창훈 최종
//1. backtracking 가지치기 조건들을 다시한번 생각해보자. DT 방식이 생각 안나면 이렇게라도 풀어야한다.
       

#include<stdio.h>

int n; // map 크기 
int gift[100];

int sol_a;
int sol_b;
int sol_c;

int d=987654321;
int sum;

int func_count;

void f(int a,int b,int c,int i)
{
	//1 교재참고
	if(c > sum/3) return; //2배 개선  , 내가 발견한 조건.
	if(b > sum/2) return; //이건 못찾았다. 책 그림을 보자.
	
	//2 교재참고
	int rest = sum - (a+b+c); 
	if( b > a + rest) return;
	if( c > b + rest) return;
	

	func_count++;

	if(i==n)
	{
		//똑같이 배분하는게 목표지만, 똑같이 안나눠질때 길동,길순,길삼 순으로 나눈다.
		if(a>=b && b>=c)
		{
			int new_d=a-c;
			if( d >= new_d) //그런데 diff 차가 제일 작은걸 찾지만 똑같을때가 존재한다.
			{
				if(d==new_d) //최소 diff가 현재 diff하고 같을때는 a값이 기존 해의 a값 보다 작다면 이를 갱신한다.
				{
					if(sol_a > a)
					{
						sol_a=a;
						sol_b=b;
						sol_c=c;
					}
				}
				else  // 일반적인 경우는 계속 해를 조건에 맞는 해를 갱신한다.
				{
					d=new_d;
					sol_a=a;
					sol_b=b;
					sol_c=c;
				}

			}

		}
			return;
	}

	f(a+gift[i],b,c,i+1);
	f(a,b+gift[i],c,i+1);
	f(a,b,c+gift[i],i+1);
}


void main()
{

freopen("input.txt","r",stdin);
scanf("%d",&n);

for(int i=0;i<n;i++)
{
	scanf("%d",&gift[i]);
	sum+=gift[i];
}

f(0,0,0,0);

printf("%d %d %d\n",sol_a,sol_b,sol_c);
printf("func_count:%d\n", func_count);

}

/////////////////////////
//DP로 풀이 :20개 이상의 선물 계산 가능
//해석은 교재에서 내가 정리한 부분 참고


#include<stdio.h>

int n;
int gift[20];
int DT[20][2000][2000];
int sum;

void main()
{
freopen("input.txt","r",stdin);
scanf("%d",&n);

DT[0][0][0]=1;

for(int i=1;i<=n;i++)
{
	scanf("%d",&gift[i]);
	sum+=gift[i];
}

int bound=2000/3;

for(int i=1;i<=n;i++)
	for(int b=0;b<=bound;b++)
		for(int c=0;c<=bound;c++)
		{
			if(DT[i-1][b][c])
			{
			  DT[i][b][c]=1;
			  DT[i][b+gift[i]][c]=1;
			  DT[i][b][c+gift[i]]=1;
			}
		}

//마지막 n번째 배열에 모든 a,b,c가 가질수 있는 부피의 경우의 수를 알 수가 있다.
	
	int diff=987654321;
	int solve_a;
	int solve_b;
	int solve_c;
	
	for(int b=0;b<=bound;b++)
		for(int c=0;c<=bound;c++)
		{
			if(DT[n][b][c])
			{
				int real_a = sum - (b+c);
				int real_b = b;
				int real_c = c;
				
				if(real_a >= real_b && real_b >= real_c)
				{
					int d= real_a-real_c;
					if(diff>=d)
					{
						if(diff==d)
						{
							if(solve_a > real_a)
							{
								solve_a=real_a;
								solve_b=real_b;
								solve_c=real_c;
							}
						}
						else
						{
								diff=d;
								solve_a=real_a;
								solve_b=real_b;
								solve_c=real_c;
						}
					}
				}
				
			}
		}
		
		printf("%d %d %d",solve_a,solve_b,solve_c);

}





//아래 알고리즘 보지 말자. 위의 두개 보도록
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



/*
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//DP
각 선물의 부피가 100이고 선물의 개수가 20개이므로 모든 선물 부피의 합이 2000을 초과하지 않는다. 

DT[k][b][c] = 현재 k 개의 선물을 받았을 때(k까지 선물을 받았을때 고려했을때 ), 길순이가 부피 b, 길삼이가 부피 c 를 받을 수
있는 상태가 가능하면 1, 그렇지 않으면 0



결정문제
ex )  선물이 5개가 있을때  길순 / 길삼  가 선물을 100,76 을 가질수가 있는가? Yes or NO 

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

#include <cstdio>
int n, W, G[21], A, B, C, ans=987654321;
bool DT[21][668][668];
int main()
{
scanf("%d", &n);
for(int i=1; i<=n; i++)
scanf("%d", G+i), W+=G[i];
DT[0][0][0]=true;
for(int i=1; i<=n; i++)
for(int a=0; a<=667; a++)
for(int b=0; b<=667; b++)
DT[i][a][b]=(DT[i-1][a][b] ||
(a-G[i]<0?false:DT[i-1][a-G[i]][b]) ||
(b-G[i]<0?false:DT[i-1][a][b-G[i]]));
for(int a=0; a<=667; a++)
for(int b=0; b<=667; b++)
if(DT[n][a][b])
{
if(W-(a+b)>=a && a>=b && W-(a+b)-b<=ans)
ans=W-(a+b)-b, A=W-(a+b), B=a, C=b;
}
printf("%d %d %d\n", A, B, C);
return 0;
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//분석을 위해서 디버깅 코드 넣은 소스 
////////////////////////
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>



#include <cstdio>

#define INF 987654321

int n, W, G[21], A, B, C, ans=987654321;
bool DT[21][2001][2001];

int bound;

int min_d=INF;
int min_d_a=INF;


void display()
{

	for(int i=0; i<=3; i++) 
	{
		printf("%d . \n",i);
		for(int a=0; a<=6; a++)  
		{
			for(int b=0; b<=6; b++)
			{
				printf(" %d",DT[i][a][b]);
			}
			printf("\n");
		}
		printf("=============\n\n");

	}
}

int main()
{
	freopen("input.txt","r",stdin);

	//freopen("output_present.txt","w",stdout);

	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	scanf("%d", G+i), W+=G[i];
	
	bound=(int) 2000/3; // 길순/길삼은 이 값을 넘을 수 없다.
			   

	DT[0][0][0]=true;

	for(int i=1; i<=n; i++)           // 선물 하나를 가지고 모든 case를 계산하고, 다시 다음 선물을 가지고 모든 case를 계산한다. .. 마지막 선물까지 고려한다.
	for(int a=0; a<=bound; a++)    // 최대 정의역까지 간다. 
	for(int b=0; b<=bound; b++)
	{	
	#if 0
		DT[i][a][b]=(DT[i-1][a][b] || (a-G[i]<0?false:DT[i-1][a-G[i]][b]) ||(b-G[i]<0?false:DT[i-1][a][b-G[i]]));
		//현재 i개의 선물을 받았을 때, 길순이가 부피 a, 길삼이가 부피 b 를 받을 수 있는 상태가 가능하면 1, 그렇지 않으면 0
		// 생뚱맞게 부피가 확장되어서 늘어 나느게 아니라, 이전의 선물의 기반으로 지금 선물의 부피을 이어 받을 수 있는지? 있으면 1이다.
	#else
		if (DT[i-1][a][b]==1)
		{
 		 DT[i][a][b]=1;
		 DT[i][a+G[i]][b]=1;
		 DT[i][a][b+G[i]]=1;
		}			
	#endif
	}

	display();
	
	for(int a=0; a<=bound; a++)
	for(int b=0; b<=bound; b++)
		if(DT[n][a][b])   //마지막 n까지 모두 고려했을때 마지막을 보면 1~n 선물까지 다 고려해서 만들어진 최적이다.
		{
			//교재 방법 
			#if 0
			printf("- %d  %d  %d \n" , W- (a+b) ,a, b); // 길동 ,김순,  길삼
	
			if(W-(a+b)>=a && a>=b && W-(a+b)-b<=ans)  // 내가 짠 전체 탐색조건하고 똑같음,  이 부분은 어려운 부분이 아님     
			                                          // W-(a+b)-b<=ans  , = 이 들어가야지 해가 나온다. 이 부분 명료하지 아래 내 방법으로 보기 
	    	ans=W-(a+b)-b, A=W-(a+b), B=a, C=b;
		
			#else 
				
			// 내방법 
			int real_a=(W-(a+b));
			int real_b=a;
			int real_c=b;
			
			 if(real_a >= real_b && real_b >= real_c )
			{
				if( min_d >= real_a - real_c   &&  min_d_a  >=  real_a )  // 매번 여기 헷갈린다. 조심!!!
				{
	    	 	  min_d=real_a-real_c; 
				  min_d_a=A=real_a;
				  B=real_b;
				  C=real_c;					
				
				}
			}
			
			#endif
			
		}
		
	printf("result  : %d %d %d\n", A, B, C);
	return 0;
}




로깅 출력 

입력
3
3 2 1

디버깅 코드 출력
>>>>>>>>>>>>>>>>>

0 .   아마것두 고려하지 않다 이말은 길순 길삼이 각각 0이다 그러므로 길동이 6 이다 .  6.0.0 임
 1 0 0 0 0 0 0
 0 0 0 0 0 0 0
 0 0 0 0 0 0 0
 0 0 0 0 0 0 0
 0 0 0 0 0 0 0
 0 0 0 0 0 0 0
 0 0 0 0 0 0 0
=============
                          6 0 0    
1 .   '3' 을 고려했을때   3 0 3
 1 0 0 1 0 0 0            3 3 0 
 0 0 0 0 0 0 0
 0 0 0 0 0 0 0
 1 0 0 0 0 0 0     
 0 0 0 0 0 0 0
 0 0 0 0 0 0 0
 0 0 0 0 0 0 0
=============

2 . '2'을 고려햇을때 
 1 0 1 1 0 1 0
 0 0 0 0 0 0 0
 1 0 0 1 0 0 0
 1 0 1 0 0 0 0
 0 0 0 0 0 0 0
 1 0 0 0 0 0 0
 0 0 0 0 0 0 0
=============

3 . '1'을 고려했을 때 
 1 1 1 1 1 1 1
 1 0 1 1 0 1 0
 1 1 0 1 1 0 0
 1 1 1 1 0 0 0
 1 0 1 0 0 0 0
 1 1 0 0 0 0 0
 1 0 0 0 0 0 0
=============

- 6  0  0 
- 5  0  1 
- 4  0  2 
- 3  0  3 
- 2  0  4 
- 1  0  5 
- 0  0  6 
- 5  1  0 
- 3  1  2 
- 2  1  3 
- 0  1  5 
- 4  2  0 
- 3  2  1 
- 1  2  3 
- 0  2  4 
- 3  3  0 
- 2  3  1 
- 1  3  2 
- 0  3  3 
- 2  4  0 
- 0  4  2 
- 1  5  0 
- 0  5  1 
- 0  6  0 
result  : 3 2 1


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//메모리를 적게 사용하는 토클링 방법은 내하고 그다지 상관없을듯 시간될때 보도록 ...
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

