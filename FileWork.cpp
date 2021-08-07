#include "FileWork.h"
#include <fstream>
void saveToFile(ToDoList& mylist,const std::string fileName)
{
    std::ofstream file;
    file.open(fileName);

    if(file.is_open())
    {
        file << mylist;
        file.close();
    }
    else
    {
        file.close();
        throw "Can't open the file" ;
    }
}
void loadFromFile(ToDoList& mylist,const std::string fileName){
    std::ifstream file;
    file.open(fileName);
    printf("\nLoading from %s\n", (fileName));
    if(file.is_open())    {
        file >> mylist;
    }
    else {
        file.close();
        throw "Can't open the file" ;
    }
    file.close();
}
void saveLoadListToDo(std::string fileName, ToDoList& mylist)
{
    int userInputInt = 0;
    if(fileName==""||fileName=="0")    {
        std::cout<< "Enter the file name with full path(\'0\' for skip): ";
        std::cin>> fileName;
    }

    if(fileName==""||fileName=="0")    {
        fileName = "D:\\HOMEWORK\\C++\\PatternsExam\\TESTFile.txt";
    }
    std::cout<< "Enter the method code (1-save to file, 2-load from file): ";
    std::cin>> userInputInt;

    switch(userInputInt)    {
        case 1:
            saveToFile(mylist, fileName);
            break;
        case 2:
            loadFromFile(mylist, fileName);
            break;
        default:
            break;
    }
}
const std::string& inputFilename(std::string& fileName)
{
    std::cout << "Input the file's full name(\'0\' for skip): ";
    std::cin >> fileName;
    return fileName;
}
