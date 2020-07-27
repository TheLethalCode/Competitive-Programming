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
int n, m, v[17][10001];
bool ed[17][17], cross[17][17];
int dp[16][1<<16];

int calc(int end, int sub){

    if(dp[end][sub]!=-1)
        return dp[end][sub];
    
    int ne = sub - (1<<end);
    FOR(i, n){
        if(!(ne & (1<<i))) continue;
        if(ed[end][i] && calc(i, ne))
            return dp[end][sub] = 1; 
    }
    return dp[end][sub]=0;
}

bool can(int ans){

    if(n==1){
        FOR(i, m-1) if(abs(v[0][i]-v[0][i+1])< ans) return false;
        return true;
    }

    FOR(i, n) FOR(j, n) ed[i][j]=cross[i][j]=false;
    FOR(j, n) FOR(k, n){
        if(j==k) continue;
        int fl=0, ch=0;
        FOR(i, m) if(abs(v[j][i]-v[k][i]) < ans) {
                fl=1;
                break;
            }
        FOR(i, m-1) if(abs(v[j][i]-v[k][i+1])<ans){
                ch=1;
                break;
            }
        if(!fl) ed[j][k] = true;
        if(!ch) cross[j][k]=true;
    }
    
    FOR(i, n){
        FOR(i, 1<<n) FOR(j, n) dp[j][i] = -1;
        FOR(j, n) dp[j][1<<j]=(i==j);
        FOR(j, n) if(calc(j, (1<<n)-1) && cross[j][i]) return true;
    }
    return false;
}

int main(int argc, char **argv)
{
    crap;
    cin>>n>>m;
    FOR(i, n) FOR(j, m) cin>>v[i][j];
    int ans = 0;
    for(int i=29;i>=0;i--) if(can(ans+(1<<i))) ans+=1<<i;
    cout<<ans<<endl;
}