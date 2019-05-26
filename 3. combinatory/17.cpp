#include <bits/stdc++.h>

using namespace std;
long long n,k;
vector <vector <long long> > d;
int main()
{
    freopen("num2brackets.in","r",stdin);
    freopen("num2brackets.out","w",stdout);
    cin >> n >> k;
    k++;
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

    /*for (int i = 0; i < 2*n + 1; i++){
        for (int j = 0; j < n + 1; j++){
            cout << d[i][j] << " ";
        }
        cout << endl;
    }

*/
    string s = "";
    for (long long i = 0; i < 2*n; i++){
        if (buf + 1 <= n && d[2*n - i - 1][buf + 1]>= k){
            s += '(';
            buf++;
        }
        else {
            if (buf + 1 <= n) k -= d[2*n - i - 1][buf + 1];
            s += ')';
            buf--;
        }
    }
    /*for (int i = 2*n-1; i >= 0; i--){
        if (buf + 1 <= n && d[i][buf+1] >= k){
            s += '(';
            ++buf;
        }else{
            s+= ')';
            if (buf + 1 <= n) {
                k -= d[i][buf+1];
            }
            --buf;
        }
    }*/
    cout << s;

}
