#include <bits/stdc++.h>

using namespace std;
int n, k;
vector <int> a, b;

int func(int nn, int kk){
    for (int i = 0; i < k; i++){
        b[i] = a[i];
    }
    b[k] = n+1; int i = k-1;
    while (i >= 0 && b[i+1] - b[i] <2) i--;
    if (i >= 0){
        b[i]++;
        for (int j = i+1; j < k; j++){
            b[j] = b[j-1] + 1;
        }
        for (int p = 0; p < k; p++){
            a[p] = b[p];
        }
        return 1;
    }else return 0;

}


int main()
{
    freopen("nextchoose.in","r",stdin);
    freopen("nextchoose.out","w",stdout);
    cin >> n >> k;
    a.resize(k); b.resize(k+1);
    for (int i = 0; i < k; i++) {
            cin >> a[i];
    }
    if (func(n,k) == 0) cout << "-1"; else{
        for (int i = 0 ;i < a.size(); i++){
            cout << a[i] << " ";
        }
    }
}
