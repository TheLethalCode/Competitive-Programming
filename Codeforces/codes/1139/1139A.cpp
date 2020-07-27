#include<bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    crap;
    int n;
    string s;
    cin>>n>>s;
    lli ans=0;
    for(lli i=0;i<n;i++)
    {
        if(((int)(s[i]-'0'))%2==0)
            ans+=i+1;
    }
    cout<<ans<<endl;
}