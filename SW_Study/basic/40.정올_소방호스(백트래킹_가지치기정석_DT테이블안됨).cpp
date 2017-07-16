
/*

3 2
12 50 81
27 73

23


>>>>>>>>>>>>>>>>>>>>>>>>>



7 6
12 50 81 100 200 300 400
27 73 75 90 100 120

334

*/

//창훈 최종 필기
//알고리즘 
#include<stdio.h>

int p;// pump의 갯수
int f;// 소방차 대수

int p_arr[20]; //펌프위치
int f_arr[20]; //소방차 위치

int pump_chk[20];
int min_length=987654321;

int func_call;

int abs(int a)
{
	return a>0 ? a : a*(-1);
}

int getlength(int a,int b)
{
	return abs(a-b);
}

int greedy()
{
	int selected_pump[20]={0};
	int greedy_length=0;

	for(int i=1;i<=f;i++)
	{
		int temp=987654321;
		int s=0;

		for(int j=1;j<=p;j++)
		{
			if(selected_pump[j]==0)
			{
				int l=getlength(p_arr[j],f_arr[i]);
				if(temp>l){temp=l;s=j;}
			}
		}
		selected_pump[s]=1;
		greedy_length=greedy_length+temp;
	}
	return greedy_length;
}

void solve(int car, int length)
{
	if(length > min_length) return;
	func_call++;

	if(car==f+1) // 여기 등호 자꾸 실수 한다.
	{
		if(min_length>length) min_length=length;
		return;
	}

	for(int i=1;i<=p;i++)
	{
		if(pump_chk[i]==0)
		{
			pump_chk[i]=1;
			int l=getlength(p_arr[i],f_arr[car]);
			solve(car+1,length+l);
			pump_chk[i]=0;
		}
	}	
}

void main()
{
	freopen("input.txt","r",stdin);
	scanf("%d %d",&p,&f);

	for(int i=1;i<=p;i++)
	scanf("%d",&p_arr[i]);

	for(int i=1;i<=f;i++)
	scanf("%d",&f_arr[i]);


	min_length=greedy(); // 데이터가 커지면 성능향상될듯.
	solve(1,0);

	printf("min_length:%d\n",min_length);
	printf("func_call:%d",func_call);
}















//++ 아래 풀이는 보지 말도록
///////////////////////////////////////////////////////








//>>
//  이렇게 풀면 답이 아니다.!!!
//  tree를 그려보고 생각을 하자.!
//  펌프<->소방차 간의 최소의 거리가 각각 나온다. 
//  이때 문제는 하나를 선택했을때 다른 하나도 고려를 해야한다는 것이다.
// 
//  두번째 풀때도 구조화 시키는게 문제인데.. 난 비선행 탐색에 따른 구조화를 못했음...?까? 
//  소방차가 깊이로 내려갈때 펌프의 갯수는 후보군이 된다. 이때 선택되어진 펌프는 선택이 안된다.
//  
//<<

#include<stdio.h>


int h;
int c;

int h_array[20];
int c_array[20];

int h_checked[20];
int c_checked[20];

int sum;

int abs(int a)
{
	if(a<0) return a*(-1);
	else return a;
}

int allConnected()
{
for(int i=0; i < c ; i++)
if(c_checked[i]==0) return 0;

return 1;
	
}

void main()
{

freopen("input.txt","r",stdin);

scanf("%d %d",&h,&c);

for(int i=1; i <= h ; i++)
scanf("%d",&h_array[i]);

for(int i=1; i <= c ; i++)
scanf("%d",&c_array[i]);

while(!allConnected())
{
	int shortpath=0xfffff;
	int shortpath_h=0;
	int shortpath_c=0;
	
	for(int i=1; i <= h ; i++)
	{
		if(h_checked[i]==1) continue;
			
		for(int j=1; j <= c ; j++)
		{
			if(c_checked[j]==1) continue;
			
			int temp =abs(h_array[i]-c_array[j]);
			
			printf("pump :%d ,firecar : %d, length:%d \n",i,j,temp);
			
			if ( shortpath > temp){ 
			shortpath=temp;
			shortpath_h=i;
			shortpath_c=j;
			}		
		}	
	}

	h_checked[shortpath_h]=1;
	c_checked[shortpath_c]=1;
	
	sum+=shortpath;
}	

printf("%d",sum);

}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// 창훈 교재 방법으로 품.  트리를 그려보고 결정한다.
// 선택된것을 이후 하위 트리에서 안 선택되게 하는게 중요함.
/*
3 2
12 50 81
27 73
*/
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#include<stdio.h>

