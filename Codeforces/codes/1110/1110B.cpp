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
    int n,m,k;
    cin>>n>>m>>k;
    vi v(n),st(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=1;i<n;i++)
        st[i]=v[i]-v[i-1]-1;
    sort(st.begin(),st.end());
    int cnt=n;
    lli ans=n;
    for(int i=0;cnt>=k;i++,cnt--)
        ans+=st[i];
    cout<<ans<<endl;
}