#include <stdio.h>
//library for string functions
#include <string.h>
//library for time related functions --clock()
#include <time.h>
//function for miscellaneous function --sleep() --unix standard
#include <unistd.h>
//library for charcater related functions --isspace()
#include <ctype.h>

#define MAX_TEXT_LENGTH 1000

// function in which the text is shown and input is taken , also the time interval between the typing is recorded
void start_typ()
{
    // original text
    const char *textToBeTyped = "The quick brown fox jumps.";

    //text that the user inputs
    char userInput[MAX_TEXT_LENGTH];
    //copy of original text to operate on
    char copyText[MAX_TEXT_LENGTH];

    //special data type that stores times stamps  --units is cpu ticks
    clock_t startTime , endTime;

    // -- input starts from here--
    printf("typing speed\n");

    printf("type the following text:%s \n",textToBeTyped);

    printf("get reday to type in 5 seconds\n");
    // give delay of 5 seconds before next line 
    sleep(5);

    printf("start typing: \n");

    //record the time before typing
    startTime = clock();
    gets(userInput);
    //record time after typing
    endTime = clock();

    //--input ends here

    //copying original string to copy
    strcpy(copyText,textToBeTyped);
    
    //calls for the fuction to remove spaces
    remove_space(copyText);
    remove_space(userInput);

    //calculate the actual time 
    double timeTake = (double)(endTime-startTime)/CLOCKS_PER_SEC;//clocks_per_second is a compiler variable 
   
   //call for the function to calculate speed and accuracy
    Info(copyText,userInput,timeTake);
}

// this function remove space from the given string
void remove_space(char *str)
{
    int count = 0;

    // the condition is the character is not null
    for (int i = 0;str[i] !='\0'; i++)
    {
        //changes the current charcter place if the current characte is not space
        if(!isspace(str[i]))
            str[count++] = str[i];
    }
}

// this function claculates the accuracy and speed
void Info(const char *givetext,const char *userInput,double time)
{
    int correctChar=0; // number of correct characters
    int totalCharacters = strlen(userInput);//total characters

    //loop which checks if the characters are same in both the strings
    for(int i=0;i<totalCharacters;i++)
        if ((givetext[i]==userInput[i]))
            correctChar++;//increase if the character is correct
        
    // caculate the accuracy 
    double accuracy = (double)correctChar/totalCharacters *100.0;

    //devide the number of letter by number of words
    int wordsTyped = strlen(userInput)/5;
    //calculate the number of seconds take to type the number of words
    double speed = wordsTyped/(time/60);

    // -- final output
    printf("user accuracy = %lf and user speed = %lf",accuracy,speed);
}


// main function -- calls for the first function
int main()
{
    // calling the start tping functions
    start_typ();

    return 0;
}
