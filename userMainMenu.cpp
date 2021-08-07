#include <iostream>
#include <string.h>
#include "userMainMenu.h"
#include "FileWork.h"
void randAppendToDoList(ToDoList& mylist)
{
    int userInputInt;
    std::cout<< "Input count of ToDo\'s to add: ";
    std::cin>> userInputInt;
    for( int i = 0; i < userInputInt; i++ )
    {
        ToDo* p = new ToDo(rand()%100+1, Date(rand()%30+1, rand()%11+1, rand()%2000+1000), "#WFLife", rand()%1);
        mylist.pushElem(p);
    }
    mylist.show();
}

void appendToDoList(ToDoList& mylist)
{

    int userInputInt;
    int nDay, nMonth, nYear, nPrior, nComplete;
    char* nTag = new char[255];
    bool isComplete;
    std::cout<< "Input count of ToDo\'s to add: ";
    std::cin>> userInputInt;

    for( int i = 0; i < userInputInt; i++ )
    {
        isComplete = false;

        std::cout<<std::endl<<"Input tag text of current ToDo\'s: ";
        std::cin>>nTag;

        std::cout<<std::endl<< "Input date in local format day//month//year: ";
        std::cin>> nDay>> nMonth>> nYear;

        std::cout<<std::endl<< "Input priority in decimal number: ";
        std::cin>> nPrior;

        std::cout<<std::endl<< "Input \'1\' if that ToDo\'s is complete or \'0\' if it\'s not: ";
        std::cin>> nComplete;

        if(nComplete==1)
            isComplete = true;

        ToDo* p = new ToDo(nPrior, Date(nDay, nMonth, nYear), nTag, isComplete);
        mylist.pushElem(p);
    }

    mylist.show();
    delete[] nTag;
}

void setupPriors(ToDoList& mylist)
{

    int userInputInt;
    int priority;
    bool isRetry;
    do
    {
        isRetry = false;
        std::cout<< "Input the same ToDo\'s number to setup priority: ";
        std::cin>> userInputInt;
        std::cout<< "Input priority number: ";
        std::cin>> priority;

        mylist.setPriority(userInputInt-1, priority);

        std::cout<< "Do you want to do this with other elements? :(0-false, 1-true)";
        std::cin>> userInputInt;
        if(userInputInt!=0)
            isRetry = true;

    }
    while(isRetry);

    mylist.show();
}

void setupDates(ToDoList& mylist)
{
    int userInputInt;
    int tDay, tMonth, tYear;
    bool isRetry;
    do
    {
        isRetry = false;
        std::cout<< "Input the same ToDo\'s number to setup date: ";
        std::cin>> userInputInt;
        std::cout<< "Input date in local format day//month//year: ";
        std::cin>> tDay>> tMonth>> tYear;

        mylist.setDate(userInputInt-1, Date(tDay,tMonth,tYear));
        mylist.show();

        std::cout<< "Do you want to do this with other elements? :(0-false, 1-true)";
        std::cin>> userInputInt;
        if(userInputInt!=0)
            isRetry = true;

    }
    while(isRetry);


}

void removeToDo(ToDoList& mylist)
{

    int userInputInt;
    bool isRetry;
    do
    {
        isRetry = false;

        std::cout<<"Input the same elem number to removing: ";
        std::cin>> userInputInt;

        mylist.removeElem(userInputInt-1);
        mylist.show();

        std::cout<< "Do you want to do this again? :(0-false, 1-true)";
        std::cin>> userInputInt;
        if(userInputInt!=0)
            isRetry = true;

    }
    while(isRetry);
}

void setupTags(ToDoList& mylist)
{
    int userInputInt;
    bool isRetry;
    char* nTag = new char[255];

    do
    {
        isRetry = false;

        std::cout<<"Input the same elem number to setup new tag: ";
        std::cin>> userInputInt;

        std::cout<<std::endl<<"Input tag text of current ToDo\'s: ";
        std::cin>>nTag;

        mylist.setTag(userInputInt-1, nTag);
        mylist.show();

        std::cout<< "Do you want to do this with other elements? :(0-false, 1-true)";
        std::cin>> userInputInt;
        if(userInputInt!=0)
            isRetry = true;

    }
    while(isRetry);

    delete[] nTag;
}

void findToDo(ToDoList& mylist) //8. Поиск задачи по: дате, тегу, приоритету, и т.д.+
{
    int userInputInt;
    int nDay, nMonth, nYear, nPrior, nComplete;
    char* nTag = new char[255];
    bool isRetry, isComplete=false;

    do
    {
        isRetry = false;
        std::cout<< "Enter the date in local format dd/mm/YYYY :";
        std::cin>> nDay>>nMonth>> nYear;

        std::cout<< "Enter the tag: ";
        std::cin>> nTag;

        std::cout<< "Enter the priority: ";
        std::cin>> nPrior;

        std::cout<< "Enter the complete(1-true, 0-false): ";
        std::cin>> nComplete;
        if(nComplete==1)
            isComplete = true;

        mylist.showElem(mylist.findElem(Date(nDay, nMonth, nYear), nTag, nPrior, isComplete));

        std::cout<< "Do you want to do this again? :(0-false, 1-true)";
        std::cin>> userInputInt;
        if(userInputInt!=0)
            isRetry = true;

    }
    while(isRetry);
}

void userMainMenu()
{

    ToDoListProxy mylist;
    int userInputInt;
    std::string fileName = "";
    fileName=inputFilename(fileName);

    do
    {
        std::cout<<"Main menu."<<std::endl;
        std::cout<<"1. Append to list some ToDo\'s"<<std::endl;
        std::cout<<"2. Setup priors in current list"<<std::endl;
        std::cout<<"3. Setup dates in current list"<<std::endl;
        std::cout<<"4. Remove ToDo\'s from current list"<<std::endl;
        std::cout<<"5. Setup tags of ToDo\'s in current list"<<std::endl;
        std::cout<<"6. Save current list\\Load in current list"<<std::endl;
        std::cout<<"7. Find ToDo\'s in current list"<<std::endl;
        std::cout<<"8. Append to list rand ToDo\'s"<<std::endl;
        std::cout<<"9. Show list"<<std::endl;
        std::cout<<"0. Exit"<<std::endl;


        std::cin>> userInputInt;

        switch(userInputInt)
        {
        case 1:        //1. Создание списка задач++
            appendToDoList(mylist);
            break;
        case 2:        //2. Установка приоритетов задачи++
            setupPriors(mylist);
            break;
        case 3:        //3. Установка даты выполнения задачи++
            setupDates(mylist);
            break;
        case 4:        //4. Удаление задачи++
            removeToDo(mylist);
            break;
        case 5:        //6. Установка тега задачи+
            setupTags(mylist);
            break;
        case 6:        //7. Загружать и сохранять в файл список задач
            saveLoadListToDo(fileName, mylist);
            break;
        case 7:        //8. Поиск задачи по: дате, тегу, приоритету, и т.д.+
            findToDo(mylist);
            break;
        case 8:        //8. Заполнить случайно
            randAppendToDoList(mylist);
            break;
        case 9:        //8. Заполнить случайно
            mylist.show();
            break;
        default:
            mylist.show();
            break;
        }

    }
    while(userInputInt>0&&userInputInt<10);
}
