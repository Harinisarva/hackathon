#include <iostream>
using namespace std;

int countRegularPolygons(int N, int K, int D[]) {
    int perimeter = 0;
    for (int i = 0; i < N; ++i) {
        perimeter += D[i];
    }
    
    if (perimeter % K != 0) return 0;
    int sideLength = perimeter / K;
    int validCount = 0;

    for (int start = 0; start < N; ++start) {
        int currentSum = 0;
        int sideCount = 0;
        
        for (int i = 0; i < N; ++i) {
            int idx = (start + i) % N;  
            currentSum += D[idx];
            
            if (currentSum == sideLength) {
                sideCount++;
                currentSum = 0;
            } 
            else if (currentSum > sideLength) {
                sideCount = 0;
                break;
            }
        }
        
        if (sideCount == K) validCount++;
    }

    return validCount / K;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, K;
        cin >> N >> K;
        int D[100];
        
        for (int i = 0; i < N; ++i) {
            cin >> D[i];
        }
        
        cout << countRegularPolygons(N, K, D) << endl;
    }
    
    return 0;
}
