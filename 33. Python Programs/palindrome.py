"""
A palindrome is a word, sentence, verse, or even number 
that reads the same backward or forward.
"""

def is_palindrome(word):
    """
    This function return boolean value
    to check whether the word/sentence is 
    a palindrome or not.
    """
    
    # Base Condition
    if len(word) < 2:
        return True

    # Work Condition
    if word[0] == word[-1]:
        return is_palindrome(word[1:-1])

    # Ultimatum
    return False

print(is_palindrome("racecar"))
