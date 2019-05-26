#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("problem2.in","r",stdin);
    freopen("problem2.out","w",stdout);
    ios_base::sync_with_stdio(false);

    long long n, m, k;
    string str;
    cin >> str;
    cin >> n >> m >> k;
    set <long long> term;
    for (long long i = 0; i < k; i++){
        long long p; cin >> p; p--;
        term.insert(p);
    }

    vector <vector <set <long long>>> transition;
    transition.resize(n);
    for (int i = 0; i < n; i++){
        transition[i].resize(26);
    }

    for (int i = 0; i < m; i++){
        long long oldCond, newCond; char buf;
        cin >> oldCond >> newCond >> buf;
        oldCond--; newCond--;
        transition[oldCond][(int)buf-(int)'a'].insert(newCond);
    }
    set <long long> cur;
    cur.insert(0);
    for (int i = 0; i < str.length(); i++){
        set <long long> buf;
        for (auto j : cur){
            for (auto p : transition[j][(int)str[i] - (int)'a']){
                buf.insert(p);
            }
        }
        cur = buf;
    }
    bool flag = false;
    for (auto i : cur){
        if (term.count(i) > 0){
            flag = true;
        }
    }
    if (flag) cout << "Accepts" << endl;
        else cout << "Rejects";
}
