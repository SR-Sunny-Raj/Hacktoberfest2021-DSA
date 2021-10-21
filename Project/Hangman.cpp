#include<bits/stdc++.h>

using namespace std;

int main()
{
    
    string fruits[10] {"mango","papaya","apple","orange","banana","kiwi","watermelon","peach","grapes","strawberry"};
    string answer = fruits[rand()% 10];
    vector<int> foundchar;
    int foundCount = 0;
    int lives = 5;
    while (foundCount < (answer.size()-1) && lives > 0)
    {
        cout << "Guess the fruits name:" << std :: endl;
        cout << " \nYou currently have: " << lives << " lives." << std::endl;
        foundCount = 0;
        for (int i = 0; i < answer.length(); ++i)
        {
           
            if (find (foundchar.begin(), foundchar.end(), i) != foundchar.end())
            {
                
                std::cout << answer[i] << " "; 
                foundCount++; 
            }
            else
            {
              
                cout << "_ ";
            }
        }
        cout << std::endl;
        char userChoice = ' ';
        bool found = false;
        cout << "Choose a character..." << std::endl;
        cin >> userChoice;
        for (int i = 0; i < answer.length(); i++)
        {
            if (userChoice == answer[i])
            {
                found = true;
                foundchar.push_back (i);
            }
        }
        if (found == false)
            lives--;
        
    }
    
    if (lives != 0)
       cout << "\nCongrats you found the word!" << std::endl;
    else
         cout << "The correct word is " << answer << std::endl;
         cout << "\n You failed !" << std::endl;

    return 0;
}