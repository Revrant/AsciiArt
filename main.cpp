/* -----------------------------------------------------------------------------
 *
 * File Name:  main.cpp
 * Author: Tristen Schwarzenberger
 * Assignment:   EECS-168 Homework 2
 * Description: This program will ask the user display a picture with a certain size based on the users input
 * Date: 9/30/2016
 *
 ---------------------------------------------------------------------------- */
 #include <iostream>
 #include <limits>

 int main()
 {
   int choice = 0; //Users option choice
   int size = 0; //Frame size
   char exit = 'y'; //Variable for exiting
//-----------------------------------------------------------------------Repeats
   do
   {
     std::cout<<"\nChoose one of the following patterns by typing the corresponding number:\n";
     std::cout<<"1) Frame\n";
     std::cout<<"2) Checker Board\n";
     std::cout<<"3) Double Diagonal (aka the X)\n";
     std::cout<<"4) Two Islands\n";
     std::cout<<"Choice: ";
     std::cin>>choice;
//-----------------------------------------------------------------------If users puts invalid choice

     while(choice < 1 || choice > 4 || std::cin.fail() )  //Repeats till choice is valid
     {

       if( std::cin.fail() ) //Outputs an error if users types characters/string
        {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout<<"\nError.\n";
          std::cout<<"\nChoose one of the following patterns by typing the corresponding number:\n";
          std::cout<<"1) Frame\n";
          std::cout<<"2) Checker Board\n";
          std::cout<<"3) Double Diagonal (aka the X)\n";
          std::cout<<"4) Two Islands\n";
          std::cout<<"Choice: ";
          std::cin>>choice;
        }

        else if (choice < 1 || choice > 4) //Error if choices aren't within the limit
        {
          std::cout<<"\nError.\n";
          std::cout<<"\nChoose one of the following patterns by typing the corresponding number:\n";
          std::cout<<"1) Frame\n";
          std::cout<<"2) Checker Board\n";
          std::cout<<"3) Double Diagonal (aka the X)\n";
          std::cout<<"4) Two Islands\n";
          std::cout<<"Choice: ";
          std::cin>>choice;
        }

     }
//-----------------------------------------------------------------------Input size and error
     std::cout<<"\nInput a size (must be larger than 1): "; //Size of users choice
     std::cin>>size;
     std::cout<<'\n';

     while(size < 2) //If the user inputs a size less than two, it will ask them again
     {
       std::cout<<"\nError.\n";
       std::cout<<"\nInput a size (must be larger than 1): ";
       std::cin>>size;
       std::cout<<'\n';
     }
//----------------------------------------------------------------------- Frame
//i represents rows and j represents collums

     if(choice == 1)
     {
       for( int i = 0; i < size; i++  ) //Represents rows
       {
         std::cout<<i<<" "; //Numbers each row
          for(int j = 0; j < size; j++ ) //Represents collums
          {
            if(i == 0 || i == size - 1 || j == 0 || j == (size - 1))
            {
              std::cout<<"*";
            }
            else
            {
              std::cout<<" ";
            }
          }
          std::cout<<'\n';
        }
      }
//----------------------------------------------------------------------- Checker Board
      if(choice == 2)
      {
        for (int i = 0; i < size; i++)
        {
          std::cout<<i<<" ";

          for(int j = 0; j < size; j++)
          {
            if(i % 2 == 0 && j % 2 == 0) //Prints when both values equal eachothers remainder
            {
              std::cout<<"*";
            }
            else if(i % 2 == 1 && j % 2 == 1)
            {
              std::cout<<"*";
            }
            else
            {
              std::cout<<" ";
            }
          }
          std::cout<<'\n';
        }
      }
//----------------------------------------------------------------------- Double Diaganol
      if (choice == 3)
      {
        for (int i = 0; i < size; i ++)
        {
          std::cout<<i<<" ";

          for(int j = 0; j < size; j++)
          {
            if (i == j || i == -1 * j + (size - 1)) //Equation of both lines. Think of printing each line separately
            {
              std::cout<<"*";
            }
            else
            {
              std::cout<<" ";
            }
          }
          std::cout<<'\n';
        }
      }
//----------------------------------------------------------------------- Two Islands
if (choice == 4)
{
  int cut = size / 2;
  for (int i = 0; i < size; i++)
  {
    std::cout<<i<<" ";

    for(int j = 0; j < size; j++)
    {
      if(i == -1 * j + (size -1) )
      {
        std::cout<<"*";
      }
      else if(i < cut && j < cut)
      {
        std::cout<<"!";
      }
      else if(size % 2 == 0 && i >= cut && j >= cut)
      {
        std::cout<<"?";
      }
      else if(size % 2 == 1 && i > cut && j > cut)
      {
        std::cout<<"?";
      }
      else
      {
        std::cout<<"~";
      }

    }
    std::cout<<'\n';
  }
}
//-----------------------------------------------------------------------
        std::cout<<"\nWould you like to exit? (y/n): "; //Asks to end program
        std::cin>>exit;

   }while(exit != 'y'); //Loops program until user wants to exit





   return(0);
 }
