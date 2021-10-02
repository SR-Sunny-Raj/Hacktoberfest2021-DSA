// RAIL FENCE CIPHER
// The rail fence cipher (also called a zigzag cipher) is a form of transposition cipher.
// It derives its name from the way in which it is encoded.

// Encryption:-
// In a transposition cipher, the order of the alphabets is re-arranged to obtain the cipher-text. 
// In the rail fence cipher, the plain-text is written downwards and diagonally on successive rails of an imaginary fence.
// When we reach the bottom rail, we traverse upwards moving diagonally, after reaching the top rail, the direction is changed again.
// Thus the alphabets of the message are written in a zig-zag manner.
// After each alphabet has been written, the individual rows are combined to obtain the cipher-text.

// Decryption:-
// As we’ve seen earlier, the number of columns in rail fence cipher remains equal to the length of plain-text message.
// And the key corresponds to the number of rails.
// Hence, rail matrix can be constructed accordingly.
// Once we’ve got the matrix we can figure-out the spots where texts should be placed (using the same way of moving diagonally up and down alternatively ).
// Then, we fill the cipher-text row wise. After filling it, we traverse the matrix in zig-zag manner to obtain the original text.


#include<bits/stdc++.h>
using namespace std;
string encryption_function(string plaintext,int depth,int length_of_pt){
    char rail_matrix[depth][length_of_pt];
    string cipher_text;
    for(int i=0;i<depth;i++){
        for(int j=0;j<length_of_pt;j++){
            rail_matrix[i][j]='-';
        }
    }
    int flag=0;
    int j=0;
    for(int i=0;i<length_of_pt;i++){
        rail_matrix[j][i]=plaintext[i];
        if(j==depth-1){
            flag=1;
        }else if(j==0){
            flag=0;
        }
        if(flag==0){
            j++;
        }else{
            j--;
        }
    }
    for(int i=0;i<depth;i++){
        for(int j=0;j<length_of_pt;j++){
            if(rail_matrix[i][j]!='-'){
                cipher_text.push_back(rail_matrix[i][j]);
            }
        }
    }
    return cipher_text;
}
string decryption_fuction(string cipher_text,int depth){
    int length_of_ct=cipher_text.length();
    string decrypted_pt;
    char rail_matrix[depth][length_of_ct];
    for(int i=0;i<depth;i++){
        for(int j=0;j<length_of_ct;j++){
            rail_matrix[i][j]='-';
        }
    }
    int j=0;
    int flag=0;
    for(int i=0;i<length_of_ct;i++){
        rail_matrix[j][i]='0';
        if(j==depth-1){
            flag=1;
        }else if(j==0){
            flag=0;
        }
        if(flag==0){
            j++;
        }else{
            j--;
        }
    }
    int k=0;
    for(int i=0;i<depth;i++){
        for(int j=0;j<length_of_ct;j++){
            if(rail_matrix[i][j]=='0'){
                rail_matrix[i][j]=cipher_text[k];
                k+=1;
            }
        }
    }
    flag=0;
    j=0;
    for(int i=0;i<length_of_ct;i++){
        decrypted_pt.push_back(rail_matrix[j][i]);
        if(j==depth-1){
            flag=1;
        }else if(j==0){
            flag=0;
        }
        if(flag==0){
            j++;
        }else j--;
    }
    return decrypted_pt;

}
int main(){
    string plaintext;
    cout<<"enter the plain-text"<<endl;
    cin>>plaintext;
    int depth;
    cout<<"enter the key depth"<<endl;
    cin>>depth;
    int length_of_pt=plaintext.length();
    string cipher_text;
    cipher_text=encryption_function(plaintext,depth,length_of_pt);
    cout<<"CIPHER TEXT="<<cipher_text<<endl;
    string decrypthed_pt=decryption_fuction(cipher_text,depth);
    cout<<"DECRYPTED PLAIN TEXT="<<decrypthed_pt<<endl;
    return 0;
}
