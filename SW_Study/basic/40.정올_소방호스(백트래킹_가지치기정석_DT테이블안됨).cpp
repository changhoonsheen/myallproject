
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

//â�� ���� �ʱ�
//�˰��� 
#include<stdio.h>

int p;// pump�� ����
int f;// �ҹ��� ���

int p_arr[20]; //������ġ
int f_arr[20]; //�ҹ��� ��ġ

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

	if(car==f+1) // ���� ��ȣ �ڲ� �Ǽ� �Ѵ�.
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


	min_length=greedy(); // �����Ͱ� Ŀ���� �������ɵ�.
	solve(1,0);

	printf("min_length:%d\n",min_length);
	printf("func_call:%d",func_call);
}















//++ �Ʒ� Ǯ�̴� ���� ������
///////////////////////////////////////////////////////








//>>
//  �̷��� Ǯ�� ���� �ƴϴ�.!!!
//  tree�� �׷����� ������ ����.!
//  ����<->�ҹ��� ���� �ּ��� �Ÿ��� ���� ���´�. 
//  �̶� ������ �ϳ��� ���������� �ٸ� �ϳ��� ����� �ؾ��Ѵٴ� ���̴�.
// 
//  �ι�° Ǯ���� ����ȭ ��Ű�°� �����ε�.. �� ���� Ž���� ���� ����ȭ�� ������...?��? 
//  �ҹ����� ���̷� �������� ������ ������ �ĺ����� �ȴ�. �̶� ���õǾ��� ������ ������ �ȵȴ�.
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
// â�� ���� ������� ǰ.  Ʈ���� �׷����� �����Ѵ�.
// ���õȰ��� ���� ���� Ʈ������ �� ���õǰ� �ϴ°� �߿���.
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
//  ���� ���
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
g(i, ft+1, h);            // ���⼭ �ٷ� �� ���ָ�Ǵµ�..
h-=abs(pp[i]-fp[ft+1]);   // �� �̷��� Ǯ����.. 
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
// hoony ���� ���� 
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
