#include <iostream>
#include <string.h>
#include "ToDoList.h"
#pragma once
class ToDoListProxy: public ToDoList{
private:

    unsigned pwd;
    unsigned userPwd;
    std::string nullStr;
    Date nullDate;
public:
    //self
    ToDoListProxy();
    bool isAutorized();
    void tryToAutorize();
    bool isValidData        (   const Date& nDate   );
    //override
    virtual void pushElem	(	ToDo* elem      )override;
    virtual void popElem	(   )                override;
    virtual void changeElem	(	int index=0		)override;
    virtual void removeElem	(	int index=0		)override;

    virtual void showElem   (   int index=0     )override;
    //setters
    virtual void setPriority(	int index=0,
                                int nPriority=0) override;
    virtual void setDate	(	int index,
                                const Date& nDate)override;
    virtual void setTag		(	int index=0,
                                const std::string& nTag="")override;
    //getters
    virtual int	 getPriority         (	int index=0	)override;
    virtual const Date& getDate	     (	int index=0	)override;
    virtual const std::string& getTag(	int index=0	)override;
    virtual bool  getDone            (  int index=0 )override;
    virtual const ToDo* getElem	     (	int index=0	)override;

};
