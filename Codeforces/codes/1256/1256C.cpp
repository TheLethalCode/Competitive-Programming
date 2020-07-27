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
    int n, m, d;
    cin>>n>>m>>d;
    vi v(m), sum(m);
    FOR(i, m)
        cin>>v[i];
    for(int i=m-1;i>=0;i--)
    {
        if(i==m-1)
            sum[i]=v[i];
        else
            sum[i]=sum[i+1]+v[i];
    }
    vi ans(m);
    int pr = 0;
    for(int i=0;i<m;i++)
        ans[i] = min(d+pr, n-sum[i]+1), pr=ans[i]+v[i]-1;
    if(pr+d <= n)
        cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        int j=0;
        for(int i=1;i<=n;i++)
        {
            if(j<m & i == ans[j])
            {
                for(int r=0;r<v[j];r++)
                    cout<<j+1<<" ";
                i+=v[j]-1, j++;
            }
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}