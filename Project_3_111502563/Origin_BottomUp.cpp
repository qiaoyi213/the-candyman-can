#include<bits/stdc++.h>
using namespace std;

int dp[20000][20000];
int n;
int maxx(int a, int b, int c){
	return max(max(a,b),c);
}
int minn(int a, int b, int c){
	return min(min(a,b),c);
}
int main(){
	int t;
	int cnt = 1;
	cin>>t;
	while(t--){
		cin>>n;
		int candies[n];
		for(int i=0;i<n;i++)cin>>candies[i];
		int sum = 0;
		for(int i=0;i<n;i++)sum += candies[i];
		memset(dp,0,sizeof(dp));
		dp[0][0] = 1;
		for(int i=0;i<n;i++){ // i-th candies to c1 and c2
			for(int c1=sum;c1>=0;c1--){
				for(int c2=sum;c2>=0;c2--){
					if(dp[c1][c2]){
						dp[c1+candies[i]][c2] = 1;
						dp[c1][c2+candies[i]] = 1;
					}
				}
			}
		}
		int ans = INT_MAX;
		for(int i=0;i<=sum;i++){
			for(int j=0;j<=sum;j++){
				if(dp[i][j]){
					ans = min(ans, max(max(i,j), sum-i-j) - min(min(i,j),sum-i-j));
				}
			}
		}

		printf("Case %d: %d\n", cnt , ans);
		cnt++;
	}
	return 0;
}
