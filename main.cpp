#include <fstream>
#include "IntBinaryTree.h"
#include "StringBinaryTree.h"
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
            numline++;
        }
    }
    fin.clear();
    fin.seekg(0);

    return 0;
}