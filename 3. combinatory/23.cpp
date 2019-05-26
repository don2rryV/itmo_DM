#include <bits/stdc++.h>

using namespace std;
vector <int> a,b;

int main()
{
    freopen("nextvector.in","r",stdin);
    freopen("nextvector.out","w",stdout);
    string s;
    cin >> s;
    int n = s.length(); bool flag1 = false, flag2 = false;
    a.resize(s.length());
    b.resize(s.length());
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '1') {
                a[i] = 1;
                b[i] = 1;
        }else {
            a[i] = 0;
            b[i] = 0;
        }
    }
    int i = n - 1;
    if (a[i] == 0){
        a[i] = 1;
    }else{
        while (i > -1 && a[i] != 0){
            a[i] = 0;
            i--;
        }
        if (i == -1) {
            flag1 = true;
        } else {
            a[i] = 1;
        }
    }
    //next

    i = n - 1;
    if (b[i] == 1){
        b[i] = 0;
    }else{
        while (i > -1 && b[i] != 1){
            b[i] = 1;
            i--;
        }
        if (i == -1){
            flag2 = true;
        } else {
            b[i] = 0;
        }
    }

    if (flag2) cout << "-"; else {
        for (int i = 0; i < n; i++){
            cout << b[i];
        }
    }
    cout << endl;

    if (flag1) cout << "-"; else {
        for (int i = 0; i < n; i++){
            cout << a[i];
        }
    }


}
