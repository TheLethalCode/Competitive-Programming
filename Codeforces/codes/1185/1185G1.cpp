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

lli solve(vi &te, int pr, int left){
    if(left == 0) return 1;
    lli ans = 0;
    FOR(i, 3) {
        if(i!=pr && te[i]){
            vi c = te;
            c[i]--;
            ans = (ans + te[i] * solve(c, i, left-1)) % mod;
        }
    }
    return ans;
}

int main(int argc, char **argv)
{
    crap;
    int n, T;
    cin>>n>>T;
    vpa v(n);
    FOR(i, n) cin>>v[i].fi>>v[i].se;
    vector< pair<int, vi> > sum[226];
    FOR(i, n){
        FOR(j, 226){
            FORR(x, sum[j]){
                if(x.fi == i) continue;
                x.fi = i, x.se.pb(i);
                sum[j+v[i].fi].pb(x);
            }
        }
        pair< int, vi > temp;
        temp.fi = i, temp.se.pb(i);
        sum[v[i].fi].pb(temp);
    }
    lli ans = 0;
    FORR(q, sum[T]){
        vi te(3, 0);
        int n = sz(q.se);
        FORR(x, q.se) te[v[x].se-1]++;
        ans = (ans + solve(te, -1, n))%mod;
    }
    cout<<ans<<endl;
}