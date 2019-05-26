#include <bits/stdc++.h>

using namespace std;
vector <vector <bool> > a;

int main()
{
    freopen("gray.in","r",stdin);
    freopen("gray.out","w",stdout);
    int n;
    cin >> n;
    a.resize(pow(2,n));
    for (int i = 0; i < a.size(); i++) a[i].resize(n);
    a[0][n-1] = false;
    a[1][n-1] = true;


    for (int i = 1; i < n; i++){

        int leng = pow(2,i); int t = leng - 1;

        for (int j = leng; j < 2*leng; j++){
            for (int k = n-1; k > n-1-i; k--){
                a[j][k] = a[t][k];
            }
            t--;
        }

        for (int j = 0; j < leng; j++){
            a[j][n-1-i] = false;
        }
        for (int j = leng; j < a.size(); j++){
            a[j][n-1-i] = true;
        }

    }

    for (int i = 0; i < a.size(); i++){
        for (int j = 0; j < a[i].size(); j++){
            cout << a[i][j];
        }
        cout << endl;
    }



}
