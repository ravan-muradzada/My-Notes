#include <iostream>
using namespace std;

int f(int x){
    if (x < 4) return 1;
    if (x == 4) return 2;
    
    int left = 0, right = x, mid, fmid;
    
    while (left <= right){
        mid = left + (right - left) / 2;
        fmid = mid * mid;
        if (fmid == x || right - left == 1){
            break;
        }else if (fmid > x){
            right = mid;
        }else left = mid;
    }
    return mid;
}
int main(){
    int x;
    cin >> x;
    cout << f(x);
    
    return 0;
}