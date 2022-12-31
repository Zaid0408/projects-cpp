#include <iostream>
#include<fstream>
#include<sstream>   //to provide templates and type that enable inter operation between string buffer and string types
#include<string>

using namespace std;
int main()
{

    int a,i=0,j=0;
    string text,old,password0,password1,password2,pass,name,age,user,word,word1,cp[100],creds[100];
    
    cout<<"         Security System         "<<endl<<endl;
    cout<<"_________________________________"<<endl;
    cout<<"|        1.Register             |"<<endl;
    cout<<"|        2.Login                |"<<endl;
    cout<<"|        3.Change password      |"<<endl;
    cout<<"|________4.End program__________|"<<endl;
    do
    {
        cout<<"Enter a choice:"<<endl;
        cin>>a;
        switch(a)
        {
            case 1:
            {
                cout<<"_________________________________"<<endl;
                cout<<"|-----------REGISTER------------|"<<endl;
                cout<<"|_______________________________|"<<endl<<endl;
                cout<<"Enter the following credentials for registering:"<<endl<<endl;
                cout<<"Enter your username:"<<endl;
                cin>>name;
                cout<<"Enter your password:"<<endl;
                cin>>password0;
                cout<<"Enter your age:"<<endl;
                cin>>age;
                ofstream of1;   //creating an object of type ofstream class; ofsream helps us to read write and change contents in a particular file
                of1.open("file.txt");//creating a text file or opening it if it already exists
                if(of1.is_open())
                {
                    of1<<name<<"\n";
                    of1<<password0<<"\n";//readind data in the file
                    cout<<"Registration is Successful!"<<endl;
                }
                break;
            }
            case 2:
            {
                cout<<"_________________________________"<<endl;
                cout<<"|-------------LOGIN-------------|"<<endl;
                cout<<"|_______________________________|"<<endl<<endl;
                cout<<"Enter your username :-  ";
                cin>>name;
                cout<<"Enter your password :-  ";
                cin>>password0;

                ifstream if1;// ifstream class only helps in reading the cotents of the file
                if1.open("file.txt");
                if(if1.is_open())
                {
                    while(!if1.eof)// if file is open then it while go line by line to the end of the file
                    {
                        while(getline(if1,text))//to go through all the lines of the file
                        {
                            istringstream iss(text); //this class is used to stream the contents of the file
                            iss>>word;//using extraction operator to extract the word from the text file and the store it in credentials array to compare the details
                            creds[i]=word;
                            i++;
                        }
                    }
                    int d=1,b=0,c=1;
                    while(!if1.eof && i>=c)
                    {
                        if(creds[b]==user && pass ==creds[c])
                        {
                            cout<<"|-------LOGIN SUCCESSFUL--------|"<<endl<<endl;
                            cout<<"User details are:"<<endl;
                            cout<<"Username is :- "<<user<<endl;
                            cout<<"Password is :- "<<pass<<endl;
                            d=0;
                            break;
                        }
                        b+=2;
                        c+=2;
                    }
                    if(d==1)
                    {
                        cout<<"         Incorrect credentials"<<endl<<endl;
                        cout<<"         Enter 2 to Login Again"<<endl;
                        cout<<"         Enter 3 to Change password"<<endl<<endl;
                    }
                }



                break;
            }
            case 3:;
                    break;
            case 4:cout<<"         Thank You For Using!"<<endl;;
                    break;
            default:cout<<"        Invalid choice"<<endl;
                    break;

        }
    } while (a>0&&a<4);
    
}