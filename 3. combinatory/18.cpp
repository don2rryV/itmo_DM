#include <bits/stdc++.h>

using namespace std;
long long n, k;
vector <vector <long long> > d;

int main()
{
    freopen("brackets2num.in","r",stdin);
    freopen("brackets2num.out","w",stdout);
    string s;
    cin >> s;

    n = s.length() / 2;
    long long buf = 0;
    d.resize(2*n+1);
    for (long long i = 0; i < d.size(); i++) d[i].resize(n+1);

    for (long long i = 0; i < 2*n + 1; i++){
        for (long long j = 0; j < n + 1; j++){
            d[i][j] = 0;
        }
    }
    d[0][0] = 1;
    for (long long i = 1; i < 2*n ; i++){
        for (long long j = 0; j < n+1; j++){
            if (j-1 < 0) d[i][j] = d[i-1][j+1]; else
            if (j+1 > n) d[i][j] = d[i-1][j-1]; else
                d[i][j] = d[i-1][j-1] + d[i-1][j+1];
        }
    }


    long long num = 0;
    for (long long i = 0; i < 2*n; i++){
        if (s[i] == '('){
                buf++;
            }
        else{
            if (buf + 1 <= n) num += d[2*n - i - 1][buf+1];
            buf--;
        }
    }
    cout << num;
}
