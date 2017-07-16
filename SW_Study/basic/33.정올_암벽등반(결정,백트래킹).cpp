//â�� �ʱ� ����!!
//��Ʈ ������ 

#include<stdio.h>

int N;
int dx[4]={-1,0,1 ,0};
int dy[4]={ 0,1,0,-1};

int map[500][500];
int chk[500][500];

int abs(int a)
{
	return a < 0 ? a*(-1) : a;
}

int getAltitude(int a, int b)
{
	return abs(a-b);
}

//�ݵ�� �̷����� ������ Return �� �������� Ǯ���.
//���� ��û�� �Ǽ��� �Ͼ� ����.!!! ���������� ����ϰ� �Ǹ� ���� �� �ִ�.

int Doclimb(int x, int y, int H)
{
	int sum=0;
	
	for(int i=0;i<4;i++)
	{
		int new_x=x+dx[i];
		int new_y=y+dy[i];
		
		if( chk[new_x][new_y]==0 &&
		    getAltitude(map[x][y],map[new_x][new_y])<=H &&
		    ( new_x < N && new_y < N ) &&
			( new_x >=0 && new_y >=0 )
		  )
		  {
			chk[new_x][new_y]=1; // 
			sum=sum+Doclimb(new_x,new_y,H)+1;  // �ٴڿ��� �ö�鼭 ���ذ���.			
		  }
	}
	
	return sum;
}

int CanClimb(int H)
{
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			for(int x=0;x<N;x++)
			for(int y=0;y<N;y++)
			chk[x][y]=0;
		
			chk[i][j]=1;               //���� üũ�صΰ�
		    int area=Doclimb(i,j,H)+1; //�������� �ö� �ö� �ڱ��ڽŲ� �����ش�.
			
			if(area >= (int) N*N*3/4) return 1; //������.
		}
	return 0;	//���� ����.
}


void input()
{
	freopen("input.txt","r",stdin);
	
	scanf("%d",&N);
	
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	scanf("%d",&map[i][j]);		
}

void main()
{
	input();
	
	int lb=0;
	int ub=1000000;
	
#if 0  //�׽�Ʈ
	printf("%d",CanClimb(3));
#else
	while(lb<ub)
	{
		int m=(lb+ub-1)/2;
		if(CanClimb(m)) ub=m;
		else lb=m+1;
	}
	
	printf("%d",ub);
#endif
}






//++++++++++++++++++++++++++++++++++++++++++++++++++++++
///////////////////////////////////////////////////////////

/*
ó�� ���� �����̶� �� ���ذ� �ȵȴ�.  �Ž; ������. 


�ӱ��� �����ϴ� ����� ���ߴ� ����  �ӱ��� ���� ���ϴ� �� ���� ������ ����� �ش�.
�ӱ��� �����ϴ� ���� �� �� �� �ӱݿ��� ��� ���� �� ������?

*/



5 
9 9 9 3 3 
0 0 0 0 3 
0 9 9 3 3 
0 0 0 3 3 
9 0 0 9 3


//â�� ���� �� Ǯ����.
//�� ����߰�, ������ ������Ƽ� �� Ǯ�� ����.

#include <cstdio>

int N;

int map[500][500];
int chk[500][500];

//���� ���� �ٸ� �� �׻� �� ����� ����ؾߵȴ�.
int dx[]={-1, 0, 1, 0};
int dy[]={ 0, 1, 0,-1};

int abs(int a)
{
	return a<0 ? a*(-1) : a;
}

int getDiff(int a, int b)
{
	return abs( a - b);	
}

int max(int a, int b)
{

	return a > b ? a : b;
}

// �� �Լ��� ��ȯ�� ����
// �������� �������� ������ִ�.
int solve(int i, int j, int h)
{
	    int a=0;
		for(int k=0;k<4;k++)
		{
			int new_i=i+dx[k];  //���� �Ǽ� 
			int new_j=j+dy[k];

           if( new_i < N && new_j < N && new_i >=0 && new_j >=0 ) 
		   {
			    int d=getDiff( map[i][j] , map[new_i][new_j]);
				if( d <= h && !chk[new_i][new_j])
				{
					chk[new_i][new_j]=1;
					a=a+solve(new_i, new_j, h)+1;
				}			
		   }
		}			
		return a;
}

int f(int h) 
{  
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	{		
	    for(int x=0;x<N;x++)
		for(int y=0;y<N;y++)
			chk[x][y]=0;
		
		int area=0;
		chk[i][j]=1;
		
		//printf("i:%d,j:%d ",i,j);		
		area=solve(i,j,h)+1;
		//printf("- area:%d\n",area);
		
		if(area >= (int)N*N*3/4) return 1;
	}

	return 0;
}


