//================================================================================================================
// Problem Name        : Pattern Matching
// Link to problem     : https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd74/00000000002b3034
// Author              : ktcoder
// Description         : Use of String Manipulation
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
	fast_io;
    int no_of_strings,tests;
    cin>>tests;
    int cases=0;
    while(tests--){
    	cases++;
    	cin>>no_of_strings;
    	string st;
    	vector<string>  v;
    	int maxi=0;
    	for(int i=0;i<no_of_strings;i++){
    		cin>>st;
    		v.pb(st);
    		maxi=max(maxi,(int)st.size());
		}
		int f=0;
		string s1="";
		bool vis[no_of_strings]={0};
		int in[no_of_strings];
		for(int i=0;i<maxi;i++){
				set<char> s;
				char bc;
			for(int j=0;j<no_of_strings;j++){
				in[j]=v[j].size()-1;
				if(!vis[j]){
				   if(v[j].size()<=i) {vis[j]=1; continue;}
				   if(v[j][i]=='*') {vis[j]=1; continue;}
				   	 s.insert(v[j][i]);
				   	 bc=v[j][i];
				}
			}
			if(s.size()>1){
				f=1;
				break;
			}
			if(s.size()==1){
				s1+=bc;
			}
		}

		memset(vis,0,sizeof(vis));
		string s2="";
		for(int j=0;j<100;j++){
			set<char> s;
			char bc;
			for(int i=0;i<no_of_strings;i++){
			  if(!vis[i]){
			  	if(in[i]<0) {vis[i]=1; continue;}
				if(v[i][in[i]]=='*') {vis[i]=1; continue;}
			  		bc=v[i][in[i]];
			  		s.insert(v[i][in[i]--]);
			  }
			}
			if(s.size()>1){
				f=1;
				break;
			}
			if(s.size()>0) {
			  s2=bc+s2;
			}
		}

		if(f) cout<<"Case #"<<cases<<": *"<<endl;
		else{
			string ans=s1;
			for(int i=0;i<no_of_strings;i++){
				for(int j=0;j<v[i].size();j++){
					if(v[i][j]!='*'){
						ans+=v[i][j];
					}
				}
			}
			ans+=s2;
			cout<<"Case #"<<cases<<": "<<ans<<endl;
		}


	}

    return  0;
}