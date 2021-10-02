"""
Blowfish is a symmetric block cipher designed by Bruce Schneier.
It has a fixed data block size of 8 bytes and
its keys can vary in length from 32 to 448 bits (4 to 56 bytes).
Blowfish is deemed secure and it is fast.
However, its keys should be chosen to be big enough to withstand a brute force attack
(e.g. at least 16 bytes).
"""

from Crypto.Cipher import Blowfish
import codecs
from struct import pack
import argparse

class BlowFish:

	def __init__(self):
		pass

	def encrypt(self,plaintext,key):
		bs = Blowfish.block_size
		key = bytes(key, encoding="utf-8")
		cipher = Blowfish.new(key, Blowfish.MODE_CBC)
		plaintext = bytes(plaintext, encoding="utf-8")
		plain = bs - len(plaintext) % bs
		padding = [plain]*plain
		padding = pack("b"*plain, *padding)
		return cipher.iv + cipher.encrypt(plaintext + padding)

	def decrypt(self,ciphertext, key):
		bs = Blowfish.block_size
		ciphertext,_ = codecs.escape_decode(ciphertext, 'hex')
		key = bytes(key, encoding="utf-8")
		iv = ciphertext[:bs]
		ciphertext = ciphertext[bs:]

		cipher = Blowfish.new(key, Blowfish.MODE_CBC, iv)
		msg = cipher.decrypt(ciphertext)

		last_byte = msg[-1]
		msg = msg[:- (last_byte if type(last_byte) is int else ord(last_byte))]
		return msg


if __name__ == "__main__":
	parser = argparse.ArgumentParser(description='Encrypt/Decrypt with Blowfish Algorithm')

	parser.add_argument("-m",'--method', help='enc/dec for Encrypt/Decrypt respectively',required=True)
	parser.add_argument(
		"-t", '--text', help='Text to encrypt/decrypt', required=True)
	parser.add_argument(
		"-k", '--key', help='Key for the encryption/decryption', required=True)
	args = parser.parse_args()
	b = BlowFish()
	if(args.method=="enc"):
		print(b.encrypt(args.text,args.key))
	elif(args.method=="dec"):
		ciphertext = bytes(args.text.replace("\\\\","\\"),encoding="utf-8")
		print(b.decrypt(ciphertext,args.key))
	else:
		print("Invalid argument for method: Use 'enc' for encryption or 'dec' for decryption")

"""
(base) PS D:\Projects\Hacktoberfest2021-DSA\24. Cryptography> python3 Blowfish.py -h

usage: Blowfish.py [-h] -m METHOD -t TEXT -k KEY

Encrypt/Decrypt with Blowfish Algorithm

optional arguments:
	-h, --help            show this help message and exit
	-m METHOD, --method METHOD
							enc/dec for Encrypt/Decrypt respectively
	-t TEXT, --text TEXT  Text to encrypt/decrypt
	-k KEY, --key KEY     Key for the encryption/decryption

(base) PS D:\Projects\Hacktoberfest2021-DSA\24. Cryptography> python3 Blowfish.py -m enc -t "This is a test string" -k "This is a test key"

b'Ml\xb7\x88\xe4\xbcTU\x918\xd1\xca\xb0\xa3[O\xd3\x9a\xdcGA\xb9v;f\xcb\x81L\xae\x80\x18\x07'

(base) PS D:\Projects\Hacktoberfest2021-DSA\24. Cryptography> python3 Blowfish.py -m dec -t "Ml\xb7\x88\xe4\xbcTU\x918\xd1\xca\xb0\xa3[O\xd3\x9a\xdcGA\xb9v;f\xcb\x81L\xae\x80\x18\x07" -k "This is a test key"

b'This is a test string'
"""
