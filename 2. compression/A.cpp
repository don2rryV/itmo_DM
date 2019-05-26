#include <bits/stdc++.h>

using namespace std;
long long ans = 0;
int main()
{
    freopen("huffman.in","r",stdin);
    freopen("huffman.out","w",stdout);
    vector <long long> b;
    vector <long long> a;
    int n;
    cin >> n;
    a.resize(n+1);
    b.resize(n+1);
    for (int i = 0; i <= n; i++){
        b[i] = 1000000001;
    }
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    a[n] = 100000000000000;
    sort(a.begin(), a.end());
    int i, j;
    i = 0; j = 0;


    //cout << ans << endl;
    for (int k = 0; k < n-1; k++){
        if ((a[i] + a[i+1] <= a[i] + b[j]) && (a[i] + a[i+1] <= b[j] + b[j+1])){
            b[k] = a[i] + a[i+1];
           // cout << ans << " "<< endl;
            ans = ans + b[k];
           // cout << b[k] << endl;
           // cout << ans << " " << endl;
            i+=2;
        } else if (a[i] + b[j] <= a[i] + a[i+1] && a[i] + b[j] <= b[j] + b[j+1]){
            b[k] = a[i] + b[j];
            ans += b[k];
          //  cout << ans << " " << endl;
            i++;
            j++;
        } else if (b[j] + b[j+1] <= a[i] + a[i+1] && b[j] + b[j+1] <= a[i] + b[j]){
            b[k] = b[j] + b[j+1];
            ans += b[k];
            // cout << ans << " " << endl;
            j+=2;
        }

    }
  //  for (int k = 0; k < b.size(); k++) cout << b[k] << " ";
    cout << ans;
}
