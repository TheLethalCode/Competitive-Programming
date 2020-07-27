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
#define sz(a) (int)(a.size())
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

#define perc %

int main(int argc, char **argv)
{
    crap;
    int n, p, st=0, cnt;
    cin>>n>>p;
    vi v(n), pref(n, 0);
    FOR(i, n) cin>>v[i];
    sort(all(v));
    FOR(i, n) st = max(st, v[i]-i), cnt = v[n-1]-st;
    FOR(i, n) pref[max(0, v[i]-st)]++;
    FOR(i, n-1) pref[i+1]+=pref[i];
    FOR(i, n) if(pref[i] >= p) cnt=min(cnt, max(0, i-pref[i]+p));
    cout<<cnt<<endl;
    FOR(x, cnt) cout<<st+x<<" ";
    cout<<endl;
}