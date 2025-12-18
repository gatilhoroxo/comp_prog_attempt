//travei aqui
//tea queue
#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second 

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.st > b.st;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        queue<pair<int,int>> student;
        for(int ind=0; ind<n; ind++) {
            pair<int,int> i;
            cin >> i.st >> i.nd;
            student.push(i);
        }

        int time=1; 
        bool used = false;
        for(;!student.empty();){
            auto i = student.front();
            time = max(time, i.st);
            if(time<=i.nd){
                cout << time << ' ';
                time++; 
            } else cout << 0 << ' ';
            student.pop();
        }
        cout << '\n';
    }

    return 0;
}