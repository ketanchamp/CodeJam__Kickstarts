//==================================================================================================================
// Problem Name        : Plates
// Link to problem     : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d40bb
// Author              : ktcoder
// Description         : Dynamic Programming
//==================================================================================================================

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll tests;
    cin>>tests;
    int cases=1;
    while(tests--){
        int n,k,p;
        cin>>n>>k>>p;
        int sum[n][k+1]={{0}};
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                int x;
                cin>>x;
                sum[i][j+1]=sum[i][j]+x;
            }
        }
        int dp[n+1][p+1]={{0}};
        memset(dp,0,sizeof(dp));
        ll ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=p;j++){
                dp[i][j]=0;
                for(int l=0;l<=min(j,k);l++){
                    dp[i][j]=max(dp[i-1][j-l]+sum[i-1][l],dp[i][j]);
                }
            }
        }

       cout<<"Case #"<<cases++<<": "<<dp[n][p]<<endl;
    }

    return  0;
}