#include <iostream>
using namespace std;

// Node class for each element in the sparse matrix
class Node {
public:
    int row;        // Row index of the element
    int col;        // Column index of the element
    int value;      // Value of the element
    Node* next;     // Pointer to the next node

    // Constructor to initialize a node
    Node(int r, int c, int val) {
        row = r;
        col = c;
        value = val;
        next = nullptr;
    }
};

// SparseMatrix class to manage the linked list of nodes
class SparseMatrix {
private:
    Node* head; // Head pointer of the linked list
    int rows;   // Number of rows in the matrix
    int cols;   // Number of columns in the matrix

public:
    // Constructor to initialize the matrix with given dimensions
    SparseMatrix(int r, int c) {
        head = nullptr;
        rows = r;
        cols = c;
    }

    // Function to insert a new non-zero element into the matrix
    void insert(int row, int col, int value) {
        if (row >= rows || col >= cols || value == 0) {
            cout << "Invalid insertion!" << endl;
            return;
        }
        Node* newNode = new Node(row, col, value);
        if (!head) {
            head = newNode; // If list is empty, new node becomes the head
        } else {
            Node* temp = head;
            // Traverse to the end of the list
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode; // Add the new node at the end
        }
    }

    // Function to display the sparse matrix elements in list format
    void displayList() {
        Node* temp = head;
        while (temp) {
            cout << "Row: " << temp->row << ", Col: " << temp->col << ", Value: " << temp->value << endl;
            temp = temp->next;
        }
    }

    // Function to display the sparse matrix in grid format
    void displayGrid() {
        Node* temp = head;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (temp && temp->row == i && temp->col == j) {
                    cout << temp->value << " ";
                    temp = temp->next;
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a new Sparse Matrix with dimensions 4x5
    SparseMatrix sparseMatrix(4, 5);

    // Insert some non-zero elements
    sparseMatrix.insert(0, 4, 5);
    sparseMatrix.insert(1, 4, 6);
    sparseMatrix.insert(3, 2, 3);

    // Display the matrix in list format
    cout << "List Format Display Output:" << endl;
    sparseMatrix.displayList();

    // Display the matrix in grid format
    cout << "\nDisplay Output:" << endl;
    sparseMatrix.displayGrid();

    return 0;
}