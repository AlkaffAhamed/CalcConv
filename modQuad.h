//Quadratic Solver Module
//
//Header File for Quadratic Solver Module
//
//Done by A.Alkaff Ahamed (Alkaff Paiya)
//
//Copyright 2016

#include<iostream>
#include<cmath>
#include"modLogger.h"
using namespace std;

class quad
{
private:
    float a, b, c;
    float re, im;
    float x1, x2, x, zero = 0;//float zero to pass 0 literally
    logger L;

public:
    float d;

    float getData(float x, float y, float z)
    {
        a = x;
        b = y;
        c = z;

        d = b*b - 4*a*c;
        L.logQuadExpr(a,b,c,d);//Logging Module
    }

    float solve()
    {

        //Logging Module embedded here

        if (d<0)
        {
            d = -1*d;
            re = (0-b)/(2*a);
            im = (sqrt(d))/(2*a);

            //Reset values to prevent using previous values

            x1 = NULL;
            x2 = NULL;
            x = NULL;
            d = -1*d;

            L.logQuadSoln(d, re, im);
        }
        else if (d>0)
        {
            x1 = ((0-b)+sqrt(d))/(2*a);
            x2 = ((0-b)-sqrt(d))/(2*a);

            //Reset values to prevent using previous values

            re = NULL;
            im = NULL;
            x = NULL;

            L.logQuadSoln(d, x1, x2);
        }
        else
        {
            x = (0-b)/(2*a);

            //Reset values to prevent using previous values

            x1 = NULL;
            x2 = NULL;
            re = NULL;
            im = NULL;

            L.logQuadSoln(d, x, zero);
        }
    }

    int display ()
    {
        cout<<"Determinant = "<<d<<endl;

        if (d>0)
        {
            cout<<"Solution\nx1 = "<<x1<<endl<<"x2 = "<<x2<<endl;
        }
        else if (d<0)
        {
            cout<<"x = "<<re<<" +/- "<<im<<"i"<<endl;
        }
        else
        {
            cout<<"x = "<<x<<endl;
        }

        //Testing all variables
        //cout<<a<<b<<c<<" "<<d<<" "<<"x "<<x<<x1<<x2<<"z "<<re<<im<<endl;
    }
};
