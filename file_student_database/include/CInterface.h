
/**
 * File CInterface.h - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the declaration of CInterface class.
 *
 * Author   : Kiran Bal
 * Version  : 1.0.0
 * Date     : 18-07-2019
 *
 */

#ifndef CINTERFACE_H
#define CINTERFACE_H
#define MAXSTUDENT 20

#include <iostream>
#include <fstream>
#include <conio.h>
#include "CStudentDetails.h"

using namespace std;

/**
* Class CComplex
* simple class to Overload the '+' operator for complex number addition
* Author :Kiran Bal
* Version :1.0.0
* Date :10-07-2019
*
*/

class CInterface
{
    private:
        int nIterate = 0;
        //define array of object;

    public:

        void Title();
        void Manager();
        void UserInterfaceMain();

};

#endif // CINTERFACE_H
