
// 창훈 최종풀이 아래 두 풀이 결과는 동일하다.
// 조합 풀이 방식은 아래 두개의 방법이 있다. 참조해라.
// 상수결과를 얻는 방법도 Overflow가 발생한다. 그래서 unsigned _int64 로 표현해한다.

#include <cstdio>
int func_call;

unsigned _int64 f(int n, int k) 
{
	func_call++;

	if(k==n) return 1;  
	else if(k==1) return n;  
	else return f(n,k-1)*(n-k+1)/k; 
}

int main() 
{  
	int n, k;  
	scanf("%d %d", &n, &k);   
	printf("%I64d\n", f(n,k));    // 이렇게 표현하는것 외워둔다.
	printf("func_call:%d\n", func_call);   
	return 0; 
}



//점화식에의해서 아래와 같이 풀어도 된다.
//이때 주의할것은 제일 큰수로 잡는거다. 64비트 int 로 잡는것이다.
//아래 3개의 조합이 값이 정상적으로 나오는지 확인해봐라.
/*
55 C 30
34 C 16
33 C 16
*/

#include<stdio.h>

int n;  
int k; 

unsigned _int64 DT[500][500];

int func_count;

 unsigned _int64 solve(int n, int k)
{
	unsigned _int64 temp;

	if(DT[n][k]==-1)
	{		
		func_count++;
		if(n==k)  temp=1;
		else if(k==1) temp=n;
		else temp=solve(n-1,k-1) + solve(n-1,k);	
	}
	else 
	{
		temp=DT[n][k];
	}
	
	printf("%d C %d = %I64d\n",n,k,temp);
	return DT[n][k]=temp;
}


void main()
{
	freopen("output.txt","w",stdout);

	for(int i=1;i<500;i++)
	for(int j=1;j<500;j++)
	{
		DT[i][j]=-1;
	}
		
	scanf("%d %d",&n,&k);
	printf("%I64d\n",solve(n,k));
	printf("func_count : %d\n", func_count);

}



////////////
//로또 선택된 수 출력하기
////////////

#include<stdio.h>

int an[]={1,2,3};
int tr[2]; // 전역으로 빼야지 값을 유지하고 있다. 

int n=3; //3개중 2개를 선택할때 경우의 수
int k=2;
int K=k;

void solve(int n, int k)
{
	if(k==0) //Base 수식의 정의, 선택을 다했을때
	{
		printf("{ ");
		for(int i=0;i<K;i++)
		printf("%d ",tr[i]);
		printf("}\n");
		return;
	}
	
	if(n<k) return; //정의 위반
	
	tr[k-1]=an[n-1];
	solve(n-1,k-1);
	solve(n-1,k);
}


void main()
{
	solve(n,k);
}


























//아래는 옛날 풀이다. 보지말도록 위의 두식만 분석해도된다.
//+++++++++++++++++++++++++++++
//////////////





































/*

일반화와 관계식.

f(n,k) = n! / k! (n-k)!
..
f(n-1,k-1) = (n-1)! / (k-1)! ( n-k-2 ) !
..
f(1,1)=1

아래 공식에 의해서 조합을 풀어도됨.

*/
//>>>>>>>>>>>>>>>>>>>>>>>

#include<stdio.h>

int n;
int k;

int fa(int i)
{
	if(i==1) return 1;
	return fa(i-1)*i;
}

int f(int n, int k)
{

return  fa(n)  / fa(k) * fa(n-k) ;

}


void main()
{	
	//freopen("input.txt", "r", stdin);
	
	scanf("%d %d",&n,&k);
	printf("%d",f(n,k));
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//교재 풀이 
// 50C5 만해도 위의 방식은 overflow가 발생함.
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//팩토리얼 계산을 피하기위한 방법

#include <cstdio>
int f(int n, int k)
{
if(k==n) return 1;
else if(k==1) return n;
else return f(n-1,k-1)+f(n-1,k);
}
int main()
{
int n, k;
scanf("%d %d", &n, &k);
printf("%d\n", f(n,k));
return 0;
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// 최종 교제 풀어 직관적으로 풀이한 방법
#include <cstdio>
int f(int n, int k)
{
if(k==n) return 1;
else if(k==1) return n;
else return f(n,k-1)*(n-k+1)/k;
}
int main()
{
int n, k;
scanf("%d %d", &n, &k);
printf("%d\n", f(n,k));
return 0;
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// 조합식을 점화식으로 유도해서 풀이한 방법

// >>>>>>>>>>>>>>>>
// DP로 구하기  교재 90 page
 
#include<stdio.h>

int DT[30][30];

void main()
{	
	int n;
	int k;
	
	scanf("%d %d",&n,&k);
	
	for(int i=1; i<=n ; i++)
		for(int j=1; j<=k && j<=i ; j++)
	{
		if(i==j) DT[i][j]=1;
		else if(j==1) DT[i][j]=i;
        else DT[i][j]=DT[i-1][j-1] + DT[i-1][j];
	}	
	
    printf("%d",DT[i][j]);
}

///////////////////////////////////////////////////////////
//창훈  최종 분석 풀이
///////////////////////////////////////////////////////////



#include<stdio.h>


static int func_count=0;

//n개의 물건중 k개를 고르는 경우의 수

int f(int n,int k)
{
func_count++;
if(n==k) return 1;
if(k==1) return n;
return f(n-1,k-1)+f(n-1,k);
}


static int new_func_count=0;

int DT[60][60];

int new_f(int n,int k)
{
new_func_count++;

if(DT[n][k] == -1)
{
	if(n==k) return DT[n][k]=1;
	else if(k==1) return DT[n][k]=n;
	else return DT[n][k]=new_f(n-1,k-1)+new_f(n-1,k);
}
else return DT[n][k];

}



void main()
{
int n=50;
int c=5;


printf("%d\n",f(n,c));	
printf("func_count:%d\n",func_count);
printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

for(int i=0;i<60;i++)
for(int j=0;j<60;j++)
{
	DT[i][j]=-1;
}
printf("DT Table -  %d\n",new_f(n,c));	
printf("DT Table -  new_func_count:%d\n",new_func_count);

}









