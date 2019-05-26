#include <bits/stdc++.h>

using namespace std;
vector <bool> isTerm1, isTerm2;
vector <vector <bool> > used1;

bool Check(vector<vector <int> > tran1, vector <vector<int>> tran2){
    queue <pair <int, int>> q;
    q.push({0,0});

    while(!q.empty()){
        int u = q.front().first;
        int v = q.front().second;
        q.pop();
        if (isTerm1[u] != isTerm2[v]) return false;
        used1[u][v] = true;
        for (int c = 0; c < 26; c++){
            if (!used1[tran1[u][c]][tran2[v][c]]){
                q.push({tran1[u][c], tran2[v][c]});
                //used1[tran1[u][c]] = true;
                //used2[tran2[v][c]] = true;
            }
        }
    }
    return true;

}

int main()
{
    freopen("equivalence.in","r",stdin);
    freopen("equivalence.out","w",stdout);
    ios_base::sync_with_stdio(false);
    int n1, m1, k1, n2, m2, k2;
    cin >> n1 >> m1 >> k1;
    //set <int> term1;
    //used.resize(n1);
    n1++;
    isTerm1.resize(n1);
    for (int i = 0; i < k1; i++){
        int p; cin >> p; p--;
        isTerm1[p] = true;
    }
    vector <vector <int> > tran1;
    tran1.resize(n1);
    for (int i = 0; i < n1; i++){
        tran1[i].resize(26);
        for (int j = 0; j < 26; j++){
            tran1[i][j] = n1-1;
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
    n2++;
    isTerm2.resize(n2);
    for (int i = 0; i < k2; i++){
        int p; cin >> p; p--;
        isTerm2[p] = true;
    }
    vector <vector <int> > tran2;
    tran2.resize(n2);
    for (int i = 0; i < n2; i++){
        tran2[i].resize(26);
        for (int j = 0; j < 26; j++){
            tran2[i][j] = n2 - 1;
        }
    }

    for (int i = 0; i < m2; i++){
        int oldCond, newCond; char buf;
        cin >> oldCond >> newCond >> buf;
        oldCond--; newCond--;
        tran2[oldCond][(int)buf - (int)'a'] = newCond;
    }
    used1.resize(n1);
    for (int i = 0; i < n1; i++){
        used1[i].resize(n2);
    }
    used1[0][0] = true;

    bool ans = Check(tran1, tran2);
    if (ans) cout << "YES"; else cout << "NO";
}
