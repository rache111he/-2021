#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

//functions
int random(int min, int max);
void mayanNumberGame();
void print_digit(int  n);
void print_fives(int fives);
void printMayanNumber(int n);

int main()
{
    //displays 5212 in Mayan number form
    printMayanNumber(5212); 
    cout << endl;
    //calls function for mayan number game
    mayanNumberGame(); 

    return 0;
}

//random number generator function using the parameters for range 
int random(int min, int max) 
{
    static bool first = true;
    if (first) 
    {  
        srand( time(NULL) ); 
        first = false;
    }
    return min + rand() % (( max + 1 ) - min);
}

//number game
void mayanNumberGame()
{
    int input, wrong_anw, wrong_anw1, wrong_anw2, correct_answer, correct_option;
    char answer;

    cout<<"MAYAN NUMBER GAME"<<endl;
    cout<<"Welcome to the Mayan Number Game!"<<endl;

    while (true)
    {
        cout<<endl<<"Enter a number greater than 10. The game will choose a number less than or equal to what you entered.\nYou will have to match your decimal number to its Mayan equiavlent. \nOr, enter a number less than 10 to exit: ";
        cin>>input;

        //dealing with input errors
        while(cin.fail())
        { 
            cin.clear(); 
            cin.ignore(100000, '\n');
            cout << "Please enter a number: ";
            cin>>input;
        }

        //terminates game when number less that 10 is entered
        if (input<10) {return;}

        //randomly generating the number for user to guess
        correct_answer=random(4, input);

        //randomly generating option number for correct answer
        correct_option=random(0,2);

        //randomly generating incorrect options
        int min=correct_answer*0.5;
        int max=correct_answer*1.5;

        cout<<"Which of these Mayan numbers is equal to "<<correct_answer<<"?\n"<<endl;

        char order[]={'a','b','c'};
        int number=5;
        for (int i=0; i<=2; i++)
        {
            //printing multiple choice options
            cout<<order[i]<<"."<<endl; 
            if (correct_option==i) //when the i option is the correct option
            {
                number=i;
                printMayanNumber(correct_answer);
            }
            if (i!=number) //if the option is not the correct option
            {
                wrong_anw1= random(min, max);
                wrong_anw=wrong_anw1;
                int count=0;
                if (count==1)
                {
                    wrong_anw2 = random(min, max);
                    //preventing duplicates of options
                    while(wrong_anw1==wrong_anw2 || wrong_anw1==correct_answer || wrong_anw2==correct_answer)
                    {
                        wrong_anw=random(min,max);
                    }
                }
                printMayanNumber(wrong_anw);
                count++;
            }
            cout<<endl;
        }

        answer='d';
        while(answer != 'a' && answer != 'b' && answer != 'c')
        {
            cout<<"Please enter a, b, or c?:  ";
            cin>>answer;
            //handling input errors
            while(cin.fail())
            { 
                cin.clear(); 
                cin.ignore(100000, '\n');
                cout <<"Please enter a, b, or c?:  ";
                cin>>answer;
            }
        }
        //when the user enters the correct answer
        if (order[number]==answer)
        {
            cout<<"CORRECT! The Mayan representation of "<<correct_answer<<" is"<<endl<<endl;
            printMayanNumber(correct_answer);
        }
        //when the user enters the incorrect answer
        if (order[number]!=answer)
        {
            cout<<"INCORRECT! The Mayan representation of "<<correct_answer<<" is"<<endl<<endl;
            printMayanNumber(correct_answer);
        }
    }
}

//printing lower case o for each digits
void print_digit(int n)
{
    for (int i=0; i<n; i++)
    {
        cout<<"o";
    }
    cout<<endl;
}

//printing lines for each fives
void print_fives(int fives)
{
    const char* line = "\u2580";
    for (int i=0; i<fives; i++)
    {
        for (int i=0; i<9; i++)
        {
            cout<<line;
        }
        cout<<endl;
    }
}

//printing mayan number
void printMayanNumber(int n)
{
    int number, quotient, twenty_pow, power;

    power=0;
    //identifying the power of twenty the number is divisible by
    for (int x=1; x<10; x++)
    {
        if (n/pow(20,x)>=1)
        {
            power++;
        }
    }

    //for loop for each twenty power level (mayan number format)
    for (int i=power; i>=0; i--)
    {
        twenty_pow=pow(20,i);
        number= n/twenty_pow;
        quotient=number;
        if (quotient==0) 
        {
            //printing zeroes if the division for the tewenty power is 0
            cout<<"00"<<endl;
        }
        if (quotient!=0)
        {
            int fives = quotient/5;
            quotient=-5*fives + quotient;

            //printing lower case o's and lines for the number of fives and remainders there are
            print_digit(quotient);
            print_fives(fives);
            quotient=0;
            //subtracting the multiple of twenty power from the original number to continue the loop to the next section
            n=-twenty_pow*number + n; 
        }
        cout<<"------------------"<<endl; //section lines
    }
}