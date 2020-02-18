//Logger Module
//
//Header File for Logger Module
//
//Done by A.Alkaff Ahamed (Alkaff Paiya)
//
//Copyright 2016

#include<iostream>
#include<cmath>
#include<cstring>
#include<fstream>
#include<ctime>
#ifndef MODLOGGER_H
#define MODLOGGER_H
using namespace std;

class logger
{
private:
    ofstream upd;

    string modTypeList (int n)
    {
        switch(n)
        {
        case 1:
            return ("Basic Module");
            break;
        case 2:
            return ("Unit Converter Module");
            break;
        case 3:
            return ("Quadratic Solver Module");
            break;
        default:
            return ("None");
            break;
        }
    }

    int printTime()
    {
        time_t now = time(0);
        tm *tStamp = localtime(&now);

        if (tStamp->tm_hour < 10)
        {
            upd<<"0"<<tStamp->tm_hour<<":";
        }
        else
        {
            upd<<tStamp->tm_hour<<":";
        }

        if (tStamp->tm_min < 10)
        {
            upd<<"0"<<tStamp->tm_min<<":";
        }
        else
        {
            upd<<tStamp->tm_min<<":";
        }

        if (tStamp->tm_sec < 10)
        {
            upd<<"0"<<tStamp->tm_sec;
        }
        else
        {
            upd<<tStamp->tm_sec;
        }

        return 0;
    }

    int printDate()
    {
        time_t now = time(0);
        tm *tStamp = localtime(&now);

        if (tStamp->tm_mday < 10)
        {
            upd<<"0"<<tStamp->tm_mday<<"/";
        }
        else
        {
            upd<<tStamp->tm_mday<<"/";
        }

        if (tStamp->tm_mon < 9)
        {
            upd<<"0"<<1+tStamp->tm_mon<<"/";
        }
        else
        {
            upd<<1+tStamp->tm_mon<<"/";
        }

        upd<<1900+tStamp->tm_year;

        return 0;
    }

public:

    logger()
    {
        upd.open("Log.txt",ios::app);

    }

    int startLog()
    {
        upd<<"File Opened"<<endl<<"Date: ";
        printDate();
        upd<<endl<<"Time: ";
        printTime();
        upd<<endl<<endl<<"Logging Started"<<endl<<"At ";
        printTime();
        upd<<endl<<endl;
    }

    int stopLog()
    {
        upd<<"Logging Ended"<<endl<<"At ";
        printTime();
        upd<<endl<<endl;
    }

    int modType(int t)
    {
        string j;
        j = modTypeList(t);

        if (j != "None")
        {
            upd<<"At ";
            printTime();
            upd<<endl;
            upd<<"Opened Module: "<<j<<endl<<endl;
        }
    }

    int logBasic(int arit, float m, float n, float res)
    {
        upd<<"At ";
        printTime();
        upd<<endl<<"Expression: ";

        switch (arit)
        {
        case 1:
            upd<<m<<"+"<<n<<endl;
            upd<<"Result: "<<res<<endl<<endl;
            break;
        case 2:
            upd<<m<<"-"<<n<<endl;
            upd<<"Result: "<<res<<endl<<endl;
            break;
        case 3:
            upd<<m<<"*"<<n<<endl;
            upd<<"Result: "<<res<<endl<<endl;
            break;
        case 4:
            upd<<m<<"/"<<n<<endl;
            upd<<"Result: "<<res<<endl<<endl;
            break;
        case 5:
            upd<<m<<"/"<<n<<endl;
            upd<<"Error: Division by Zero"<<endl<<endl;
            break;
        default:
            upd<<endl<<"Invalid Operation"<<endl<<endl;
        }
    }

    int logQuadExpr(float a, float b, float c, float d)
    {
        upd<<"At ";
        printTime();
        upd<<endl<<"Expression: "<<a<<"x^2 + "<<b<<"x + "<<c<<" = 0"<<endl;
        upd<<"Determinant = "<<d<<endl<<endl;
        return 0;
    }
    int logQuadSoln(float d, float a, float b)
    {
        upd<<"At ";
        printTime();
        upd<<endl<<"Result: "<<endl;
        if (d > 0)
        {
            upd<<"x1 = "<<a<<endl<<"x2 = "<<b<<endl<<endl;
        }
        else if (d < 0)
        {
            upd<<"x = "<<a<<" +/- "<<b<<"i"<<endl<<endl;
        }
        else
        {
            upd<<"x = "<<a<<endl<<endl;
        }
    }

    int logUnitInput (float m, int u)
    {
        upd<<"At ";
        printTime();
        upd<<endl<<"Converted "<<m<<" ";
        switch(u)
        {
        case 1:
            upd<<"cm"<<endl;
            break;
        case 2:
            upd<<"m"<<endl;
            break;
        case 3:
            upd<<"in"<<endl;
            break;
        case 4:
            upd<<"ft"<<endl;
            break;
        case 5:
            upd<<"yd"<<endl;
            break;
        default:
            upd<<""<<endl;
            break;
        }
    }

    int logUnitResult (float a, float b, float c, float d, float e, int t)
    {
        if (t == 0 || t >5)
        {
            upd<<"Invalid Operation"<<endl<<endl;
        }
        else
        {
            upd<<"Result: "<<a<<" cm, "<<b<<" m, "<<c<<" in, "<<d<<" ft, "<<e<<" yd"<<endl<<endl;
        }

    }

    ~logger()
    {
        upd.close();
    }
};
#endif
