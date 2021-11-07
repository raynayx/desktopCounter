#ifndef ANALYZER_H_
#define ANALYZER_H_

#include "stepTypes.h"

class Analyzer
{
    public:
        Analyzer(double *d);

        int getSteps(); 
        // void updateSteps(int numberFromSet);
        int countSteps();





    private:
        uint8_t i = 1;
        unsigned long steps;
        bool countStep;
        double *data;
};




#endif