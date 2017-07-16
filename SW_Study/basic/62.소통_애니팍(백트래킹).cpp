/*


1
BEEBEDDEBEEBBBBB
1 2 4 11 13 14
->2

1
BBBBBBBBBBBBBBBB
0 1 2 3 4 5 
-> 0

1
CDEBCDEBCDEBCDEB
4 2 10 11 3 8
-> -1


*/


#include<stdio.h>

int N;
char map[20] = {"\0"};
int grey[6];

int MIN_COUNT = 987654321;

void input()
{
	freopen("input.txt", "r", stdin);
	scanf("%d",&N);
	scanf("%s", &map);

	for (int i = 0; i <= 5; i++)
	{
		scanf("%d", &grey[i]);
	}
}


char next_animal(char t)
{
	//Bird->Cat->Dog->Elephant->Bird
	if (t == 'B') return 'C';
	else if (t == 'C') return 'D';
	else if (t == 'D') return 'E';
	else if (t == 'E') return 'B';
}

int checkgrey(int n)
{
	for (int i = 0; i <= 5; i++)
	{
		if (grey[i] == n) return 1;
	}

	return 0;
}

void all_change(int i)
{
	int first = i - 4;
	int second = i + 1;
	int third = i + 4;
	int fourth = i;

	printf("position : %d - ", i);
	if (first >= 0)
	{
		char new_type = next_animal(map[first]);
		map[first] = new_type;
		printf("%d : ", first);
	}

	if (second % 4 != 0)
	{
		char new_type = next_animal(map[second]);
		map[second] = new_type;
		printf("%d : ", second);
	}

	if (third <= 15)
	{
		char new_type = next_animal(map[third]);
		map[third] = new_type;
		printf("%d : ", third);
	}

	if (i %4 != 0)
	{
		fourth = i - 1;
		char new_type = next_animal(map[fourth]);
		map[fourth] = new_type;
		printf("%d : ", fourth);
	}

	printf("\n");
}


int isitfinished()
{
	for (int i = 0; i <= 15; i++)
	{
		if (map[i] != 'B') return 0;
	}

	return 1;
}

// a->b
void copy_arr(char a[], char b[])
{
	for (int i = 0; i <= 15; i++)
	{
		b[i] = a[i];
	}
}

void solve(int i, int cnt)
{

	if (MIN_COUNT < cnt) return;

	if (isitfinished()) // 바닥에서 처리를 하는게 아니라 매 단계마다 확인을 한다.
	{
		if (MIN_COUNT > cnt) MIN_COUNT = cnt;
	}
		
	if (i >= 16)
	{
		return;
	}


	char local_map[20] = {"\0"};
	char new_type;

	if (checkgrey(i))
	{
			solve(i + 1, cnt);
	}
	else
	{
		    /// 있는 그대로 유지하고 다음 단계로 
			solve(i + 1, cnt);

			///한번 터치 
			copy_arr(map, local_map);

			new_type = next_animal(map[i]);
			map[i] = new_type;
			all_change(i);
			cnt++;
			solve(i + 1, cnt);

			copy_arr(local_map, map);

			///두번 터치 
			copy_arr(map, local_map);

			new_type = next_animal(map[i]);
			map[i] = new_type;
			all_change(i);
			cnt++;

			new_type = next_animal(map[i]);
			map[i] = new_type;
			all_change(i);
			cnt++;

			solve(i + 1, cnt);

			copy_arr(local_map, map);

			///3번 터치 
			copy_arr(map, local_map);

			new_type = next_animal(map[i]);
			map[i] = new_type;
			all_change(i);
			cnt++;

			new_type = next_animal(map[i]);
			map[i] = new_type;
			all_change(i);
			cnt++;

			new_type = next_animal(map[i]);
			map[i] = new_type;
			all_change(i);
			cnt++;

			solve(i + 1, cnt);

			copy_arr(local_map, map);

	}
}

void main(void)
{
	input();
//	solve(0, 0);
//	printf("%d\n", MIN_COUNT);

	//debugging
	/*
	printf("%c", next_animal('B'));
	printf("%c", next_animal('C'));
	printf("%c", next_animal('D'));
	printf("%c", next_animal('E'));


	for (int i = 0; i <= 15; i++)
	{
		all_change(i);
	}
	*/
}
