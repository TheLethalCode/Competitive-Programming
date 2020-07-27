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
int m;

vi v(4*1e4+1, -1);
int solve(int n)
{
    FOR(i, 2*1e4+1) v[20000+i]=1e9;
    v[0] = 1e9;
    queue<int> q;
    q.push(n);v[n]=0;
    while(!q.empty()){
        int u = q.front();q.pop();
        if(u==m) return v[u];
        if(v[2*u] == -1) q.push(2*u), v[2*u] = v[u]+1;
        if(v[u-1] == -1) q.push(u-1), v[u-1] = v[u]+1;
    }
    return -1;
}

int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n>>m;
    cout<<solve(n)<<endl;
}