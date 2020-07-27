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
 
int val(char k)
{
    switch(k)
    {
        case '+':return 1;
        case '-':return 2;
        case '*':return 3;
        case '/':return 4;
        case '^':return 5;
        case '(':return 0;
    }
}
 
int main()
{       
    crap;
    int t=1;
    cin>>t;
    while(t--)
    {
        string s,k;
        cin>>s;
        int n=s.length();
        god(i,0,n)
        {
            if(s[i]>=97 && s[i]<=122)cout<<s[i];
            else
            {
                if(s[i]==')')
                {
                    while(k.back()!='(')
                    {
                        cout<<k.back();
                        k.pop_back();
                    }
                    k.pop_back();
                }
                else
                {
                    if(!k.empty() && s[i]!='(')
                    {
                        while(val(k.back())>val(s[i]) && k.back()!= '(')
                        {
                            cout<<k.back();
                            k.pop_back();
                            if(k.empty())
                                break;
                        }
                    }
                    k.pb(s[i]);
                }
            }
        }
        while(!k.empty())
        {
            cout<<k.back();
            k.pop_back();
        }
        cout<<endl;
    }
    return 0;
}