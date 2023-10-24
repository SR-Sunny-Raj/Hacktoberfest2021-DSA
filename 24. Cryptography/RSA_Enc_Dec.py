"""
RSA Encryption Algorithm implementation.
Best range for prime numbers are 3-digit ones, as higher primes will run slower,
While lower primes will give product less than 255, leading to a chance of ASCII characters collision, that is a single cycle of Zn ring will include multiple characters.
"""

import random
import json


def gcd(a, b):
    """
    Returns GCD(a,b) by Euclid's algorithm.
    """
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


def is_prime(n):
    """
    Primality Test
    """
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    for i in range(3, int(n**0.5) + 1, 2):
        if n % i == 0:
            return False
    return True


def extended_euclidean_algorithm(a, b):
    # @param ax + by = gcd(a,b)
    """
    Based on the fact that:
     b % a = b - (b // a) * a\\
     gcd(a, b) = gcd(b%a, a)
    """
    if a == 0:
        return b, 0, 1
    gcd, x1, y1 = extended_euclidean_algorithm(b % a, a)
    x = y1 - (b//a)*x1
    y = x1
    return (gcd, x, y)


def calculation(m, d, n):
    """
    Calculates m**d mod(n) more efficiently
    """
    value = 1
    for _ in range(d):
        value = (value * m) % n
    return value


def mod_multiplicative_inverse(a, n):
    # @param (a, n) such that at = 1 mod(n), t has to be found.
    """
    Can return t, if at = 1 mod(n) exists, which always will cause gcd(a, n) is ensured before.\\
    This is equivalent to finding (at + ns = gcd(a,n)) mod(n)
    """
    gcd, t, s = extended_euclidean_algorithm(a, n)
    if t == None:
        raise ValueError("No Existing Inverse")
    if t < 0:
        t = t + n
    return t


def key_generation(p, q):
    # @params p, q are the large primes to be passed for key generation
    """
    Returns ((public key), (private key))\\
    p, q should not be revealed anywhere.
    """
    if not (is_prime(p) and is_prime(q)):
        raise Exception(u"\u001b[31mOne of them aren't primes\u001b[0m")
    elif p == q:
        raise Exception(u"\u001b[31mBoth are equal!\u001b[0m")
    else:
        prod = p * q
        totient = (p - 1) * (q - 1)
        e = random.randrange(2, totient)
        while gcd(e, totient) != 1:
            e = random.randrange(2, totient)
        return ((e, prod), (mod_multiplicative_inverse(e, totient), prod))


def encrypt(public_key, plainText):
    """
    Note that if n is not large enough, i.e. at least 255, 
    then there might be clashes due to 2+ ascii codes giving out same encrypted value.
    """
    e, n = public_key
    cipherText = []
    for char in plainText:
        ch = calculation(ord(char), e, n)
        cipherText.append(ch)

    return ' '.join(map(lambda x: str(x), cipherText))


def decrypt(private_key, cipherText):
    d, n = private_key
    cipherText = cipherText.split(' ')
    plainText = [chr(calculation(int(char), d, n))
                 for char in cipherText]  # Consists of ascii characters
    return ''.join(plainText)


if __name__ == '__main__':

    print("RSA implementation with no third-party libraries")
    # Obtain prime numbers
    p = int(input("Enter a prime: "))
    q = int(input("Enter another prime: "))

    # Save keys in files
    public, private = key_generation(p, q)
    print(f"Your public key is: {public}")
    print(f"Your private key is saved in `./private.json`")
    with open('public_key.json', 'w') as f:
        e, n = public
        public_json = json.dumps({"e": e, "n": n}, indent=4)
        f.write(public_json)
    with open('private_key.json', 'w') as f:
        d, n = private
        private_json = json.dumps({"d": d, "n": n}, indent=4)
        f.write(private_json)

    # Obtaining plaintext
    choice = '2'
    try:
        choice = input(
            "Save your plaintext as `./plaintext.txt` or input here (1 or 2): ")
        if choice == '1':
            try:
                with open('plaintext.txt', 'r') as f:
                    plainText = f.read()
            except:
                print(u"\u001b[31mFile problems.\u001b[0m")
                choice = '2'
    except:
        print(u"\u001b[31mInvalid choice.\u001b[0m")

    if choice == '2':
        plainText = input("Enter Message to be encrypted: ")

    # Encrypting plaintext
    blockSize = 2
    cipherText = encrypt(public, plainText)
    with open('ciphertext.txt', 'w') as f:
        f.write(cipherText)

    print(f"Your encrypted message is saved in `./ciphertext.txt`\n")

    print("CipherText is decrypted and saved in `./plaintextOut.txt`\n")
    plainTextOut = decrypt(private, cipherText)
    with open('plaintextOut.txt', 'w') as f:
        f.write(plainTextOut)
