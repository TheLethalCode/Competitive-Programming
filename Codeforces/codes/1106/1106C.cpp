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
    multiset<int> a;
    for(int i=0;i<n;i++)
    {
        int b;
        cin>>b;
        a.insert(b);
    }
    lli ans=0;
    auto en=a.rbegin();
    for(auto it=a.begin();it!=a.end();it++,en++)
    {   
        lli x=*it,y=*en;
        ans+=(x+y)*(x+y);
    }
    cout<<ans/2<<endl;
}