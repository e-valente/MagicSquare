#include "ga.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;
GA::GA(int sizeSquare)
{
    goal =  0.5 * sizeSquare*((sizeSquare * sizeSquare)-1);
    //goal = 34;
}


void GA::exec()
{
    int count = 0;

    cout <<"Objetivo: soma de todas as filas: " << goal << endl;
    cout <<"Estado inicial do quadrado:\n";
    magicSquare.printSquare();

    srand(magicSquare.mysrand());

    do{
        calculateFitness();

        //roleta
        //70% de prob pra pegar as
        //2 piores linhas
        //30% de prob: linhas aleatorias
        if(((rand()%10) +1) > 7)
        {
            worstLine1 = ((rand()%10) +1);
            worstLine2 = ((rand()%10) +1);

        }

        //magicSquare.printSquare();

        crossOver();

        //magicSquare.printSquare();
        count++;


    }while(count < 10000);

    cout << "Melhor quadrado apos 10000 geracoes:\n";
    magicSquare.printSquare();


}

void GA::calculateFitness()
{
    int worstIndex, sum;

    worstDeviation = -1;
    worstIndex = -1;

    for(int i = 0; i < 10; i++)
    {
        sum = magicSquare.calculateSum(i+1);
        sum -= goal;
        sum = abs(sum);
        //cout <<"sum, index: " << magicSquare.calculateSum(i+1) << " " << i+1 << endl;
        if(sum  > worstDeviation)
        {
            worstDeviation = sum;
            worstIndex = i + 1;
        }

    }


    worstLine1 = worstIndex;

    worstDeviation = -1;


    for(int i = 0; i < 10; i++)
    {
        if(i+1 != worstLine1)
        {
            sum = magicSquare.calculateSum(i+1);
            sum -= goal;
            sum = abs(sum);
            //cout <<"sum, index: " << magicSquare.calculateSum(i+1) << " " << i+1 << endl;
            if(sum  > worstDeviation)
            {
                worstDeviation = sum;
                worstIndex = i + 1;
            }
        }
    }

    worstLine2 = worstIndex;


//    cout <<"piores desvios: "<< worstDeviation <<"  mostrando indice da linha " << worstLine1<< " "
//        << worstLine2 << endl;





}

void GA::crossOver()
{

    //obtem inteiros das 2 piores filas
    setFenotypes();


    /*primeiro inteiro*/
    //inteiro -> bin (chromossomo)
    setChromosome1(fenotype1_1);
    setChromosome2(fenotype2_1);


    //swap
    swap(chromosome1[0], chromosome2[2]);
    swap(chromosome1[1], chromosome2[3]);



    fenotype1_1 = getFenotypeFromChromosome1();
    fenotype2_1 = getFenotypeFromChromosome2();



    /*segundo inteiro*/
    //inteiro -> bin (chromossomo)
    setChromosome1(fenotype1_2);
    setChromosome2(fenotype2_2);

    //swap
    swap(chromosome1[0], chromosome2[2]);
    swap(chromosome1[1], chromosome2[3]);
    fenotype1_2 = getFenotypeFromChromosome1();
    fenotype2_2 = getFenotypeFromChromosome2();

    /*terceiro inteiro*/
    //inteiro -> bin (chromossomo)
    setChromosome1(fenotype1_3);
    setChromosome2(fenotype2_3);

    //swap
    swap(chromosome1[0], chromosome2[2]);
    swap(chromosome1[1], chromosome2[3]);


    fenotype1_3 = getFenotypeFromChromosome1();
    fenotype2_3 = getFenotypeFromChromosome2();

    /*quarto inteiro*/
    //inteiro -> bin (chromossomo)
    setChromosome1(fenotype1_4);
    setChromosome2(fenotype2_4);

    //swap
    swap(chromosome1[0], chromosome2[2]);
    swap(chromosome1[1], chromosome2[3]);
    fenotype1_4 = getFenotypeFromChromosome1();
    fenotype2_4 = getFenotypeFromChromosome2();




    fenotypesToSquare();



}

