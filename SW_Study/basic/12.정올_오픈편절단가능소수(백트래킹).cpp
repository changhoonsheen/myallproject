//창훈 최종 출이





#include<stdio.h>

int K;
int count;


//이부분 외우 도록 
//2 3 5 7 
int isPrime(int v)
{
	if(v<2) return 0;
	if(v==2) return 1; 
	if(v%2==0) return 0;   // 이미 알고 있는 부분 2를 제외 하고 모든 소수는 홀수임,

	for(int i=2;i*i<=v;i++)  //=이 들어가야함.
	{
		if(v%i==0) return 0;
	}

	return 1;
}

int old_isPrime(int v)
{
	if(v<2) return 0;
	if(v==2) return 1; 
	if(v%2==0) return 0;   // 이미 알고 있는 부분 2를 제외 하고 모든 소수는 홀수임,

	for(int i=2;i<v;i++)  //=이 없어야함. 그냥 생각으로 짜면 이걸 작성한다.
	{
		if(v%i==0) return 0; // 소수가 아닌조건 
	}

	return 1;
}



void solve(int i , int k)
{

	if(k==K)
	{
		printf("%d\n",i);
		count++;
		return ;
	}

	for(int j=0;j<10;j++)
	{
		int value =i*10+j;
		if(isPrime(value))  // 후보군 만들기 
		{
			solve(value,k+1);
		}
	}

}

void main()
{

	scanf("%d",&K);
	solve(2,1);
	solve(3,1);
	solve(5,1);
	solve(7,1);

	printf("%d",count);
}



























//교재응용풀이.
////////////////
#include<stdio.h>

int N;
int count;

int isPrime(int v)
{
	if(v<2) return 0;

	for(int i=2;i*i<=v;i++)
	{
	  if(v%i==0) return 0;
	}

	return 1;
}

void f(int num , int i)
{
	if(i==N)
	{
		if(isPrime(num))
		{
			printf("%d\n",num);
			count++;
		}
		return;
	}

	if(!isPrime(num)) return;

	f(num*10+1,i+1); //1
	f(num*10+3,i+1); //3
	f(num*10+5,i+1); //5 //난 짝수만 없앤다.
	f(num*10+7,i+1); //7
	f(num*10+9,i+1); //9
	
}

void main()
{
	scanf("%d",&N);

	f(2,1); // 마지막 짤랐을때 2,3,5,7 만 소수다.
	f(3,1);
	f(5,1);
	f(7,1);
	printf("%d\n",count);
}
















//아래껀 가능 참조하도록
///////////////////////////////////////////////////////

//소수적어 보기
//2,3,5,7,11...

#include<stdio.h>

int isprime1(int x)
{
	if(x<2) return 0; //1은 소수가 아님

	for(int i=2;i<x;i++)  // = 이 없다.
	{
		if(x%i==0) return 0;
	}

	return 1;
}


int isprime2(int x)
{
	if(x<2) return 0;

    //X가 합성수라면 X는 a*b 형태가 되므로
	//(a>1&& b>1) a와b둘중 하나는 sqrt(X)보다
	//작거나 같음을 알수 있다. 그러므로 2부터 sqrt(X)까지 나눠보고
	//나눠지지 않는다면 N은 소수다. sqrt을 없애기 위해서 양쪽에 거듭제곱을 함.
	for(int i=2; i*i<=x; i++)  // = 이 있다. 즉관적으로 안 와 닫는다 외워라.
	{
	  if(x%i==0){return 0;}
	}

	return 1;
}

int main()
{
    printf("%d",isprime1(i));
    printf("%d",isprime2(i));
}


/////////////////////

3 -> 14 개 
4 -> 16 개
5 -> 15 개 
7 -> 8개 (힘들게 나옴)
8 -> 결과 안나옴

//가지치기 들어가야됨. 그리고 
//반복문으로 풀어보기
#include<stdio.h>

int digit;
int start;
int end;

int isPrime(int n)
{
	if(n<2) return 0;

	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0) return 0;
	}

	return 1;
}


int f(int value)
{
	while(value)
	{
		if(!isPrime(value)) return 0;
		value=value/10;
	}

	return 1;
}



void main()
{
	scanf("%d",&digit);

	end=1;
	for(int i=1;i<=digit;i++)
	end*=10;

	start=end/10;
	//printf("start:%d end:%d\n",start,end);

	int cnt=0;
	for(int i=start;i<end;i++)
	{
		if(f(i)) {
		cnt++;
		printf("%d\n",i);
		}
	}

	printf("%d\n",cnt);
}


/////////////////////////////////////
#include<stdio.h>
int n, cnt;
int isprime(int x)
{
	if(x<2) return 0;

	for(int i=2; i*i<=x; i++)
	if(x%i==0) return 0;

	return 1;
}

void f(int num, int len)
{
	if(len==n)
	{
		if(num==0) return ;
		int flag=1;
		int temp=num;
		
		while(temp)
		{
			if(!isprime(temp))
			return ;
			temp /= 10;
		}
		
		cnt++;
		printf("%d\n", num);
		return ;
	}
	else
	{
		for(int i=1; i<=9; i++)
			f(num*10+i, len+1);
	}
}
int main()
{
scanf("%d", &n);
f(0, 0);
printf("%d", cnt);
}