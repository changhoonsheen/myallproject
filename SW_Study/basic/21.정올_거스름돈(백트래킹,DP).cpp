
//창훈 최종 필기


/*
//DT 테이브를 사용하지 않으면 이 데이터는 답이 나오지 않는다.
9820
7
10 15 20 50 100 400 500



730
5
10 50 100 500 1250
답 6


570
7
10 50 100 500 1000 5000 10000
답 4

*/

/*
/*
730 5
10 50 100 500 1250
*/



// DT 테이블을 이용한 하향식 방법
// 나는 돈울 줄여갔다.  기출 주식 문제하고 흡사하다.

#include<stdio.h>

int m;
int n;
int coins[10];
int DT[20000];

void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d %d",&m,&n);

	for(int i=0;i<n;i++)
	{
		scanf("%d",&coins[i]);
	}

}

int MIN(int a, int b)
{
	return a > b ? b : a;
}

int f(int total)
{
	if(total==0) return DT[total]=0; //실수 Base 처리!!
	if(DT[total]!=-1) return DT[total];

	int min_value=987654321;
	for(int i=0;i<n;i++)
	{
	 if(total-coins[i]>=0) min_value=MIN(min_value,f(total-coins[i])+1);
	}

	return DT[total]=min_value;
}

void main(void)
{
input();

for(int i=0;i<=10000;i++)
{
	DT[i]=-1;
}

printf("%d\n",f(m));

}
*/


//가장 기본 백트래킹 풀이
#include<stdio.h>

int m; //거슬러줘야하는 돈
int n; //동전의 갯수 , 거슬러줘야하는 동전의 갯수가 최소가 되어야한다.

int money[11];
int min_count=987654321;

int func_count;

int check[11]; // 선택된 동전 갯수 표시하기
int result_check[11]; // 선택된 동전 갯수 표시하기


void input()
{
	freopen("input.txt","r",stdin);
//	freopen("output_changes.txt","w",stdout);

	scanf("%d",&m);
	scanf("%d",&n);

	for(int i=1;i<=n;i++)
	{
		scanf("%d",&money[i]);
	}
}


void solve(int total, int count)
{
	if(min_count < count) return; //가지치기는 필수 , 아님 결과 안나옴

	func_count++;

	if(total>=m)
	{
		if(total==m)
		{
			if(min_count > count){ 
				min_count=count;
				
				for(int i=1;i<=n;i++)
				{
					result_check[i]=check[i];
				}
			}
		}
	    return;
	}

	for(int i=1;i<=n;i++)
	{
		check[i]=check[i]+1; // 선택된 동전 갯수 표시하기
		solve(total+money[i],count+1);
		check[i]=check[i]-1; // 선택된 동전 갯수 표시하기
	}
}

void main()
{
	input();
	solve(0,0);
	printf("min_count:%d\n",min_count);
	printf("func_count:%d\n",func_count);

	printf("\nselected coins : \n");
	for(int i=1;i<=n;i++)
	{
		if(result_check[i])
		{
			printf("conis:%d count:%d \n",money[i],result_check[i]);
		}
	}

}









//Greedy 반영한 알고리즘 , 성능이 많이 좋아짐.

#include<stdio.h>

int m; //거슬러줘야하는 돈
int n; //동전의 갯수 , 거슬러줘야하는 동전의 갯수가 최소가 되어야한다.

int money[11];
int min_count=987654321;

int func_count;

void input()
{
	freopen("input.txt","r",stdin);
//	freopen("output_changes.txt","w",stdout);

	scanf("%d",&m);
	scanf("%d",&n);

	for(int i=1;i<=n;i++)
	{
		scanf("%d",&money[i]);
	}
}

