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
    lli w1,h1,w2,h2;
    cin>>w1>>h1>>w2>>h2;
    lli ans=0;
    ans= 2*(h1+h2) + w1 + w2 + abs(w1-w2) + 4;
    cout<<ans<<endl;
}