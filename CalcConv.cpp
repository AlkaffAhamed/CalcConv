//Calculator with Unit Converter
//
//A Mini Project for Object Oriented Programming
//
//Done by A.Alkaff Ahamed (Alkaff Paiya)
//
//Copyright 2016

#include<iostream>
#include<cmath>
#include<fstream>
#include<ctime>
#include"modBasic2.h"
#include"modQuad.h"
#include"modUnit.h"
#include"modLogger.h"

using namespace std;


int basicModule()
{
    basic obj;
    int x, y, selA;

    do
    {
        cout<<"Enter operation:\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n0. Terminate Module\n";
        cin>>selA;

        if (selA == 0 || selA > 4)
        {
            obj.arit = 0;
            obj.logFile();
            //Log and continue with next iteration for invalid selection
            continue;
        }

        cout<<"Enter first term (a): ";
        cin>>x;
        cout<<"Enter second term (b): ";
        cin>>y;

        obj.getData(x,y);

        switch (selA)
        {
        case 1:
            obj.add();
            break;
        case 2:
            obj.sub();
            break;
        case 3:
            obj.multi();
            break;
        case 4:
            obj.div();
            break;
        case 0:
            break;
        }
        obj.logFile();
    }
    while (selA != 0);

    return 0;
}

int quadModule()
{
    quad obj;
    int a, b, c, sel;

    do
    {
        cout<<"Enter equation in the form: ax^2 + bx + c = 0."<<endl;
        cout<<"Enter a: ";
        cin>>a;
        cout<<"Enter b: ";
        cin>>b;
        cout<<"Enter c: ";
        cin>>c;

        obj.getData(a, b, c);
        obj.solve();
        obj.display();

        cout<<"Solve another Quadratic Equation? \n1-Yes, 0-No\n";
        cin>>sel;
        if (sel != 0)
        {
            //Continue with next iteration if selection is Yes
            continue;
        }
    }
    while (sel != 0);
}

int unitModule()
{
    length obj;
    int x, sel;

    do
    {
        cout<<"Enter the unit to convert from:\n1. cm\n2. m\n3. in\n4. ft\n5. yard\n0. Terminate Module\n";
        cin>>sel;

        if (sel > 5)
        {
            //Log Invalid selection. Then continue with next iteration
            obj.invalid(0);
            continue;
        }
        else if (sel == 0)
        {
            //Break if user selects Terminate
            break;
        }

        cout<<"Enter magnitude: ";
        cin>>x;
        obj.getData(x);

        switch (sel)
        {
        case 1:
            obj.centimeter(sel);
            break;
        case 2:
            obj.meter(sel);
            break;
        case 3:
            obj.inch(sel);
            break;
        case 4:
            obj.feet(sel);
            break;
        case 5:
            obj.yard(sel);
            break;
        case 0:
            break;
        }

    }
    while (sel != 0);
}

int main ()
{
    logger L;
    L.startLog();

    cout<<"Calculator with Unit Converter\n";
    int sel;

    do
    {
        cout<<"Enter Module:\n1. Calculator\n2. Unit Converter\n3. Quadratic Solver\n0. Terminate\n";
        cin>>sel;

        L.modType(sel);

        switch (sel)
        {
        case 1:
            basicModule();
            break;
        case 2:
            unitModule();
            break;
        case 3:
            quadModule();
            break;
        case 0:
            break;
        }
    }
    while (sel != 0);

    L.stopLog();
    return 0;
}
