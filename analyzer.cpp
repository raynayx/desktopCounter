#include "analyzer.h"


Analyzer::Analyzer(double *d)
{
 steps = 0;  
 countStep = true; 
 data = d;
}

int Analyzer::getSteps()
{
    return steps;
}

// void Analyzer::updateSteps(int numberFromSet)
// {
//     steps += numberFromSet;
// }

int Analyzer::countSteps()
{
    for(; i <= maxSize; i++)
    {
        int cur = i%maxSize;
        int prev = (i-1)%maxSize;
    if((data[cur] >= THRESHOLD) && (data[prev]) < THRESHOLD)
    {
        if(!countStep)
            continue;       
        steps++;
        countStep = false;
        return steps;
    }
    if((data[cur] < 0) && (data[prev] >= 0))
        countStep = true;

        
    }
    return steps;
}