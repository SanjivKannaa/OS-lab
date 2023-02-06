#!/bin/bash

# 1. Write a shell script to calculate the value of X^n
x=0
n=0
ans=1
read -p "X = " x
read -p "n = " n
for i in $(seq 1 n)
do
    ans=$((ans*x))
done
echo "x^n = $(ans)"

# 2. Write a shell script to read 10 numbers from the user and to find the sum and average of the numbers.
sum=0
for i in {1..10}
do
    echo "Enter the input"
    read value
    sum=$((sum+value))
done
echo "The sum is $sum"


# 3. Write a shell script to find whether the given number is Armstrong or not


# 4. Write a shell script to print all the divisors of a given integer.
n=0
read -p "enter the number" n
for i in $(seq 1 $n)
do
    if [ $((n%i)) -eq 0 ]
    then
        echo $i
    fi
done


# 5. Write a shell script to count the number of vowels in the string.


# 6. Write a shell script to reverse the string without using in-built functions.
s=""
read -p "enter the string: " s
for (( i=${#s}-1; i>=0; i-- ))
do
    echo "${s:$i:1}"
done