#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
#define vi vector< int >
#define vli vector< lli >
#define endl "\n"
#define pa pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

int main()
{
    crap;
    int n,m;
    cin>>n>>m;
    vi v(m),has(n+1,0);
    for(int i=0;i<m;i++)
        cin>>v[i];
    int cnt=0;
    vi ans;
    for(int i=0;i<m;i++)
    {
        if(has[v[i]-1]==0)
            cnt++;
        has[v[i]-1]++;
        if(cnt==n)
        {
            for(int i=0;i<n;i++)
            {
                has[i]--;
                if(has[i]==0)
                    cnt--;
            }
            ans.pb(1);
        }
        else
            ans.pb(0);
    }
    for(int i=0;i<m;i++)
        cout<<ans[i];
    cout<<endl;
}