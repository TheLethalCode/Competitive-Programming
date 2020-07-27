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
    lli b,k;
    cin>>b>>k;
    vli v(k);
    for(int i=0;i<k;i++)
        cin>>v[i];
    lli sum=0;
    for(int i=0;i<k-1;i++)
        sum+=(v[i]%2)*(b%2);
    sum+=v[k-1]%2;
    if(sum%2)
        cout<<"odd";
    else
    {
        cout<<"even";
    }
    cout<<endl;
    
}