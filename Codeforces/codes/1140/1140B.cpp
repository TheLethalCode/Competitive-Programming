#include<bits/stdc++.h>
using namespace std;


int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int l=-1,r=-1;
        FOR(i,n)
            if(s[i]=='>')
            {
                l=i;
                break;
            }
        FOR(i,n)
            if(s[n-1-i]=='<')
            {
                r=n-1-i;
                break;
            }
        if(l==-1 || r==-1)
            cout<<0;
        else
            cout<<min(l,n-r-1);
            nl;
    }
}