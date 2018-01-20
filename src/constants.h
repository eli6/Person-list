// constants.h
// Elin Fritiofsson
// v1.0
#ifndef constants
#define constants


    #include <string>
    #include <vector>
    #include <algorithm>
    #include <cctype>
    using namespace std;

    struct Person {
        private:
            string firstName;
            string lastName;
            string signature;
            float height;
        public:
            void setFirstName(string s) { firstName = s; }
            void setLastName(string s) { lastName = s; }
            void setHeight(float h) {
                if(h > 3){
                       throw invalid_argument("Orimlig längd");
               } else {
                   height = h;
               }
            }
            void setSignature(string s) { signature = s; }

            string getFirstName() const { return firstName; }
            string getLastName() const { return lastName; }
            string getSignature() const { return signature;}
            float getHeight() const { return height; }

            void lowercase();
            void addSignature(vector <Person> personer);

    };

    const int MAX_PERSONS_IN_LIST = 2;

    enum SortType {
        name,
        signature,
        height
    };

    const char DELIM = ',';
    const int MAX_MENU_NUMBER = 11;

#endif
