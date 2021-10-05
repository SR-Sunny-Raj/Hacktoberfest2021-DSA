if __name__ == '__main__':
    s = input()
    print(any(i.isalnum() for i in s))
    print(any(i.isalpha() for i in s))
    print(any(i.isdigit() for i in s))
    print(any(i.islower() for i in s))
    print(any(i.isupper() for i in s))
            
      
# str.isalnum()
# This method checks if all the characters of a string are alphanumeric (a-z, A-Z and 0-9).

# str.isalpha()
# This method checks if all the characters of a string are alphabetical (a-z and A-Z).

# str.isdigit()
# This method checks if all the characters of a string are digits (0-9).

# str.islower()
# This method checks if all the characters of a string are lowercase characters (a-z).

# str.isupper()
# This method checks if all the characters of a string are uppercase characters (A-Z).
