//================================================================================================================
// Problem Name        : Pascal Walk
// Link to problem     : https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd74/00000000002b1353
// Author              : ktcoder
// Description         : Use of Bit Manipulation and constructive algorithm
//================================================================================================================

#include<bits/stdc++.h>
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
int main()
{

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