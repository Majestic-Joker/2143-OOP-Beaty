/*****************************************************************************
*
* Author: Terry Griffin
* Email: terry.griffin@msutexas.edu
* Label: A04
* Title: Circular Array Queue Class
* Course: CMPS 2143
* Semester: Fall 2021
*
* Description:
*       This program implements a class that manipulates the standard integer array to act like a circularly linked queue.
*
* Usage:
*       Skim through the code and be happy about the commments.
*
* Files:
*       main.cpp    : driver of program
*
**************************************************************************** */

#include <iostream>

using namespace std;

/**
 * CircularArrayQue
 * 
 * Description:
 *      This class manipulates the standard integer array to act like a circularly linked queue.
 * 
 * Public Methods:
 *                  CircularArrayQue()
 *                  CircularArrayQue(int size)
 *      void        Push(int item)
 *      int         Pop()
 *      ostream     &operator<<(ostream &os, const CircularArrayQue &other)
 * 
 * Private Methods:
 *      int         *Container
 *      int         Front
 *      int         Rear
 *      int         QueSize
 *      int         CurrentSize
 *      void        init(int size = 0)
 *      bool        Full()
 * 
 * Usage: 
 * 
 *      CircularArrayQue c()                //creates a Circular Array Queue of size 10
 *      CircularArrayQue a(n)               //creates a Circular Array Queue of size n
 * 
 *      c.Push(f)                           //if queue isn't full, pushes int f into the rear of CircularArrayQue c
 *      c.Pop ()                            //removes the integer from the front of the CircularArrayQue c
 *      
 *      cout << c;                          //prints out every integer in CircularArrayQue c from front to rear
 */

class CircularArrayQue {
private:
    int *Container;
    int Front;
    int Rear;
    int QueSize;                            // items in the queue
    int CurrentSize;

     /**
     * Private : init
     * 
     * Description:
     *      Initializes member variables for the class
     * 
     * Params:
     *      int     : queue size, defaults to 0
     * 
     * Returns:
     *      No explicit returns, sets QueSize to the size parameter and Front/Rear/CurrentSize to 0;
     */
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }

     /**
     * Private : Full
     * 
     * Description:
     *      Compares CurrentSize to QueSize and returns the result as a boolean.
     * 
     * Params:
     *      No parameters
     * 
     * Returns:
     *      returns a boolean(true/false) of CurrentSize equal to QueSize
     */
    bool Full() {
        return CurrentSize == QueSize;
    }

public:
    /**
     * Public : CircularArrayQue
     * 
     * Description:
     *      Default constructor for the class CircularArrayQue, initializes to a default size of 10
     * 
     * Params:
     *      No parameters
     * 
     * Returns:
     *      No explicit returns, sets the queue size to 10 and runs the init function with a param of 10
     */
    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }
    
    /**
     * Public : CircularArrayQue
     * 
     * Description:
     *      Overloaded constructor for the class CircularArrayQue, initializes the queue to param size
     * 
     * Params:
     *      int     : queue size
     * 
     * Returns:
     *      No explicit returns, sets the queue size to param size and runs the init function with a param of size
     */
    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }

    /**
     * Public : Push
     * 
     * Description:
     *      Checks to make sure the queue isn't full and adds param item to the end of the queue
     * 
     * Params:
     *      int             : item to add to the queue
     * 
     * Returns:
     *      No explicit returns, adds item or prints message "FULL!!!!"
     */
    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {
            cout << "FULL!!!!" << endl;
        }
    }

    /**
     * Public : Pop
     * 
     * Description:
     *      Removes the int at the front of the queue and returns it
     * 
     * Params:
     *      No parameters
     * 
     * Returns:
     *      Returns the temp variable which contains the removed integer from the front of the queue.
     */
    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

/**
 * Public : &operator<<
 * 
 * Description:
 *      prints entire contents of queue from front to back to the command line
 * 
 * Params:
 *      ostream             : &os references outstream component used to output to terminal
 *      CircularArrayQue    : &other references the queue this function is attached to.
 * 
 * Returns:
 *      No explicit returns, prints content to the terminal
 */
ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {
    CircularArrayQue C1(5);

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}