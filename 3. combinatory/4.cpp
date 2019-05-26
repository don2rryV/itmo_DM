#include <bits/stdc++.h>

using namespace std;

int n;
vector <int> a;
vector <bool> use;
vector <int> power;

int main()
{
    freopen("chaincode.in","r",stdin);
    freopen("chaincode.out","w",stdout);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++){
        a[i] = 0;
    }

    use.resize(pow(2, n));
    for (int i = 0; i < use.size(); i++) use[i] = false;
    use[0] = true;

    power.resize(n);
    for (int i = 1; i < n; i++){
        power[i] = pow(2, i);
       // cout << power[i] << " ";
    }

    int buf;
    for (int i = 0; i < n; i++) cout << "0";
    cout << endl;
    for (int i = 0; i < pow(2,n); i++){
        buf = 1;
        for (int j = 1; j < n; j++){
            buf += a[n-j]*power[j];
        }
        if (!use[buf]) {

            for (int k = 1; k < n; k++){
                cout << a[k];
                a[k-1] = a[k];
            }
            a[n-1] = 1;
            cout << "1" << endl;
            use[buf] = true;


        }else{
          //  for (int i = 0; i < n; i++) cout << power[i] << " ";
          //  cout << endl;

            buf = 0;
            for (int j = 1; j < n; j++){
                buf += a[n-j]*power[j];
            }
            //s cout << "ura " << buf << endl;
            if (!use[buf]) {

            for (int k = 1; k < n; k++){
                cout << a[k];
                a[k-1] = a[k];
            }
            a[n-1] = 0;
            cout << "0" << endl;
            use[buf] = true;


            }

        }

    }


}
