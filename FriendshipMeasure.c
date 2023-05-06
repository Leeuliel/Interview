#include "Hacker.h"
#include "Student.h"
#include <math.h>

#define FRIENDSHIP_THRESHOLD 20
#define RIVAL_THRESHOLD -20
#define NEUTRAL_THRESHOLD 0

int friendshipMeasureByFile(void *hacker, void* student){

    Hacker h = (Hacker)hacker;
    Student s = (Student)student;

    for (int i = 0; i < h->numberFriend; i++){

        if (h->friends[i]->studentID == s->studentID){

            return FRIENDSHIP_THRESHOLD;
        }
    }

    for (int i = 0; i < h->numberRival; i++ ){

        if (h->rivals[i]->studentID == s->studentID){

            return RIVAL_THRESHOLD;

        }

    }

    return NEUTRAL_THRESHOLD;
}    

int friendshipMeasureByID(void *hacker, void* student){

    Hacker h = (Hacker)hacker;
    Student s = (Student)student;

    return (abs((atoi(h->hacker->studentID)) - (atoi(s->studentID))));
}


int friendshipMeasureByName(void *hacker, void* student){

    Hacker h = (Hacker)hacker;
    Student s = (Student)student;
    int diffName = returnDiffAsciiName(h->hacker->name, s->name);
    int diffSurname = returnDiffAsciiName(h->hacker->surname, s->surname);

    return (diffName+diffSurname);    

}

int returnDiffAsciiName (char* hackerName, char* studentName)[
 int i = 0;
 int diff = 0;


    for (;i < min(strlen(hackerName),strlen(studentName)); i++){
     
        diff = diff + abs((int)hackerName[i]-(int)studentName[i]);

    }

    if (strlen(hackerName) < strlen(studentName)){

        while (i <= strlen(studentName)){

            diff = diff + abs((int)studentName[i]);
            i++;
        }
    }else {

        while (i <= strlen(hackerName)){

            diff = diff + abs((int)hackerName[i]);
            i++;

        }
    }

]