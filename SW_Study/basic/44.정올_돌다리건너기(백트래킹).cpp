//창훈 최종 필기
//필기 내용 참조

//반환값 + DT 테이블 적용해보기

#include<stdio.h>

#define D 0
#define A 1

char paper[10];
char bridge[2][20];

int DT[20][10][2];

void input()
{
	freopen("input.txt","r",stdin);
	
	scanf("%s",paper);
	scanf("%s",&bridge[0]);
	scanf("%s",&bridge[1]);
}

int solve(int b_p, int p_p, int type)
{
	//실수!!! 트리를 그려보고 판단한다.  int b_p, int p_p, int type 값들을 손대고 있기 때문에
	//DT 테이블 구축을 위해서 필요함.
	int current_b_p=b_p;
	int current_p_p=p_p;
	int current_type=type;
	
	if(DT[b_p][p_p][type]!=-1) return DT[b_p][p_p][type];
	
	if(paper[p_p]=='\0') //여기 실수!!
	{
		return DT[b_p][p_p][type]=1;
	}
	
	//트리를 그려보고, 생각해보자, 얼마나 많은 후보군이 나올지는 모르지만,이 값을 더해서 올려야한다.
	int result=0;
	while(bridge[type][b_p]!='\0')
	{
		if(bridge[type][b_p]==paper[p_p])
		{
			if(type==D){result=solve(b_p+1,p_p+1,A)+result;}
			else       {result=solve(b_p+1,p_p+1,D)+result;}
		}
		
		b_p++;// 여기 bp 때문에 current 변수들이 필요한거다.
	}
	
	return DT[current_b_p][current_p_p][current_type]=result;
}

void main()
{
	input();
	
	for(int x=0;x<20;x++)
		for(int y=0;y<20;y++)  // 여기 인덱스 10이라고 입력.!! 실수!!
			for(int z=0;z<2;z++)
				DT[x][y][z]=-1;
	
	int first=solve(0,0,D);
	int second=solve(0,0,A);
	
	printf("%d\n",first+second);
}








































//아래껀 보지말도록
//++++++++++++++++++++++++++++++++++++++++++++++++++++
//////////////////////////////////////////////////////
/*
창훈, 전체검색 풀기 <정답>

입력
첫째 줄에는 

마법의 두루마리에 적힌 문자열(R, I, N, G, S로만 구성된)이 주어진다.
이 문자열의 길이는 최소 2, 최대 10이다. 

그 다음 두 줄에는 각각 <악마의 돌다리>
와 <천사의 돌다리>를 나타내는 같은 길이의 문자열이 주어진다. 그 길이는 5 이상,
20 이하이다.

출력
출력 파일에 마법의 두루마리에 적힌 문자열의 순서대로 다리를 건너갈 수 있는
방법의 수를 출력한다. 그러한 방법이 없으면 0을 출력한다. 모든 테스트 데이터에
대한 출력결과는 2^31 - 1 이하이다.

RGS
RINGSR
GRGGNS

answer 3
fun count 11

>>>>>>>>>>>>>>>>>>


GG
GGGGRRRR
IIIIGGGG

answer 16
fun count 26
/*
>>>>
//창훈 최종풀이 잘풀었다.
//매번 이 문제는 Base 조건이 헷갈린다.<두루마리에 적혀 있는 문자열을 모두 밟고 지나가는게 도착 조건이다.>
//교재의 그림을 그려보자, While안에서 재귀호출이 이루어져야한다. 그리고 굳이 문자열 길이를 구하지 않더라도 
// null로서 끝을 알수가 있다. 
*/

//backtracking 1
#include<stdio.h>

char paper[100];
char bridge[2][100];

int solve_count;

//p는 다리에서의 위치, p_p 읽은 종이까지의 위치, type은 어느타입의 다리인가?
void f(int p,int p_p,int type)
{
	char ch=paper[p_p];
	int pos=p;
	
	if(ch=='\0')
	{
		solve_count++;
		return;
	}

	
	while(bridge[type][pos]!='\0')
	{
		if(ch == bridge[type][pos]) f(pos+1,p_p+1,type==1?0:1);
		pos++;
	}
}

