#include <bits/stdc++.h>
using namespace std;

bool sahiHai(vector<int>& a, vector<int>& b, string t, int distinct){
    int cnt = 0;
    for(int i = 0; i < 256; i++){
        if(b[i] > 0){
            if(a[i] >= b[i]){
                cnt++;
            }
        }
        
    }
    if(cnt == distinct){
        return true;
    }
    return false;
}

string hardSlide(string s, string t){
    int m = s.size();
    int n = t.size();
    int low = 0, high = 0;
    int alow = 0;
    int res = m;
    int distinct = 0;
    bool trigger = false;
    vector<int> a(256, 0);
    vector<int> b(256, 0);

    map<char, int> dist;

    for(int i = 0; i < n; i++){
        b[t[i]]++;
        dist[t[i]]++;
    }

    distinct = dist.size();

    while(high < m){
        a[s[high]]++;
        cout << "added " <<  s[high];
        cout << endl;
        while(sahiHai(a, b, t, distinct)){
            trigger = true;
            int len = high - low + 1;
            if(len < res){
                res = len;
                alow = low;
            }
            if(len == n) break;
            a[s[low]]--;
            cout << "removed " <<  s[low];
            cout << endl;
            low++;
            
        }
        high++;
    }
    if(trigger){
        return s.substr(alow, res);
    }
    return "";


}


int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << hardSlide(s, t);
}