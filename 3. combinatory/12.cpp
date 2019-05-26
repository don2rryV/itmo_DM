#include <bits/stdc++.h>

using namespace std;
long long n, k;
vector <vector <long long> > a;
vector <long long> kek;

int main()
{
    cin >> n >> k;
    kek.resize(k);
    for (long long i = 1; i < k; i++) kek[i] = i;

    long long y = pow(k,n);
    a.resize(y);
    for (long long i = 0; i < y; i++){
        a[i].resize(n+1);
    }

    long long buf;
    buf = 1;

    for (long long j = n-1; j >= 0; j--){
        if (j != n-1) buf = buf * k;
        long long p = 0;
        for (long long i = 0; i < y; i++){
            if (i == 0) a[i][j] = p; else{
                if (i % buf == 0){a[i][j] = p; p = (p+1)%k;} else {
                    a[i][j] = p;
                }
            }
        }

    }

    for (long long i =0 ;i < a.size(); i++){
        for (long long j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

}
