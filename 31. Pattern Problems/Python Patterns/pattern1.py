#  Date   02/10/2021.
#   __Author__   :  Krishnan Navadia
#  __Package__  :  Python 3.x
#  __GitHub__  : https://github.com/krishnan-tech/


# [pattern1.py] Pattern that print "*" as a matrix for rows x cols

# *****
# *****
# *****
# *****
# *****

# This program will ask you for number of rows and columns then print pattern.

rows = int(input("Enter the number of rows: "))
cols = int(input("Enter the number of columns: "))

for i in range(rows):
    for j in range(cols):
        print("*", end="")
    print()

