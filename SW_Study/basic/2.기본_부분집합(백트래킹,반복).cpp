
//창훈 최종
//노트 필기를 참조, 1. 반복문에 의한 방법, 2. Backtracking에 의한 방법을 알아 놓도록 

#include<stdio.h>

#define SIZE 4
int arr[SIZE]={10,20,30,40}; // 실재배열 

int a[SIZE];

void backtracking(int k)
{


if(k==SIZE)
{
	printf("{ ");
	for(int i=0;i<SIZE;i++)
	{
		if(a[i]) printf("%d ",arr[i]);
	}
	printf("}\n");
	return;
}


a[k]=0;
backtracking(k+1);

a[k]=1;
backtracking(k+1);

}

void main()
{
	backtracking(0);
}





/////////////////////////////////////////////////////////////////

//반복문을 이용
#include<stdio.h>

int a[5]={100,200,300,400,500};


void main()
{
	int n=sizeof(a)/sizeof(int);//배열의크기
	
	for(int i=0;i<(1<<n);i++)
	{
		printf("{ ")
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j)) printf("%d",a[j]);
		}
	    printf(" }")
		
	}
}


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//그림을 그려보면 이해가 쉬움
//backtracking

#include<stdio.h>

int DATA[5]={100,200,300,400,500};
static int count;

void solve(int a[] , int k , int n)
{

 if(k==n-1)
 {
	printf("%d : { ",count++); 
	 for(int i=0;i<n;i++)
	 {
		 if(a[i]==1)
		 printf(" %d",DATA[i]);
	 }
	printf(" }\n");
	
	return;
 }

 k++;
 
 a[k]=0;
 solve(a,k,n);

 a[k]=1;
 solve(a,k,n);

}

void main()
{
	int a[5]={0,};
	int n=sizeof(a)/sizeof(int);//배열의크기
	
	solve(a,-1,n);
	
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// 가지치기 
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#include<stdio.h>

int arr[]={1,2,3,4,5,6,7,8,9,10};

static int func_call;

void solve(int a[],int k, int n)
{

if(k==n-1)
{

	int sum=0;

	for(int i=0;i<n;i++)
	{
	  if(a[i]) {
				   // printf("	%d",i);
				   sum+=arr[i];
			   }
	}

	
	if(sum==10)
	{
	  printf("{ ");
	  for(int i=0;i<n;i++)
	  {
		if(a[i]) {
	    printf(" %d",arr[i]);
		}
	  }
	  printf(" }\n");
	}

return;
}

// 부분합 가지치기 
#if 1  // 이렇게 가능한 이유는 양수만 존재하기 때문이다.
    int temp_sum=0;
	for(int i=0;i<k;i++)  // a 배열은 전역 배열이기 때문에 n 까지 계산하면 쓰레기가 들어 간다. 
	{                     // 이 부분 실수했다. <순열에서도 현재 a 배열의 길이인 k를 이용했었다.>
		if(a[i]) { 
				   // printf("	%d",i);
				   temp_sum+=arr[i];
			   }
	}

	if(temp_sum > 11) return;  // 10을 통과 시켜야한다.
#endif


func_call++;


k++;
a[k]=0;
solve(a,k,n);  // 실수 k+1;

a[k]=1;
solve(a,k,n);


}

void main()
{
 int a[10]={0};
 int n=10;


 solve(a,-1,n);
 printf("func_call : %d \n",func_call);

}