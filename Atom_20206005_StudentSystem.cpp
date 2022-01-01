#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

/*======================================
==> PROGRAM OVERVIEW (TOP).

  0- Main Lobby.  Function      [Y].
|  ---------------------------------- |
|  1- Add New      Function      [Y]. |
|  2- Edit         Function      [N]. |
|  3- Delete       Function      [N]. |
|  4- View List    Function      [Y]. |
|  5- Exit         Function      [Y]. |
---------------------------------------
-SUB: ERROR HANDLING [Y].

==> FUNCTIONS ALGORITHMS:
1-
2-
3-

*/
//======================================

/************************************************
*                GLOBAL VARIABLE                *
************************************************/

//======> DATA BASE FOR STUDENTS:
#define MIN_MAX_STUDENTS 255 // Min.
#define MIN_MAX_REGISTERED_SUBJECTS 3 //Min

//#pragma pack(1)
typedef struct
{
    string ID;
    uint32_t Budget; // 32-bit U[0-4294967296].

    uint8_t Registered_Subjects[MIN_MAX_REGISTERED_SUBJECTS];
    uint8_t Subjects_Counter;

} Coolest_DB_STUDENTS;

// KEY STRUCTS TO ACCESS ITS MEMBERS.
Coolest_DB_STUDENTS Coolest_Students[MIN_MAX_STUDENTS];


//======> DATA BASE FOR SUBJECTS:
#define MIN_MAX_SUBJECTS 4

typedef struct
{
    uint8_t ID;
    uint16_t Fees;

} Coolest_DB_SUBJECTS;

// KEY STRUCTS TO ACCESS ITS MEMBERS.
Coolest_DB_SUBJECTS Subjects[MIN_MAX_SUBJECTS];

#define Programming_Languages Subjects[0]
#define Technical_Writing     Subjects[1]
#define Software_Engineering  Subjects[2]
#define Database              Subjects[3]

// FUNCTION TO INIT THE SUBJECTS:
void Coolest_SubjectsINIT(void)   // TheCoolestMalak[ARRAY_OF_STRUCTS].
{
    Subjects[0] = {.ID = 1, .Fees = 1000};    // Programming_Languages.
    Subjects[1] = {.ID = 2, .Fees = 1000};   //  Technical_Writing.
    Subjects[2] = {.ID = 3, .Fees = 400};   //   Software_Engineering.
    Subjects[3] = {.ID = 4, .Fees = 600};  //    Database.

} // END Coolest_SubjectsINIT.

// Variable to count the real time students.
uint8_t LINEAR_STUDENTS_COUNTER = 0;
/************************************************
*                FUNCTION DECLARED              *
************************************************/
void Coolest_Main_Lobby(void); // leave it, ty - WX: OKi :)
void Coolest_Switcher(char );
void Coolest_SubjectsINIT(void);
void Coolest_New_Students(void);
void Coolest_Subject_Switcher(char );
void Coolest_StudentsLIST(void);
string Coolest_SubjectsDecoder(uint8_t );
//======================================
int main(void)
{
    system("COLOR 0D");

    Coolest_SubjectsINIT();

    Coolest_Main_Lobby();



    cout << endl;
    return 0;
}
//======================================

/************************************************
*                MAIN FUNCTIONS                 *
************************************************/

// MAIN LOBBY FUNCTION:
void Coolest_Main_Lobby(void)
{
  char Coolest_User_Input;

  while(1)
  {
    system("cls");

    cout <<"\t\tRegistration of students in college" << endl;
    cout <<"\n1. Students registered in system.";
    cout <<"\n2. Add student.";
    cout <<"\n3. Edit student.";
    cout <<"\n4. Delete student.";
    cout <<"\n5. Exit.\n";
    cout <<"\n   Please choose one from above choices: ";

    cin >> Coolest_User_Input; // taking the input (user choice).

    Coolest_Switcher(Coolest_User_Input);
  }

}// END MAIN_LOBBY.

