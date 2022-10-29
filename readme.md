# CSC212 MEC Project

Ronnie Williams

## Project Summary
This project allows CSC212 students to have an interactive command line application to view, enter, and update grades. This gradebook saves the data to the file system to allow the student to edit the application throughout the year with their grades!

<br>

## Proof of Planning
```text

open previous data file or create file

while running:
  input for a command:
    do command based on input
  if quit command, quit

command view:
  input for category to view
    display grade

command enter:
  input for category to enter grade into
    input for grade

command update:
  input for category to update
    input for grade to update
      input for new grade
```

<br>

## Features:
The application takes integers as inputs for the command selection and double for the grade input.

The outputs of the program are shown in the console and can be seen in the txt file where all the data is saved for the next time the student wants to check their grade.

When viewing grades you can view each categories individual grade or the class final grade. When the student enters grades they select the category and it will save the grade. If a student messes up or gets a re-grade the option to update grades is available too! Once a student finishes a command the application will keep asking for more commands until you quit the program.

This way of handling the data is important because if a student wants to check their grade if a grade gets released then they dont have to enter in all their grades again and again.

<br>

## Usage:

To compile the application run:
```bash
$ g++ -std=c++11 -Wall main.cpp gradebook.cpp db.cpp -o gradebook
```
***OR***
```bash
$ make
```
<br>
To start the application run:

```bash
$ ./gradebook <f_name>.txt
```
>When inputting the filename the file does not have to exist, the application will create it!

***OR***
```bash
$ make run
```
>This will use "data/test1.txt"

<br>
Once the application is running the student will be promped with command requiring them to enter the number corresponding to the command. Once a command is entered depending on the command more options will appear and require entering additional numbers.