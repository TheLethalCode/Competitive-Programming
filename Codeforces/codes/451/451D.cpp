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
    // cin>>n;
    string s;
    cin>>s;
    n=s.length();
    lli oa=0,ob=0,ea=0,eb=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='a')
        {
            oa+=(i%2!=0);
            ea+=(i%2==0);
        }
        else
        {
            ob+=(i%2!=0);
            eb+=(i%2==0);   
        }
    }
    lli even=0,odd=0;
    odd+=oa*ea+ob*eb;
    even+=oa*(oa-1)/2 + oa + ob*(ob-1)/2 + ob;
    even+=ea*(ea-1)/2 + ea + eb*(eb-1)/2 + eb;
    cout<<odd<<" "<<even<<endl;
}