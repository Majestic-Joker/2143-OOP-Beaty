/*****************************************************************************
*                    
*  Author:           Joshua Beaty
*  Email:            joshua.a.beaty@gmail.com
*  Label:            P01
*  Title:            MyVector Class
*  Course:           CMPS 2143
*  Semester:         Fall 2021
* 
*  Description:
*        This program implements a class that allows a linked list to be used just like 
*        an array. It overloads the "[]" (square brackets) to simulate accessing seperate 
*        array elements, but really it traverses the list to find the specified node using
*        an index value. It also overloads the "+" and "-" signs allowing a user to "add"
*        or "push" items onto the end of the list, as well as "pop" items off the end of the 
*        array. This class is not meant to replace the STL vector library, its simply a project
*        to introduce the beginnings of creating complex / abstract data types. 
* 
*  Usage:
*        - $ ./main
*        - in the main.cpp you can implement the following functions
* 
*  Files:
*        main.cpp    : driver program 
*****************************************************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(){
        data = 0;
        next = NULL;
        prev = NULL;
    }
};

/**
 * MyVector
 * 
 * Description:
 *      MyVector class basically mimics the built in Vector class but it only works with ints
 * 
 * Public Methods:
 *      - MyVector()                            // Default constructor, initializes head and tail to NULL, and size to 0
 *      - MyVector(int* A, int sz)              // Constructs a MyVector and fills it with ints from Array A
 *      - MyVector(string FileName)             // Contructs a MyVector with ints from a file
 *      - MyVector(const MyVector &other)       // Copy constructor
 *      - void pushFront(int val)               // Creates a new node at front with data = val
 *      - void pushFront(const MyVector &V2)    // Creates enough new nodes at front of MyVector to hold data from V2
 *      - void pushRear(int val)                // Creates a new node at end with data = val
 *      - void pushRear(const MyVector &V2)     // Creates enough nodes at end of MyVector to hold data from V2
 *      - void pushAt(int loc, int val)         // Creates a new node at loc with data = val
 *      - void inOrderPush(int val)             // Traverses to node at position loc and overrides data with val
 *      - int popFront()                        // Returns the data from head and deletes head node
 *      - int popRear()                         // Returns the data from the tail and deletes tail node
 *      - int popAt(int loc)                    // Returns the data from the node at loc and deletes that node
 *      - int find(int val)                     // Returns the location of val from head
 *      - void print()                          // Prints entire contents of MyVector to console and test.out
 * 
 * Private Methods:
 *      - None
 * 
 * Usage: 
 *      MyVector V1();
 *      int arr[] = {11,25,33,47,51};
 *      MyVector V2(arr, 5);
 *      MyVector V3("input.dat");
 *      
 * 
 *      V1.pushFront(5);
 *      V1.pushFront(6);
 *      V1.pushFront(132);
 *      V1.pushFront(45);
 *      V1.print();
 *      MyVector V4(V1);
 *      
 *      cout << V2.popRear();
 *      V2.print();
 *      V3.print();
 *      V4.print();
 *      V4.pushRear(V2);
 *      V3.pushFront(V1);
 * 
 *      V1.pushAt(2,4);
 */

