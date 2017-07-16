/*
300 60
3 8
135 120 111 144 170 170 171 173 169
156 150 144 144 144 150 150 150 147
195 180 165 150 141 172 185 190 159

0 month : max profit:300
1 month : max profit:360
2 month : max profit:420
3 month : max profit:579
4 month : max profit:743
5 month : max profit:958
6 month : max profit:1083
7 month : max profit:1168
8 month : max profit:1228
448


320 0
2 1
80 160
150 250

0 month : max profit:320
1 month : max profit:640
320


230 0
2 1
80 160
150 250

0 month : max profit:230
1 month : max profit:410
180


300 : 초기 예치금
60 : 월 불입금
3 : 투자회사수(가로줄)
8 : 8개월 투자(세로줄 0번째~8번째달 그래서 테이블은 세로는 아홉임)

//문제
//0달(첫번째 세로 테이블)에서 부터 주식 매수 가능, 1달 부터 매도함, 다음달이 넘어가면 매달 전달에 산 주식을 현금화 가능 
//현금화 시킨돈을 가지고 그에 또 다시 투자함.
//그리고 첫달부터 ~ 종료달까지 월불입금(여기선 60) 추가됨(0번째 달은 아님)
//주식 : 등락은 폭은 +-30%
//이렇게 계속 투자를 하여 마지막 달이 됐을 최대 이익은 얼마인가 ????? <1228>
//<답은 : 최대 이익금에서 투자금을 빼면 ,  <1228> - (300 + 60*8) => 448임 실제 수익금임 >

*/




//서성덕 풀이를 백트래킹으로 풀이함.
//함수 설계가 DT[금액] 해당 금액으로 벌수 있는 최대 이익금은?
#include<stdio.h>

#define SIZE 100000

int Ma; //초기 자본
int Ms; //월불입금
int C;  //투자회사수 (3~15개)
int L;  //투자기간 1~15개월

int TABLE[20][20];

int DT[SIZE];

void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d %d",&Ma,&Ms);
	scanf("%d %d",&C,&L);

	for(int i=1;i<=C;i++)
	for(int j=0;j<=L;j++)
	scanf("%d",&TABLE[i][j]);
}


int MAX(int a, int b)
{
	return a>b ? a : b;
}

//동일한 알고리즘 
// 해당달(m)에 투자금(money)를 투자해서 얻을 수 있는 최대 이익은?
// 거스름돈 알고리즘 : 해당돈으로 줄수 있는 최소 동작 갯수는?  / 배낭 알고리즘(01 배낭말고) : 돈이 될때까지 담아 보기  
//거스름돈 알고리즘하고 동일 패턴임.
//money와 month헷갈린다. 실수!!!!
//변수명 선택시 주의!!!
int solve(int month, int money)
{

	if(money==0) {  // 돈이 0일때 처리
		 return DT[money]=0 ;
	}

	if(DT[money]!=-1) return DT[money];

	int MAX_RESULT=0;
	for(int i=1;i<=C;i++)
	{
		if(money-TABLE[i][month]>=0 && TABLE[i][month] < TABLE[i][month+1]) //굳이 손해되는것을 손댈 필요가 없다.
		{
			MAX_RESULT=MAX(
				       MAX_RESULT,  //현재달의 금액과 이전달의 diff가 현재 수익임.
					   solve(month,money-TABLE[i][month])+(TABLE[i][month+1]-TABLE[i][month])
					   );
		}
	}

	return DT[money]=MAX_RESULT;
}

void init()
{
	for(int i=0;i<SIZE;i++)
	DT[i]=-1;
}

int main(void)
{
	input();

	int money=Ma;
	for(int i=0;i<L;i++)  //로직상 막달은 갈 필요가 없다.
	{
		if(i!=0) money=money+Ms;
		printf("%d month : max profit - %d \n",i,money);
		init();
		int max_profit=solve(i,money);
		money+=max_profit;
	}

	//나올때 막달 처리 단지 월불입금만 더하면된다. 
	money+=Ms;
	printf("%d month : max profit - %d \n",L,money);

	printf("%d\n",money-(Ma+L*Ms));
}













//DP 완벽풀이 서성덕이 품
#include<stdio.h>
#define SIZE 16

int input[SIZE][SIZE];
int data[100000];

int main(void)
{
	int test_case,T, ms,ma,N,M;
	int money,money1,i,j,k,n;

	int result;

	freopen("input.txt","r",stdin);
	scanf("%d",&ms);
	scanf("%d",&ma);
	scanf("%d",&N);
	scanf("%d",&M);
	result=0;
	money1=0;

	for(i=1;i<=N;i++)//회사수
	{
		for(j=0;j<=M;j++) //개월수 
		scanf("%d",&input[i][j]);
	}

	money=ms;
	for(j=0;j<=M;j++)
	{
		if(j!=0) money+=ma; //월급은 0달에는 안 받음

		printf("%d month : max profit:%d \n",j,money);

		for(k=1;k<=money;k++) //전재산, 현재는 초기 자본금 , 1부터 내 재산 만큼 돌림
		{
			data[k]=0;//초기화 시켜줌 //k자금으로 벌수 있는 수익금은.?
			
			//현재 확인할돈k
			//현재 확인할 주식가격 input[i][j] 해당 index만큼으로 최대 이익이 저정된 배열
			//DP로 현재 금액에서 최대 이익만 생각함.
			//배열 k-input[i][j]을 인덱스로 사용할꺼라 음수면 안됨.

			for(i=1;i<=N;i++)
			{
				if(k-input[i][j]>=0 && data[k] < data[k-input[i][j]]+(input[i][j+1]-input[i][j]))
					data[k] =data[k-input[i][j]]+(input[i][j+1]-input[i][j]);
			}
		}

		money+=data[money];

	}

	money1 = ms+(M*ma);//투자금
	result = money-money1;
	printf("%d\n",result);
}



