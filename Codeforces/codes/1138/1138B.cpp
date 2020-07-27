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
    cin>>n;
    vector< pa > v(n);
    string x,y;
    cin>>x>>y;
    for(int i=0;i<n;i++)
        v[i].fi = x[i]-'0', v[i].se = y[i]-'0';
    vi cl_o,ac_o,both,none;
    for(int i=0;i<n;i++)
    {
        if(v[i].fi && v[i].se)
            both.pb(i+1);
        else if(v[i].fi)
            cl_o.pb(i+1);
        else if(v[i].se)
            ac_o.pb(i+1);
        else
            none.pb(i+1);
    }
    int a=min((int)cl_o.size(),(int)ac_o.size()),b=max((int)cl_o.size(),(int)ac_o.size());
    if(b>n/2)
        cout<<-1<<" ";
    else if(a + both.size() < b)
    {
        if(a == cl_o.size())
        {
            int cnt=0;
            for(int i : cl_o)
            {
                cout<<i<<" ";
                cnt++;
            }
            for(int i : both)
            {
                cout<<i<<" ";
                cnt++;
            }
            for(int i=0;i < b-a-(int)both.size();i++)
            {
                cout<<ac_o[i]<<" ";
                cnt++;
            }
            for(int i=cnt;i<n/2;i++)
                cout<<none[i]<<" ";
        }
        else
        {
            int cnt=0;
            for(int i=0;i < a+both.size();i++)
            {
                cout<<cl_o[i]<<" ";
                cnt++;
            }
            for(int i=cnt;i<n/2;i++)
                cout<<none[i]<<" ";
            cout<<endl;
        }
    }
    else
    {
        int cnt=0;
        if( a == cl_o.size())
        {
            for(int te: cl_o)
            {
                cout<<te<<" ";
                cnt++;
            }
            for(int i=0;i < b-a; i++)
            {
                cout<<both.back()<<" ";
                both.pop_back();
                cnt++;
            }
            int l=(int)both.size();
            for(int i=0; i < l/2 ;i++)
            {
                cout<<both.back()<<" ";
                both.pop_back();
                cnt++;
            }
            if(l%2)
            {
                cout<<ac_o.back()<<" ";
                cnt++;
            }
            for(int i=cnt;i<n/2;i++)
            {
                cout<<none.back()<<" ";
                none.pop_back();
            }
        }
        else
        {
            int l=both.size(),cnt=0;
            for(int i=0;i < b-l%2 ;i++)
            {
                cout<<cl_o[i]<<" ";
                cnt++;
            }

            for(int i=0;i < l/2 + l%2;i++)
            {
                cout<<both[i]<<" ";
                cnt++;
            }

            for(int i=cnt;i<n/2;i++)
                cout<<none[i]<<" ";
            
        }
    }
    cout<<endl;
}