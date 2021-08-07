#pragma once
#include "ToDoListProxy.h"

/**
Система планирования задач:
1. Создание списка задач+
2. Установка приоритетов задачи+
3. Установка даты выполнения задачи+
4. Удаление задачи+
5. Изменение задачи+
6. Установка тега задачи+
7. Загружать и сохранять в файл список задач
8. Поиск задачи по: дате, тегу, приоритету, и т.д.+
**/

void randAppendToDoList(ToDoList& mylist);
void appendToDoList(ToDoList& mylist);
void setupPriors(ToDoList& mylist);
void setupDates(ToDoList& mylist);
void removeToDo(ToDoList& mylist);
void setupTags(ToDoList& mylist);
void findToDo(ToDoList& mylist);
void userMainMenu();


