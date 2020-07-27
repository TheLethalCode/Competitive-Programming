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
    int n,k;
    cin>>n>>k;
    vector< pa > v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].fi;
        v[i].se = i;
    }
    sort(v.begin(),v.end());
    vi ans(n);
    vector< vi > hash(k);
    int r=1,fl=0;
    for(int i=0;i<n;i++)
    {
        ans[v[i].se]=(r%k)+1;
        r++;
        if(!hash[r%k].empty() && hash[r%k].back()==v[i].fi)
        {
            fl=1;
            break;
        }
        hash[r%k].pb(v[i].fi);
    }
    if(fl)
        cout<<"NO";
    else
    {
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
            cout<<ans[i]<<" ";
    }
    cout<<endl;
}