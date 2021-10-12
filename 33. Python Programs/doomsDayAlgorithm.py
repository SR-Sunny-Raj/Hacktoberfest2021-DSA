def doomsDay(year):
     
    weekDays = ("Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday")

    k = year % 400
     
    if(k >= 0 and k < 100):
        anchor = 2
         
    elif(k >= 100 and k < 200):
        anchor = 0
         
    elif(k >= 200 and k < 300):
        anchor = 5
         
    else:
        anchor = 3
   
    y = year % 100
     
    doomsday = ((y//12 + y % 12 + (y % 12)//4)% 7 + anchor) % 7
     
    return weekDays[doomsday]
 
year = 2021
print("Doomsday in the year % s = % s"%(year, doomsDay(year)))

