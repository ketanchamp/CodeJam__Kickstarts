//==================================================================================================================
// Problem Name        : Bus Routes
// Link to problem     : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d83bf
// Author              : ktcoder
// Description         : Binary Search
//==================================================================================================================

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll tests,n;
    cin>>tests;
    int cases=0;
    while(tests--){
    	cout<<"Case #"<<++cases<<": ";
    	ll n,d;
    	cin>>n>>d;
    	vector<ll> v(n);
    	for(int i=0;i<n;i++) cin>>v[i];
    	ll ans=1;
		ll l=1ll,r=d;

    	while(l<=r){
    		ll mid=(l+r)/2;
    		ll prev=mid;
    		int f=0;
    		for(int i=0;i<n;i++){
    			ll check=(prev/v[i])*v[i];
    			if(check==prev){
    				continue;
				}
				else if(check<prev){
					check=((prev/v[i])+1ll)*(v[i]);
					if(check>d){
						r=mid-1;
						f=1;
						break;
					}
					prev=check;
				}
			}
			if(f){
				continue;
			}
			else{
				ans=max(ans,mid);
				l=mid+1;
			}
		}
		cout<<ans<<endl;

	}

    return  0;
}