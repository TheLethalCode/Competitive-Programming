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
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        vi v(m);
        FOR(i,m) cin>>v[i];
        vector< vector<lli> > st(n+1,vli(26,0));
        FOR(i,n)
        {
            FOR(j,26)
                st[i+1][j] = st[i][j];
            st[i+1][s[i]-'a']++;
        }

        vli ans(26,0);
        FOR(i,m)
        {
            FOR(j,26)
            {
                ans[j]+=st[v[i]][j];
            }
        }
        FOR(j,26)
            cout<<ans[j]+st[n][j]<<" ";
        cout<<endl;
    }
}