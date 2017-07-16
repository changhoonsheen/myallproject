

//>>
// 창훈 최종 , 
// 노트의 알고리즘을 머리속에 그려볼 수 있어야 한다.<최종 부분만 외우고 공부하면됨.>

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int arr[100000];
int N;

////////////////////
void select_sort()
{
	for(int i=0;i<N;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			if(arr[i]>arr[j])
			{
				int temp;
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}


///////////////////
//삽입정렬
///////////////////

void swap(int *a, int *b)
{
	int temp=*a;
	*a = *b;
	*b = temp;
}

void insert_sort()
{
	for (int i = 0; i < N; i++)
	{
		int j = i;
		while (j > 0 && arr[j - 1] > arr[j])
		{
			swap(&arr[j - 1], &arr[j]);
			j--;
		}
	}
}




/*
삽입정렬을 이용한 간단한 우선순위큐

다이젝트라,프림알고리즘에서 사용되지만,(선택되지 않은것중 제일 작은것)
우린 Check 배열과 최소값 찾기로 대치될수 있다.


*/

#include<stdio.h>

int f = -1;
int r = -1;

int N = 10;
int arr[100];


int dequeue()
{
	if (f == r) { printf("empty\n");  return -1; }

	f++;
	return arr[f];
}


void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


void enqueue(int ele)
{

	r++;
	arr[r] = ele;

//	for (int i = f; i < r; i++)  // Q가 공집합에서 하나씩 늘어가는 구조기에. 여기 for는 필요가 없다. 실수!! 이거 하면 이상하게 결과 나옴
//	{
		int j = r;
		while (j > f+1 && arr[j - 1] > arr[j])  //(j>0  ->  j>f+1)-1부터 시작함으로  ,삽입정렬으로 부터
		{
			swap(&arr[j - 1], &arr[j]);
			j--;
		}
//	}

}




void main()
{

	enqueue(1);
	enqueue(5);
	enqueue(2);
	enqueue(4);
	enqueue(3);


	printf("de : %d\n", dequeue());
	printf("de : %d\n", dequeue());
	printf("de : %d\n", dequeue());

	enqueue(3);
	enqueue(2);
	enqueue(1);


	printf("de : %d\n", dequeue());
	printf("de : %d\n", dequeue());
	printf("de : %d\n", dequeue());


}




///////////////////
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// 버블정렬 문제 해결 - 창훈풀이 
// 그림을 그려 보자. 
// 1.버블이 교차해서 비교가 되고 마지막에 제일 큰수가 옮겨진다.
// 2.제일 마지막꺼는 정렬이된 상태니깐 이 값을 제외하고 제일 처음부터 다시 시작한다.
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void bubble_sort()
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j< N-i-1;j++)  // N-i-1  이건 그려봐야지 실수 안한다.마지막에 0이 들어감.
		{
			if(arr[j] > arr[j+1]) // 버블
			{
				int temp;
				temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
///////////////////

void swap(int *a, int *b)
{
	int temp;

	temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int l , int r)
{
	int pivot=arr[l];
	int i=l;
	int j=r;

	while(i<=j)
	{
		while(arr[i]<=pivot){ i++; if(i==r) break;} //실수!!  그려보자. 그려 보면 실수 안한다.
		while(arr[j]>=pivot){ j--; if(j==l) break;}

		if(i<j) swap(&arr[i],&arr[j]);
	}

	swap(&arr[l],&arr[j]);

	return j;
}

void quick_sort(int l, int r)
{
	if(l<r)
	{
		int s=partition(l,r);
		quick_sort(l,s-1);
		quick_sort(s+1,r);
	}
}
///////////////////
void main()
{
	scanf("%d",&N);	

	int start;

	//+++
	srand(time(NULL));
	for(int i=0;i<N;i++)
	{
		arr[i]=rand();
	}

	start=clock();
	select_sort();
	printf("select sort : %f sec\n",(double)(clock()-start)/CLOCKS_PER_SEC);

	//+++

	srand(time(NULL));
	for(int i=0;i<N;i++)
	{
		arr[i]=rand();
	}

	start=clock();
	bubble_sort();
	printf("bubble sort : %f sec\n",(double)(clock()-start)/CLOCKS_PER_SEC);

	//+++

	srand(time(NULL));
	for(int i=0;i<N;i++)
	{
		arr[i]=rand();
	}
	start=clock();
	quick_sort(0,N-1);
	printf("quick sort : %f sec\n",(double)(clock()-start)/CLOCKS_PER_SEC);

}















///////////////////////////////////////////////////////////

#include<stdio.h>
#include<ctime>    //시간 관련
#include<stdlib.h> //난수 관련

int arr[100000];
int N;

void main()
{

	scanf("%d",&N);
   	
    srand(time(NULL));
	for(int i=0; i<N;i++)
	{
		arr[i]=rand();
	}

	int start = clock();
    //>> 여기서 알고리즘 시작


	//<< 여기서 알고리즘 종료
    printf("%.3lf sec\n",(double)(clock()-start)/CLOCKS_PER_SEC  );
}




























//////////////////
//이전에 정렬 알고리즘 공부했던것.
/*
Quick sort 알고리즘
스토리텔링 : 피봇을 기준으로 왼쪽이 작은것 , 오른쪽이 큰것이며 
Quicksort와 parition 함수로 나눠진다. 

Quicksort가 l가 r을 넘어 설때까지 진행을한다. Quicksort내부는 두개로 쪼개진다. logn을 시간 복잡도를가진다.


partion 함수는 while이 3개로 이뤄지다. (전체 while하나, left에서 움직일 while , right 쪽에서 움직일 while)

일반적으로 
왼쪽은 피봇 보다 작은 값을 위치시킴, 피봇 보다 큰값이 나오면 스톱
오른쪽은 일반적으로 피봇 보다 큰값임으로  피봇 보다 작은값이 나오면  스톱 
찾은값 swap


종료시 
전체 while 을  i,j가 넘어설때까지 찾는다. 넘어서면 종료하는것이다.
이때 넘어서 j 와 피봇(a[l])을 swap한다.
*/


 //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// 최종 문제 해결 - 창훈풀이 
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//오름차순 
//선택 정렬은 10만건 정렬시 약 0.03 초가 나옴.


#include<stdio.h>
#include<ctime>
#include<stdlib.h>

int arr[100000];
int N;

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int partion(int a[],int l, int r)
{
	int p=a[l];
	int i=l;
	int j=r;
	
	while(i<=j) //넘어 설때까지
	{ 
		while(a[i]<=p){ i++; if(i==r) break;} //오름차순 일때이다.  내림차순으로 변경하고 싶으면  a[i]>=p
		while(a[j]>=p){ j--; if(j==l) break;} //오름차순 일때이다.  내림차순으로 변경하고 싶으면  a[j]<=p
		
		if(i<j) swap(&a[i],&a[j]); // 거짓이 될때까지 찾은거고 교환해주는게 합당하다.
	}
	swap(&a[l],&a[j]); // cross 될때 ,종료되고, 피봇을 옮긴다.
	
	return j;
}

void quicksort(int a[],int l, int r)
{
 if(l<r)
 {
	int s=partion(a,l,r);
	quicksort(a,l,s-1);
	quicksort(a,s+1,r);
 }
}

void main()
{
	
scanf("%d",&N);
   	
    srand(time(NULL));
	for(int i=0; i<N;i++)
	{
		arr[i]=rand();
	}

	int start = clock();
    //>> 여기서 알고리즘 시작

	quicksort(arr,0,N);	// 배열, 배열의 제일 작은 인덱스 , 제일 큰 인덱스 
	
	//<< 여기서 알고리즘 종료
    printf("%.3lf sec\n",(double)(clock()-start)/CLOCKS_PER_SEC  );

}


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// 선택정렬 문제 해결 - 창훈풀이 
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//선택 정렬은 10만건 정렬시 약 30초가 나옴.


#include<stdio.h>
#include<ctime>
#include<stdlib.h>

int arr[100000];
int N;


void main()
{
//	int arr[5]={5,4,3,2,1};
	//int N=5;

	scanf("%d",&N);
   	
    srand(time(NULL));
	for(int i=0; i<N;i++)
	{
		arr[i]=rand();
	}

	
	int start = clock();
    

	for(int i=0;i<N;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			if(arr[i] > arr[j])
			{
				int temp= arr[i];
				arr[i] =arr[j];
				arr[j] = temp;
			}
		}
	}

	printf("%.3lf sec\n",(double)(clock()-start)/CLOCKS_PER_SEC  );  //%f로 출력해도 상관없다. 더 길게 나올뿐.

}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// 버블정렬 문제 해결 - 창훈풀이 
// 그림을 그려 보자. 
// 1.버블이 교차해서 비교가 되고 마지막에 제일 큰수가 옮겨진다.
// 2.제일 마지막꺼는 정렬이된 상태니깐 이 값을 제외하고 제일 처음부터 다시 시작한다.
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void main()
{
	int arr[10]={10,9,8,7,6,5,4,3,2,1};
	int N=10;

	for(int i=0;i<N-1;i++)  
	{
		for(int j=0;j<(N-1)-i;j++)
		{
			if(arr[j] > arr[j+1])
			{
				int temp= arr[j];
				arr[j] =arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
