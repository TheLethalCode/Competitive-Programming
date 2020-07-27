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
        lli a,x,fl=0;
        string b="@";
        while(b != "=")
        {
            if(!fl)
                cin>>a>>b>>x;
            else
            {
                cin>>b;
                if(b!="=")
                    cin>>x;
            }
            fl=1;
            // cout<<b<<flush<<endl;
            if(b == "*")
                a*=x;
            else if(b == "+")
                a+=x;
            else if(b == "/")
                a/=x;
            else if(b == "-")
                a-=x;
        }
        cout<<a<<endl;
    }
}