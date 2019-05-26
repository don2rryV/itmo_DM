#include <bits/stdc++.h>

using namespace std;
int n;
vector <int> a,b;

int main()
{
    freopen("nextperm.in","r",stdin);
    freopen("nextperm.out","w",stdout);
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (int i = 0 ;i < n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    bool flag_a = true;
    for (int i = n-2; i > -1; i--){
        if (a[i] < a[i+1]){
            flag_a = false;
            int min_buf = i+1;
            for (int j = i + 1; j < n; j++){
                if (a[j] < a[min_buf] && a[j] > a[i]){
                    min_buf = j;
                }
            }
            swap(a[i], a[min_buf]);
            reverse(a.begin()+i+1, a.begin() + n);
            break;
        }

    }
    bool flag_b = true;
    for (int i = n-2; i > -1; i--){
        if (b[i] > b[i+1]){
            flag_b = false;
            int max_buf = i+1;
            for (int j = i + 1; j < n; j++){
                if (b[j] > b[max_buf] && b[j] < b[i]){
                    max_buf = j;
                }
            }
            swap(b[i], b[max_buf]);
            reverse(b.begin()+i+1, b.begin() + n);
            break;
        }

    }
    if (flag_a) {
        for (int i = 0 ;i < n; i++) a[i] = 0;
    }
    if (flag_b) {
        for (int i = 0 ;i < n; i++) b[i] = 0;
    }
    for (int i = 0; i < b.size(); i++){
        cout << b[i] << " ";
    }

    cout << endl;


    for (int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
}
