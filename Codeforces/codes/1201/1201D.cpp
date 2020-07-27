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

map< int, lli > mp[200005];
vi b;
vpa tr;
int la=0;

lli solve(int r, int c){
    if(mp[r].count(c)) return mp[r][c];
    if(r == la){
        int wid = tr[r].se - tr[r].fi;
        return mp[r][c] = wid + min(abs(tr[r].se - c), abs(tr[r].fi - c));
    }
    if(tr[r].se==-1) {
        if(r==1) return mp[r][c] = b[0]+solve(r+1, b[0]);
        return mp[r][c] = solve(r+1, c) + 1;
    }
    
    lli ans = 1e18, wid = tr[r].se - tr[r].fi, temp;
    auto it = lower_bound(all(b), tr[r].se), it1 = lower_bound(all(b), tr[r].fi);

    temp = abs(c-tr[r].fi) + wid;
    if(it!=b.end()) ans =  min(ans, temp + *it - tr[r].se + 1 + solve(r+1, *it));
    if(it!=b.begin()) it--, ans = min(ans, temp + tr[r].se - *it + 1 + solve(r+1, *it));

    temp = abs(c-tr[r].se) + wid;
    if(it1!=b.end()) ans =  min(ans, temp + *it1 - tr[r].fi + 1 + solve(r+1, *it1));
    if(it1!=b.begin()) it1--, ans = min(ans, temp + tr[r].fi - *it1 + 1 + solve(r+1, *it1));

    return mp[r][c]=ans;
}

int main(int argc, char **argv)
{
    crap;
    int n, m, k, q;
    cin>>n>>m>>k>>q;
    tr.assign(n+1, {m+1, -1});
    FOR(i, k){
        int a, b;
        cin>>a>>b;
        tr[a].fi = min(tr[a].fi, b);
        tr[a].se = max(tr[a].se, b);
        la = max(a, la);
    }
    b.resize(q);
    FOR(i, q) cin>>b[i];
    sort(all(b));
    cout<<solve(1, 1)<<endl;
}