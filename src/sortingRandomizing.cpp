#include "generalFunctions.h"
#include "constants.h"
#include "sortingRandomizing.h"

void randomize(vector <Person> personer){
    random_shuffle(personer.begin(), personer.end());
    printOnScreen(personer);
}

bool signatureSort(const Person &a, const Person &b){
    return a.getSignature() < b.getSignature();
}

bool lengthSort(const Person &a, const Person &b){
    return a.getLength() > b.getLength();
}

bool nameSort(const Person &a, const Person &b){
    string nameForSorting1 = a.getLastName() + a.getFirstName();
    string nameForSorting2 = b.getLastName() + b.getFirstName();
    cout << nameForSorting1 << endl;
    cout << nameForSorting2 << endl;
    for(auto &c : nameForSorting1){
        c = tolower(c);
    }
    for(auto &c : nameForSorting2){
        c = tolower(c);
    }
    return nameForSorting1 < nameForSorting2;
}

void sortBy(SortType type, vector <Person> personer){
    switch(type) {
        case signature:
            sort(personer.begin(), personer.end(), signatureSort);
            break;
        case name:
            sort(personer.begin(), personer.end(), nameSort);
            break;
        case length:
            sort(personer.begin(), personer.end(), lengthSort);
            break;
        }
        printOnScreen(personer);
}
