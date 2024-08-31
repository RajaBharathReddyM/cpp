#include <iostream>
using namespace std;

void targetSum(int nums[], int size, int target) {
    // Nested loop to check each pair of elements
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (nums[i] + nums[j] == target) {
                std::cout << "[" << i << ", " << j << "]" << std::endl;
                return; // Exit after finding the first pair
            }
        }
    }
    std::cout << "No solution found." << std::endl; // If no pairs are found
}

int main() {
    // Step 1:  we need to knwo how many elements user want to enter
    // to store that value we need to create a variable
    int n;

    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    // Step 2 : if we know how many elements user is entering then only we can declare an array with the size given by the user
    int nums[n];

    std::cout << "Enter the elements of the array:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i]; // Input elements of the array
    }

    // step 3:  Get the taget value input from user 
    int target;
    std::cout << "Enter the value of the target element: ";
    std::cin >> target;

    // step 4: call the function and pass array, size , target value
    targetSum(nums, n, target);

    return 0;
}