//==================================================================================================================
// Problem Name        : Workout
// Link to problem     : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3f5b
// Author              : ktcoder
// Description         : Sortings and Constructive
//==================================================================================================================

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ll tests,n,k;
    cin>>tests;
    int cases=1;
    while(tests--){
        cin>>n>>k;
        vector<ll> v;
        ll prev;
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            if(i>0){
               v.push_back(x-prev);
            }
            prev=x;
        }
        sort(v.begin(),v.end());
        ll l=1,r=v[n-2];
        ll ans=r;
        while(l<=r){
            ll mid=(l+r)/2;
            ll sum=0;
            for(int i=0;i<n-1;i++){
                sum+=ceil((double)(v[i])/(double)(mid));
                sum-=1;
            }
            if(sum<=k){
                r=mid-1;
                ans=min(ans,mid);
            }
            else l=mid+1;
        }
        cout<<"Case #"<<cases++<<": "<<ans<<endl;

    }

    return 0;
}