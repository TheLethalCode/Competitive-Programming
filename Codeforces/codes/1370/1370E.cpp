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

// %
int func(vi ar){
    int n = ar.size(), ans = 0, temp = 0;
    FOR(i, n) temp = max(temp+ar[i], ar[i]), ans=max(ans, temp);
    return ans;
}

int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;
    string s, t, rem="";
    cin>>s>>t;
    vi c(2, 0);
    FORR(x, s) c[x-'0']++;
    FORR(x, t) c[x-'0']--;
    if(c[0] || c[1]) {
        cout<<-1<<endl;
        return 0;
    }
    vi ar, ar1;
    FOR(i, n) if(s[i]!=t[i]) ar.pb(s[i]=='0'?1:-1), ar1.pb(t[i]=='0'?1:-1);
    cout<<max(func(ar), func(ar1))<<endl;
}