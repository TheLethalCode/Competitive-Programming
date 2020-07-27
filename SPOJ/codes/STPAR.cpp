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
 
lli pom(lli n,lli p){ if(!p)return 1;else if(p%2)return (pom(n,p-1)*(n%mod))%mod;else{lli te=pom(n,p/2);return (te*te)%mod;}}
 
int main()
{
    crap;
    int t;
    //cin>>t;
    while(1)
    {
        int n;
        cin>>n;
        if(!n)break;
        vi v(n);
        god(i,0,n)cin>>v[i];
        vi a(n+1);
        a[0]=0;
        int j=0;
        std::stack<int> s;
        god(i,0,n)
        {
            if(!s.empty()){
                while(s.top()==a[j]+1){
                    a[++j]=s.top();
                    s.pop();
                    if(s.empty()){break;}
                }
            }
            if(v[i]==a[j]+1){
                a[++j]=v[i];
            }
            else{
                s.push(v[i]);
            }
        }
        int flag=0;
        j++;
        while(j!=n+1)
        {
            a[j]=s.top();
            if(a[j]!=a[j-1]+1){flag=1;break;}
            s.pop();
            j++;
        }
        if(flag)cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
    return 0;
}