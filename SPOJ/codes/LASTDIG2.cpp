#include<bits/stdc++.h>
using namespace std;
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
int pom(lli a,lli b)
{
    if(!b)
        return 1;
    if(b%2)
        return (pom(a,b-1)*a)%10;
    int t = pom(a,b/2);
    return (t*t)%10; 
}
int main()
{
    crap;
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        lli b;
        cin>>b;
        int a = *s.rbegin() - '0';
        cout<<pom(a,b)<<endl;
    }
}