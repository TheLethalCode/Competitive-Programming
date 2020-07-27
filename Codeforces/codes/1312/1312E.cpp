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

// %
int v[501], dp[501][501], dpx[501][501], n;

int calc(int i, int j){
    if(dpx[i][j]!=-1) return dpx[i][j];
    if(dp[i][j] != -1) return dpx[i][j]=1;
    int mi = 10000;
    for(int k=i;k<j;k++) mi = min(mi, calc(i, k) + calc(k+1, j));
    return dpx[i][j]=mi;
}

int main(int argc, char **argv)
{
    crap;
    cin>>n;
    FOR(i, n) cin>>v[i];
    FOR(i, n) FOR(j, n) dp[i][j]=dpx[i][j]=-1;
    FOR(i, n) dp[i][i]=v[i];
    for(int l=2;l<=n;l++){
        for(int i=0, j=i+l-1;j<n;j++, i++){
            for(int k=i;k<j;k++){
                if(dp[i][k]!=-1 && dp[i][k] == dp[k+1][j])
                    dp[i][j] = dp[i][k]+1;
            }
        }
    }
    cout<<calc(0, n-1)<<endl;
}