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
    int n=s.length();
    vi pi(n,0);
    for(int i=1;i<n;i++)
    {
        int j=pi[i-1];
        while(j>0 && s[j]!=s[i])
            j=pi[j-1];
        if(s[j]==s[i])
            j++;
        pi[i]=j;
    }
    vi sub(n+1,0);
    for(int i=0;i<n;i++)
        sub[pi[i]]++;
    for(int i=n;i>0;i--)
        sub[pi[i-1]] += sub[i];
    int j=n,ch=0;
    while(j>0)
    {
        j=pi[j-1];
        if(sub[j]>1 && j)
        {
            ch=1;
            break;
        }
    }
    if(ch)
        cout<<s.substr(0,j);
    else
        cout<<"Just a legend\n";
    cout<<endl;
}