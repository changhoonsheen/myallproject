

// â�� ���� �ʱ���
// â�� ǰ.
// ���� Ʈ���� ����� ����Ʈ���� ������ �ϴ� ������ ������.


/*
5
A 00
B 01
C 10
D 110
E 111
00000101111
*/

#include<stdio.h>

char tree[50];
char input[50];

int getindex(char *s)
{
	int pos=1;
	while(*s!='\0')
	{
		if(*s=='0') pos = pos*2;
		else pos = pos*2+1;		
		s++;
	}

	return pos;
}


void main()
{
int n;
freopen("input.txt","r",stdin);

scanf("%d ",&n); // �Է¿� �����̽��� �־���Ѵ�.���� �Ǽ�

for(int i=0;i<n;i++)
{
	char code[10]={0};
    char c;

	scanf("%c %s ",&c,&code); // �Է¿� �����̽��� �־���Ѵ�.���� �Ǽ� 

	int pos=getindex(code);
	tree[pos]=c;
}

scanf("%s",&input);


int pos=1;
int index=0;

while(input[index]!='\0')
{
	char c=input[index];
	
	if(c=='0') pos = pos*2; 
	else pos = pos*2+1;

	if(tree[pos]!='\0')
	{
		printf("%c",tree[pos]);
		pos=1;
	}

	index++;
}

}















////////////////////////////////////////////////


/*
5
A 00
B 01
C 10
D 110
E 111
00000101111


//Tip! : 2�� Ʈ���� 1���� �迭�� ǥ���� �� �ִ�. 
â��ǰ 2��Ʈ�� ����� ��Ʈ�� ������.!


*/

#include<stdio.h>

int n;  // ���ڼ� 

struct ele
{
	char c;
	char code[20];
};

ele arr[100];
char encoded_string[100];

char tree[100];


int gettreeindex(char *code)
{
	int index=0;
	int n=1;
	
	while(*code!='\0')
	{
		if(*code=='0')  n=2*n;  // ����
		else n=2*n+1;  // ������
		code++;
	}	
	
	return n;
}

void maketree(char c, char *code)
{
  int index=gettreeindex(code);
  tree[index]=c;
}


void main(void)
{

	freopen("input.txt", "r", stdin);
	scanf("%d",&n);

	for(int i=0; i<n ; i++)
	{
	  scanf("\n%c %s",&arr[i].c,&arr[i].code);	  // ���� ������ �߿���.
//	  printf("%c %s\n",arr[i].c,arr[i].code);     // ����� �Է� �޴��� Ȯ����.
	}
	scanf("%s",&encoded_string);

	for(int i=0; i<n ; i++)
	{
	  maketree(arr[i].c,arr[i].code);
	}
	
	
	int index=1;
	int k=0;
	while( encoded_string[k] != '\0' )
	{
		if(encoded_string[k]=='0')  index=2*index;  // ����
		else index=2*index+1;  // ������
		
		if(tree[index]!=0) 
		{
			printf("%c",tree[index]);
			index=1;
		}			
		
	 k++;
	}
}




