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
    string s1, s2, s3;
    cin>>s1;
    cin>>s2>>s2;
    cin>>s3>>s3;
    lli a1=-1,a2=-1,a3=-1;
    stringstream ss1(s1);
    stringstream ss2(s2);
    stringstream ss3(s3);
    if(s1.find('m')==-1)ss1>>a1;
    if(s2.find('m')==-1)ss2>>a2;
    if(s3.find('m')==-1)ss3>>a3;
    if(a3==-1)a3=a2+a1;
    if(a2==-1)a2=a3-a1;
    if(a1==-1)a1=a3-a2;
    cout<<a1<<" + "<<a2<<" = "<<a3<<endl;
  }
}