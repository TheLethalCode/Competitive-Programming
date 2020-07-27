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

#define nl cout<<"\n"
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(int i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

int n,k=0;
vector< vi > ed;
vector< int > func;

int rec(int u)
{
    if(ed[u].empty())
        return 1;

    int ans;
    if(!func[u])
        ans = 0;
    else
        ans = 1e9;
    for(int v : ed[u])
    {
        if(!func[u])
            ans += rec(v);
        else
            ans = min(ans, rec(v));
    }
    return ans;
}

int main(int argc, char **argv)
{
    crap;
    cin>>n;
    func.resize(n+1);
    ed.resize(n+1);
    for(int i=0;i<n;i++)
        cin>>func[i+1];
    for(int i=0;i<n-1;i++)
    {
        int a;
        cin>>a;
        ed[a].pb(i+2);
    }
    for(int i=1;i<=n;i++)
        if(ed[i].empty())
            k++;

    cout<<k-rec(1)+1<<endl;
}