// 숫자 게임 , 기출 문제
// 81057 일때 답이 17  이 풀이 정답 나옴 ㅠㅠ, 실제 난 시험에서 15가 나옴, 뭘 잘못했지???;;
// 247 이 있다고 하면
// 이 아이의 후보군은 2*47  , 24 *7 , 2 * 4* 7 .... 이렇게 내려가서 자리수가 1일때까지가 나온다.
// 이때 가장길게 터치한 횟수는 얼마 인가?

// 배열계산과 백트래킹을 응용할수 있는 좋은 문제이다.



//창훈 최종 풀이 및 정답
//문자로 변형하면 시간 안에 풀수가 없다. 
//숫자를 가지고 놀데, 길이를 구하고, 모듈러와 나누기를 적당히 이용해서 후보군을 쪼개야한다. 깔끔하게 후보군을 쪼갤수 없다면 조건문을 적절히 사용해서 쪼개라.
//마지막 Base조건 처리도 주의하도록  , 마지막 후보군 실수햇다. 그래서 답이 17이 아니라 16이 나옴.!!!

















//테이블 없이 작성함.

#include<stdio.h>

long long DIGIT=81057;


int getLength(long long digit)
{
	int count=1;

	while(digit=digit/10)
	{
		count++;
	}

	return count;
}


int MAX_PUSH=0;
void solve(long long digit,int k)
{
	int length=getLength(digit);
	if(length==1)
	{
		if(MAX_PUSH < k) MAX_PUSH=k;
		return;
	}
	else if(length==2)
	{
		long long a=digit/10; 
		long long b=digit%10;

		solve(a*b,k+1);
	}else
	{
		
		int div=1;

		for(int i=1;i<=length;i++)
		{
			
			if(i==1)
			{
			  long long a;
			  long long b=digit;
			  long long result=1;

     		   while(b)
			   {
		     	  a=b%10;
			      b=b/10;
				  result=result*a;
			   }

			   solve(result,k+1);
			}
			else
			{
				div=div*10;
				long long a=digit/div;
				long long b=digit%div;
				
				solve(a*b,k+1);
			}

			
		}
	}

}

void main(void)
{
	solve(DIGIT,0);
	printf("%d\n",MAX_PUSH);

}

//////////////////////////////////




//창훈 깔끔하게 잘 풀었다. 이걸 외우듯이 해라.
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int N=81057; 

int carray[]={0,
	         1, //1
			 10, //2                   
			 100, //3
			 1000, //4
			 10000, //5
			 100000, //6
			 1000000, //7
			 10000000, //8
			 100000000, //9
			 1000000000 //10
};

int getSize(int digit)
{
	int count=0;
	while(digit)
	{
		digit=digit/10;
		count++;
	}
	return count;
}


void input()
{
 freopen("input.txt","r",stdin);
}

int max_len=-987654321;
void f(int digit,int len)
{

if(digit<=9)
{
	if(max_len<len) max_len=len;

	return;
}

int size = getSize(digit);

for(int i=size;i>=1;i--)
{
	if(i==1)
	{
		int value=1;
		while(digit)
		{
			int temp=digit%10;
			value=value*temp;
			digit=digit/10;
		}

		f(value,len+1);

	}
	else
	{
		int a=digit/carray[i];
		int b=digit%carray[i];
		//printf("a:%d * b:%d => %d \n",a,b,a*b);
		f(a*b,len+1);
	}
}


}

void main()
{
f(N,0);
printf("%d",max_len);
}








//위에꺼만 보도록
//////////////////////////////////////////////////////////
//++
//이렇게 풀면 시간안에 풀수가 없다.
//숫자를 직접 처리해야한다.


#include<stdio.h>

char input[10];
int  input_len;
int max=0;

static int func_count;

int carrys[]={0,1,10,100,1000,10000,100000,1000000};

int getDigit(char a[],int l)
{
	int result=0;
	int index=0;

	for(int i=l;i>=1;i--)
	{
		  result=result+( (int)(a[index] - '0') * carrys[i] );
		  index++;
	}

	return result; 
}


int getLen(char a[])
{
	int i=0;
	
	while(a[i]!='\0')
	{
		i++;
	}
	
	return i;
}


void trimString(char a[],int l)
{

	char string[10]={'\0'};

	if(a[0] != '0') 
		{ 
			return; // don't care;
	     }

	int i=0;
	for(i=0;i<l;i++)
	{
		if(a[i]!='0') break; 
	}

	int j=0;
	for(int k=i;k<l;k++)
	{
		string[j]=a[k];
		j++;
	}


	for(int i=0;i<10;i++)
	{
		a[i]=string[i];
	}
}



int compute(char a[],int l,int p)
{
	int result=0;

	if(l==p)
	{
		int r=1;
		for(int i=0; i < l; i++ )
		{
			int digit = (int)(a[i] -'0');
			r=r * digit;
		}

		result=r;
	}
	else
	{
		char string1[10]={'\0'};
		char string2[10]={'\0'};

		for(int i=0; i<p;i++)
		string1[i]=a[i];

		int j=0;
		for(int i=p; i<l;i++)
		{
		 string2[j]=a[i];
		 j++;
		}

		//printf("string1 :  %s\n" ,string1);
		//printf("string2 :  %s\n" ,string2);

		trimString(string1,getLen(string1));  // 쪼개졌을때 0 이 있는 경우, 앞에 0을 없앤다.
		trimString(string2,getLen(string2));

		int digit1=getDigit(string1,getLen(string1));
		int digit2=getDigit(string2,getLen(string2));
		result=digit1 * digit2;
	}

	return result;

}

void changeString(char a[],int digit)
{

	if(digit==0) { a[0]='0'; return; } 


	int temp=digit;

	int count=0;
	while(temp)
	{
	  temp=temp/10;
	  count++;
	}
	
	int c=count-1;
	temp=digit;
	int value=0;
	while(temp)
	{

	    value=temp%10;
		a[c]=value+'0';
		temp=temp/10;
		c--;
	}

//	printf("digit string: %s \n" ,a );

}



void solve(char a[],int k,int l)
{
	
	int digit=getDigit(a,l);

	func_count++;

	if(l==1)
	{
		if(k>max) max=k;
		return;
	}

	for(int i=1;i<=l;i++)  // 중복이 있는 후보군이 있다. 이걸 처리하는 방법을 생각해보자.!!! 이거 처리해야 연산량 줄일수있다.
	{
		char string[10]={'\0'};
		int digit=compute(a,l,i);
		changeString(string,digit); 
	//	printf("k:%d - digit:%s \n",k,string);
		solve( string, k+1,getLen(string));
	}

}




void main()
{


	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	scanf("%s",&input);
	
	//input_len=getLen(input);
	
	//printf("input_len     : %d\n",input_len);
	//printf("input integer : %d\n", getDigit(input,input_len));
    //printf("input integer : %d\n", compute(input,input_len,3));

	//trimString(input,input_len);
	//printf("trimString : %s",input);

//	char string[10]={'\0'};
//	changeString(string,0);
//	printf("%s",string);

	solve(input,0,getLen(input));

	printf("func_count:%d \n",func_count);
	printf("max:%d\n",max);

	
}