/*
크리스마스 전등만들기

공장에서 해당 상품을 만들기 위해서 필요한 전등의 갯수(R,B,Y)가 이미 정해져 있고,
하나의 상품을 만들기 위해서 필요한 갯수가 이미 정해져 있을때 
가장 많은 상품을 만들고자 할때 몇개의 상품을 최대로 만들 수 있는가?
<이때 한 상품을 3개까지만 만들수 없다.>

테스트 케이스 답은 3임

1
3 3 2 4  //3 상품수 , R 전등갯수 : 3 ,  b 전등갯수 : 2 ,    Y 전등갯수 : 4
1 1 1    //상품1이 소모되는 전등수 R전등:1, B전등:1, Y전등:1
1 0 2    //상품2이 소모되는 전등수 R전등:1, B전등:0, Y전등:2
1 1 0    //상품3이 소모되는 전등수 R전등:1, B전등:1, Y전등:0



input.txt
1
3 3 2 4
1 1 1 
1 0 2
1 1 0



*/

#include<stdio.h>

int TEST_CASE;

int product_cnt; 
int r_cnt;  //최대 50개의 전등을 공장에서 소유할 수 있음
int b_cnt;  //최대 50개의 전등을 공장에서 소유할 수 있음
int y_cnt;  //최대 50개의 전등을 공장에서 소유할 수 있음

int arr[11][3]; // 상품의 수는 최대 10개임 

int MAX_PROUDCT_CNT;

int func_call;

int made_product[11]; //한 상품을 3개 이상 만들수 없다.
                      //그래서 현재까지 만들어진 각 상품의 갯수가 필요함

int DT[51][51][51][51]; //중복된 연산 반복 제거, 예제 5개는 맞음 그러나.!!!!
                        //이게 없으면 검증시스템에 넣으면 결과 Timeout 남
                        //이런걸 찾을 수 있는 테크닉이 필요함! 중요함!

void input()
{
	scanf("%d %d %d %d", &product_cnt, &r_cnt, &b_cnt, &y_cnt);
	for (int i = 1; i <= product_cnt; i++)
	{
		scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
	}
}

//현재 i번째 상품을 만들수 있는가?
int isitpossible(int i)
{
	//현재 공장에 전등이 없어서 못 만드는 경우를 처리함.
	if (r_cnt - arr[i][0] < 0) return 0;
	if (b_cnt - arr[i][1] < 0) return 0;
	if (y_cnt - arr[i][2] < 0) return 0;

	return 1;
}

//현재 가지고 있는 전등을 소모했서 하나를 만든다.
void make_product(int i)
{
	r_cnt -= arr[i][0];
	b_cnt -= arr[i][1];
	y_cnt -= arr[i][2];
}

//사용했던 전등을 원래 되로 돌려 놓는다.
void unmake_product(int i)
{
	r_cnt += arr[i][0];
	b_cnt += arr[i][1];
	y_cnt += arr[i][2];
}

void solve(int cnt)
{
	//printf("cnt:%d\n", cnt);

	//제일 중요한 부분이다 !!!! 5개는 맞지만 
	//이 부분이 없으면 검증 시스템에서는 timeout남 왜 필요한지 생각해도록!! 
	//>>
	if (DT[cnt][r_cnt][b_cnt][b_cnt] == 1) return;
	DT[cnt][r_cnt][b_cnt][b_cnt] = 1;
	//<<

	func_call++;

	if (MAX_PROUDCT_CNT < cnt)
	{
		MAX_PROUDCT_CNT = cnt;
	}


	for (int i = 1; i <= product_cnt; i++)
	{

		if (made_product[i] < 3 && isitpossible(i))
		{
			make_product(i);    // i번째 상품을 하나를 만듦
			made_product[i]++;  // 하나의 상품을 3개만 만들수 있음으로 이를 카운트한다.
			solve(cnt + 1); 
			made_product[i]--;  // 이를 카운트했던걸 돌려 놓는다.
			unmake_product(i);  // i번째 상품을 현재 상태를 돌려 놓음
		}

	}

}


void main()
{

	freopen("input.txt", "r", stdin);
	scanf("%d", &TEST_CASE);

	for (int i = 1; i <= TEST_CASE; i++)
	{
		input();
		solve(0);
		printf("func_call : %d \n", func_call);
		printf("max product:%d\n", MAX_PROUDCT_CNT);
	}

}








