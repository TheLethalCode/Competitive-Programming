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
    string s,t;
    cin>>s>>t;
    int n=s.length(),m=t.length();
    int fl=0;
    if(n==m)
    {
        vi v(n,0);
        for(int i=0;i<n;i++)
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                v[i]=1;
        
        vi k(n,0);
        for(int i=0;i<n;i++)
            if(t[i]=='a' || t[i]=='e' || t[i]=='i' || t[i]=='o' || t[i]=='u')
                k[i]=1;
        
        for(int i=0;i<n;i++)
            if(v[i]!=k[i])
                goto lab;
        fl=1;
        lab:;
    }
    if(fl)
        cout<<"Yes";
    else
    {
        cout<<"No";
    }
    cout<<endl;
    
}