int main() {  

	int lb,ub,m;
	lb=0;
	ub=0;
	//ub=1000000; // ub�� ������ �ִ� ���̷� �ϸ�ȴ�.

	freopen("input.txt","r",stdin);
	
	scanf("%d",&N);

	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	{
		scanf("%d",&map[i][j]);
		ub=max(ub,map[i][j]);
	}


	while(lb<ub)
	{
		m = (lb+ub-1)/2;

		if(f(m)) ub=m;
		else lb=m+1;
	}

	printf("result : %d\n" , ub);

    return 0; 
}









////////////////////////////////////////////////////////////


#include<stdio.h>
#define SOL 81  // �ӱ��� ���� �ϴ� �� 


int f(int x)
{
 //return (SOL >= x) ;
   return (x <= SOL) ;
}



int main()
{
//	freopen("output.txt","w",stdout);


int lb=0,ub=100 , m;

while(lb < ub) // ���Ѱ� �� ������ �Ѿ� ���� ������.
{
  m =(lb + ub -1 ) /2;  // ���� ������ ���ǰ� ���� �Ǹ� -1 
  if(f(m)) ub =m;  // ���� ����. �������� �մ����� �����Ѵ�.
  else lb=m+1; // ���� ������ ���ǰ� ���� �Ǹ� +1
  
  printf("lb:%d m:%d ub:%d\n",lb,m,ub);
}
 printf("%d\n",ub);

}

////////////
//�Ϻ���� ���� 
////////////

////////////
//â��ǰ
////////////

#include<stdio.h>

int n;

int map[500][500];
int checked[500][500];

int dx[4]={-1,0,1, 0};
int dy[4]={ 0,1,0,-1};


int can(int x, int y)
{
 return (0<=x && x<n ) && (0<=y && y<n) ;
}

int abs(int a)
{
 return a < 0 ? (-1)* a : a;
}


int getArea(int x ,int y, int h)
{
  checked[x][y]=1; // ó�� ������ ��� 
  int area=1;  // ó�� ������ ��ҵ� �ϳ� ī��Ʈ 

  for(int i=0;i<4;i++)
  {
      if(
	   checked[x+dx[i]][y+dy[i]]==0 &&
	   can(x+dx[i],y+dy[i]) &&
	   h >=abs(map[x+dx[i]][y+dy[i]]-map[x][y])
	   )
	   {
		   checked[x+dx[i]][y+dy[i]]=1;
		   area+=getArea(x+dx[i],y+dy[i],h);  // ���� �������� ���� ������ �������� �̰� 		                                      
		                                      // ������ �ؾ���!!! Ʋ�ȴ�. ���ؼ� �������� �ߴ�. 
	  }
  }
 
  return area;  // area�� ������ ������ ������ �̰� �м�����.
}

void clearhistory()
{
 for(int i=0; i<n;i++)  
 for(int j=0; j<n;j++)
 {
  checked[i][j]=0;
 }
}

//�����̰� int 
int f(int h)
{

 int current_area=0;
 int cond = (n * n) * 3/4;  /// ���� ���� �ؾ��Ѵ�. !!! �߸��ϸ� 0�� ���´�

 
 for(int i=0; i<n;i++)  // ���� ��� ��ġ���� ��� ��Ű�� 
 for(int j=0; j<n;j++)
 {
     clearhistory();
     current_area=getArea(i,j,h);
//	 printf("start: i:%d , j:%d  current area :%d\n", i, j ,current_area);

	if(cond <= current_area)  return 1;
 }

	return 0;
}


int ub=-987654321;
int lb;

void main()
{
		
 freopen("input.txt","r",stdin);

 scanf("%d",&n);
 
 for(int i=0; i< n ; i++)
 for(int j=0; j< n ; j++)
 {
  scanf("%d",&map[i][j]);
  if(ub<=map[i][j]) ub=map[i][j];
 }

/*
  //test;
  for(i=0; i<=9;i++)
  {
   printf("health %d  pass: %d \n",i, f(i));
  }
*/


while(lb<ub)
{
 int m = (ub+lb-1)/2;
 if(f(m)) ub=m;  // �̰� �����Ǹ� , �Ʒ� �� +1, -1�� ���Ҽ� ���� 
 else lb=m+1 ;
}
 
printf("%d",ub);

}


