#include "generalFunctions.h"
#include "constants.h"
#include "addSearchRemove.h"

bool areIdentical(Person p1, Person p2){
    //Make the person data lowercase
    p1.lowercase();
    p2.lowercase();
    //If persons are equal, return true
    return p1.getFirstName() == p2.getFirstName() &&
        p1.getLastName() == p2.getLastName() &&
        p1.getLength() == p2.getLength();
}

void addPersonTo(vector<Person> &personer){

    Person newPerson;
    bool finished = false;

    do {
        do {
            finished = false;
            //----------------------------------------------------------------------------
            // User enters newPerson data
            //----------------------------------------------------------------------------
            string firstName;
            string lastName;
            float length;

            cout << "Ange personens förnamn: " << endl;
            getline(cin, firstName);
            newPerson.setFirstName(firstName);
            cout << "Ange efternamn: " << endl;
            getline(cin, lastName);
            newPerson.setLastName(lastName);
            cout << "Ange personens längd: " << endl;
            cin >> length;
            cin.get();
            newPerson.setLength(length);

            //----------------------------------------------------------------------------
            // Checks if the new person is unique.
            //----------------------------------------------------------------------------
            bool notUnique = false;

            if(!personer.empty() > 0){

                for(auto p: personer){
                    if(areIdentical(p, newPerson)){
                        notUnique = true;
                    }
                }

                if(notUnique){
                    //The user chooses what to do in case the person isn't unique
                    int choice = 0;
                    cout << "Denna person finns redan. Välj ett alterantiv nedan:" << endl;
                    cout << "1. Ändra inmatning" << endl;
                    cout << "2. Avbryt" << endl;
                    do {
                        cin >> choice;
                        cin.get();
                        printLine();
                    } while(!(choice == 1 || choice == 2));
                    if(choice == 1){
                        //Sets variable that lets us continue in this loop to add data
                        finished = false;
                    } else if(choice == 2) {
                        cout << "choice 2" << endl;
                        finished = true;
                    }
                } else {
                    //Add the new person to the vector of persons
                    newPerson.addSignature(personer);
                    personer.push_back(newPerson);
                    finished = true;
                }

            } else {
                //Add the new person to the vector of persons
                newPerson.addSignature(personer);
                personer.push_back(newPerson);
                finished = true;
            }

        } while(!finished);
    } while(userWantsToRepeat("Vill du lägga till en till person?") != 'N');
}


vector<Person>::const_iterator findIndexWithSignatureIn(vector <Person> &personer){

    string signature;

    cout << "Ange signaturen för den person du vill söka efter" << endl;
    cin >> signature;
    printLine();

    auto it =
    find_if(personer.begin(), personer.end(), [&signature](Person &p) {
        //Try to find a person with that signature
        return p.getSignature() == signature;

    });
    //If person found, return iterator to it
    if(it != personer.end()){
        return it;
    }
    cout << "Personen hittades inte" << endl;
    return it;
}

void searchIn(vector <Person> personer){

  //----------------------------------------------------------------------------
  // Finds the index of the person with a certain signature
  // and prints the persons details on screen
  //----------------------------------------------------------------------------
    do {
        auto it = findIndexWithSignatureIn(personer);

        //If we have an iterator to a found person, print that person's data
        if(it!=personer.end()) {
            Person p = *it;
            cout << "Resultat: " << endl;
            printLine();
            printHeadlines();
            printPersonData(p, 0);
        }
    } while(userWantsToRepeat("Vill du söka igen?") != 'N');

}

void removeFrom(vector <Person> &personer){
    do {
        vector<Person>::const_iterator it;
        it = findIndexWithSignatureIn(personer);
        /*If we have an iterator to a found person, erase the person and
        show a message */
        if(it != personer.end()) {
            string signature = it->getSignature();
            personer.erase(it);
            cout << "Personen " << signature << " har tagits bort." << endl;
        }
    } while(userWantsToRepeat("Vill du ta bort en annan person?") != 'N');
}
