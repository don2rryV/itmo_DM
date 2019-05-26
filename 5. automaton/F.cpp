#include <bits/stdc++.h>

using namespace std;
vector <bool> isTerm1, isTerm2;
vector <bool> used;
vector<vector <int> > tran1;
vector <vector<int>> tran2;

bool Check(int u, int v){
    used[u] = true;
    if (isTerm1[u] != isTerm2[v]) return false;
    bool res = true;
    for (size_t c = 0; c < 26; c++){
        pair <int, int> t;
        t.first = tran1[u][c]; t.second = tran2[v][c];
        if (t.first < 0 || t.second < 0){
            if (t.second != t.first){
                return false;
            }
        }
        if (t.first > 0 && !used[t.first] )
            res = res && Check(t.first, t.second);
    }
    return res;
}

int main()
{
    freopen("isomorphism.in","r",stdin);
    freopen("isomorphism.out","w",stdout);
    ios_base::sync_with_stdio(false);
    int n1, m1, k1, n2, m2, k2;
    cin >> n1 >> m1 >> k1;
    //set <int> term1;
    used.resize(n1);

    isTerm1.resize(n1);
    for (int i = 0; i < k1; i++){
        int p; cin >> p; p--;
        isTerm1[p] = true;
    }
    //vector <vector <int> > tran1;
    tran1.resize(n1);
    for (int i = 0; i < n1; i++){
        tran1[i].resize(26);
        for (int j = 0; j < 26; j++){
            tran1[i][j] = -1;
        }
    }

    for (int i = 0; i < m1; i++){
        int oldCond, newCond; char buf;
        cin >> oldCond >> newCond >> buf;
        oldCond--; newCond--;
        tran1[oldCond][(int)buf - (int)'a'] = newCond;
    }

    cin >> n2 >> m2 >> k2;
    //set <int> term2;
    isTerm2.resize(n2);
    for (int i = 0; i < k2; i++){
        int p; cin >> p; p--;
        isTerm2[p] = true;
    }
    //vector <vector <int> > tran2;
    tran2.resize(n2);
    for (int i = 0; i < n2; i++){
        tran2[i].resize(26);
        for (int j = 0; j < 26; j++){
            tran2[i][j] = -1;
        }
    }

    for (int i = 0; i < m2; i++){
        int oldCond, newCond; char buf;
        cin >> oldCond >> newCond >> buf;
        oldCond--; newCond--;
        tran2[oldCond][(int)buf - (int)'a'] = newCond;
    }

    bool ans = Check(0,0);
    /*for (int i = 0; i < n1; i++){
        for (int j = 0; j < 26; j++){
            cout << tran1[i][j] << " ";
        }
        cout << endl;
    }*/
    if (ans) cout << "YES"; else cout << "NO";


}
