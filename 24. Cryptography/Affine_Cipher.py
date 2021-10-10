import re

def cipher_text():
    while True:
        clt = input("Enter cipher text: ").strip()
        if clt.isalpha() or bool(re.search(r"\s", clt)):
            return clt.upper()

        else:
            print("Sorry, I didn't understand that.")


def inverse():
    # a = int(key())
    xs = []
    for a in range(0,27):
        for x in range(1, 27):
            if (a * x) % 26 == 1:
                xs.append(x)
    return xs


def decryption():
    plt = ""
    ct = cipher_text()
    ks = inverse()
    words = []
    for k in ks:
        print(k)
        plt = ""
        for b in range(20,21):
            print(b)
            for i in ct.split():
                plt = ""
                for j in i:
                    total = ((ord(j) - 65 - b) * k) % 26
                    plt = plt + (chr(total + 65))
                words.append(plt)
            print(words)
            words = []

def main():
    decryption()


main()
