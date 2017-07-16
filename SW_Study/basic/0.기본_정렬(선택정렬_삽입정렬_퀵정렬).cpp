

//>>
// â�� ���� , 
// ��Ʈ�� �˰����� �Ӹ��ӿ� �׷��� �� �־�� �Ѵ�.<���� �κи� �ܿ�� �����ϸ��.>

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
//��������
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
���������� �̿��� ������ �켱����ť

������Ʈ��,�����˰��򿡼� ��������,(���õ��� �������� ���� ������)
�츰 Check �迭�� �ּҰ� ã��� ��ġ�ɼ� �ִ�.


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

//	for (int i = f; i < r; i++)  // Q�� �����տ��� �ϳ��� �þ�� �����⿡. ���� for�� �ʿ䰡 ����. �Ǽ�!! �̰� �ϸ� �̻��ϰ� ��� ����
//	{
		int j = r;
		while (j > f+1 && arr[j - 1] > arr[j])  //(j>0  ->  j>f+1)-1���� ����������  ,������������ ����
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
// �������� ���� �ذ� - â��Ǯ�� 
// �׸��� �׷� ����. 
// 1.������ �����ؼ� �񱳰� �ǰ� �������� ���� ū���� �Ű�����.
// 2.���� ���������� �����̵� ���´ϱ� �� ���� �����ϰ� ���� ó������ �ٽ� �����Ѵ�.
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void bubble_sort()
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j< N-i-1;j++)  // N-i-1  �̰� �׷������� �Ǽ� ���Ѵ�.�������� 0�� ��.
		{
			if(arr[j] > arr[j+1]) // ����
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
		while(arr[i]<=pivot){ i++; if(i==r) break;} //�Ǽ�!!  �׷�����. �׷� ���� �Ǽ� ���Ѵ�.
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
#include<ctime>    //�ð� ����
#include<stdlib.h> //���� ����

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
    //>> ���⼭ �˰��� ����


	//<< ���⼭ �˰��� ����
    printf("%.3lf sec\n",(double)(clock()-start)/CLOCKS_PER_SEC  );
}




























//////////////////
//������ ���� �˰��� �����ߴ���.
/*
Quick sort �˰���
���丮�ڸ� : �Ǻ��� �������� ������ ������ , �������� ū���̸� 
Quicksort�� parition �Լ��� ��������. 

Quicksort�� l�� r�� �Ѿ� �������� �������Ѵ�. Quicksort���δ� �ΰ��� �ɰ�����. logn�� �ð� ���⵵��������.


partion �Լ��� while�� 3���� �̷�����. (��ü while�ϳ�, left���� ������ while , right �ʿ��� ������ while)

�Ϲ������� 
������ �Ǻ� ���� ���� ���� ��ġ��Ŵ, �Ǻ� ���� ū���� ������ ����
�������� �Ϲ������� �Ǻ� ���� ū��������  �Ǻ� ���� �������� ������  ���� 
ã���� swap


����� 
��ü while ��  i,j�� �Ѿ������ ã�´�. �Ѿ�� �����ϴ°��̴�.
�̶� �Ѿ j �� �Ǻ�(a[l])�� swap�Ѵ�.
*/


 //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// ���� ���� �ذ� - â��Ǯ�� 
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//�������� 
//���� ������ 10���� ���Ľ� �� 0.03 �ʰ� ����.


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
	
	while(i<=j) //�Ѿ� ��������
	{ 
		while(a[i]<=p){ i++; if(i==r) break;} //�������� �϶��̴�.  ������������ �����ϰ� ������  a[i]>=p
		while(a[j]>=p){ j--; if(j==l) break;} //�������� �϶��̴�.  ������������ �����ϰ� ������  a[j]<=p
		
		if(i<j) swap(&a[i],&a[j]); // ������ �ɶ����� ã���Ű� ��ȯ���ִ°� �մ��ϴ�.
	}
	swap(&a[l],&a[j]); // cross �ɶ� ,����ǰ�, �Ǻ��� �ű��.
	
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
    //>> ���⼭ �˰��� ����

	quicksort(arr,0,N);	// �迭, �迭�� ���� ���� �ε��� , ���� ū �ε��� 
	
	//<< ���⼭ �˰��� ����
    printf("%.3lf sec\n",(double)(clock()-start)/CLOCKS_PER_SEC  );

}


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// �������� ���� �ذ� - â��Ǯ�� 
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//���� ������ 10���� ���Ľ� �� 30�ʰ� ����.


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

	printf("%.3lf sec\n",(double)(clock()-start)/CLOCKS_PER_SEC  );  //%f�� ����ص� �������. �� ��� ���û�.

}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// �������� ���� �ذ� - â��Ǯ�� 
// �׸��� �׷� ����. 
// 1.������ �����ؼ� �񱳰� �ǰ� �������� ���� ū���� �Ű�����.
// 2.���� ���������� �����̵� ���´ϱ� �� ���� �����ϰ� ���� ó������ �ٽ� �����Ѵ�.
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
