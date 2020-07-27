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
    set<int> v;
    int n;
    cin>>n;
    lli sum=0;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        sum+=a;
        v.insert(a);
    }
    int del=0;
    vi q;
    for(int a:v)
        q.push_back(a);
    for(int i=0;i<q.size();i++)
    {
        for(int j=i+1;j<q.size();j++)
        {
            int temp=0;
            for(int k=2;k<=sqrt(q[j]);k++)
            {
                if(q[j]%k==0)
                {
                    int st=q[j]/k;
                    temp=min(temp,-q[j]-q[i]+st+q[i]*k);
                    temp=min(temp,k+q[i]*st-q[j]-q[i]);
                }
            }
            del=min(del,temp);
        }
    }
    cout<<sum+del<<endl;
}