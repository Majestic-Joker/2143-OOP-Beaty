/*
*   P03A Rock, Paper, Scissors, Lizard, Spock
*   Joshua Beaty, Alexander Ryan, Aodhan Shaw, Blake Guana
*   2143
*   10/10/2021
*/
#include <iostream>
#include <fstream>
#include "Hands.h"
#include "time.h"

ofstream fout;

//prototype for compare
void compare(Player, Player);

int main()
{
    fout.open("test.out");
    
    srand(time(NULL));
    Hands h;
    h.heading();
    //print heading to file
    fout << "Welcome to Rock Paper Scissors Lizard Spock!" << endl;
    fout << "--------------------------------------------" << endl;

    //looping 30 times to exceed assignment requirements
    for (int i = 0; i < 30; i++)
    {
        Player p1;
        Player p2;
        cout << endl;
        cout << "    " << "Player 1:" << "             " << "Player 2: " << endl;
        cout << "      " << p1.weapon1 << "                   " << p2.weapon1 << endl;
        cout << "      " << p1.weapon2 << "                   " << p2.weapon2 << endl;
        fout << endl;
        fout << "    " << "Player 1:" << "             " << "Player 2: " << endl;
        fout << "      " << p1.weapon1 << "                   " << p2.weapon1 << endl;
        fout << "      " << p1.weapon2 << "                   " << p2.weapon2 << endl;

        compare(p1, p2);
    }

    fout.close();
    return 0;
}

/*
*   This function takes in 2 players and prints out the result
*/
void compare(Player p1, Player p2)
{
    //if weapons aren't equal check the comparisons
    if (p1.weapon1 != p2.weapon1)
    {
        //weapons aren't equal, compare p1 to p2, if p1 wins at all, print out the output.
        if (p1 > p2)
        {
            cout << "Player 1's " << p1.weapon1 << " or " << p1.weapon2 << " beats Player 2's " << p2.weapon1 << " or " << p2.weapon2 << '\n';
            fout << "Player 1's " << p1.weapon1 << " or " << p1.weapon2 << " beats Player 2's " << p2.weapon1 << " or " << p2.weapon2 << '\n';
        }
        else if (p2 > p1)
        {
            cout << "Player 2's " << p2.weapon1 << " or " << p2.weapon2 << " beats Player 1's " << p1.weapon1 << " or " << p1.weapon2 << '\n';
            fout << "Player 2's " << p2.weapon1 << " or " << p2.weapon2 << " beats Player 1's " << p1.weapon1 << " or " << p1.weapon2 << '\n';
        }
        else
            cout << "error, weird case found\n";
    }
    else
    {
        //they're equal
        if (p1.weapon2 != p2.weapon2)
        {
            //2nd weapons not equal declare winner
            if (p1 > p2)
            {
                cout << "Player 1's " << p1.weapon2 << " beats Player 2's " << p2.weapon2 << '\n';
                fout << "Player 1's " << p1.weapon2 << " beats Player 2's " << p2.weapon2 << '\n';
            }
            else if (p2 > p1)
            {
                cout << "Player 2's " << p2.weapon2 << " beats Player 1's " << p1.weapon2 << '\n';
                fout << "Player 2's " << p2.weapon2 << " beats Player 1's " << p1.weapon2 << '\n';
            }
            else
                cout << "error, weird case found\n";
        }
        else
        {
            //they're equal again
            cout << "It's a tie!\n";
            fout << "It's a tie!\n";
        }
    }
}
