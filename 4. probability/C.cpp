#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("lottery.in","r",stdin);
    freopen("lottery.out","w",stdout);
    int n, m;
    vector <double> a,b, c,d;
    cin >> n >> m;
    a.resize(m);
    b.resize(m);
    c.resize(m);
    d.resize(m);

    for (int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
    }

    c[0] = 1/a[0];
    d[0] = 1- c[0];
    for (int i = 1; i < m; i++){
        c[i] = c[i-1] * (1/a[i]);
        d[i] = c[i-1]*(1 - 1/a[i]);
    }
    for (int i = 0 ;i < m; i++){
    //    cout << c[i] << " " << d[i] << endl;
    }

    double out = 0;
    for (int i = 0 ; i < m-1; i++){
        out += d[i+1] * b[i];
    }
    out += c[m-1] * b[m-1];
    cout << n - out;


}
