
/*
10
80 90 65 55 90 60 40 35 30 25

답 38425

8
30 25 70 55 95 75 90 20 

답 44225

10 
60 85 45 25 15 70 55 70 85 35

답 37925


1.
2개의 특급 노선을 구축
조건이 있음
노트 그림 참조


2. 타당성이 최대인값은
   타당성식 ((A+B)*(A+B)) + ((C+D)*(C+D))

*/

//반복 풀이
//////////////////////////////////////


#include<stdio.h>

int N;
int check[30];
int SUBWAY[30];

int first_path[2];
int second_path[2];

int MAX_VALUE=-987654321;

int func_count;

//노선 1, 노선 2에 같이 사용됨. 그래서 1,2를 다 처리해야함
int isitpossilbe(int subway)
{	
			    if(subway==0)  // 선택이 필요한 역이 처음역일때
				{
					if(check[N-1]) return 0;
					if(check[subway]) return 0;
					if(check[subway+1]) return 0;
				}
				else if(subway==N-1) // 선택이 필요한 역이 마지막 역일때 
				{
					if(check[0]) return 0;
					if(check[N-1]) return 0;
					if(check[N-2]) return 0;
				}
				else  // 일반적인 경우
				{
					if( check[subway-1]) return 0;
					if( check[subway]) return 0;
					if( check[subway+1]) return 0;
				}
					
				return 1;
}

int crossingcheck()
{
	int start_index=-1;
	int end_index=-1;

	//두번째 노선의 처음역
	for(int i=0;i<N;i++)
	{
		if(check[i]==2)
		{
			start_index=i;
			break;
		}
	}

	//두번째 노선의 두번째역
	for(int i=start_index+1;i<N;i++)
	{
		if(check[i]==2)
		{
			end_index=i;
		}
	}

	int another_path=0;

	//그 구간에 1번역이 끼어 있는가?
	for(int i=start_index;i<=end_index;i++)
	{
		if(check[i]==1)
		{
			another_path++;
		}
	}

	if(another_path==2 || another_path==0 )  return 1;
	else return 0;
}


void main()
{
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d",&N);

	for(int i=0;i<N;i++)
	scanf("%d",&SUBWAY[i]);

	for(int a=0;a<N;a++)
	{
		if(isitpossilbe(a))
		{
			check[a]=1;
			for(int b=0;b<N;b++)
			{
				if(isitpossilbe(b))
				{
					check[b]=1;
					for(int c=0;c<N;c++)
					{
						if(isitpossilbe(c))
						{
							check[c]=2;
							for(int d=0;d<N;d++)
							{
								if(isitpossilbe(d))
								{
									check[d]=2;
									// printf("a:%d b:%d c:%d d:%d\n",a,b,c,d);
									
									if(crossingcheck())
									{
										//printf("a:%d b:%d c:%d d:%d\n",a,b,c,d);
										int first=0;
										int second=0;

										int path_1[2];
										int path_1_count=0;

										int path_2[2];
										int path_2_count=0;

										for(int i=0;i<N;i++)
										{
											if(check[i]==1) { first+=SUBWAY[i]; 
															 path_1[path_1_count]=i;
															 path_1_count++;
															}
											if(check[i]==2) { second+=SUBWAY[i]; 
															 path_2[path_2_count]=i;
															 path_2_count++;
															}
										}
	
										int result = first*first + second*second;

										if(MAX_VALUE < result){
											MAX_VALUE=result;

											for(int i=0; i<2;i++)
											{
												first_path[i]=path_1[i];
												second_path[i]=path_2[i];
											}
										}
									}
									
									check[d]=0;
								}
							}
							check[c]=0;
						}
					}
					check[b]=0;
				}
			}
			check[a]=0;
		}
	}

	printf("--------------------------\n");
	printf("MAX_VALUE : %d\n",MAX_VALUE);

	printf("first path : %d - %d \n",first_path[0],first_path[1]);
	printf("second path :%d - %d \n",second_path[0],second_path[1]);
}








//백트래킹 풀이
//////////////////////////////////////

#include<stdio.h>

int N;
int check[30];
int new_check[30];

int SUBWAY[30];

int first_path[2];
int second_path[2];

int MAX_VALUE=-987654321;

int func_count;

//노선 1, 노선 2에 같이 사용됨. 그래서 1,2를 다 처리해야함
int isitpossilbe(int subway)
{	
			    if(subway==0)  // 선택이 필요한 역이 처음역일때
				{
					if(check[N-1]) return 0;
					if(check[subway]) return 0;
					if(check[subway+1]) return 0;
				}
				else if(subway==N-1) // 선택이 필요한 역이 마지막 역일때 
				{
					if(check[0]) return 0;
					if(check[N-1]) return 0;
					if(check[N-2]) return 0;
				}
				else  // 일반적인 경우
				{
					if( check[subway-1]) return 0;
					if( check[subway]) return 0;
					if( check[subway+1]) return 0;
				}
					
				return 1;
}

int crossingcheck()
{
	int start_index=-1;
	int end_index=-1;

	//두번째 노선의 처음역
	for(int i=0;i<N;i++)
	{
		if(new_check[i]==2)
		{
			start_index=i;
			break;
		}
	}

	//두번째 노선의 두번째역
	for(int i=start_index+1;i<N;i++)
	{
		if(new_check[i]==2)
		{
			end_index=i;
		}
	}

	int another_path=0;

	//그 구간에 1번역이 끼어 있는가?
	for(int i=start_index;i<=end_index;i++)
	{
		if(new_check[i]==1)
		{
			another_path++;
		}
	}

	if(another_path==2 || another_path==0 )  return 1;
	else return 0;
}


