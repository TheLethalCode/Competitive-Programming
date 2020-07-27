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
vpa ans;
vpa left;

bool comp(vi &l, vi &r){
    int i=0;
    while(l[i]==r[i]) i++;
    return l[i] < r[i];
}

void solve(vector< vi > &v, int l, int r, int pos, vi &le)
{    
    if(l == r){
        le.pb(v[l][3]);
        return ;
    }

    int pr = l-1, cur = l;
    vi te;
    while(cur<=r){
        while(cur<r && v[cur][pos] == v[cur+1][pos]) cur++;
        solve(v, pr+1, cur, pos+1, te);
        if(te.size() >= 2){
            ans.pb({te[0], te[1]});
            te.clear();
        }
        pr = cur, cur++;
    }
    for(int el : te)
        le.pb(el);
}

int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;
    vector< vi > v(n, vi(4));
    FOR(i, n) {
        FOR(j, 3) cin>>v[i][j];
        v[i][3]=i;
    }
    sort(all(v));
    vi le;
    solve(v, 0, n-1, 0, le);
    FOR(i, n/2) cout<<ans[i].fi+1<<" "<<ans[i].se+1<<endl;
}