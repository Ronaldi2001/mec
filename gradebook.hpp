/*
* MEC Assignment
* Gradebook Header File
*/

#pragma once

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "db.hpp"


// Represents a CSC212 gradebook with weights
class Gradebook: public DataBase {

  public:
    Gradebook();
    ~Gradebook();
    void run();

  private:
    void _view();
    void _enter();
    void _update();
    void _classGrade();
};