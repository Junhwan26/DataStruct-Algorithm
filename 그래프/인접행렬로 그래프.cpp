#include<stdio.h>
int v,e; // ������ ����, �� ���� 
int graph[1001][1001]; // �׷��� ������ �����ϴ� ������� 

int main()
{
	scanf("%d %d",&v,&e);
	for(int i =0,a,b;i<e;i++)
	{
		scanf("%d %d",&a,&b);
		graph[a][b] = graph[b][a] = 1; // ������ a,b ������ �� ���� 
	}
	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=v;j++)
		{
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}	
 } 
