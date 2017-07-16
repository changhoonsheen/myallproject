
//â�� ���� �ʱ� Ǯ��
//���� ������� ����ϱ⿡ ��Ż�� ����.
//�׷��� �����ϴ°� ������....

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
#if 0  //���� �ʿ� ���� ���� 1 �϶� ���⼭ Base ó�� ���ʿ� ����. �Ʒ� ���ǿ��� �ɷ�����. 
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

//â�� ����ǰ
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
	
	if(check(p,len,&c)) // ���ҵ� ������ ���� ���ڷ� �Ǿ� ���� �ʴٸ�.
	{
		printf("-");
		solve(p,len/2);
		solve(p+len/2,len/2);
	}
	else // ���ҵ� ������ ���� ���ڷ� �Ǿ� �ִٸ�.
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
//���ſ� �ʹ� ��ư� Ǯ����.
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
	solve(s,w/2);  // �ʺ��� 1/2 �� ���踦 �����ϸ鼭 �ٴڱ��� ��������. 
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
