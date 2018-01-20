#include "generalFunctions.h"
#include "constants.h"
#include "fileIO.h"

string removeSubstring(string &databaseString, const char delimiter){
    string temporary;
    //Find the first part of the line, until the first delimiter
    temporary = databaseString.substr(0, databaseString.find(delimiter));
    //Erase that part together with the delimiter
    databaseString.erase(0, databaseString.find(delimiter)+1);
    return temporary;
}

unsigned char rot(unsigned char &character, int steps) {

	unsigned char newCharacter;
	int diff;
	unsigned int ascii;
	ascii = static_cast<unsigned int>(character);
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
    //Create a string of person data separated by the delimiter
    string personInfo = p.getFirstName() + DELIM + p.getLastName() + DELIM + p.getSignature() + DELIM + to_string(p.getHeight());
    string encryptedString;
    unsigned char unsignedCharacter;
    //Encrypt every char in the person data string
    for(auto c: personInfo){
        unsignedCharacter = static_cast<unsigned char>(c);
        encryptedString += rot(unsignedCharacter, steps);
    }
    return encryptedString;
}

Person decryptPerson(string encryptedString, int steps){
    string personInfo;
    unsigned char unsignedCharacter;
    //Decrypt every har in "encrypted string"
    for(auto c: encryptedString){
        unsignedCharacter = static_cast<unsigned char>(c);
        personInfo += rot(unsignedCharacter, steps*-1);
    }
    //Create a new person with the data extracted from the decrypted string
    Person nyPerson;
    nyPerson.setFirstName(removeSubstring(personInfo, DELIM));
    nyPerson.setLastName(removeSubstring(personInfo, DELIM));
    nyPerson.setSignature(removeSubstring(personInfo, DELIM));

    //Set height using conversion from string to float and catch exception if this fails
    try {
       nyPerson.setHeight(stof(removeSubstring(personInfo, DELIM)));
    } catch (exception const &e) {
       throw;
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
    //Encrypt every person in the vector and print to file
    for(const auto &p: personer){
        encryptedString = encryptPerson(p, encryptionKey);
        outFile << encryptedString << endl;
    }
    outFile.close();
    returnToMenu();
}

void readFromFile(vector <Person> &personer){
    bool found = false;

    cout << "Skriv filens namn (t.ex. \"minfil.txt\")" << endl;
    string fileName;
    cin >> fileName;
    cout << "Ange ursprunglig krypteringsnyckel (positivt tal)" << endl;
    int encryptionKey;
    cin >> encryptionKey;
    ifstream inFile(fileName);
    if(inFile){
        found = true;
        personer.clear();
        string encryptedString;
        string decryptedString;
        Person nyPerson;
        int line = 0;
        //Decrypt every line in the file and add as new person to vector personer
        try {
            while (getline(inFile, encryptedString)) {
                nyPerson = decryptPerson(encryptedString, encryptionKey);
                personer.push_back(nyPerson);
            }
            inFile.close();
            cout << "Filen lästes in." << endl;
        } catch (exception const &e) {
            cout << "Orimlig längd på person hittades i filen." << endl;
            cout << "Inmatningen avbryts. Kontrollera att du angav rätt krypteringsnyckel" << endl;
            cout << "Inmatade data raderas" << endl;
            personer.clear();
        }
    } else {
        cout << "Filen hittades ej" << endl;
    }

    returnToMenu();
}
