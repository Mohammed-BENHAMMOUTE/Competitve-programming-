
#include <iostream>
#include <vector>
using namespace std;
const int MAX_SIZE = 1000;
bool adjacencyMatrix[MAX_SIZE][MAX_SIZE], leftSubtree[MAX_SIZE][MAX_SIZE], rightSubtree[MAX_SIZE][MAX_SIZE];

int readInt() {
    int number = 0, sign = 1;
    char ch;
    while((ch = getchar()) > '9' || ch < '0') 
        if(ch == '-') sign = -1;
    while(ch >= '0' && ch <= '9') {
        number = (number << 1) + (number << 3) + (ch ^ 48);
        ch = getchar();
    }
    return number * sign;
}

int gcd(const int a, const int b) {
    if(!b) return a;
    return gcd(b, a % b);
}

int main() {
    int arraySize;
    arraySize = readInt();
    vector<int> numbers(arraySize + 1);
    for(int i = 1; i <= arraySize; ++i) 
        numbers[i] = readInt();
    for(int i = 1; i <= arraySize; ++i)
        for(int j = 1; j <= arraySize; ++j)
            adjacencyMatrix[i][j] = (gcd(numbers[i], numbers[j]) == 1 ? 0 : 1);
    for(int i = 1; i <= arraySize; ++i) 
        leftSubtree[i][i] = rightSubtree[i][i] = 1;
    for(int distance = 1; distance < arraySize; ++distance)
        for(int i = 1; i <= arraySize - distance; ++i) {
            int j = i + distance;
            for(int k = i; k < j; ++k) 
                leftSubtree[i][j] |= (adjacencyMatrix[k][j] & leftSubtree[i][k] & rightSubtree[k][j - 1]);
            for(int k = i + 1; k <= j; ++k) 
                rightSubtree[i][j] |= (adjacencyMatrix[i][k] & leftSubtree[i + 1][k] & rightSubtree[k][j]);
        }
    for(int i = 1; i <= arraySize; ++i)
        if(leftSubtree[1][i] & rightSubtree[i][arraySize]) {
            cout << "Yes" << endl;
            return 0;
        }
    cout << "No" << endl;
    return 0;
}