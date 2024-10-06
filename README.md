# Backlog
Have you ever had a bunch of things to do and felt overwhelmed? Have you ever had a bunch of movies, tv shows, games, or anime you wanted to watch but didn't have the time to? Have you ever felt your ass clench from cringing at stupid jokes from TikTok? Well, my friend, Backlog is just the right tool for you. 

With Backlog, you can add any movie, tv show, game, or anime to a list to keep track of the things you need to watch or play. Don't keep them in a shitty notes app on your shitty phone, put them in a shitty text file on your shitty laptop/PC. And all you have to do is learn how to code, open your favorite terminal, write backlog and whatever form of entertainment you want to note down, and BOOM you've got yourself and a backlog list of things to watch and/or play. Never stress again about what to watch or play with Backlog.
 
 With Backlog, you'll never feel cringe.

It is upon my lawyer's advice to tell you that the above statement is not valid. Backlog has no guarantee to free you from the ever-growing feeling of cringe.  

# Use
Backlog is exclusively used in the terminal. It is a CLI tool after all. However, the good news is that it's not hard to use Backlog at all. All you have to do is--once you install it, of course--is write, on your terminal, `backlog --help`. Everything you need to know about backlog is in there. The commands you can use and how to use them exactly. Yet, the help menu doesn't tell you everything. 

The way Backlog works is that it takes the path you give it and create 4 empty text files: games.txt, films.txt, shows.txt, and animes.txt. You can of course edit these files as you wish. Backlog will basically write and read from these files everytime you use the tool. You cannot rename these files or move each one to another folder seperately. These files have to be in the same directory at all times. If you deleted one or more of these files, then Backlog will just create them again. When you'd want to list the contents of any of the files or search a specific entry in any of them, you'd have to use the names provided by Backlog. 

Say, for example, you want to search for the entry "Game of Thrones" in the shows file, you'd write on your terminal: `backlog --search "Gamea of Thrones" shows.txt`. As goes with any other file. You also not only have to specify the name of the file, you also have to specify its extension, which is always a ".txt". As you can see, the log entry _need_ to be surrounded with "" to be read as one word. 

Make sure to remember the names of these files as they are very important, as you can see. And also make sure to keep the files together in the same directory at all times.

Enjoy.

# Installation
This project uses cmake for building and configuring. Please make sure to have cmake installed on your system. First of all, as usual, you have to clone the repo somewhere on your system, build the project, and then compile it.

Cloning:
~~~
git clone https://github.com/MohamedAG2002/Backlog.git
cd Backlog
~~~

Building:
~~~
mkdir build
cd build
cmake ..
~~~

Compiling(in the **build** directory):
~~~
make
~~~

## Linux and Mac
Installing backlog on Linux or Mac is easy enough. All you have to do is run the following commands in the **build** directory that you just created:

~~~
sudo make install
~~~

This will install Backlog for you on your Linux or Mac machine. Now you're ready to use Backlog. Please take a look at the *Notes* section to know some things before using Backlog. 

## Windows
Installing Backlog on Windows is not as straightforward as on Linux or Mac. But it should be easy enough as well. There are no commands to run this time as with Windows you'll have to set the environment variable to the executable you just built.

To do that, go to the start menu and search for "env." Two options should show up, pick the one that has "System" in it. You should see a list of variables, skip all of them and look for a "Path" variable from the list. Click on edit. Then a window should pop up. Skip everything and look for an option on the side called "New." Type the path to the **build** folder of Backlog. 

You might need to close your terminal and open it again for the changes to take effect, but, either way, you should be ready. Please refer to the *Notes* section to know some things before using Backlog. 

# Notes
A couple of notes to keep in mind if you're using Backlog for the first time.

## Path
First of all, always set a path *before* using anything in Backlog. If you don't set a path, the files that will be written to will either be created in the project's build folder or not at all. So, if this is your first time using Backlog, make sure to set a path before doing *anything* with Backlog. You can check your current path by showing the "help" menu. Setting a path is currently very inconvenient. To change the path, you have to go to the "main.cpp" file, open it with a text editor, search for the "PATH" variable at the very top of the file (after the includes), and change it to your desired path. I know this is horrible but I can't find another way. Sorry.
