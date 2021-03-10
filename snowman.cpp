//
// Created by abdms on 08/03/2021.
//


#include <stdexcept>
#include "snowman.hpp"
#include "cmath"
    std::string ariel::snowman(int config)
    {
        std::string code= std::to_string(config);
        if(int(log10(config))+1 != 8) throw std::runtime_error("invalid code "+code);


        /*
         * search through the string if it has any number beyond 4 then it's invalid
         */
        for (size_t i =0; i<code.length(); ++i)
        {
            char c = code[i];
            if(c!='1' && c!='2' && c!='3' && c!='4')
            {
                throw std::runtime_error("invalid code "+code);
            }
        }


        return "INCOMPLETE";
    }


