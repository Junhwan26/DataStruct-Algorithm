#include<iostream>
using namespace std;

int in[9][9];
int check[8][8];	// �ѹ� �湮�ߴ� �� üũ 
int dir[4][2]={{1,0}, {0,1}, {-1,0}, {0,-1}};	// ����迭 

int ans;

int search(int a,int b){  //flood fill ��� ���� 

	check[a][b]=1;
	int cnt=1;
	for(int i=0;i<4;i++){
		int na=a+dir[i][0], nb=b+dir[i][1];
		
		if(check[na][nb]||!in[na][nb])
			continue;
		
		if(in[na][nb]==in[a][b])
			cnt+=search(na,nb);
	}
	
	return cnt;
}

int main(){
	for(int i=1;i<=7;i++){
		for(int j=1;j<=7;j++){
			cin>>in[i][j];
		}
	}
	for(int i=1;i<=7;i++){
		for(int j=1;j<=7;j++){
			if(search(i,j)>=3)
				ans++;
		}
	}
	
	cout<<ans;
}
