class Solution {
   
    public boolean exist(char[][] b, String w) {
        
        boolean vis[][]=new boolean[b.length][b[0].length];
    for(int i=0;i<b.length;i++){
        for(int j=0;j<b[0].length;j++){
              if(b[i][j]==w.charAt(0) && check(b,0,w,vis,i,j)){
                  return true;
              }
        }
    }
    return false;
    }
   static boolean check(char b[][],int pos,String w,boolean vis[][],int i,int j){
  if(pos==w.length()-1) return true;
  
   vis[i][j] = true;
  
if(i>0 && !vis[i-1][j] && b[i-1][j]==w.charAt(pos+1) && check(b,pos+1,w,vis,i-1,j)) return true;
if(j>0 && !vis[i][j-1] && b[i][j-1]==w.charAt(pos+1) && check(b,pos+1,w,vis,i,j-1)) return true;
if(i<b.length-1 && !vis[i+1][j] && b[i+1][j]==w.charAt(pos+1) && check(b,pos+1,w,vis,i+1,j)) return true;
if(j<b[0].length-1 && !vis[i][j+1] && b[i][j+1]==w.charAt(pos+1) && check(b,pos+1,w,vis,i,j+1)) return true;

  vis[i][j] = false;
  return false;

}
 }
