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
    int n;
    cin>>n;
    vi v,ha(1e6+1,0);
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        ha[a]++;
    }
    for(int i=1;i<=1e6;i++)
        if(ha[i])
            v.pb(i);
    
    n=v.size();
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        int j=v[i];
        int temp=0;
        while(true)
        {
            int it=lower_bound(v.begin()+i,v.end(),j)-v.begin();
            if(it-i)
                temp=max(temp,v[it-1]%v[i]);
            if(temp==v[i]-1 || it==n || j>v[n-1]+v[i])
                break;
            j+=v[i];
        }
        ans=max(ans,temp);
    }
    cout<<ans<<endl;

}