#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("problem4.in","r",stdin);
    freopen("problem4.out","w",stdout);
    ios_base::sync_with_stdio(false);
    int n, m, k, leng;
    long long consta = 1000000007;
    cin >> n >> m >> k >> leng;
    set <int> term;
    vector <int> d;
    d.resize(n);
    d[0] = 1;
    for (int i = 0; i < k; i++){
        int p; cin >> p; p--;
        term.insert(p);
    }

    vector <vector <int> > transition;
    transition.resize(n);
    for (int i = 0; i < m; i++){
        long long oldCond, newCond; char buf;
        cin >> oldCond >> newCond >> buf;
        oldCond--; newCond--;
        transition[oldCond].push_back(newCond);
    }

    set <int> cur;
    cur.insert(0);
    for (int i = 0; i < leng; i++){
        set <int> buf;
        vector<int> temp;
        temp.resize(n);
        for (auto k : cur){
            for (int j = 0; j < transition[k].size(); j++){
                int a = transition[k][j];
                temp[a] = temp[a] + d[k];
                temp[a] = temp[a] % consta;
                buf.insert(a);
            }
        }
        cur = buf;
        d = temp;
    }

    long long cnt = 0;
    for (int i = 0; i < d.size(); i++){
        if (term.count(i) > 0){
            cnt += d[i];
            cnt = cnt % consta;
        }
    }

    cout << cnt;
}