void main()
{
	freopen("input.txt","r",stdin);
	
	scanf("%s",paper);
	scanf("%s",&bridge[0]);
	scanf("%s",&bridge[1]);
	
	f(0,0,0);
	f(0,0,1);
	
	printf("%d",solve_count);
}

//2. DT 적용 반환값 버젼으로 만들기 그리고 중복을 확인하고 DT 테이블 적용

#include<stdio.h>

char paper[100];
char bridge[2][100];
int DT[100][100][2];


//p는 다리에서의 위치, p_p 읽은 종이까지의 위치, type은 어느타입의 다리인가?
int f(int p,int p_p,int type)
{
	char ch=paper[p_p];

	if(DT[p][p_p][type] != -1) return DT[p][p_p][type];
	
	if(ch=='\0')
	{
		return DT[p][p_p][type]=1;
	}


	int value=0;
	int pos=p; // 실수!!!  while 루프를 돌릴 pos 이걸 복사해서 돌려야한다. 헷갈리지마라.
	           // 교재의 내가 그린 트리 그림 완벽하게 이해하고 분석해야된다. 즉 p를 터치하면된다.
	while(bridge[type][pos]!='\0')
	{
		if(ch == bridge[type][pos]) value = value + f(pos+1,p_p+1,type==1?0:1);
		pos++;
	}
	
	return DT[p][p_p][type]=value;
}

void main()
{
	freopen("input.txt","r",stdin);
	
	scanf("%s",paper);
	scanf("%s",&bridge[0]);
	scanf("%s",&bridge[1]);
	
	for(int x=0;x<100;x++)
	for(int y=0;y<100;y++)
	for(int z=0;z<2;z++)
	{
		DT[x][y][z]=-1;
	}

	printf("%d",f(0,0,0)+f(0,0,1));
}






//위의 방법과 동일하게 아래 문제도 풀었다. 깔끔하게 위의 두 방법만 공부한다.
///++++++++++++++++++++++++++++++++++++++++++++
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// 창훈 풀기 반환값 버젼으로 변경하기
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
/*
RGS
RINGSR
GRGGNS

answer 3
fun count 10

*/

#include<stdio.h>

char paper[10];
char brige[2][20];

int solution;
static int func_count;
void f(int paper_index, int bridge_index, int side)
{

   char c=paper[paper_index];
   int i=bridge_index;
   
   func_count++;
   
   if(c=='\0')
   {
	 solution++;
	 return;
   }

  while(brige[side][i]!='\0')
  {	  
    if( brige[side][i] == c ) // 찾았다면 switching
	{
	  if(side==0)
		f(paper_index+1,i+1,1);  // switch toward angel bridge
	  else
		f(paper_index+1,i+1,0);  // switch toward devil bridge
	}
	i++;
  }
 
}


