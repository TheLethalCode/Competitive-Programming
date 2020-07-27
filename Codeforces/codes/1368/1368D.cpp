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
int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;
    vli v(n), ans(n, 0);
    FOR(i, n) cin>>v[i];
    for(int i=19;i>=0;i--){
        int cnt=0;
        FOR(j, n) if((v[j]&(1<<i))) cnt++;
        FOR(j, cnt) ans[j]+=1<<i;
    }
    lli an = 0;
    FOR(i, n) an+=ans[i]*ans[i];
    cout<<an<<endl;
}