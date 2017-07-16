//창훈 직접품 최종 풀이 및 필기
//필기 노트의 알고리즘을 본다.




//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#include<stdio.h>

int N;
int K;

void input()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	//scanf("%d",&N);
	//scanf("%d",&K);
}

int f(int n, int k,int first)
{

//결과는 내 Base하고 교재 Base가 같음.
#if 1   // 창훈 Base
	if(k==K) return 1;
	if(first &&  n > N-1) return 0;
	if(!first && n > N ) return 0;
#else   //교재 Base
   if( n >= N+1 || k==K)
   {
	   return (int)( k==K && (!first || n <= N+1) );
   }
#endif

	return f(n+1,k,first) + f(n+2,k+1,first); // 처음을 선택 안했을때 + 처음을 선택했을때
}

void main(void)
{
    	input();

	 // N (4<=n<=1,000)
	//  K (1<=k<=n)

	for(int i=4;i<20;i++)
    for(int j=1;j<20;j++)
	{
		printf("n:%d k:%d=",i,j);		
		N=i;
		K=j;
		printf("%d\n",f(2,0,0) + f(3,1,1));
	}
}

//////////////////////////////////////

#include<stdio.h>
#define MOD 1000000003

int N;
int K;

int DT[1000][1000][2];

int f(int n, int k,int first)
{
	if(DT[n][k][first]!=-1) return DT[n][k][first]%MOD ;
	
	if(k==0) return DT[n][k][first]=1%MOD;
	else if(first && N-2 < n) return DT[n][k][first]=0%MOD;  // 여기를 선택할 수 있게 해줘야함. base 위치 다시한번 생각해보자. N-2 <= n 이렇게 생각해서 답이 안나옴
		 if(!first && N-1 < n) return DT[n][k][first]=0%MOD; // 여기를 선택할 수 있게 해줘야함. N-1<=n 이렇게 생각해서 답이 안나옴
	
	//아래 점화식 루틴에 의해서
	return DT[n][k][first]=(f(n+2,k-1,first)+f(n+1,k,first))%MOD;
}

void main()
{
	N=5;
	K=2;
	
	for(int i=0;i<1000;i++)
		for(int j=0;j<1000;j++)
			for(int p=0;p<2;p++)
				DT[i][j][p]=-1;
	
	//아래 두가지 경우에서 부터 시작한다.
	int result1=f(2,K-1,1); //제일 처음을 선택한다는 것은 2로 점프하고(0부터 시작함으로), 선택해야될 수를 하나 줄이고 , 처음을 표시한다. 
	int result2=f(1,K,0);   //제일 처음을 선택 안한다는 것은 1로 점프호고 그냥 K를 내리고 처음이 아닌것을 표시함.
	printf("%d",(result1+result2)%MOD);
}








//교재 알고리즘
#include<stdio.h>

int N;
int K;

void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d",&N);
	scanf("%d",&K);
}

int f(int n, int k,int first)
{
	printf("n:%d k:%d first:%d\n",n,k,first);


   if( n >= N+1 || k==K)
   {
	   return (int)( k==K && (!first || n <= N+1) ); // 아직도 first처리는 이렇게 되는게 와벽하게 이해가 되지 않음.
   }


	return f(n+1,k,first) + f(n+2,k+1,first); // 처음을 선택 안했을때 + 처음을 선택했을때
}

void main(void)
{
	input();
	//(4<=n<=1,000), (1<=k<=n)

	printf("%d",f(2,0,0) + f(3,1,1));

}





