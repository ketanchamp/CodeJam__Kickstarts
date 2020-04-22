//==================================================================================================================
// Problem Name        : Robot Path Decoding
// Link to problem     : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d83dc
// Author              : ktcoder
// Description         : Recursion
//==================================================================================================================

#include<bits/stdc++.h>
#define mod 1000000000
typedef long long ll;
using namespace std;
ll add(ll a,ll b){
	return((a%mod)+(b%mod))%mod;
}
ll prod(ll a,ll b){
	a%=mod;
	b%=mod;
	return ((a%mod)*(b%mod)%mod);
}
int i=0;
string s1;
ll n=0,s=0,w=0,e=0;
void recur(ll nu){
	ll cos=0,cow=0,con=0,coe=0;
	while(s1[i]!=')'&&i<s1.size()){
		if(s1[i]>='2'&&s1[i]<='9'){
		  ll ch=ll(s1[i]-'0');
		  i+=2;
		  recur(prod(nu,ch));
		}
		else{
		 if(s1[i]=='N') con++;
		 else if(s1[i]=='S') cos++;
		 else if(s1[i]=='E') coe++;
		 else cow++;
		 i++;
		}
	}
	n=add(n,prod(nu,con));
	e=add(e,prod(nu,coe));
	w=add(w,prod(nu,cow));
	s=add(s,prod(nu,cos));
	i++;
	return ;
}
int main()
{

    ll tests;
    cin>>tests;
    int cases=0;
    while(tests--){
    	cout<<"Case #"<<++cases<<": ";
    	n=0;s=0;w=0;e=0;
    	ll d;
    	i=0;
    	cin>>s1;
    	for(i=0;i<s1.size();){
    		if(s1[i]>='2'&&s1[i]<='9'){
    			ll num=(ll)(s1[i]-'0');
    			i+=2;
    			recur(num);
			}
			else{
				if(s1[i]=='N') n=add(n,1ll);
				else if(s1[i]=='S') s=add(s,1ll);
				else if(s1[i]=='E') e=add(e,1ll);
				else w=add(w,1ll);
				i++;
			}
		}

		ll col=(e)%mod;
		col=(col+mod-w)%mod;
		ll row=(s)%mod;
		row=(row+mod-n)%mod;
		cout<<col+1<<" "<<row+1<<endl;

	}


    return  0;
}