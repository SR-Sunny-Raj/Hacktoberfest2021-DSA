class Solution {
    public List<Integer> spiralOrder(int[][] mat) {
        int cl=0;
        int cr=mat[0].length-1;
        int rt=0;
        int rb=mat.length-1;
        List<Integer> ans=new ArrayList<>();
        int x=0;
        while(cl<=cr && rt<=rb){
             x=x%4;
            if(x==0){
                for(int i=cl;i<=cr;i++){
                    ans.add(mat[rt][i]);
                }
                rt++;
                x+=1;   
            }else if(x==1){
                 for(int i=rt;i<=rb;i++){
                    ans.add(mat[i][cr]);
                }
                cr--;
                x+=1;
                
            }else if(x==2){
               for(int i=cr;i>=cl;i--){
                    ans.add(mat[rb][i]);
                }
                rb--;
                x+=1;
                
                
            }else if(x==3){
                 for(int i=rb;i>=rt;i--){
                    ans.add(mat[i][cl]);
                }
                cl++;
                x+=1;
                
                
            }
           
        }
        return ans;
        
    }
}
