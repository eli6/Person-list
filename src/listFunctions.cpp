// functions.cpp
// Elin Fritiofsson
// v1.0

#include "listFunctions.h"
#include "mainFunctions.h"
#include "constants.h"

bool signatureSort(const Person &a, const Person &b){
  return a.signature < b.signature;
}

bool lengthSort(const Person &a, const Person &b){
  return a.length > b.length;
}

bool nameSort(const Person &a, const Person &b){
    string nameForSorting1 = a.lastName + a.firstName;
    string nameForSorting2 = b.lastName + b.firstName;
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
  cout << setw(18) << left << p.signature << setw(20) << left << fixed << p.firstName + " " + p.lastName << setw(15) << right << p.length << endl;
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
          //cin.get();
        } while(!(choice == 1 || choice == 2));
      if(choice == 1){
        finished = false;
      } else if(choice == 2) {
        cout << "choice 2" << endl;
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

    //Prints as many persons (if they exist) at a time as specified in the constant "maxPersonsShownInList" in "constants.h"
    printHeadlines();
    for(size_t i = 0; i < maxPersonsShownInList; i++){
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

int findIndexWithSignatureIn(vector <Person> personer){
  string signature;

  cout << "Ange signaturen för den person du vill söka efter" << endl;
  cin >> signature;
  printLine();
  if(personer.size() > 0){
    for(size_t i=0; i<personer.size(); i++){
      if(personer[i].signature == signature){
        return i;
      }
    }
    cout << "Personen finns tyvärr inte i listan" << endl;
    return -1;
  } else {
      cout << "Listan är tom. Personen hittades inte." << endl;
      return -1;
  }

  return -1;
}

void searchIn(vector <Person> personer){

  //----------------------------------------------------------------------------
  // Finds the index of the person with a certain signature
  // and prints the persons details on screen
  //----------------------------------------------------------------------------
  do {
    int index;
    index = findIndexWithSignatureIn(personer);
    if(index>=0) {
      Person p = personer[index];
      cout << "Resultat: " << endl;
      printLine();
      printHeadlines();
      printPersonData(p, index+1);
    }
  } while(userWantsToRepeat("Vill du söka igen?") != 'N');

}


void removeFrom(vector <Person> &personer){
  do {
    int index;
    index = findIndexWithSignatureIn(personer);
    if(index>=0) {
          personer.erase(personer.begin()+index);
          cout << "Person med signatur " << personer[index].signature << " har tagits bort." << endl;
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
  printHeadlines();
  for(auto p: personer){
    printPersonData(p, 0);
  }
}
