#include <bits/stdc++.h>

using namespace std;
vector <long long> a;
long long n,k;

bool func(){
    long long i;
    for (i = n-2; i > -1; i--){
        if (a[i+1] > a[i]) break;
    }
    if (i == -1) return false;
    long long j;
    for (j = n-1; j > -1; j--){
        if (a[j] > a[i]) break;
    }
    //cout << i << " " << j << endl;
    swap(a[i], a[j]);
    long long l = i+1;
    long long r = n-1;
    //cout << l << " " << r << endl;
    while (l<r){
        swap(a[l], a[r]);
        l++;
        r--;
        }
    return true;

}

int main()
{
    freopen("num2perm.in","r",stdin);
    freopen("num2perm.out","w",stdout);
    cin >> n >> k;
    a.resize(n);
    long long kk = 1;
    for (int i = 1; i < n; i++){
        kk *= i;
    }
    long long kkk = kk;
    long long ind = 1;
    while (kk <= k) {
        ind++;
        kk = kk + kkk;
        //if (kk != k) {kk *= 2;} else break;
    }

    //cout << "ind = " << ind << endl;
    //cout << "kk = " << kk << endl;
    a[0] = ind;
    long long j = 1;
    for (long long i = 1; i <= n; i++){
        if (i != ind) {a[j] = i;j++;}
    }

    //cout << "kkk = " << kkk << endl;
    k = k - (kk - kkk);

     //cout << "k = " << k << endl;
    while(k > 0 && func()){
        k--;
    }


    for (long long i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
}
