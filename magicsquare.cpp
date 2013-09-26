#include "magicsquare.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
using namespace std;

MagicSquare::MagicSquare()
{
    square.resize(SIZE_SQUARE);

    for(int i = 0; i < SIZE_SQUARE; i++)
        square[i].resize(SIZE_SQUARE);

    sizeSquare = SIZE_SQUARE;

    checkVector.resize(sizeSquare * sizeSquare);
    randomLoadSquare();
}

MagicSquare::MagicSquare(int mySizeSquare)
{
    square.resize(mySizeSquare);

    for(int i = 0; i < mySizeSquare; i++)
        square[i].resize(mySizeSquare);

    sizeSquare = mySizeSquare;
    checkVector.resize(sizeSquare * sizeSquare);
    randomLoadSquare();
}


void MagicSquare::printSquare()
{
    for(int i = 0 ; i < sizeSquare; i++)
    {
        for(int j = 0 ; j < sizeSquare; j++)
        {
            cout << square[i][j] << "  ";
        }

        cout << endl;
    }

}

void MagicSquare::randomLoadSquare()
{
    int myNumber;

    for(int i = 0; i < checkVector.size(); i++)
        checkVector[i] = 0;

    for(int i = 0; i < sizeSquare; i++)
    {
        for(int j = 0 ; j < sizeSquare; j++)
        {

            srand(mysrand());
            do
            {
                myNumber = rand() % ((sizeSquare * sizeSquare) + 1);
                //cout <<"gerou " << myNumber << endl;
            }while(numberIsSquare(myNumber));

            checkVector[i*sizeSquare + j] = myNumber;

            square[i][j] = myNumber;
            //cout <<"guardando " << myNumber << endl;
        }
    }



}

bool MagicSquare::numberIsSquare(int myNumber)
{
    vector<int>::iterator it;

    it = std::find(checkVector.begin(), checkVector.end(), myNumber);

    if(it == checkVector.end()) return false;
    else  return true;
    //{
    //cout << "\nconflito com " << *it << endl;

    //}

}

long int MagicSquare::mysrand()
{
       __asm__ __volatile__("rdtsc");
}
