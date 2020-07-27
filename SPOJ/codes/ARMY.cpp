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
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int g=0,h=0;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            g=max(g,a);
        }
        for(int i=0;i<m;i++)
        {
            int a;
            cin>>a;
            h=max(h,a);
        }
        if(h>g)
            cout<<"MechaGodzilla";
        else
            cout<<"Godzilla";
        cout<<endl;
    }
}