void solve(int k)
{
	func_count++;
	if(k==5)
	{
			//copy check arry
			for(int i=0;i<N;i++)
			new_check[i]=check[i];

		    //지하철 역을 2개의 노선으로  1,2를 1번 노선 -  3,4를 2번 노선
			//>>
			for(int i=0;i<N;i++)
			{
				if(new_check[i]==2) new_check[i]=1;
			}

			for(int i=0;i<N;i++)
			{
				if(new_check[i]==3) new_check[i]=2;
			}

			for(int i=0;i<N;i++)
			{
				if(new_check[i]==4) new_check[i]=2;
			}
			//<<


		if(crossingcheck())
		{
			int first=0;
			int second=0;

			int path_1[2]={0,0};
			int path_1_count=0;

			int path_2[2]={0,0};
			int path_2_count=0;

			for(int i=0;i<N;i++)
			{
				if(new_check[i]==1) { first+=SUBWAY[i]; 
								 path_1[path_1_count]=i;
								 path_1_count++;
								}
				if(new_check[i]==2) { second+=SUBWAY[i]; 
								 path_2[path_2_count]=i;
								 path_2_count++;
								}
			}
	
		    int result = first*first + second*second;

			if(MAX_VALUE < result){
				MAX_VALUE=result;

				for(int i=0; i<2;i++)
				{
					first_path[i]=path_1[i];
					second_path[i]=path_2[i];
				}
			}
		
		  printf("\nfirst path : %d - %d \n",path_1[0],path_1[1]);
		  printf("second path :%d - %d \n",path_2[0],path_2[1]);
		}
		return;
	}

	for(int i=0;i<N;i++)
	{
		if(isitpossilbe(i))
		{
			check[i]=k;
			solve(k+1);
			check[i]=0;
		}
	}
}

void main()
{
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d",&N);

	for(int i=0;i<N;i++)
	scanf("%d",&SUBWAY[i]);

	solve(1);

	printf("--------------------------\n");
	printf("MAX_VALUE : %d\n",MAX_VALUE);

	printf("first path : %d - %d \n",first_path[0],first_path[1]);
	printf("second path :%d - %d \n",second_path[0],second_path[1]);
	printf("func_count:%d\n",func_count);
}


//2중 백트래킹
//>>>>>>>>>>>

#include<stdio.h>

int N;
int check[30];
int SUBWAY[30];

int first_path[2];
int second_path[2];

int MAX_VALUE=-987654321;

int func_count;

//노선 1, 노선 2에 같이 사용됨. 그래서 1,2를 다 처리해야함
int isitpossilbe(int subway)
{	
			    if(subway==0)  // 선택이 필요한 역이 처음역일때
				{
					if(check[N-1]) return 0;
					if(check[subway]) return 0;
					if(check[subway+1]) return 0;
				}
				else if(subway==N-1) // 선택이 필요한 역이 마지막 역일때 
				{
					if(check[0]) return 0;
					if(check[N-1]) return 0;
					if(check[N-2]) return 0;
				}
				else  // 일반적인 경우
				{
					if( check[subway-1]) return 0;
					if( check[subway]) return 0;
					if( check[subway+1]) return 0;
				}
					
				return 1;
}

int crossingcheck()
{
	int start_index=-1;
	int end_index=-1;

	//두번째 노선의 처음역
	for(int i=0;i<N;i++)
	{
		if(check[i]==2)
		{
			start_index=i;
			break;
		}
	}

	//두번째 노선의 두번째역
	for(int i=start_index+1;i<N;i++)
	{
		if(check[i]==2)
		{
			end_index=i;
		}
	}

	int another_path=0;

	//그 구간에 1번역이 끼어 있는가?
	for(int i=start_index;i<=end_index;i++)
	{
		if(check[i]==1)
		{
			another_path++;
		}
	}

	if(another_path==2 || another_path==0 )  return 1;
	else return 0;
}

//두번째 특급노선
void solve2(int k)
{

	if(k==3)
	{
		if(crossingcheck())
		{
			int first=0;
			int second=0;

			int path_1[2];
			int path_1_count=0;

			int path_2[2];
			int path_2_count=0;

			for(int i=0;i<N;i++)
			{
				if(check[i]==1) { first+=SUBWAY[i]; 
								 path_1[path_1_count]=i;
								 path_1_count++;
								}
				if(check[i]==2) { second+=SUBWAY[i]; 
								 path_2[path_2_count]=i;
								 path_2_count++;
								}
			}
	
		    int result = first*first + second*second;

			if(MAX_VALUE < result){
				MAX_VALUE=result;

				for(int i=0; i<2;i++)
				{
					first_path[i]=path_1[i];
					second_path[i]=path_2[i];
				}
			}
		
		 // printf("\nfirst path : %d - %d \n",path_1[0],path_1[1]);
		//  printf("second path :%d - %d \n",path_2[0],path_2[1]);
		}
		return;
	}

	for(int i=0;i<N;i++)
	{
		if(isitpossilbe(i))
		{
			check[i]=2;
			solve2(k+1);
			check[i]=0;
		}
	}
}


//첫번째 노선
void solve(int k)
{
	func_count++;
	if(k==3)
	{
		solve2(1);
		return;
	}

	for(int i=0;i<N;i++)
	{
		if(isitpossilbe(i))
		{
			check[i]=1;
			solve(k+1);
			check[i]=0;
		}
	}
}

void main()
{
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d",&N);

	for(int i=0;i<N;i++)
	scanf("%d",&SUBWAY[i]);

	solve(1);

	printf("--------------------------\n");
	printf("MAX_VALUE : %d\n",MAX_VALUE);

	printf("first path : %d - %d \n",first_path[0],first_path[1]);
	printf("second path :%d - %d \n",second_path[0],second_path[1]);
	printf("func_count:%d\n",func_count);
}

