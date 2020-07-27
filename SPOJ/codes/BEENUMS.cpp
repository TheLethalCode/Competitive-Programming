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
    lli n;
    cin>>n;
    while(n!=-1)
    {
        lli te=9+12*(n-1);
        lli x=sqrt(te);
        cout<< ((( x * x == te ) && (x % 6 == 3))? "Y":"N" );
        cout<<endl;
        cin>>n;
    }
}