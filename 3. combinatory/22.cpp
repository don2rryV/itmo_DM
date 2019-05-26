#include <bits/stdc++.h>

using namespace std;
long long k, n, cnt;
vector <long long> a, b;

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
    freopen("part2num.in","r",stdin);
    freopen("part2num.out","w",stdout);
    string s;
    cin >> s; long long sum = 0; long long buf;
    long long i = 0;
    while (i < s.length()){
        buf = 0;
        while(s[i] != '+' && i < s.length()) {buf = buf*10 + int(s[i]) - 48; i++;}
        b.push_back(buf);
        sum += buf;
        i++;

    }
    //for (int j = 0; j < a.size(); j++)
    //    cout << a[j] << " ";

    b.resize(b.size());
    a.resize(sum);
    k = sum;
    n = k;
    for (int i = 0; i < n; i++){
        a[i] = 1;
    }
bool flag = true;
long long cnt_buf = 0;

    for (long long i = 0; i < a.size(); i++){
            if (a[i] == b[i] && a.size() == b.size()) cnt_buf++;
        }
        if (cnt_buf == a.size()) flag = false; else cnt++;



    while (a.size()!= 1 && flag){
        next_sum(); cnt_buf = 0;

        for (long long i = 0; i < a.size(); i++){
            //cout << a[i] << " " << b[i] << endl;
            if (a[i] == b[i] && a.size() == b.size()) cnt_buf++;
        }
        //cout << "cnt_buf = " << cnt_buf << endl;
        if (cnt_buf == a.size()) flag = false; else cnt++;

    }
    cout << cnt;
    //if (n == 1) cout << 1 << endl;
}
