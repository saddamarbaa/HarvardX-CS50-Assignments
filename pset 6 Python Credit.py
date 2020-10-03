"""
    [PROGRAM] :  Credit Card Validation (Luhn’s Algorithm)
    [AUTHOR]  :  Saddam Arbaa
    [Email]   :  <saddamarbaas@gmail.com>

    Python Program to Implement CS50x 2020 Problem Set 6
    CS50X 2020 Problem Set 1 Credit Card Program (Python Implementation)

    Link to the Week 6 lecture
    CS50 2019 - Lecture 6 - Python
    https://youtu.be/fL308_-Kbt0
    Link to the  Problem Set
    https://cs50.harvard.edu/x/2020/psets/1/credit/#:~:text=Card  """

from cs50 import get_string  # include  get_int function
# define main function
def main():
    # get credit card number( call get_creditcard_number() function)
    ueserInput = get_creditcard_number()
    #print("creditcard_number is : ", ueserInput)
    # check credit card Validation
    isValid = checksum(ueserInput)  # call checksum() function

    # get the first digit of the credit card
    fitst_digits = int(ueserInput[0])

    # get start two digit of the credit card
    first_two_digits = ueserInput[0] + ueserInput[1]
    first_two_digits = int(first_two_digits)

    # get the Length of the credit card
    length = len(ueserInput)

   # check for all the corner cases
    if (isValid and (first_two_digits == 51 or first_two_digits == 52 or first_two_digits
                     == 53 or first_two_digits == 54 or first_two_digits == 55)) and length == 16:
        print("MASTERCARD")
    elif (isValid and (first_two_digits == 34 or first_two_digits == 37) and length == 15):
        print("AMEX")

    elif (isValid and fitst_digits == 4 and (length == 13 or length == 16)):
        print("VISA")
    else:
        print("INVALID")

"""
checksum Function takes one argument(user card number)
    and return true if the credit card is valid in system
    else if not valid return false """
def checksum(ueserInput):

    # initialize flowing variable to zero
    even_numberSum = odd_numberSum = 0
    # save in even_number and odd_number ueserInput
    even_number = odd_number = int(ueserInput)
    
    while even_number > 0:
        temp = even_number % 10     # get the digit
        # print(temp)
        even_number = even_number // 100
        # print("even", even_number)
        even_numberSum = even_numberSum + temp  # compute sum
    #print("\neven_numberSum", even_numberSum)
    """
    finding the sum of number starting from second
    digits * 2 according to Luhn’s Algorithm """
    while odd_number > 0:
        odd_number = odd_number // 10  # get the digit
        temp = odd_number % 10
        # print(temp)
        result = temp * 2
        if result > 9:  # Handle corner cases
            result = result % 10 + 1

        odd_number = odd_number // 10   # get the digit
        odd_numberSum = odd_numberSum + result   # compute sum

    #print("\nodd_numberSum", odd_numberSum)
    # calculate the total sum
    total_sum = even_numberSum + odd_numberSum
    #print("Toatal : ", total_sum)

    # check if the last digits == 0  if so its valid numbe
    if total_sum % 10 == 0:
        return True
    else:
        return False

# function to get credit card number
def get_creditcard_number():
    while True:
        # prompt the user for credit card number
        ueserInput = get_string("Enter the credit card number : ")
        # credit card must be posstive number.
        if int(ueserInput) > 0:
            break
    return ueserInput

# call main
main()

