#include <bits/stdc++.h>

using namespace std;
vector <int> a;
int n;
int buf  = 0;
int func(int k, int length){
   // cout << length << " " << n;
    if (length < n){
        a[k] = 0;
        func(k+1, length+1);
        a[k] = 1;
        func(k+1, length+1);
        a[k] = 2;
        func(k+1, length+1);
    } else {
        if (buf < pow(3, n-1)){
        for (int i = 0; i < length; i++){
            cout << a[i];
        }
        cout << endl;
        buf++;
        for (int i = 0; i < length; i++){
            cout << (a[i]+1) % 3;
        }
        cout << endl;

        for (int i = 0; i < length; i++){
            cout << (a[i]+2) % 3;
        }
        cout << endl;

        }


    }
}


int main()
{
    freopen("antigray.in","r",stdin);
    freopen("antigray.out","w",stdout);
    cin >> n;
    a.resize(n);
    func(0,0);

}
