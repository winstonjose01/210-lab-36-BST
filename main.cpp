#include <fstream>
//#include "IntBinaryTree.h"
#include "StringBinaryTree.h"
#include "StringBinaryTree.cpp"
#include <iostream>
#include <cstdlib>
#include <thread>
using namespace std;

int TEST_DELAYTIME = 4;
void testing(StringBinaryTree &);

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
    while (choice < 9){
        string record, newrecord;
        cout << endl;
        cout << "Choose an option:" << endl;
        cout << "[1] Add a record " << endl;
        cout << "[2] Delete a record " << endl;
        cout << "[3] Search for a record " << endl;
        cout << "[4] Modify a record" << endl;
        cout << "[5] Display the tree InOrder" << endl;
        cout << "[6] Display the tree PreOrder " << endl;
        cout << "[7] Display the tree PostOrder" << endl;
        cout << "[8] Test all BST functions" << endl;
        cout << "[9] Quit" << endl;
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
                if (codes.searchNode(record))
                    cout << "Record found: " << record << endl;
                else
                    cout << "Record not found. " << endl;
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
                codes.displayPostOrder();
                break;
            case 8: 
                cout << "----TESTING ALL BST FUNCTIONS----\n ";
                testing(codes);
                break;
            case 9: 
                cout << "Exiting the program. ";
                return 0;
            
        }
    }
    return 0;
}

void testing(StringBinaryTree &temp){
    
    std::this_thread::sleep_for(std::chrono::seconds(TEST_DELAYTIME));
    cout << "\n--------- Inserting new records ----------";
    cout << "\nInserting 'winston'";
    temp.insertNode ("winston");
    cout << "\nInserting 'jose'";
    temp.insertNode ("jose");
    cout << endl;

    std::this_thread::sleep_for(std::chrono::seconds(TEST_DELAYTIME));
    cout << "\n--------- Searching for the added records ----------";
    cout << "\nSearching 'winston'";
    if (temp.searchNode("winston")) 
        cout <<"\n\t-> Record 'winston' FOUND";
    else 
        cout <<"\n\t-> Record 'winston' NOT FOUND";

    cout << "\nSearching 'jose'";
    if(temp.searchNode("jose"))
        cout <<"\n\t-> Record 'jose' FOUND";
    else 
        cout <<"\n\t-> Record 'jose' NOT FOUND";
    cout << endl;

    std::this_thread::sleep_for(std::chrono::seconds(TEST_DELAYTIME));
    cout << "\n--------- Deleting the added records ----------";
    cout << "\nDeleting 'winston'";
    temp.remove("winston");
    cout << "\nDeleting 'jose'";
    temp.remove ("jose");
    cout << endl;

    std::this_thread::sleep_for(std::chrono::seconds(TEST_DELAYTIME));
    cout << "\n--------- Searching for deleted record ----------";
    cout << "\nSearching 'winston'";
    if (temp.searchNode("winston")) 
        cout <<"\n\t-> Record 'winston' FOUND";
    else 
        cout <<"\n\t-> Record 'winston' NOT FOUND";
    cout << "\nSearching 'jose'";
    if(temp.searchNode("jose"))
        cout <<"\n\t-> Record 'jose' FOUND";
    else 
        cout <<"\n\t-> Record 'jose' NOT FOUND";
    cout << endl;

    std::this_thread::sleep_for(std::chrono::seconds(TEST_DELAYTIME));
    cout << "\n--------- Putting back the previous records ----------";
    cout << "\nInserting 'winston'";
    temp.insertNode ("winston");
    cout << "\nInserting 'jose'";
    temp.insertNode ("jose");
    cout << endl;

    std::this_thread::sleep_for(std::chrono::seconds(TEST_DELAYTIME));
    cout << "\n--------- Modify Record ----------";
    cout << "\nModifying 'winston' with 'james' --> ";
    if (temp.modifyNode("winston","james"))
    cout << "\nModifying 'jose' with 'albert' --> ";
    if (temp.modifyNode("jose","albert"))
    cout << endl;

    std::this_thread::sleep_for(std::chrono::seconds(TEST_DELAYTIME));
    cout << "\n--------- Searching tree for modified record ----------";
    cout << "\nSearching 'winston'";
    if (temp.searchNode("james")) 
        cout <<"\n\t-> Record 'james' FOUND";
    else 
        cout <<"\n\t-> Record 'james' NOT FOUND";
    cout << "\nSearching 'albert'";
    if(temp.searchNode("jose"))
        cout <<"\n\t-> Record 'albert' FOUND";
    else 
        cout <<"\n\t-> Record 'albert' NOT FOUND";

    cout << "\n--------- Display Record InOrder ----------";
    std::this_thread::sleep_for(std::chrono::seconds(TEST_DELAYTIME));
    temp.displayInOrder();
    cout << endl;

    cout << "\n--------- Display Record PreOrder ----------";
    std::this_thread::sleep_for(std::chrono::seconds(TEST_DELAYTIME));
    temp.displayPreOrder();
    cout << endl;

    cout << "\n--------- Display Record PostOrder ----------";
    std::this_thread::sleep_for(std::chrono::seconds(TEST_DELAYTIME));
    temp.displayPostOrder();
    
}
