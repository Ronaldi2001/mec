/*
* MEC Assignment
* Database Header File
*/

#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Represent a grade category with its attributes
struct GradeCategory {

  std::string name;
  int weight;
  std::vector<double> grades;

  std::string toFile(bool end_line=true);
  double getGrade();
  double getGradeSum();
};

// Represent a database interacting with the file system
class DataBase {

  public:
    DataBase();
    ~DataBase();
    bool hasSuffix(std::string &str, std::string &ending);
    void setFileName(std::string &f_name);
    void write();
    std::vector<GradeCategory> categories;

  private:
    void _create();
    void _read();
    std::string _f_name;
};