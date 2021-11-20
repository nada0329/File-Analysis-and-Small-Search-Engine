# File-Analysis-and-Small-Search-Engine
Analyzes a text file and returns information about its  content using Linked list

<h3>To run the code in cmd </h3>

    g++ main.cpp linked_list.cpp
  
    a.exe name_of_your_target_text_file name_of_the_commands_text_file  (ex: a.exe my_text.txt commands.txt)
 
  
The first input is a text file which is the target file

The second input is a text file that contains the needed commands to be executed 

The output is printed on screen

**the commands that code handdles:**
- wordCount: the whole number of words in file
- distWords: the number of distinct words only
- charCount: the number of chars in the file
- frequentWord: the most used word in the file ignorong a, an, is ...etc
- countWord put_your_word_here: how many this word appear 
- starting put_your_str_here: get the words that start with (what ever you want) and how many times
- containing put_your_str_here: get the words that contain (what ever you want) and how many times
- search put_your_str_here: find the string you searched for and in which line
