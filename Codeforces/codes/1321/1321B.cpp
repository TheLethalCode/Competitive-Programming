#include<bits/stdc++.h>
using namespace std;

#define modN 1000000007
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

#define mod %

vli v;

bool comp(int l, int r)
{
    return v[l] - l < v[r] - r;
}

int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;
    vli dp(n);
    v.resize(n);
    FOR(i,n) cin>>v[i], dp[i]=i;
    sort(all(dp), comp);
    
    lli ma = 0, temp=0;
    int i=0;
    while(i < n)
    {
        if(!i)
        {
            temp += v[dp[i]];
            i++;
            continue;
        }
        if(v[dp[i]] - dp[i] == v[dp[i-1]] - dp[i-1])
            temp+=v[dp[i]];
        else
        {
            ma = max(ma, temp);
            temp = v[dp[i]];
        }
        i++;
    }
    ma = max(ma, temp);
    cout<<ma<<endl;
}