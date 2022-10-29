/*
* MEC Assignment
* Gradebook CPP File
*/

#include "gradebook.hpp"

// Class constructor
Gradebook::Gradebook() {}

// Class deconstructor
Gradebook::~Gradebook() {}

// Runs the gradebook app loop
void Gradebook::run() {

  // Get a command
  while(true) {

    std::cout << "Enter number corresponding to the command:\n";
    std::cout << "--------------------\n";
    std::cout << "1  View grade\n";
    std::cout << "2  Enter grade\n";
    std::cout << "3  Update grade\n";
    std::cout << "4  Quit\n";
    std::cout << "--------------------\nCommand number: ";

    int num;

    // Get the command number
    std::cin >> num;

    // Do the command
    switch(num) {
      case 1:
        _view();
        break;
      case 2:
        _enter();
        break;
      case 3:
        _update();
        break;
      case 4:
        return;
      default:
        std::cout << "[ERROR]  Invalid command, try again...\n";
    }
  }
  return;
}

// Views the categories of the gradebook then the specific grade
void Gradebook::_view() {

  int num;

  // Get the category to view
  while(true) {

    std::cout << "Enter number corresponding to the category:\n";
    std::cout << "--------------------\n";
    for(int i=1; i<=categories.size(); i++) std::cout << i << "  " << categories[i-1].name << "\n";
    std::cout << std::to_string(categories.size()+1) << "  Class final grade\n";
    std::cout << "--------------------\nCategory number: ";

    std::cin >> num;

    // Get the final class grade for all categories
    if(num==categories.size()+1) {

      _classGrade();
      return;
    }

    // If the wrong number was entered, try again
    if(num>categories.size()+1) {

      std::cout << "[ERROR] Invalid categoty, try again...\n";
      continue;
    }

    break;
  }

  // If the category has no grades to calculate
  if(categories[num-1].grades.size()==0) {
    std::cout << "[ERROR]  There are no grades in this category...\n";
    return;
  }

  // Calculate the grade for the category
  std::cout << "Grade: " << categories[num-1].getGrade()*100 << "%\n";
  return;
}

// Add a grade to the category in the gradebook
void Gradebook::_enter() {

  int num;

  // Get the category to add the grade too
  while(true) {

    std::cout << "Enter number corresponding to the category:\n";
    std::cout << "--------------------\n";
    for(int i=1; i<=categories.size(); i++) std::cout << i << "  " << categories[i-1].name << "\n";
    std::cout << "--------------------\nCategory number: ";

    std::cin >> num;

    // if the wrong category was entered, try again
    if(num>categories.size()) {

      std::cout << "[ERROR] Invalid categoty, try again...\n";
      continue;
    }

    break;
  }

  std::cout << "Enter grade: ";

  double grade;

  // Get the grade for the category
  std::cin >> grade;
  std::cout << "\n";

  // Add the grade to the category
  categories[num-1].grades.push_back(grade);

  // Save to file
  write();
  return;
}

// Updates a certain grade in a category
void Gradebook::_update() {

  int cat;

  // Get the category to update the grade in
  while(true) {

    std::cout << "Enter number corresponding to the category:\n";
    std::cout << "--------------------\n";
    for(int i=1; i<=categories.size(); i++) std::cout << i << "  " << categories[i-1].name << "\n";
    std::cout << "--------------------\nCategory number: ";

    std::cin >> cat;

    // if the wrong category was entered, try again
    if(cat>categories.size()) {
      std::cout << "[ERROR] Invalid categoty, try again...\n";
      continue;
    }

    break;
  }

  int assign;

  // If there are no grades to update
  if(categories[cat].grades.size()==0) {
    std::cout << "[ERROR]  There are no grades in this category to update...\n";
    return;
  }

  // Get the assignments to update one
  while(true) {

    std::cout << "Enter number corresponding to the Assignment:\n";
    std::cout << "--------------------\n";
    for(int i=1; i<=categories[cat].grades.size(); i++) std::cout << i << "  " << categories[cat].grades[i-1] << "\n";
    std::cout << "--------------------\nAssignment number: ";

    std::cin >> assign;

    // if the wrong assignment was entered, try again
    if(assign>categories[cat].grades.size()) {
      std::cout << "[ERROR] Invalid assignment, try again...\n";
      continue;
    }

    break;
  }

  std::cout << "Enter new grade: ";

  double grade;

  // Get the new grade
  std::cin >> grade;

  // Update the new grade
  categories[cat].grades[assign] = grade;

  // Save to file
  write();
  return;
}

// Get the final class grade with all categories
void Gradebook::_classGrade() {

  int sum_weights = 0;
  long double sum_grades = 0;

  // Iterate over every category and sum up the weights and grades
  for(int i=0; i<categories.size(); i++) {
    sum_weights += categories[i].weight;
    sum_grades += categories[i].getGradeSum();
  }

  // Divide the grades by weights to get the final grade
  std::cout << "Class Grade: " << ((sum_grades/sum_weights)*100) << "%\n\n";
  return;
}