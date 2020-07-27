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
        int n;
        cin>>n;
        map<string,int> wtf;
        string te;
        getline(cin,te);
        while(n--)
        {
            string s;
            getline(cin,s);
            wtf[s]++;
        }
        for(auto r:wtf)
            cout<<r.fi<<" "<<r.se<<endl;
        cout<<endl;
    }
}