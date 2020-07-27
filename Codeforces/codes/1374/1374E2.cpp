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
    int n, m, k;
    cin>>n>>m>>k;
    vi cnt(5, 0), mark(4, 0), as;
    vpal v[4];
    lli ret = 1e18, ans=0;
    FOR(i, n){
        int x, y, z;
        cin>>x>>y>>z;
        v[2*y+z].pb({x, i});
    }
    if(min(sz(v[1]), sz(v[2])) + sz(v[3]) < k || ( sz(v[3])<k && sz(v[3])+ 2*(k-sz(v[3])) > m)){
        cout<<-1<<endl;
        return 0;
    }

    int hi = min3(sz(v[1]), sz(v[2]), k), lo = max(0, k-sz(v[3]));
    mark[0] = 0, mark[1] = mark[2] = hi, mark[3] = k-hi;
    FOR(i, 4) v[i].pb({2*mod, n+i}), sort(all(v[i]));
    
    // Make set size M
    FOR(i, 4) FOR(j, mark[i]) ans+=v[i][j].fi;
    while(hi+k>m){
        ans-= v[1][hi-1].fi+v[2][hi-1].fi-v[3][k-hi].fi, hi--;
        mark[1] = mark[2] = hi, mark[3] = k-hi;
    }
    FOR(i, 4) cnt[i]=mark[i];
    FOR(i, m-(hi+k)){
        int qw = 2*mod, in;
        FOR(j, 4) if(qw > v[j][cnt[j]].fi) qw = v[j][cnt[j]].fi, in = j;
        ans+=qw, cnt[in]++;
    }
    ret = min(ret, ans), as = cnt;
    
    // Going down for different x for Alice and Bob
    for(int i=hi-1;i>=lo;i--){
        // Remove 2 conform elements and two smallest elements
        int temp = 0;
        if(mark[1]--==cnt[1]) cnt[1]--, temp--, ans-=v[1][cnt[1]].fi;
        if(mark[2]--==cnt[2]) cnt[2]--, temp--, ans-=v[2][cnt[2]].fi;
        while(temp < 0){
            int qw = 2*mod, in;
            FOR(j, 4) if(qw > v[j][cnt[j]].fi) qw = v[j][cnt[j]].fi, in = j;
            ans+=qw, cnt[in]++, temp++;
        }
        if(mark[3]++==cnt[3]){
            int qw = 0, in=4;
            FOR(j, 4) if(cnt[j]>mark[j] && qw < v[j][cnt[j]-1].fi) qw = v[j][cnt[j]-1].fi, in = j;
            ans-=qw, cnt[in]--;
            ans+=v[3][cnt[3]].fi, cnt[3]++;
        }
        if(ret > ans) as = cnt, ret=ans;
    }
    cout<<ret<<endl;
    FOR(i, 4) FOR(j, as[i]) cout<<v[i][j].se+1<<" ";
    cout<<endl;
}