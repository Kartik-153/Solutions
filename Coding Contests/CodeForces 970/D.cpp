#include <bits/stdc++.h>
#include <cmath>

using namespace std;
int main() {
    int t, n, i, j, r, count, tb, no;
    cin>>t;
    while(t--)
    {
        cin>>n;
        string s;
        cin>>s;
        r = static_cast<int>(sqrt(n));
       // cout<<r<<endl;
       count=0, no=0, tb=0;
        if(r*r!=n)
            cout<<"No"<<endl;
        else
        {
            for(i=0; i<n; i++)
            {
                if(i<r || i>= r*(r-1))
                {
                    if(s[i]!='1')
                    {
                        no++;
                        break;
                    }
                }
                else
                {
                    if(i%r==0 || i%r==r-1)
                    {
                        if(s[i]!='1')
                        {
                            no++;
                            break;
                        }
                    }
                    else
                    {
                        if(s[i]!='0')
                        {
                            no++;
                            break;
                        }
                    }
                }
            }
            if(no>0)
                cout<<"No"<<endl;
            else
                cout<<"Yes"<<endl;
            
        }
    }

    return 0;
}