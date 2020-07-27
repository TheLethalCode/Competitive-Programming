#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define vi vector<int> 
#define vli vector<long long int>
#define rgod(i,a,b) for(int i=a;i>=b;i--)
#define god(i,a,b) for(int i=a;i<b;i++)
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long int
#define fi first
#define se second
#define pb push_back
#define pa pair<int,int>
#define ma make_pair
#define ulli unsigned lli
 
 
double tick(){static clock_t oldt,newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}
 
lli pom(lli n){ if(n==0)return 1;else{if(n%2)return (2*pom(n-1))%mod; else{lli t=pom(n/2); return (t*t)%mod;}}}
 
int main()
{       
    crap;
    int t=1;
    cin>>t;
    while(t--)
    {
     string s1,s2;
     cin>>s1>>s2;
     int n1,n2;
     n1=s1.length();
     n2=s2.length();
     if(n1>n2)
     {
         string k;
         k=s1;
         s1=s2;
         s2=k;
         n1=n1+n2;
         n2=n1-n2;
         n1=n1-n2;
     }
     vi v1(n1),v2(n2),v;
     god(i,0,n1)
     {
         v1[i]=s1[i]-'0';
     }
     god(i,0,n2)
     {
         v2[i]=s2[i]-'0';
     }
     int c=0;
     god(i,0,n1)
     {
         v.pb((v1[i]+v2[i]+c)%10);
         c=v1[i]+v2[i] + c;
         c/=10;
     }
     god(i,n1,n2)
     {
         v.pb((v2[i]+c)%10);
         c=v2[i] + c;
         c/=10;
     }
     if(c)
        v.pb(c);
     int f=1;
     for(auto it= v.begin();it!=v.end();it++)
     {
         if(*it)
            {f=0;cout<<*it;}
         else if(!f)
            cout<<*it;
     }
     cout<<endl;
    }
 // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}