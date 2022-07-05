//Homework 1. Task 1. Read arrays from the file. Output data to the file.

#include <iostream>
#include <fstream>

void readArray(std::ifstream &fileInput, int arrSize, int* arr)
{
    for (int i = 0; i < arrSize; ++i)
    {
        fileInput >> arr[i];
    }
}

void printArrayM(std::ofstream& fileOutput, int arrSize, int* arr)
{
        fileOutput << arrSize << std::endl << arr[arrSize-1] << " ";
        for (int i = 0; i < arrSize-1; ++i)
        {
            fileOutput << arr[i] << " ";
        }
        fileOutput << std::endl;
}

void printArrayN(std::ofstream& fileOutput, int arrSize, int* arr)
{
    fileOutput << arrSize << std::endl;
    for (int i = 1; i < arrSize; ++i)
    {
        fileOutput << arr[i] << " ";
    }
    fileOutput << arr[0] << std::endl;
}

int main(int argc, char** argv)
{
    std::ifstream fileInput("in.txt");

    if (fileInput.is_open()) 
    {
        int arrSizeN = 0, arrSizeM = 0;
        
        fileInput >> arrSizeN;  
        int* arrN = new int[arrSizeN]; 
        readArray(fileInput, arrSizeN, arrN);

        fileInput >> arrSizeM;  
        int* arrM = new int[arrSizeM];
        readArray(fileInput, arrSizeM, arrM);

        fileInput.close();

        std::ofstream fileOutput("out.txt");
        
        printArrayM(fileOutput, arrSizeM, arrM);
        printArrayN(fileOutput, arrSizeN, arrN);

        delete[] arrN;
        delete[] arrM;

        fileOutput.close();

        return 0;
    }
    else 
    {
        std::cout << "File could not be found. Check the path.";
        return 1;
    }
}