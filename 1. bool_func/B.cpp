#include <bits/stdc++.h>

using namespace std;

vector <vector <int> > a;
vector <int> cnt;
vector <int> cnt_0;
int n,k;
bool flag = true;

int main()
{
    cin >> n >> k;
    a.resize(k); for(int i = 0; i < k; i++) a[i].resize(n);
    cnt.resize(k); cnt_0.resize(k);
    for (int i = 0; i < k; i++){
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] != -1) cnt[i]++;
            if (a[i][j] == 0) cnt_0[i]++;
        }
    }

    /*for (int i = 0; i < k; i++){
        for (int j = 0; j < k; j++){
            cout << a[i][j] << " ";
        }
        cout << cnt[i] << " " << cnt_0[i] << endl;
    }*/

    int i = 0;
    int buf,ind;
    bool ans = false;

    while (flag){
        i=0;
        while (i != k-1 && cnt[i] != 1) i++;
        if (i == k-1 && cnt[i] != 1) {flag = false; ans = false;}
        else { //не конец или равно количество 1
            for (int j = 0; j < n; j++) {
                if (a[i][j] != -1){
                    buf = a[i][j];
                    ind = j;
                    a[i][j] = -1;
                    cnt[i]--;
                    cnt_0[i] = -1;
                }
            }
            for (int j = 0; j < k; j++){
                if (a[j][ind] == buf) {  //если в скобках такой же литерал? hfdysq 1
                    cnt[j] = 0;
                    cnt_0[j] = -1;
                } else if (a[j][ind] != -1 && a[j][ind] != buf) {
                    if (cnt[j] == 1) {
                        flag = false;
                        ans = true;
                      //  cout << j << " " << ind <<" " << buf << endl;
                    }
                    else {
                        if (a[j][ind] == 0) cnt_0[j]--;
                        a[j][ind] = -1;
                        cnt[j]--;
                    }
                }
            }
        }
    }
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;




}
