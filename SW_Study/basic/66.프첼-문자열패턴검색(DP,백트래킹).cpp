/*
Page.290
1.backtracking 전체 검색에 대한 풀이
*/


#include<stdio.h>

#define MATCH 0
#define INSERT 1
#define DELETE 2

int match(char c, char d)
{
	if(c == d) return 0;
	else return 1;
}

int indel(char c)
{
	return 1;
}


int string_compare(char *s, char *t, int i, int j)
{
	int opt[3]={0,};       //세 옵션의 비용,
	                  //[0] - 매치 또는 틀렸을때 비용 매치되면 0 비용 필요 없음, 틀리면(치환시 비용) 1
					  //[1] - 삽입시 비용 , 1
					  //[2] - 삭제시 비용 , 1
					  
	int lowest_cost=987654321;  //최저 비용

	//printf("i:%d j:%d\n",i,j);
	
	//base 처리
	//중요, 두개의 문자열에 대한 처리임으로 base가 두개여야함!
	if(i==0) return(j * indel(' ')); //남아 있는 j에 대한 삭제에 대한 비용
	if(j==0) return(i * indel(' '));


	opt[MATCH]  = string_compare(s,t,i-1,j-1) + match(s[i],t[j]);
	opt[INSERT] = string_compare(s,t,i,j-1) + indel(t[j]);
	opt[DELETE] = string_compare(s,t,i-1,j) + indel(s[i]);
		
	//3개의 연산중 제일 작은 값을 찾는다	
	for(int k=MATCH ; k<=DELETE;k++)
	if(opt[k] < lowest_cost) lowest_cost=opt[k];

	return lowest_cost;
}


int main(void)
{
	char *s=" Thou"; //첫번째 0번 인덱스는 사용하지 않는다.
	char *t=" ABou"; //첫번째 0번 인덱스는 사용하지 않는다.

	int result = string_compare(s,t,4,4);
	printf("result:%d\n",result);
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


/*
DT 테이블
*/


#include<stdio.h>

#define MATCH 0
#define INSERT 1
#define DELETE 2

struct RESULT{
	int cost;
	int parent;
};


RESULT DT[20][20];

int match(char c, char d)
{
	if (c == d) return 0;    //MATH 
	else return 1;           //SUBS 교체     
}

int indel(char c)
{
	return 1;  // Insert 혹은 Delete
}


int string_compare(char *s, char *t, int i, int j)
{
	int opt[3] = { 0, };       //세 옵션의 비용,
	//[0] - 매치 또는 틀렸을때 비용 매치되면 0 비용 필요 없음, 틀리면(치환시 비용) 1
	//[1] - 삽입시 비용 , 1
	//[2] - 삭제시 비용 , 1

	int selected = 0;

	if (DT[i][j].cost != -1) return DT[i][j].cost;

	int lowest_cost = 987654321;  //최저 비용

	//printf("i:%d j:%d\n",i,j);

	//base 처리
	//중요, 두개의 문자열에 대한 처리임으로 base가 두개여야함!
	if (i == 0) return(j * indel(' ')); //남아 있는 j에 대한 삭제에 대한 비용
	if (j == 0) return(i * indel(' '));


	opt[MATCH] = string_compare(s, t, i - 1, j - 1) + match(s[i], t[j]);  // 매치이거나 교체 이거나.
	opt[INSERT] = string_compare(s, t, i, j - 1) + indel(t[j]);
	opt[DELETE] = string_compare(s, t, i - 1, j) + indel(s[i]);

	//3개의 연산중 제일 작은 값을 찾는다	
	for (int k = MATCH; k <= DELETE; k++)
		if (opt[k] < lowest_cost){
			lowest_cost = opt[k];
			selected = k;
		}

	DT[i][j].parent = selected;

	return DT[i][j].cost=lowest_cost;
}

void reconstruct_path(char *s, char *t, int i, int j)
{

	if (DT[i][j].parent == -1) return;

	if (DT[i][j].parent == MATCH)
	{
		reconstruct_path(s, t, i - 1, j - 1);

		if (s[i] == t[j]) printf("M");
		else printf("S");

		return;
	}

	if (DT[i][j].parent == INSERT)
	{
		reconstruct_path(s, t, i , j - 1);
		printf("I");
		return;
	}

	if (DT[i][j].parent == DELETE)
	{
		reconstruct_path(s, t, i-1, j);
		printf("D");
		return;
	}
}


void row_init(int i)
{
	DT[0][i].cost = i;

	if (i > 0) DT[0][i].parent = INSERT;
	else DT[0][i].parent = -1;
}

void column_init(int i)
{
	DT[i][0].cost = i;

	if (i > 0) DT[i][0].parent = DELETE;
	else DT[i][0].parent = -1;
}

void display()
{
	// 무엇을 선택했는지를 나타내는 parent
	printf("selected method\n");
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			printf(" %d", DT[i][j].parent);
		}
		printf("\n");
	}

	printf("\n\n");

	//실제 비용
	printf("selected cost\n");
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			printf(" %d", DT[i][j].cost);
		}
		printf("\n");
	}

}

int main(void)
{
	#define MAX_LENGTH 20

	char s[MAX_LENGTH] = " thou shalt not";  // 이 문자열을 아래 문자열로 바꿈.
	char t[MAX_LENGTH] = " you should not";
	int str_len = 14;

	for (int i = 0; i < MAX_LENGTH; i++)
	for (int j = 0; j < MAX_LENGTH; j++)
	{
		DT[i][j].cost = -1;
		DT[i][j].parent = -1;
	}

	//중요! display()테이블을 보고 원리를 따져 봐라. source -> target으로 문자가 변할때 
	//이해할수 있다.
	for (int i = 0; i<MAX_LENGTH; i++) {
		row_init(i);
		column_init(i);
	}

	int result = string_compare(s, t, str_len, str_len);

	//결과 
	printf("result:%d\n", result);
	//display();  // cost 매트릭스 와 parent 매트릭스를 출력함.
	reconstruct_path(s, t, str_len, str_len);
}

