/*
//창훈
7
0 0 1 0 0 0 0
0 0 1 0 0 0 0
0 0 0 0 0 1 0
0 0 0 0 0 0 0
1 1 0 1 0 0 0
0 1 0 0 0 0 0
0 0 0 0 0 0 0 

답 12



7
0 0 0 0 0 0 0
0 0 0 1 0 0 0
0 0 1 1 1 0 0
0 0 0 1 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 

답 8
*/


//창훈 최종
#include<stdio.h>

int PCB[15][15];
int result_PCB[15][15];
int N;

struct CORD
{
	int x;
	int y;
};

CORD cord[15]; //배선이 필요한 코어, 0번 부터 시작
int count = 0; //core의 갯수 

void findCore()
{
		for (int x = 0; x<N; x++)
		for (int y = 0; y<N; y++)
		{
			if (PCB[x][y] == 1)
			{
				if (x == 0 || y == 0 || x==N-1 || y==N-1) continue;
				else { cord[count].x = x; cord[count].y = y; count++; }
			}
		}
}

void input()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);

	for (int i = 0; i<N; i++)
		for (int j = 0; j<N; j++)
			scanf("%d", &PCB[i][j]);
}


//숫자를 리턴하면 가능한것임.
int isitpossible(int dir, int core_num)
{
	int x = cord[core_num].x;
	int y = cord[core_num].y;
	int len = 0;
	int sum = 0;

	if (dir == 1)
	{
		x = x - 1;
		for (; x >= 0; x--)
		{
			len++;
			sum += PCB[x][y];
		}

		if (sum == 0) return len;
		else return 0;
	}

	if (dir == 2)
	{
		y = y + 1;
		for (; y<N; y++)
		{
			len++;
			sum += PCB[x][y];
		}

		if (sum == 0) return len;
		else return 0;
	}

	if (dir == 3)
	{
		x = x + 1;
		for (; x<N; x++)
		{
			len++;
			sum += PCB[x][y];
		}

		if (sum == 0) return len;
		else return 0;
	}

	if (dir == 4)
	{
		y = y - 1;
		for (; y >= 0; y--)
		{
			len++;
			sum += PCB[x][y];
		}

		if (sum == 0) return len;
		else return 0;
	}

	return 0;
}


//똑같은 루틴임
//mode = 0 -> wire
//mode = 1 -> unwire
void wire(int mode, int dir, int core_num)
{
	int x = cord[core_num].x;
	int y = cord[core_num].y;

	if (dir == 1)
	{
		x = x - 1;
		for (; x >= 0; x--)
		{
			if (mode == 0) PCB[x][y] = 2;
			else  PCB[x][y] = 0;
		}

	}

	if (dir == 2)
	{
		y = y + 1;
		for (; y<N; y++)
		{
			if (mode == 0) PCB[x][y] = 2;
			else  PCB[x][y] = 0;
		}

	}

	if (dir == 3)
	{
		x = x + 1;
		for (; x<N; x++)
		{
			if (mode == 0) PCB[x][y] = 2;
			else  PCB[x][y] = 0;
		}

	}

	if (dir == 4)
	{
		y = y - 1;
		for (; y >= 0; y--)
		{
			if (mode == 0) PCB[x][y] = 2;
			else  PCB[x][y] = 0;
		}

	}


}

int max_selected_core_count = -987654321;
int min_len = 987654321;

void solve(int core_num, int selected_core_count, int len)
{

	if (core_num == count)
	{
		if (max_selected_core_count <= selected_core_count)
		{
			if (max_selected_core_count == selected_core_count)
			{
				if (min_len > len)
				{
					min_len = len;

					for (int i = 0; i<N; i++)
						for (int j = 0; j<N; j++)
							result_PCB[i][j] = PCB[i][j];
				}

			}
			else
			{
				min_len = len;

				for (int i = 0; i<N; i++)
					for (int j = 0; j<N; j++)
						result_PCB[i][j] = PCB[i][j];
			}

			max_selected_core_count = selected_core_count;
		}

		return;
	}


	for (int i = 1; i <= 4; i++)
	{
		int new_len = 0;

		if (new_len = isitpossible(i, core_num)) //실수!!! length, len 인자 넘길때 혼동
		{
			wire(0, i, core_num);
			solve(core_num + 1, selected_core_count + 1, new_len + len);
			wire(1, i, core_num);

			solve(core_num + 1, selected_core_count, len);  //배선이 가능하지만 자발적으로 배선하지 않음 , 실수!!! length, len 인자 넘길때 
		}
		else{
			solve(core_num + 1, selected_core_count, len);  //어쩔수 없이 배선을 못함. 실수!!! length, len 인자 넘길때 혼동
		}
	}
}


