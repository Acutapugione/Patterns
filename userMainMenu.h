#pragma once
#include "ToDoListProxy.h"

/**
������� ������������ �����:
1. �������� ������ �����+
2. ��������� ����������� ������+
3. ��������� ���� ���������� ������+
4. �������� ������+
5. ��������� ������+
6. ��������� ���� ������+
7. ��������� � ��������� � ���� ������ �����
8. ����� ������ ��: ����, ����, ����������, � �.�.+
**/

void randAppendToDoList(ToDoList& mylist);
void appendToDoList(ToDoList& mylist);
void setupPriors(ToDoList& mylist);
void setupDates(ToDoList& mylist);
void removeToDo(ToDoList& mylist);
void setupTags(ToDoList& mylist);
void findToDo(ToDoList& mylist);
void userMainMenu();


