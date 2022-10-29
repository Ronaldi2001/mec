/*
* MEC Assignment
* Ronnie Williams
*/

#include "gradebook.hpp"

int main(int argc, char *argv[]) {

  // If the user doesnt provide the database file explain how to use command
  if(argc==1) {
    std::cout << "\nUsage: './gradebook <f_name>'\nArgs:\n";
    std::cout << "  <f_name> - File name of gradebook database (.txt)\n\n";
  }

  // Construct the gradebook
  Gradebook gb;

  // Get the database file name
  std::string f_name = std::string(argv[1]);

  // File extension for database
  std::string ext = std::string(".txt");

  // If the user doesnt provide the correct database file extension
  if(!gb.hasSuffix(f_name, ext)) {

    std::cout << "[ERROR]  Incorrect file extension please use .txt\n";

    // End program
    return 0;
  }

  std::cout << "[INFO]  CSC212 Gradebook is starting...\n";

  // Set the file name to the gradebook database
  gb.setFileName(f_name);

  //Start the gradebook
  gb.run();

  std::cout << "Good bye!!\n";

  // End program
  return 0;
}