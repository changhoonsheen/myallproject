

// 창훈 최종 필기방법
// 창훈 품.
// 이진 트리를 만들고 이진트리를 엑세스 하는 평이한 문제임.


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

scanf("%d ",&n); // 입력에 스페이스가 있어야한다.여기 실수

for(int i=0;i<n;i++)
{
	char code[10]={0};
    char c;

	scanf("%c %s ",&c,&code); // 입력에 스페이스가 있어야한다.여기 실수 

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


//Tip! : 2진 트리를 1차원 배열로 표현할 수 있다. 
창훈품 2진트리 만드는 힌트는 참고함.!


*/

#include<stdio.h>

int n;  // 글자수 

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
		if(*code=='0')  n=2*n;  // 왼쪽
		else n=2*n+1;  // 오른쪽
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
	  scanf("\n%c %s",&arr[i].c,&arr[i].code);	  // 여기 개행이 중요함.
//	  printf("%c %s\n",arr[i].c,arr[i].code);     // 제대로 입력 받는지 확인함.
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
		if(encoded_string[k]=='0')  index=2*index;  // 왼쪽
		else index=2*index+1;  // 오른쪽
		
		if(tree[index]!=0) 
		{
			printf("%c",tree[index]);
			index=1;
		}			
		
	 k++;
	}
}




