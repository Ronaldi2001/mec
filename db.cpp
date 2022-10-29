/*
* MEC Assignment
* Database CPP File
*/

#include "db.hpp"

// ************************************************** Structures ************************************************** //

// Converts the category struct to a string that can be saved to file
std::string GradeCategory::toFile(bool end_line) {

  std::string line = "";
  line += name;
  line += "-";
  line += std::to_string(weight);
  line += ":";
  for(int i=0; i<grades.size(); i++) line += (" " + std::to_string(grades[i]));
  if(end_line) line += "\n";
  return line;
}

// Gets the grade for the category
double GradeCategory::getGrade() {

  double grade = 0;

  // Add each weight to the grade
  for(int i=0; i<grades.size(); i++) grade += grades[i];

  // Return the category grade by dividing by the weight
  return grade/weight;
}

// Gets the sum of all the grades for the category
double GradeCategory::getGradeSum() {

  double sum = 0;

  // Add each grade to the sum
  for(int i=0; i<grades.size(); i++) sum += grades[i];

  // Return the category grade sum
  return sum;
}

// ************************************************** Classes ************************************************** //

// Class constructor
DataBase::DataBase() {}

// Class deconstructor
DataBase::~DataBase() {}

// Checks to see if file has the correct extension
bool DataBase::hasSuffix(std::string &str, std::string &ending) {

  // If the ending checked is larger return false
  // The ending cannot be longer than the actual string being checked
  if(str.length() < ending.length()) return false;
  
  // Subtract the length of the ending from the string to get the starting position
  // to compare the rest of the string to the ending
  // If they are equal then the function equals 0, invert it to make it true
  return !str.compare(str.length()-ending.length(), ending.length(), ending);
}

// Sets the file name for the database
void DataBase::setFileName(std::string &f_name) {

  // Set the file name
  _f_name = f_name;

  // Read the file
  _read();
  return;
}

// Write the file
void DataBase::write() {

  // Open the file to create/write
  std::ofstream file(_f_name);

  // Iterate through the file to get the data
  for(int i=0; i<categories.size(); i++) {
    if(i==categories.size()-1) file << categories[i].toFile(false);
    else file << categories[i].toFile();
  }

  // Close the file 
  file.close();
  return;
}

// Write the file
void DataBase::_create() {

  std::cout << "[INFO]  Creating database file called " << (_f_name) << "\n";

  // Open the file to create/write
  std::ofstream file(_f_name);

  // Create the default category along with the weights
  GradeCategory labs = {"Labs", 50};
  GradeCategory assignments = {"Assignments", 500};
  GradeCategory term_project = {"Term Project", 350};
  GradeCategory rewiew_project = {"Review Project", 30};
  GradeCategory final = {"Final", 100};

  // Create the database file
  file << labs.toFile() << assignments.toFile() << term_project.toFile() << rewiew_project.toFile() << final.toFile(false);

  // Close the file 
  file.close();
  return;
}

// Read the file
void DataBase::_read() {

  // Open the file to read
  std::ifstream file(_f_name);

  if(!file) _create();

  // Iterate over every line in the file
  for(std::string line; getline(file, line);) {

    // Empty category to read from file to
    GradeCategory cat;

    //Find key spots to break up the line by delimeters
    int d1 = line.find("-"), d2 = line.find(":");

    // Get the category name and weight
    cat.name = line.substr(0, d1);
    cat.weight = std::stoi(line.substr(d1+1, d2-d1-1));

    // Read char by char till whitespace then conver to double
    std::string num = "";

    // Get all the grades seperated by whitespace after name and weight
    for(unsigned int i=line.find(":")+2; i<line.size(); i++) {

      // Get the single char at pos i
      char c = line[i];

      // Check if the number has ended
      if(c==' ') {

        // Change num to an int then add it to the img vector
        cat.grades.push_back(std::stod(num));

        // Reset num for the next number to be read
        num = "";
        continue;
      }

      // Add the char to the end of num
      num.push_back(c);

      // Change num to an int then add it to the img vector before next iteration of the loop
      if(i+1==line.size()) {
        cat.grades.push_back(std::stod(num));
      }
    }
    // Add the grade category to the category vector
    categories.push_back(cat);
  }

  // Close the file 
  file.close();
  return;
}