# Luna Terminal

Luna Terminal is a simple command-line interface program written in C, 
designed to provide basic file and directory management commands within a terminal environment. 
The project offers functionality such as listing files, 
changing directories, creating directories, 
and removing files, making it a lightweight and useful tool for handling simple file operations.

# Features
* List Files: List all files and directories in the current working directory.
* Change Directory: Navigate to a specified directory.
* Make Directory: Create a new directory.
* Remove File: Delete a specified file.
* Exit: Terminate the Luna Terminal session.

# Commands
The following commands are supported:

* ls : Lists all files and directories in the current directory.
* cd <directory> : Changes the current directory to <directory>.
* mkdir <directory> : Creates a new directory with the name <directory>.
* rm <file> : Removes the specified <file>.
* exit : Exits the Luna Terminal.

# Building with CMake

1. Clone this repository:
```bash
git clone https://github.com/lunastev/LunaTerminal.git
cd LunaTerminal
```

2. Create a build directory and navigate to it:
```bash
mkdir build
cd build
```

3. Run CMake to configure the project:
```bash
cmake ..
```

4. Build the project using make:
```bash
make
```

5. Run the compiled program:
```bash
./LunaTerminal
```