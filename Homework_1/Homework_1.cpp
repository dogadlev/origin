// Read arrays from the file. Output data to the file.

#include <iostream>
#include <fstream>

void readArray(std::ifstream &fileInput, int arrSize, int* arr)
{
    for (int i = 0; i < arrSize; ++i)
    {
        fileInput >> arr[i];
    }
}

void mixArray(int arrSize, int* arr)
{
    if (arr[0] % 10 == 0)
    {
        int tmp = arr[0];

        for (int i = arrSize - 1; i > 0; --i)
        {
            if (arr[i] > arr[i - 1])
            {
                tmp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = tmp;
            }
        }
    }
    else
    {
        int tmp = arr[0];

        for (int i = 0; i < arrSize; ++i)
        {
            if (arr[i] < arr[i + 1])
            {
                tmp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = tmp;
            }
        }
    }
}

void printArray(std::ofstream& fileOutput, int arrSize, int* arr)
{
        fileOutput << arrSize << std::endl;
        for (int i = 0; i < arrSize; ++i)
        {
            fileOutput << arr[i] << " ";
        }
        fileOutput << std::endl;
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

        mixArray(arrSizeN, arrN);
        mixArray(arrSizeM, arrM);

        std::ofstream fileOutput("out.txt");
        
        printArray(fileOutput, arrSizeM, arrM);
        printArray(fileOutput, arrSizeN, arrN);

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