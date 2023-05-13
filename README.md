# Introduction
Backlog is a CLI program that lets you add a game you want to play, a show, a movie or an anime you want to watch to a specified text file so you can keep track of the content you want to consume. Instead of going to wherever you keep your watchlist or gamelist, open it, write to it and then close it, you can just open the terminal, write "backlog," specify which type of content you want to add, and write the name of the content. Useless? Maybe. Cool? Hell, yes! 

# Installation
Currently, the only way to use the program is to clone it directly from github. Obviously, you must have git installed to run the command below

```
-git clone https://github.com/MohamedAG2002/Backlog
```

Now that you have the project in a file somewhere, you have to install the Rust tools to your system. The most important one is "Cargo" because that's what you will use next.

Once you finished installing Cargo, you have to open the terminal and go into the project wherever you put it, and run this command:

```
cargo install --path .
```

Make sure to include the "." and write everything as is. And finally, once you did that, you can call the command "backlog" from anywhere in your system.

# How to use
There are a couple of things you have to know before using this amazing, genius program. The first is the writing method. Do not type a space. Terminals do not handle spaces very well, as you may know, so for that, you have to write an "_" in place of a space. 

The second thing you need to know is the file types. This program is only limited to ".txt" files. Perhaps there may be a future update that will handle other file types, but for the time being ".txt" is the only valid file type the program can write to. This paragraph will be deleted if another file type is added.
