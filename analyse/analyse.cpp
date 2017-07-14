/*
 *  analyse.cpp
 *  analyse
 *
 *  Created by Alistair Baxter on 14/07/2017.
 *  Copyright © 2017 Alistair Baxter. All rights reserved.
 *
 */

#include <iostream>
#include "analyse.hpp"
#include "analysePriv.hpp"

void analyse::HelloWorld(const char * s)
{
    analysePriv *theObj = new analysePriv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void analysePriv::HelloWorldPriv(const char * s) 
{
    std::cout << s << std::endl;
};

