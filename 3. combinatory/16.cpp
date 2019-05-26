#include <bits/stdc++.h>

using namespace std;
int n,k;
vector <int> a;

vector <vector <long long> > s;

int main()
{
    freopen("choose2num.in","r",stdin);
    freopen("choose2num.out","w",stdout);
    cin >> n >> k;
    a.resize(k+1);
    a[0] = 0;
    for (int i = 0; i < k; i++){
        cin >> a[i+1];
    }
    s.resize(n+1);
    for (long long i = 0; i < s.size(); i++){
        s[i].resize(n+1);
    }

    for (int i = 0; i < n+1; i++){
        s[i][0] = 1;        s[i][1] = i;
    }
    for (int i = 2; i < n+1; i++){
        for (int j = 2; j <= i; j++){
            s[i][j] = s[i-1][j] + s[i-1][j-1];
        }
    }

    int buf = 0;

    for (int i = 1; i < k+1; i++){
        for (int j = a[i-1]+1; j <= a[i] - 1; j++){
            buf += s[n-j][k-i];
        }
    }
    cout << buf;

}
