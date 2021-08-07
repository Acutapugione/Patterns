#include "ToDo.h"
#include <string.h>

ToDoAdapter::ToDoAdapter(ToDo& todo)
            :represent("")
{
    /*После выполнения следующего фрагмента программы строка str содержит one 2 3:
    char str[80];
    sprintf (str, "%s %d %c", "one", 2, '3');*/
    char str[255];
    sprintf(str, "Tag: \'%s\'; Date: %d.%d.%d; Priority: %d; Donerate: %d",
            todo.getTag(),
            todo.getDate().month,
            todo.getDate().day,
            todo.getDate().year,
            todo.getPriority(),
            todo.getDone());
    represent = str;
}
std::string ToDoAdapter::operator()() const{
    return represent;
}
