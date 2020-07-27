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

// %

int main(int argc, char **argv)
{
    crap;
    int n,m,k;
    cin>>n>>m>>k;
    vi a(n), b(m);
    FOR(i,n) cin>>a[i];
    FOR(j,m) cin>>b[j];
    vi cntA, cntB;
    for(int i=0;i<n;i++)
    {
        if(!a[i])
            continue;
        int j = i;
        while(j<n && a[j])
            j++;
        cntA.pb(j-i);
        i=j;
    }

    for(int i=0;i<m;i++)
    {
        if(!b[i])
            continue;
        int j = i;
        while(j<m && b[j])
            j++;
        cntB.pb(j-i);
        i=j;
    }

    sort(all(cntA));
    sort(all(cntB));

    vli cA(n+1,0), cB(m+1,0);
    set<int> fact;
    fact.insert(1);
    for(int i=2; i <= sqrt(k); i++)
    {
        if((k % i))
            continue;
        fact.insert(i);
        if(k/i != i)
            fact.insert(k/i);
    }
    fact.insert(k);

    lli ans = 0;
    for(int te : cntA)
    {
        for(int i=1;i<=te;i++)
            cA[i] += te - i + 1;
    }
    for(int te : cntB)
    {
        for(int i=1;i<=te;i++)
            cB[i] += te - i + 1;
    }

    for(int f : fact)
    {
        if(f <= n && k/f <= m)
            ans += cA[f] * cB[k/f];
    }
    cout<<ans<<endl;
}