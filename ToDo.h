#include <iostream>
#include <string.h>
#include "Date.h"
#pragma once
class ToDo
{
private:

    int prior;
    Date date;
    std::string tag;
    bool done;
public:

    ToDo();
    ToDo(const ToDo& todo);
    ToDo(int prior, const Date& date, const std::string& tag, bool done);
    ~ToDo();

    //setters
    void 		setPriority	(	int nPriority = 0	);
    void 		setDate		(	const Date& nDate   );
    void 		setTag		(	const std::string& tag );
    void        setDone     (   bool nDone = false);
    //getters
    int			getPriority	();
    Date&       getDate		();
    const std::string& getTag		();
    bool        getDone     ();
    ToDo* operator=(const ToDo& todo);
    bool operator==(const std::string& tag);
};

class ToDoAdapter
{
public:
    ToDoAdapter(ToDo& todo);
    std::string operator()() const;
private:
    std::string represent;
};
