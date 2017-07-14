/*
 *  analyse.hpp
 *  analyse
 *
 *  Created by Alistair Baxter on 14/07/2017.
 *  Copyright © 2017 Alistair Baxter. All rights reserved.
 *
 */

#ifndef analyse_
#define analyse_

/* The classes below are exported */
#pragma GCC visibility push(default)

extern "C"
{
    int analyse(const char * input, const char * output);
}

#pragma GCC visibility pop
#endif
