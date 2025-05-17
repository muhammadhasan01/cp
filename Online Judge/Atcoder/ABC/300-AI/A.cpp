#include <iostream>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    
    int sum = A + B;
    for (int i = 1; i <= N; i++) {
        int choice;
        cin >> choice;
        if (choice == sum) {
            cout << i;
            break;
        }
    }
    
    return 0;
}
