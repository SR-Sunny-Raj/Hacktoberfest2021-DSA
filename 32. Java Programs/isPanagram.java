class Solution {
    public boolean checkIfPangram(String sentence) {
        if(sentence.length() < 26)
            return false ;
        String str = "abcdefghijklmnopqrstuvwxyz";
        for(int i=0 ; i<str.length() ; i++){
            if(sentence.indexOf(str.charAt(i)) == -1)
                return false ;
        }
        return true ;
    
    }
}
