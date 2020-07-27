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
int n, m, cnt=0;
lli calc(vpa &cl, vi &rl){
    int si = cl.size();
    lli ans = 0;
    FOR(i, si-2){
        if(cl[i].se < cl[i+1].se || cl[i+2].se < cl[i+1].se)
            continue;
        int si = cl[i+1].se;
        int l = m;
        FOR(j, si) {
            l = min3(l, rl[cl[i+1].fi-1-j], rl[cl[i+1].fi+j]);
            l = min(l, rl[cl[i+2].fi+j]);
        }
        if(l == m) cnt++;
        ans+=l; 
    }
    return ans;
}

int main(int argc, char **argv)
{
    crap;
    cin>>n>>m;
    vector< string > v(n);
    FOR(i, n) cin>>v[i];
    vector< vi > r(m, vi(n, 0));
    FOR(i, n){
        int j=0;
        while(j<m){
            int k = j;
            while(k<m && v[i][k]==v[i][j]) k++;
            while(j<k) r[j][i]=k-j, j++;
        }
    }
    lli ans = 0;
    vector< vpa > cl(m);
    FOR(te, m){
        FOR(i, n){
            int j=i;
            while(j<n && v[j][te]==v[i][te])j++;
            cl[te].pb({i, j-i}), i=j-1;
        }
    }
    FOR(i, m){
        ans+=calc(cl[i], r[i]);
    }
    cout<<ans<<endl;
}