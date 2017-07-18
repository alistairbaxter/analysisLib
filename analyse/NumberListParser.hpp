//
//  NumberListParser.hpp
//  analyse
//
//  Created by Alistair Baxter on 18/07/2017.
//  Copyright © 2017 Alistair Baxter. All rights reserved.
//

#ifndef NumberListParser_hpp
#define NumberListParser_hpp

#include <fstream>
#include "analyse.hpp"

namespace analysis
{
    
    class NumberListParser
    {
    public:
        NumberListParser(std::string filename);
        virtual ~NumberListParser();
        
        /**
         * Has the input file been successfully opened for parsing
         */
        bool isValid();
        
        AnalysisError getNextNumber(int64_t &nextNumber);
        
        bool numbersRemaining();
        
    protected:
        std::ifstream m_inputFile;
    };
    
}

#endif /* NumberListParser_hpp */
