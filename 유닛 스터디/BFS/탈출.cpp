#include<stdio.h>
int c,r;
int map[50][50];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int d[50][50];
#include<iostream> 
struct dot
{
	int x,y;
};
#include<queue>
using namespace std;
queue<dot> q;
queue<dot> qwater;
void print()
{
	for(int i=0;i<c;i++)
	{
		for(int j=0;j<r;j++)
			printf("%d ",map[i][j]);
		printf("\n");
	}
	printf("\n");
}

void printd()
{
	for(int i=0;i<c;i++)
	{
		for(int j=0;j<r;j++)
			printf("%d ",d[i][j]);
		printf("\n");
	}
	printf("\n");
}

int main()
{
	scanf("%d %d",&c,&r);
	int a,b,goala,goalb;
	for(int i=0;i<c;i++)
	{
		char tmp[51];
		scanf("%s",tmp);
		for(int j=0;j<r;j++)
		{
			if(tmp[j]=='S') //�� �� 
			{ 
				map[i][j]=1;
				a=i;b=j;
			}
			else if(tmp[j]=='D') // �� 
			{ 
				map[i][j]=2;
				goala=i;
				goalb=j;
			}
			else if(tmp[j]=='*')	//�� 
			{
				map[i][j]=-1;
				qwater.push({i,j});
			}
			else if(tmp[j]=='X') //�� 
				map[i][j]=-2;
		
			d[i][j]=-1;
		}	
	}
	//printf("����\n");	print(); 	printf("goala=%d goalb=%d\n",goala,goalb);	//����� 

	//printf("hi");
	d[a][b]=0; 	//a,b �� ����ġ 
	q.push({a,b});
	// �� -1, �� -2, �� 2, ���� 1 �����  0 
	while(!q.empty())
	{			
		int qwsize=qwater.size();
		//cout<<qwsize;
		for(int j=0;j<qwsize;j++)
		{
			int wa=qwater.front().x,wb=qwater.front().y;
			qwater.pop();
			for(int i=0;i<4;i++)
			{
				int nwa=wa+dir[i][0],nwb=wb+dir[i][1];
				if(nwa>=c||nwb>=r||nwa<0||nwb<0) continue;
				if(map[nwa][nwb]==1||map[nwa][nwb]==0)
				{
				map[nwa][nwb]=-1;
				qwater.push({nwa,nwb});
				}
			}
		}
		
		int qsize=q.size();
		for(int j=0;j<qsize;j++)
		{
			a=q.front().x; b=q.front().y;
			q.pop();
			for(int i=0;i<4;i++)
			{
				int na=a+dir[i][0],nb=b+dir[i][1];
				if(na>=c||nb>=r||na<0||nb<0||d[na][nb]>=0||map[na][nb]<0) continue;	 
		 	    q.push({na,nb});
	   	    	d[na][nb]=d[a][b]+1;
            		// printf("��� ��ġ�� %d %d\n",na,nb); //����� 
			}			
		}
			// printf("d�迭�� ���\n"); printd(); //��� �� 
			
		if(d[goala][goalb]>=0)
			break;

	}	
	//printf("�� ä����\n");	print();
		
	
	if(d[goala][goalb]==-1)
		printf("KAKTUS");
	else 
	printf("%d",d[goala][goalb]);
}
