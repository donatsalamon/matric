#ifndef BMATRIX_H
#define BMATRIX_H

#include <vector>
#include <string>

class BMatrix
{
    public:
        BMatrix(int a,int b);
        int getN1(){return n1;}
        int getN2(){return n2;}
        void BlockMKir();
        void Mkiir(std::vector<int>vekt);
       std::vector<int>vektor;
       std::vector<int>vektorPlus;
       void multiply(std::vector<int>vekt);
       std::vector<int>vektorMultiply;
       int elementByIndex(int c,int d);
       void osszeg(std::vector<int>vekt);

    private:
        int n1;
        int n2;

};

#endif // BMATRIX_H
