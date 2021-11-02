# Check leap year
def leap_year_check(yr):
    leap = 0
    if yr % 4 == 0:
        leap = 1
        if yr % 100 ==0 and yr % 400 != 0: leap = 0
        else: leap = 1
    if leap == 1: print("{0} is a leap year".format(yr))
    else: print("{0} is not a leap year".format(yr))