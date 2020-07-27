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
int n, m;

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        int a[n+1][m+1];
        FOR(i, n) FOR(j, m) cin>>a[i][j];
        vpa ed[n+m+1];
        FOR(i, n) FOR(j, m) {
            if(i+j==n+m-2-i-j) continue;
            int dis = min(i+j, n+m-2-i-j);
            ed[dis].pb({i, j});
        }
        int i=0, ans=0;
        while(!ed[i].empty()){
            int on = 0, ze = 0;
            for(auto el : ed[i]) (a[el.fi][el.se]==0?ze:on)++;
            ans+=min(on, ze), i++;
        }
        cout<<ans<<endl;
    }
}