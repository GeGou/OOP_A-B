#include <iostream>
#include <cstring>
#include "classes.h"
using namespace std;

int main (int argc, char* argv[])
{
    if (argc == 5)
    {
        srand(time(NULL));      // the start of the generator
        int k = atoi(argv[1]);
        int m = atoi(argv[2]);
        int n = atoi(argv[3]);
        int l = atoi(argv[4]);
        int entered;
        int not_entered = 0;

        Bank bank(k, l);
        // entering and serving entered customers (b bullet)
        for (int i = 0 ; i < m ; i++)
        {
            entered = 0;
            for (int y = 0 ; y < n ; y++)
            {
                if (bank.enter() == true)
                {
                    entered++;
                }
                else
                {
                    not_entered++;
                }
            }
            for (int x = 0 ; x < entered ; x++)
            {
                bank.serve();
            }
            cout << endl;
        }

        // enter and serving the last customers who didn't enter at first (c bullet)
        int last_entered = 0;
        for (int i = 0 ; i < not_entered ; i++)
        {
            if (bank.enter() == true)
            {
                last_entered++;
            }
        }
        for (int i = 0 ; i < last_entered ; i++)
        {
            bank.serve();
        }
    }
    else
    {
        cout << "Wrong given arguments." << endl;
    }
    return 0;
}