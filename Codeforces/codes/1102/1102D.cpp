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
    string s;
    cin>>s;
    vi c(3,0);
    for(int i=0;i<n;i++)
        c[s[i]-'0']++;
    int ans=n/3;
    int i=0;
    while(c[0]<ans)
    {
        int x=s[i]-'0';
        if(c[x]>ans)
            s[i]='0',c[0]++,c[x]--;
        i++;
    }
    i=n-1;
    while(c[2]<ans)
    {
        int x=s[i]-'0';
        if(c[x]>ans)
            s[i]='2',c[2]++,c[x]--;
        i--;
    }
    i=n-1;
    while(c[0]>ans)
    {
        if(s[i]=='0')
            s[i]='1',c[1]++,c[0]--;
        i--;
    }
    i=0;
    while(c[2]>ans)
    {
        if(s[i]=='2')
            s[i]='1',c[1]++,c[2]--;
        i++;
    }
    cout<<s<<endl;
}