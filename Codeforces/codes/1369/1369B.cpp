#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
#define pa pair<int,int>
#define pal pair<lli,lli>
#define vi vector< int >
#define vli vector< lli >
#define vpa vector< pa >
#define vpal vector< pal >
#define fi first
#define se second
#define pb push_back

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define all(v) v.begin(), v.end()
#define sz(a) a.size()
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

#define perc %

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--){
        int n, first = 1;
        cin>>n;
        string s, temp, ans;
        cin>>s;
        for(int i=n-1;i>=0;i--){
            int j = i;
            while(j>=0 && s[j]=='0') j--;
            if(j<0){
                for(;i>=0;i--) temp.pb(s[i]);
            }
            else if(i==j){
                temp.pb(s[i]);
            }
            else s[j]='0', i=j+1; 
        }
        reverse(all(temp));
        cout<<temp<<endl; 
    }
}