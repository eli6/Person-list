// functions.cpp
// Elin Fritiofsson
// v1.0

#include "listFunctions.h"
#include "mainFunctions.h"
#include "constants.h"



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


bool areIdentical(Person p1, Person p2){
    p1.lowercase();
    p2.lowercase();
    if(p1.getFirstName() == p2.getFirstName() &&
        p1.getLastName() == p2.getLastName() &&
        p1.getLength() == p2.getLength()){
        return true;
    } else {
        return false;
    }
}


void printHeadlines(){
    cout << setw(15) << left << "Nr" << setw(18) << left << "Sign" << setw(20) << left << fixed << "Name" << setw(15) << right << "Length [m]" << endl;
    printLine();
}

void printPersonData(Person p, int number){
    cout << fixed << setprecision(2);
    if(number > 0){
        cout << setw(15) << left << to_string(number) + ". ";
    } else {
        cout << setw(15) << left << "--";
    }
    cout << setw(18) << left << p.getSignature() << setw(20) << left << fixed << p.getFirstName() + " " + p.getLastName() << setw(15) << right << p.getLength() << endl;
}

void addPersonTo(vector<Person> &personer){

    Person newPerson;
    bool finished = false;

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

        if(personer.size() > 0){

            for(auto p: personer){
                if(areIdentical(p, newPerson)){
                    notUnique = true;
                }
            }

            if(notUnique == true){
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

    } while(finished != true);

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

vector<Person>::const_iterator findIndexWithSignatureIn(vector <Person> &personer){

    string signature;

    cout << "Ange signaturen för den person du vill söka efter" << endl;
    cin >> signature;
    printLine();
    auto it =
    find_if(personer.begin(), personer.end(), [&signature](Person &p) {

        return p.getSignature() == signature;

    });

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
        vector<Person>::const_iterator it = findIndexWithSignatureIn(personer);

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
        if(it != personer.end()) {
            string signature = it->getSignature();
            personer.erase(it);
            cout << "Personen " << signature << " har tagits bort." << endl;
        }
    } while(userWantsToRepeat("Vill du ta bort en annan person?") != 'N');
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

void randomize(vector <Person> personer){
    random_shuffle(personer.begin(), personer.end());
    printOnScreen(personer);
}

string removeSubstring(string &databaseString, const char delimiter){
    string temporary;
    temporary = databaseString.substr(0, databaseString.find(delimiter));
    databaseString.erase(0, databaseString.find(delimiter)+1);
    return temporary;
}

unsigned char rot(unsigned char &character, int steps) {

	unsigned char newCharacter;
	int diff;
	unsigned int ascii;
	ascii = int(character);
	//For converted numbers exceeding 255 -> resume from 32.
	if (ascii + steps > 255) {
        diff = 255 - ascii;
		ascii = 32 - diff;
	}

	//For converted numbers below 32 -> add 224 to continue "backwards" instead.
	if (ascii + steps < 32) {
		ascii += 224;
	}

	ascii += steps;
	newCharacter = char(ascii);
	return newCharacter;
}

string encryptPerson(Person p, int steps){
    string personInfo = p.getFirstName() + DELIM + p.getLastName() + DELIM + p.getSignature() + DELIM + to_string(p.getLength());
    string encryptedString;
    unsigned char unsignedCharacter;
    for(auto c: personInfo){
        unsignedCharacter = static_cast<unsigned char>(c);
        encryptedString += rot(unsignedCharacter, steps);
    }
    return encryptedString;
}

Person decryptPerson(string encryptedString, int steps){
    string personInfo;
    unsigned char unsignedCharacter;
    for(auto c: encryptedString){
        unsignedCharacter = static_cast<unsigned char>(c);
        personInfo += rot(unsignedCharacter, steps*-1);
    }
    Person nyPerson;
    nyPerson.setFirstName(removeSubstring(personInfo, DELIM));
    nyPerson.setLastName(removeSubstring(personInfo, DELIM));
    nyPerson.setSignature(removeSubstring(personInfo, DELIM));
    try {
        nyPerson.setLength(stoi(removeSubstring(personInfo, DELIM)));
    } catch (exception const &e) {
        cout << "Fel när längden lästes in: " << e.what() << endl;
    }
    return nyPerson;
}

void saveToFile(vector <Person> personer){
    cout << "Skriv vad filen ska heta (t.ex. \"minfil.txt\")" << endl;
    string fileName;
    cin >> fileName;
    cout << "Ange krypteringsnyckel" << endl;
    int encryptionKey;
    cin >> encryptionKey;
    string encryptedString;
    ofstream outFile(fileName.c_str());
    for(auto p: personer){
        encryptedString = encryptPerson(p, encryptionKey);
        outFile << encryptedString << endl;
    }
    outFile.close();
}

void readFromFile(vector <Person> &personer){
    cout << "Skriv filens namn (t.ex. \"minfil.txt\")" << endl;
    string fileName;
    cin >> fileName;
    cout << "Ange ursprunglig krypteringsnyckel (positivt tal)" << endl;
    int encryptionKey;
    cin >> encryptionKey;
    ifstream inFile(fileName);
    personer.clear();
    string encryptedString;
    string decryptedString;
    Person nyPerson;
    while(getline(inFile, encryptedString)){
        nyPerson = decryptPerson(encryptedString, encryptionKey);
        personer.push_back(nyPerson);
    }

    inFile.close();
}
