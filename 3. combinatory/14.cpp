#include <bits/stdc++.h>

using namespace std;
long long n, k;
vector <long long> a;

int next(){
    long long ind = -1;
    for (long long i = k-1; i > -1; i--){
        if (a[i]<n){
            a[i]++;
            ind = i;
            break;
        }
    }
    if (ind == -1) return false;
    for (long long i = ind + 1; i < k; i++){
        a[i] = a[i-1] + 1;
    }
    return true;

}

int main()
{
    freopen("num2choose.in","r",stdin);
    freopen("num2choose.out","w",stdout);
    long long m;
    cin >> n >> k >> m;
    a.resize(k);
    for (long long i = 0; i < k; i++) {
            a[i] = i+1;
          // cout << a[i] << " ";
    }
   // cout << endl;
    bool flag = true;
    while (m > 0 && next()){

        flag = true;
        for (long long i = 0; i < k; i++){
            if (a[i] > n) flag = false;
        }
        if (flag) m--;
    }

        for (long long i = 0 ; i < k; i++){
            cout << a[i] << " ";
        }
        cout << endl;
}
