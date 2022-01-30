/*
Rainwater Trapping
*/
#include <bits/stdc++.h>
using namespace std;
void display(vector<int> a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> a(n), maxL(n), maxR(n);
    int water = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    maxL[0] = a[0];
    maxR[n-1] = a[n - 1];
    for (int i = 1; i < n; i++)
    {
        maxL[i] = max(maxL[i - 1], a[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        maxR[i] = max(a[i], maxR[i + 1]);
    }
    for (int i = 0; i < n; i++)
    {
        water += (min(maxL[i], maxR[i]) - a[i]);
    }
    display(a,n);
    display(maxL,n);
    display(maxR,n);
    cout<<water<<endl;
    return 0;
}