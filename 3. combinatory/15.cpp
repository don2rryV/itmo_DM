#include <bits/stdc++.h>

using namespace std;
long long n, m, k;
vector <long long> a;
vector < vector <int> > s;
vector <int> fuck;
/*long long ss(int nn, int kk){
    long long fuc_n = 1;
    for (long long x = 1; x <= nn; x++){
        fuc_n *= x;
    }
    long long fuc_k = 1;
    for (long long x = 1; x <= kk; x++){
        fuc_k *= x;
    }
    long long fuc_n_k = 1;
    for (long long x = 1; x <= nn-kk; x++){
        fuc_n_k *= x;
    }
    return fuc_n/(fuc_k * fuc_n_k);
}*/

/*int fuck(int p){
    if (p == 0) return 1 else{
        long long ans = 1;
        for (int i = 1; i < p+1; i++){
            ans *= i;
        }
        return ans;
    }
}*/


int main()
{
    freopen("num2choose.in","r",stdin);
    freopen("num2choose.out","w",stdout);
    cin >> n >> k >> m;
    fuck.resize(n);
    fuck[0] = 1;
    for (int i = 1; i < )


    s.resize(n+1);
    for (int i = 0; i < s.size(); i++){
        s[i].resize(k+1);
    }

    long long next = 1;
    for (int i = )

    for (int i = 0; i < s.size(); i++){
        for (int j = 0; j < s[i].size()/2; j++){
            s[i][j] = fuck
        }
    }


    while (k > 0){
        if (m < s){
            a.push_back(next);
            k--;
        } else{
            m = m - s;
        }
        n--;
        next++;
    }
    for (int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
}
