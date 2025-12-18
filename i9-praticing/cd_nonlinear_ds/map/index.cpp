//UVa 00417 - Word Index
//era mais simples do que o que eu achava
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    map<string,int> words;
    int counter = 1;
    for(char c='a'; c<='z';c++){
        string f(1, c);
        words[f] = counter++;
    }
    for(char c='a'; c<='y';c++){
        for(char c2=c+1; c2<='z';c2++){
            string f = {c,c2};
            words[f] = counter++;
        }
    }
    for(char c='a'; c<='x';c++){
        for(char c2=c+1; c2<='y';c2++){
            for(char c3=c2+1; c3<='z';c3++){
                string f = {c,c2,c3};
                words[f] = counter++;
            }
        }
    }
    for(char c='a'; c<='w';c++){
        for(char c2=c+1; c2<='x';c2++){
            for(char c3=c2+1; c3<='y';c3++){
                for(char c4=c3+1; c4<='z'; c4++){
                    string f = {c,c2,c3,c4};
                    words[f] = counter++;
                }
            }
        }
    }
    for(char c='a'; c<='v';c++){
        for(char c2=c+1; c2<='w';c2++){
            for(char c3=c2+1; c3<='x';c3++){
                for(char c4=c3+1; c4<='y'; c4++){
                    for(char c5=c4+1; c5<='z';c5++){
                        string f = {c,c2,c3,c4,c5};
                        words[f] = counter++;
                    }
                }
            }
        }
    }    

    string s;
    while(getline(cin,s)){
        cout << words[s] << '\n';
    }

    return 0;
}