void display(int map[][15])
{
	for (int x = 0; x<N; x++)
	{
		for (int y = 0; y<N; y++)
		{
			printf(" %d", map[x][y]);
		}
		printf("\n");
	}

	printf("\n");
}


void main()
{
	input();
	display(PCB);

	findCore();
	solve(0, 0, 0);

	printf("\n%d\n", min_len);
	display(result_PCB);
}












/////////////////////////////////////////////////////


#include<stdio.h>

int n; //가로 

int PCB[20][20];

int PCB_RESULT[20][20];


struct CORE
{
	int i;
	int j;
};


CORE cores[12];// 전원 연결이 필요한 코어
int cores_count;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void input()
{
	//freopen("output.txt","w",stdout);
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);

	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			scanf("%d", &PCB[i][j]);


	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
		{
			if (PCB[i][j] == 1 &&
				!(i == 0 || j == 0 || (n - 1) == i || (n - 1) == j))
			{
				cores[cores_count].i = i;
				cores[cores_count].j = j;
				cores_count++;
			}
		}

}


//배선
//해당 방향 배선이 가능하면 길이 못하면 0
int connect(int c, int dir)
{
	int len = 0;

	if (dir == 0)
	{
		int i = cores[c].i - 1;
		int j = cores[c].j;

		//check;
		for (; i >= 0; i--)
		{
			if (PCB[i][j] != 0) return 0;
		}

		i = cores[c].i - 1;
		j = cores[c].j;


		for (; i >= 0; i--)
		{
			PCB[i][j] = 2;
			len++;
		}

	}


	if (dir == 1)
	{
		int i = cores[c].i;
		int j = cores[c].j + 1;

		//check;
		for (; j<n; j++)
		{
			if (PCB[i][j] != 0) return 0;
		}

		i = cores[c].i;
		j = cores[c].j + 1;


		for (; j<n; j++)
		{
			PCB[i][j] = 2;
			len++;
		}

	}


	if (dir == 2)
	{
		int i = cores[c].i + 1;
		int j = cores[c].j;

		//check;
		for (; i<n; i++)
		{
			if (PCB[i][j] != 0) return 0;
		}

		i = cores[c].i + 1;
		j = cores[c].j;


		for (; i<n; i++)
		{
			PCB[i][j] = 2;
			len++;
		}

	}


	if (dir == 3)
	{
		int i = cores[c].i;
		int j = cores[c].j - 1;

		//check;
		for (; j >= 0; j--)
		{
			if (PCB[i][j] != 0) return 0;
		}

		i = cores[c].i;
		j = cores[c].j - 1;


		for (; j >= 0; j--)
		{
			PCB[i][j] = 2;
			len++;
		}

	}


	return len;
}


//un배선
void unconnect(int c, int dir)
{

	if (dir == 0)
	{
		int i = cores[c].i - 1;
		int j = cores[c].j;

		//check;
		for (; i >= 0; i--)
		{
			if (PCB[i][j] == 2) PCB[i][j] = 0;
		}
	}


	if (dir == 1)
	{
		int i = cores[c].i;
		int j = cores[c].j + 1;

		//check;
		for (; j<n; j++)
		{
			if (PCB[i][j] == 2) PCB[i][j] = 0;
		}
	}


	if (dir == 2)
	{
		int i = cores[c].i + 1;
		int j = cores[c].j;

		//check;
		for (; i<n; i++)
		{
			if (PCB[i][j] == 2) PCB[i][j] = 0;
		}

	}


	if (dir == 3)
	{
		int i = cores[c].i;
		int j = cores[c].j - 1;

		//check;
		for (; j >= 0; j--)
		{
			if (PCB[i][j] == 2) PCB[i][j] = 0;
		}
	}
}


void display()
{
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			printf(" %d", PCB[i][j]);
		}
		printf("\n");
	}
}

void display_result()
{
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			printf(" %d", PCB_RESULT[i][j]);
		}
		printf("\n");
	}
}


int max_core = -987654321;
int min_wire = 987654321;



void f(int c, int selected_core, int len)
{
	if (c == cores_count)
	{
		//printf("selected_core core:%d , len:%d\n",selected_core,len);
		//  display();

		if (max_core <= selected_core)
		{
			if (max_core == selected_core)
			{
				if (min_wire > len)
				{
					min_wire = len;

					for (int i = 0; i<n; i++)
						for (int j = 0; j<n; j++)
							PCB_RESULT[i][j] = PCB[i][j];
				}
			}
			else
			{
				//min_wire=987654321; // 이렇게 풀면안됨.
				min_wire = len;

				for (int i = 0; i<n; i++)
					for (int j = 0; j<n; j++)
						PCB_RESULT[i][j] = PCB[i][j];

			}

			max_core = selected_core;
		}

		return;  //모든 코어를 고려했다.
	}

	for (int k = 0; k<4; k++)
	{

		int l = connect(c, k);
		if (l>0)
		{
			f(c + 1, selected_core + 1, len + l);
			unconnect(c, k);
		}
		else
			f(c + 1, selected_core, len);

	}

}



