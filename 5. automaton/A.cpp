#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("problem1.in","r",stdin);
    freopen("problem1.out","w",stdout);
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

    vector <map <char, long long>> transition;
    transition.resize(n);
    for (long long i = 0; i < m; i++){
        long long oldCond, newCond; char buf;
        cin >> oldCond >> newCond >> buf;
        oldCond--; newCond--;
        transition[oldCond].insert(pair<char, long long>(buf, newCond));
    }

    long long whereAreWeNow = 0;
    bool flag = true;

    for (long long i = 0; i < str.length(); i++){
        if (transition[whereAreWeNow].count(str[i]) != 0){
            whereAreWeNow = (*transition[whereAreWeNow].find(str[i])).second;
        } else {
            flag = false;
            break;
        }
    }

    if (flag && term.count(whereAreWeNow) != 0) cout << "Accepts" << endl;
        else cout << "Rejects";

}