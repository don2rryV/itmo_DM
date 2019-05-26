#include <bits/stdc++.h>

using namespace std;
long long k, n;
vector <long long> a;


bool next_sum(){
    a[k-1]--; a[k-2]++;
    if (a[k-2] > a[k-1]){
        a[k-2] += a[k-1];
        a.pop_back();
        k--;
    } else{
        while (a[k-2] * 2 <= a[k-1]){
            a.push_back(a[k-1] - a[k-2]);
            k = a.size();
            a[k-2] = a[k-3];
        }
    }
}


int main()
{
    freopen("num2part.in","r",stdin);
    freopen("num2part.out","w",stdout);
    long long r;
    cin >> k >> r;
    a.resize(k);
    n = k;
    for (long long i = 0; i < n; i++){
        a[i] = 1;
    }

   /* for (int i = 0; i < a.size(); i++){
            if (i != a.size()-1)
                cout << a[i] << "+"; else
            cout << a[i];
        }
        cout << endl;*/

    while (r > 0){
        next_sum();
        r--;
    }
    for (long long i = 0; i < a.size(); i++){
            if (i != a.size()-1)
                cout << a[i] << "+"; else
            cout << a[i];
        }
        cout << endl;
}
