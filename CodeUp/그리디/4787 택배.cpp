#include<iostream>
#include<algorithm> 
using namespace std;

pair<int, int> pii;

typedef struct In{
    int from,to,cost;
}In;

In ins[10001];

// ������, ����� ������ ���� 
int cmp(In a, In b){    
    if(a.to!=b.to)
        return a.to < b.to;
    return a.from < b.from;
}

int box[2001];        // �� �������� Ʈ���� ��� �ִ� ������  

int main(){
    int ans=0;
    int n,c,m;
    cin>>n>>c>>m;

    for (int i=0; i < m; i++){ 
        scanf("%d %d %d", &ins[i].from, &ins[i].to, &ins[i].cost); 
    }
    
    sort(ins, ins + m , cmp);
    for(int i=0;i<m;i++){

        In now = ins[i]; // �̹��� �� �Է� ��
    
        int already = 0; // �־��� ���������� �ִ� ���� ��
        
        for (int i = now.from; i < now.to; i++) 
            already=max(already,box[i]);

        // ������ �ִ� ������ �ѱ� �� �ֱ� ������ 
        // ���� ���� �ִ� ������ ������ ���� �뷮�� ���� ���� ����
        int add = min(now.cost, c - already); 
        
        for (int i = now.from; i < now.to; i++) { //������ �߰� 
            box[i] += add; 
        } 
    
        ans += add; // �߰��� ��ŭ�� �信 ������ 
    }
    
    cout << ans << "\n";
    return 0;
} 
