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

vi v;
int n;
int fl=0;

bool check(int x,int sum)
{
    if(!(sum%360) && x==0)
        return true;
    if(x==0)
        return false;
    return check(x-1,sum+v[x-1]) || check(x-1,sum-v[x-1]);
}

int main()
{
    crap;
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    if(check(n,0))
        cout<<"YES";
    else
        cout<<"NO";
    cout<<endl;
}