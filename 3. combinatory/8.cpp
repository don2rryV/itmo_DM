/#include <bits/stdc++.h>

using namespace std;
int n, k;
vector <int> a;

int next(){
    int ind = -1;
    for (int i = k-1; i > -1; i--){
        if (a[i]<n){
            a[i]++;
            ind = i;
            break;
        }
    }
    if (ind == -1) return false;
    for (int i = ind + 1; i < k; i++){
        a[i] = a[i-1] + 1;
    }
    return true;

}

int main()
{
    //freopen("choose.in","r",stdin);
    //freopen("choose.out","w",stdout);
    cin >> n >> k;
    a.resize(k);
    for (int i = 0; i < k; i++) {
            a[i] = i+1;
            cout << a[i] << " ";
    }
    cout << endl;
    while (next()){
        bool flag = true;
        for (int i = 0; i < k; i++){
            if (a[i] > n) flag = false;
        }
    if (flag){
        for (int i = 0 ; i < k; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    }
}
