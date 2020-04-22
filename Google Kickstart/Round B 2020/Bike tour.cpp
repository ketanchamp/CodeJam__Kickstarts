//==================================================================================================================
// Problem Name        : Bike Tour
// Link to problem     : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d82e6
// Author              : ktcoder
// Description         : basic
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
    	ll n;
    	cin>>n;
    	vector<ll> v(n);
    	for(int i=0;i<n;i++){
    		cin>>v[i];
		}
		int ans=0;
		for(int i=1;i<n-1;i++){
			if(v[i]>v[i-1]&&v[i]>v[i+1]) ans++;
		}
		cout<<ans<<endl;
	}

    return  0;
}