#include "ga.h"
#include <iostream>

using namespace std;
GA::GA()
{
    cout << "GA object has just created..\n";


    setGenotype1(16);



}


int GA::setGenotype1(int fenotype)
{
    if(fenotype > 16) return 0;

    fenotype--;

    genotype1[3] = (fenotype & 8) >> 3;
    genotype1[2] = (fenotype & 4) >> 2;
    genotype1[1] = (fenotype & 2) >> 1;
    genotype1[0] = (fenotype & 1);

    return 1;

}

int GA::getFenotype(int *genotype)
{
    int n;

    n = 0;

    //bit order: 0001 = 1
    n = genotype[0] + 2*genotype[1] + 4*genotype[2] + 8*genotype[3];

    //saving one bit: 0000 = 1 and so on
    return n + 1;

}

