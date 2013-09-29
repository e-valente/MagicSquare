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

int MagicSquare::calculateSum(int line)
{
    //horizontal
    if(line == 1)
        return square[0][0] + square[0][1] + square[0][2] + square[0][3];

    if(line == 2)
        return square[1][0] + square[1][1] + square[1][2] + square[1][3];


    if(line == 3)
        return square[2][0] + square[2][1] + square[2][2] + square[2][3];


    if(line == 4)
        return square[3][0] + square[3][1] + square[3][2] + square[3][3];

    //vertical

    if(line == 5)
        return square[0][0] + square[1][0] + square[2][0] + square[3][0];

    if(line == 6)
        return square[0][1] + square[1][1] + square[2][1] + square[3][1];

    if(line == 7)
        return square[0][2] + square[1][2] + square[2][2] + square[3][2];

    if(line == 8)
        return square[0][3] + square[1][3] + square[2][3] + square[3][3];

    //diagonal
    if(line == 9)
        return square[0][0] + square[1][1] + square[2][2] + square[3][3];

    if(line == 10)
        return square[0][3] + square[1][2] + square[2][1] + square[3][0];


    return -1;


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
