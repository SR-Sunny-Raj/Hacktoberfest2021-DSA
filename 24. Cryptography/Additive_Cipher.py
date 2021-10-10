ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
SPECIAL_CHARS = " ,.-;:_?!="

def decrypt(cipher_text, key=None):
    texts = []
    for key in range(0,26):
        plain_text = ""
        for letter in cipher_text:
            #Skipping special characters (incomplete solution)
            if letter in SPECIAL_CHARS:
                plain_text += letter
                continue
            index = ALPHABET.find(letter.upper())
            new_index = flatten(index - key)
            plain_text += ALPHABET[new_index]
        texts.append(plain_text)
    return texts

def flatten(number) :
    return number - (26*(number//26))

if __name__ == "__main__":
    encrypted= input("Enter the encrypted text: ")
    texts = decrypt(encrypted)
    i = 0
    for text in texts:
        print(i, text)
        i = i + 1