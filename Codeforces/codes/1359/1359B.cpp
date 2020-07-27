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
    int t;
    cin>>t;
    while(t--){
        int n, m, x, y;
        cin>>n>>m>>x>>y;
        vector< string > v(n);
        FOR(i, n) cin>>v[i];
        if(2*x <= y){
            int cnt = 0;
            FOR(i, n) FOR(j, m) if(v[i][j]=='.') cnt++;
            cout<<cnt*x<<endl;
        }
        else{
            lli ans = 0;
            FOR(i, n){
                int cnt=0, j = 0;
                while(j<m){
                    cnt=0;
                    while(j<m && v[i][j] == '.')
                        cnt++, j++;
                    ans += (cnt/2)*y + (cnt&1)*x;
                    j++;
                }
            }
            cout<<ans<<endl;
        }
    }
}