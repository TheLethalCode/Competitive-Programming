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

lli cnt=0;

void merge(vi &v,int st,int mid,int en)
{
    vi l,r;
    for(int i=st;i<=mid;i++)
        l.push_back(v[i]);
    for(int i=mid+1;i<=en;i++)
        r.push_back(v[i]);
    int lc=0,rc=0,s=st;
    int n=l.size(),m=r.size();
    while(lc<n && rc<m)
    {
        if(l[lc] <= r[rc])
            v[s++]=l[lc++];
        else
        {
            // cout<<"True "<<lc<<" "<<l[lc]<<" "<<mid-lc-st+1<<endl;
            v[s++]=r[rc++];
            cnt+=mid-lc-st+1;
        }
    }
    while(lc<n)
        v[s++]=l[lc++];
    while(rc<m)
        v[s++]=r[rc++];
}

void sort(vi& v,int st, int en)
{
    if(st>=en)
        return;
    int mid = st+en;
    mid/=2;
    sort(v,st,mid);
    sort(v,mid+1,en);
    merge(v,st,mid,en);
}

int main()
{
    crap;
    int t;
    cin>>t;
    while(t--)
    {
        cnt=0;
        int n;
        cin>>n;
        vi v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        sort(v,0,n-1);
        cout<<endl;
        cout<<cnt<<endl;
    }
}