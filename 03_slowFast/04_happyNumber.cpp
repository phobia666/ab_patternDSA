#include <bits/stdc++.h>
using namespace std;

int happ(int fast){
    int num = fast;
    int sum = 0;
    int rem;
    while(num != 0){
        rem = num % 10;
        sum = sum + (rem * rem);
        num = num / 10;
    }
    return sum;
}

bool isHappy(int x){
    int slow = x;
    int fast = x;

    while(happ(fast) != 1 && happ(happ(fast)) != 1){
        slow = happ(slow);
        fast = happ(happ(fast));

        if(slow == fast){
            return false;
        }
    }
    return true;

}


int main(){
    int x;
    cin >> x;

    cout << isHappy(x);
}