#include <bits/stdc++.h>
using namespace std;

bool charMatch(vector<int>& a, string t, int n){
    int cnt = 0;

    for(int i = 0; i < n; i++){
        if(a[t[i]] <= 0){
            cnt++;
        }
    }

    if(cnt == n){
        return true;
    }
    return false;
}

string hardSlide(string s, string t){
    int m = s.size();
    int n = t.size();
    vector<int> a(256, 0);
    int high = 0, low = 0;
    int res = m;
    int alow = 0;
    bool trigger = false;

    for(int i = 0; i < n; i++){
        a[t[i]]++;
    }
    

    // for(int i = 0; i < 26; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    while(high < m){
        a[s[high]]--;

    // for(int i = 0; i < 26; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;
        bool cond = charMatch(a, t, n);
        
        while(cond){
            trigger = true;
            int len = high - low + 1;
            if(len < res){
                res = len;
                alow = low;
            }
            if(len == n) break;
            a[s[low]]++;
            low++;
            cond = charMatch(a, t, n);

        }
        

        high++;
    }
    if(trigger){
        return s.substr(alow, res);
    }
    return "";

}


int main(){
    // string s = "abhyanshu";
    // string t = "ash";
    string s = "a";
    string t = "a";

    cout << hardSlide(s, t);
}