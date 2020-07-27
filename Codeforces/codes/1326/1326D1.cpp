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

bool palin(string ch)
{
    string te = ch;
    reverse(all(ch));
    return ch == te;
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
        int n;
        n = s.length();
        vector< vector< bool > > dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++)
            dp[i][i] = true;
        for(int len=2;len<=n;len++)
        {
            for(int i=0;i<n-len+1;i++)
            {
                if(len==2)
                    dp[i][i+len-1] = (s[i] == s[i+len-1]);
                
                else
                    dp[i][i+len-1] = ((s[i] == s[i+len-1]) & dp[i+1][i+len-2]);
            }
        }
        if(dp[0][n-1])
            cout<<s<<endl;
        else
        {
            int l = 0, r = n-1;
            int ans = -1, st = -1;
            while(s[l++] == s[r--]);
            l--;
            for(int i=0;i<=l;i++)
                for(int k=i;k<n-i;k++)
                {
                    if(dp[k][n-i-1] & i+n-k > ans)
                        ans = i+n-k, st = i;
                }
                    
            for(int i=0;i<=l;i++)
                for(int k=i;k<n-i;k++)
                    if(dp[i][k] & i+k+1 > ans)
                        ans = i+k+1, st = k+1;
            

            for(int i=0;i<st;i++)
                cout<<s[i];
            for(int i=n-ans+st;i<n;i++)
                cout<<s[i];
            cout<<endl;
        }
    }
}