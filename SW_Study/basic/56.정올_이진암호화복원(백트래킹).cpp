
/*
â�� �Ϸ縸�� Ǯ����.
���� �� ������ �ϲ���. ���� 
�ʹ� ������� ������.^________________________^
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

	if('-'==data) //'-'�� �ɰ��ߵǸ�,
	{
		solve(s,len/2);
		solve(s+len/2,len/2);
	
	}
	else
	{
		for(int i=s;i<s+len;i++)
		{
			out[i]=data; //�ش� �����ͷ� ä���.
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


//���� ��ȣ ����
//��ǰ 
/*
8
00111101

4
0000

4
1101

*/

//////////
// â�� ����ǰ
/////////

#include<stdio.h>

char str[1<<19];
int N;
char ans[1<<19];

int P; // ���ڿ��� ��Ʈ�� �ϴ� �۷ι� ������


void solve(int s, int len)
{
	char ch=str[P++]; //���� ����, �ѹ� ������Ŵ, ���Ⱑ ���̶���Ʈ��

	printf("P:%d\n",P);

	if(ch=='\0') return; // �Է��� ���̶�� �ٴ��̴�.

	if(ch=='-') // - �̸� ������ ������.
	{
		solve(s,len/2);
		solve(s+len/2,len/2);
	}
	else //�� �ڸ��� ���ڸ� �ش� ������ �ش� ���ڷ� ä���.
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
		solve(s,w/2);       // �ʺ��� 1/2 �� ���踦 �����ϸ鼭 �ٴڱ��� ��������. 
	    solve(s+(w/2),w/2); // ����� �� �迭 
	}
	else  // ����� �� �迭�� ���⼭ ä���. 
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
