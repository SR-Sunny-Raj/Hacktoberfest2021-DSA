number = raw_input('Enter Number :')

if len(number)%2 == 1:
    if number[:len(number)/2] == number[-1:-len(number)/2:-1]:
         print 'palindrome'
    else:
        print 'not palindrome'
else:
    if number[:len(number)/2] == number[-1:-(len(number)/2+1):-1]:
        print 'palindrome'
    else:
        print 'not palindrome'


    

