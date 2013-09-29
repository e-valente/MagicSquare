#ifndef GA_H
#define GA_H

#include "magicsquare.h"
class GA
{
public:
    GA();
    MagicSquare magicSquare;
private:

    int genotype1[4];
    int genotype2[4];

    //private methods
    int getFenotype(int*);
    int setGenotype1(int);
    int setGenotype2(int);
};

#endif // GA_H