//easiest and worst way to only print header on test.out once
bool firstPrint = true;
class MyVector{
    private:
        ofstream outFile;
        ifstream inFile;
    public:
        Node* head;
        Node* tail;
        int size;
        /**
        * Public : MyVector
        * 
        * Description:
        *      Default constructor, initializes stuff to NULL and 0
        * 
        * Params:
        *      none
        * 
        * Returns:
        *      none
        */
        MyVector(){
            head = NULL;
            tail = NULL;
            size = 0;
        }
        /**
        * Public : MyVector
        * 
        * Description:
        *      This constructor takes an array of ints and creates enough nodes to hold the data
        * 
        * Params:
        *       int*    A
        *       int     sz
        * 
        * Returns:
        *      none
        */
        MyVector(int* A, int sz){
            head = NULL;
            tail = NULL;
            size = 0;
            for(int i = 0; i < sz; i++){
                Node* newTail = new Node();
                newTail->data = A[i];
                if(!tail)
                    head = tail = newTail;
                else{
                    tail->next = newTail;
                    newTail->prev = tail;
                    tail = newTail;
                }
                size++;
            }
        }
        MyVector(string FileName){
            inFile.open(FileName);
            head = NULL;
            tail = NULL;
            size = 0;
            int temp = 0;
            while(!inFile.eof()){
                inFile >> temp;
                pushRear(temp);
            }
        }
        MyVector(const MyVector &other){
            size = other.size;
            head = other.head;
            tail = other.tail;
        }
        void pushFront(int val){
            Node* newHead = new Node();
            newHead->data = val;
            if(!head)
                head = tail = newHead;
            else{
                head->prev = newHead;
                newHead->next = head;
                head = newHead;
            }
            size++;
        }
        void pushFront(const MyVector &V2){
            Node* trav = V2.tail;
            while(trav){
                pushFront(trav->data);
                trav = trav->prev;
            }
        }
        void pushRear(int val){
            Node* newTail = new Node();
            newTail->data = val;
            if(!tail)
                head = tail = newTail;
            else{
                tail->next = newTail;
                newTail->prev = tail;
                tail = newTail;
            }
            size++;
        }
        void pushRear(const MyVector &V2){
            Node* trav = V2.head;
            while(trav){
                pushRear(trav->data);
                trav = trav->next;
            } 
        }
        void pushAt(int loc, int val){
            Node* trav = head;
            for(int i = 0; i < loc; i++)
                trav = trav->next;
            trav->data = val;
        }
        void inOrderPush(int val){
            Node* newNode = new Node();
            newNode->data = val;
            if(!head){
                head = tail = newNode;
            }
            else{
                Node* trav = head;
                while(trav){
                    if(val > trav->data)
                        trav = trav->next;
                    else{
                        newNode->prev = trav->prev;
                        newNode->next = trav;
                        trav->prev->next = newNode;
                        break;
                    }
                }
            }
            size++;
        }
        int popFront(){
            Node* temp = head;
            head = head->next;
            head->prev = NULL;
            return temp->data;
        }
        int popRear(){
            Node* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            return temp->data;
        }
        int popAt(int loc){
            Node* trav;
            if(loc < (size/2)){
                trav = head;
                for(int i = 0; i < loc; i++){
                    trav = trav->next;
                }
            }
            else{
                trav = tail;
                for(int i = 0; i < (size-loc); i++){
                    trav = trav->prev;
                }
            }
            trav->prev->next = trav->next;
            trav->next->prev = trav->prev;

            int temp = trav->data;
            delete trav;
            return temp;
        }
        int find(int val){
            int count = 0;
            Node* trav = head;
            while(trav){
                if(val != trav->data){
                    trav = trav->next;
                }
                else{
                    break;
                }
                count++;
            }
            if(count == (size-1))
                count = -1;
            return count;
        }
        void print(){
            
            Node* trav = head;
            if(firstPrint){
                outFile.open("test.out");
                outFile << "Joshua Beaty\n09/10/2021\nFall 2143\n\n";
                firstPrint = false;
            }
            else
                outFile.open("test.out", std::ios_base::app);
            cout << '[';
            outFile << '[';
            while(trav){
                cout << trav->data;
                outFile << trav->data;
                if(trav->next){
                    cout << ", ";
                    outFile << ", ";
                }

                trav = trav->next;
            }
            cout << "]\n";
            outFile << "]\n";
            outFile.close();
        }

        //friends and overloads << operator to print everything in myVector to the console
        friend ostream& operator<<(ostream& os, const MyVector& rhs) {
            Node* temp = rhs.head;

            while (temp) {
                os << temp->data;
                if (temp->next) {
                    os << "->";
                }
                temp = temp->next;
            }
            return os;
        }

        //friends and overloads << operator to print to the file
        friend ofstream& operator<<(ofstream& ofs, const MyVector& rhs) {
            Node* temp = rhs.head;

            while (temp) {
                ofs << temp->data;
                if (temp->next) {
                    ofs << "->";
                }
                temp = temp->next;
            }
            return ofs;
        }
        //overloads square brackets to return value at specified index.
        int operator[](int index) {
            Node* trav;

            if(index < (size/2)){
                trav = head;
                for(int i = 0; i < index; i++){
                    trav = trav->next;
                }
            }
            else{
                trav = tail;
                for(int i = 0; i < (size-index); i++){
                    trav = trav->prev;
                }
            }

            int temp = trav->data;
            delete trav;
            return temp;
        }
};

int main(){
int a1[] = { 1, 2, 3, 4, 5 };
int a2[] = { 10, 20, 30 };

//have to include size of arrays in the call to MyVector
MyVector v1(a1, 5);
MyVector v2(a2, 4);

ofstream fout;
fout.open("output.txt");

cout << v1[2] << endl;
// writes out 3

v1[4] = 9;
// v1 now = [1,2,3,4,9]

cout << v1 << endl;
// writes out [1,2,3,4,9] to console.

fout << v1 << endl;
// writes out [1,2,3,4,9] to your output file.

Vector v3 = v1 + v2;
cout << v3 << endl;
// writes out [11,22,33,4,9] to console.

v3 = v1 - v2;
cout << v3 << endl;
// writes out [-9,-18,-27,4,9] to console.

v3 = v2 - v1;
cout << v3 << endl;
// writes out [9,18,27,4,9] to console.

v3 = v2 * v1;
cout << v3 << endl;
// writes out [10,40,90,4,9] to console.

v3 = v1 * v2;
cout << v3 << endl;
// writes out [10,40,90,4,9] to console.

v3 = v1 / v2;
cout << v3 << endl;
// writes out [0,0,0,4,9] to console.

v3 = v2 / v1;
cout << v3 << endl;
// writes out [10,10,10,4,9] to console.

cout << (v2 == v1) << endl;
// writes 0 to console (false) .

MyVector v4 = v1;
cout << (v4 == v1) << endl;
// writes 1 to console (true) .
}