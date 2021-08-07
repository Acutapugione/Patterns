#include <cstring>
#include <string.h>
#include <iostream>
#include "ToDoList.h"
ToDoList::ToDoList()
    :arr(nullptr), listCount(0) {}

ToDoList::ToDoList(const ToDoList& nList )
    :arr(nullptr), listCount(0)
{
    if(&nList)
    {
        this->listCount = nList.listCount;
        this->arr = new ToDo[this->listCount];

        for(int index = 0; index < this->listCount; index++)
        {
            this->arr[index] = nList.arr[index];
        }
    }
}

ToDoList::~ToDoList()
{
    delete[] arr;
}

std::ifstream& operator >> (std::ifstream& in, ToDoList &self)
{
    int listCount = 0;
    int tDay, tMonth, tYear, tPriority, tComplete;
    std::string tTag;
    char buffer[255] = {};

    in >> listCount;
    for(int index = 0; index < listCount; index++)
    {
        in  >> tDay         >> buffer
            >> tMonth       >> buffer
            >> tYear        >> buffer
            >> tPriority    >> buffer
            >> tComplete    >> buffer
            >> tTag;

        ToDo* p = new ToDo(tPriority,
                           Date(tDay, tMonth, tYear),
                           tTag,
                           tComplete);
        self.pushElem(p);
    }
    return in;
}
std::ofstream& operator << (std::ofstream& out, ToDoList& self)
{
    out << self.getListCount() << std::endl;

    for(int index = 0; index < self.getListCount(); index++)
    {
        out  << self.getDate(index).day   <<
             "; " << self.getDate(index).month <<
             "; " << self.getDate(index).year  <<
             "; " << self.getPriority(index)   <<
             "; " << static_cast<bool>(self.getDone(index))<<
             "; " << self.getTag(index)        << "\n";
    }
    std::cout<<"Complete"<<std::endl;

    return out;
}
bool ToDoList::isEmpty()
{
    return this->listCount==0 ? true : false;
}

void ToDoList::pushElem( ToDo* elem )
{
    //1. Проверяем элемент на НУЛЛ
    //2. Делаем временную копию массива
    //3. Перевыделяем память под новый массив
    //4. Заполняем массив
    if(elem!=nullptr)
    {
        ToDo* tempElement = new ToDo(*elem);
        ToDo* tempArr = new ToDo[this->listCount];

        for(int index = 0; index < this->listCount; index++)
        {
            tempArr[index] = this->arr[index];
        }

        delete this->arr;
        this->arr = new ToDo[++this->listCount];

        for(int index = 0; index < this->listCount; index++)
        {
            if(index<this->listCount-1)
                this->arr[index] = tempArr[index];
            else
                this->arr[index] = *tempElement;
        }
    }
}

void ToDoList::changeElem(int index)
{

}

void ToDoList::popElem()
{
    if( this->listCount>0 && this->isEmpty()==false)
    {
        ToDo* temp = new ToDo[this->listCount];
        for(int index = 0; index < this->listCount; index++)
        {
            temp[index] = this->arr[index];
        }
        delete[] this->arr;

        this->arr = new ToDo[--this->listCount];
        for(int index = 0; index < this->listCount; index++)
        {
            this->arr[index]=temp[index];
        }
    }
}

//Удалить элемент массива по индексу
void ToDoList::removeElem(int index)
{

    ToDo* temp = new ToDo[this->listCount-1];
    //Перебираем весь исходный массив
    for(int i = 0; i < this->listCount-1; i++)
    {
        //Если дошли до индекса - берем данные за ним
        if(i>=index)
        {
            temp[i] = this->arr[i+1];
        }
        else
            temp[i] = this->arr[i];
    }
    //Удаляем исходный массив
    delete[] this->arr;
    --this->listCount;
    this->arr = new ToDo[this->listCount];
    //Копируем обратно в исходный массив данные временного
    for(int i = 0; i < this->listCount; i++)
    {
        this->arr[i] = temp[i];
    }

}

int ToDoList::findElem(const Date& date, const std::string& tag, int priority, bool done)
{
    for(int index = 0; index < this->listCount; index++)
    {
        if( this->arr[index].getDate() == date  )
            return index;
        if( this->arr[index].getTag()==tag )
            return index;
        if( this->arr[index].getPriority() == priority   )
            return index;
        if( this->arr[index].getDone() == done )
            return index;
    }
    return -1;
}

void ToDoList::show()
{
    std::cout << std::endl;
    for( int index = 0; index < this->listCount; index++ )
    {
        std::cout << "Bind "
                  << this->arr[index].getDate().day  <<"."
                  << this->arr[index].getDate().month<<"."
                  << this->arr[index].getDate().year <<" day;\tTag: "
                  << this->getTag(index)       <<";\tPriority: "
                  << this->arr[index].getPriority()  <<";\tDonerate: "
                  << (this->arr[index].getDone() ? "is done" : "isn't done") << std::endl;
    }
    std::cout << std::endl;
}
void ToDoList::showElem(int index)
{
    std::cout << std::endl<<"Bind "
              << this->arr[index].getDate().day  <<"."
              << this->arr[index].getDate().month<<"."
              << this->arr[index].getDate().year <<" day;\tTag: "
              << this->getTag(index)       <<";\tPriority: "
              << this->arr[index].getPriority()  <<";\tDonerate: "
              << (this->arr[index].getDone() ? "is done" : "isn't done") << std::endl << std::endl;

}

void ToDoList::setPriority(int index, int nPriority)
{
    this->arr[index].setPriority(nPriority);
}

void ToDoList::setDate(int index, const Date& nDate )
{
    this->arr[index].setDate(nDate);
}

void ToDoList::setTag(int index, const std::string& nTag )
{
    this->arr[index].setTag(nTag);
}

int ToDoList::getPriority(int index)
{
    return (index > 0)&&(index < this->listCount) ? this->arr[index].getPriority() : -1;
}

const Date& ToDoList::getDate(int index)
{
    return this->arr[index].getDate();
}

const std::string&  ToDoList::getTag(int index)
{
    return this->arr[index].getTag();
}

const ToDo* ToDoList::getElem(int index)
{
    return (index > 0)&&(index < this->listCount) ? &this->arr[index]: nullptr;
}

int ToDoList::getListCount()
{
    return this->listCount;
}
bool ToDoList::getDone(int index)
{
    return this->arr[index].getDone();
}
