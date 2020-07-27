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
    int x=0,y=0;
    while(n--)
    {
        char a;
        cin>>a;
        if(a=='+')
        {
            int p,q;
            cin>>p>>q;
            x=max(x,min(p,q));
            y=max(y,max(p,q));
        }
        else
        {
            int p,q;
            cin>>p>>q;
            if(x<=p && y<=q)
                cout<<"YES";
            else if(x<=q && y<=p)
                cout<<"YES";
            else
                cout<<"NO";
            cout<<endl;
        }
    }
}