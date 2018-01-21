// constants.h
// Elin Fritiofsson
// v1.0
#ifndef constants
#define constants


    #include <iostream>
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
            void setFirstName(string s) {
                if(s.size() < 1){
                    throw invalid_argument("För kort namn");
                } else {
                    firstName = s;
                }
            }
            void setLastName(string s) {
                if(s.size() < 1){
                    throw invalid_argument("För kort namn");
                } else {
                    lastName = s;
                }
            }
            void setHeight(float h) {
                //Kontrollera att längden är rimlig (inte över 3 m). Undantag isåfall
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

    //Antal personer som visas samtidigt i listan
    const int MAX_PERSONS_IN_LIST = 20;

    //Enum for types of sorting of the list
    enum SortType {
        name,
        signature,
        height
    };

    //Enum for the different user-settable property types of the object
    enum PropertyType {
        firstNameProperty,
        secondNameProperty,
        heightProperty
    };

    const char DELIM = ',';

    /*Sista numret i menyn som används för "Avsluta." Det återanvänds flera
    gånger, därav konstanten */
    const int MAX_MENU_NUMBER = 11;

#endif
