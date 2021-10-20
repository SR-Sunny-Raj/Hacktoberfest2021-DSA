/*
      Given 2 strings : 
      S = "TUTMTAPTAT";
      T = "TTA";
	
      Find the minimum Window in S that present all T String characters.
      return the minimum window substring.
*/

class Solution{
        public String minWindow(String s, String t) {
        	Map<Character,Integer> map = new HashMap<>();
        	for(char c: t.toCharArray())
            		map.put(c, map.getOrDefault(c,0)+1);
        
       	 int i=0, j=0;
        	 int count = map.size();
        	 int maxLength=Integer.MAX_VALUE, minStart=0, minEnd=0;
        	 while(j<s.length()){
           	     char c=s.charAt(j);
                     if(map.containsKey(c)){
                          int val = map.get(c)-1;
                          map.put(c, val);
    
                          if(val==0)
                             count--;
                      }
            
                      while(count==0){
                          if(maxLength>j-i+1){
                               maxLength = j-i+1;
                               minStart = i;
                               minEnd = j+1;
                          }
                
                          char x = s.charAt(i);
                          if(map.containsKey(x)){
                                map.put(x, map.get(x)+1);
                        
                                if(map.get(x)>0)
                                     count++;
                          }
                          i++;
                     }
                    j++;
              }
             return s.substring(minStart,minEnd);
        }
}