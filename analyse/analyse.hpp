/*
 * @file analyse.hpp
 * Main Header for Analysis Library
 *
 *  Created by Alistair Baxter on 17/07/2017.
 *  Copyright © 2017 Alistair Baxter. All rights reserved.
 *
 */

#ifndef analyse_
#define analyse_

/* The classes below are exported */
#pragma GCC visibility push(default)

namespace analysis
{
    
/**
 * \enum AnalysisError
 * \brief specifies the available DCCP packet types
 */
enum
{
    Error_NoError               =  0, /**< No error, function was successful */
    Error_InputFileInvalid      = -1, /**< An error occurred when trying to open the input file */
    Error_ReadError             = -2, /**< An error occurred when reading from the input file */
    Error_InvalidNumber         = -3, /**< The input file contained a line which was not a whole number */
    Error_InvalidAnalyis        = -4, /**< The list of numbers was not valid for analysis */
    Error_OutputFileInvalid     = -5, /**< There was a problem when opening the output file */
    Error_WriteError            = -6  /**< There was a problem when writing to the output file */
} AnalysisError;

}

extern "C"
{
    /**
     * Determine whether the numbers are valid for analysis.
     *
     * If there has been a maths overflow during summation,
     * or if a number could not be added to the list, or the
     * list is empty, then it will not be considered valid.
     *
     * @return Zero for success, or a negative number if an error occurred, corresponding to
     *
     */
    int analyse(const char * input, const char * output);
}

#pragma GCC visibility pop
#endif
