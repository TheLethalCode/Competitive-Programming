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

#define vpac vector< pair< char, char > >

int diff(string src, string des)
{
    int cnt = 0;
    for(int i=0;i<7;i++)
    {
        if(src[i] == '0' & des[i] == '1')
            cnt++;
        else if(src[i] == '1' & des[i] == '0')
            return -1;
    }
    return cnt;
}

int main(int argc, char **argv)
{
    crap;
    int n, k;
    cin>>n>>k;
    vector< string > s(n);
    FOR(i, n) cin>>s[i];
    reverse(all(s));

    vector< string > mp(10);
    mp[0] = "1110111";
    mp[1] = "0010010"; 
    mp[2] = "1011101";
    mp[3] = "1011011";
    mp[4] = "0111010"; 
    mp[5] = "1101011"; 
    mp[6] = "1101111";
    mp[7] = "1010010"; 
    mp[8] = "1111111";
    mp[9] = "1111011";

    vector< vector< vpac > > dp(n, vector< vpac >(2001));
    vector< vpa > num(n);

    for(int i=0;i<n;i++)
    {
        vector< vi > temp(8);
        for(int j=0;j<10;j++)
        {
            int re = diff(s[i], mp[j]);
            if(re != -1)
                temp[re].pb(j);
        }
        for(int te = 0; te<8;te++)
            if(!temp[te].empty())
                num[i].pb({te, temp[te].back()});
    }

    // for(int i=0;i<n;i++)
    // {   for(auto te : num[i])
    //         cout<<te.se<<":"<<te.fi<<" ";
    //     cout<<endl;
    // }
        
    vector< set<int> > ne(n);
    for(int i=0; i<n ; i++)
    {
        if(!i)
        {
            for(auto te : num[i])
                dp[i][te.fi].pb({'0'+te.fi, '0'+te.se}), ne[i].insert(te.fi);
            continue;
        }
        
        for(int pr : ne[i-1])
            for(auto te : num[i])
                if(pr + te.fi <= k)
                    dp[i][pr+te.fi].pb({'0'+te.fi, '0'+te.se}), ne[i].insert(pr+te.fi);
    }

    if(dp[n-1][k].empty())
        cout<<-1<<endl;
    else
    {
        string ans = "";
        int start = k;
        for(int i=n-1;i>=0;i--)
        {
            pa ma = dp[i][start][0];
            for(auto te : dp[i][start])
                if(te.se > ma.se)
                    ma = te;
            start -= ma.fi - '0', ans += ma.se;
        }
        cout<<ans<<endl;
    }    
}