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
    int n;
    cin>>n;
    vector< vector<  pa  > > ed(n+1);
    FOR(i,n-1)
    {
        int a,b;
        cin>>a>>b;
        ed[a].pb({b,i});
        ed[b].pb({a,i});
    }
    for(int i=1;i<=n;i++)
    {
        if(ed[i].size() >= 3)
        {
            vi ans(n-1,-1);
            int cnt=0;
            for(auto st : ed[i])
                ans[st.se] = cnt++;
            FOR(j,n-1)
                if(ans[j]==-1)
                    ans[j] = cnt++;
            debugA(ans);cout<<endl;
            return 0;
        }
    }
    FOR(i,n-1)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}