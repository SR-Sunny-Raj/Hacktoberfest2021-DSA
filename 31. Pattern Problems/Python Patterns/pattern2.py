#  Date   02/10/2021.
#   __Author__   :  Krishnan Navadia
#  __Package__  :  Python 3.x
#  __GitHub__  : https://github.com/krishnan-tech/


# [pattern2.py] Pattern that print "*" as a rectangle/square shape

# * * * * * 
# *       *
# *       *
# *       *
# * * * * *

# This program will ask you for number of rows and columns then print pattern.

rows = int(input("Enter the number of rows: "))
cols = int(input("Enter the number of columns: "))

for i in range(rows):
    for j in range(cols):
        if i == 0 or i == rows - 1 or j == 0 or j == cols - 1:
            print("*", end=" ")
        else:
            print(" ", end=" ")
    print()
