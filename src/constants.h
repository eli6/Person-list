// constants.h
// Elin Fritiofsson
// v1.0
#ifndef constants
#define constants


    #include <string>
    #include <vector>
    #include <algorithm>
    #include <ctype.h>
    using namespace std;

    struct Person {
        private:
            string firstName;
            string lastName;
            string signature;
            float length;
        public:
            void setFirstName(string s) { firstName = s; }
            void setLastName(string s) { lastName = s; }
            void setLength(float l) { length = l; }
            void setSignature(string s) { signature = s; }

            string getFirstName() const { return firstName; }
            string getLastName() const { return lastName; }
            string getSignature() const { return signature;}
            float getLength() const { return length; }

            void lowercase();
            void addSignature(vector <Person> personer);

    };

    const int MAX_PERSONS_IN_LIST = 2;

    enum SortType {
        name,
        signature,
        length
    };

    const char DELIM = ',';
    const int MAX_MENU_NUMBER = 11;

#endif
