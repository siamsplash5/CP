#include<bits/stdc++.h>
using namespace std;
int main()
{
	int s,n;
	scanf("%d %d",&s,&n);
	int W[n+1],P[n+1],DP[n+1][s+1];
	for(int i=1;i<=n;i++){
		scanf("%d %d",&W[i],&P[i]);
	}
	memset(DP,0,sizeof(DP));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=s;j++){
			DP[i][j]=DP[i-1][j];
			if(j-W[i]>=0){
				DP[i][j]=max(DP[i][j],DP[i-1][j-W[i]]+P[i]);
			}
		}
	}
	int ans=DP[n][s];
	printf("%d\n",ans);
	return 0;
}
