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

int main()
{
    crap;
    int n;
    while(cin>>n)
    {
        string r;
        cin>>r;
        vi pi(n,0);
        for(int i=1;i<n;i++)
        {
            int j=pi[i-1];
            while(r[j] != r[i] && j!=0)
                j = pi[j-1];
            if(r[j] == r[i])
                j++;
            pi[i]=j;
        }
        string k;
        cin>>k;
        k=r+'#'+k;
        int m=k.length();
        int ans=0;
        vi cnt;
        for(int i=n;i<m;i++)
        {
            int j=pi[i-1];
            while(k[j] != k[i] && j!=0)
                j = pi[j-1];
            if(k[j] == k[i])
                j++;
            pi.push_back(j);
            if(pi[i]==n)
                ans++,cnt.push_back(i-2*n);
        }
        for(int q:cnt)
            cout<<q<<endl;
    }
}