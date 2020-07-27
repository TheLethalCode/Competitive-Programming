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

int cnt(string s,string r)
{
    int fl=0,cnt=0;
    // cout<<s<<" "<<r<<flush;
    for(int i=0;i < s.length()-2;i++)
    {
        fl=0;
        for(int j=0;j<=2;j++)
        {
            if(s[i+j] != r[j])
            {
                fl=1;
                break;
            }
        }
        if(!fl)
            cnt++;
    }
    return cnt;
}

int main()
{
    crap;
    int t,te=0;
    cin>>t;
    while(te++ < t)
    {
        string s;
        cin>>te;
        cin>>s;
        cout<<te<<" ";
        char hi[] = {'T','H'};
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                {
                    string q="";
                    q+=hi[i];
                    q+=hi[j];
                    q+=hi[k];
                    cout<<cnt(s,q)<<" ";
                }
        cout<<endl;
    }
}