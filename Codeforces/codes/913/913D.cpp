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

int n, T;
vi t, sc;

bool comp(int lhs, int rhs)
{
    return t[lhs-1] < t[rhs-1];
}


bool can(int ans, vi& v)
{
    if(ans > n)
        return false;
    vi ind;
    for(int i=0;i<n;i++)
    {
        if(sc[i] < ans)
            continue;
        ind.pb(i+1);
    }

    if(ind.size() < ans)
        return false;
    sort(all(ind), comp);
    int sum = 0, cnt = 0;
    for(int i : ind)
    {
        sum += t[i-1], v.pb(i), cnt++;
        if(sum > T)
            return false;
        if(cnt == ans)
            return true;
    }
    return false;    
}

int main(int argc, char **argv)
{
    crap;
    cin>>n>>T;
    t.resize(n), sc.resize(n);
    int fl=0;
    FOR(i, n) { cin>>sc[i]>>t[i]; if(t[i]<=T) fl = 1; }

    if(!fl)
    {
        cout<<0<<endl<<0<<endl;
        return 0;
    }

    int ans = 0;
    vi ansA;
    for(int i=24;i>=0;i--)
    {
        vi v;
        if(can(ans+(1<<i), v))
            ans+=1<<i, ansA = v;
    }
    cout<<ans<<endl;
    cout<<ansA.size()<<endl;
    for(int u : ansA)
        cout<<u<<" ";
    cout<<endl;
}