int p;
int c;
int p_array[20];
int c_array[20];

int checked[20];

int shortestmin=0xfffff;

int abs(int a)
{
	if(a<0) return a*(-1);
	else return a;
}

int min(int a, int b)
{
	return a>b ? b : a ;
}


void solve(int pump , int car , int l)
{
	int length;
	
	if(car == c+1)
	{
		shortestmin=min(shortestmin,l);
		printf("pump:%d, car:%d length:%d \n",pump,car,l);
		return;
	}
	
	for(int i=1; i <= p ; i++)
	{
		if( checked[i] == 0 )
		{
			checked[i]=1;
			length=abs(c_array[car]-p_array[i]);
			solve(i,car+1,l+length);
			checked[i]=0;
		}
	}
	
}


void main()
{

freopen("input.txt","r",stdin);

scanf("%d %d",&p,&c);

for(int i=1; i <= p ; i++)
scanf("%d",&p_array[i]);

for(int i=1; i <= c ; i++)
scanf("%d",&c_array[i]);


solve(0,1,0);
 
printf("ans : %d \n",shortestmin);
}




// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//  교재 방법
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#include <stdio.h>
int p, f, pp[100001], fp[100000], pv[100001],mh=0x7fffffff;
int min(int a, int b)
{
return a>b ? b:a;
}
int abs(int a)
{
return a>0 ? a:-a;
}
void g(int pt, int ft, int h)
{
if(ft==f)
{
mh=min(mh, h);
return;
}
for(int i=1; i<=p; i++)
{
if(pv[i]==0)
{
pv[i]=1;
h+=abs(pp[i]-fp[ft+1]);
g(i, ft+1, h);            // 여기서 바로 더 해주면되는데..
h-=abs(pp[i]-fp[ft+1]);   // 왜 이렇게 풀었지.. 
pv[i]=0;
}
}
}
int main()
{
int i;
freopen("input.txt","r",stdin);
scanf("%d %d", &p, &f);
for(i=1; i<=p; i++)
scanf("%d", &pp[i]);
for(i=1; i<=f; i++)
scanf("%d", &fp[i]);
g(0,0,0);
printf("%d\n", mh);
return 0;
}	


////////////////////////
// hoony 최종 접근 
////////////////////////

#include<stdio.h>

int pump;
int pump_array[12];

int firecar;
int firecar_array[11];

int checked[12];

int min_length=0x7fffffff;

int abs(int a)
{
  if(a<0)  return a*(-1); 
  else return a;	
}


void solve(int p,int f,int l)
{
	
	if(f==firecar)
	{
	  if(min_length > l) min_length=l;
	  return;
	}
	
	for(int i=0;i<pump;i++)
	{
		if(checked[i]==0)
		{
			checked[i]=1;
			l+=abs(firecar_array[f]-pump_array[i]);
			solve(i,f+1,l);
			l-=abs(firecar_array[f]-pump_array[i]);
			checked[i]=0;
		}
		
	}
			
}

void input()
{
 scanf("%d %d",&pump,&firecar);

 for(int i=0;i<pump;i++)
 scanf("%d",&pump_array[i]);

 for(int j=0;j<firecar;j++)
 scanf("%d",&firecar_array[j]);
	
}

void main()
{
	 freopen("input.txt","r",stdin);
	input();
	solve(0,0,0);
	printf("%d",min_length);
}
