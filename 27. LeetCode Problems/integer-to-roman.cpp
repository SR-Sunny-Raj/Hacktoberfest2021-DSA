class Solution {
public:
    string intToRoman(int num) {
        vector<string> digit(13);
        digit[0]="I";
        digit[1]="IV";
        digit[2]="V";
        digit[3]="IX";
        digit[4]="X";
        digit[5]="XL";
        digit[6]="L";
        digit[7]="XC";
        digit[8]="C";
        digit[9]="CD";
        digit[10]="D";
        digit[11]="CM";
        digit[12]="M";
        
        vector<int> digitN(13);
        digitN[0]=1;
        digitN[1]=4;
        digitN[2]=5;
        digitN[3]=9;
        digitN[4]=10;
        digitN[5]=40;
        digitN[6]=50;
        digitN[7]=90;
        digitN[8]=100;
        digitN[9]=400;
        digitN[10]=500;
        digitN[11]=900;
        digitN[12]=1000;
        
        string res="";
        
        while(num>0){
            for(int i=12;i>=0;i--){
                if(num-digitN[i]>=0){
                    num=num-digitN[i];
                    res+=digit[i];
                    break;
                }
            }
        }
        return res;
    }
};
