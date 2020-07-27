#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
#define vi vector< int >
#define vli vector< lli >
#define endl "\n"
#define pa pair<lli,lli>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

vector< pa > hashc;
vli pow1,pow2,pow_1,pow_2;

lli modi(lli n,lli p,lli mo)
{
    if(p==0)
        return 1;
    else if(p%2)
        return (modi(n,p-1,mo)*n)%mo;
    else
    {
        lli t=modi(n,p/2,mo);
        return (t*t)%mo;
    }
}

int p1=31,m1=1e9+9,p2=29,m2=1e9+7,p_1=modi(p1,m1-2,m1),p_2=modi(p2,m2-2,m2);

void hashf(string s)
{
    int n=s.length();
    pow1.resize(n,1);
    pow2.resize(n,1);
    pow_1.resize(n,1);
    pow_2.resize(n,1);
    hashc.resize(n);

    for(int i=1;i<n;i++)
        pow1[i]*=pow1[i-1]*p1,pow1[i]%=m1;
    for(int i=1;i<n;i++)
        pow2[i]*=pow2[i-1]*p2,pow2[i]%=m2;
    
    for(int i=1;i<n;i++)
        pow_1[i]*=pow_1[i-1]*p_1,pow_1[i]%=m1;
    for(int i=1;i<n;i++)
        pow_2[i]*=pow_2[i-1]*p_2,pow_2[i]%=m2;

    for(int i=0;i<n;i++)
    {
        lli a=(s[i]-'a'+1)*pow1[i];
        if(i)
            a+=hashc[i-1].fi;
        a%=m1;
        lli b=(s[i]-'a'+1)*pow2[i];
        if(i)
            b+=hashc[i-1].se;
        b%=m2;
        hashc[i]=mp(a,b);
    }
}

pa hashf(int i,int j)
{
    if(!i)
        return hashc[j];
    lli a=hashc[j].fi-hashc[i-1].fi+m1;
    a*=pow_1[i],a%=m1;
    lli b=hashc[j].se-hashc[i-1].se+m2;
    b*=pow_2[i],b%=m2;
    return mp(a,b);
}

int main()
{
    crap;
    string s,val;
    int k,n;
    cin>>s>>val>>k;
    n=s.length();
    hashf(s);
    vi che(n+1,0);
    for(int i=1;i<=n;i++)
        che[i]=(val[s[i-1]-'a']=='0')?che[i-1]+1:che[i-1];
    set< pa > m;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            if(che[j]-che[i-1]<=k)
                m.insert(hashf(i-1,j-1));
    cout<<m.size()<<endl;
}