#include <iostream>
#include <vector>
using namespace std;

template <class T> void sort(vector<T> &a, int start, int end){
    if(start >= end) return;
    
    T pivot = a[start];
    int i = start;
    int j = end;
    while(true){
        while(a[i] < pivot) i++; // pivot以上の数値を左から探す
        while(a[j] > pivot) j--; //pivot以下の数値を右から探す
        if(i >= j) break; //探索範囲が重複したら終了

        swap(a[i], a[j]);
        i++;
        j--;
    }
    sort(a, start, i - 1);
    sort(a, j + 1, end);
}

int main(){
    vector<int> a = {5, 5, 5, 5, 5};
    sort(a, 0, a.size() - 1);
    for(auto x : a){
        cout << x << " ";
    }
    cout << endl;
}