//서성덕 풀이를 백트래킹으로 풀이함.
//함수 설계가 DT[금액] 해당 금액으로 벌수 있는 최대 이익금은?
#include<stdio.h>

#define SIZE 100000

int Ma; //초기 자본
int Ms; //월불입금
int C;  //투자회사수 (3~15개)
int L;  //투자기간 1~15개월

int TABLE[20][20];

int DT[SIZE];

void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d %d",&Ma,&Ms);
	scanf("%d %d",&C,&L);

	for(int i=1;i<=C;i++)
	for(int j=0;j<=L;j++)
	scanf("%d",&TABLE[i][j]);
}


int MAX(int a, int b)
{
	return a>b ? a : b;
}

//거스름돈 알고리즘하고 동일 패턴임.
//money와 month헷갈린다. 실수!!!!
//변수명 선택시 주의!!!
int solve(int month, int money)
{
	if(DT[money]!=-1) return DT[money];

	int MAX_RESULT=0;
	for(int i=1;i<=C;i++)
	{
		if(money-TABLE[i][month]>=0 && TABLE[i][month] < TABLE[i][month+1])
		{
			MAX_RESULT=MAX(
				       MAX_RESULT,
					   solve(month,money-TABLE[i][month])+(TABLE[i][month+1]-TABLE[i][month])
					   );
		}
	}

	return DT[money]=MAX_RESULT;
}

void init()
{
	for(int i=0;i<SIZE;i++)
	DT[i]=-1;
}

int main(void)
{
	input();

	int money=Ma;
	for(int i=0;i<L;i++)  //로직상 막달은 갈 필요가 없다.
	{
		if(i!=0) money=money+Ms;
		printf("%d month : max profit - %d \n",i,money);
		init();
		int max_profit=solve(i,money);
		money+=max_profit;
	}

	//나올때 막달 처리 단지 월불입금만 더하면된다. 
	money+=Ms;
	printf("%d month : max profit - %d \n",L,money);

	printf("%d\n",money-(Ma+L*Ms));
}




 
//창훈이 푼거.. 이렇게 풀면안됨.!!
//백트래킹 풀이- 기본 풀이 돈의 크기가 커지면 중복호출이 심해져 결과가 오는데 힘듦
//잘못된 풀이. 

#include<stdio.h>

int Ma; //초기 투자금
int Ms; //월 불입금

int C; //투자회사 수 
int L; //기간

int TABLE[20][20]; // 주식 종목, 기간.
int RESULT_PROFIT[20];

void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d %d",&Ma,&Ms);
	scanf("%d %d",&C,&L);

	for(int i=1;i<=C;i++)
	for(int j=0;j<=L;j++)
    scanf("%d",&TABLE[i][j]);
}

int invest_table[15];
int MAX_PROFIT=-987654321;

int isitbase(int month, int original_money)
{
	int sum=0;
	for(int i=1;i<=C;i++)
	sum=sum+(invest_table[i]*TABLE[i][month-1]);

	return original_money < sum ? 1 : 0;
}

void invest(int month, int money, int original_money)
{
	if(isitbase(month,original_money))
	{
		return;
	}

	int invested_money=0;
	int earn_money=0;

	for(int j=1;j<=C;j++)
	{
		invested_money=invested_money + (invest_table[j]*TABLE[j][month-1]);
		earn_money=earn_money+(invest_table[j]*TABLE[j][month]);
	}

	int changes=original_money-invested_money;
	int total_money=changes+earn_money;

	if(MAX_PROFIT < total_money) MAX_PROFIT=total_money;

	for(int i=1;i<=C;i++)
	{
		if(money >= TABLE[i][month-1] && TABLE[i][month-1] < TABLE[i][month])
		{
			invest_table[i]=invest_table[i]+1;
			invest(month,money-TABLE[i][month-1],original_money);
			invest_table[i]=invest_table[i]-1;
		}
	}
}

int solve(int month, int money)
{
	int first_condition=0;
	int second_condition=0;

	//빨리 나갈수 있는 조건 처리 
	for(int i=1;i<=C;i++)
	if(TABLE[i][month-1] > TABLE[i][month]) first_condition++;
	if(first_condition==C) return money;

	for(int i=1;i<=C;i++)
	if(money< TABLE[i][month-1]) second_condition++;
	if(second_condition==C) return money;

	MAX_PROFIT=-987654321;
	for(int i=1;i<=C;i++) invest_table[i]=0;

	invest(month,money,money);

	return MAX_PROFIT;
}

void main(void)
{
	input();

	RESULT_PROFIT[0]=Ma;
	printf("0 month : max profit:%d \n",RESULT_PROFIT[0]);

	for(int i=1;i<=L;i++)
	{
		int max=solve(i,RESULT_PROFIT[i-1]);
		RESULT_PROFIT[i]=max+Ms;
		printf("%d month : max profit:%d \n",i,RESULT_PROFIT[i]);
	}

	printf("%d\n",RESULT_PROFIT[L]-(Ma+L*Ms));
}