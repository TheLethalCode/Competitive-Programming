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
    string s;
    cin>>s;
    int n=s.size();
    vector< vli > v(26,vli(n+1,0));
    
    FOR(i,n)
    {
        FOR(j,26)
            v[j][i+1] = v[j][i];
        v[s[i]-'a'][i+1]++;
    }

    lli ans = 0;
    FOR(i,26)
        ans = max(ans, v[i][n]);
    ans = max(ans, ans*(ans-1)/2);
    
    vector< vli > temp(26,vli(26,0));
    FOR(i, n)
    {
        int k = s[i] - 'a';
        FOR(j,26)
        {
            if(j==k)
                continue;
            temp[k][j] += v[j][n] - v[j][i+1];
        }
    }
    FOR(i,26)
        FOR(j,26)
            ans = max(ans, temp[i][j]);
    cout<<ans<<endl;
}