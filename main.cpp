#include <iostream>
#include <cstring>

using namespace std;

int check_input(string str)
{
    try {

        size_t pos = 0 ;
        stoi( str, std::addressof(pos) ) ;
        while(isspace( str.back() ) ) str.pop_back() ;
        return pos == str.size() ; // fully parsed except for white space at the end
    }

    catch( const std::exception& ) { return false ; }
}

void show_flag(string flag)
{
    if (flag == "UXQQR=^RPMTQ\\IRO")
        cout << flag << endl;
    else
        cout << "How?" << endl;
}

void decrypt_flag(string flag, string user_flag)
{
     string true_flag = "";
     char flg[flag.length() + 1];
     strcpy(flg, flag.c_str());
     int counter = 0;
     do
     {
         flg[counter] ^= 0x1A;
         ++counter;
     } while(counter <= flag.length());
     counter = 0;
     while(counter <= flag.length())
     {
          flg[counter] ^= 0x07;
          true_flag += flg[counter];
          ++counter;
     }
     if (true_flag.compare(user_flag) == 1)
     {
          cout << "Congratulations! Here is your flag" << endl;
          cout << true_flag << endl;
     }
     cout << "Bye!" << endl;
}

void select_mode(int mode, string user_flag)
{
    string flag = "UXQQR=^RPMTQ\\IRO";
    switch(mode)
    {
        case 1:
            show_flag(flag);
            break;
        case 2:
            decrypt_flag(flag, user_flag);
            break;
        case 3:
            goto secret;
            break;
        default:
            secret:
                cout << "Congratulations! H" << endl;
            cout << "How?????" << endl;
            break;
    }
}

int main()
{
    string user_flag = "";
    string selected_mode = "";
    cout << "Welcome to my test program. Please select operation mode (1-3)" << endl;
    cin >> selected_mode;
    if (!check_input(selected_mode))
    {
        cout << "Wrong" << endl;
        return 1;
    }
    int mode = stoi(selected_mode);
    if (mode > 3 || mode <= 0)
    {
        cout << "Wrong" << endl;
        return 1;
    }
    cout << "Enter super secret flag... ";
    getline(cin >> ws, user_flag);
    select_mode(mode, user_flag);
	for (int i = 0; i < 10; ++i)
		cout << ".";
    return 0;
}
