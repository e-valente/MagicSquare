#ifndef GA_H
#define GA_H

#include "magicsquare.h"
class GA
{
public:

    int goal;
    MagicSquare magicSquare;
    //public methods
    GA();
    GA(int);
    void exec();

private:

    int worstDeviation;
    int chromosome1[4];
    int chromosome2[4];
    int worstLine1, worstLine2;
    int fenotype1_1, fenotype1_2, fenotype1_3, fenotype1_4;
    int fenotype2_1, fenotype2_2, fenotype2_3, fenotype2_4;


    //private methods

    void calculateFitness();
    void crossOver();
    void fenotypesToSquare();
    int getFenotypeFromChromosome1();
    int getFenotypeFromChromosome2();
    void setFenotypes();

    void swap(int&, int&);
    int getFenotype(int*);
    int setChromosome1(int);
    int setChromosome2(int);
    void repairSquare(int line);
    bool isAtSquare(int value, int exceptPosition_i, int exceptPosition_j);
};

#endif // GA_H
