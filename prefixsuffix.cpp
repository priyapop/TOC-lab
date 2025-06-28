#include <iostream>
using namespace std;
void prefix(string);
void suffix(string);
void substring(string);
int main()
{
    string str;
    int no;
    cout << "enter a string";
    cin >> str;
    while (1)
    {
        cout << "\n1. Prefix \n2. Suffix \n3. Substring \n4.Exit\n\nEnter your choice: ";

        cin >> no;
        switch (no)
        {
        case 1:
        {
            prefix(str);
            break;
        }
        case 2:
        {
            suffix(str);
            break;
        }
        case 3:
        {
            substring(str);
            break;
        }
        case 4:
        {
            exit(0);
        }
        default:
                cout<<"invalid choice";
        }
    }
}

void prefix(string str)
{
    string temp;
    for (int i = 0; i < str.length(); i++)
    {
        temp += str[i];
        cout << temp << endl;
    }
}
void suffix(string str)
{
    string temp = "";
    for (int i = str.length(); i >= 0; i--)
    {
        temp = str[i] + temp;
        cout << temp << endl;
    }
}

void substring(string str)
{

    for (int i = 0; i < str.length(); i++)
    {
        string temp = "";
        for (int j = i; j < str.length(); j++)
        {
            temp += str[j];
            cout << temp << endl;
        }
    }
}
