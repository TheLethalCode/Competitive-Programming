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
    int n,m;
    cin>>n>>m;
    vector< string > v(n);
    FOR(i,n) cin>>v[i];
    vector< pair< string, string > > dub;
    vector< string > sing;
    vi mark(n,0);
    FOR(i,n)
    {
        for(int j=i+1;j<n;j++)
        {
            if(!mark[j])
            {
                string temp = v[i];
                reverse(all(temp));
                if(temp == v[j])
                {
                    dub.pb({v[i],v[j]});
                    mark[i] = mark[j] = 1;
                    break;
                }
            }
        }
        if(!mark[i])
        {
            string temp = v[i];
            reverse(all(temp));
            if(temp == v[i])
                sing.pb(v[i]);
        }
    }
    string ans = "";
    for(int k = 0;k < dub.size(); k++)
        ans += dub[k].fi;

    int l = sing.size();
    for(int i = 0 ; i < (l?1:0);i++)
        ans += sing[i];

    int r = dub.size();
    for(int k = r-1;k>=0; k--)
        ans += dub[k].se;

    cout<<ans.size()<<endl<<ans<<endl;
}