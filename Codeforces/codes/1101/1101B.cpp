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
    string s;
    cin>>s;
    vi v(255);
    int n=s.length();
    int a=-1,b=-1,c=-1,d=-1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='[' && a==-1)
            a=i;
        else if(s[i]==':' && a!=-1 && b==-1)
            b=i;
    }
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]==']' && d==-1)
            d=i;
        else if(s[i]==':' && d!=-1 && c==-1)
            c=i;
    }
    int cnt=0;
    if(a!=-1 && b!=-1 && c!=-1 && d!=-1 && b<c)
    {
        for(int i=b+1;i<c;i++)
            if(s[i]=='|')
                cnt++;
        cout<<cnt+4;
    }
    else
        cout<<-1;
    cout<<endl;
}