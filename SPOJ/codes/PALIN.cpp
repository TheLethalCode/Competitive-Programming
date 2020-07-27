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
  int t;
  cin>>t;
  while(t--)
  {
    string s;
    cin>>s;
    int n=s.length(),a,first=0,check=0;
    n%2?a=n/2:a=n/2-1;
    rgod(i,a,0)
    {
      if(s[i]!=s[n-i-1])
      {
        check=1;
        if(first)
        {
          s[n-i-1] = s[i];
        }
        else
        {
          if(s[n-i-1] < s[i])
          s[n-i-1] = s[i];
          else
          {
            s[n-i-1] = s[i];
            if(s[a]!='9')
            {s[a]++;s[n-a-1]=s[a];}
            else
            {
              int k=0;
              while(s[a-k]=='9')
              {
                s[a-k]='0';
                s[n-a+k-1]='0';
                k++;
              }
              s[a-k]+=1;
              s[n-a+k-1]=s[a-k];
            }
          }
          first=1;
        }
      }
    }
    if(!check)
    {
      if(s[a]!='9')
      {s[a]++;s[n-a-1]=s[a];}
      else
      {
        int k=0;
        while(s[a-k]=='9')
        {
          s[a-k]='0';
          s[n-a+k-1]='0';
          if(k==a)
          {
            s+='1';
            s[0]='1';
            k++;
            break;
          }
          k++;
        }
        if(k!=a+1)
        {
          s[a-k]++;
          s[n-a+k-1]=s[a-k];
        }
      }
    }
    cout<<s<<endl;
  }
}