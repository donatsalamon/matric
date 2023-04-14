#include "BMatrix.h"
#include <random>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

BMatrix::BMatrix(int a,int b)
{
    n1=a;
    n2=b;
    for(int i=0;i<(n1*n1)+(n2*n2);i++)
    {
        vektor.push_back((rand()%100)+1);
    }
}
void BMatrix::osszeg(std::vector<int>vekt1)
{
    for(int j=0;j<(n1*n1)+(n2*n2);j++)
    {
        vektorPlus.push_back(vektor[j]+vekt1[j]);
    }
    Mkiir(vektorPlus);
}
void BMatrix::Mkiir(vector<int>vekt)
{
    int db=0;
    for(int i=0;i<n1;i++)
    {
        int j=0;
       while(j<n1)
        {
            cout<<vekt[db]<<' ';
            db++;
            j++;
        }
        for(int k=0;k<n2;k++)
        {
            cout<<0<<' ';
        }
        cout<<endl;
    }
    for(int i=0;i<n2;i++)
    {
        for(int k=0;k<n1;k++)
        {
            cout<<0<<' ';
        }
        int j=0;
       while(j<n2)
        {
            cout<<vekt[db]<<' ';
            db++;
            j++;
        }
        cout<<endl;
    }

}
void BMatrix::BlockMKir()
{
    int db=0;
    for(int i=0;i<n1;i++)
    {
        int j=0;
       while(j<n1)
        {
            cout<<vektor[db]<<' ';
            db++;
            j++;
        }
        for(int k=0;k<n2;k++)
        {
            cout<<0<<' ';
        }
        cout<<endl;
    }
    for(int i=0;i<n2;i++)
    {
        for(int k=0;k<n1;k++)
        {
            cout<<0<<' ';
        }
        int j=0;
       while(j<n2)
        {
            cout<<vektor[db]<<' ';
            db++;
            j++;
        }
        cout<<endl;
    }
}
int BMatrix::elementByIndex(int c,int d)
{
    if(c<=n1&&d<=n1)
    {
    cout<<vektor[(((c-1)*n1)+d)-1];
    return vektor[(((c-1)*n1)+d)-1];
    }
    else if(c>=n2&&d>=n2)
    {
    /*for(int i=n1*n1;i<n1*n1+n2*n2;i++)
    {
        if()

    }*/
    cout<<vektor[((n1*n1+((c-n2)*n2)+d)-1)-n1];
    return vektor[((n1*n1+((c-n2)*n2)+d)-1)-n1];
    }
    else
    {
        cout<<'0';
        return 0;
    }
}
void BMatrix::multiply(vector<int>vekt)
{
    int sor=0;
    int oszlop=0;
    int ossz=0;
    int aktualisSor=0;
    for(int k=0;k<n1;k++)
    {
        ossz=0;
        aktualisSor=sor+k*n1;
        sor+=(k*n1);
       // oszlop+=(k*n1);
        for(int j=0;j<n1;j++)
        {
            //sor+=(j*n1);
            ossz=0;
            oszlop+=j;
        for(int i=0;i<n1;i++)
        {
        //ossz=0;
        ossz+=(vektor[sor]*vekt[oszlop]);
        sor++;
        oszlop+=n1;
        }
        vektorMultiply.push_back(ossz);
        sor=aktualisSor;
        oszlop=0;
        }
    }
    sor=0;
    oszlop=0;
      for(int k=0;k<n2;k++)
    {
        ossz=0;
        sor=0;
        aktualisSor=(sor+k*n2)+(n1*n1);
        sor=(sor+k*n2)+(n1*n1);
        for(int j=0;j<n2;j++)
        {
            ossz=0;
            oszlop=(oszlop+j)+n1*n1;
        for(int i=0;i<n2;i++)
        {
        ossz+=(vektor[sor]*vekt[oszlop]);
        sor++;
        oszlop+=n2;
        }
        vektorMultiply.push_back(ossz);
        sor=aktualisSor;
        oszlop=0;
        }
    }
   Mkiir(vektorMultiply);
}