//반드시 돈들은 정렬되어 있어야한다. 큰 것 부터 내어 줄꺼기 때문
//탐욕적으로 큰돈을 고려해서 준다고 생각.
void greedy()
{
	int change_count=0;
	int tot=m;
	for(int i=n; i >= 1; i--)
	{
		if ( tot >= money[i] ) // 제일 큰돈부터 거슬러 줘서... 작은 동전 까지 고려한다. 
		{

			while(1)
			{
				if ( tot - money[i] >= 0  )// 이 동전이 고려될수 있다. 
				{
					 tot-=money[i];   // 전체 돈에서 빼주면서 
					 change_count++;  // 동전의 갯수를 증가시킨다.
				}
				else
				{
					printf("money : %d  total change_count:%d \n" , money[i] ,change_count );
					break;
				}
			}
	}
	
}

//greedy해를 찾은 경우
if(tot==0)
{
	min_count=change_count;
}
else // greedy해를 못 찾은 경우
{
	min_count=987654321;
}

printf("greedy count:%d\n",min_count);
}


//창훈 그리디 알고리즘 교재 필기함.
void greedy2()
{
	int r=m;
	int money_count=0;
	for(int i=n-1;i>=0;i--)
	{
		while(r>=money[i])
		{
			r=r-money[i];
			money_count++;
		}
	}
	
	//greedy로 해가 합당한가? r이 0이 어야함.
	if(r==0) 
	min_cnt=money_count;
	else
	min_cnt=987654321;

}


void solve(int total, int count)
{
	if(min_count < count) return; //가지치기는 필수

	func_count++;

	if(total>=m)
	{
		if(total==m)
		{
			if(min_count > count) min_count=count;
		}
	    return;
	}

	for(int i=1;i<=n;i++)
	{
		solve(total+money[i],count+1);
	}
}

void main()
{
	input();
	greedy();

	if(min_count==987654321)
	{
		printf("No solution\n");
	}
	else
	{
		solve(0,0);
		printf("min_count:%d\n",min_count);
		printf("func_count:%d\n",func_count);
	}
}




//하향식 DT 테이블 반영 

#include<stdio.h>

int m; //거슬러줘야하는 돈
int n; //동전의 갯수 , 거슬러줘야하는 동전의 갯수가 최소가 되어야한다.

int money[11];
int min_count=987654321;

int func_count;

int DT[10000];

void input()
{
	freopen("input.txt","r",stdin);
//	freopen("output_changes.txt","w",stdout);

	scanf("%d",&m);
	scanf("%d",&n);

	for(int i=1;i<=n;i++)
	{
		scanf("%d",&money[i]);
	}
}



int MIN(int a, int b)
{
	return a>b?b:a;
}

int solve(int total)
{
	if(DT[total]!=-1) return DT[total];

	if(total==m) return DT[total]=0;

	int result=987654321;

	for(int i=1;i<=n;i++)
	{
		if(total+money[i] <= m)  //중요!! 폭의 가지치기 중요함.  애초부터 바닥의 값을 초과할 수가 없는 구조다. Base에 둬도 되지만, DT 테이블 크기가 있기에 비효율적
		result=MIN(result,solve(total+money[i])+1);
	}

	return DT[total]=result;
}

void main()
{
	input();

	for(int i=0;i<10000;i++)
	{
		DT[i]=-1;
	}

	printf("min_count:%d\n",solve(0));
	printf("func_count:%d\n",func_count);
}






//DP 풀이
#include<stdio.h>

int m; //거슬러줘야하는 돈
int n; //동전의 갯수 , 거슬러줘야하는 동전의 갯수가 최소가 되어야한다.

int money[11];
int DT[11][10001]; //1~10개의 동전을 고려했을때 10000을 고려했을때의 최소 동전의 갯수

void input()
{
	freopen("input.txt","r",stdin);
//	freopen("output_changes.txt","w",stdout);

	scanf("%d",&m);
	scanf("%d",&n);

	for(int i=1;i<=n;i++)
	{
		scanf("%d",&money[i]);
	}
}

int MIN(int a, int b)
{
	return a>b ? b:a ;
}


void printMatrix()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			printf(" %d",DT[i][j]);
		}
		printf("\n");
	}

}


void main()
{
	input();

	for(int j=1;j<=m;j++)
	{
		DT[0][j]=0xffff;
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(money[i] > j) DT[i][j]=DT[i-1][j];
			else
			{
				DT[i][j]=MIN(DT[i][j-money[i]]+1,DT[i-1][j]);
			}
		}
	}

	printMatrix();
	printf("%d",DT[n][m]);
}







////////////////////////////////////////////////////////////////////////////
