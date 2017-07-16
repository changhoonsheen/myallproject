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


300 : �ʱ� ��ġ��
60 : �� ���Ա�
3 : ����ȸ���(������)
8 : 8���� ����(������ 0��°~8��°�� �׷��� ���̺��� ���δ� ��ȩ��)

//����
//0��(ù��° ���� ���̺�)���� ���� �ֽ� �ż� ����, 1�� ���� �ŵ���, �������� �Ѿ�� �Ŵ� ���޿� �� �ֽ��� ����ȭ ���� 
//����ȭ ��Ų���� ������ �׿� �� �ٽ� ������.
//�׸��� ù�޺��� ~ ����ޱ��� �����Ա�(���⼱ 60) �߰���(0��° ���� �ƴ�)
//�ֽ� : ����� ���� +-30%
//�̷��� ��� ���ڸ� �Ͽ� ������ ���� ���� �ִ� ������ ���ΰ� ????? <1228>
//<���� : �ִ� ���ͱݿ��� ���ڱ��� ���� ,  <1228> - (300 + 60*8) => 448�� ���� ���ͱ��� >

*/




//������ Ǯ�̸� ��Ʈ��ŷ���� Ǯ����.
//�Լ� ���谡 DT[�ݾ�] �ش� �ݾ����� ���� �ִ� �ִ� ���ͱ���?
#include<stdio.h>

#define SIZE 100000

int Ma; //�ʱ� �ں�
int Ms; //�����Ա�
int C;  //����ȸ��� (3~15��)
int L;  //���ڱⰣ 1~15����

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

//������ �˰��� 
// �ش��(m)�� ���ڱ�(money)�� �����ؼ� ���� �� �ִ� �ִ� ������?
// �Ž����� �˰��� : �ش絷���� �ټ� �ִ� �ּ� ���� ������?  / �賶 �˰���(01 �賶����) : ���� �ɶ����� ��� ����  
//�Ž����� �˰����ϰ� ���� ������.
//money�� month�򰥸���. �Ǽ�!!!!
//������ ���ý� ����!!!
int solve(int month, int money)
{

	if(money==0) {  // ���� 0�϶� ó��
		 return DT[money]=0 ;
	}

	if(DT[money]!=-1) return DT[money];

	int MAX_RESULT=0;
	for(int i=1;i<=C;i++)
	{
		if(money-TABLE[i][month]>=0 && TABLE[i][month] < TABLE[i][month+1]) //���� ���صǴ°��� �մ� �ʿ䰡 ����.
		{
			MAX_RESULT=MAX(
				       MAX_RESULT,  //������� �ݾװ� �������� diff�� ���� ������.
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
	for(int i=0;i<L;i++)  //������ ������ �� �ʿ䰡 ����.
	{
		if(i!=0) money=money+Ms;
		printf("%d month : max profit - %d \n",i,money);
		init();
		int max_profit=solve(i,money);
		money+=max_profit;
	}

	//���ö� ���� ó�� ���� �����Աݸ� ���ϸ�ȴ�. 
	money+=Ms;
	printf("%d month : max profit - %d \n",L,money);

	printf("%d\n",money-(Ma+L*Ms));
}













//DP �Ϻ�Ǯ�� �������� ǰ
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

	for(i=1;i<=N;i++)//ȸ���
	{
		for(j=0;j<=M;j++) //������ 
		scanf("%d",&input[i][j]);
	}

	money=ms;
	for(j=0;j<=M;j++)
	{
		if(j!=0) money+=ma; //������ 0�޿��� �� ����

		printf("%d month : max profit:%d \n",j,money);

		for(k=1;k<=money;k++) //�����, ����� �ʱ� �ں��� , 1���� �� ��� ��ŭ ����
		{
			data[k]=0;//�ʱ�ȭ ������ //k�ڱ����� ���� �ִ� ���ͱ���.?
			
			//���� Ȯ���ҵ�k
			//���� Ȯ���� �ֽİ��� input[i][j] �ش� index��ŭ���� �ִ� ������ ������ �迭
			//DP�� ���� �ݾ׿��� �ִ� ���͸� ������.
			//�迭 k-input[i][j]�� �ε����� ����Ҳ��� ������ �ȵ�.

			for(i=1;i<=N;i++)
			{
				if(k-input[i][j]>=0 && data[k] < data[k-input[i][j]]+(input[i][j+1]-input[i][j]))
					data[k] =data[k-input[i][j]]+(input[i][j+1]-input[i][j]);
			}
		}

		money+=data[money];

	}

	money1 = ms+(M*ma);//���ڱ�
	result = money-money1;
	printf("%d\n",result);
}



//������ Ǯ�̸� ��Ʈ��ŷ���� Ǯ����.
//�Լ� ���谡 DT[�ݾ�] �ش� �ݾ����� ���� �ִ� �ִ� ���ͱ���?
#include<stdio.h>

#define SIZE 100000

int Ma; //�ʱ� �ں�
int Ms; //�����Ա�
int C;  //����ȸ��� (3~15��)
int L;  //���ڱⰣ 1~15����

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

//�Ž����� �˰����ϰ� ���� ������.
//money�� month�򰥸���. �Ǽ�!!!!
//������ ���ý� ����!!!
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
	for(int i=0;i<L;i++)  //������ ������ �� �ʿ䰡 ����.
	{
		if(i!=0) money=money+Ms;
		printf("%d month : max profit - %d \n",i,money);
		init();
		int max_profit=solve(i,money);
		money+=max_profit;
	}

	//���ö� ���� ó�� ���� �����Աݸ� ���ϸ�ȴ�. 
	money+=Ms;
	printf("%d month : max profit - %d \n",L,money);

	printf("%d\n",money-(Ma+L*Ms));
}




 
//â���� Ǭ��.. �̷��� Ǯ��ȵ�.!!
//��Ʈ��ŷ Ǯ��- �⺻ Ǯ�� ���� ũ�Ⱑ Ŀ���� �ߺ�ȣ���� ������ ����� ���µ� ����
//�߸��� Ǯ��. 

#include<stdio.h>

int Ma; //�ʱ� ���ڱ�
int Ms; //�� ���Ա�

int C; //����ȸ�� �� 
int L; //�Ⱓ

int TABLE[20][20]; // �ֽ� ����, �Ⱓ.
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

	//���� ������ �ִ� ���� ó�� 
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