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
    int t,te=0;
    cin>>t;
    while(te++<t)
    {
        int n;
        cin>>n;
        double the = 2*asin(0.25/n);
        double ans = n + n*cos(the) + sin(the/2);
        cout<<fixed<<setprecision(2)<<"Case "<<te<<": "<<ans*2*n<<endl;
    }
}