import random

i = 0 
j = 0
n = 1
print ("*************WELCOME**********\n  ")
while n != 0:
    user = input ("Enter your choice \n"+ "s for snake \n"+ "w for water \n"+ "g for gun\n")
    opt = ["s" , "w" , "g" ]
    comp = random.choice (opt)
    
    if (user == comp ):
        print ("Draw ")
    elif (user == "s" and comp == "w" ):
        i += 1 
        print("You win\n"+ "You - ", i , "    comp- " ,j )
        
    elif (user == "w"and comp == "g"):
        i += 1 
        print("You win\n"+ "You - ", i , "    comp- " ,j )
        
    elif (user == "g"and comp =="s"):
        i += 1  
        print("You win\n"+ "You - ", i , "    comp- " ,j )
        
    elif (user == "s"and comp == "g"):
        j += 1  
        print("You loose\n"+ "You - ", i , "    comp- " ,j )
        
    elif (user == "w"and comp == "s"):
        j += 1  
        print("You loose\n"+ "You - ", i , "    comp- " ,j )
        
    elif (user == "g"and comp == "w"):
        j  += 1  
        print("You loose\n"+ "You - ", i ,  "    comp- " ,j )
        
    else :
        print ("Invalid Choice ")
        
    try :
        n = int(input ("If you want to continue press 1 otherwise press 0\n"))
    except Exception as e :
        print (e)
print ("GAME OVER!!!! "+"\n" + "Your score - ", i , "Comp score - ", j)
if (i >j):
    print ("You win this game !!!!!!! ")
elif (i < j):
    print ("You loose !!")


        

