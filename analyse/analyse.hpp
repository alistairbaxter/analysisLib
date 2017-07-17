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


enum
{
    Error_InputFileInvalid      = -1,
    Error_ReadError             = -2,
    Error_InvalidNumber         = -3,
    Error_InvalidAnalyis        = -4,
    Error_OutputFileInvalid     = -5,
    Error_WriteError            = -6
};


extern "C"
{
    int analyse(const char * input, const char * output);
}

#pragma GCC visibility pop
#endif