// ADD NEW STUDENT
void Coolest_New_Students(void)
{
  system("cls");

  //uint8_t  Student_ID     = 0; // U[0-255]
  //uint16_t Student_Budget = 0; // U[0-65563]

  char
    Coolest_Switcher,
    Coolest_Descision;

  char ADD_STATE;
  bool Student_Exist = false;

  while(1)
  {
    system("cls");

    cout <<"\n Please enter id for a new student: ";
    cin  >> Coolest_Students[LINEAR_STUDENTS_COUNTER].ID ;

    // Check if the entered ID already exist using function compare
    // compare() is class function used to compare string with other string.
    for(uint8_t i = 0; i < LINEAR_STUDENTS_COUNTER; i++)
    {
      if(((Coolest_Students[LINEAR_STUDENTS_COUNTER].ID).compare(Coolest_Students[i].ID)) == 0)
      {
        // If student ID already exist:
        Student_Exist = true;
        break;
      }
    }

    if(Student_Exist == false)
    {
      // If passed get the money
      cout <<"\n Please Enter available money: ";
      cin  >> Coolest_Students[LINEAR_STUDENTS_COUNTER].Budget;

      // Picking
      cout << "\n The available subjectS: "    << endl;
      cout << "\n1) Programming Languagues \t" << Programming_Languages.Fees << "Fees" << endl;
      cout << "\n2) Technical Writing  \t"     << Technical_Writing.Fees     << "Fees" << endl;
      cout << "\n3) Software Engineering \t"   << Software_Engineering.Fees  << "Fees" << endl;
      cout << "\n4) Database \t"               << Database.Fees              << "Fees" << endl;

      // Conditional loop.
      while(1)
      {
          cout << "\n Please choose subject number to enroll in: ";
          cin  >> Coolest_Switcher;

          // Subject picker BACKEND PROCESS.
          Coolest_Subject_Switcher(Coolest_Switcher);

          cout << "\n Do you want to enroll in another subject Y/N: ";
          cin  >> Coolest_Descision;


          if( (Coolest_Descision == 'Y') || (Coolest_Descision == 'y') )
          {
              continue; // SKIP.
          }

          else if( (Coolest_Descision == 'N') || (Coolest_Descision == 'n') )
          {
            break; // BREAK THE LOOP.
          }

      } //end while.

      // Increasing sutdents number after registering 1.
      LINEAR_STUDENTS_COUNTER += 1;

      // Checking if user want to add more sturents at a time.
      cout << "\n Add new student?(Y/N): ";
      cin  >> ADD_STATE;

      // Restarting the Exist variable.
      if(ADD_STATE == 'Y' || ADD_STATE == 'y') {Student_Exist = false; continue;}
      else if(ADD_STATE == 'N' || ADD_STATE == 'n') {break;}
      else {continue;}
    }// end if.

    else
    {
      Student_Exist = false;
      printf("\n Student ID exists. Please try another one.\n");
      // Delay the Screen for 1 seconds then restart.
      sleep(1);
    }
  }//end while.
}// END Coolest_New_Students.


// FUNCTION TO VIEW THE RESGITERED STUDENTS:

// User friendly coding
#define STUDENTS Coolest_Students[temp_counter]
#define REG_SUBJ STUDENTS.Registered_Subjects[temp2_counter]

void Coolest_StudentsLIST(void)
{
  int temp_counter  = 0;
  int temp2_counter = 0;
  char temp;

  while(1)
  {
    system("cls");

    printf("\n Number of students registered: %d\n", LINEAR_STUDENTS_COUNTER);

    while(temp_counter < LINEAR_STUDENTS_COUNTER)
    {
      //cout << "\n Student_ID: "       <<       STUDENTS.ID               << endl;
      //cout << "\n Student_BUDGET: "   << (int) STUDENTS.Budget           << endl;
      //cout << "\n Student_SUBJECTS: " << (int) STUDENTS.Subjects_Counter << endl;

      cout << "\n";
      cout << temp_counter << ") Id=" << STUDENTS.ID << ",and subjects enrolled in are(";

      // Printing the student[x] subject registered:
      while(temp2_counter < STUDENTS.Subjects_Counter)
      {
        cout << (string)Coolest_SubjectsDecoder(REG_SUBJ) << ", ";
        temp2_counter += 1;
      }
      // (\b\b) to delete the space and comma after the last registered subject.
      cout << "\b\b)";

      cout << "\n";
      temp2_counter = 0;
      temp_counter += 1;
    }//end while 2.

    printf("\n \nBack to main lobby(Y/N): ");
    cin >> temp;

    if(temp == 'Y' || temp == 'y') {break;}
    else if(temp == 'N' || temp == 'n') {continue;}
    else {continue;}
  }//end while 1.
}//END Coolest_StudentsLIST

