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
    int x,y,z;
    cin>>x>>y>>z;
    int a,b,c;
    cin>>a>>b>>c;
    int fl=0;
    a-=x;
    int tot=a+b+c;
    if(a<0)
        goto lab;
    if( a+b < y)
        goto lab;
    tot -= y;
    if( tot < z)
        goto lab;
    fl=1;
    cout<<"YES";
    lab: if(!fl) cout<<"NO";
    cout<<endl;
}