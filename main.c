#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TEXT_LENGTH 500

void start_typ()
{
    const char *textType = "The quick brown fox jumps.";
    char userInput[MAX_TEXT_LENGTH];
    clock_t startTime , endTime;

    printf("typing speed\n");

    printf("type the following text:%s \n",textType);

    printf("get reday to type in 5 seconds\n");
    sleep(5);

    printf("start typing: ");
    startTime = clock();
    fgets(userInput,MAX_TEXT_LENGTH,stdin);
    endTime = clock();

    userInput[strcspn(userInput,"\n")] = "\0";

    double timeTake = (double)(endTime-startTime)/CLOCKS_PER_SEC;
   
    Info(textType,userInput,timeTake);
}
void Info(const char *givetext,const char *userInput,double time)
{
    int correctChar =0;
    int totalCharacters = strlen(userInput);

    for(int i=0;i<totalCharacters;i++)
        if ((givetext[i]==userInput[i]))
            correctChar++;
        
    double accuracy = (double)correctChar/totalCharacters *100.0;

    int wordsTyped = strlen(userInput)/5;
    double speed = wordsTyped/(time/60);

    printf("user accuracy = %lf and user speed = %lf",accuracy,speed);
}
int main()
{
    start_typ();

    return 0;
}
