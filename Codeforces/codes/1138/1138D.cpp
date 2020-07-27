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
    string s,t;
    cin>>s>>t;
    int m=s.size();
    int n = (int)t.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && t[i] != t[j])
            j = pi[j-1];
        if (t[i] == t[j])
            j++;
        pi[i] = j;
    }
    int one=0,ze=0;
    for(int i=0;i<m;i++)
    {
        if(s[i] == '0')
            ze++;
        else
            one++;
    }

    int fl=0;
    string ans="";
    for(int i=0;i<n;i++)
    {
        if(t[i] == '0' && !ze)
        {
            fl=1;
            break;
        }
        if(t[i] == '1' && !one)
        {
            fl=1;
            break;
        }
        ans+=t[i];
        if(t[i]=='1')
            one--;
        else
            ze--;
    }

    while(!fl)
    {
        for(int i=pi[n-1];i<n;i++)
        {
            if(t[i] == '0' && !ze)
            {
                fl=1;
                break;
            }
            if(t[i] == '1' && !one)
            {
                fl=1;
                break;
            }
            ans+=t[i];
            if(t[i]=='1')
                one--;
            else
                ze--;
        }
        // cout<<one<<" "<<ze<<endl<<flush;
    }

    while(ze)
        ans+="0",ze--;
    while(one)
        ans+="1",one--;
    cout<<ans<<endl;
}