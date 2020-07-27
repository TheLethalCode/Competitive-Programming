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
    vi v(n);
    vi arr(1e4+1,0);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        arr[v[i]]++;
    }
    sort(v.begin(),v.end());
    lli x=v[n-1],y=1;
    for(int i=1;i<=x;i++)
        if(x%i==0)
            arr[i]--;
    for(int te:v)
        if(arr[te])
            y=te,arr[te]--;
    cout<<x<<" "<<y<<endl;
}