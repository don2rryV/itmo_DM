#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("shooter.in","r",stdin);
    freopen("shooter.out","w",stdout);
    int n,m,k;
    double buf, p, sum = 0;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++){
        cin >> buf;
        buf = 1 - buf;
        buf = pow(buf, m);
        if (i + 1 == k) p = buf;
        sum += buf;
    }
    double out = p / sum;
   // cout << out;
   cout<<setprecision(13)<<out;
}
