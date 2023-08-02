#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int arr[100];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int v;
    cin >> v;
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] == v) count++;
    }
    
    printf("%d", count);
    
    return 0;
}