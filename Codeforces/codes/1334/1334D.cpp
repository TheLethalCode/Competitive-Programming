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
    int t;
    cin>>t;
    while(t--)
    {
        lli n, l, r;
        cin>>n>>l>>r;
        vli v(n,0);
        if(l == n*(n-1)+1)
        {
            cout<<1<<endl;
            continue;
        }
        FOR(i,n-1)
            v[i+1]=v[i], v[i+1]+=2*(n-1-i);
        int pos = lower_bound(all(v), l) - v.begin();
        vi ans;
        lli st = v[pos-1]+1;
        int temp = pos;
        while(st<=r)
        {
            int cnt = temp+1;
            while(cnt<=n)
            {
                ans.pb(temp), ans.pb(cnt);
                st+=2, cnt++;
            }
            temp++;
            if(temp == n)
                ans.pb(1), st++;
        }
        for(int i=0;i<=r-l;i++)
            cout<<ans[l-v[pos-1]-1+i]<<" ";
        cout<<endl;
    }
}