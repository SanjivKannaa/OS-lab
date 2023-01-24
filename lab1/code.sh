#!/bin/bash

# 1.Create a directory 'CSE', change your working directory to ‘CSE’ and display where you
# are working now? Create files named 'date' and 'user'. Store the calendar and current date
# information in the file named 'date'. Store the login details of user in the file 'user'. 

mkdir CSE
cd CSE
pwd
touch date
touch user
echo "$(date)" >> date
echo "$(cal)" >> date
echo "$(users)" >> user


# 2.Create a file consisting of countries and their corresponding continents. Display the
# countries which are in the continent Asia. Sort the generated list and convert them into
# lowercase.
touch asia
touch europe
echo "India" >> asia
echo "China" >> asia
echo "Pakistan" >> asia
echo "Nepal" >> asia
echo "Thailand" >> asia
echo "Netherland" >> europe
echo "Germany" >> europe
cat asia
sort asia | tr '[:upper:]' '[:lower:]'


# 3.Create files like oldstu.txt, newstu.txt, oldlab.txt, newlab.pdf. Create hidden files called
# ‘stu’ and ‘oldfiles’. Search for files having the pattern "stu" and "old" in the current direc
touch oldstu.txt newstu.txt oldlab.txt newlab.pdf
touch .stu .oldfiles
ls -la | grep "stu\|old"

# 4.Create a file maks_numbered.txt using the file marks.txt. The new file should like
#           1:89 92 85
#           2:98 47 67
#           3:67 82 76
#           4:78 97 60
#           5:67 68 69

touch marks.txt
echo "89 92 85" >> marks.txt
echo "98 47 67" >> marks.txt
echo "67 82 76" >> marks.txt
echo "78 97 60" >> marks.txt
echo "67 68 69" >> marks.txt
touch marks_numbered.txt
nl marks.txt > marks_numbered.txt
sed -i 's/^[0-9]\+\s\+/&:/' marks_numbered.txt


# 5.Sort the file marks.txt based on the third column. 
touch marks.txt
echo "89 92 85" >> marks.txt
echo "98 47 67" >> marks.txt
echo "67 82 76" >> marks.txt
echo "78 97 60" >> marks.txt
echo "67 68 69" >> marks.txt
sort -n -k3 marks.txt -o marks_sorted.txt

# 6. Create two files NameList and MarkList. Add necessary information. Merge the contents of
# files NameList & MarkList and store it in a student file.
touch NameList
touch MarkList
touch Student
echo "Alice, Bob, Charlie, David" > NameList
echo "80, 90, 85, 95" > MarkList
paste NameList MarkList > Student
cat Student

# 7.List all the files recursively in a directory. 
ls -R

# 8.Display the tenth line of the file 'NameList.txt'.
head -n 10 NameList.txt | tail -n 1

# 9.Count the number of lines, words and Characters in the 'NameList.txt' file



# 16. Write C programs to simulate the following commands in Unix Operating system.
# • head
# • tail
# • cp
# • mv


#                   #include <stdlib.h>
#                   int main() {
#                       system("head");
#                       system("tail");
#                       system("cp");
#                       system("mv");
#                       return 0;
#                   }