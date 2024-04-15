#ifndef RECCHECK
// For debugging
#include <iostream>
// For std::remove
#include <algorithm> 
#include <map>
#include <set>
#endif

#include "wordle.h"
#include "dict-eng.h"
using namespace std;


// Add prototypes of helper functions here


// Definition of primary wordle function
std::set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict)
{
    // Add your code here

    // create a set that holds all the potential words helper function returns

    std::set<std::string> setWordle;

    std::string in_copy = in;
    std::string floating_copy = floating;

    wordleHelper(in_copy, floating_copy, dict, setWordle, 0);

    // place words in set
    //std::set<std::string>& finalSet = accurateValidWords(setWordle,dict);

    return setWordle;
    // //iterarte through answer set and then put each one in the setWordle 
    // for(std::string& str = setWordle.begin(); str != setWordle.end(); str++){
    //     setWordle.insert(str);
    // }

}

// Define any helper functions here




    // recursion function to create the potetial wordle word 
        // parameter: in, floating, dict, current? , result?


//HELPER FUNCTION 1:
    //generate all combinations:
        /*

        //this function generates all combinations of letters given a string containing 
            fixed & floating characters. it's the core of your program's logic  

        ** recursively filling in the fixed characters & floating characters **
        */
void wordleHelper(
    std::string in,
    std::string floating,
    const std::set<std::string>& dict, 
    std::set<std::string>& wordleSet,
    size_t nextIndex
    )
{
       // meets conditions??
        // correct length 
        // contains all the letters 
        // makes sure its withiin dictionary 2

    //base case (when you hit the end of the string length (therefore placed all the letters))
            // return that string 

    if (in.size() == nextIndex) {
        bool isItValid = isValidWordleWord(in,dict);
        if (!isItValid || floating.length() != 0) {
            return;
        }

        wordleSet.insert(in);
        return;
    }

    // if(in.empty()){
    //     return;
    // }

    // if(nextIndex == newString.size()){
    //     bool isItValid = isValidWordleWord(newString,dict);
    //     if(isItValid){
    //         wordleSet.insert(newString);
    //     }
    //     return;
    // }

    // if(in=="--" && floatingSet.empty()){
    //     for(char c = 'a'; c <= 'z'; c++){
    //         for(char d = 'a'; d <= 'z'; d++) 
    //         {
    //             string temp;
    //             temp += c;
    //             temp += d;
    //             if(dict.find(temp) != dict.end())
    //             {
    //                 wordleSet.insert(temp);
    //             }
    //         }
	//     }
    //     return;
    // }


    // if(in == "-" && floatingSet.empty()){
    //     //std::set<std::string> oneCharacterWordle;
    //     for(char characters = 'a'; characters <='z'; ++characters){
    //         std::string wordleWord(1,characters); //idk about this 
    //         wordleSet.insert(wordleWord);
    //     }
    //     return;
    // }
    // else if(in == "-"){
    //     for(char floatchar : floatingSet){
    //         std::string wordleWord(1,floatchar);
    //         wordleSet.insert(wordleWord);
    //     }
    // }

    // int counter = 0;
    // for(char character : in){
    //     if(character != '-'){
    //         counter++;
    //     }
    // }

    // if(counter == 0){
    //     return; 
    // }
    
 

    // if(in[certain location] != '-')
        // recurse wordleHelper again movign to next index in the wod beign generated
                // therefore: return wordleHelper()
    if(in[nextIndex] != '-'){
        wordleHelper(in,floating,dict,wordleSet,nextIndex+1);
        return;
    }
    // for(char letter = a; size <= z; ++letter)
        // if( accurateValidWords(in) )
                // add the letter 

    int numDashes = 0;
    for (int k = 0; k < in.length(); k++) {
        numDashes += (int) (in[k] == '-');
    }

    // first check all my floating letters
    for (int k = 0; k < floating.length(); k++) {
        std::string floatingCopy = floating.substr(0,k) + floating.substr(k+1);
        in[nextIndex] = floating[k];
        wordleHelper(in,floatingCopy,dict,wordleSet, nextIndex+1);
    }

    if (numDashes == floating.length()) {
        return; //cecking if there isn't anymore spots left for a-z ; then return
    }
    // second check all a-z
    for(char c = 'a'; c <= 'z'; ++c){
        in[nextIndex] = c;
        wordleHelper(in,floating,dict,wordleSet, nextIndex+1);
    }
    // else{
    //     for(std::set<char>:: iterator i = floatingSet.begin(); i != floatingSet.end(); ++i){
    //         newString[nextIndex] = *i;
    //         char popedFloatingChar = *i;
    //         floatingSet.erase(i);
    //         wordleHelper(in,floatingSet,dict,newString,wordleSet, nextIndex+1);
    //         floatingSet.insert(popedFloatingChar);
    //     }
    // }

    //when float(subset or actual) is empty 
}

//HELPER FUNCTION 2:
    // valid words:
    /*
        this function checks if a generated combination is a valid English word
        --> you can use this function to check if a combination is a vlid English word by looking it up in the provided dictionary
    */
bool isValidWordleWord(std::string possibleWord, const std::set<std::string>& dict)
{
    return dict.find(possibleWord) != dict.end();
}

//HELPER FUNCTION 3:
    // filter valid words: 
    /*
        this function filters out valid english words from the generated combintations
        --> this function takes the set of generated combiinations and filters out the valid English words usign 'isValidWord
 function    
    
    */
// std::set<std::string> accurateValidWords(const std::set<std::string>& createdWordsSet, const std::set<std::string>& dict)
// {
//     std::set<std::string> validWordSet;

//     for(std::set<std::string>::iterator it = createdWordsSet.begin(); it!= createdWordsSet.end(); ++it){
//         if(isValidWordleWord(*it, dict)){
//             validWordSet.insert(*it);
//         }
//     }

//     return validWordSet;
// }