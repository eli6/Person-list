// functions.cpp
// Elin Fritiofsson
// v1.0

#include "listFunctions.h"
#include "mainFunctions.h"


void convertToLower(Person &p){
  transform(p.firstName.begin(), p.firstName.end(), p.firstName.begin(), ::tolower);
  transform(p.lastName.begin(), p.lastName.end(), p.lastName.begin(), ::tolower);
}

bool areIdentical(Person p1, Person p2){
  convertToLower(p1);
  convertToLower(p2);
  if(p1.firstName == p2.firstName &&
      p1.lastName == p2.lastName &&
      p1.length == p2.length){
        return true;
  } else {
    return false;
  }
}

void addSignature(Person &person, vector<Person> personer){
  //----------------------------------------------------------------------------
  // Adds unique signature xxxyyyzz for a Person
  //----------------------------------------------------------------------------

  //First name part (xxx)
  for(int i = 0; i < 3; i++){
      if ( i > (person.firstName.size()-1)) {
        person.signature += 'x';
      } else {
        person.signature += person.firstName[i];
      }
  }

  //Last name part (yyy)
  for(int i = 0; i < 3; i++){
      if ( i > (person.lastName.size()-1)) {
        person.signature += 'x';
      } else {
        person.signature += person.lastName[i];
      }
  }

  //Checks if the signature is unique, if not, the serial number is augmented
  int serialNumber = 1;

  for(auto i: personer){
    i.signature.pop_back();
    i.signature.pop_back();
    if(i.signature == person.signature){
      serialNumber += 1;
    }
  }

  //Add serial number (zz) to signature (with a preceding 0 if it's below 10)
  if (serialNumber > 9){
    person.signature += to_string(serialNumber);
  } else {
    person.signature += to_string(0) + to_string(serialNumber);
  }


}

void addPersonTo(vector<Person> &personer){

  Person newPerson;
  bool finished = false;

  do {
    finished = false;
    //----------------------------------------------------------------------------
    // User enters newPerson data
    //----------------------------------------------------------------------------
    cin.get();
    cout << "Ange personens förnamn: " << endl;
    getline(cin, newPerson.firstName);
    cout << "Ange efternamn: " << endl;
    getline(cin, newPerson.lastName);
    cout << "Ange personens längd: " << endl;
    cin >> newPerson.length;


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
          printLine();
          //necessary?
          cin.get();
        } while(!(choice == '1' || choice == '2'));
      if(choice == 1){
        finished = false;
      } else if(choice == 2) {
        finished = true;
      }
    } else {
      //Add the new person to the vector of persons
      addSignature(newPerson, personer);
      personer.push_back(newPerson);
      finished = true;
    }

    } else {
      //Add the new person to the vector of persons
      addSignature(newPerson, personer);
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


  int number = 1;
  char continues = 'N';
  int tracker = 0;
  int maxIndex = int(personer.size()-1);


  //----------------------------------------------------------------------------
  // Displays the users in a list with a constant number of posts per page
  // until there are no persons left or until the user taps "n" when asked
  // if he/she wants to continue
  //----------------------------------------------------------------------------
  do{

    cout << setw(15) << left << "Nr. " << setw(18) << left << "Sign" << setw(20) << left << fixed << "Name" << setw(15) << right << "Length [m]" << endl;

    //Prints as many persons (if they exist) at a time as specified in the constant "maxPersonsShownInList" in "constants.h"
    for(size_t i = 0; i < maxPersonsShownInList; i++){
      if(tracker <= maxIndex){
        cout << fixed << setprecision(2);
        cout << setw(15) << left << to_string(number) + ". " << setw(18) << left << personer[tracker].signature << setw(20) << left << fixed << personer[tracker].firstName + " " + personer[tracker].lastName << setw(15) << right << personer[tracker].length << endl;
        number++;
      } else {
        continues = 'N';
      }
      tracker++;
    }


    // If there are persons left to display: asks if the user wants to display them
    if((maxIndex - tracker) >= 0){
      printLine();
      cout << "Visa fler personer (j/n)?" << endl;
      do {
          cin >> continues;
          printLine();
          cin.get();
          continues = toupper(continues);
        } while( !(continues == 'J' || continues == 'N'));
    }

  } while(continues != 'N');

}

void searchIn(vector <Person> personer){

  char again;

  do {
    string signature;


    cout << "Ange signaturen för den person du vill söka efter" << endl;
    cin >> signature;

    //If the vector isn't empty, check if the signature is there
    //then print the data for that person
    if(personer.size() > 0){
      for(auto p: personer){
        if(p.signature == signature){
          printLine();
          cout << "Resultat: " << endl;
          printLine();
          cout << setw(18) << left << "Sign" << setw(20) << left << fixed << "Name" << setw(15) << right << "Length [m]" << endl;
          cout << setw(18) << left << p.signature << setw(20) << left << fixed << p.firstName + " " + p.lastName << setw(15) << right << p.length << endl;
        } else {
          cout << "Personen finns tyvärr inte i listan" << endl;
        }
      }
    } else {
      cout << "Listan är tom. Personen hittades inte." << endl;
    }
    printLine();
    cout << "Vill du söka igen (j/n)?" << endl;
    do {
      cin >> again;
      printLine();
      cin.get();
      again = toupper(again);
    } while( !(again == 'J' || again == 'N'));
  } while(again != 'N');

}

void removeFrom(vector <Person> &personer){
  char again;

  do {
    string signature;


    cout << "Ange signaturen för den person du vill ta bort" << endl;
    cin >> signature;

    //If the vector isn't empty, check if the signature is there
    //then print the data for that person
    if(personer.size() > 0){
      for(size_t i=0; i<personer.size(); i++){
        if(personer[i].signature == signature){
          printLine();
          personer.erase(personer.begin()+i);
          cout << "Person med signatur " << personer[i].signature << " har tagits bort." << endl;

        } else {
          cout << "Personen finns tyvärr inte i listan och kunde inte tas bort." << endl;
        }
      }
    } else {
      cout << "Listan är tom. Personen kan inte tas bort" << endl;
    }
    printLine();
    cout << "Vill du ta bort en annan person (j/n)?" << endl;
    do {
      cin >> again;
      printLine();
      cin.get();
      again = toupper(again);
    } while( !(again == 'J' || again == 'N'));
  } while(again != 'N');
}
