#include <iostream>
#include <fstream>
#include "ToDo.h"
#pragma once
class ToDoList
{
    ToDo* arr;
    int listCount;
public:
    ToDoList(	);
    ToDoList				(	const ToDoList& nList	);
    ~ToDoList(	);
    virtual void pushElem	(	ToDo* elem	);
    virtual void popElem	(   );
    virtual void changeElem	(	int index=0			);
    virtual void removeElem	(	int index=0			);
    virtual int  findElem	(	const Date& date, const std::string& tag, int priority = 0, bool done=false	);
    virtual void show		(	);
    virtual bool isEmpty    (   );
    virtual void showElem   (   int index=0         );
    //fstream
    friend std::ifstream& operator >> (std::ifstream& in, ToDoList &self);
    friend std::ofstream& operator << (std::ofstream& out, ToDoList &self);
    //setters
    virtual void setPriority(	int index=0, int nPriority=0	);
    virtual void setDate	(	int index, const Date& nDate  );
    virtual void setTag		(	int index=0, const std::string& nTag="");
    //getters
    virtual int  getListCount        (   );
    virtual int	 getPriority         (	int index=0	);
    virtual const Date& getDate	     (	int index=0	);
    virtual const std::string& getTag(	int index=0	);
    virtual bool  getDone            (  int index=0 );
    virtual const ToDo* getElem	     (	int index=0	);
};



