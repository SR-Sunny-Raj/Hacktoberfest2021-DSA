#include <iostream>
#include <string>

using namespace std;

int main(){
    string sentence;
    cout<<"Enter your sentence :-"<<endl;                       // Asks the user for sentence
    getline(cin, sentence);

    int count = 0;
    for(int i=0; i<sentence.length(); i++)
    {
        if(sentence[i]==' ')  
            count++;                                            // Counts the number of empty space " " encountered
    }
    cout<<"\n\nThe number of words in your sentence is "<<count+1;      // Number of words in the sentence is 1 more than the number of empty spaces.
    return 0;
}