void GA::fenotypesToSquare()
{
    int n;

    if(worstLine1 == 1)
    {
        magicSquare.square[0][0] = fenotype1_1; magicSquare.square[0][1] = fenotype1_2;
        magicSquare.square[0][2] = fenotype1_3; magicSquare.square[0][3] = fenotype1_4;
        repairSquare(1);

    }

    if(worstLine2 == 1)
    {
        magicSquare.square[0][0] = fenotype2_1; magicSquare.square[0][1] = fenotype2_2;
        magicSquare.square[0][2] = fenotype2_3; magicSquare.square[0][3] = fenotype2_4;
        repairSquare(1);

    }

    if(worstLine1 == 2)
    {
        magicSquare.square[1][0] = fenotype1_1; magicSquare.square[1][1] = fenotype1_2;
        magicSquare.square[1][2] = fenotype1_3; magicSquare.square[1][3] = fenotype1_4;
        repairSquare(2);

    }

    if(worstLine2 == 2)
    {
        magicSquare.square[1][0] = fenotype2_1; magicSquare.square[1][1] = fenotype2_2;
        magicSquare.square[1][2] = fenotype2_3; magicSquare.square[1][3] = fenotype2_4;
        repairSquare(2);

    }

    if(worstLine1 == 3)
    {
        magicSquare.square[1][0] = fenotype1_1; magicSquare.square[1][1] = fenotype1_2;
        magicSquare.square[1][2] = fenotype1_3; magicSquare.square[1][3] = fenotype1_4;
        repairSquare(3);

    }

    if(worstLine2 == 3)
    {
        magicSquare.square[2][0] = fenotype2_1; magicSquare.square[2][1] = fenotype2_2;
        magicSquare.square[2][2] = fenotype2_3; magicSquare.square[2][3] = fenotype2_4;
        repairSquare(3);

    }

    if(worstLine1 == 4)
    {
        magicSquare.square[3][0] = fenotype1_1; magicSquare.square[3][1] = fenotype1_2;
        magicSquare.square[3][2] = fenotype1_3; magicSquare.square[3][3] = fenotype1_4;
        repairSquare(4);

    }

    if(worstLine2 == 4)
    {
        magicSquare.square[3][0] = fenotype2_1; magicSquare.square[3][1] = fenotype2_2;
        magicSquare.square[3][2] = fenotype2_3; magicSquare.square[3][3] = fenotype2_4;
        repairSquare(4);

    }


    if(worstLine1 == 5)
    {
        magicSquare.square[0][0] = fenotype1_1; magicSquare.square[1][0] = fenotype1_2;
        magicSquare.square[2][0] = fenotype1_3; magicSquare.square[3][0] = fenotype1_4;
        repairSquare(5);

    }

    if(worstLine2 == 5)
    {
        magicSquare.square[0][0] = fenotype2_1; magicSquare.square[1][0] = fenotype2_2;
        magicSquare.square[2][0] = fenotype2_3; magicSquare.square[3][0] = fenotype2_4;
        repairSquare(5);

    }

    if(worstLine1 == 6)
    {
        magicSquare.square[0][1] = fenotype1_1; magicSquare.square[1][1] = fenotype1_2;
        magicSquare.square[2][1] = fenotype1_3; magicSquare.square[3][1] = fenotype1_4;
        repairSquare(6);

    }

    if(worstLine2 == 6)
    {
        magicSquare.square[0][1] = fenotype2_1; magicSquare.square[1][1] = fenotype2_2;
        magicSquare.square[2][1] = fenotype2_3; magicSquare.square[3][1] = fenotype2_4;
        repairSquare(6);
    }

    if(worstLine1 == 7)
    {
        magicSquare.square[0][2] = fenotype1_1; magicSquare.square[1][2] = fenotype1_2;
        magicSquare.square[2][2] = fenotype1_3; magicSquare.square[3][2] = fenotype1_4;
        repairSquare(7);

    }

    if(worstLine2 == 7)
    {
        magicSquare.square[0][2] = fenotype2_1; magicSquare.square[1][2] = fenotype2_2;
        magicSquare.square[2][2] = fenotype2_3; magicSquare.square[3][2] = fenotype2_4;
        repairSquare(7);

    }

    if(worstLine1 == 8)
    {
        magicSquare.square[0][3] = fenotype1_1; magicSquare.square[1][3] = fenotype1_2;
        magicSquare.square[2][3] = fenotype1_3; magicSquare.square[3][3] = fenotype1_4;
        repairSquare(8);

    }

    if(worstLine2 == 8)
    {
        magicSquare.square[0][3] = fenotype2_1; magicSquare.square[1][3] = fenotype2_2;
        magicSquare.square[2][3] = fenotype2_3; magicSquare.square[3][3] = fenotype2_4;
        repairSquare(8);

    }

    if(worstLine1 == 9)
    {
        magicSquare.square[0][0] = fenotype1_1; magicSquare.square[1][1] = fenotype1_2;
        magicSquare.square[2][2] = fenotype1_3; magicSquare.square[3][3] = fenotype1_4;
        repairSquare(9);

    }

    if(worstLine2 == 9)
    {
        magicSquare.square[0][0] = fenotype2_1; magicSquare.square[1][1] = fenotype2_2;
        magicSquare.square[2][2] = fenotype2_3; magicSquare.square[3][3] = fenotype2_4;
        repairSquare(9);

    }

    if(worstLine1 == 10)
    {
        magicSquare.square[0][3] = fenotype1_1; magicSquare.square[1][2] = fenotype1_2;
        magicSquare.square[2][1] = fenotype1_3; magicSquare.square[3][0] = fenotype1_4;
        repairSquare(10);

    }

    if(worstLine2 == 10)
    {
        magicSquare.square[0][3] = fenotype2_1; magicSquare.square[1][2] = fenotype2_2;
        magicSquare.square[2][1] = fenotype2_3; magicSquare.square[3][0] = fenotype2_4;
        repairSquare(10);

    }



}


