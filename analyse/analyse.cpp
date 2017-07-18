/*
 *  analyse.cpp
 *  analyse
 *
 *  Created by Alistair Baxter on 17/07/2017.
 *  Copyright © 2017 Alistair Baxter. All rights reserved.
 *
 */

#include <string>
#include <iostream>
#include <fstream>

#include "analyse.hpp"
#include "Analyser.hpp"


int analyse(const char * input, const char * output)
{
    //std::cout << "Reading " << input << " and outputting to " << output << std::endl;
    
    // Create a local instance of our analysis class
    analysis::Analyser analyser;
    
    std::string inputFileName = std::string(input);
    std::ifstream inputFile( inputFileName );
    
    if (inputFile.is_open())
    {
        // Read a line
        std::string line;
        while ( getline (inputFile,line) )
        {
            if (inputFile.good())
            {
                //std::cout << line << '\n';
                
                //check if the string represents a valid number
                for (char currChar : line)
                {
                    if (currChar != '-' && currChar != ' ')
                    {
                        if (currChar < '0' || currChar > '9')
                        {
                            inputFile.close();
                            return analysis::Error_InvalidNumber;
                        }
                    }
                }
                
                // Convert the line to a whole number
                int64_t newNumber = atoll(line.c_str());
                
                // Add the number for analysis
                analyser.addWholeNumber(newNumber);
                
                if (!analyser.isAnalysisValid())
                {
                    inputFile.close();
                    return analysis::Error_InvalidAnalyis;
                }
            }
            else
            {
                // Something went wrong while reading
                inputFile.close();
                return analysis::Error_ReadError;
            }
        }
        inputFile.close();
    }
    else
    {
        // We couldn't open the input file
        return analysis::Error_InputFileInvalid;
    }
    
    // Open the file for writing our resuts to
    std::string outputFileName = std::string(output);
    std::ofstream outputFile( outputFileName );
    
    if (outputFile.is_open())
    {
        // rite the count, sum and average to the output file
        outputFile << analyser.count() << std::endl;
        outputFile << analyser.sum() << std::endl;
        outputFile << analyser.average() << std::endl;
        
        
        // Success!
        if (outputFile.good())
        {
            outputFile.close();
            return 0;
        }
        else
        {
            outputFile.close();
            return analysis::Error_WriteError;
        }
    }
    else
    {
        // We couldn't open the input file
        return analysis::Error_OutputFileInvalid;
    }
}
