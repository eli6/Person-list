// functions.cpp
// Elin Fritiofsson
// v1.0
#include "generalFunctions.h"
#include "constants.h"


char userWantsToRepeat(string question){
    char again;
    printLine();
    cout << question << " (j/n)" << endl;
    do {
        cin >> again;
        printLine();
        cin.get();
        again = toupper(again);
    } while( !(again == 'J' || again == 'N'));
    return again;
}

void printLine(){
    cout << "------------------------------------------------------------------------" << endl;
}

void checkIfNumber(int &variable){
    bool correctInput = false;
    do {
        cin >> variable;
        cin.get();

        if(!cin) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Ange ett tal" << endl;
            correctInput = false;
        } else {
            correctInput = true;
        }
    } while(correctInput != true);
}

int printMenu(vector<string> menuChoices){

    int choice = 0;

    cout << endl;
    printLine();
    cout <<  "Menyval:" << endl;
    printLine();
    cout << endl;

    for(size_t i = 0; i < menuChoices.size(); i++){

        cout << i+1 << ". " << menuChoices[i] << endl;

    }
    printLine();

    do {
        checkIfNumber(choice);
        if(choice > MAX_MENU_NUMBER){
            cout << "Ange ett tal mellan 1 och " << MAX_MENU_NUMBER << endl;
        }
    } while(choice > MAX_MENU_NUMBER);

    return choice;
}

void printHeadlines(){
    cout << setw(15) << left << "Nr" << setw(18) << left << "Sign" << setw(20) << left << fixed << "Name" << setw(15) << right << "Length [m]" << endl;
    printLine();
}

void printPersonData(Person p, int number){
    cout << fixed << setprecision(2);
    if(number > 0){
        //Adds a number first on each line
        cout << setw(15) << left << to_string(number) + ". ";
    } else {
        //If the number is below 1, don't add a number (for example in searches)
        cout << setw(15) << left << "--";
    }
    cout << setw(18) << left << p.getSignature() << setw(20) << left << fixed << p.getFirstName() + " " + p.getLastName() << setw(15) << right << p.getLength() << endl;
}



void printOnScreen(vector<Person> personer){

    cout << endl;
    cout << "*************************************************"<< endl;
    cout << setw(10) << "" << "UTSKRIFT AV LISTAN" << endl;
    cout << "*************************************************" << endl;
    cout << endl;


    int number;
    char continues = 'N';
    int tracker = 0;
    int maxIndex = int(personer.size()-1);


    //----------------------------------------------------------------------------
    // Displays the users in a list with a constant number of posts per page
    // until there are no persons left or until the user taps "n" when asked
    // if he/she wants to continue
    //----------------------------------------------------------------------------
    do{

        //Prints as many persons (if they exist) at a time as specified in the constant "MAX_PERSONS_IN_LIST" in "constants.h"
        printHeadlines();
        for(size_t i = 0; i < MAX_PERSONS_IN_LIST; i++){
            if(tracker <= maxIndex){
                number = tracker+1;
                Person p = personer[tracker];
                printPersonData(p, number);
                number++;
            } else {
                continues = 'N';
            }
            tracker++;
        }
        // If there are persons left to display: asks if the user wants to display them
        if((maxIndex - tracker) >= 0){
            continues = userWantsToRepeat("Visa fler personer?");
        }

    } while(continues != 'N');

}
