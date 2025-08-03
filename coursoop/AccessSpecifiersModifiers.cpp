#include <iostream>
using namespace std;
class clsPerson
{
private:
    // only accessable inside this calass
    int Variabl1 = 5;
    int Function1()
    {
        return 40;
    }

protected:
    // only accessable inside this calass and all classes inhirets  this calss
    int Variabl2 = 100;
    int Function2()
    {
        return 50;
    }

public: // accessable for everyone outside/inside/and classes inherits  this class
    string FirstName;
    string LastName;
    string FullName()
    {
        return FirstName + " " + LastName;
    }
    float Function3()
    {
        return Function1() * Variabl1;
        class
            clsPerson
        {
        private:
            // only accessable inside this calass
            int
                Variabl1 = 5;
            int
            Function1()
            {
                return 40;
            }

        protected:
            // only accessable inside this calass and all classes inhirets
            this calss int
                Variabl2 = 100;
            int
            Function2()
            {
                return 50;
            }

        public:
            // accessable for everyone outside/inside/and classes inherits
            this class
                string
                    FirstName;
            string
                LastName;
            string
            FullName()
            {
                return FirstName +
                       " " + LastName;
            }
            float
            Function3()
            {
                return Function1() * Variabl1 * Variabl2;
            }
        };
    }
};