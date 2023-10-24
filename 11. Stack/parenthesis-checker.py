def bal_parentheses(test_str):

    open_List = ["[", "{", "("]
    close_List = ["]", "}", ")"]
    stack = []

    for i in test_str:

        if i in open_List:
            #append to stack if opening bracket encountered
            stack.append(i)

        elif i in close_List:
            #check if closing bracket matches last opening bracket
            if (len(stack) > 0) and (open_List[close_List.index(i)] == stack[len(stack) - 1]):
                #remove matching opening bracket from stack      
                stack.pop()
            else:
                return "Parentheses are unbalanced..."

    if len(stack) == 0:
        #implies no extra brackets remaining in stack
        return "Parentheses are balanced!!!"
    else:
        return "Parentheses are unbalanced..."


def main():
    n = int(input())
    for i in range(n):
        test_str = input()
        print("Result for {}  :  {}".format(test_str,bal_parentheses(test_str)))

if __name__ == "__main__":
    main()