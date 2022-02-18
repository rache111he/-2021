//including libraries
#include <iostream>
#include <string>
using namespace std;

//initializing functions
string intName(int number);
string ones(int number);
string teens(int number);
string tens(int number);
string hundreds(int number);
string thousands(int number);
string intToString(int number);
void printIntStrings(int start, int end, int interval);

//Commented out main function which was used for testing

int main()
{
    printIntStrings(17,25, 1);
    return 0;
}


//void function that prints integers to strings in the given parameter and interval
void printIntStrings(int start, int end, int interval)
{   
    //for descending order
    if(start>=end)
    {
        for (int i=start; i>=end; i-=interval)
        {
            cout<<intToString(i)<<endl;
        }
    }
    //for ascending order
    if(start <= end)
    {
        for(int i=start; i<=end; i+=interval)
        {
            cout<<intToString(i)<<endl;
        }
    }
}

/*function for returning the string
function calls other functions that are broken down into the integer ranges*/
string intToString(int number)
{
    string name;

    if(number>99999 || number<0)
    {
        return "error";
    }
    if (number>=1000)
    {
        return thousands(number);
    }
    if (number>=100)
    {
        return hundreds(number);
    }
    if (number>=20)
    {
        return tens(number);
    }
    if (number >10)
    {
        return teens(number);
    }
    if (number<=10)
    {
        return ones(number);
    }
    return " ";
}

//defining ones function, used for the one digits' strings
string ones(int number)
{
    if (number==0){
        return "zero";
    }
    if (number==1){
        return "one";
    }
    if (number==2){
        return "two";
    }
    if (number==3){
        return "three";
    }
    if (number==4){
        return "four";
    }
    if (number==5){
        return "five";
    }
    if (number==6){
        return "six";
    }
    if (number==7){
        return "seven";
    }
    if (number==8){
        return "eight";
    }
    if (number==9){
        return "nine";
    }
    if (number==10){
        return "ten";
    }

    /*for function to return a value if any of the if statement is not true.
    this return statement will not run but is needed since in the case none of the if statements are true,
    the function HAS to return a string or will result in an error.
    same goes for some of the following functions*/
    return " "; 
}

//defining teens function, used for the teens digits' strings
string teens(int number)
{
    if (number==11){
        return "eleven";
    }
    if (number==12){
        return "twelve";
    }
    if (number==13){
        return "thirteen";
    }
    if (number==14){
        return "fourteen";
    }
    if (number==15){
        return "fifteen";
    }
    if (number==16){
        return "sixteen";
    }
    if (number==17){
        return "seventen";
    }
    if (number==18){
        return "eighteen";
    }
    if (number==19){
        return "nineteen";
    }
    return " ";
}

//defining tens function, used for the tens digits' strings
string tens(int number)
{
    string name;

    if (number>=90){
        name= "ninety";
    }
    else if (number>=80){
        name= "eighty";
    }
    else if (number>=70){
        name= "seventy";
    }
    else if (number>=60){
        name= "sixty";
    }
    else if (number>=50){
        name= "fifty";
    }
    else if (number>=40){
        name= "forty";
    }
    else if (number>=30){
        name= "thirty";
    }
    else if (number>=20){
        name= "twenty";
    }

    //if remainder exists, (will be ones value) will call the ones function where it will return the string for the ones
    if (number%10!=0)
    {
        name=name + "-" + ones(number%10);
    }
    return name;
}

//defining hundreds function, used for the hundreds digits' strings
string hundreds(int number)
{
    string name;

    //in case a number that is over a thousand has tens, teens, or/and ones as remainder but no hundreds
    //because the thousands function will call the hundreds function
    if (number/100==0)
    {
        if (number%100<=10)
        {
            return name + " and " + ones(number%100);
        }
        if (number%100>=20)
        {
            return name + " and " + tens(number%100);
        }
        else if (number%100>10)
        {
            return name + " and " + teens(number%100);
        }
    }
    //when the number doesn't have a tens or ones digit; number's tens and ones are zero
    if (number%100==0)
    {
        if (number/100==0)
        {
            return name;
        }
        if(number/100!=0)
        {
            name = name + ones(number/100) + " hundred";
            return name;
        }
    }

    //when the number contains ones and tens digit; number's tens and ones are not zero
    if (number%100!=0)
    {
        name= name + ones(number/100) + " hundred and ";
        if (number%100<=10)
        {
            return name + ones(number%100);
        }
        if (number%100>=20)
        {
            return name + tens(number%100);
        }
        else if (number%100>10)
        {
            return name + teens(number%100);
        }
    }
    return name;
}

//defining thousands function, used for the thousands digits' strings
string thousands(int number)
{
    string name;
    //when the number of thousands is less or equal to ten
    if (number/1000<=10)
    {
        name=ones(number/1000);
        if (number%1000==0) //when the number doesn't have a hundres, tens or ones digit; number's hundreds, tens and ones are zero
        {
            name=name + " thousand";
            return name;
        }
        if (number%1000<100)
        {
            name=name + " thousand"; //for format purposes regarding the comma
            return name + hundreds(number%1000);
        }
        else if (number%1000!=0)
        {
            name=name + " thousand, "; 
            return name + hundreds(number%1000);
        }
    }
    //when the number of thousands is greater than ten; following the similar structure as before
    if (number/1000>10)
    {
        if (number/1000<20) //when the number of thousands is teens
        {
            name=teens(number/1000);
            if (number%1000==0) 
            {
                name=name + " thousand";
                return name;
            }
            if (number%1000<100)
            {
                name=name + " thousand";
                return name + hundreds(number%1000);
            }
            else if (number%1000!=0)
            {
                name=name + " thousand, ";
                return name + hundreds(number%1000);
            }
        }
        if (number/1000>=20) //when the number of thousands is greater or equal to twenty; following the similar structure as before
        {
            name=tens(number/1000);
            if (number%1000==0)
            {
                name=name + " thousand";
                return name;
            }
            if (number%1000<100)
            {
                name=name + " thousand";
                return name + hundreds(number%1000);
            }
            else if (number%1000!=0)
            {
                name=name + " thousand, ";
                return name + hundreds(number%1000);
            }
        }
    }
    return name;
}