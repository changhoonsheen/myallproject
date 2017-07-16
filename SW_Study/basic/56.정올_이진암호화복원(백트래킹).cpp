
/*
창훈 하루만에 풀었다.
이제 이 문제는 니꺼다. ㅎㅎ 
너무 어렵지만 잘했음.^________________________^
*/

#include<stdio.h>

int n;
char digits[100];
char out[100];

void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	scanf("%s",&digits);
}

int k=0;
void solve(int s, int len)
{

	if(digits[k]=='\0')
	{
		return;
	}

	char data=digits[k++];

	if('-'==data) //'-'는 쪼개야되며,
	{
		solve(s,len/2);
		solve(s+len/2,len/2);
	
	}
	else
	{
		for(int i=s;i<s+len;i++)
		{
			out[i]=data; //해당 데이터로 채운다.
		}
	}

}

void main()
{
	input();
	solve(0,n);
	printf("%s",out);
}






































//++++++++++++++++++++++++++++++++++++++++++++++


//이진 암호 복원
//못품 
/*
8
00111101

4
0000

4
1101

*/

//////////
// 창훈 직접품
/////////

#include<stdio.h>

char str[1<<19];
int N;
char ans[1<<19];

int P; // 문자열을 컨트롤 하는 글로벌 포인터


void solve(int s, int len)
{
	char ch=str[P++]; //읽자 마자, 한번 증가시킴, 여기가 하이라이트임

	printf("P:%d\n",P);

	if(ch=='\0') return; // 입력의 끝이라면 바닥이다.

	if(ch=='-') // - 이면 분할을 시작함.
	{
		solve(s,len/2);
		solve(s+len/2,len/2);
	}
	else //그 자리가 숫자면 해당 영역을 해당 숫자로 채운다.
	{
		for(int i=s;i<s+len;i++)
		{
			ans[i]=ch;
		}
	}
}

void main()
{
	freopen("input.txt","r",stdin);
	scanf("%d",&N);
	scanf("%s",str);

	solve(0,N);

	printf("%s",ans);
}












/////////////////////////////////////////////

#include<stdio.h>

char arr[1<<10];
char str[1<<10];

int n;
int p;

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

	char val = arr[p];
	p++;

	if(val=='\0') return;

	if(val=='-')
	{
		solve(s,w/2);       // 너비의 1/2 로 관계를 유지하면서 바닥까지 내려간다. 
	    solve(s+(w/2),w/2); // 결과가 들어갈 배열 
	}
	else  // 결과가 들어갈 배열을 여기서 채운다. 
	{
		for(int i=s; i < s+w ; i++ )
		{
		   str[i]=val;
		}

	}
}


void main()
{

	freopen("input.txt","r",stdin);

	scanf("%d",&n);
	
	scanf("%s",&arr);

	solve(0,n);

	printf("input:%s\n",arr);
    printf("result:%s\n",str);
}
