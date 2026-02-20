CS 210 – Corner Grocer Item Tracking System

Author: Richard Savage
Language: C++ (OOP Design)

Project Summary

The Corner Grocer Item Tracking System was developed to solve the problem of tracking item purchase frequency from a structured input file. The program reads item names from a text file, calculates frequency counts, and allows users to interact with the data through a menu-driven interface. It also generates a backup file (frequency.dat) to preserve processed results.

This project demonstrates object-oriented programming principles, file input/output operations, data normalization, input validation, and use of the C++ Standard Library (std::map) to efficiently store and retrieve frequency data.

What I Did Particularly Well

One of the strongest aspects of this project was the implementation of object-oriented design. I encapsulated all data processing and file operations within the GroceryTracker class, which improved separation of concerns and maintainability.

I also implemented:

Strong input validation to prevent runtime errors

Case normalization to eliminate duplicate entries caused by inconsistent capitalization

Defensive file handling with error checking before processing

Automatic backup file generation for data persistence

A dynamic histogram feature for visual representation of frequency data

These elements demonstrate attention to robustness, reliability, and usability.

Areas for Enhancement

While the project meets functional requirements, there are several areas where it could be enhanced:

Implementing exception handling (try/catch) for stronger error management

Adding unit tests to validate functionality automatically

Improving user interface formatting for better readability

Allowing dynamic file name input instead of hardcoding the file path

Optimizing normalization using more advanced string processing techniques

These improvements would increase scalability, adaptability, and security while making the program more production-ready.

Most Challenging Components

The most challenging portion of this project was implementing file handling correctly and ensuring the program properly located and processed the input file. Debugging file path issues required careful validation of directory structure and runtime execution context.

Another challenge was ensuring accurate case-insensitive comparisons. I overcame this by implementing a normalization function that converts all strings to lowercase before storage.

To support my learning, I utilized:

C++ documentation for std::map

Course resources and module examples

Compiler error messages and debugging strategies

Terminal commands to verify file placement

These tools strengthened my debugging and problem-solving skills.

Transferable Skills

This project reinforced several transferable skills:

Object-oriented programming design

Use of associative containers (std::map)

File input/output management

Input validation and defensive programming

Data normalization techniques

Modular design and separation of concerns

These skills directly apply to larger software development projects, database interaction, and systems programming.

Maintainability and Adaptability

The program was designed with maintainability in mind by:

Separating implementation and header files

Using descriptive function names

Encapsulating private data members

Implementing reusable class methods

Following consistent formatting and commenting standards

