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
    int q;
    cin>>q;
    while(q--)
    {
        lli l,r,d;
        cin>>l>>r>>d;
        if(d<l)
            cout<<d;
        else if(r==d)
            cout<<2*d;
        else if(!(r%d))
            cout<<r+d;
        else
        {
            lli k=ceil(r*1.0/d);
            cout<<k*d;
        }
        cout<<endl;
    }
}