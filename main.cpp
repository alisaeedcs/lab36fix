//comsc 210 | ali saeed | lab36
//trying to fix now

#include <iostream>
#include <fstream>
#include "IntBinaryTree.h"
using namespace std;

void outputMenu();

int main() {
    IntBinaryTree binaryTree;

    ifstream input("codes.txt");
    string line;

    int choice;

    do {
        outputMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        cout << endl;
        switch (choice) {
            case 1:
                if (getline(input, line)) {
                    binaryTree.insertNode(line);
                    cout << "Added " << line << " to the tree\n";
                }
                else {
                    cout << "All lines already added\n";
                }
                cout << endl;
                break;
            case 2:
                cout << "Enter the record to delete: ";
                getline(cin, line);
                binaryTree.remove(line);
                cout << "Deleted " << line <<  " from the tree\n";
                cout << endl;

                break;
            case 3:
                cout << "Enter the record to search for: ";
                getline(cin, line);
                if (binaryTree.searchNode(line)) {
                    cout << "Record exists in tree\n";
                }
                else {
                    cout << "Record not found\n";
                }
                cout << endl;
                break;
            case 4:
                cout << "Displaying all records in order:\n";
                binaryTree.displayInOrder();
                cout << endl;
                break;
            case 5:
                cout << "Exiting the program\n";
                cout << endl;
                break;
            default:
                cout << "Invalid choice, try again\n";
        }
    } while (choice != 5);

    input.close();

    return 0;
}

void outputMenu() {
    cout << "BST Menu" << endl;
    cout << "1. Add record\n";
    cout << "2. Delete record\n";
    cout << "3. Search for record\n";
    cout << "4. Output records\n";
    cout << "5. Exit\n";
}