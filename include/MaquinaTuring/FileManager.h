#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <stdexcept>
#include <iostream>
#include <fstream>

using namespace std;

class FileManager
{

    public:
        int GetCharOcurrenceCount(char pCharacter, string pLine){
            int res = 0;

            for(unsigned int index = 0; index < pLine.size(); index++){

                if(pLine[index] == pCharacter){

                    res++;
                }
            }
            return res;
        }



        string* StringSplit(char pCharacter, string pLine){
            int arraySize = GetCharOcurrenceCount(pCharacter, pLine)+1;

            string* result = new string[arraySize];


            int spotIndex = 0;
            for(int index = 0; index < pLine.size(); index++){

                if(pLine[index] != pCharacter){

                    result[spotIndex] += pLine[index];

                }
                else{
                    spotIndex++;
                }
            }

            return result;
        }



};

#endif // FILEMANAGER
