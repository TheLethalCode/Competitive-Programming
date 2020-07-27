#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
#define pa pair<int,int>
#define pal pair<lli,lli>
#define vi vector< int >
#define vli vector< lli >
#define vpa vector< pa >
#define vpal vector< pal >
#define fi first
#define se second
#define pb push_back
#define pp pop_back

#define nl cout<<"\n"
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(int i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)
#define perc %
#define xors ^

int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;
    string s;
    cin>>s;
    int lc = 0,rc = 0;
    for(auto r : s)
        if(r == '(') lc ++;
        else rc ++;

    if(lc != rc)
        cout<<0<<endl<<"1 1"<<endl;
    else
    {
        lli ma = 0, ch1 = 1, ch2 = 1;

        string r = s;
        r += r;

        stack<int> trys;
        int cnt = 0;
        
        for(int k = 0;k < 2*n;k++)
        {
            if(r[k] == '(')
                trys.push(k);
            else if(!trys.empty())
            {
                trys.pop();
                if(k >= n && trys.empty())
                    cnt++;
            }
        }
        ma = cnt;
        
        for(int i = 0; i < n;i++)
        {
            if(s[i] == '(')
            {
                for(int j = 0; j < n; j++)
                {
                    if(s[j] == ')')
                    {
                        string r = s;
                        r[i] = ')', r[j] = '(';
                        r += r;

                        stack<int> tryst;
                        int cnt = 0;
                        
                        for(int k = 0;k < 2*n;k++)
                        {
                            if(r[k] == '(')
                                tryst.push(k);
                            else if(!tryst.empty())
                            {
                                tryst.pop();
                                if(k >= n && tryst.empty())
                                    cnt++;
                            }
                        }

                        if( ma < cnt)
                        {
                            ma = cnt;
                            ch1 = i + 1, ch2 = j + 1;
                        }
                    }
                }
            }
        }
        cout<<ma<<endl<<ch1<<" "<<ch2<<endl;
    }
}