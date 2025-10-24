#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <limits>
#include <algorithm>
#include <regex>

//using namespace std;

/*
string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

string removefile(string str)
{
    str.erase(remove(str.begin(), str.end(), 'file://'), str.end());
    return str;
}
*/

std::string do_replace( std::string const & in, std::string const & from, std::string const & to )
{
  return std::regex_replace( in, std::regex(from), to );
}


std::string find_word(std::string file, std::string word)
{
  std::size_t pos=0;
  std::string line1;
  std::string returnline1;
  std::ifstream Myfile;
  int count=6;
  int mainline;

  std::ofstream myfileout;
  
  Myfile.open(file);
  Myfile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  if (Myfile.is_open())
  {
    myfileout.open ("sumtallyres.tmp");

    while (Myfile)
    { 
      count++;
      
      std::getline(Myfile >> std::ws, line1);
      //  offset =
      if ((  pos = line1.find(word,0)) != std::string::npos)
      { 
        // mainline = 0;
        returnline1 = line1;
        mainline = count;
      }

      if(count > mainline-1 && count  < mainline+7)
      {
       // std::cout << count << std::endl;
        if(count == mainline)
         line1.replace(line1.find("#",0), 0, "   ");

      myfileout << line1 << '\n';


   
     }
     
    }
     count = 0;
    
        Myfile.close();
        myfileout.close();

  }
  else
    std::cout << "sumtally could not be opened" << std::endl;


     
    return returnline1;


}

int main ()
{
  std::string particle;
  std::string particle2;
  std::string particle3;
  std::string particle4;
  std::string particle5;
  std::ifstream part;
  part.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
  part.open("sumtalpart.tmp");
  std::getline (part >> std::ws,particle);
  part.close();

 //particle = removeSpaces(particle);

  //string = std::regex_replace(string, std::regex("\\$name"), "Somename");

 //particle = removefile(particle);

  particle2 = do_replace(particle," ","");

  particle3 = do_replace(particle2,"\n","");

  particle4 = do_replace(particle3,"\r","");

  particle5 = do_replace(particle4,"file://","");


  //std::cout << particle5 << std::endl;

  std::string c = find_word(particle5, "#  num    reg     volume");

  
      
  return 0;
}
