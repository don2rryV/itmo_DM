#include <bits/stdc++.h>

using namespace std;
int k, n;
vector <int> a;

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
    //freopen("partition.in","r",stdin);
    //freopen("partition.out","w",stdout);
    cin >> k;
    a.resize(k);
    n = k;
    for (int i = 0; i < n; i++){
        a[i] = 1;
    }

    for (int i = 0; i < a.size(); i++){
            if (i != a.size()-1)
                cout << a[i] << "+"; else
            cout << a[i];
        }
        cout << endl;

    while (a.size()!= 1){
        next_sum();
        for (int i = 0; i < a.size(); i++){
            if (i != a.size()-1)
                cout << a[i] << "+"; else
            cout << a[i];
        }
        cout << endl;
    }
    //if (n == 1) cout << 1 << endl;
}
