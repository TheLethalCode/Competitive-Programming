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

vector< vli > v;
lli solve(vli B, int ty, int y, int i=-1, int k=-1){
    int m = B.size(); lli init = 0;
    FOR(j, m) {
        lli el = 0;
        if(i!=-1) el+=ty?v[i][j]:v[j][i];
        if(k!=-1) el+=ty?v[k][j]:v[j][k];
        B[j]-=el;
    }
    while(y--) {
        int pos = max_element(all(B)) - B.begin();
        init+=B[pos], B[pos]=0;
    }
    return init;
}

lli solve1(int x, vli &A, vli &B, int ty=1){
    int n = A.size(), m=B.size();
    lli ans = 0;
    if(!x) return solve(B, ty, 4);
    if(x==1){
        FOR(i, n) ans = max(ans, solve(B, ty, 3, i)+A[i]);
        return ans; 
    }
    FOR(i, n) FOR(k, i) ans = max(ans, solve(B, ty, 2, i, k)+A[i]+A[k]);
    return ans;
}

int main(int argc, char **argv)
{
    crap;
    int n, m;
    cin>>n>>m;
    lli ans = 0;
    v.resize(n, vli(m));
    vli row(n, 0), cols(m, 0);
    FOR(i, n) FOR(j, m) cin>>v[i][j], row[i]+=v[i][j], cols[j]+=v[i][j];
    FOR(i, 2)
        ans=max3(solve1(i, row, cols), solve1(i, cols, row, 0), ans);
    if(n<=m) ans = max(solve1(2, row, cols), ans);
    else ans = max(solve1(2, cols, row, 0), ans);
    cout<<ans<<endl;
}