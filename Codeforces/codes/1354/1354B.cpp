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
int n;

bool can(int ans, vector< vi > ar)
{
    if(ans > n)
        return true;
    for(int i=0;i<=n-ans;i++)
        if(ar[i+ans][0]-ar[i][0] > 0 & ar[i+ans][1]-ar[i][1] > 0 & ar[i+ans][2]-ar[i][2] > 0)
            return true;
    return false;
}

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        n=s.size();
        vector< vi > ar(n+1, vi(3,0));
        for(int i=0;i<n;i++)
            ar[i+1]=ar[i], ar[i+1][s[i]-'1']++;
        
        int ans = 1<<25;
        for(int i=24;i>=0;i--)
            if(can(ans-(1<<i), ar))
                ans -= 1<<i;
        
        if(!ar[n][0] | !ar[n][1] | !ar[n][2])
            cout<<0<<endl;
        else
            cout<<ans<<endl;
    }
}