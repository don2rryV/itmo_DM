#include <bits/stdc++.h>

using namespace std;
vector <int> a;
vector <vector <int> > out;
int j = 0;
    int n, ans;

bool func (int k, int length){
    if (k<length){
        a[k] = false;
        func(k+1,length);
        a[k] = true;
        func(k+1, length);
    }else{
        for (int i = 0; i < length; i++){
            out[j][i] = a[i];
            if (i > 0 && out[j][i] == 1 && 1 == out[j][i-1] && out[j][n] == 0){
                ans--;
                out[j][n] = 1;
            }
        }

        j++;

        /*for (int i = 0; i < length; i++){
            cout << a[i];
        }
       cout << endl;*/

    }
}

int main()
{
freopen("vectors.in","r",stdin);
    freopen("vectors.out","w",stdout);
    cin >> n;
    ans = pow(2,n);
    out.resize(pow(2,n));
    a.resize(n);
    for (int i = 0; i < out.size(); i++) out[i].resize(n+1);
    func(0,n);
    cout << ans << endl;
    for (int i = 0; i < out.size(); i++){
        if (out[i][n] == 0){
        for (int j = 0; j < out[i].size()-1; j++){

            cout << out[i][j];
        }
        cout << endl;
        }
    }
}
