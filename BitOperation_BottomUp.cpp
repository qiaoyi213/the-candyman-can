#include<bits/stdc++.h>
#pragma GCC optimize ("O3")

using namespace std;
bitset<25000> bs[25000];

int n;
int maxx(int a, int b, int c){
	return max(max(a,b),c);
}
int minn(int a, int b, int c){
	return min(min(a,b),c);
}
int32_t main(){
	int t;
  	ios::sync_with_stdio(0);
  	cin.tie(0);
	int cnt = 1;
	cin>>t;
	while(t--){
		cin>>n;
		int candies[n];
		for(int i=0;i<n;i++)cin>>candies[i];
		int sum = 0;
		for(int i=0;i<n;i++)sum += candies[i];
		for(int i=0;i<=sum;i++)bs[i] = 0;
		bs[0] = 1;

		for(int i=0;i<n;i++){ // i-th candies to c1 and c2
			for(int c1=sum;c1>=0;c1--){
				bs[c1+candies[i]] = bs[c1+candies[i]] |  bs[c1];
				bs[c1] = bs[c1] | (bs[c1] << candies[i]);	
			}
		}

		int sans = INT_MAX;
		for(int i=0;i<=sum;i++){
			for(int j=i;j<=sum;j++){
				if(bs[i][j]){
					sans = min(sans, max(max(i,j), sum-i-j) - min(min(i,j),sum-i-j));
				}
			}
		}

		cout<<"Case "<<cnt<<": "<<sans<<endl;	
		cnt++;
	}
	return 0;
}