void main()
{
	input();
	/*
	printf("len %d\n",connect(0,2));
	display();

	printf("----------\n");
	unconnect(0,2);
	display();
	*/

	f(0, 0, 0);
	printf("min len:%d\n", min_wire);
	display_result();
}




//while
/////////////////////////////


#include<stdio.h>

int N;

struct Core
{
	int x;
	int y;
};

Core core[20];
int core_count=1;

int arr[20][20];
int result_map[20][20];

//불가능하면 0, 가능하면 길이를 반환한다.
int canConnect(int core_num, int dir)
{
	int x=core[core_num].x;
	int y=core[core_num].y;
	
	//0 direction
	if(dir==0)
	{
		do{
			x--;
			if(arr[x][y]!=0) return 0;// 중간에 하나라도 걸리는게 나오면 
		}while(x>0);
		
		if(x==0) return core[core_num].x;
		else return 0;
	}
	
	if(dir==1)
	{
		do{
			y++;
			if(arr[x][y]!=0) return 0;
		}while(y<N-1);
		
		if(y==N-1) return N-core[core_num].y-1;
		else return 0;
	}
	
	if(dir==2)
	{
		do{
			x++;
			if(arr[x][y]!=0) return 0;
		}while(x<N-1);
		
		if(x==N-1) return N-core[core_num].x-1;
		else return 0;
	}
	
	if(dir==3)
	{
		do{
			y--;
			if(arr[x][y]!=0) return 0;
		}while(y>0);
		
		if(y==0) return core[core_num].y;
		else return 0;
		
	}	
}


//2번 wire
//0번 원래대로
void wiring(int core_num,int dir, int type)
{
	int x=core[core_num].x;
	int y=core[core_num].y;
	
	if(dir==0)
	{
		for(int i=x-1;i>=0;i--)
			arr[i][y]=type;
	}
	
	if(dir==1)
	{
		for(int i=y+1;i<N;i++)
			arr[x][i]=type;
	}
	
	if(dir==2)
	{
		for(int i=x+1;i<N;i++)
			arr[i][y]=type;
	}
	
	if(dir==3)
	{
		for(int i=y-1;i>=0;i--)
			arr[x][i]=type;
	}
}

void printMap()
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			printf(" %d",arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int max_core=-987654321;
int min_dist=987654321;


void solve(int c, int selected_core_count, int distance)
{
	if(c==core_count+1)
	{
		//base에서의 바닥 로그
		//printf("selected_core_count:%d distance:%d \n",selected_core_count,distance);
		
		if(selected_core_count>=max_core) // 이 조건이 더 명료하다.
		{
			if(max_core != selected_core_count) min_dist=98765421; //max core가 변경되었음, 그래서 min_dist를 초기화.
			
			max_core=selected_core_count;
			
			if(min_dist > distance)
			{
				min_dist=distance;
				
				for(int i=0;i<N;i++)
				for(int j=0;j<N;j++)
				{
					result_map[i][j]=arr[i][j];
				}
				
			}
			
		}
		
		return;
	}
	
	
	for(int i=0;i<4;i++)
	{
			int length=canConnect(c,i);
			
			if(length>0)
			{
				wiring(c,i,2);
				solve(c+1,selected_core_count+1,distance+length);
				wiring(c,i,0);
			}
			else{
				
				solve(c+1,selected_core_count,distance);
			}
	}
}


void findCore()
{
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			if(arr[i][j]==1 &&
			  (i==0 || j==N-1) ||
			  (j==0 || j==N-1))
			  {
				  continue;
			  }
			  
			  if(arr[i][j]==1)
			  {
				  core[core_count].x=i;
				  core[core_count].y=j;
				  core_count++;
			  }
		}
	
	core_count--;
}

void input()
{
	freopen("input.txt","r",stdin);
	scanf("%d",&N);
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			scanf("%d",&arr[i][j]);
		}
}


void main()
{
	input();
	findCore();
	solve(1,0,0);
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			printf(" %d",result_map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	//Max core는 이미 전원에 연결된 Core를 제외한 수
	printf("MAX Core : %d Min Distnace:%d \n",max_core,min_dist);
}