void GA::setFenotypes()
{
    if(worstLine1 == 1)
    {
        fenotype1_1 = magicSquare.square[0][0]; fenotype1_2 = magicSquare.square[0][1];
        fenotype1_3 = magicSquare.square[0][2]; fenotype1_4 = magicSquare.square[0][3];
    }

    if(worstLine2 == 1)
    {
        fenotype2_1 = magicSquare.square[0][0]; fenotype2_2 = magicSquare.square[0][1];
        fenotype2_3 = magicSquare.square[0][2]; fenotype2_4 = magicSquare.square[0][3];
    }


    if(worstLine1 == 2)
    {
        fenotype1_1 = magicSquare.square[1][0]; fenotype1_2 = magicSquare.square[1][1];
        fenotype1_3 = magicSquare.square[1][2]; fenotype1_4 = magicSquare.square[1][3];
    }

    if(worstLine2 == 2)
    {
        fenotype2_1 = magicSquare.square[1][0]; fenotype2_2 = magicSquare.square[1][1];
        fenotype2_3 = magicSquare.square[1][2]; fenotype2_4 = magicSquare.square[1][3];
    }


    if(worstLine1 == 3)
    {
        fenotype1_1 = magicSquare.square[2][0]; fenotype1_2 = magicSquare.square[2][1];
        fenotype1_3 = magicSquare.square[2][2]; fenotype1_4 = magicSquare.square[2][3];
    }

    if(worstLine2 == 3)
    {
        fenotype2_1 = magicSquare.square[2][0]; fenotype2_2 = magicSquare.square[2][1];
        fenotype2_3 = magicSquare.square[2][2]; fenotype2_4 = magicSquare.square[2][3];
    }

    if(worstLine1 == 4)
    {
        fenotype1_1 = magicSquare.square[3][0]; fenotype1_2 = magicSquare.square[3][1];
        fenotype1_3 = magicSquare.square[3][2]; fenotype1_4 = magicSquare.square[3][3];
    }

    if(worstLine2 == 4)
    {
        fenotype2_1 = magicSquare.square[3][0]; fenotype2_2 = magicSquare.square[3][1];
        fenotype2_3 = magicSquare.square[3][2]; fenotype2_4 = magicSquare.square[3][3];
    }

    if(worstLine1 == 5)
    {
        fenotype1_1 = magicSquare.square[0][0]; fenotype1_2 = magicSquare.square[1][0];
        fenotype1_3 = magicSquare.square[2][0]; fenotype1_4 = magicSquare.square[3][0];
    }

    if(worstLine2 == 5)
    {
        fenotype2_1 = magicSquare.square[0][0]; fenotype2_2 = magicSquare.square[1][0];
        fenotype2_3 = magicSquare.square[2][0]; fenotype2_4 = magicSquare.square[3][0];
    }

    if(worstLine1 == 6)
    {
        fenotype1_1 = magicSquare.square[0][1]; fenotype1_2 = magicSquare.square[1][1];
        fenotype1_3 = magicSquare.square[2][1]; fenotype1_4 = magicSquare.square[3][1];
    }

    if(worstLine2 == 6)
    {
        fenotype2_1 = magicSquare.square[0][1]; fenotype2_2 = magicSquare.square[1][1];
        fenotype2_3 = magicSquare.square[2][1]; fenotype2_4 = magicSquare.square[3][1];
    }


    if(worstLine1 == 7)
    {
        fenotype1_1 = magicSquare.square[0][2]; fenotype1_2 = magicSquare.square[1][2];
        fenotype1_3 = magicSquare.square[2][2]; fenotype1_4 = magicSquare.square[3][2];
    }

    if(worstLine2 == 7)
    {
        fenotype2_1 = magicSquare.square[0][2]; fenotype2_2 = magicSquare.square[1][2];
        fenotype2_3 = magicSquare.square[2][2]; fenotype2_4 = magicSquare.square[3][2];
    }

    if(worstLine1 == 8)
    {
        fenotype1_1 = magicSquare.square[0][3]; fenotype1_2 = magicSquare.square[1][3];
        fenotype1_3 = magicSquare.square[2][2]; fenotype1_4 = magicSquare.square[3][3];
    }

    if(worstLine2 == 8)
    {
        fenotype2_1 = magicSquare.square[0][3]; fenotype2_2 = magicSquare.square[1][3];
        fenotype2_3 = magicSquare.square[3][3]; fenotype2_4 = magicSquare.square[3][3];
    }

    if(worstLine1 == 9)
    {
        fenotype1_1 = magicSquare.square[0][0]; fenotype1_2 = magicSquare.square[1][1];
        fenotype1_3 = magicSquare.square[2][2]; fenotype1_4 = magicSquare.square[3][3];
    }

    if(worstLine2 == 9)
    {
        fenotype2_1 = magicSquare.square[0][0]; fenotype2_2 = magicSquare.square[1][1];
        fenotype2_3 = magicSquare.square[2][2]; fenotype2_4 = magicSquare.square[3][3];
    }


    if(worstLine1 == 10)
    {
        fenotype1_1 = magicSquare.square[0][3]; fenotype1_2 = magicSquare.square[1][2];
        fenotype1_3 = magicSquare.square[2][1]; fenotype1_4 = magicSquare.square[3][0];
    }

    if(worstLine2 == 10)
    {
        fenotype2_1 = magicSquare.square[0][3]; fenotype2_2 = magicSquare.square[1][2];
        fenotype2_3 = magicSquare.square[2][1]; fenotype2_4 = magicSquare.square[3][0];
    }
}

