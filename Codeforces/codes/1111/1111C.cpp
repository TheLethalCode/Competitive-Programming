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

map<int, int> h;
set<int> p;
vi Z;
lli n,k,A,B;
vli sum;

int cnt(int a)
{
    int val;
    try
    {
        val = h[a];
    }
    catch(const std::exception& e)
    {
        val=0;
    }
    return val;
}

int cnt(int a,int b)
{
    int val_st,val_en;
    int st=lower_bound(Z.begin(),Z.end(),a)-Z.begin();
    int en=lower_bound(Z.begin(),Z.end(),b)-Z.begin();
    // cout<<endl<<st<<" "<<en<<endl;
    if(!st)val_st=0;
    else val_st=sum[st-1];
    if(Z[en]!=b)
        en--;
    if(en<0)
        val_en=0;
    else val_en=sum[en];
    return val_en-val_st;
}

lli func(int a,int b)
{
    if(a==b)
    {
        int val=cnt(a);
        if(val)
            return B*val;
        else
            return A;
    }
    int val=cnt(a,b);
    if(val)
    {
        int mid=(a+b)/2;
        return min(func(a,mid)+func(mid+1,b),B*(b-a+1)*val);
    }
    else
        return A; 
}

int main()
{
    crap;
    cin>>n>>k>>A>>B;
    for(int i=0;i<k;i++)
    {
        int a;
        cin>>a;
        auto ch = p.insert(a);
        if(!ch.se)
            h[a]++;
        else
        {
            h[a]=1;
        }
    }
    for(auto vr:p)
    {
        Z.push_back(vr);
        if(sum.empty())
            sum.pb(h[vr]);
        else
        {
            sum.pb(sum.back()+h[vr]);
        }
    }
    sum.pb(sum.back());
    cout<<func(1,pow(2,n))<<endl;
}