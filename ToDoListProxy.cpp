#include "ToDoListProxy.h"
#include <exception>

ToDoListProxy::ToDoListProxy()
    :ToDoList(), pwd(100), userPwd(0), nullStr("#NullString"), nullDate(Date(1, 1, 1991))
{
    tryToAutorize();
}

bool ToDoListProxy::isAutorized()
{
    if(this->pwd == this->userPwd)
        return true;
    return false;
}

void ToDoListProxy::tryToAutorize()
{
    do
    {
        int inputInt=0;
        try
        {
            std::cout << "Please, enter the valid password: ";
            std::cin >> inputInt;
            this->userPwd = static_cast<unsigned>(inputInt);
            if(this->userPwd==0)
            {
                std::cin.clear();
                throw "Input exception was called";
            }

        }
        catch(std::exception& except)
        {
            std::cerr << "catched: " <<except.what();
            throw except;
        }
        catch(...)
        {
            std::cerr << "catched: ..." <<std::endl ;
            throw ("Unknown exception!!!");
        }
    }
    while(!isAutorized());
}
bool ToDoListProxy::isValidData(const Date& nDate)
{
    if(  nDate.day<=0 || nDate.day>31 || nDate.month<=0 || nDate.month>12 || nDate.year<=1900 || nDate.year>2200 )
        return false;
    return true;
}

void ToDoListProxy::pushElem(ToDo* elem)
{
    if(elem)
    {
        if(elem->getTag()==" ")
            elem->setTag(nullStr);
        if ( !isValidData(elem->getDate()) )
            elem->setDate(this->nullDate);
        ToDoList::pushElem(elem);
    }
    else
        std::cout << "Current element wasn't append to list!!!";
}

void ToDoListProxy::popElem()
{
    if(ToDoList::getListCount()>0)
        ToDoList::popElem();
    else
        std::cout << "You can't remove elements from current list!!!";
}

void ToDoListProxy::changeElem(int index)
{
    if( index >= 0 && index < ToDoList::getListCount() && ToDoList::isEmpty() == false )
    {
        ToDoList::changeElem(index);
    }
    else
        std::cout << "You can't change this element from current list!!!";
}

void ToDoListProxy::removeElem(int index)
{
    if( index >= 0 && index < ToDoList::getListCount() && ToDoList::isEmpty() == false )
        ToDoList::removeElem(index);
    else
        std::cout << "You can't remove this element from current list!!!";
}



void ToDoListProxy::showElem(int index)
{
    if( index >= 0 && index < ToDoList::getListCount() && ToDoList::isEmpty() == false )
        ToDoList::showElem(index);
}

void ToDoListProxy::setPriority(int index, int nPriority)
{
    if( index >= 0 && index < ToDoList::getListCount() && ToDoList::isEmpty() == false)
        if ( nPriority >= 0 && nPriority <=1000 )
            ToDoList::setPriority(index, nPriority);
        else
            std::cout<<"Log: incorrect parameter \'priority\' by calling method setPriority(int, int);";
    else
        std::cout<<"Log: incorrect parameter \'index\' by calling method setPriority(int, int);";
}

void ToDoListProxy::setDate(int index, const Date& nDate)
{
    if( index >= 0 && index < ToDoList::getListCount() && ToDoList::isEmpty() == false )
        if ( nDate.day>0&&nDate.day<=31&&
                nDate.month>0&&nDate.month<=12&&
                nDate.year>1900&&nDate.year<=2200)
            ToDoList::setDate(index, nDate);
        else
        {
            ToDoList::setDate(index, nullDate);
            std::cout<<"Log: incorrect parameter \'date\' by calling method setDate(int, const Date&);";
        }

    else
        std::cout<<"Log: incorrect parameter \'index\' by calling method setDate(int, const Date&);";
}

void ToDoListProxy::setTag(int index, const std::string& nTag)
{
    if( index >= 0 && index < ToDoList::getListCount() && ToDoList::isEmpty() == false )
        if( nTag != "" )
            ToDoList::setTag(index, nTag);
        else
        {
            ToDoList::setTag(index, nullStr);
            std::cout<<"Log: incorrect parameter \'tag\' by calling method setTag(int, const std::string& )";
        }
    else
        std::cout<<"Log: incorrect parameter \'index\' by calling method setTag(int, const std::string& )";
}

int ToDoListProxy::getPriority(int index)
{
    if( index >= 0 && index < ToDoList::getListCount() && ToDoList::isEmpty() == false )
        return ToDoList::getPriority(index);
    std::cout<<"Log: incorrect parameter \'index\' by calling method getPriority(int)";
    return 0;
}

const Date& ToDoListProxy::getDate(int index)
{
    if( index >= 0 && index < ToDoList::getListCount() && ToDoList::isEmpty() == false )
        return ToDoList::getDate(index);
    std::cout<<"Log: incorrect parameter \'index\' by calling method getDate(int)";
    return this->nullDate;
}

const std::string& ToDoListProxy::getTag(int index)
{
    if( index >= 0 && index < ToDoList::getListCount() && ToDoList::isEmpty() == false )
        return ToDoList::getTag(index);
    std::cout<<"Log: incorrect parameter \'index\' by calling method getTag(int)";
    return this->nullStr;
}

const ToDo* ToDoListProxy::getElem(int index)
{
    if( index >= 0 && index < ToDoList::getListCount() && ToDoList::isEmpty() == false )
        return ToDoList::getElem(index);
    std::cout<<"Log: incorrect parameter \'index\' by calling method getElem(int)";
    return nullptr;
}
bool ToDoListProxy::getDone(int index)
{
    if( index >= 0 && index < ToDoList::getListCount() && ToDoList::isEmpty() == false )
        return ToDoList::getDone(index);
    std::cout<<"Log: incorrect parameter \'index\' by calling method getElem(int)";
    return false;
}