int GA::setChromosome1(int fenotype)
{
    if(fenotype > 16) return 0;

    fenotype--;

    chromosome1[3] = (fenotype & 8) >> 3;
    chromosome1[2] = (fenotype & 4) >> 2;
    chromosome1[1] = (fenotype & 2) >> 1;
    chromosome1[0] = (fenotype & 1);

    return 1;

}

int GA::setChromosome2(int fenotype)
{
    if(fenotype > 16) return 0;

    fenotype--;

    chromosome2[3] = (fenotype & 8) >> 3;
    chromosome2[2] = (fenotype & 4) >> 2;
    chromosome2[1] = (fenotype & 2) >> 1;
    chromosome2[0] = (fenotype & 1);

    return 1;

}

int GA::getFenotypeFromChromosome1()
{
    int n;

    n = 0;

    //bit order: 0001 = 1
    n = chromosome1[0] + 2*chromosome1[1] + 4*chromosome1[2] + 8*chromosome1[3];

    //saving one bit: 0000 = 1 and so on
    return n + 1;

}


int GA::getFenotypeFromChromosome2()
{
    int n;

    n = 0;

    //bit order: 0001 = 1
    n = chromosome2[0] + 2*chromosome2[1] + 4*chromosome2[2] + 8*chromosome2[3];

    //saving one bit: 0000 = 1 and so on
    return n + 1;

}

