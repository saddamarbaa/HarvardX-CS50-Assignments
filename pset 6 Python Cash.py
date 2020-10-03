"""
    [PROGRAM] :  Cash (Greedy Algorithms)
    [AUTHOR]  :  Saddam Arbaa
    [Email]   :  <saddamarbaas@gmail.com>
    CS50X 2020 Problem Set 6 Cash Python Implementation
    Link to the Week 6 lecture
    CS50 2019 - Lecture 6 - Python
    https://youtu.be/fL308_-Kbt0  """

from cs50 import get_float  # include  get_float function
# define main function
def main():
    # asking user input the Change owed
    userIput = get_Change_owed()  # call get_Change_owed() function
    # converts user input money from dollars to cents
    cents = userIput * 100
    
    # Compute coin
    # call cash_coins() function
    coins = cash_coins(cents)
    # print the result
    print(coins)

# function to Compute the number of coins
def cash_coins(cents):
    """
    cointCounter is Variable to hold the number of coin
    will be used as counter initialize to zero for now """
    cointCounter = 0
    # iterate over cents to count quarters change
    while cents >= 25:
        cents -= 25
        cointCounter += 1  # increment cointCounter by one
    # iterate over cents to count dimes change
    while cents >= 10:
        cents -= 10
        cointCounter += 1  # increment cointCounter by one
    # iterate over cents to count nickels change
    while cents >= 5:
        cents -= 5
        cointCounter += 1  # increment cointCounter by one
    # iterate over cents to count pennies change
    while cents >= 1:
        cents -= 1
        cointCounter += 1  # increment cointCounter by one

    # return number of coins
    return cointCounter

# function to get the an amount of  Change owed in Dollar from user
def get_Change_owed():
    while True:
        # prompt user for an amount of change
        userIput = get_float("Change owed  :")
        # userIput must be postive number.
        if userIput > 0:
            break
    return userIput
  
  # call main
main()
