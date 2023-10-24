def check_columns_rows(set, mat):
    index = 0
    for i in range(0,25):
        if(set[0] == mat[i]):
            index = i
            break
    c1 = (int)(index%5)
    r1 = (int)(index/5)
    i1 = index

    for i in range(0,25):
        if(set[1] == mat[i]):
            index = i
            break
    c2 = (int)(index%5)
    r2 = (int)(index/5)
    i2 = index
    return (c1,r1,i1,c2,r2,i2)
    

def encrypt(plain, mat):
    sets = []
    tmp = []
    output = []
    i = 0
    for ch in plain:
        if( ord(ch) < 65 or ord(ch) > 90 ):
            continue
        tmp.append(ch)
        i = i + 1
        if(i == 2):
            i = 0
            sets.append(tmp)
            tmp = []
    
    if(i == 1):
        tmp.append("X")
        sets.append(tmp)
        tmp = []

    for s in sets:
        tmp = []
        (c1,r1,i1,c2,r2,i2) = check_columns_rows(s,mat)

        if(c1 == c2):
            tmp.append(mat[(i1 + 5) % 25])
            tmp.append(mat[(i2 + 5) % 25])
        elif(r1 == r2):
            if(i1 + 1)%5 == 0:
                tmp.append(mat[(i1 - 4)])
            else:
                tmp.append(mat[(i1 + 1)])
            if(i2 + 1)%5 == 0:
                tmp.append(mat[(i2 - 4)])
            else:
                tmp.append(mat[(i2 + 1)])
        else:
            if(c1 < c2):
                tmp.append(mat[(i1 + abs(c1 - c2)) % 25 ])
                tmp.append(mat[(i2 - abs(c1 - c2)) % 25 ])
            else:
                tmp.append(mat[(i1 - abs(c1 - c2)) % 25 ])
                tmp.append(mat[(i2 + abs(c1 - c2)) % 25 ])

        output.append(tmp)
        tmp = []
    return output

def main():
    key = input("Enter the key: ").upper()
    mat = []
    char_arr = [0] * 26
    for index in range(0,len(key)):
        mat.append(key[index])
        if key[index] == 'J':
            key[index] = 'I'
        char_arr[ord(key[index]) - ord("A")] = 1
        
    for i in range(0,26):
        # for ignoring J
        if i == 9:
            continue

        if(char_arr[i] == 0):
            mat.append(chr(i + ord("A")))
    print(mat)
    plain = input("Enter the plain text: ").upper()
    plain = plain.upper()
    print(encrypt(plain, mat))
main()