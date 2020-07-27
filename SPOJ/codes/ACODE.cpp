#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define vi vector<int> 
#define vli vector<long long int>
#define rgod(i,a,b) for(int i=a;i>=b;i--)
#define god(i,a,b) for(int i=a;i<b;i++)
#define igod(v) for(auto it=v.begin();it!=v.end();it++)
#define rigod(v) for(auto it=v.rbegin();it!=v.rend();it++)
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long int
#define fi first
#define se second
#define pb push_back
#define pa pair<int,int>
#define ma make_pair
#define ulli unsigned lli
 
lli pom(lli n){ if(n==0)return 1;else{if(n%2)return (2*pom(n-1))%mod; else{lli t=pom(n/2); return (t*t)%mod;}}}
 
int main()
{       
    crap;
    int t=1;
    //cin>>t;
    while(t)
    {
        string s;
        cin>>s;
        if(s=="0")
        break;
        int n=s.length();
        vi v(n+2);
        god(i,0,n)
        {
            if(s[i]=='0')
            {
                s[i]='-';
                s[i-1]='-';
            }
        }
        v[n]=1;
        v[n-1]=1;
        rgod(i,n-2,0)
        {
            if(s[i]=='-')
            {
                v[i]=v[i+1];
                continue;
            }
            else
            {
                if(s[i+1]=='-')
                {
                    v[i]=v[i+1];
                    continue;
                }
                int k=(s[i]-48)*10+(s[i+1]-48);
                if(k<=26)
                {
                    v[i]=v[i+1]+v[i+2];
                }
                else
                {
                    v[i]=v[i+1];
                }
            }
        }
        cout<<v[0];
        cout<<endl;
    }
    return 0;
}