void main()
{
	freopen("input.txt","r",stdin);
	scanf("%s", &paper);
	
	scanf("%s", &brige[0]); // devil bridge
	scanf("%s", &brige[1]); // angle bridge
	
	//int paper_index, int bridge_index, int side
	f(0,0,0);
	f(0,0,1);
	
	printf("%d\n",solution);
	printf("func_count : %d\n" ,func_count);
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// 창훈 풀기 반환값 버젼으로 변경하기
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


#include<stdio.h>

char paper[10];
char brige[2][20];

int DT[20][20][2];

int solution;
int  f(int paper_index, int bridge_index, int side)
{

	   char c=paper[paper_index];
	   int i=bridge_index;
	   
	   int result=0;
	   
	   if(c=='\0')
	   {
	     return 1;
	   }

	  while(brige[side][i]!='\0')
	  {	  
		if( brige[side][i] == c ) // 찾았다면 switching
		{
		  int a=0;
		  int b=0;
		  
		  if(side==0)
			a=f(paper_index+1,i+1,1);  // switch toward angel bridge
		  else
			b=f(paper_index+1,i+1,0);  // switch toward devil bridge
		
		   result=result+a+b;  //  누적을 해줘야된다.!!  이게 제일 중요하다.!!!! 트리를 그려봐라!!!!!
  		}
		i++;
	  }
  
   
   return result;
	 
}


void main()
{
	freopen("input.txt","r",stdin);
	scanf("%s", &paper);
	
	scanf("%s", &brige[0]); // devil bridge
	scanf("%s", &brige[1]); // angle bridge
	
	//int paper_index, int bridge_index, int side
	printf("%d",f(0,0,0)+f(0,0,1));
}


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// 창훈 풀기 로 DT 테이블 적용해보기 
// 과연 중복이 있나?  반환값 버젼으로 바꿔보기
// 이런류의 문제는 중복이 반듯이 있다.


GG
GGGGRRRR
IIIIGGGG

answer 16
fun count 14

>>>>


RGS
RINGSR
GRGGNS

answer 3
fun count 10


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#include<stdio.h>

char paper[10];
char brige[2][20];

int DT[20][20][2];

int solution;
static int func_count;
int  f(int paper_index, int bridge_index, int side)
{

	if(DT[paper_index][bridge_index][side]==0)
	{	
		func_count++;
	   char c=paper[paper_index];
	   int i=bridge_index;
	   
	   if(c=='\0')
	   {
	     return DT[paper_index][bridge_index][side]=1;
	   }

	  while(brige[side][i]!='\0')
	  {	  
		if( brige[side][i] == c ) // 찾았다면 switching
		{
		  int a=0;
		  int b=0;
		  
		  if(side==0)
			a=f(paper_index+1,i+1,1);  // switch toward angel bridge
		  else
			b=f(paper_index+1,i+1,0);  // switch toward devil bridge
		
		   DT[paper_index][bridge_index][side]=DT[paper_index][bridge_index][side]+a+b;  //  누적을 해줘야된다.!!  이게 제일 중요하다.!!!! 트리를 그려봐라!!!!! 교재 알고리즘 내꺼랑은 다른다!
  		}
		i++;
	  }
  
	}
   
   return DT[paper_index][bridge_index][side];
	 
}


void main()
{
	freopen("input.txt","r",stdin);
	scanf("%s", &paper);
	
	scanf("%s", &brige[0]); // devil bridge
	scanf("%s", &brige[1]); // angle bridge
	
	//int paper_index, int bridge_index, int side
	printf("answer:%d\n",f(0,0,0)+f(0,0,1));
	printf("func_count : %d\n" ,func_count);
}




//>>>>>>>>>>>>>>>>
// 교재 풀기   
// 내 알고리즘하고 연산량은 똑같음, 로직도 똑같음.! 그냥 내껄 보도록!!
//>>>>>>>>>>>>>>>>
/*
GG
GGGGRRRR
IIIIGGGG

answer 16
fun count 14

>>>>


RGS
RINGSR
GRGGNS

answer 3
fun count 10
*/
//>>>>>>>>>>>>>>>>
#include <stdio.h>
char rol[30], dol[2][120];
int DT[2][120][30];

static int func_count;

int f(int dolnum, int dolpos, int rolpos)
{
	if(DT[dolnum][dolpos][rolpos]==0)
	{
		func_count++;

		if(rol[rolpos]=='\0')
		DT[dolnum][dolpos][rolpos]=1;
	
		for(int i=dolpos; dol[1-dolnum][i]!='\0'; i++)
		{	
			if(dol[1-dolnum][i]==rol[rolpos])
			DT[dolnum][dolpos][rolpos]+=f(1-dolnum,i+1,rolpos+1); // 누적을 sum함 
		}
	}
	return DT[dolnum][dolpos][rolpos];
}
int main()
{
	freopen("input.txt","r",stdin);
	scanf("%s %s %s", rol, dol[0], dol[1]);
	printf("%d", f(0,0,0)+f(1,0,0));
		
	printf("func_count : %d\n" ,func_count);

	return 0;
}


//>>>>>>>>>>>>>>>>
// 교재 풀기   
// DP는 나중에 봅시다.
//>>>>>>>>>>>>>>>>



