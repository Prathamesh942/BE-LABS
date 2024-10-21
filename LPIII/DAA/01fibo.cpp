#include <iostream>
using namespace std;

pair<int, int> fibonacci(int n) {
    if (n <= 0) {
        return make_pair(-1, 0);  
    }
    
    int a = 0, b = 1;
    int step_count = 0; 


    if (n == 1) {
        return make_pair(a, step_count); 
    }

    for (int i = 2; i <= n; i++) {
        step_count++; 
        int temp = b;
        b = a + b;
        a = temp;
    }

    return make_pair(a, step_count);
}

int main() {
    int n;
    cout << "Enter a number to calculate the nth Fibonacci: ";
    cin >> n;

    pair<int, int> result = fibonacci(n);
    
    if (result.first == -1) {
        cout << "Invalid input. Please enter a positive integer." << endl;
    } else {
        cout << "The " << n << "th Fibonacci number is: " << result.first << endl;
        cout << "Total number of steps: " << result.second << endl;
    }
    return 0;
}
