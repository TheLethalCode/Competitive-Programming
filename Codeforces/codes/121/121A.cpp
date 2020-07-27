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

lli next(int l)
{
    vi num;
    while(l)
        num.pb(l%10),l/=10;
    int i,n=num.size(),fl=0;
    for(i=n-1;i>=0 && (num[i]==4 || num[i]==7);i--);
    if(i>=0)
    {
        fl=1;
        for(int j=i-1;j>=0;j--)
            num[j]=4;
        int carry=0;
        if(num[i]>7)
            num[i]=4,carry=1;
        else if(num[i]>4)
            num[i]=7;
        else
            num[i]=4;
        while(carry)
        {
            i++;
            if(i>=n)
                num.pb(4),carry=0;
            else
            {
                if(num[i]==4)
                    num[i]=7,carry=0;
                else
                    num[i]=4;
            }
        }
    }
    lli x=1,ans=0;
    for(int a:num)
        ans+=x*a,x*=10;
    return ans;
}

int main()
{
    crap;
    lli ans=0;
    lli l,r;
    cin>>l>>r;
    lli cur=l;
    while(cur<=r)
    {
        lli ne=next(cur);
        ans+= ne>r ? (r-cur+1)*ne:(ne-cur+1)*ne;
        cur=ne+1;
    }
    cout<<ans<<endl;
}