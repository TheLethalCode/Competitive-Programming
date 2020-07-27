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
#define pp pop_back

#define nl cout<<endl;
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(auto i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

// %
int main(int argc, char **argv)
{
    crap;
    int n, m;
    cin>>n>>m;
    vi ed[n+1], cur(n+1, -1);
    FOR(i, m){
        int a, b;
        cin>>a>>b;
        ed[a].pb(b), ed[b].pb(a); 
    }
    vpa t(n);
    FOR(i, n) cin>>t[i].fi, t[i].se=i+1;
    sort(all(t));
    FOR(i, n){
        int cnt=1;
        vi tem;
        tem.pb(0), tem.pb(2*n);
        for(int el : ed[t[i].se])
            if(cur[el]!=-1) tem.pb(cur[el]);
        sort(all(tem));
        int k = tem.size();
        FOR(i, k-1) if(tem[i+1] - tem[i] > 1) {
            cnt = tem[i]+1;
            break;
        }
        if(cnt != t[i].fi){
            cout<<-1<<endl;
            return 0;
        }
        cur[t[i].se]=cnt;
    }
    FOR(i, n) cout<<t[i].se<<" ";
    cout<<endl;
}