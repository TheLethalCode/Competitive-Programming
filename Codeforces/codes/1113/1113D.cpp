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

bool ch(string k)
{
    int n=k.length();
    for(int i=0;i<=n/2;i++)
        if(k[i]!=k[n-1-i])
            return false;
    return true;
}

bool och(string s)
{
    int n=s.length();
    for(int i=1;i<n;i++)
    {
        string r=s.substr(0,i),l=s.substr(i,n-i);
        if(ch(l+r) && (l+r)!=s)
            return true;
    }
    return false;
}

int main()
{
    crap;
    string s;
    cin>>s;
    int n = s.length();
    set<char> q;
    for(int i=0;i<n/2;i++)
        q.insert(s[i]);
    if(q.size()<2)
        cout<<"Impossible";
    else if(och(s))
        cout<<1;
    else
        cout<<2;
    cout<<endl;
}