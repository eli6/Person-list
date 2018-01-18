#include "constants.h"

void Person::lowercase() {
    for(auto &c: firstName){
        c = tolower(c);
    }
    for(auto &c: lastName){
        c = tolower(c);
    }
}

void Person::addSignature(vector<Person> personer){
  //----------------------------------------------------------------------------
  // Adds unique signature xxxyyyzz for a Person
  //----------------------------------------------------------------------------
    string signature;
  //First name part (xxx)
    for(int i = 0; i < 3; i++){
        if ( i > (this->firstName.size()-1)) {
            signature += 'x';
        } else {
            signature += this->firstName[i];
        }
    }

  //Last name part (yyy)
    for(int i = 0; i < 3; i++){
        if ( i > (this->lastName.size()-1)) {
            signature += 'x';
        } else {
            signature += this->lastName[i];
        }
    }

    //Checks if the signature is unique, if not, the serial number is augmented
    int serialNumber = 1;

    for(auto i: personer){
        i.signature.pop_back();
        i.signature.pop_back();
        if(i.signature == signature){
            serialNumber += 1;
        }
    }

    for(auto &c: signature){
        c = tolower(c);
    }

    //Add serial number (zz) to signature (with a preceding 0 if it's below 10)
    if (serialNumber > 9){
        signature += to_string(serialNumber);
    } else {
        signature += to_string(0) + to_string(serialNumber);
    }

    this->signature = signature;

}
