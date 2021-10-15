
# Run "pip install pyqrcode" or "pip3 install pyqrcode" before running this program
import pyqrcode

data = input("Enter the text or link to generate QR code: ")

# Using pyqrcode.create() to create a qr code of the input data 
qr = pyqrcode.create(data)

# Using .svg method to save the qr code as SVG file of provided name & scale 
qr.svg('qr_code.svg', scale = 8)

# Run "python3 <filename.py>" to execute the program
# The program will generate a QR code of the input in the same directory