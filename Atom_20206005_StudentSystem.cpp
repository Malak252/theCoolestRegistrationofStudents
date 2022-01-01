#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <windows.h>
#include <conio.h> // AKA pinocchio!

using namespace std;

/*======================================
==> PROGRAM OVERVIEW (TOP).

    1- Main Lobby.  Function      [Y].
    2- Add New      Function      [N].
    3- Edit         Function      [N].
    4- Delete       Function      [N].
    5- View List    Function      [N].
    5- Exit         Function      [N].

==> FUNCTIONS ALGORITHMS:

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
    uint32_t ID;      // 32-bit U[0-255].
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


uint8_t LINEAR_STUDENTS_COUNTER = 0;
/************************************************
*                FUNCTION DECLARED              *
************************************************/
void Coolest_Main_Lobby(void); // leave it, ty - WX: OKi :)
void Coolest_Switcher(char );
void Coolest_SubjectsINIT(void);
void Coolest_New_Students(void);
void Coolest_Subject_Switcher(char );
void Coolest_SREH(void);
//======================================
int main(void)
{
    uint8_t counter = 0;

    system("COLOR 0D");
    Coolest_SubjectsINIT();
    Coolest_Main_Lobby();

    // TESTING PURPOSE ONLY:
    system("cls");
    printf("\n Student[%d]_ID: %d", LINEAR_STUDENTS_COUNTER, Coolest_Students[0].ID);
    printf("\n Student[%d]_Budget: %d", LINEAR_STUDENTS_COUNTER, Coolest_Students[0].Budget);
    printf("\n Student[%d]_SubjectCounter: %d", LINEAR_STUDENTS_COUNTER, Coolest_Students[0].Subjects_Counter);

    printf("\n \nRegistered Subjects: \n");

    while(Coolest_Students[0].Registered_Subjects[counter] != '\0')
    {
        printf("\n Subject[%d]: %d",counter, Coolest_Students[0].Registered_Subjects[counter]);
        counter += 1;
    }


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

    cout <<"\t\tRegistration of students in college" << endl;
    cout <<"\n1. Students registered in system.";
    cout <<"\n2. Add student.";
    cout <<"\n3. Edit student.";
    cout <<"\n4. Delete student.";
    cout <<"\n5. Exit.\n";
    cout <<"\n   Please choose one from above choices: ";

    cin >> Coolest_User_Input; // taking the input (user choice).

    Coolest_Switcher(Coolest_User_Input);

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

    cout <<"\n Please enter id for a new student: ";
    cin  >> Coolest_Students[LINEAR_STUDENTS_COUNTER].ID ;
    cout <<"\n Please Enter available money: ";
    cin  >> Coolest_Students[LINEAR_STUDENTS_COUNTER].Budget;

    /*Hash Mechanism for storing the data (DATA-STRUCTURE). */

    //Student[LINEAR_STUDENTS_COUNTER].ID     = Student_ID;
    //Student[LINEAR_STUDENTS_COUNTER].Budget = Student_Budget;

    // Picking
    cout << "\n The available subjectS: "        << endl;
    cout << "\n1) Programming Languagues \t\t\t" << Programming_Languages.Fees << "Fees"<< endl;
    cout << "\n2) Technical Writing  \t\t\t"     << Technical_Writing.Fees     << "Fees"<< endl;
    cout << "\n3) Software Engineering \t\t\t"   << Software_Engineering.Fees  << "Fees"<< endl;
    cout << "\n4) Database \t\t\t"               << Database.Fees              << "Fees"<< endl;

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

}// END Coolest_New_Students.

/************************************************
*                SUB FUNCTIONS                  *
************************************************/

// SUBJECT SWITCHER FUNCTION:
void Coolest_Subject_Switcher(char Coolest_Choice)
{
    Coolest_SREH();

    switch(Coolest_Choice)
    {
        // Programming Languages.
        case '1':
            {

                Coolest_Students[LINEAR_STUDENTS_COUNTER].Budget -= Programming_Languages.Fees;


                Coolest_Students[LINEAR_STUDENTS_COUNTER].Registered_Subjects[Coolest_Students[LINEAR_STUDENTS_COUNTER].Subjects_Counter]     =               Programming_Languages.ID;

                Coolest_Students[LINEAR_STUDENTS_COUNTER].Subjects_Counter += 1;
                break;
            }

        // Technical Writing.
        case '2':
            {
                Coolest_Students[LINEAR_STUDENTS_COUNTER].Budget -= Technical_Writing.Fees;
                Coolest_Students[LINEAR_STUDENTS_COUNTER].Registered_Subjects[Coolest_Students[LINEAR_STUDENTS_COUNTER].Subjects_Counter]     =               Technical_Writing.ID;

                Coolest_Students[LINEAR_STUDENTS_COUNTER].Subjects_Counter += 1;
                break;
            }
        // Software Engineering.
        case '3':
            {
                Coolest_Students[LINEAR_STUDENTS_COUNTER].Budget -= Software_Engineering.Fees;
                Coolest_Students[LINEAR_STUDENTS_COUNTER].Registered_Subjects[Coolest_Students[LINEAR_STUDENTS_COUNTER].Subjects_Counter]     =               Software_Engineering.ID;

                Coolest_Students[LINEAR_STUDENTS_COUNTER].Subjects_Counter += 1;

                break;
            }

        // Database
        case '4':
            {
                Coolest_Students[LINEAR_STUDENTS_COUNTER].Budget -= Database.Fees;

                Coolest_Students[LINEAR_STUDENTS_COUNTER].Registered_Subjects[Coolest_Students[LINEAR_STUDENTS_COUNTER].Subjects_Counter]     =               Database.ID;

                Coolest_Students[LINEAR_STUDENTS_COUNTER].Subjects_Counter += 1;

                break;
            }

        default: /*do nothing*/ break;

    }//end switch.

} // END Coolest_Subject_Switcher.

// SUBJECT REGISTER ERROR HANDLER:
void Coolest_SREH(void)
{

}

// LOBBY SWITCHER FUNCTION:
void Coolest_Switcher(char Coolest_Choice)
{
    switch(Coolest_Choice)
    {
        case '1':
        {

            break;
        }

        case '2':
        {
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

            break;
        }
        case '6':
        {

            break;
        }

        default: break;

    }
} // END CoolestSwitcher.
