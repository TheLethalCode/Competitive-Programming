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

int sol(string s)
{
    int n = s.size();
    vector< vi > dp(n, vi(3,0));
    for(int i=0;i<n;i++)
    {
        if(!i)
        {
            if(s[i]=='0')
                dp[i][1]=1;
            else
                dp[i][0]=dp[i][2]=1;
            continue;
        }
        dp[i][0]=dp[i-1][0];
        dp[i][1]=min(dp[i-1][0], dp[i-1][1]);
        dp[i][2]=min(dp[i-1][1], dp[i-1][2]);
        if(s[i]=='0')
            dp[i][1]++;
        else
            dp[i][0]++, dp[i][2]++;
    }
    return min3(dp[n-1][0], dp[n-1][1], dp[n-1][2]);
}

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        vi pref(n+1,0);
        for(int i=1;i<=n;i++)
        {
            pref[i] = pref[i-1];
            if(s[i-1] == '1')
                pref[i]++;
        }
        int ans = 1e9;
        for(int i=0;i<k;i++)
        {
            string temp = "";
            int te_a = 0, st;
            for(st=i;st<n;st+=k)
            {
                temp+=s[st];
                if(st>=k)
                    te_a += pref[st]-pref[st-k+1];
                else
                    te_a += pref[st];
            }
            te_a += pref[n] - pref[st-k+1];
            te_a += sol(temp);
            ans = min(ans, te_a);
        }
        cout<<ans<<endl;    
    }
}