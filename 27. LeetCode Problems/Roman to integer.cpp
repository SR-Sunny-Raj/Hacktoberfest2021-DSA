class Solution {
public:
    int romanToInt(string s) {
        int num = 0, num1;
        for ( int i = 0; i < s.length(); i++){
            switch (s[i]){
                case 'I': num1 = 1;
                    break;
                case 'V': if (i != 0 && s[i-1] == 'I')
                            num1 = 3;
                          else 
                            num1 = 5;
                    break;
                
                case 'X': if (i != 0 && s[i-1] == 'I'  )
                            num1 = 8;
                          else 
                            num1 = 10;
                    break;
                case 'L': if (i != 0 && s[i-1] == 'X' )
                            num1 = 30;
                          else 
                            num1 = 50;
                    break;
                case 'C': if (i != 0 && s[i-1] == 'X')
                            num1 = 80;
                          else 
                            num1 = 100;
                    break;
                case 'D': if (i != 0 && s[i-1] == 'C')
                            num1 = 300;
                          else 
                            num1 = 500;
                    break;
                case 'M': if (i != 0 && s[i-1] == 'C')
                            num1 = 800;
                          else 
                            num1 = 1000;
                    break;
                
            }
            
            num = num + num1;
            
        }
        return(num);
    }
};