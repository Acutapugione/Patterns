#include <cstring>
#include <string.h>
#include <iostream>
#include "ToDo.h"

 ToDo::ToDo(int prior, const Date& date, const std::string& tag, bool done)
    : prior(prior), date(date), tag(tag), done(done){
}

 ToDo::ToDo(const ToDo& todo)
    : prior(todo.prior), date(todo.date), tag(todo.tag), done(todo.done){
}

 ToDo::ToDo()
    : prior(1), date(Date(1,1,2000)), tag(""), done(false){
}

 ToDo::~ToDo(){

}
 ToDo* ToDo::operator=(const ToDo& todo)
{
    if(&todo){
        this->tag = todo.tag;
        this->prior = todo.prior;
        this->date = todo.date;
        this->done = todo.done;
    }
    return this;
}

void ToDo::setPriority(int nPriority){
    this->prior = nPriority;
}

void ToDo::setDate(const Date& nDate){
    this->date = nDate;
}

void ToDo::setTag(const std::string& nTag){
    this->tag = nTag;
}
void ToDo::setDone(bool nDone){
    this->done = nDone;
}

bool ToDo::getDone(){
    return this->done;
}

int ToDo::getPriority(){
    return this->prior;
}

Date& ToDo::getDate(){
    return this->date;
}

const std::string& ToDo::getTag(){
    return this->tag;
}


bool ToDo::operator==(const std::string& tag){
    return this->tag==tag ? true : false;
}
