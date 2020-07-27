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
    int n, m;
    cin>>n>>m;
    vi v(m), ans(m);
    FOR(i, m) cin>>v[i];
    int cv = 0;
    vi ma(m);
    for(int i=m-1;i>=0;i--)
        cv = max(cv, i+v[i]), ma[i]=cv;;
    if(cv > n)
        cout<<-1<<endl;
    else
    {
        int pr = 0, shi = 0, fl=0;
        for(int i=0;i<m;i++)
        {
            if(!i)
            {
                ans[i]=0;
                continue;
            }
            if(fl)
                ans[i] = pr+1, pr++;
            else
            {    
                int te = min(n-ma[i]-shi, v[i-1]-1);
                ans[i] = pr+1+te, pr = ans[i], shi+=te;
                if(n == ma[i]+shi)
                    fl=1;
            }
        }
        if(m==1)
        {
            if(v[0]==n)
                cout<<1;
            else
                cout<<-1;
        }
        else if(!fl)
            cout<<-1;
        else
            FOR(i, m)
                cout<<ans[i]+1<<" ";
        cout<<endl;
    }
}