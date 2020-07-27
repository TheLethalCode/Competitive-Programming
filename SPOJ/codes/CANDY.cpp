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
    while(1)
    {
        int n;
        cin>>n;
        if(n==-1)
            break;
        else
        {
            vi v(n);
            int sum=0;
            god(i,0,n)
            {
                cin>>v[i];
                sum+=v[i];
            }
            if(sum%n)
                cout<<-1;
            else
            {
                sum/=n;
                int rsum=0;
                god(i,0,n)
                {
                    if(v[i]>sum)
                        rsum+=v[i]-sum;
                }
                cout<<rsum;
            }
        }
        cout<<endl;
    }
    return 0;
}