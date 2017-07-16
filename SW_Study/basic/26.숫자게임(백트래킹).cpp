// ���� ���� , ���� ����
// 81057 �϶� ���� 17  �� Ǯ�� ���� ���� �Ф�, ���� �� ���迡�� 15�� ����, �� �߸�����???;;
// 247 �� �ִٰ� �ϸ�
// �� ������ �ĺ����� 2*47  , 24 *7 , 2 * 4* 7 .... �̷��� �������� �ڸ����� 1�϶������� ���´�.
// �̶� ������ ��ġ�� Ƚ���� �� �ΰ�?

// �迭���� ��Ʈ��ŷ�� �����Ҽ� �ִ� ���� �����̴�.



//â�� ���� Ǯ�� �� ����
//���ڷ� �����ϸ� �ð� �ȿ� Ǯ���� ����. 
//���ڸ� ������ �, ���̸� ���ϰ�, ��ⷯ�� �����⸦ ������ �̿��ؼ� �ĺ����� �ɰ����Ѵ�. ����ϰ� �ĺ����� �ɰ��� ���ٸ� ���ǹ��� ������ ����ؼ� �ɰ���.
//������ Base���� ó���� �����ϵ���  , ������ �ĺ��� �Ǽ��޴�. �׷��� ���� 17�� �ƴ϶� 16�� ����.!!!

















//���̺� ���� �ۼ���.

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




//â�� ����ϰ� �� Ǯ����. �̰� �ܿ���� �ض�.
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








//�������� ������
//////////////////////////////////////////////////////////
//++
//�̷��� Ǯ�� �ð��ȿ� Ǯ���� ����.
//���ڸ� ���� ó���ؾ��Ѵ�.


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

		trimString(string1,getLen(string1));  // �ɰ������� 0 �� �ִ� ���, �տ� 0�� ���ش�.
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

	for(int i=1;i<=l;i++)  // �ߺ��� �ִ� �ĺ����� �ִ�. �̰� ó���ϴ� ����� �����غ���.!!! �̰� ó���ؾ� ���귮 ���ϼ��ִ�.
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