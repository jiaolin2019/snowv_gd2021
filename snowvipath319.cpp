#include<iostream>
#include <math.h>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<malloc.h>
#include <time.h>
#include <vector>
using namespace std;
int main()
{
    int T=5;//连续时刻
	int E=120*T+16;//方程个数
	int V=112*(T+1);//变量个数
	int M=E-24*T;
	int I=E-16*T;
	int const1=9;
	ofstream fout("outputGD.txt");
	
	int **A=(int **)calloc(sizeof(int *), E);  
	if(A!=NULL)
		for(int i=0; i<E; i++)
		{
			A[i]=(int *)calloc(sizeof(int), const1); 
			if(A[i]==NULL)
				exit(0);
		}
		
	int count=0;
	for(int j=0;j<16;j++)
		for(int t=0;t<=T;t++)
		{
			A[count][0]=3;
			A[count][1]=80-j+112*t;
			A[count][2]=64-j+112*t;
			A[count][3]=96-j+112*t;
			count++;
		}

	for(int j=0;j<4;j++)
		for(int t=0;t<T;t++)
		{
			A[count][0]=4;
			A[count][1]=80-4*j+112*(t+1);
			A[count][2]=96-j+112*t;
			A[count][3]=112-j+112*t;
			A[count][4]=32-j+112*t;
			count++;
		}
	for(int j=0;j<4;j++)
		for(int t=0;t<T;t++)
		{
			A[count][0]=4;
			A[count][1]=80-(4*j+1)+112*(t+1);
			A[count][2]=96-4-j+112*t;
			A[count][3]=112-4-j+112*t;
			A[count][4]=32-4-j+112*t;
			count++;
		}
	for(int j=0;j<4;j++)
		for(int t=0;t<T;t++)
		{
			A[count][0]=4;
			A[count][1]=80-(4*j+2)+112*(t+1);
			A[count][2]=96-8-j+112*t;
			A[count][3]=112-8-j+112*t;
			A[count][4]=32-8-j+112*t;
			count++;
		}
	for(int j=0;j<4;j++)
		for(int t=0;t<T;t++)
		{
			A[count][0]=4;
			A[count][1]=80-(4*j+3)+112*(t+1);
			A[count][2]=96-12-j+112*t;
			A[count][3]=112-12-j+112*t;
			A[count][4]=32-12-j+112*t;
			count++;
		}
	
	for(int j=0;j<16;j++)
		for(int t=0;t<T;t++)
		{
			A[count][0]=4;
			A[count][1]=32-j+112*(t+1);
			A[count][2]=48-j+112*t;
			A[count][3]=16-j+112*t;
			A[count][4]=30-j+112*t;
			count++;
		}
	for(int j=0;j<16;j++)
		for(int t=0;t<T;t++)
		{
			A[count][0]=2;
			A[count][1]=16-j+112*(t+1);
			A[count][2]=32-j+112*t;
			count++;
		}

	for(int j=0;j<16;j++)
		for(int t=0;t<T;t++)
		{
			A[count][0]=4;
			A[count][1]=64-j+112*(t+1);
			A[count][2]=16-j+112*t;
			A[count][3]=48-j+112*t;
			A[count][4]=64-j+112*t;
			count++;
		}
	for(int j=0;j<16;j++)
		for(int t=0;t<T;t++)
		{
			A[count][0]=2;
			A[count][1]=48-j+112*(t+1);
			A[count][2]=64-j+112*t;
			count++;
		}

	for(int t=0;t<T;t++)
	{
		A[count][0]=8;
		A[count][1]=93+112*(t+1);
		A[count][2]=94+112*(t+1);
		A[count][3]=95+112*(t+1);
		A[count][4]=96+112*(t+1);
		A[count][5]=77+112*t;
		A[count][6]=66+112*t;
		A[count][7]=71+112*t;
		A[count][8]=76+112*t;
		count++;
	}
	for(int t=0;t<T;t++)
	{
		A[count][0]=8;
		A[count][1]=89+112*(t+1);
		A[count][2]=90+112*(t+1);
		A[count][3]=91+112*(t+1);
		A[count][4]=92+112*(t+1);
		A[count][5]=73+112*t;
		A[count][6]=78+112*t;
		A[count][7]=67+112*t;
		A[count][8]=72+112*t;
		count++;
	}
	for(int t=0;t<T;t++)
	{
		A[count][0]=8;
		A[count][1]=85+112*(t+1);
		A[count][2]=86+112*(t+1);
		A[count][3]=87+112*(t+1);
		A[count][4]=88+112*(t+1);
		A[count][5]=69+112*t;
		A[count][6]=74+112*t;
		A[count][7]=79+112*t;
		A[count][8]=68+112*t;
		count++;
	}
	for(int t=0;t<T;t++)
	{
		A[count][0]=8;
		A[count][1]=81+112*(t+1);
		A[count][2]=82+112*(t+1);
		A[count][3]=83+112*(t+1);
		A[count][4]=84+112*(t+1);
		A[count][5]=65+112*t;
		A[count][6]=70+112*t;
		A[count][7]=75+112*t;
		A[count][8]=80+112*t;
		count++;
	}

	for(int t=0;t<T;t++)
	{
		A[count][0]=8;
		A[count][1]=109+112*(t+1);
		A[count][2]=110+112*(t+1);
		A[count][3]=111+112*(t+1);
		A[count][4]=112+112*(t+1);
		A[count][5]=93+112*t;
		A[count][6]=82+112*t;
		A[count][7]=87+112*t;
		A[count][8]=92+112*t;
		count++;
	}
	for(int t=0;t<T;t++)
	{
		A[count][0]=8;
		A[count][1]=105+112*(t+1);
		A[count][2]=106+112*(t+1);
		A[count][3]=107+112*(t+1);
		A[count][4]=108+112*(t+1);
		A[count][5]=89+112*t;
		A[count][6]=94+112*t;
		A[count][7]=83+112*t;
		A[count][8]=88+112*t;
		count++;
	}
	for(int t=0;t<T;t++)
	{
		A[count][0]=8;
		A[count][1]=101+112*(t+1);
		A[count][2]=102+112*(t+1);
		A[count][3]=103+112*(t+1);
		A[count][4]=104+112*(t+1);
		A[count][5]=85+112*t;
		A[count][6]=90+112*t;
		A[count][7]=95+112*t;
		A[count][8]=84+112*t;
		count++;
	}
	for(int t=0;t<T;t++)
	{
		A[count][0]=8;
		A[count][1]=97+112*(t+1);
		A[count][2]=98+112*(t+1);
		A[count][3]=99+112*(t+1);
		A[count][4]=100+112*(t+1);
		A[count][5]=81+112*t;
		A[count][6]=86+112*t;
		A[count][7]=91+112*t;
		A[count][8]=96+112*t;
		count++;
	}

	for(int j=0;j<16;j++)
		for(int t=0;t<T;t++)
		{
			A[count][0]=6;
			A[count][1]=64-j+112*(t+1);
			A[count][2]=32-j+112*(t+1);
			A[count][3]=30-j+112*t;
			A[count][4]=64-j+112*t;
			A[count][5]=48-j+112*t;
			A[count][6]=16-j+112*t;
			count++;
		}

	//A赋值
	
	if(count==E)
		cout<<"Initial is right.\n";
	else 	
		cout<<"Initial is wrong.\n";
	

	int **C=(int **)calloc(sizeof(int *), V);//记录Guess和Determine的变量
	if(C!= NULL)
	{
		for(int i=0; i<V; i++)
		{
			C[i]=(int *)calloc(sizeof(int), 2);  
			if(C[i]==NULL)
				exit(0);
		}
	}
	int pp;//C长度
	

	/*C[0][0]=301	;C[1][0]=	290;C[2][0]=295	;C[3][0]=300	;
	C[4][0]=285	;C[5][0]=274	;C[6][0]=279	;C[7][0]=284	;*/

	C[0][0]=77+112*2;C[1][0]=66+112*2;C[2][0]=71+112*2;C[3][0]=76+112*2;
	C[4][0]=73+112*2;C[5][0]=78+112*2;C[6][0]=67+112*2;C[7][0]=72+112*2;
	C[8][0]=61+112*2;C[9][0]=50+112*2;C[10][0]=55+112*2;C[11][0]=60+112*2;


	pp=12;
	for(int i=0;i<pp;i++)
		C[i][1]=10000;

	for(int l=0;l<pp;l++)//对C中点循环
	{
		for(int i=0;i<M;i++)
		{
			for(int j=1;j<9;j++)
				if(A[i][j]==C[l][0])
				{
					A[i][j]=0;
					A[i][0]--;
				}
			if(A[i][0]==1)
			{
				for(int j=1;j<9;j++)
					if(A[i][j]!=0)
					{
						int repetition=0;
						for(int u=0;u<pp;u++)
							if(C[u][0]==A[i][j])
								repetition=1;
						if(repetition==0)
						{										
							C[pp][0]=A[i][j];
							C[pp][1]=i;
							pp++;
						}//判断Determine值是否与C中点重复，压入C
						A[i][j]=0;
					}	
				A[i][0]=0;
			}
		}
		for(int i=M;i<I;i++)
		{
			for(int j=1;j<9;j++)
				if(A[i][j]==C[l][0])
				{
					A[i][j]=0;
					A[i][0]--;
				}
			if(A[i][0]==4)
			{
				for(int j=1;j<9;j++)
					if(A[i][j]!=0)
					{
						int repetition=0;
						for(int u=0;u<pp;u++)
							if(C[u][0]==A[i][j])
								repetition=1;
						if(repetition==0)
						{										
							C[pp][0]=A[i][j];
							C[pp][1]=i;
							pp++;
						}
						A[i][j]=0;
					}
				A[i][0]=0;
			}
		}
		for(int i=I;i<E;i++)
		{
			for(int j=1;j<9;j++)
				if(A[i][j]==C[l][0])
				{
					A[i][j]=0;
					A[i][0]--;
				}
			if((A[i][1]==0)&&(A[i][2]==0)&&(A[i][3]==0)&&(A[i][4]==0))
			{
				for(int j=1;j<9;j++)
					if(A[i][j]!=0)
					{
						int repetition=0;
						for(int u=0;u<pp;u++)
							if(C[u][0]==A[i][j])
								repetition=1;
						if(repetition==0)
						{										
							C[pp][0]=A[i][j];
							C[pp][1]=i;
							pp++;
						}
						A[i][j]=0;
					}
				A[i][0]=0;
			}
		}
		
	}

	fout<<"initial:";
	for(int i=0;i<V,C[i][0]!=0;i++)
	{
		if((C[i][0]-1)%112<32)
			fout<<"a_{"<<(C[i][0]-1)%112<<"}^{"<<(C[i][0]-1)/112<<"};";
		else if((C[i][0]-1)%112<64)
			fout<<"b_{"<<(C[i][0]-1)%112-32<<"}^{"<<(C[i][0]-1)/112<<"};"; 
		else if((C[i][0]-1)%112<80)
			fout<<"R1_{"<<(C[i][0]-1)%112-64<<"}^{"<<(C[i][0]-1)/112<<"};"; 
		else if((C[i][0]-1)%112<96)
			fout<<"R2_{"<<(C[i][0]-1)%112-80<<"}^{"<<(C[i][0]-1)/112<<"};"; 
		else
			fout<<"R3_{"<<(C[i][0]-1)%112-96<<"}^{"<<(C[i][0]-1)/112<<"};"; 

		if(C[i][1]<10000)
		{
			if(C[i][1]<16*T+16)
				fout<<"E:Z_"<<15-C[i][1]/(T+1)<<"^"<<C[i][1]%(T+1)<<"\n"; 
			else if(C[i][1]<32*T+16)
				fout<<"E:R1_"<<15-(C[i][1]-(16*T+16))/T<<"^"<<(C[i][1]-(16*T+16))%T<<"\n"; 
			else if(C[i][1]<48*T+16)
				fout<<"E:a_"<<15-(C[i][1]-(32*T+16))/T+16<<"^"<<(C[i][1]-(32*T+16))%T<<"\n"; 
			else if(C[i][1]<64*T+16)
				fout<<"E:a_"<<15-(C[i][1]-(48*T+16))/T<<"^"<<(C[i][1]-(48*T+16))%T<<"\n";
			else if(C[i][1]<80*T+16)
				fout<<"E:b_"<<15-(C[i][1]-(64*T+16))/T+16<<"^"<<(C[i][1]-(64*T+16))%T<<"\n";
			else if(C[i][1]<96*T+16)
				fout<<"E:b_"<<15-(C[i][1]-(80*T+16))/T<<"^"<<(C[i][1]-(80*T+16))%T<<"\n";
			else if(C[i][1]<100*T+16)
				fout<<"E:R2_"<<3-(C[i][1]-(96*T+16))/T<<"^"<<(C[i][1]-(96*T+16))%T<<"\n";
			else if(C[i][1]<104*T+16)
				fout<<"E:R3_"<<3-(C[i][1]-(100*T+16))/T<<"^"<<(C[i][1]-(100*T+16))%T<<"\n";
			else
				fout<<"E:Back"<<15-(C[i][1]-(104*T+16))/T<<"^"<<(C[i][1]-(104*T+16))%T<<"\n";

		}
		else
			fout<<"GUESS\n";
	}	


	
	int flag=0;//标志基
	int pathnum=0;
	int first=0;
	
	int ***index= (int ***) calloc(sizeof(int **), V);
	if(index!= NULL)
	{
		for(int i=0; i<V; i++)
		{
			index[i]=(int **)calloc(sizeof(int *), E);  
			if(index[i]!=NULL)
				for(int j=0; j<E; j++)
				{
					index[i][j]=(int *)calloc(sizeof(int), const1); 
					if(index[i][j]==NULL)
						exit(0);
				}
			else
			exit(0);
		}
	}//表操作前方程(变量个数组)
	for(int k=0;k<V;k++)
		for(int i=0;i<E;i++)
			for(int j=0;j<const1;j++)
				index[k][i][j]=A[i][j];//初始化为A
	
	int ***path= (int ***) calloc(sizeof(int **),V);
	if(path!= NULL)
	{
		for(int i=0; i<V; i++)
		{
			path[i]=(int **)calloc(sizeof(int *), V);  
			if(path[i]!=NULL)
				for(int j=0; j<V; j++)
				{
					path[i][j]=(int *)calloc(sizeof(int), 2); 
					if(path[i][j]==NULL)
						exit(0);
				}
			else
			exit(0);
		}
	}
	//表操作前路径
			
	int ***indexnew= (int ***) calloc(sizeof(int **), V);
	if(indexnew!= NULL)
	{
		for(int i=0; i<V; i++)
		{
			indexnew[i]=(int **)calloc(sizeof(int *), E);  
			if(indexnew[i]!=NULL)
				for(int j=0; j<E; j++)
				{
					indexnew[i][j]=(int *)calloc(sizeof(int), const1); 
					if(indexnew[i][j]==NULL)
						exit(0);
				}
			else
			exit(0);
		}
	}//表操作后方程	

	int ***pathnew= (int ***) calloc(sizeof(int **),V);
	if(pathnew!= NULL)
	{
		for(int i=0; i<V; i++)
		{
			pathnew[i]=(int **)calloc(sizeof(int *), V);  
			if(pathnew[i]!=NULL)
				for(int j=0; j<V; j++)
				{
					pathnew[i][j]=(int *)calloc(sizeof(int), 2); 
					if(pathnew[i][j]==NULL)
						exit(0);
				}
			else
			exit(0);
		}
	}
	//表操作后路径
	
	int **B= (int **) calloc(sizeof(int *),V);
	if(B!= NULL)
	{
		for(int i=0; i<V; i++)
		{
			B[i]=(int *)calloc(sizeof(int), 2);  
			if(B[i]==NULL)
				exit(0);
		}
	}

	int point;//B长度
	
	int guessmin=V;//记录最小猜测个数
	
	for(int t=0;t<V;t++)//level
	{ 
		for(int s=1;s<=V;s++)//入点
		{
			int al=0;//判断是否在初始猜测集中
			for(int x=0;x<pp;x++)
				if(s==C[x][0])
					al=1;
			if(al==0)
			{
			int record=0;//记录消去最多变量的k
			for(int k=0;k<V;k++)//出点
			{
				int num=0;//消去变量个数
		
				for(int i=0;i<V;i++)
					for(int j=0;j<2;j++)
						B[i][j]=0;//B清零
			
				B[0][0]=s;
				point=1;//在原有每条路径的基础上猜测s
				
				for(int i=0;i<E;i++)
					for(int j=0;j<const1;j++)
						A[i][j]=index[k][i][j];//表操作前数组赋给操作数组A
				
				for(int l=0;l<point;l++)//对B中点循环
				{
					for(int i=0;i<M;i++)
					{
						for(int j=1;j<9;j++)
							if(A[i][j]==B[l][0])
							{
								num++;
								A[i][j]=0;
								A[i][0]--;
							}
						if(A[i][0]==1)
						{
							for(int j=1;j<9;j++)
								if(A[i][j]!=0)
								{
									int repetition=0;
									for(int u=0;u<point;u++)
										if(B[u][0]==A[i][j])
											repetition=1;
									if(repetition==0)
									{										
										B[point][0]=A[i][j];
										B[point][1]=i;
										point++;
									}//判断Determine值是否与B中点重复，压入B
									num++;
									A[i][j]=0;
								}	
							A[i][0]=0;
						}
					}
					for(int i=M;i<I;i++)
					{
						for(int j=1;j<9;j++)
							if(A[i][j]==B[l][0])
							{
								num++;
								A[i][j]=0;
								A[i][0]--;
							}
						if(A[i][0]==4)
						{
							for(int j=1;j<9;j++)
								if(A[i][j]!=0)
								{
									int repetition=0;
									for(int u=0;u<point;u++)
										if(B[u][0]==A[i][j])
											repetition=1;
									if(repetition==0)
									{										
										B[point][0]=A[i][j];
										B[point][1]=i;
										point++;
									}
									num++;
									A[i][j]=0;
								}
							A[i][0]=0;
						}
					}
					for(int i=I;i<E;i++)
					{
						for(int j=1;j<9;j++)
							if(A[i][j]==B[l][0])
							{
								num++;
								A[i][j]=0;
								A[i][0]--;
							}
						if((A[i][1]==0)&&(A[i][2]==0)&&(A[i][3]==0)&&(A[i][4]==0))
						{
							for(int j=1;j<9;j++)
								if(A[i][j]!=0)
								{
									int repetition=0;
									for(int u=0;u<point;u++)
										if(B[u][0]==A[i][j])
											repetition=1;
									if(repetition==0)
									{										
										B[point][0]=A[i][j];
										B[point][1]=i;
										point++;
									}
									num++;
									A[i][j]=0;
								}
							A[i][0]=0;
						}
					}
					
				}//猜s对A[][]做消息传播(表操作)
				if(record<num)//记录更优值
				{
					record=num;
					for(int i=0;i<V;i++)
						for(int j=0;j<2;j++)
							pathnew[s-1][i][j]=0;//pathnew清零
					for(int i=0;i<E;i++)
						for(int j=0;j<const1;j++)
							indexnew[s-1][i][j]=A[i][j];
					int tag=0;
					for(int i=0;i<V;i++)
						if(path[k][i][0]!=0)
						{
							for(int j=0;j<2;j++)
								pathnew[s-1][tag][j]=path[k][i][j];
							tag++;
						}
					pathnew[s-1][tag][0]=B[0][0];
					pathnew[s-1][tag][1]=10000;
					for(int i=1;i<point;i++)
					{
						if(tag+i>=V)
							cout<<"wrong:"<<tag<<","<<tag+i<<">V.\n";
						for(int j=0;j<2;j++)
							pathnew[s-1][tag+i][j]=B[i][j];//更新pathnew=path+B
					}
				}//if end 判断是否更优	
			}//for k end
			int sign=0;
			for(int i=0;i<E;i++)
				if(indexnew[s-1][i][0]!=0)
					sign=1;
				
			if(sign==0)
			{
				flag=1;pathnum++;
				if(first<100)
				{
					first++;
					fout<<"path:";
					for(int i=0;i<V,pathnew[s-1][i][0]!=0;i++)
					{
						if((pathnew[s-1][i][0]-1)%112<32)
							fout<<"a_{"<<(pathnew[s-1][i][0]-1)%112<<"}^{"<<(pathnew[s-1][i][0]-1)/112<<"};";
						else if((pathnew[s-1][i][0]-1)%112<64)
							fout<<"b_{"<<(pathnew[s-1][i][0]-1)%112-32<<"}^{"<<(pathnew[s-1][i][0]-1)/112<<"};"; 
						else if((pathnew[s-1][i][0]-1)%112<80)
							fout<<"R1_{"<<(pathnew[s-1][i][0]-1)%112-64<<"}^{"<<(pathnew[s-1][i][0]-1)/112<<"};"; 
						else if((pathnew[s-1][i][0]-1)%112<96)
							fout<<"R2_{"<<(pathnew[s-1][i][0]-1)%112-80<<"}^{"<<(pathnew[s-1][i][0]-1)/112<<"};"; 
						else
							fout<<"R3_{"<<(pathnew[s-1][i][0]-1)%112-96<<"}^{"<<(pathnew[s-1][i][0]-1)/112<<"};"; 

						if(pathnew[s-1][i][1]<10000)
						{
							if(pathnew[s-1][i][1]<16*T+16)
								fout<<"E:Z_"<<15-pathnew[s-1][i][1]/(T+1)<<"^"<<pathnew[s-1][i][1]%(T+1)<<"\n"; 
							else if(pathnew[s-1][i][1]<32*T+16)
								fout<<"E:R1_"<<15-(pathnew[s-1][i][1]-(16*T+16))/T<<"^"<<(pathnew[s-1][i][1]-(16*T+16))%T<<"\n"; 
							else if(pathnew[s-1][i][1]<48*T+16)
								fout<<"E:a_"<<15-(pathnew[s-1][i][1]-(32*T+16))/T+16<<"^"<<(pathnew[s-1][i][1]-(32*T+16))%T<<"\n"; 
							else if(pathnew[s-1][i][1]<64*T+16)
								fout<<"E:a_"<<15-(pathnew[s-1][i][1]-(48*T+16))/T<<"^"<<(pathnew[s-1][i][1]-(48*T+16))%T<<"\n";
							else if(pathnew[s-1][i][1]<80*T+16)
								fout<<"E:b_"<<15-(pathnew[s-1][i][1]-(64*T+16))/T+16<<"^"<<(pathnew[s-1][i][1]-(64*T+16))%T<<"\n";
							else if(pathnew[s-1][i][1]<96*T+16)
								fout<<"E:b_"<<15-(pathnew[s-1][i][1]-(80*T+16))/T<<"^"<<(pathnew[s-1][i][1]-(80*T+16))%T<<"\n";
							else if(pathnew[s-1][i][1]<100*T+16)
								fout<<"E:R2_"<<3-(pathnew[s-1][i][1]-(96*T+16))/T<<"^"<<(pathnew[s-1][i][1]-(96*T+16))%T<<"\n";
							else if(pathnew[s-1][i][1]<104*T+16)
								fout<<"E:R3_"<<3-(pathnew[s-1][i][1]-(100*T+16))/T<<"^"<<(pathnew[s-1][i][1]-(100*T+16))%T<<"\n";
							else
								fout<<"E:Back_"<<15-(pathnew[s-1][i][1]-(104*T+16))/T<<"^"<<(pathnew[s-1][i][1]-(104*T+16))%T<<"\n";

						}
						else
							fout<<"GUESS\n";
					}
					fout<<"end\n";
				}
				
				int guess=0;
				for(int i=0;i<V;i++)
					if(pathnew[s-1][i][1]==10000)
						guess++;
				
				if(guess<guessmin)
					guessmin=guess;		
			}//判断是否为基
			}
		}//for s end
		
		if(flag==1)
		{
			cout<<"level:"<<t<<"\ is done.\n";
			break;//找到基，跳出t循环
		}
		
	
		for(int k=0;k<V;k++)
		{
			for(int i=0;i<E;i++)
			{
				for(int j=0;j<const1;j++)
				{
					index[k][i][j]=indexnew[k][i][j];
				}
			}		
			for(int i=0;i<V;i++)
				for(int j=0;j<2;j++)
					path[k][i][j]=pathnew[k][i][j];
		}
		cout<<"level:"<<t<<"\ is done.\n";
	}//for t end
	cout<<guessmin<<"\n";
	cout<<pathnum<<"\n";
	getchar();
	return 0;
}