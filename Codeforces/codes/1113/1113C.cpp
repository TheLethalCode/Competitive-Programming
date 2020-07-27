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
    map<int,lli> qo,qe;
    int xo=0;
    qo[0]++;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        xo^=a;
        if(i%2)
            qo[xo]++;
        else
            qe[xo]++;
    }
    lli ans=0;
    for(auto a:qe)
    {
        ans+=(a.se)*(a.se-1)/2;
    }
    for(auto a:qo)
    {
        ans+=(a.se)*(a.se-1)/2;
    }
    cout<<ans<<endl;
}