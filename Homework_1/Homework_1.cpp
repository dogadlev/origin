// Read arrays from the file. Output data to the file.

#include <iostream>
#include <fstream>


int main(int argc, char** argv)
{
    
    std::ifstream fileInput("in.txt");

    if (fileInput.is_open()) //Check if a file exists
    {
        int arrSizeN = 0, arrSizeM=0;
        
        fileInput >> arrSizeN; //Read size of the N array from the in.txt 

        int* arrN = new int[arrSizeN]; //Allocate memory for array N

        for (int i = 0; i < arrSizeN; ++i) //Read data from the in.txt. Fill array N with values
        {
            fileInput >> arrN[i];
        }

        fileInput >> arrSizeM; //Read size of the M array from the in.txt

        int* arrM = new int[arrSizeM]; //Allocate memory for array M

        for (int i = 0; i < arrSizeM; ++i)
        {
            fileInput >> arrM[i];
        }

        fileInput.close(); //Close in.txt

        std::ofstream fileOutput("out.txt");

        fileOutput << arrSizeM << std::endl; //Write data from the array M to the out.txt
        fileOutput << arrM[arrSizeM - 1] << " ";
        for (int i = 0; i < arrSizeM - 1; ++i)
        {
            fileOutput << arrM[i] << " ";
        }
        fileOutput << std::endl;

        delete[] arrM; //Deallocate memory used for array M
         
        fileOutput << arrSizeN << std::endl; //Write data from the array N to the out.txt
        for (int i = 1; i < arrSizeN; ++i)
        {
            fileOutput << arrN[i] << " ";
        }
        fileOutput << arrN[0];   
        
        delete[] arrN; //Deallocate memory used for array N       
    }
    else 
    {
        std::cout << "File could not be found. Check the path.";
    }

    return 0;
}