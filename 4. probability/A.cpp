#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("exam.in","r",stdin);
    freopen("exam.out","w",stdout);
    int n,k;
    vector <int> p, m;
    double out = 0;
    cin >> k >> n;
    p.resize(k);
    m.resize(k);
    for (int i = 0; i < k; i++){
        cin >> p[i] >> m[i];
        out += p[i]*m[i];
    }
    out = out / (n * 100);
    cout << out << endl;
}
