first_number = float(input())
second_number = float(input())
operation = input()
if second_number ==0.0:
    print('Division by 0!')
else:
    if operation == '+':
        print(add)
    elif operation == '-':
        print(sub)
    elif operation == '/':
        print(div)
    elif operation == '*':
        print(mult)
    elif operation == 'div':
        print(int_div)
    elif operation == 'pow':
        print(power)
    else:
        print(mod)
