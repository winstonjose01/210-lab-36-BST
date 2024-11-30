// COMSC210 | Lab36 - Records BST | Winston Jose
// IDE Used: Visual Studio code
// https://github.com/winstonjose01/210-lab-36-BST

#include <fstream>
//#include "IntBinaryTree.h"
#include "StringBinaryTree.h"
#include "StringBinaryTree.cpp"
#include <iostream>
#include <cstdlib>
#include <thread>
using namespace std;

int TEST_DELAYTIME = 4; // Delay time for testing functions
void testing(StringBinaryTree &);   // Function prototype for testing all BST functions

int main() {

    string line;    // Variable to hold each line from the input file
    int numline = 0;    // Variable to count the number of lines read from the file
    ifstream fin("codes.txt");  // Open the file 'codes.txt' for reading
    StringBinaryTree codes; // Create an instance of the StringBinaryTree class
    
    // Check if the file was opened successfully
    if (!fin.is_open()){
        cout << "Error opening file. Aborting!";
        return(1);
    }
    else{
        // Read each line from the file and insert it into the binary search tree
        while (getline(fin,line)){
            codes.insertNode(line);
        }
    }
    // Reset the file stream for further reading if necessary
    fin.clear();
    fin.seekg(0);
    int choice = 0; // Variable to store the user's menu choice
    cout << "The binary search tree has been populated." << endl;

    // Main menu loop that provides options to interact with the BST
    while (choice < 9){
        string record, newrecord;   // Variables to store user inputs for records
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
        cin >> choice;  // Get the user's menu choice

        switch (choice){
            case 1:  // Add a new record to the tree
                cout << "Enter the new record to add: ";
                cin >> record;
                codes.insertNode(record);
                break;
            case 2: // Delete an existing record from the tree
                cout << "Enter the record to delete: ";
                cin >> record;
                codes.remove(record);
                break;
            case 3: // Search for a specific record
                cout << "Enter the record you are searching for: ";
                cin >> record;
                if (codes.searchNode(record))
                    cout << "Record found: " << record << endl;
                else
                    cout << "Record not found. " << endl;
                break;
            case 4: // Modify an existing record
                cout << "Enter the record you want to modify: ";
                cin >> record;
                cout << "\nEnter the record value: ";
                cin >> newrecord;
                codes.modifyNode(record, newrecord);
                break;
            case 5: // Display the tree in InOrder traversal
                cout << "Display tree InOrder";
                codes.displayInOrder();
                break;
            case 6: // Display the tree in PreOrder traversal
                cout << "Display tree PreOrder";
                codes.displayPreOrder();
                break;
            case 7: // Display the tree in PostOrder traversal
                cout << "Display tree PostOrder";
                codes.displayPostOrder();
                break;
            case 8: // Exit the program
                cout << "----TESTING ALL BST FUNCTIONS----\n ";
                testing(codes);
                break;
            case 9: // Exit the program
                cout << "Exiting the program. ";
                return 0;
            
        }
    }
    return 0;
}

// Function to test all the BST operations
// arguments: a StringBinaryTree object
// returns: no returns
void testing(StringBinaryTree &temp){
    
    // Testing to add new records
    cout << "\n--------- Inserting new records ----------";
    std::this_thread::sleep_for(std::chrono::seconds(TEST_DELAYTIME));
    cout << "\nInserting 'winston'";
    temp.insertNode ("winston");
    cout << "\nInserting 'jose'";
    temp.insertNode ("jose");
    cout << endl;

    // Testing to search for the newly added records
    cout << "\n--------- Searching for the added records ----------";
    std::this_thread::sleep_for(std::chrono::seconds(TEST_DELAYTIME));
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

    // Testing to delete the newly added records
    cout << "\n--------- Deleting the added records ----------";
    std::this_thread::sleep_for(std::chrono::seconds(TEST_DELAYTIME));
    cout << "\nDeleting 'winston'";
    temp.remove("winston");
    cout << "\nDeleting 'jose'";
    temp.remove ("jose");
    cout << endl;

    // Testing to search for the deleted records
    cout << "\n--------- Searching for deleted record ----------";
    std::this_thread::sleep_for(std::chrono::seconds(TEST_DELAYTIME));
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

    // Testing to replace back the deleted records
    cout << "\n--------- Putting back the previous records ----------";
    std::this_thread::sleep_for(std::chrono::seconds(TEST_DELAYTIME));
    cout << "\nInserting 'winston'";
    temp.insertNode ("winston");
    cout << "\nInserting 'jose'";
    temp.insertNode ("jose");
    cout << endl;

    // Testing to modify the replaced records
    cout << "\n--------- Modify Record ----------";
    std::this_thread::sleep_for(std::chrono::seconds(TEST_DELAYTIME));
    cout << "\nModifying 'winston' with 'james' --> ";
    if (temp.modifyNode("winston","james"))
    cout << "\nModifying 'jose' with 'albert' --> ";
    if (temp.modifyNode("jose","albert"))
    cout << endl;

    // Testing to search for the newly added/modified record
    cout << "\n--------- Searching tree for modified record ----------";
    std::this_thread::sleep_for(std::chrono::seconds(TEST_DELAYTIME));
    cout << "\nSearching 'james'";
    if (temp.searchNode("james")) 
        cout <<"\n\t-> Record 'james' FOUND";
    else 
        cout <<"\n\t-> Record 'james' NOT FOUND";
    cout << "\nSearching 'albert'";
    if(temp.searchNode("albert"))
        cout <<"\n\t-> Record 'albert' FOUND";
    else 
        cout <<"\n\t-> Record 'albert' NOT FOUND";

    // Display the tree InOrder
    cout << "\n--------- Display Record InOrder ----------";
    std::this_thread::sleep_for(std::chrono::seconds(TEST_DELAYTIME));
    temp.displayInOrder();
    cout << endl;

    // Display the tree PreOrder
    cout << "\n--------- Display Record PreOrder ----------";
    std::this_thread::sleep_for(std::chrono::seconds(TEST_DELAYTIME));
    temp.displayPreOrder();
    cout << endl;

    // Display the tree PostOrder
    cout << "\n--------- Display Record PostOrder ----------";
    std::this_thread::sleep_for(std::chrono::seconds(TEST_DELAYTIME));
    temp.displayPostOrder();
    
}
