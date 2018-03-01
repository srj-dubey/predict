
// predict
// by Suraj Dubey
// started on 22-02-2018
// last updated on 01-03-2018

//header files
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

//global variables
    //user input variables
    char name[15];
    //int age=10;
    char m[60]={'n','o','n','e'};

//function prototypes
    void thankyou_at_end();
    void input(char *);
    void rekon(char *);
    void correct(char *);

//main function
int main()
{

    //variables declaration


    //welcome message
    cout<<" \n\n\t\t Hello world! \n\n\t\t I'm Predict\n";

    cout<<" \n\t\t Want to test me, press ENTER to start : ";
    cin.get();

    //loading
    cout<<"\n\n\t\t Loading ...\n\n\n";

    //user input's
    cout<<"\n\t\t Hey, your good name : ";
    cin.getline(name,15);

    /*
    cout<<"\n\t\t What age group you belong to: ";
    cout<<"\n\t\t 1. (0-15)\n\t\t 2. (15-30)\n\t\t 3. (30+)";
    cout<<"\n\t\t Enter : ";
    cin>>age;
    cout<<age;
    */
    //user interaction inputs


    //user interaction start

    cout<<"\n\n\t\t Enter a message here : ";
    //meaage input
    input(m);

    //main function
    /*here the message string is compared to all senario's*/
    rekon(m);

    //default return type
    return 0;

}

//function definations

void thankyou_at_end()
{
    cout<<"\n\n\t\t Thank you, i hope you'll have a good day ahead.\n\n";
}

/*funtion with defination
  it is defined here because i'm scread of pointers */

  void input(char *input)
  {
      char str[60];
      cin.getline(str,60);

      for(int i=0; i<60;i++)
      {
      input[i]=str[i];
      }
  }



  //correction function
  /* this function takes the previous input question string and
    and inputs its answer from user and then store both in the file for future use */

  void correct(char *m)
  {

            //variables declaration
            string ans_input="";
      cin.get();

      cout<<"\n\n\t\t There's always a roo for improvement. ";
      cout<<"\n\t\t And we are glad that you wish to improve.";




      //writing question and answer into file

            //opening file
            ofstream file;
            file.open("namo2.txt", ios::app);

                  //input from user
                  cout<<"\n\n\t\t Question : "<<m;
                  cout<<"\n\t\t Enter the Answer here : ";
                  getline(cin,ans_input);



            file<<m<<"="<<ans_input<<"=\n";

                //success message
                cout<<"\n\n\t\t Thanks, for improving me";
                cout<<"\n\n\t\t Enter here : ";
                input(m);
                rekon(m);

            //closing file
            file.close();

  }


  void rekon(char *m)
  {
      //variable declaration
      int choice=0;

      if(strcmp(m,"hey")==0 || strcmp(m,"hi")==0 || strcmp(m,"hello")==0)
      {
          cout<<"\n\n\t\t Hey "<<name<<", how are you doing : ";
          input(m);
          rekon(m);
      }

      else if(strcmp(m,"how are you")==0 || strcmp(m,"whats up")==0 || strcmp(m,"how are you feeling")==0)
      {
          cout<<"\n\n\t\t I still can not feel, but i'm fine so far";
          cout<<"\n\t\t Enough of me, tell me what are you upto : ";
          input(m);
          rekon(m);
      }

      else if(strcmp(m,"what are you")==0 || strcmp(m,"who are you")==0 || strcmp(m,"who made you")==0 ||
      strcmp(m,"your creator")==0 ||strcmp(m,"your owner")==0 || strcmp(m,"?")==0)
      {
          cout<<"\n\n\t\t They call me Predict";
          cout<<"\n\t\t I am mostly made of C++, it took a lot of effort though";
          cout<<"\n\t\t but i'm stil not perfect \n\n\t\t Reply here : ";
          input(m);
          if(strcmp(m,"good")==0 || strcmp(m,"wow")==0 || strcmp(m,"fantastic")==0)
          {
              cout<<"\n\n\t\t You are such a nice person, you always talk sweet ";
              cout<<"\n\t\t Reply here : ";
              input(m);
              rekon(m);
          }
          else
          {
              rekon(m);
          }
      }

      else if(strcmp(m,"i am fine")==0 || strcmp(m,"fine")==0 || strcmp(m,"i am good")==0
      || strcmp(m,"good")==0 || strcmp(m,"i am good")==0)
      {
          cout<<"\n\n\t\t I'm glad to hear that,";
          cout<<"\n\t\t by the way, what are you doing today : ";
          input(m);
          cout<<"\n\n\t\t Amazing, best of luck with that. ";
          cout<<"\n\t\t Reply here : ";
          input(m);
          rekon(m);
      }

      else if(strcmp(m,"end")==0 || strcmp(m,"exit")==0 || strcmp(m,"leave")==0
      || strcmp(m,"quit")==0)
      {
          thankyou_at_end();
      }

      else if(strcmp(m,"thanks")==0 || strcmp(m,"thankyou")==0 || strcmp(m,"thankyou so much")==0)
      {
          cout<<"\n\n\t\t You are being sweet here ";
          cout<<"\n\t\t I look forward to entertain you more : ";
          input(m);
          rekon(m);
      }

      else
      {

          int count=0;

          //question for comparing
          string ques="";
          ques+=m;

          //file pointer and opening
          ifstream file;
          file.open("namo2.txt");

          //strings declaration
          string s;
          string temp;

          for (int l = 1; l <= 100; l++)
          {

              getline(file,s);

              temp=s;


              //variable declarations
              int i=0;
              //final question
              string q_str="";
              char q_letter;
              //final answer
              string ans_str="";
              char ans_letter;


              //for question
              do
              {
                  q_letter=temp[i];
                  q_str+=q_letter;
                  i++;
              }while(temp[i]!='=');


              //for Answer
              for(int j=0;j<120;j++)
              {
                  if(temp[j]=='=')
                  {
                      int k=j+1;
                      do
                      {
                          ans_letter=temp[k];
                          ans_str+=ans_letter;
                          k++;
                      }while(temp[k]!='=');
                      break;
                  }
              }


              if(q_str==m)
              {
                  cout<<"\n\n\t\t "<<ans_str;
                  count++;
                  cout<<"\n\n\t\t Reply here : ";
                  input(m);
                  rekon(m);
              }


          }


          if(count==0)
          {
              cout<<"\n\n\t\t I didn't get you, would you like to correct me.";
              cout<<"\n\n\t\t 0 - for no\t1 - for yes \n\n\t\t Enter here : ";

              cin>>choice;
              cin.get();

              if(choice==1)
              {
                  correct(m);
              }

              else if(choice==0)
              {
                  cout<<"\n\n\t\t Okay, What next... Enter here : ";
                  input(m);
                  rekon(m);
              }

              else
              {
                  cout<<"\n\n\t\t My appologies \n\n";
              }
          }
      }

  }
