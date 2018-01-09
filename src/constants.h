// constants.h
// Elin Fritiofsson
// v1.0
#ifndef constants
#define constants

  using namespace std;
  #include <string>
  #include <algorithm>

  struct Person {
    private:
      string firstName;
      string lastName;
      string signature;
      float length;
    public:
      void setFirstName(string s) { firstName = s; }
      void setLastName(string s) { lastName = s; }
      void setSignature(string s) { signature = s; }
      void setLength(float l) { length = l; }

      string getFirstName() const { return firstName; }
      string getLastName() const { return lastName; }
      string getSignature() const { return signature;}
      float getLength() const { return length; }

      void addSignature(vector<Person> personer){
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

        //Add serial number (zz) to signature (with a preceding 0 if it's below 10)
        if (serialNumber > 9){
          signature += to_string(serialNumber);
        } else {
          signature += to_string(0) + to_string(serialNumber);
        }

        this->setSignature(signature);

      }
  };

  const int maxPersonsShownInList = 2;

  enum SortType {
    name,
    signature,
    length
  };

  const char DELIM = ',';
  const int MAX_MENU_NUMBER = 11;

#endif
