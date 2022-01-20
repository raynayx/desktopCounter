/*


*/

#include "modelIMU.h"
#include "filter.h"
#include "analyzer.h"

#define DEBUG

CB totalAccel{maxSize}; //raw data from IMU
CB gravityAccel{maxSize}; //lowpassed giving gravity acceleration
CB userAccel{maxSize}; //user acceleration


double dotP[maxSize];     //find dotP(movement in the direction of gravity)
double final[maxSize];

//IMU object
IMU imu;
Filter f;
Analyzer a(final);
int i = 0;
bool first = true;



int main()
{
    while(1)
{  
    imu.fillBuffer(totalAccel);
    f.movingAverage(totalAccel,gravityAccel,WINDOW);
    f.getUserAccel(totalAccel,gravityAccel,userAccel);
    f.dotProduct(userAccel,gravityAccel,dotP);
    f.movingAverage(dotP,final,maxSize,WINDOW);

    cout << a.countSteps() <<"\n";
    // usleep(500000);

    // for(size_t i=0;i<totalAccel.capacity();i++)
    // {
    //     cout << totalAccel[i].x <<"\t"<< totalAccel[i].y << "\t" << totalAccel[i].z << "\n";
    // }

    // for(size_t i=0; i < gravityAccel.capacity();i++)
    // {
    //     cout <<gravityAccel[i].x << "\t"
    //      <<gravityAccel[i].y <<"\t" 
    //      <<gravityAccel[i].z <<"\n";

    //     usleep(1000000); 
    // }

    #ifdef DEBUG
        // Serial.print(i);TAB;
        // Serial.print("x ");
        // Serial.print(totalAccel[i].x);
        //  TAB;
        // Serial.print("y ");
        //  Serial.print(totalAccel[i].y);
        //   TAB;
        // Serial.print("z ");
        //  Serial.println(totalAccel[i].z);
        //  TAB;

        // // Serial.print("||Rx ");
        // Serial.println(smoothed[i].x);
        //  TAB;
        // // Serial.print("y ");
        //  Serial.println(smoothed[i].y);
        //  TAB;
        // // Serial.print("z ");
        //  Serial.print(gravityAccel[i].z);
        //  TAB; 

        // Serial.print("||Ux ");Serial.print(userAccel[i].x); TAB;
        // Serial.print("y "); Serial.print(userAccel[i].y); TAB;
        // Serial.print("z "); 
        // Serial.print(userAccel[i].z);
        // TAB;
        // Serial.print("1-D ");
        // Serial.print(dotP[i],6);
        // TAB;
        // Serial.print(final[i],6);
        // TAB;
        // // Serial.print("Number of Steps\t"); 
        // Serial.println(a.getSteps());

    #endif

}

}

