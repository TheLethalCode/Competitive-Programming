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

int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;
    vi v(n-1);
    FOR(i,n-1)
        cin>>v[i];
    map<int,int> m;
    int ans=0;
    int fl=1;
    FOR(i,n-1)
    {
        ans+=v[i];
        m[ans]++;
        if(m[ans] > 1 || !ans)
            fl=0;
    }
    if(!fl)
        cout<<-1;
    else
    {
        vi val;
        int ans=0;
        val.pb(1);
        FOR(i,n-1)
        {
            ans+=v[i];
            val.pb(1+ans);
        }
        if(*max_element(all(val)) - *min_element(all(val)) != n-1)
            cout<<-1;
        else
        {
            int k=*min_element(all(val));
            FOR(i,n)
                cout<<val[i]-k+1<<" ";
        }
    }
    nl;
}