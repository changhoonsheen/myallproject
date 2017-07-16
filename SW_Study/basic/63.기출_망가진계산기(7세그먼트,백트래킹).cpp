/*

하기와 같이 Test case하나 입력 

0 0 1 0 0 0 0
0 0 1 0 0 0 0
0 0 1 0 0 0 0
1 0 0 0 0 0 0
1 0 0 0 0 0 0
1 0 0 0 0 0 0
1 0 0 0 0 0 0
1 0 0 0 0 0 0
1 0 0 0 0 0 0
1 0 0 0 0 0 0
1 0 0 0 0 0 0
1 0 0 0 0 0 0

--------------------------------
알고리즘 설명 

1.입력을 아래와 같이 3군으로 나눈다.

0 0 1 0 0 0 0  //A군
0 0 1 0 0 0 0
0 0 1 0 0 0 0

1 0 0 0 0 0 0  //B군 
1 0 0 0 0 0 0
1 0 0 0 0 0 0

1 0 0 0 0 0 0  //C군
1 0 0 0 0 0 0
1 0 0 0 0 0 0
1 0 0 0 0 0 0
1 0 0 0 0 0 0
1 0 0 0 0 0 0


2.
A * B = C

A군 * B군 = C군

나올 수 있는 모든 A군을 뽑는다.(실제 나올수 았는 숫자(Integer)와 그 갯수)
나올 수 있는 모든 B군을 뽑는다.(실제 나올수 았는 숫자(Integer)와 그 갯수)

- A군 * B군 한 결과를 인덱스로 생각하고 아래 구조체 배열의 value1 맴버에 체크한다.
- C군를 인덱스로 생각하고 아래 구조체 배열의 value2 맴버에 체크한다.

struct result_arr
{
	int value1;
	int value2;
}

result_arr result[100000]; //결과 값은 이 범위를 넘지 않는다

3. 결과 찾기
C가 나올수 있는 제일 작은 값 임으로 result배열의 인덱스 0번 부터 검색을 하여 value1,value2가 1로 설정되어 있으면
이게 정답이며 알고리즘을 끝낸다.

*/

#include<stdio.h>

int N = 7;

//실제 숫자
int DIGIT[10][10] ={
{1, 1, 1, 0, 1, 1, 1}, //0
{0, 0, 1, 0, 0, 1, 0}, //1
{1, 0, 1, 1, 1, 0, 1}, //2
{1, 0, 1, 1, 0, 1, 1}, //3
{0, 1, 1, 1, 0, 1, 0}, //4
{1, 1, 0, 1, 0, 1, 1}, //5 
{1, 1, 0, 1, 1, 1, 1}, //6 
{1, 1, 1, 0, 0, 1, 0}, //7
{1, 1, 1, 1, 1, 1, 1}, //8
{1, 1, 1, 1, 0, 1, 1}  //9
};


int arr[10];           // 실제 입력 받은 한줄(7 세그먼트)
int arr_result[10];    // 가능한 부분집합을 찾는 실제 Integer값이 들어감
int arr_result_cnt;    // 그 샛수 


//A군에 만들수 있는 숫자와 갯수
int A_set[1000];
int A_sen_cnt;


//B군에 만들수 있는 숫자와 갯수 
int B_set[1000];
int B_sen_cnt;


//C군에서 만들수 있느 숫자와 갯수 
int C_set[1000000];
int C_sen_cnt;


struct result_arr
{
	int value1;
	int value2;
};

result_arr result[100000]; //결과 값은 이 범위를 넘지 않는다


//진짜 숫자이면 1과 a로 정보를 넘긴다.
int isitdigit(int *a)
{
	for (int i = 0; i <= 9; i++)
	{
		int cnt = 0;
		for (int j = 0; j < N; j++)
		{
			if (DIGIT[i][j] == arr[j])
			{
				cnt++;
			}
		}

		if (cnt == N)
		{
			*a = i;
			return 1;
		}
	}

	*a = 0;
	return 0;
}


//한줄(7 세그먼트)을 입력받아서 가능한 모든 숫자를 반환한다.
void make_onedigit(int k)
{
	if (k == N)
	{
		int digit = 0;
		if (isitdigit(&digit))
		{
			arr_result[arr_result_cnt] = digit;
			arr_result_cnt ++ ;
		}

		return;
	}

	if (arr[k]) 
	{
		make_onedigit(k + 1);
	}
	else
	{	//현재상태를 토글 시킨다.
		arr[k] = 1;           // 여기 순서 주의 
		make_onedigit(k + 1);
        //원래대로 만들고 탐색을 계속 진행 
		arr[k] = 0;
		make_onedigit(k + 1);
	}
}


void main()
{
	freopen("input.txt", "r", stdin);

	for (int i = 0; i < N; i++)
	scanf("%d", &arr[i]);

	make_onedigit(0);  // 첫번째 라인에서 나올 수 있는 모든 부분집합 
	
	//하나의 7세그먼트가 "0 0 1 0 0 0 0" 가 만들수 있는 숫자 출력해보기
	for (int i = 0; i < arr_result_cnt; i++)
	{
		printf(" %d", arr_result[i]);
	}


	//이하는 위의 알고리즘으로 생략하겠습니다. 
	//쉽게 for로 A군,B군,C군의 모든 가능한 수를 찾을 수 있을껍니다.


	//A군(실제 XXX단위 숫자를 만듦)

	//B군(실제 XXX단위 숫자를 만듦)

	//C군(실제 XXXXXX단위 숫자를 만듦)

	//위의 알고리즘 2,3을 진행합니다.


}