#include <bits/stdc++.h>

using namespace std;
long long n, k;
vector <vector <long long> > a;
vector <long long> kek;
int main()
{
    //freopen("telemetry.in","r",stdin);
    //freopen("telemetry.out","w",stdout);
    cin >> n >> k;
    long long y = pow(k,n);
    a.resize(y);
    kek.resize(k);

    for (long long i = 0; i < k; i++) kek[i] = i;

    for (long long i = 0; i < a.size(); i++){
        a[i].resize(n);
    }

    long long buf;
    buf = 1;

    for (long long i = 0; i < n; i++){
        if (i != 0) buf = buf * k;

        long long ind = 0;

        while (ind < y){

            long long p = 0;
            while (ind < y && p < k){
                for (long long j = 0; j < buf; j++){
                    a[ind][i] = kek[p];
                    ind++;
                }
                p++;
            }
            p--;
            while (ind < y && p > -1){
                for (int j = 0; j < buf; j++){
                    a[ind][i] = kek[p];
                    ind++;
                }
                p--;
            }

        }
    }

    for (long long i = 0; i < y; i++){
        for (long long j = 0; j < n; j++){
            cout << a[i][j];
        }
        cout << endl;
    }

}
