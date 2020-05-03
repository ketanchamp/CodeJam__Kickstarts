//================================================================================================================
// Problem Name        : Expogo
// Link to problem     : https://codingcompetitions.withgoogle.com/codejam/round/000000000019fef2/00000000002d5b62
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
#define mod (1000000000)
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
bool check[100]={0};
int main()
{
	ss
	ll t;
	cin>>t;
	int co=0;
	while(t--){
		memset(check,0,100);
		cout<<"Case #"<<++co<<": ";
		ll x,y;
		cin>>x>>y;
		ll sum=abs(x)+abs(y);
		if(sum%2==0){                           //Sum should be Odd as first step is 1(2^0)
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		ll power_of_2=1,ch=0;
		vector<ll> v;
		int lo=0;
		while(ch<sum){
			ch+=power_of_2;
			v.pb(power_of_2);
			power_of_2*=2;
			lo++;
		}
		ll diff=ch-sum;
		diff/=2;
		vector<int> index;
		int in=0;
		while(diff>0){
			if(diff%2==1){
				index.pb(in);
				check[in]=1;
			}
			diff/=2;
			in++;
		}
		in=0;

		index.pb(100000);
		ll odd,even,evenx=0;
		if(x%2==0) {
			evenx=1;
			even=x;
			odd=y;
		}
		else{
			even=y;
			odd=x;
		}
		int neg=0;
		if(even<0) neg=1;
		vector<int> bits;
		even=abs(even);
		ll mc=abs(even);
		while(even>0){
			bits.pb(even%2);
			even/=2;
		}
		vector<char> ans(lo);
		for(int i=0;i<lo;i++) ans[i]='Z';
		ll yo=2;
		for(int i=0;i<bits.size();){
			if(bits[i]&&check[i]){
				if(i+1<bits.size()){
					if(bits[i+1]) bits[i+1]=0;
					else bits[i+1]=1;
				}
				else bits.pb(1);
				int j=i+1;
				while(j<bits.size()&&!bits[j]){
					if(j+1<bits.size()){
						if(bits[j+1]) bits[j+1]=0;
						else bits[j+1]=1;
					}
					else {bits.pb(1);break;}
					j++;
				}
				i=j;
			}
			else i++;
		}
		in=0;

		for(int i=0;i<bits.size();i++) {
			if(bits[i]==1){
				if(neg){
					if(evenx){
						if(check[i]){
							ans[i]=('E');
						}
						else ans[i]=('W');
					}
					else{
						if(check[i]){
							ans[i]=('N');
						}
						else ans[i]=('S');
					}
				}
				else{
					if(evenx){
						if(check[i]){
							ans[i]=('W');
							in++;
						}
						else ans[i]=('E');
					}
					else{
						if(check[i]){
							ans[i]=('S');
							in++;
						}
						else ans[i]=('N');
					}
				}
			}
		}
		if(odd<0) neg=1;
		else neg=0;
		for(int i=0;i<lo;i++){
			if(ans[i]=='Z'){
				if(neg){
					if(evenx){
						if(check[i]){
							ans[i]=('N');
							in++;
						}
						else ans[i]=('S');
					}
					else{
						if(check[i]){
							ans[i]=('E');
							in++;
						}
						else ans[i]=('W');
					}
				}
				else{
					if(evenx){
						if(check[i]){
							ans[i]=('S');
							in++;
						}
						else ans[i]=('N');
					}
					else{
						if(check[i]){
							ans[i]=('W');
							in++;
						}
						else ans[i]=('E');
					}
				}
			}
		}
		ll xx=0,yy=0;
		for(int i=0;i<lo;i++) {
			cout<<ans[i];
		}
		cout<<endl;

	}


	return  0;
}