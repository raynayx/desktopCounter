#include "types.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
class IMU
{
    private:
        ifstream dataFile;
        vector<string> split (const string &s, char delim)
        {
            vector<string> result;
            stringstream ss (s);
            string item;

            while (getline (ss, item, delim))
            {
                result.push_back (item);
            }
            return result;
        }
    
    public:
        IMU()
        {
            dataFile.open("./walking.txt");
            if(!dataFile)
            {
                cout << "file can't be opened\n";
                exit(1);
            }
        }
        ~IMU()
        {
            dataFile.close();
        }
              
        axes getAccelData()
        {
            string temp;
            vector<string>tempv;
            axes A;

            if(dataFile.eof())
            {
                dataFile.clear();
                dataFile.seekg(0,ios::beg);
            }
            getline(dataFile,temp,'\n');
                 
            tempv = split(temp,'\t');

            for(size_t i=0;i<tempv.size();i++)
            {
                if(i==0)
                {
                    A.x = stof(tempv[i]);
                }
                else if(i==1)
                {
                     A.y = stof(tempv[i]);
                }
                else if(i==2)
                {
                    A.z = stof(tempv[i]);
                }
            }         
            return A;
        }


        void fillBuffer(CB &buff)
        {
            if(buff.full())
            {
                buff.push_back(getAccelData());
                return;
            }
            while(!buff.full())
            {
                buff.push_back(getAccelData());
            }
        }

};