#include <iostream>
#include "BMatrix.h"
#include <random>
#include "read.hpp"


using namespace std;

#define valami
#ifdef valami

void MenuKiir()
{
    cout << endl << endl;
    cout << " 0. - Kilepes" << endl;
    cout << " 1. - Matrix kiirasa" << endl;
    cout << " 2. - Konkret elem lekerese" << endl;
    cout << " 3. - Masik matrix letrehozasa,es kiirasa" << endl;
    cout << " 4. - Matrixok osszeadasa" << endl;
    cout << " 5. - Matrixok szorzasa" << endl;
}

int main()
{
    int veg;
    vector<int>masikV;
    bool matrixLetezik=false;
    bool masikMatrix=false;
    cout<<endl;
    cout<<endl;
    int a1;
    int a2;
    cout<<"Kerem az elso negyzetmatrix meretet"<<endl;
    do
    {
        cin>>a1;
        if(a1<0)
        {
            cout<<"rossz adatot adott meg"<<endl;
        }
    }
    while(a1<=0);
    cout<<"Kerem a masodik negyzetmatrix meretet"<<endl;
    do
    {
        cin>>a2;
        if(a2<0)
        {
            cout<<"rossz adatot adott meg"<<endl;
        }
    }
    while(a2<=0);
    cout<<endl;
    BMatrix prob(a1,a2);
    MenuKiir();
    cout<<endl;
    do
    {
        cout<<"Melyik menupont hajtodjon vegre?"<<endl;
        cin>>veg;
        if(veg==0)
        {
            exit(0);
        }
        else if(veg>0&&veg<6)
        {
            if(veg==1)
            {
            prob.BlockMKir();
            cout<<endl;
            MenuKiir();
            }
        //cout<<endl;
        cout<<endl;
        if(veg==2)
        {
        int index1,index2;
        cout<<"Kerem az elso index-et(sor)"<<endl;
        cin>>index1;
        cout<<"Kerem a masodik index-et(oszlop)"<<endl;
        cin>>index2;
        cout<<endl;
        prob.elementByIndex(index1,index2);
        cout<<endl;
        MenuKiir();
        cout<<endl;
        }
       // cout<<endl;
        cout<<endl;
        if(veg==3)
        {
        for(int i=0;i<(a1*a1)+(a2*a2);i++)
        {
            masikV.push_back((rand()%100)+1);
        }
        prob.Mkiir(masikV);
        masikMatrix=true;
        cout<<endl;
        MenuKiir();
        cout<<endl;
        }
        //cout<<endl;
        cout<<endl;
        if(veg==4&&masikMatrix==true)
        {
        prob.osszeg(masikV);
        cout<<endl;
        MenuKiir();
        cout<<endl;
        }
        else if(veg==4&&masikMatrix==false)
        {
            cout<<"nem letezik a masik matrix"<<endl;
            cout<<endl;
            MenuKiir();
            cout<<endl;
        }
        if(veg==5&&masikMatrix==true)
        {
        prob.multiply(masikV);
        cout<<endl;
        MenuKiir();
        cout<<endl;
        }
        else if(masikMatrix==false&&veg==5)
        {
            cout<<"nem letezik a masik matrix"<<endl;
        }
    }
    else
    {
        cout<<"ilyen opcio nincs"<<endl;
        cout<<endl;
    }
}
    while(veg!=0);
    int a;
    cin>>a;
    return 0;
}
#else
#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"

TEST_CASE("ADOTT ELEM","")
{
    BMatrix a(4,5);
    CHECK(a.elementByIndex(1,1) == 42);
}
TEST_CASE("ADOTT ELEM","")
{
    BMatrix a(4,5);
    CHECK(a.elementByIndex(1,2)==68);
}
TEST_CASE("ADOTT ELEM","")
{
    BMatrix a(4,5);
    CHECK(a.elementByIndex(2,3)==79);
}
TEST_CASE("ADOTT ELEM","")
{
    BMatrix a(4,5);
    CHECK(a.osszeg(masikV).elementByIndex(3,4)==46);
}
TEST_CASE("OSSZEG","")
{
    BMatrix a(4,5);
    CHECK(a.osszeg(masikV).elementByIndex(1,3)==69);
}
TEST_CASE("OSSZEG","")
{
    BMatrix a(4,5);
    CHECK(a.osszeg(masikV).elementByIndex(2,1)==135);
}
TEST_CASE("OSSZEG","")
{
    BMatrix a(4,5);
    CHECK(a.osszeg(masikV).elementByIndex(3,2)==113);
}
TEST_CASE("SZORZAT","")
{
    BMatrix a(4,5);
    CHECK(a.multiply(masikV).elementByIndex(3,1)==12418);
}
TEST_CASE("SZORZAT","")
{
    BMatrix a(4,5);
    CHECK(a.multiply(masikV).elementByIndex(2,3)==9775);
}
TEST_CASE("SZORZAT","")
{
    BMatrix a(4,5);
    CHECK(a.multiply(masikV).elementByIndex(5,6)==16307);
}

#endif
