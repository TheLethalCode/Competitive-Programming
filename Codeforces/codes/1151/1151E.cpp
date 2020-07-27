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
#define pb emplace_back

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define all(v) v.begin(), v.end()
#define sz(a) (int)(a.size())
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)
#define perc %

int n;
lli dis(int l, int r){ return 1LL*l*(n-r+1);}
int main(int argc, char **argv)
{
    crap;
    lli ans = 0;
    cin>>n;
    vi v(n);
    FOR(i, n) cin>>v[i];
    FOR(i, n){
        ans+=dis(v[i], v[i]);
        if(i) ans-=dis(min(v[i], v[i-1]), max(v[i], v[i-1]));
    }
    cout<<ans<<endl;
}