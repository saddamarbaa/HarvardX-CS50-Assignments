# importing sys to access command-line arguments and Exits with explicit value
import sys
# importing csv module for reading CSV files into memory,
import csv

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
    with open(sys.argv[2]) as file:
        DNA_sequence =   file.read()

    # for testing
    # print(DNA_sequence)




    # if reach this line mean STR counts do not match exactly
    # with any of the individuals in the CSV file
    print("No match")



# call main
main()


