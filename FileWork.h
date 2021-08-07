#include <iostream>
#include <string.h>

#include "ToDoListProxy.h"
#pragma once

/**
1. Сохранить весь лист в файл
2. Загрузить весь лист из файла
3. Меню выбора сохранить или загрузить
4. Меню выбора/ввода имени файла
**/


void saveToFile(ToDoList& mylist,const std::string fileName="");
void loadFromFile(ToDoList& mylist,const std::string fileName="");
void saveLoadListToDo(std::string fileName, ToDoList& mylist);
const std::string& inputFilename(std::string& fileName);
