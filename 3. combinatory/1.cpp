#include <bits/stdc++.h>

using namespace std;
int n;
vector <int> a;

bool func (int k, int length){
    if (k<length){
        a[k] = false;
        func(k+1,length);
        a[k] = true;
        func(k+1, length);
    }else{

        for (int i = 0; i < length; i++){
            cout << a[i];
        }
       cout << endl;
    /*if (main_main() == 0) {flag_main = false;}

    }*/
    }
}
int main()
{
    freopen("allvectors.in","r",stdin);
    freopen("allvectors.out","w",stdout);
    cin >> n;
    a.resize(n);
    func(0,n);
}
