#include <bits/stdc++.h>

using namespace std;
vector <int> a;
int n;

bool func(){
    int i;
    for (i = n-2; i > -1; i--){
        if (a[i+1] > a[i]) break;
    }
    if (i == -1) return false;
    int j;
    for (j = n-1; j > -1; j--){
        if (a[j] > a[i]) break;
    }
    //cout << i << " " << j << endl;
    swap(a[i], a[j]);
    int l = i+1;
    int r = n-1;
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
    //freopen("permutations.in","r",stdin);
    //freopen("permutations.out","w",stdout);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
            a[i] = i+1;
            cout << a[i] << " ";
    }
    cout << endl;
    while(func()){
        for (int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
}