void GA::repairSquare(int line)
{
    int n, count;

    srand(magicSquare.mysrand());

    if(line == 1)
    {
        for(int i = 0; i < 4; i++)
        {
            n = magicSquare.square[0][i];
            while(isAtSquare(n, 0, i))
            {
                n = (rand()%16) + 1;
            }

            magicSquare.square[0][i] = n;

        }
    }



    if(line == 2)
    {
        for(int i = 0; i < 4; i++)
        {
            n = magicSquare.square[1][i];
            while(isAtSquare(n, 1, i))
            {
                n = (rand()%16) + 1;
            }
            magicSquare.square[1][i] = n;

        }
    }

    if(line == 3)
    {
        for(int i = 0; i < 4; i++)
        {
            n = magicSquare.square[2][i];
            while(isAtSquare(n, 2, i))
            {
                n = (rand()%16) + 1;
            }
            magicSquare.square[2][i] = n;

        }
    }

    if(line == 4)
    {
        for(int i = 0; i < 4; i++)
        {
            n = magicSquare.square[3][i];
            while(isAtSquare(n, 3, i))
            {
                n = (rand()%16) + 1;
            }
            magicSquare.square[3][i] = n;

        }
    }

    if(line == 5)
    {
        for(int i = 0; i < 4; i++)
        {
            n = magicSquare.square[i][0];
            while(isAtSquare(n, i, 0))
            {
                n = (rand()%16) + 1;
            }

            magicSquare.square[i][0] = n;

        }
    }


    if(line == 6)
    {
        for(int i = 0; i < 4; i++)
        {
            n = magicSquare.square[i][1];
            while(isAtSquare(n, i, 1))
            {
                n = (rand()%16) + 1;
            }
            magicSquare.square[i][1] = n;

        }
    }

    if(line == 7)
    {
        for(int i = 0; i < 4; i++)
        {
            n = magicSquare.square[i][2];
            while(isAtSquare(n, i, 2))
            {
                n = (rand()%16) + 1;
            }
            magicSquare.square[i][2] = n;

        }
    }

    if(line == 8)
    {
        for(int i = 0; i < 4; i++)
        {
            n = magicSquare.square[i][3];
            while(isAtSquare(n, i, 3))
            {
                n = (rand()%16) + 1;
            }
            magicSquare.square[i][3] = n;

        }

    }


    if(line == 9)
    {
        for(int i = 0; i < 4; i++)
        {
            n = magicSquare.square[i][i];
            while(isAtSquare(n, i, i))
            {
                n = (rand()%16) + 1;
            }
            magicSquare.square[i][i] = n;

        }
    }

    if(line == 10)
    {
        int j;
        for(int i = 0, j = 3; i < 4; i++, j--)
        {
            n = magicSquare.square[i][j];
            while(isAtSquare(n, i, j))
            {
                n = (rand()%16) + 1;
            }
            magicSquare.square[i][j] = n;

        }
    }



}

bool GA::isAtSquare(int value, int exceptPosition_i, int exceptPosition_j)
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(i != exceptPosition_i || j != exceptPosition_j)
            {
                if(value == magicSquare.square[i][j])return true;
            }
        }
    }

    return false;
}

void GA::swap(int &n1, int &n2)
{
    int tmp;

    tmp = n1;
    n1 = n2;
    n2 = tmp;
}
