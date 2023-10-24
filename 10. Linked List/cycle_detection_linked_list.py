#python program to detect loop in linked list

#if cycle found function will return 1
#else it will return 0

def has_cycle(head):
    
    #head is None i.e. no loop
    if head is None:
        return 0
    #or there is single element that means also no loop
    if head.next is None:
        return 0
    
    #two variable slow and fast is used
    #fast will take 2 steps all the time
    #slow will take 1 step
    slow = head
    fast = head
    
    while fast != None and slow != None:
        slow = slow.next
        if fast.next is not None:
            fast = fast.next.next
        else:
            fast = fast.next
        #if slow == fast that means there is loop
        if slow == fast :
            return 1
    #if fast == None that means no loop present
    return 0
