#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string s, t;
    getline(cin, s);
    getline(cin, t);
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    
    int ptr1 = 0, ptr2 = 0;
    
    while (true){
        if (s[ptr1] != t[ptr2]){
            cout << t[ptr2];
            break;
        }
        ptr1++; 
        ptr2++;
    }
    
    
    return 0;
}
