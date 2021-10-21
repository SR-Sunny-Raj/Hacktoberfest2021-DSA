import random
import string

#Storing all characters
Uppercase_letters = string.ascii_uppercase
lowercase_letters = string.ascii_lowercase
letters_list = string.ascii_letters
digit_list = string.digits
puntuation_list = string.punctuation

#Making list of combined characters
combined_list = list(Uppercase_letters + lowercase_letters + letters_list + digit_list + puntuation_list)

#Storing Generated Password
generated_pass = ""

#Generating Password
for i in range(12):
    rand_int = random.randint(0,len(combined_list)-1)
    generated_pass = generated_pass + combined_list[rand_int]

#Printing Generated Password
print(f"Your Generated Password is: {generated_pass}")