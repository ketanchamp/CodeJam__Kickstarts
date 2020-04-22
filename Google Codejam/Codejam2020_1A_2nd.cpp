//================================================================================================================
// Problem Name        : Pascal Walk
// Link to problem     : https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd74/00000000002b1353
// Author              : ktcoder
// Description         : Use of Bit Manipulation and constructive algorithm
//================================================================================================================

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ss  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define present(container, element) (container.find(element) != container.end())
#define ss  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define all(c) c.begin(), c.end()
#define pb push_back
#define mp make_pair
#define mod (1000000000 + 7)
#define inf (1e10+9)
#define fi first
#define se second
#define MAXN   1000001
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> new_set;

long long fastpow(long long n, long long x, long long m){

	long long ret = 1;

	while(x){
		if(x&1) (ret*=n)%=m;
		x>>=1;
		(n*=n)%=m;
	}

	return ret;
}
ll add(ll a,ll b){
	return((a%mod)+(b%mod))%mod;
}
ll prod(ll a,ll b){
	a%=mod;
	b%=mod;
	return ((a%mod)*(b%mod)%mod);
}
int main()
{
	ss
	int n,tests;
	cin>>tests;
	int cases=0;
	while(tests--){
		cases++;
		cout<<"Case #"<<cases<<": "<<endl;
		cin>>n;
		ll n1=n;
		n-=30;
		vector<int> bits_of_n;
		while(n>0){
			bits_of_n.pb(n%2);
			n/=2;
		}
		int flag=0;
		ll count_of_rows=0;
		for(int i=0;i<bits_of_n.size();i++){
			if(bits_of_n[i]==0){
				cout<<i+1<<" ";
				if(flag==0) cout<<1<<endl;
				else cout<<i+1<<endl;
				count_of_rows++;
			}
			else{
				count_of_rows+=(ll)pow(2,i);
				if(flag==0){
					for(int j=1;j<=i+1;j++){
						cout<<i+1<<" "<<j<<endl;
					}
					flag=1;
				}
				else{
					for(int j=i+1;j>=1;j--){
						cout<<i+1<<" "<<j<<endl;
					}
					flag=0;
				}
			}

		}
		int bits_size=bits_of_n.size();
		while(count_of_rows!=n1){
			if(flag) cout<<bits_size+1<<" "<<bits_size+1<<endl;
			else cout<<bits_size+1<<" "<<1<<endl;
			count_of_rows++;
			bits_size++;
		}



	}


	return  0;
}