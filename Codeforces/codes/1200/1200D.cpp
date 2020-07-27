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
    int n, k, orig=0;
    cin>>n>>k;
    vector<string> v(n);
    FOR(i, n) cin>>v[i];
    vector< vi > row(n+1, vi(n+1, 0)), col(n+1, vi(n+1, 0));
    vector< vpa > ch(n+1, vpa(n+1, {0, 0}));
    FOR(i, n){
        FOR(j, n){ 
            row[i+1][j+1] = row[i+1][j]+(v[i][j]=='B');
            col[i+1][j+1] = col[i][j+1]+(v[i][j]=='B');
        }
    }    
    FOR(i, n){
        if(!row[i+1][n]) {
            orig++;
            continue;
        }
        FOR(j, n-k+1){
            if(row[i+1][j+1+k-1]-row[i+1][j] == row[i+1][n]) ch[i+1][j+1].fi = 1;
        }
    }
    FOR(j, n){
        if(!col[n][j+1]) {
            orig++;
            continue;
        }
        FOR(i, n-k+1){
            if(col[i+1+k-1][j+1]-col[i][j+1] == col[n][j+1]) ch[i+1][j+1].se = 1;
        }
    }
    vector< vpa > ans(n+1, vpa(n+1, {0, 0}));
    for(int i=1;i<=n-k+1;i++){
        int temp = 0;
        for(int j=1;j<=k;j++) temp+=ch[i][j].se;
        ans[i][1].fi = temp;
        for(int j=k+1;j<=n;j++) 
            temp+=ch[i][j].se-ch[i][j-k].se, ans[i][j-k+1].fi = temp;
    }
    for(int j=1;j<=n-k+1;j++){
        int temp = 0;
        for(int i=1;i<=k;i++) temp+=ch[i][j].fi;
        ans[1][j].se = temp;
        for(int i=k+1;i<=n;i++) 
            temp+=ch[i][j].fi-ch[i-k][j].fi, ans[i-k+1][j].se = temp;
    }
    int fin = 0;
    FOR(i, n-k+1)
        FOR(j, n-k+1){
            fin = max(fin, ans[i+1][j+1].fi + ans[i+1][j+1].se);
        }
    cout<<orig +fin<<endl;
}