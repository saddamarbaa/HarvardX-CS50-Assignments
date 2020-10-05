

# importing argv and exit modules to access command-line
# arguments and  Exits with explicit value
from sys import argv, exit

# define main function
def main():
    # checking if user Enter only 2 command-line argument
    if len(argv) != 3:
        print("incorrect number of command-line arguments")
        print("Usage: python dna.py data.csv sequence.txt")
        # signal to operating system that program not successes
        exit(1)

    # a CSV file that contain the STR counts for a list of individuals
    STR_counts = argv[1]

    # a text file that contain the DNA sequence to identify
    DNA_sequence = argv[2]

    #print(f"STR_counts is  {STR_counts}")
    #print(f"DNA_sequence   {DNA_sequence}")






# call main
main()

# signal to operating system everything works fine
exit(0)

