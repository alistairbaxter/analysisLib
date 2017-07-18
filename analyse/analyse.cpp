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
#include "NumberListParser.hpp"
#include "NumberListWriter.hpp"


int analyse(const char * input, const char * output)
{
    //std::cout << "Reading " << input << " and outputting to " << output << std::endl;
    
    // Create a local instance of our analysis class
    analysis::Analyser analyser;

    
    std::string inputFileName = std::string(input);
#if 0
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
#endif
    analysis::NumberListParser inputParser(inputFileName);
    
    if (!inputParser.isValid())
        return analysis::Error_InputFileInvalid;
    
    while(inputParser.numbersRemaining())
    {
        // Convert the line to a whole number
        int64_t newNumber = 0;
        
        analysis::AnalysisError parseError = inputParser.getNextNumber(newNumber);
        
        if(parseError != analysis::Error_NoError)
            return parseError;
        
        // Add the number for analysis
        analyser.addWholeNumber(newNumber);
        
        if (!analyser.isAnalysisValid())
        {
            return analysis::Error_InvalidAnalyis;
        }

    }
    
    // Open the file for writing our resuts to
    std::string outputFileName = std::string(output);
    
    analysis::NumberListWriter resultsWriter(outputFileName);
    
    if (resultsWriter.isValid())
    {
        // Write the count, sum and average to the output file
        analysis::AnalysisError writeResult = resultsWriter.writeNumber(analyser.count());
        if (writeResult != analysis::Error_NoError)
            return writeResult;

        writeResult = resultsWriter.writeNumber(analyser.sum());
        if (writeResult != analysis::Error_NoError)
            return writeResult;

        writeResult = resultsWriter.writeNumber(analyser.average());

        return writeResult; // hopefully Error_Success!
    }
    else
    {
        // We couldn't open the input file
        return analysis::Error_OutputFileInvalid;
    }
}
