"""
    [PROGRAM] : DNA
    [AUTHOR]  : Saddam Arbaa
    [Email]   : <saddamarbaas@gmail.com>
    Python Program to Implement CS50x 2020 Problem Set 6
    DNA is a program that identifies a person based on their DNA,
    
    Link to the Week 6 lecture
    CS50 2019 - Lecture 6 - Python
    https://youtu.be/fL308_-Kbt0
    Links to the  Problem Set
    DNA - Nifty Assignments - SIGCSE 2020
    https://youtu.be/-Puz5tM3L0A
    https://cs50.harvard.edu/x/2020/psets/6/dna/#:~:text=submit50%20cs50/problems/2020/x/dna
    """
# importing sys to access command-line arguments and Exits with explicit value
import sys
# importing csv module for reading CSV files into memory,
import csv
# importing re module (Regular expression)
import re

# define main function
def main():

    # checking if user Enter only 2 command-line argument
    if len(sys.argv) != 3:
        # signal to operating system that program not successes
        print("incorrect number of command-line arguments")
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # Open(data.csv) CSV file that contain the STR counts for a list of individuals
    DNA_database = open(sys.argv[1])
    # Read the DNA_database file contents into Memory
    data = csv.DictReader(DNA_database)

    # now Open(sequence.txt) text file that contain the DNA sequence to identify
    # and read it contents into Memory(DNA_sequence)
    with open(sys.argv[2]) as sequence_file:
        DNA_sequence = sequence_file.read()

    # for testing
    # print(DNA_sequence)
    # for i in DNA_database:
        # print(i)

    # Now its time get the count for each StR
    count_StR = {}  # create Empty count_StR Dictionary

    # iterate over each patterns and call longest_consecutive_repeats_STR() function
    for patterns in data.fieldnames[1:]:
        count_StR[patterns] = longest_consecutive_repeats_STR(DNA_sequence, patterns)
       # print(patterns, count_StR[patterns]) # for testing

    # now is time to check the result and see if its math
    # will be true if all  the patterns match with the person patterns in the DNA database
    for Row in data:
        if all(count_StR[patterns] == int(Row[patterns]) for patterns in count_StR):
            print(Row['name'])
            DNA_database.close()  # close file
            sys.exit(0)
            
    # if reach this line mean STR counts do not match exactly
    # with any of the individuals in the CSV file
    print("No match")

"""
 function to Compute the longest run of Consecutive repeats
 of the STR in the DNA sequence to identify Using Regular expression.
    function take 2 parameters
    DNA sequence text
    patterns to search """

def longest_consecutive_repeats_STR(DNA_sequence, patterns):
    search_re = re.compile('(?:' + patterns + ')+')
    result = max((len(sequence)for sequence in search_re.findall(DNA_sequence)), default=0) // len(patterns)
    return result

    """
    look for all sequences of at least one repetition of the search pattern
    then Compute the maximum length of these sequences, divided by the length
    of the search pattern and return the final result """

# call main
main()
