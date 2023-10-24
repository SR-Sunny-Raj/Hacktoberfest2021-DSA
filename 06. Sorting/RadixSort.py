def counting_sort(list_vals, n, place):                                         
    integer_range = 10;                                                         
    freq =[0 for i in range(0, integer_range)];                                 
    list_sorted = [0 for i in range(0, n)];                                     
                                                                                
    for i in range(0, n):                                                       
        freq[(list_vals[i]/place)%integer_range] += 1;                          
                                                                                
    for i in range(1, integer_range):                                           
        freq[i] += freq[i-1];                                                   
                                                                                
    i = n-1;                                                                    
    while (i>=0):                                                               
        list_sorted[freq[(list_vals[i]/place)%10]-1]=list_vals[i];              
        freq[(list_vals[i]/place)%10] -= 1;                                     
        i -= 1;                                                                 
                                                                                
    for j in range(0, n):                                                       
        list_vals[j]=list_sorted[j];                                            
                                                                                
def radix_sort(list_vals):                                                      
    n = len(list_vals);                                                         
    max_element = max(list_vals);                                               
    mul=1;                                                                      
    while (max_element):                                                        
        counting_sort(list_vals, n, mul);                                       
        mul *= 10;                                                              
        max_element /= 10;                                                      
                                                                                
    return list_vals;                                                           
                                                                                
if __name__ == "__main__":                                                      
    list_vals = [3, 1, 2, 3, 6, 8, 5, 4];                                       
    print("Collection before sorting: %s" % str(list_vals));                    
    print("Sorted list elements: %s" % str(radix_sort(list_vals)));
