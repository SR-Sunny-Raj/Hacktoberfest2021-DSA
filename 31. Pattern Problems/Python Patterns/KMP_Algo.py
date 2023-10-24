def kmpAlgo(patt, recurr):
	x = len(patt)
	y = len(recurr)

	
	lps = [0]*x
	j = 0 

	
	computeLPSArray(patt, x, lps)

	i = 0 
	while i < y:
		if patt[j] == recurr[i]:
			i += 1
			j += 1

		if j == x:
			print ("Found pattern at index " + str(i-j))
			j = lps[j-1]

		
		elif i < y and patt[j] != recurr[i]:
			x
			if j != 0:
				j = lps[j-1]
			else:
				i += 1

def computeLPSArray(patt, x, lps):
	len = 0 

	lps[0] 
	i = 1


	while i < x:
		if patt[i]== patt[len]:
			len += 1
			lps[i] = len
			i += 1
		else:
			
			if len != 0:
				len = lps[len-1]

			
			else:
				lps[i] = 0
				i += 1





kmpAlgo(recurr = input("Enter pattern "), patt = input("Enter Reccuring pattern "))


