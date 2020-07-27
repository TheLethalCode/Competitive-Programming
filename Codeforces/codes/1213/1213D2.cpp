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
    int n, k;
    cin>>n>>k;
    vi ans[200001];
    FOR(i, n){
        int x, cnt=0;
        cin>>x;
        while(x) ans[x].pb(cnt++), x/=2;
    }
    int fin = 1e9;
    FOR(i, 200000) {
        int temp = 0;
        if(ans[i+1].size() < k) continue;
        sort(all(ans[i+1]));
        FOR(j, k) temp+=ans[i+1][j];
        fin = min(fin, temp);
    }
    cout<<fin<<endl;
}