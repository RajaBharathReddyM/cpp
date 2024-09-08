#include <iostream>
using namespace std;

struct Element {
    int row;    // Row index of the element
    int col;    // Column index of the element
    int value;  // Value of the element
};

int main() {
    int rows, cols, nonZeroCount;

    // Input matrix dimensions and number of non-zero elements
    cout << "Enter the number of rows and columns of the matrix: ";
    cin >> rows >> cols;
    cout << "Enter the number of non-zero elements: ";
    cin >> nonZeroCount;

    // Create an array to store the non-zero elements
    Element elements[nonZeroCount];

    // Input the non-zero elements
    cout << "Enter the row index, column index, and value of each non-zero element:\n";
    for (int i = 0; i < nonZeroCount; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> elements[i].row >> elements[i].col >> elements[i].value;
    }

    // Display the sparse matrix in (row, column, value) format
    cout << "\nSparse Matrix Representation:\n";
    cout << "Row\tColumn\tValue\n";
    for (int i = 0; i < nonZeroCount; i++) {
        cout << elements[i].row << "\t" << elements[i].col << "\t" << elements[i].value << endl;
    }

    // Display the full matrix including zeros
    cout << "\nFull Matrix Representation:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            bool found = false;
            for (int k = 0; k < nonZeroCount; k++) {
                if (elements[k].row == i && elements[k].col == j) {
                    cout << elements[k].value << " ";
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "0 ";
            }
        }
        cout << "\n";
    }

    return 0;
}