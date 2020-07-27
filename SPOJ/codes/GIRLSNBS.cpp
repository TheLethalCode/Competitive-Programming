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
    int g,b;
    cin>>g>>b;
    while(g!=-1)
    {
        int sm=min(g,b),bi=max(g,b);
        cout<<(int)ceil(bi*1.0/(sm+1))<<endl;
        cin>>g>>b;
    }
}