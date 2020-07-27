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
#define mp make_pair

#define nl cout<<endl;
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(auto i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

// %
int n, m, v[200005];
vi ed[200005];

bool can(int ans){
    if(ans > 400005) return true;
    vi temp[ans+1];
    FOR(i, n) {
        int cnt = !!v[i+1];
        for(int days : ed[i+1]){
            if(!cnt) break;
            if(days>ans) continue;
            temp[days].pb(i+1), cnt--;
        }
    }
    int bought = 0, cost=0;
    FOR(i, ans) for(int ty : temp[i+1]) bought+=min(i+1-bought, v[ty]);
    FOR(i, n) cost+=v[i+1]*2;
    return cost-bought<=ans;
}

int main(int argc, char **argv)
{
    crap;
    cin>>n>>m;
    FOR(i, n) cin>>v[i+1];
    FOR(i, m){
        int a, b;
        cin>>a>>b;
        ed[b].pb(a);
    }
    FOR(i, n) sort(ed[i+1].rbegin(), ed[i+1].rend());
    int ans = 1<<19;
    for(int i=18;i>=0;i--) if(can(ans-(1<<i))) ans-=1<<i;
    cout<<ans<<endl;
}