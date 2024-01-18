#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
  Converts an integer to its binary representation
  stored in an integer vector.
  Input: integer to convert
  Output: vector of binary
*/
vector<int> intToBin(int input);

/*
  Compares the size of the binary list vectors
  and prepends padding zeros accordingly.
*/
void adjustSize();

/*
  Outputs the two binary representations to the screen.
*/
void printLists();

/*
  Prints the number of discrepences between each position of the
  binary lists.
  Inputs: two vectors of int type of which to be compared
*/
void printHammingDistance(vector<int> list1, vector<int> list2);

//data storage for binary
vector<int> argList1; //for first cmd line arg
vector<int> argList2; //for second cmd line arg

//Cmd line arg 1 string
string argStr1;
//Cmd line arg 2 string
string argStr2;

/*
  Takes in two command line arguments and outputs their
  binary repreentation. The binary strings are altered
  to be the same length.The Hamming distance between the
  two binary representations is then outputted.
  Inputs: command line arguments.
  Outputs: integer representing success.
*/
int main(int argc, char*argv[]) {

    //ensure right amount of cmd line args
    if (argc != 3) {
        string message = "Must have exactly 3 command line arguments";
        cout << message << endl;
        return 1;
    }

    //assigning string cmd ln args
    argStr1 = argv[1];
    argStr2 = argv[2];

    //assigning string cmd ln args to integers
    int argInt1 = stoi(argStr1);
    int argInt2 = stoi(argStr2);

    //Data structer to hold binary represenation
    argList1 = intToBin(argInt1);
    argList2 = intToBin(argInt2);

    //add padding zeros
    adjustSize();

    //Print Lists
    printLists();

    //Print hamming distance
    printHammingDistance(argList1,argList2);

}

void printHammingDistance(vector<int> list1, vector<int> list2) {

    int dist = 0; //hamming distance
    for (int i = 0 ; i < list1.size() ; i++) {
        if (list1[i] != list2[i]) { //check if same
            dist ++;
        } //if
    } //for
    //output
    cout << dist << " is the Hamming distance between the bit strings" << endl;
} //printHammingDistance


void adjustSize() {

    //number of 0s to add
    int diff = argList2.size() - argList1.size();

    //list 2 is bigger
    if (diff > 0) {
        for (int i = 0 ; i < diff ; i++) {
            argList1.insert(argList1.begin(), 0);
        }
        //list1 is bigger
    } else {
        diff *= -1; //make positive
        for (int i = 0 ; i < diff ; i++) {
            argList2.insert(argList2.begin(), 0);
        }
    }
}

void printLists() {
    //printing list 1
    for (int i = 0 ; i < argList1.size() ; i++) {
        cout << argList1[i];
    }
    cout << " is the bit string of " << argStr1 << endl;
    //printing list 2
    for (int i = 0 ; i < argList2.size() ; i++) {
        cout << argList2[i];
    }
    cout << " is the bit string of " << argStr2 << endl;
}

vector<int> intToBin(int input) {

    int quotient = input;
    int remainder = 0;

    vector<int> output;

    while(quotient > 0){
        remainder = quotient % 2;
        quotient = quotient / 2;
        //insert at beggining to invert order
        output.insert(output.begin(),remainder);
    }

    if(input == 0){
        output.push_back(0);
    }


    return output;
}
