#include <bits/stdc++.h>

using namespace std;
int n;
vector <vector <int> > a;

int main()
{
    cin >> n;
    vector <int> used;
    a.resize(2);
    a[0].push_back(1);
    for (int i = 2; i <= n; i++){
        a[1].push_back(i);
    }
    bool flag = false;
    for (int i = a.size()-1; i >= 0; i--){
        if (used.size() != 0 && used[used.size()-1] > a[i][a[i].size()-1]){
            a[i].push_back(used[used.size()-1]);
            used.pop_back();
            break;
        }
        int j;
        for (j = a[i].size() - 1; j >=0; j--){
            if (used.size()!= 0 && j != 0 && used[used.size()-1]>a[i][j]){
                a[i][j] = used[used.size() - 1];
                flag = true;
                break;
            }
        }
        if (flag) break;
        used.push_back(a[i][j]);
        a[i].resize(j);
    }
    sort(used.begin(), used.end());
    for (int i = 0; i < used.size(); i++){
        a[0].push_back(used[i]);
    }
    for (int i = 0; i < a[0].size(); i++){
        cout << a[0][i] << " ";
    }

}
