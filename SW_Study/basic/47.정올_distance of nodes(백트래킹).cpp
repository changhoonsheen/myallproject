/*
다음과 같이 노드에 번호가 부여된 이진트리가 있다. 이 트리는 단말 노드를 제외
한 모든 노드들이 2개의 자식을 가지며, 모든 단말노드의 높이가 같다.
두 노드 간의 거리는 한 노드에서 다른 노드로 이동할 때 거치는 간선의 수의 합
을 의미한다. 예를 들어 노드 5와 노드 3의 거리는 3이다.
임의의 두 노드가 주어질 때, 두 노드 간의 거리를 구하는 프로그램을 작성하시오.
입력
첫 번째 줄에 두 노드의 번호가 공백으로 구분되어 입력된다.
(단, 두 노드의 값은 1이상 2,100,000,000 이하의 값이다.)

5 2 1
3 1


 800232000
 2100000000
*/
//////////////////>
// 창훈 풀이 
//////////////////>
#include<stdio.h>



int first_node[1000];
int second_node[1000];

int a;
int b;

void f(int n,int arr[])
{
  int i=0;
  arr[i]=n;
  
  while(n!=1)	  
  {
	 n=n/2;
	 i++;
	 arr[i]=n;
  }
 
}

/*
5 2 1

3 1
*/
int getdistance(int arr1[],int arr2[])
{
	int i=0;
	int j=0;

	for(i=0; arr1[i]!=0 ; i++)
	{
		int v=arr1[i];
		
		for(j=0; arr2[j]!=0 ; j++)
		{
			if(v==arr2[j]) 
			{
			  printf("bingo");	
			  return i+j;  // 여기 실수했음. break가 아님 이중 for loop를 빠져나가야됨.
			}	
		} 			
	}	

	return -1;
}
void main()
{	

 freopen("input.txt", "r", stdin);
 scanf("%d %d",&a,&b);
 
 f(a,first_node);
 f(b,second_node);
 
 printf("%d",getdistance(first_node,second_node));
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#include<stdio.h>

int aa;
int bb;

int f(int a,int b)
{
	if(a==b){ printf("a=b \n"); return 0;}
	if(b>a) { printf("b up\n"); return f(a,b/2)+1;}
	if(b<a) { printf("a up\n"); return f(a/2,b)+1;}
}

void main()
{	
 freopen("input.txt", "r", stdin);
 scanf("%d %d",&aa,&bb);
 printf("%d",f(aa,bb));
}



