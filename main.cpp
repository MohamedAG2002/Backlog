#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

// Consts
const std::string PATH_FILE_NAME = "path.txt";

// Function declaration
// ------------------------
void ShowHelp();
void SavePath(const std::string&& pathName);
const std::string GetPath();
int ExitWithError(const std::string&& errMsg);
void SaveToFile(const std::string&& arg, const std::string&& fileName);
void PrintFile(const std::string&& fileName);
void SearchAndPrint(const std::string&& entry, const std::string&& fileName);
// ------------------------

// Main function
// ----------------------------
int main(int argc, char** argv)
{
  // No arguments given
  if(argc == 1)
   return ExitWithError("No valid arguments given");

  // List of arguments
  if(strcmp(argv[1], "-H") == 0 || strcmp(argv[1], "--help") == 0)
    ShowHelp();
  else if(strcmp(argv[1], "-P") == 0 || strcmp(argv[1], "--path") == 0)
  {
    // No path given
    if(argc != 3)
      return ExitWithError("No valid path given!");
    
    SavePath(argv[2]);
  }
  else if(strcmp(argv[1], "-G") == 0 || strcmp(argv[1], "--game") == 0)
  {
    // No argument given 
    if(argc != 3)
      return ExitWithError("Could not read the given value");

    SaveToFile(argv[2], "games.txt");  
  }
  else if(strcmp(argv[1], "-F") == 0 || strcmp(argv[1], "--film") == 0)
  {
    // No argument given 
    if(argc != 3)
      return ExitWithError("Could not read the given value");

    SaveToFile(argv[2], "films.txt");  
  }
  else if(strcmp(argv[1], "-S") == 0 || strcmp(argv[1], "--show") == 0)
  {
    // No argument given 
    if(argc != 3)
      return ExitWithError("Could not read the given value");

    SaveToFile(argv[2], "shows.txt");  
  }
  else if(strcmp(argv[1], "-A") == 0 || strcmp(argv[1], "--anime") == 0)
  {
    // No argument given 
    if(argc != 3)
      return ExitWithError("Could not read the given value");

    SaveToFile(argv[2], "animes.txt");  
  }
  else if(strcmp(argv[1], "-L") == 0 || strcmp(argv[1], "--list") == 0)
  {
    // No argument given 
    if(argc != 3)
      return ExitWithError("Could not read the given value");

    PrintFile(argv[2]);
  }
  else if(strcmp(argv[1], "-R") == 0 || strcmp(argv[1], "--search") == 0)
  {
    // No argument given 
    if(argc != 4)
      return ExitWithError("Could not read the given value");

    SearchAndPrint(argv[2], argv[3]);
  }
  else
  {
    ShowHelp();
    return ExitWithError((std::string)argv[1] + " is not a valid argument");
  }

  return EXIT_SUCCESS;
}
// ----------------------------

// *** Show Help ***
// ---------------------------------------------------------------------------
void ShowHelp()
{
  std::cout << "\n\t\t======================\n";
  std::cout << "  \t\t  Welcome to Backlog\n";
  std::cout << "\t\t======================\n\n";
  std::cout << " NOTE: Please make sure to put \'_\' in place of any space\n";
  std::cout << " NOTE: Make sure to add a \'/\' (or \'\\\' if on windows) to the end of your path\n\n";

  std::cout << " --help    -H                         = Prints this help screen\n";
  std::cout << " --path    -P [Absolute path]         = Specify the path to all of the .txt files\n";
  std::cout << " --game    -G [Game]                  = Add a game to \"games.txt\"\n";
  std::cout << " --film    -F [Films]                 = Add a movie to \"films.txt\"\n";
  std::cout << " --show    -S [Show]                  = Add a show to \"shows.txt\"\n";
  std::cout << " --anime   -A [Anime]                 = Add an anime to \"animes.txt\"\n";
  std::cout << " --list    -L [File name]             = List all of the contents of a specified file\n";
  std::cout << " --search  -R [Entry] [File name]     = Search for an entry in the specified file\n";

  std::cout << "\n Current path                         = " << GetPath() << "\n\n";
}
// ---------------------------------------------------------------------------

// *** Exit With Error *** 
// -------------------------------------------
int ExitWithError(const std::string&& errMsg)
{
  std::cout << " Error: " << errMsg << std::endl;
  return EXIT_FAILURE;
}
// -------------------------------------------

// *** Save To File ***
// ---------------------------------
void SaveToFile(const std::string&& arg, const std::string&& fileName)
{
  // Opening--if it exists--the file in append mode to add more data to the file
  // If the file does not exist, it will created it
  std::fstream file(GetPath() + fileName, std::ios::app);

  // Err if the file does not open
  if(!file.is_open())
  {
    std::cout << fileName << " failed to load" << std::endl;
    std::cout << "Please make sure you entered the correct path" << std::endl;
    return;
  }

  // Write, with format, to the file with the given argument
  file << "\n" << arg << "\n";

  // Print a celebratory message
  std::cout << "\n" << arg << " was added to " << "\'" << fileName << "\'!" << std::endl; 

  // ALWAYS CLOSE THE FILE
  file.close();
}
// ---------------------------------

// *** Print File ***
// ---------------------------------
void PrintFile(const std::string&& fileName)
{
  // Open the file in read mode
  std::fstream file(GetPath() + fileName, std::ios::in);
  
  // The contents of the file will be outputed to this string
  std::string line;

  if(!file.is_open())
  {
    std::cout << fileName << " failed to load" << std::endl;
    std::cout << "Please make sure you entered the correct path" << std::endl;
    return;
  }

  // Read everything from the file and copy it to the string
  while(std::getline(file, line))
  {
    std::cout << line << std::endl;
  }

  // ALWAYS CLOSE THE FILE
  file.close();
}
// ---------------------------------

// *** Save Path *** 
// ---------------------------------
void SavePath(const std::string&& pathName)
{
  std::fstream file(PATH_FILE_NAME, std::ios::out);

  if(!file.is_open())
  {
    std::cerr << "Failed to open \'path.txt\' file" << std::endl;
    return;
  }

  file << pathName;

  file.close();
}
// ---------------------------------

// *** Get Path *** 
// ---------------------------------
const std::string GetPath()
{
  std::fstream file(PATH_FILE_NAME, std::ios::in);
  std::string path;

  if(!file.is_open())
    std::cerr << "Failed to open \'path.txt\' file" << std::endl;
    
  while(!file.eof())
  {
    // Reading the contents of the file into the variable
    file >> path;
  }

  file.close();

  return path; 
}
// ---------------------------------

// *** Search And Print ***
// ---------------------------------
void SearchAndPrint(const std::string&& entry, const std::string&& fileName)
{
  std::fstream file(GetPath() + fileName, std::ios::in);
  std::string line;
  bool isFound = false;

  if(!file.is_open())
  {
    std::cout << fileName << " failed to load" << std::endl;
    std::cout << "Please make sure you entered the correct path" << std::endl;
    return;
  }
  
  while(std::getline(file, line))
  {
    if(line == entry)
    {
      std::cout << "\n" << line << std::endl;
      isFound = true;
    }
  }

  if(!isFound)
    std::cout << "\nCould not find " << entry << " in file " << fileName << std::endl;

  file.close();
}
// ---------------------------------
