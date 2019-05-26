#include <bits/stdc++.h>

using namespace std;
int n, buf, m;
vector <string> s;
vector <vector<int> > a;
int main()
{
    cin >> n;
    s.resize(pow(2.0, n));
    a.resize(pow(2.0, n));
    m = pow(2.0 , n);
    for (int i = 0; i < m; i++){
        a[i].resize(m);
    }
    //cout << pow(2.0, n);
    for (int i = 0; i < pow (2.0, n); i++){
        cin >> s[i] >> a[i][0];
    }

  /*  for (int i = 0; i < pow(2.0, n); i++){
        for (int j = 0; j < pow(2.0, n); j++){
         cout << a[i][j] << " ";
    }
    cout << endl;
    }
cout << endl;
*/
    for (int j = 1; j < m; j++){
        for (int i = 0; i < m-j; i++){
            a[i][j] = (a[i][j-1] + a[i+1][j-1]) % 2;
        }
    }

  /*  for (int i = 0; i < pow(2.0, n); i++){
        for (int j = 0; j < pow(2.0, n); j++){
         cout << a[i][j] << " ";
    }
    cout << endl;
    }
*/    for (int i = 0; i < m; i++){
        cout << s[i] << " " << a[0][i] << endl;
    }



}
