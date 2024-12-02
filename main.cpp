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

        switch (choice) {
            case 1:
                if (getline(input, line)) {
                    binaryTree.insertNode(line);
                    cout << "Added " << line << "to the tree\n";
                }
                else {
                    cout << "All lines already added\n";
                }
                break;
            case 2:
                cout << "Enter the record to delete: ";
                getline(cin, line);
                binaryTree.remove(line);
                cout << "Deleted " << line <<  " from the tree\n";
                break;
            case 3:
                cout << "Enter the record to search for: ";
                getline(cin, line);
                if (binaryTree.searchNode(line)) {
                    cout << "Record exists in tree\n";
                }



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