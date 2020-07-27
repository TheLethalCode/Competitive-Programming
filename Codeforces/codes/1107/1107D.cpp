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

vector< vi > sum;

bool extract(int i,int j,int x)
{
    int val=sum[i+x-1][j+x-1]-sum[i-1][j+x-1]-sum[i+x-1][j-1]+sum[i-1][j-1];
    if(val==0 || val==(x*x))
        return true;
    return false;
}

int main()
{
    crap;
    int n;
    cin>>n;
    vector< vector<bool> > v(n);
    sum.resize(n+1,vi(n+1,0));
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<s.length();j++)
        {
            if(s[j]=='0')
                v[i].pb(0),v[i].pb(0),v[i].pb(0),v[i].pb(0);
            if(s[j]=='1')
                v[i].pb(0),v[i].pb(0),v[i].pb(0),v[i].pb(1);
            if(s[j]=='2')
                v[i].pb(0),v[i].pb(0),v[i].pb(1),v[i].pb(0);
            if(s[j]=='3')
                v[i].pb(0),v[i].pb(0),v[i].pb(1),v[i].pb(1);
            if(s[j]=='4')
                v[i].pb(0),v[i].pb(1),v[i].pb(0),v[i].pb(0);
            if(s[j]=='5')
                v[i].pb(0),v[i].pb(1),v[i].pb(0),v[i].pb(1);
            if(s[j]=='6')
                v[i].pb(0),v[i].pb(1),v[i].pb(1),v[i].pb(0);
            if(s[j]=='7')
                v[i].pb(0),v[i].pb(1),v[i].pb(1),v[i].pb(1);
            if(s[j]=='8')
                v[i].pb(1),v[i].pb(0),v[i].pb(0),v[i].pb(0);
            if(s[j]=='9')
                v[i].pb(1),v[i].pb(0),v[i].pb(0),v[i].pb(1);
            if(s[j]=='A')
                v[i].pb(1),v[i].pb(0),v[i].pb(1),v[i].pb(0);
            if(s[j]=='B')
                v[i].pb(1),v[i].pb(0),v[i].pb(1),v[i].pb(1);
            if(s[j]=='C')
                v[i].pb(1),v[i].pb(1),v[i].pb(0),v[i].pb(0);
            if(s[j]=='D')
                v[i].pb(1),v[i].pb(1),v[i].pb(0),v[i].pb(1);
            if(s[j]=='E')
                v[i].pb(1),v[i].pb(1),v[i].pb(1),v[i].pb(0);
            if(s[j]=='F')
                v[i].pb(1),v[i].pb(1),v[i].pb(1),v[i].pb(1);    
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            sum[i][j]=v[i-1][j-1]+sum[i][j-1];
        }
        for(int j=1;j<=n;j++)
        {
            sum[i][j]+=sum[i-1][j];
        }
    }
    vi fac;
    for(int i=n;i>=2;i--)
        if(n%i==0)
            fac.pb(i);
    
    int val=1;
    for(auto k:fac)
    {
        for(int i=1;i<=n;i+=k)
            for(int j=1;j<=n;j+=k)
                if(!extract(i,j,k))
                    goto lab;
        val=k;
        break;
        lab:;
    }
    cout<<val<<endl;
}