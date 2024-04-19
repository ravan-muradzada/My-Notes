#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int f(vector<int>& arr, int target){
    int left = 0, right = arr.size() - 1, mid;
    int closestNumber = arr[0];
    
    while (left <= right){
        mid = left + (right - left) / 2;
        
        if (abs(target - closestNumber) > abs(target - arr[mid])){
            closestNumber = arr[mid];
        }

        if (arr[mid] == target){
            return arr[mid]; // target itself
        }else if (arr[mid] > target){
            right = mid - 1;
        }else left = mid + 1;
    }
    return closestNumber;
}

int main(){
    vector<int> arr = {1, 2, 5, 12, 34};
    int target = 13;
    cout << f(arr, target);

    return 0;
}