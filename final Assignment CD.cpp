#include <iostream>
using namespace std;

bool isAccepted(string str) {
    int state = 0;

    for(char ch : str) {
        switch(state) {
            case 0:
                if(ch == 'a') state = 1;
                else return false;
                break;

            case 1:
                if(ch == 'b') state = 1;
                else if(ch == 'a') state = 2;
                else return false;
                break;

            case 2:
                if(ch == 'a') state = 2;
                else if(ch == 'b') state = 3;
                else return false;
                break;

            case 3:
                if(ch == 'b') state = 3;
                else return false;
                break;
        }
    }

    return (state == 1 || state == 2 || state == 3);
}

int main() {
    string input;
    char choice;

    do {
        cout << "Enter a string: ";
        cin >> input;

        if(isAccepted(input))
            cout << input << " -> Accepted\n";
        else
            cout << input << " -> Rejected\n";

        cout << "Try again? (y/n): ";
        cin >> choice;

    } while(choice == 'y' || choice == 'Y');

    return 0;
}
