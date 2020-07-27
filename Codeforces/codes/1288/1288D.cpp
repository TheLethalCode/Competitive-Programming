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

int n, m;
int ed[300005][8];
int x, y;

bool can(int ans){
    vi mark(1<<m, -1);
    FOR(i, n){
        int tem = 0;
        FOR(j, m) if(ed[i][j]>=ans) tem+=(1<<j);
        mark[tem]=i;
    }
    FOR(i, 1<<m){
        if(mark[i]==-1) continue;
        FOR(j, 1<<m){
            if(mark[j]==-1) continue;
            if((i | j) == (1<<m)-1){
                x = mark[i], y=mark[j];
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char **argv)
{
    crap;
    cin>>n>>m;
    FOR(i, n) FOR(j, m) cin>>ed[i][j];
    int ans=0;
    for(int i=29;i>=0;i--){
        if(can(ans+(1<<i)))
            ans+=1<<i;
    }
    if(!ans)
        cout<<1<<" "<<1<<endl;
    else
        cout<<x+1<<" "<<y+1<<endl;
}