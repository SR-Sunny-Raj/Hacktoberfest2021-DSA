# PROBLEM STATEMENT: Sending emails via python script.

# Steps to be followed
# Go to your gmail account.
# Click on the profile photo on the top right corner.
# Manage your Google Account => Security => Less secure app access => Turn on access

import smtplib

# Steps to be followed¶
# Insert the email-id (ex: abc@gmail.com) from which you want to send the email in the place of sender id.
# Insert the email-id password of the sender's email in the place of email password.
# Insert the email-id (ex: abc@gmail.com) to which you want to send the email in the place of reciever id.
# Insert the content of the mail in the place of content.

mail = smtplib.SMTP('smtp.gmail.com',587)
mail.ehlo()
mail.starttls()

# Insert sender email-id and password here
mail.login('<sender id>','<email password>')

# Insert sender email-id, reciever email-id and content of the mail here
mail.sendmail('<sender id>','<reciever id>','<content>')
mail.close()
