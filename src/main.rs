use std::fs::OpenOptions;
use std::{fs::File, io::ErrorKind};
use std::io::Write;
use std::env;

fn main() {
    // All of the neccessary files
    let mut games_file = open_file("C:/Users/family/Desktop/NotGames/notes/Films_Animes_Games/games.txt");
    let mut films_file = open_file("C:/Users/family/Desktop/NotGames/notes/Films_Animes_Games/films.txt");
    let mut anime_file = open_file("C:/Users/family/Desktop/NotGames/notes/Films_Animes_Games/anime.txt");
    let mut shows_file = open_file("C:/Users/family/Desktop/NotGames/notes/Films_Animes_Games/shows.txt");

    // Reading the first argument given, panicking if anything errs
    let content_type = read_args(env::args()).unwrap_or_else(|err| {
        panic!("ERROR: {}", err)
    });

    // Reading the second argument given, panicking if anything errs
    let mut data = read_content_input(env::args()).unwrap_or_else(|err| {
        panic!("ERROR: {}", err)
    });

    // Replaces the _ in the arguments entered with empty spaces
    data = data.replace("_", " ");

    data.replace_range(..=1, "");

    // Writing the arguments into the file specified by the user
    if content_type.trim() == "-M" {
        films_file.write(format!("\n\n{}", data).as_bytes()).expect("Failed to write to the file");
        println!("\n\"{}\" was added to your list", data);
    } else if content_type.trim() == "-G" {
        games_file.write(format!("\n\n{}", data).as_bytes()).expect("Failed to write to the file");
        println!("\n\"{}\" was added to your list", data);
    } else if content_type.trim() == "-A" {
        anime_file.write(format!("\n\n{}", data).as_bytes()).expect("Failed to write to the file");
        println!("\n\"{}\" was added to your list", data);
    } else if content_type.trim() == "-S" {
        shows_file.write(format!("\n\n{}", data).as_bytes()).expect("Failed to write to the file");
        println!("\n\"{}\" was added to your list", data);
    } else if content_type.trim() == "--help" || content_type.trim() == "-h" {
        show_help();
    } else {
        show_help();
    }
}

// Reads the argument that was passed in through the console and either returns
// the string that was entered or a string explaining what went wrong.
// This is used to read the contents that need to be added to the specific file
fn read_content_input(mut args: impl Iterator<Item = String>) -> Result<String, String> {
    let mut input = String::new();

    // Skips the first argument since it's gibberish
    args.next();

    match args.next() {
        // Will push the first string if there are arguments
        Some(arg) => input.push_str(&arg),
        // Returns an error when there are no arguments given
        None => return Err(String::from("Not enough arguments given"))
    }

    // Pushing the rest of the arguments into the string
    for arg in args {
        input.push_str(&arg);
    }

    return Ok(input);
}

// Used to specifiy which content the user wants to add to(i.e films, games, anime, or shows).
// Will return the user's input either -F(Films), -G(Games), -A(Anime), or -S(Show).
// It can either the user input or the error message explaining what went wrong
fn read_args(mut args: impl Iterator<Item = String>) -> Result<String, String> {
    let mut input = String::new();

    // Skipping the first argument like before
    args.next();

    // Returns the error if there are no arguments given
    match args.next() {
        Some(arg) => input.push_str(&arg),
        None => return Err(String::from("Not enough arguments given"))
    }

    return Ok(input);
}

// Opens the file, checks and handles errors if they are any
fn open_file(path: &str) -> File {
    let file = OpenOptions::new()
        .write(true)
        .read(true)
        .append(true)
        .open(path)
        .unwrap_or_else(|err| {
        if err.kind() == ErrorKind::NotFound {
            // Creating the file if it doesn't exist
            File::create(path).unwrap_or_else(|err| {
                panic!("Failed to create file: {:?}", err);
            })
        } else {
            panic!("Failed to load file: {:?}", err)
        }
    });

    return file;
}

fn show_help() {
    println!("\nEasily add any content to your watchlist or gamelist");
    println!("DO NOT WRITE SPACES! Whenever there is a space, write an \"_\" instead");

    println!("\nOptions: ");
    println!(" -h, --help \t Display this help screen"); 
    println!(" -M \t         Add a Movie to \"films.txt\"");
    println!(" -G \t         Add a Game to \"games.txt\"");
    println!(" -A \t         Add an Anime to \"anime.txt\"");
    println!(" -S \t         Add a Show to \"shows.txt\"");
}