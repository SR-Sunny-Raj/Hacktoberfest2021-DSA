class Solution {
    public boolean halvesAreAlike(String s) {
        int c=0;
        int d=0;
        for(int i=0;i<s.length()/2;i++){
if(s.charAt(i)=='a'||s.charAt(i)=='e'||s.charAt(i)=='i'||s.charAt(i)=='o'||s.charAt(i)=='u'||s.charAt(i)=='A'||s.charAt(i)=='E'||s.charAt(i)=='I'||s.charAt(i)=='O'||s.charAt(i)=='U'){
     
            c=c+1;
   }

    }
       for(int i=s.length()/2;i<s.length();i++){
if(s.charAt(i)=='a'||s.charAt(i)=='e'||s.charAt(i)=='i'||s.charAt(i)=='o'||s.charAt(i)=='u'||s.charAt(i)=='A'||s.charAt(i)=='E'||s.charAt(i)=='I'||s.charAt(i)=='O'||s.charAt(i)=='U'){
     
            d=d+1;
   }

    } 
    
    if(c==d)
        return true;
    else
        return false;
    }
    }
