#include <iostream> //including necessary libraries
#include <iomanip>
using namespace std;

int main() 
{
  int first_input, second_input, start_sequence, end_sequence;
  first_input=second_input=start_sequence=end_sequence=0;

  //asks user for input for start or end of sequence
  cout <<"Enter a value between 1 and 999: ";
  cin>>first_input;

  //error statement if input does not fit in domain
  while (first_input<1 || first_input>999)
  {
    cout<<"The value must be greater than 0 and less than 1000: ";
    cin>>first_input;
  }

  //asks user for input for start or end of sequence
  cout<<"Enter a second value between 1 and 999: ";
  cin>>second_input;
  cout<<endl;

  //error statment if input does not fit in domain
  while (second_input<1 || second_input>999)
  {
    cout<<"The value must be greater than 0 and less than 1000: ";
    cin>>second_input;
  }

  //assigning the start sequence as the lower number from the two inputs
  if(first_input>=second_input)
  {
    start_sequence=second_input;
    end_sequence=first_input;
  }
  //assigning the end sequence as the higher number from the two inputs
  if(first_input<=second_input)
  {
    start_sequence=first_input;
    end_sequence=second_input;
  }

  //FACTOR TABLE
  cout<<fixed;
  int count, perfect_sqr;
  
  //for loop to print dividend, factors, number of factors, perfect or prime numbers
  for(int dividend=start_sequence; dividend<=end_sequence; ++dividend)
  {
    count=0; //assigns variable as 0
    perfect_sqr=0;
    cout<<setw(4)<<dividend; //prints the dividend
    for(int divisor=1;divisor<=end_sequence; ++divisor) 
    {
      if(dividend%divisor==0) //when divisor is a factor (has no remainders)
      {
        cout<<setw(4)<<divisor; //prints divisor
        count+=1; //for every divisor found, count increases by one
        
        if(divisor*divisor==dividend) //identiying if the dividend is a perfect square
        {
          perfect_sqr=1;
        }
      }
    }
    
    //formatting the printing of number of factors to be lined up with the table
    if(count<10)
    {
      cout<<setw(3)<<"("<<count<<")";
    }
    if(count>=10)
    {
      cout<<setw(2)<<"("<<count<<")";
    }
    
    //identifying prime numbers (only two factors)
    if(count==2)
    {
      cout<<"  **prime number**";
    }
    //identifying perfect squares
    if(perfect_sqr==1)
    {
      cout<<"  **perfect square**";
    }
    cout<<endl;
  }

  //FINDING SUM OF THE START AND END SEQUENCE DIGITS AND INTERESTING NUMBER
  int start_ones, start_tens, start_hundreds, end_ones, end_tens, end_hundreds;
  start_ones=start_tens=start_hundreds=end_ones=end_tens=end_hundreds=0;
  
  //Start of sequence sum and interesting number evaluation
  start_hundreds=start_sequence/100;
  start_tens=start_sequence/10;
  start_ones=start_sequence%10;

  cout<<endl<<start_sequence<<": sum of digits = "<<start_hundreds + start_tens + start_ones; //prints sum of digit
  if(start_sequence>=10 && start_sequence<100)
  {
    if(start_tens * start_ones + start_tens + start_ones==start_sequence) //evaluating interesting number
    {
      cout<<"  --interesting--";
    }
  }
  if(start_sequence>=100)
  {
    if(start_hundreds * start_tens * start_ones + start_hundreds + start_tens + start_ones==start_sequence) //evaluating interesting number
    {
      cout<<"  --interesting--";
    }
  }

  //End of sequence sum and interesting number evaluation
  end_hundreds=end_sequence/100;
  end_tens=end_sequence/10;
  end_ones=end_sequence%10;

  cout<<endl<<end_sequence<<": sum of digits = "<<end_hundreds + end_tens + end_ones; //prints sum of digits
  if(end_sequence>=10 && end_sequence<100)
  {
    if(end_tens * end_ones + end_tens + end_ones==end_sequence) //evaluates interesting number
    {
      cout<<"  --interesting--";
    }
  }
  if(end_sequence>=100)
  {
    if(end_hundreds * end_tens * end_ones + end_hundreds + end_tens + end_ones==end_sequence) //evaluates interesting number
    {
      cout<<"  --interesting--";
    }
  }
  cout<<endl;

  return 0; //returning main function
}