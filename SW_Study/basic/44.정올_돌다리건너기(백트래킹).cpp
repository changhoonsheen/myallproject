//â�� ���� �ʱ�
//�ʱ� ���� ����

//��ȯ�� + DT ���̺� �����غ���

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
	//�Ǽ�!!! Ʈ���� �׷����� �Ǵ��Ѵ�.  int b_p, int p_p, int type ������ �մ�� �ֱ� ������
	//DT ���̺� ������ ���ؼ� �ʿ���.
	int current_b_p=b_p;
	int current_p_p=p_p;
	int current_type=type;
	
	if(DT[b_p][p_p][type]!=-1) return DT[b_p][p_p][type];
	
	if(paper[p_p]=='\0') //���� �Ǽ�!!
	{
		return DT[b_p][p_p][type]=1;
	}
	
	//Ʈ���� �׷�����, �����غ���, �󸶳� ���� �ĺ����� �������� ������,�� ���� ���ؼ� �÷����Ѵ�.
	int result=0;
	while(bridge[type][b_p]!='\0')
	{
		if(bridge[type][b_p]==paper[p_p])
		{
			if(type==D){result=solve(b_p+1,p_p+1,A)+result;}
			else       {result=solve(b_p+1,p_p+1,D)+result;}
		}
		
		b_p++;// ���� bp ������ current �������� �ʿ��ѰŴ�.
	}
	
	return DT[current_b_p][current_p_p][current_type]=result;
}

void main()
{
	input();
	
	for(int x=0;x<20;x++)
		for(int y=0;y<20;y++)  // ���� �ε��� 10�̶�� �Է�.!! �Ǽ�!!
			for(int z=0;z<2;z++)
				DT[x][y][z]=-1;
	
	int first=solve(0,0,D);
	int second=solve(0,0,A);
	
	printf("%d\n",first+second);
}








































//�Ʒ��� ����������
//++++++++++++++++++++++++++++++++++++++++++++++++++++
//////////////////////////////////////////////////////
/*
â��, ��ü�˻� Ǯ�� <����>

�Է�
ù° �ٿ��� 

������ �η縶���� ���� ���ڿ�(R, I, N, G, S�θ� ������)�� �־�����.
�� ���ڿ��� ���̴� �ּ� 2, �ִ� 10�̴�. 

�� ���� �� �ٿ��� ���� <�Ǹ��� ���ٸ�>
�� <õ���� ���ٸ�>�� ��Ÿ���� ���� ������ ���ڿ��� �־�����. �� ���̴� 5 �̻�,
20 �����̴�.

���
��� ���Ͽ� ������ �η縶���� ���� ���ڿ��� ������� �ٸ��� �ǳʰ� �� �ִ�
����� ���� ����Ѵ�. �׷��� ����� ������ 0�� ����Ѵ�. ��� �׽�Ʈ �����Ϳ�
���� ��°���� 2^31 - 1 �����̴�.

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
//â�� ����Ǯ�� ��Ǯ����.
//�Ź� �� ������ Base ������ �򰥸���.<�η縶���� ���� �ִ� ���ڿ��� ��� ��� �������°� ���� �����̴�.>
//������ �׸��� �׷�����, While�ȿ��� ���ȣ���� �̷�������Ѵ�. �׸��� ���� ���ڿ� ���̸� ������ �ʴ��� 
// null�μ� ���� �˼��� �ִ�. 
*/

//backtracking 1
#include<stdio.h>

char paper[100];
char bridge[2][100];

int solve_count;

//p�� �ٸ������� ��ġ, p_p ���� ���̱����� ��ġ, type�� ���Ÿ���� �ٸ��ΰ�?
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

//2. DT ���� ��ȯ�� �������� ����� �׸��� �ߺ��� Ȯ���ϰ� DT ���̺� ����

#include<stdio.h>

char paper[100];
char bridge[2][100];
int DT[100][100][2];


//p�� �ٸ������� ��ġ, p_p ���� ���̱����� ��ġ, type�� ���Ÿ���� �ٸ��ΰ�?
int f(int p,int p_p,int type)
{
	char ch=paper[p_p];

	if(DT[p][p_p][type] != -1) return DT[p][p_p][type];
	
	if(ch=='\0')
	{
		return DT[p][p_p][type]=1;
	}


	int value=0;
	int pos=p; // �Ǽ�!!!  while ������ ���� pos �̰� �����ؼ� �������Ѵ�. �򰥸�������.
	           // ������ ���� �׸� Ʈ�� �׸� �Ϻ��ϰ� �����ϰ� �м��ؾߵȴ�. �� p�� ��ġ�ϸ�ȴ�.
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






//���� ����� �����ϰ� �Ʒ� ������ Ǯ����. ����ϰ� ���� �� ����� �����Ѵ�.
///++++++++++++++++++++++++++++++++++++++++++++
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// â�� Ǯ�� ��ȯ�� �������� �����ϱ�
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
    if( brige[side][i] == c ) // ã�Ҵٸ� switching
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
// â�� Ǯ�� ��ȯ�� �������� �����ϱ�
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
		if( brige[side][i] == c ) // ã�Ҵٸ� switching
		{
		  int a=0;
		  int b=0;
		  
		  if(side==0)
			a=f(paper_index+1,i+1,1);  // switch toward angel bridge
		  else
			b=f(paper_index+1,i+1,0);  // switch toward devil bridge
		
		   result=result+a+b;  //  ������ ����ߵȴ�.!!  �̰� ���� �߿��ϴ�.!!!! Ʈ���� �׷�����!!!!!
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
// â�� Ǯ�� �� DT ���̺� �����غ��� 
// ���� �ߺ��� �ֳ�?  ��ȯ�� �������� �ٲ㺸��
// �̷����� ������ �ߺ��� �ݵ��� �ִ�.


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
		if( brige[side][i] == c ) // ã�Ҵٸ� switching
		{
		  int a=0;
		  int b=0;
		  
		  if(side==0)
			a=f(paper_index+1,i+1,1);  // switch toward angel bridge
		  else
			b=f(paper_index+1,i+1,0);  // switch toward devil bridge
		
		   DT[paper_index][bridge_index][side]=DT[paper_index][bridge_index][side]+a+b;  //  ������ ����ߵȴ�.!!  �̰� ���� �߿��ϴ�.!!!! Ʈ���� �׷�����!!!!! ���� �˰��� �������� �ٸ���!
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
// ���� Ǯ��   
// �� �˰����ϰ� ���귮�� �Ȱ���, ������ �Ȱ���.! �׳� ���� ������!!
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
			DT[dolnum][dolpos][rolpos]+=f(1-dolnum,i+1,rolpos+1); // ������ sum�� 
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
// ���� Ǯ��   
// DP�� ���߿� ���ô�.
//>>>>>>>>>>>>>>>>



