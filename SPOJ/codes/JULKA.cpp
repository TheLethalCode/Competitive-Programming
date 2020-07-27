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
    int t=10;
    //cin>>t;
    while(t--)
    {
        string s1,s2;
        cin>>s1>>s2;
        int n1,n2;
        n1=s1.length();
        n2=s2.length();
        vi v1(n1),v2(n1),v3(n1);
        god(i,0,n1)
        v1[i]=s1[i]-'0';
        god(i,n1-n2,n1)
        v2[i]=s2[i-(n1-n2)]-'0';
        int c=0;
        rgod(i,n1-1,0)
        {
            int k=v1[i]-v2[i]-c;
            if(k<0)
            {
                k+=10;
                c=1;
            }
            else
            c=0;
            v3[i]=k;
        }
        int l=0;
        god(i,0,n1)
        {
            int k=v3[i];
            v3[i]=(l*10+k)/2;
            l=k%2;
        }
        vi v4(n1);
        int r=0;
        rgod(i,n1-1,0)
        {
             int k=v3[i]+v2[i]+r;
             r=k/10;
             v4[i]=k%10;
        }
        int f=0;
        god(i,0,n1)
        {
            if(f==0 && v4[i]==0)
            continue;
            else if(f==0)
            f=1;
            cout<<v4[i];
        }
        f=0;
        cout<<endl;
        god(i,0,n1)
        {
            if(f==0 && v3[i]==0)
            continue;
            else if(f==0)
            f=1;
            cout<<v3[i];
        }
        cout<<endl;
    }
    return 0;
}