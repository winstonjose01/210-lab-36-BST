#include <fstream>
//#include "IntBinaryTree.h"
#include "StringBinaryTree.h"
#include "StringBinaryTree.cpp"
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    srand(time(0));
    
    string line;
    int numline = 0;
    ifstream fin("codes.txt");
    StringBinaryTree codes;
    
    if (!fin.is_open()){
        cout << "Error opening file. Aborting!";
        return(1);
    }
    else{
        while (getline(fin,line)){
            codes.insertNode(line);
        }
    }
    fin.clear();
    fin.seekg(0);
    int choice = 0;
    cout << "The binary search tree has been populated." << endl;
    while (choice < 7){
        string record, newrecord;
        cout << endl;
        cout << "Choose an option:" << endl;
        cout << "[1] Add a record " << endl;
        cout << "[2] Delete a record " << endl;
        cout << "[3] Search for a record " << endl;
        cout << "[4] Modify a record" << endl;
        cout << "[5] Quit" << endl;
        cout << " Option ---> ";
        cin >> choice;
        switch (choice){
            case 1: 
                cout << "Enter the new record to add: ";
                cin >> record;
                codes.insertNode(record);
                break;
            case 2:
                cout << "Enter the record to delete: ";
                cin >> record;
                codes.remove(record);
                break;
            case 3:
                cout << "Enter the record you are searching for: ";
                cin >> record;
                codes.searchNode(record);
                break;
            case 4:
                cout << "Enter the record you want to modify: ";
                cin >> record;
                cout << "\nEnter the record value: ";
                cin >> newrecord;
                codes.modifyNode(record, newrecord);
                break;
            case 5:
                cout << "Display tree InOrder";
                codes.displayInOrder();
                break;
            case 6:
                cout << "Display tree PreOrder";
                codes.displayPreOrder();
                break;
            case 7:
                cout << "Display tree PostOrder";
                codes.displayPreOrder();
                break;
            case 8: 
                exit(1);
                break;
            
        }
    }


    return 0;
}