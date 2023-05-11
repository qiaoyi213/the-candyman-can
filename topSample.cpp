#include<bits/stdc++.h>
using namespace std;
int dp[201][1000][1000];
int sum[201];
int arr[201];
int n ;
int solve(int index , int f1 , int f2)
{

    int f3=sum[index-1]-(f1+f2);
    if(index > n)
        return f1-f2;
    if(dp[index][f1][f2]!=-1)return dp[index][f1][f2];
    int ans=1e9;
    ans=min(ans,solve(index + 1 , max(f1+arr[index],max(f2,f3)),min(f1+arr[index],min(f2,f3))));
    ans=min(ans,solve(index + 1 , max(f1 ,max(f2+arr[index],f3)),min(f1,min(f2+arr[index],f3))));
    ans=min(ans,solve(index + 1 , max(f1 ,max(f2,f3+arr[index])),min(f1,min(f2,f3+arr[index]))));
    return dp[index][f1][f2] = ans;

}
int32_t main(){
    int t,u=1;
    cin>>t;
	while(t--)
    {

		cin>>n;

        for (int i=1; i<=n; i++)
        	cin>>arr[i];
		sum[0]=0;
        for (int i=1; i<=n; i++)
            sum[i]=sum[i-1]+arr[i];
        for(int i=0; i<=n; i++)
            for(int j=0; j<=sum[n]; j++)
                for(int k=0; k<=sum[n]; k++)
                    dp[i][k][j]=-1;

        printf("Case %d: %d\n",u++,solve(0,0,0));
    }

    return 0;

}
