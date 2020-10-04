"""
    [PROGRAM] :  Readability(Coleman-Liau formula)
    [AUTHOR]  :  Saddam Arbaa
    [Email]   :  <saddamarbaas@gmail.com>
    CS50X 2020 Problem Set 6 Readability Python Implementation
    (a program that computes the approximate grade level needed to comprehend some text)
    Link to the Week 6 lecture
    CS50 2019 - Lecture 6 - Python
    https://youtu.be/fL308_-Kbt0    """

from cs50 import get_string  # import get_string from Cs50

# define main function
def main():
    # declare and initializ the flowing variables
    number_of_letters = number_of_words = number_of_sentences = 0
   
    # Getting User Input string
    text = get_string("Enter some text: ")

   # iterate text and count number of letters and number of sentences
    for Character in text:
        if (Character >= 'a' and Character <= 'z') or (Character >= 'A' and Character <= 'Z'):
            number_of_letters += 1   # increment number_of_letters by one
        elif Character == '.' or Character == '!' or Character == '?':
            number_of_sentences += 1  # increment number_of_sentences by one
    # compute the number of words using split () function
    number_of_words = len(text.split())
    # print("Number letters is : ", number_of_letters)    # for test
    # print("number_of_sentences : ",number_of_sentences) # for test
    # print("number_of_words is :", number_of_words)      # for test

    # Computes the Coleman-Liau index formula below
    # index = 0.0588 * L - 0.296 * S - 15.8
    L = number_of_letters / number_of_words * 100
    S = number_of_sentences / number_of_words * 100
    index = round(0.0588 * L - 0.296 * S - 15.8)
    
    # print the final Result
    if index >= 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print("Grade ", index)
      
  # call main
main()
