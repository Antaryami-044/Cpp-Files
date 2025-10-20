#include<iostream>
#include<vector>
using namespace std;

vector<int> moveZeros(vector<int> &arr, int n) {
    int count = 0;
    for(int i=0; i <n; i++){
        if(arr[i] != 0){
            arr[count++] = arr[i];
        }
    }
    for(int i = count; i < n; i++) {
        arr[i] = 0;
    }
    return arr;
}

int linearSearch(vector<int> &arr, int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}

vector<int> mergeArrays(vector<int>& a, vector<int>& b) {
    int i = 0, j = 0;
    vector<int> merged;
    while(i < a.size() && j < b.size()) {
        int val;
        if(a[i] < b[j]){
            val = a[i++];
        } else if(a[i] > b[j]){
            val = b[j++];
        } else{
            val = a[i++];
            j++;
        }

        if(merged.empty() || merged.back() != val) {
            merged.push_back(val);
        }
    }

    while(i < a.size()){
        if(merged.empty() || merged.back() != a[i]) {
            merged.push_back(a[i]);
        }
        i++;
    }

    while(j < b.size()){
        if(merged.empty() || merged.back() != b[j]) {
            merged.push_back(b[j]);
        }
        j++;
    }
    
    return merged;
}

vector<int> mergeArraysIntersection(vector<int>& a, vector<int>& b) {
    int i = 0, j = 0;
    vector<int> merged;
    while(i < a.size() && j < b.size()) {
        int val;
        if(a[i] == b[j]){
            val = a[i++];
        } else if(a[i] > b[j]){
            j++;
        } else {
            i++;
        }


        if(merged.empty() || merged.back() != val) {
            merged.push_back(val);
        }
    }

    // while(i < a.size()){
    //     if(merged.empty() || merged.back() != a[i]) {
    //         merged.push_back(a[i]);
    //     }
    //     i++;
    // }

    // while(j < b.size()){
    //     if(merged.empty() || merged.back() != b[j]) {
    //         merged.push_back(b[j]);
    //     }
    //     j++;
    // }
    
    return merged;
}

int main(){
    // int n;
    // cout << "Enter the size of the array: ";    
    // cin >> n;
    // vector<int> arr(n);
    // cout << "Enter the elements of the array: ";
    // for(int i = 0; i < n; i++) {
    //     cin >> arr[i];
    // }
    // vector<int> result = moveZeros(arr, n);
    // cout << "Array after moving zeros to the end: ";
    // for(int i = 0; i < n; i++) {
    //     cout << result[i] << " ";
    // }

    // int key;
    // cout << "\nEnter the key to search: ";      
    // cin >> key;
    // int index = linearSearch(arr, n, key);  
    // if(index != -1) {
    //     cout << "Element found at index: " << index << endl;
    // } else {
    //     cout << "Element not found in the array." << endl;
    // }


    int m;
    cout << "Enter the size of the second array: "; 
    cin >> m;
    vector<int> b(m);
    cout << "Enter the elements of the second array: ";
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int m1;
    cout << "Enter the size of the third array: "; 
    cin >> m1;
    vector<int> c(m1);
    cout << "Enter the elements of the 3rd array: ";
    for(int i = 0; i < m1; i++) {
        cin >> c[i];
    }

    // vector<int> mergedArray = mergeArrays(b, c);  
    // cout << "Merged array union: ";
    // for(int i = 0; i < mergedArray.size(); i++) {
    //     cout << mergedArray[i] << " ";
    // }

    vector<int> mergedArray = mergeArraysIntersection(b, c);    
    cout << "Merged array intersection : ";
    for(int i = 0; i < mergedArray.size(); i++) {
        cout << mergedArray[i] << " ";
    }



    return 0;
}