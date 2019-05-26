#include <bits/stdc++.h>

using namespace std;

vector <vector <int> > tran, way;
vector <bool> vis;
vector <int> color;
vector <int> ans;

void dfs(int p){
    if (vis[p] == true) return;
    vis[p] = true;
    for (int k = 0; k < way[p].size(); k++){
        if (!vis[way[p][k]])
            dfs(way[p][k]);
    }
}

bool top(int p){
    color[p] = 1;
    for (int i = 0; i < tran[p].size(); i++){
        if ( color[tran[p][i]] == 1 && vis[tran[p][i]] || color[tran[p][i]] == 0 && top(tran[p][i]) ){
            return true;
        }
    }
    color[p] = 2;
    ans.push_back(p);
    return false;
}

int main()
{
    freopen("problem3.in","r",stdin);
    freopen("problem3.out","w",stdout);
    ios_base::sync_with_stdio(false);
    long long n, m, k;
    cin >> n >> m >> k;
    vis.resize(n);
    tran.resize(n);
    way.resize(n);
    set <long long> term;

    for (long long i = 0; i < k; i++){
        long long p; cin >> p; p--;
        term.insert(p);
    }
    vector <map <char, long long>> transition;
    transition.resize(n);
    for (long long i = 0; i < m; i++){
        long long oldCond, newCond; char buf;
        cin >> oldCond >> newCond >> buf;
        oldCond--; newCond--;
        tran[oldCond].push_back(newCond);
        way[newCond].push_back(oldCond);
    }

    for (auto i : term){
            dfs(i);
           // cout << i << " ";
        }

    color.resize(n);
    for(int i = 0; i < n; i++){
        color[i] = 0;
    }


    if (top(0)) cout << "-1" ; else {

        reverse(ans.begin(), ans.end());
        vector <int> paths; paths.resize(n);
        paths[0] = 1;
        for (int i = 0; i < ans.size(); i++){
            for (int j = 0; j < way[ans[i]].size(); j++){
                paths[ans[i]] += paths[way[ans[i]][j]];
                //paths[ans[i]] %= 1000000007;
            }
        }
        long long out = 0;
        for (auto i : term){
            out += paths[i];
            //out %= 1000000007;
        }
        cout << out;
    }

}