/************************************************
*                SUB FUNCTIONS                  *
************************************************/

// SUBJECT SWITCHER FUNCTION:

/*
  Algorithm:
  1- Pick the Subject.ID
  2- Detect if the student budget allows him to add the subject.
  3- If(YES): ADD=> Minus its fees from his budget , ADD subject id into his subjects.
  4- If(NO): ERROR=> SKIP.
*/

// User Friendly Coding
#define STUDENT_N             Coolest_Students[LINEAR_STUDENTS_COUNTER]
#define STUDENT_SUBJCOUNT     STUDENT_N.Subjects_Counter
#define STUDENT_REGISTERDSUBJ STUDENT_N.Registered_Subjects[STUDENT_SUBJCOUNT]

void Coolest_Subject_Switcher(char Coolest_Choice)
{
  bool Subject_Exist = false;

  if(1)
  {
    switch(Coolest_Choice)
    {
        // Programming Languages.
        case '1':
            {
              // CHECKING IF STUDENT[x].BUDGET > SUBJECT[x].FEES: ERROR_PHASE[1]
              if(Coolest_Students[LINEAR_STUDENTS_COUNTER].Budget >= Programming_Languages.Fees)
              {
                // CHECKING IF THE SUBJECT[x].ID EXISTS IN STUDENT[x].REGISTERED_SUBJECTS[x]: ERROR_PHASE[2]
                // LINEAR SEARCH ALGORITHM:
                for(uint8_t i = 0; i < STUDENT_SUBJCOUNT; i++)
                {
                  if(Programming_Languages.ID == STUDENT_N.Registered_Subjects[i])
                  {
                    // Subject already registered:
                    Subject_Exist = true;
                    break;
                  }
                }
                // IF Subject first time
                if(Subject_Exist == false)
                {
                  Coolest_Students[LINEAR_STUDENTS_COUNTER].Budget -= Programming_Languages.Fees;

                  STUDENT_REGISTERDSUBJ = Programming_Languages.ID;

                  Coolest_Students[LINEAR_STUDENTS_COUNTER].Subjects_Counter += 1;

                  Subject_Exist = false;

                  break;
                }
              }//end big if.
              else
              {
                printf("\n ERROR#code[0x1F]: (Budget < Fees). \n");

                if(Subject_Exist)
                {
                  printf("\n ERROR#code[0x2F]: Subject already registered. \n");
                  break;
                }
                break;
              }
            }//end case_1.

        // Technical Writing.
        case '2':
            {
              // CHECKING IF STUDENT[x].BUDGET > SUBJECT[x].FEES: ERROR_PHASE[1]
              if(Coolest_Students[LINEAR_STUDENTS_COUNTER].Budget >= Technical_Writing.Fees)
              {
                // CHECKING IF THE SUBJECT[x].ID EXISTS IN STUDENT[x].REGISTERED_SUBJECTS[x]: ERROR_PHASE[2]
                // LINEAR SEARCH ALGORITHM:
                for(uint8_t i = 0; i < STUDENT_SUBJCOUNT; i++)
                {
                  if(Technical_Writing.ID == STUDENT_N.Registered_Subjects[i])
                  {
                    // Subject already registered:
                    Subject_Exist = true;
                    break;
                  }
                }
                // IF Subject already
                if(Subject_Exist == false)
                {
                  Coolest_Students[LINEAR_STUDENTS_COUNTER].Budget -= Technical_Writing.Fees;

                  STUDENT_REGISTERDSUBJ = Technical_Writing.ID;

                  Coolest_Students[LINEAR_STUDENTS_COUNTER].Subjects_Counter += 1;

                  Subject_Exist = false;

                  break;
                }
              }//end big if.
              else
              {
                printf("\n ERROR#code[0x1F]: (Budget < Fees). \n");

                if(Subject_Exist)
                {
                  printf("\n ERROR#code[0x2F]: Subject already registered. \n");
                  break;
                }
                break;
              }
            }//end case_2.

        // Software Engineering.
        case '3':
            {
              // CHECKING IF STUDENT[x].BUDGET > SUBJECT[x].FEES: ERROR_PHASE[1]
              if(Coolest_Students[LINEAR_STUDENTS_COUNTER].Budget >= Software_Engineering.Fees)
              {
                // CHECKING IF THE SUBJECT[x].ID EXISTS IN STUDENT[x].REGISTERED_SUBJECTS[x]: ERROR_PHASE[2]
                // LINEAR SEARCH ALGORITHM:
                for(uint8_t i = 0; i < STUDENT_SUBJCOUNT; i++)
                {
                  if(Software_Engineering.ID == STUDENT_N.Registered_Subjects[i])
                  {
                    // Subject already registered:
                    Subject_Exist = true;
                    break;
                  }
                }
                // IF Subject already
                if(Subject_Exist == false)
                {
                  Coolest_Students[LINEAR_STUDENTS_COUNTER].Budget -= Software_Engineering.Fees;

                  STUDENT_REGISTERDSUBJ = Software_Engineering.ID;

                  Coolest_Students[LINEAR_STUDENTS_COUNTER].Subjects_Counter += 1;

                  Subject_Exist = false;

                  break;
                }
              }//end big if.
              else
              {
                printf("\n ERROR#code[0x1F]: (Budget < Fees). \n");

                if(Subject_Exist)
                {
                  printf("\n ERROR#code[0x2F]: Subject already registered. \n");
                  break;
                }
                break;
              }
            }//end case_3.

        // Database
        case '4':
            {
              // CHECKING IF STUDENT[x].BUDGET > SUBJECT[x].FEES: ERROR_PHASE[1]
              if(Coolest_Students[LINEAR_STUDENTS_COUNTER].Budget >= Database.Fees)
              {
                // CHECKING IF THE SUBJECT[x].ID EXISTS IN STUDENT[x].REGISTERED_SUBJECTS[x]: ERROR_PHASE[2]
                // LINEAR SEARCH ALGORITHM:
                for(uint8_t i = 0; i < STUDENT_SUBJCOUNT; i++)
                {
                  if(Database.ID == STUDENT_N.Registered_Subjects[i])
                  {
                    // Subject already registered:
                    Subject_Exist = true;
                    break;
                  }
                }
                // IF Subject already
                if(Subject_Exist == false)
                {
                  Coolest_Students[LINEAR_STUDENTS_COUNTER].Budget -= Database.Fees;

                  STUDENT_REGISTERDSUBJ = Database.ID;

                  Coolest_Students[LINEAR_STUDENTS_COUNTER].Subjects_Counter += 1;

                  Subject_Exist = false;

                  break;
                }
              }//end big if.
              else
              {
                printf("\n ERROR#code[0x1F]: (Budget < Fees). \n");

                if(Subject_Exist)
                {
                  printf("\n ERROR#code[0x2F]: Subject already registered. \n");
                  break;
                }
                break;
              }
            }//end case_4.

        default: {printf("\n Error Input\n"); break;}

    }//end switch.
  }//end if.

  else
  {
    printf("\n ERROR!");
  }
} // END Coolest_Subject_Switcher.

string Coolest_SubjectsDecoder(uint8_t subject_id)
{
  // Subject Decoded ID:
  string SDI[MIN_MAX_SUBJECTS+1];

  SDI[1] = "Programming Languages";
  SDI[2] = "Technical Writing";
  SDI[3] = "Software Enginnering";
  SDI[4] = "Database";

  return SDI[subject_id];
}// END Coolest_SubjectsDecoder

// LOBBY SWITCHER FUNCTION:
void Coolest_Switcher(char Coolest_Choice)
{

    switch(Coolest_Choice)
    {
        case '1': // View students registered.
        {
          system("cls");
          Coolest_StudentsLIST();

          break;
        }

        case '2': // Add new student.
        {
          system("cls");
          Coolest_New_Students();

          break;
        }

        case '3':
        {

            break;
        }

         case '4':
        {

            break;
        }
        case '5':
        {
          system("cls");
          printf("\n Thank you for using. \n");
          exit(0);
          break;
        }
        case '6':
        {

            break;
        }

        default: break;

    }
} // END CoolestSwitcher.
