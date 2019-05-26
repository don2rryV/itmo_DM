#include <bits/stdc++.h>

using namespace std;
vector < vector <double> > a;
vector < vector <double> > b;

void mul(){

    for (int i = 0; i < a.size(); i++){
        for (int j = 0; j < a.size(); j++){
            b[i][j] = 0;
        }
    }

    int i = 0;
    while (i < a.size()){
        for (int j = 0; j < a.size(); j++) {
            for (int p = 0; p < a.size(); p++) {
                double buf = a[i][p]*a[p][j];
                b[i][j] += buf;
            }
        }
        i++;
    }
}

bool flag(){
    for (int i = 0; i < a.size(); i++){
        for (int j = 0; j < a.size(); j++){
            if (abs(a[i][j] - b[i][j]) > 0.00001) {
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    freopen("markchain.in","r",stdin);
    freopen("markchain.out","w",stdout);
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) a[i].resize(n);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    b.resize(a.size());
    for (int i = 0; i < a.size(); i++)
        b[i].resize(a.size());

    mul();

   /* for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << b[i][j];
        }
    }*/

    double buf1 = 1, buf2 = 1, one, two;

    while (!flag()){
        one = a[0][0];
        a = b;
        mul();
        two = a[0][0];
        buf1 = abs(two - one);
    }

    /*for (int i = 0; i < n; i++){
        cout << a[i][i] << endl;
    }*/

    for (int j = 0; j < n; ++j) {
        double ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += a[i][j] * 1 / n;
        }
        cout << ans << endl;
    }
}
