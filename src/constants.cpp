#include "constants.h"

void Person::lowercase() {
    for(auto &c: firstName){
        c = static_cast<char>(tolower(c));
    }
    for(auto &c: lastName){
        c = static_cast<char>(tolower(c));
    }
}

void Person::addSignature(vector<Person> personer){
  //----------------------------------------------------------------------------
  // Adds unique signature xxxyyyzz for a Person
  //----------------------------------------------------------------------------
    string newSignature;
  //First name part (xxx)
    for(int i = 0; i < 3; i++){
        if ( i > (this->firstName.size()-1)) {
            newSignature += 'x';
        } else {
            newSignature += this->firstName[i];
        }
    }

  //Last name part (yyy)
    for(int i = 0; i < 3; i++){
        if ( i > (this->lastName.size()-1)) {
            newSignature += 'x';
        } else {
            newSignature += this->lastName[i];
        }
    }

    for(auto &c: newSignature){
        c = static_cast<char>(tolower(c));
    }

    //Checks if the signature is unique, if not, the serial number is augmented
    int serialNumber = 1;

    for(auto i: personer){
        //Remove the serial number from the person's signature for comparison
        i.signature.pop_back();
        i.signature.pop_back();
        if(i.signature == newSignature){
            serialNumber += 1;
        }
    }



    //Add serial number (zz) to signature (with a preceding 0 if it's below 10)
    if (serialNumber > 9){
        newSignature += to_string(serialNumber);
    } else {
        //Add a 0 if the number is one-digit
        newSignature += to_string(0) + to_string(serialNumber);
    }

    this->signature = newSignature;

}
