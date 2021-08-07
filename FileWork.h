#include <iostream>
#include <string.h>

#include "ToDoListProxy.h"
#pragma once

/**
1. ��������� ���� ���� � ����
2. ��������� ���� ���� �� �����
3. ���� ������ ��������� ��� ���������
4. ���� ������/����� ����� �����
**/


void saveToFile(ToDoList& mylist,const std::string fileName="");
void loadFromFile(ToDoList& mylist,const std::string fileName="");
void saveLoadListToDo(std::string fileName, ToDoList& mylist);
const std::string& inputFilename(std::string& fileName);
