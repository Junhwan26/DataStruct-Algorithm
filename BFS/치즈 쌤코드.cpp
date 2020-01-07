

#include <stdio.h>// ġ��2 �ҽ�
#include <memory.h>
struct location{
    int x,y;
};
int A[102][102]; //�ִ������100�� ������������� +2 ũ�� �Ҵ�
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};   //4���� üũ
location queue[10000];  
int main(){
    int n,m,i,j,k,check,time=0;
    int rear=-1,front=0,end=0;
    location cur;
    memset(A,-1,sizeof(int)*102*102);   //������ 0�� ��ġ�� �ʱ����� -1�� �ʱ�ȭ
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&A[i][j]);   //���� ��������� �ε��� 1~n,m���� �Է�
      
  
    while(end==0){  //end�� ���̻� ġ� ������� 1
        end=1;
        front=0;
        rear=-1;
        queue[++rear].x=1;
        queue[rear].y=1;
        A[1][1]=2;  //���ΰ���� �ܺΰ����� ���̸� �α����� �ܺΰ��⸦ 2�� �������
        while(front<=rear){
            cur=queue[front++];
            for(i=0;i<4;i++){
                if(A[cur.x+dx[i]][cur.y+dy[i]]==0){
                    queue[++rear].x=cur.x+dx[i];
                    queue[rear].y=cur.y+dy[i];
                    A[cur.x+dx[i]][cur.y+dy[i]]=A[cur.x][cur.y];
                }
            }
        }   //���۾��̳����� �ܺΰ���� 2�� ������ 
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                check=0;
                if(A[i][j]==1){ //ġ� �߰������� ���˸��� �ܺΰ����� 2�� ���
                    end=0;
                    for(k=0;k<4;k++){
                        if(A[i+dx[k]][j+dy[k]]==2)
                            check++;
                    }
                    if(check>=2) //���˸��� 2���̻��ΰ��
                        A[i][j]=3;  //��Ե����� 3�� �־���
                }
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(A[i][j]>=2)   //�ܺΰ���� ��Ե�������� 0�� ����� �ʱ�ȭ�۾�
                    A[i][j]=0;
            }
        }
        time++; //�ð�����
    }
    printf("%d\n",time-1);
}
 


