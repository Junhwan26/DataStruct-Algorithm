#include<iostream>
using namespace std;
int dp[1001];
int in[1001];

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>in[i];
	int ans;
	z
	for(int i=1;i<=n;i++)
	{
		dp[i]=in[i];
		for(int j=1;j<=i;j++){
			if(in[j]<in[i])
				dp[i]=max(dp[i],dp[j]+in[i]);
		}
		ans=max(dp[i],ans);
		
	}
	
	cout<<ans;
}
