//
//  @file NumberListWriter.hpp
//  analyse
//
//  Created by Alistair Baxter on 18/07/2017.
//  Copyright © 2017 Alistair Baxter. All rights reserved.
//

#ifndef NumberListWriter_hpp
#define NumberListWriter_hpp

#include <stdio.h>

#include <fstream>
#include "analyse.hpp"

namespace analysis
{
    
    class NumberListWriter
    {
    public:
        NumberListWriter(std::string filename);
        virtual ~NumberListWriter();
        
        /**
         * Has the output file been successfully opened for parsing
         */
        bool isValid();
        
        AnalysisError writeNumber(int64_t number);
        
    protected:
        std::ofstream m_outputFile;
    };
    
}

#endif /* NumberListWriter_hpp */
