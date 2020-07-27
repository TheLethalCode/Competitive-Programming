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
    int n,k;
    cin>>n>>k;
    vi v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    string s;
    cin>>s;
    int la_v;
    lli dmg=0;
    for(int i=0;i<n;i++)
    {
        la_v=s[i];
        multiset< int > q;
        int j=i;
        while(j<n && s[j]==la_v)
            q.insert(v[j]),j++;
        i=j-1;
        int cnt=0;
        for(auto it=q.rbegin();it!=q.rend();it++)
        {
            if(cnt>=k)
                break;
            dmg+=*it;
            // cout<<*it<<" cnt= "<<cnt<<endl;;
            cnt++;
        }
    }
    cout<<dmg<<endl;
}