
//창훈 최종 필기 풀이
//영역 나누기와 흡사하기에 별탈이 없다.
//그런데 복구하는게 문제다....

#include<stdio.h>

int n;
char digits[1<<18];

void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	scanf("%s",&digits);
}

int check(int s, int len)
{
	char temp=digits[s];
	for(int i=s;i<s+len;i++)
	{
		if(temp!=digits[i]) return 0;
	}

	return 1;
}

void solve(int s, int len)
{
#if 0  //굳이 필요 없는 조건 1 일때 여기서 Base 처리 할필요 없음. 아래 조건에서 걸러진다. 
	if(len==1)
	{
		printf("%c",digits[s]);
		return;
	}
#endif

	if(check(s,len)==1)
	{
		printf("%c",digits[s]);
		return;
	}

	printf("-");
	solve(s,len/2);
	solve(s+len/2,len/2);
}

void main()
{
	input();
	solve(0,n);
}







//////////////////////////////////////


/*
8
00111101

4
0000

4
1101

*/



#include<stdio.h>

int n;
char digits[1<<18];

void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	scanf("%s",&digits);
}

int check(int s, int len)
{
	char temp=digits[s];
	for(int i=s;i<s+len;i++)
	{
		if(temp!=digits[i]) return 0;
	}

	return 1;
}

void solve(int s, int len)
{
	if(len==1)
	{
		printf("%c",digits[s]);
		return;
	}

	if(check(s,len)==1)
	{
		printf("%c",digits[s]);
		return;
	}

	printf("-");
	solve(s,len/2);
	solve(s+len/2,len/2);
}

void main()
{
	input();
	solve(0,n);
}

//+++++++++++++++++++++++++++++++++++++++++++++++
////////////////////////////////////////////////////

//창훈 최종품
///////////////

#include<stdio.h>

char str[1<<19]; //2^19
int N;



int check(int k, int n, char *c)
{
	
 *c=str[k];

 for(int i=k;i<k+n;i++)
 {
	 if(*c != str[i]) return 1;
 }
 
 return 0;
}

void solve(int p, int len)
{
	char c;
	
	if(check(p,len,&c)) // 분할된 영역이 같은 숫자로 되어 있지 않다면.
	{
		printf("-");
		solve(p,len/2);
		solve(p+len/2,len/2);
	}
	else // 분할된 영역이 같은 숫자로 되어 있다면.
	{
		printf("%c",c);
	}
}


void main()
{
  freopen("input.txt","r",stdin);
  scanf("%d",&N);
  scanf("%s",str);
  
  solve(0,N);
}

/////////
//과거엔 너무 어렵게 풀었다.
////////

#include<stdio.h>

char arr[1<<10];
int n;


int check(int s, int e , int &c)
{
	c=arr[s];
	for(int i=s+1 ; i < e ; i++ )
	{
		if(c!=arr[i]) return -1;
	}

	return 1;
}


void solve(int s,int w)
{
	int c;

	if(w==1) 
	{
	  printf("%c",arr[s]);
	  return;
	}

	if(check(s,s+w,c)==1)
	{
		printf("%c",c);
		return;
	}

	printf("-");
	solve(s,w/2);  // 너비의 1/2 로 관계를 유지하면서 바닥까지 내려간다. 
	solve(s+(w/2),w/2);
}


void main()
{

	freopen("input.txt","r",stdin);

	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%s",&arr);
	}


	int s=0;
	int e=n;
	int c=0;
	if(check(s,e,c)==1)
	{
		printf("%c",c);
		return;
	}

	solve(0,e-s);
	
}
