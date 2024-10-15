
long long powerMod(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    
    while (exp > 0) {
        if (exp % 2 == 1) {  // If exponent is odd, multiply base with the result
            result = (result * base) % mod;
        }
        exp = exp >> 1;  // Divide the exponent by 2
        base = (base * base) % mod;  // Square the base
    }
    
    return result;
}


#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Define the lambda function
    auto helperFunction = [](vector<int>& nums) -> int {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        return sum;
    };

    // Example usage of the lambda function
    vector<int> numbers = {1, 2, 3, 4, 5};
    int result = helperFunction(numbers);  // Pass the vector to the lambda
    cout << "The sum of the numbers is: " << result << endl;

    return 0;
}
