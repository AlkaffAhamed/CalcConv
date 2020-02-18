//Unit Converter Module
//
//Header File for Unit Converter Module
//
//Done by A.Alkaff Ahamed (Alkaff Paiya)
//
//Copyright 2016

#include<iostream>
#include<cmath>
#include<cstring>
#include"modLogger.h"
#ifndef MODUNIT_H
#define MODUNIT_H
using namespace std;

//Inheritance is done to this class only

class length: public logger
{
private:
    float m, cm, in, ft, yd, x;
    logger L;

    int display(int n)
    {
        cout<<cm<<" cm"<<endl;
        cout<<m<<" m"<<endl;
        cout<<in<<" inches"<<endl;
        cout<<ft<<" foot"<<endl;
        cout<<yd<<" yards"<<endl;
        logFile(n);
    }

    int logFile(int u)
    {
        //int u is passed all the way from the Main Function int sel
        //for the case of invalid operations
        if (u == 0 || u > 5)
        {
            L.logUnitInput(0, 0);
            L.logUnitResult(cm, m, in, ft, yd, 0);
        }
        else
        {
            L.logUnitInput(x, u);
            L.logUnitResult(cm, m, in, ft, yd, u);
        }
    }

public:

    int getData(int n)
    {
        x = n;
    }

    int invalid (int a)
    {
        logFile(a);
    }

    float centimeter(int j)
    {
        cm = x;
        m = cm/100;
        in = cm/2.54;
        ft = in/12;
        yd = ft/3;

        cout<<x<<" cm is:\n";
        display(j);
    }

    float meter(int j)
    {
        m = x;
        cm = m*100;
        in = cm/2.54;
        ft = in/12;
        yd = ft/3;

        cout<<x<<" m is:\n";
        display(j);
    }

    float inch(int j)
    {
        in = x;
        cm = 2.54*in;
        m = cm/100;
        ft = in/12;

        cout<<x<<" inch is:\n";
        display(j);
    }

    float feet(int j)
    {
        ft = x;
        in = 12*ft;
        cm = 2.54*in;
        m = cm/100;
        yd = ft/3;

        cout<<x<<" feet is:\n";
        display(j);
    }

    float yard(int j)
    {
        yd = x;
        ft = yd*3;
        in = 12*ft;
        cm = 2.54*in;
        m = cm/100;

        cout<<x<<" yard is:\n";
        display(j);
    }
};
#endif
