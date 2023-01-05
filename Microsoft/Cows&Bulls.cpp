#include <bits/stdc++.h>
using namespace std;

string getHint(string secret, string guess) {
        map<char,int> f;
        map<char,int> ff;
        int bulls=0, cows=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                bulls++;
            }else{
                f[secret[i]]++;
                ff[guess[i]]++;
            }
        }
        for(auto &it: f){
            if(ff.find(it.first)!=ff.end()){
                cows+=min(ff[it.first],it.second);
            }
        }
        string s="";
        s+=to_string(bulls)+'A'+to_string(cows)+'B';
        return s;
    }
int main()
{
    string secret="1123", guess="0111";
    getHint(secret, guess);
}