/*
Stock Span Problem
*/
#include <bits/stdc++.h>
using namespace std;
void display(vector<int> &v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt","r", stdin);
freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int a[n];
    vector<int> v;
    stack<pair<int,int>> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0;i<n;i++)
    {
        if(s.size()==0)
        {
            v.push_back(-1);
        }
        else if(s.size()>0&&s.top().first>a[i])
        {
            v.push_back(s.top().second);
        }
        else{
            while(s.size()!=0&&s.top().first<=a[i])
            {
                s.pop();
            }
            if(s.size()==0)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top().second);
            }

        }
        s.push({a[i],i});
    }
    for(int i = 0;i<v.size();i++)
    {
        v[i] = i-v[i];
    }
    display(v);
return 0;
}