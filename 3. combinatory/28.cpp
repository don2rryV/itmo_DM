#include <bits/stdc++.h>

using namespace std;
int n;
vector <int> a;
int main()
{
    freopen("nextmultiperm.in","r",stdin);
    freopen("nextmultiperm.out","w",stdout);
    cin >> n; a.resize(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    bool flag = true;
    int i = n - 2;
    while(i >= 0 && a[i] >= a[i+1]){
        i--;
    }
    if (i >= 0){
        flag = false;
        int j = i + 1;
        while(j < n-1 && a[j+1] > a[i]){
            j++;
        }
        swap(a[i], a[j]);
        reverse(a.begin() + i + 1, a.begin() + n);

    }
    if (flag) {
        for (int i = 0; i < n; i++) cout << "0 ";
    } else{
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }

    }

}
