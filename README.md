# Minishell
This 42 project is a simplified version of a Unix shell. It provides a command-line interface where users can execute various commands and manage processes. The project focuses on parsing and executing commands, handling environment variables, and providing basic shell functionalities.

## Features
- Command-line interface with a prompt for user input
- Command parsing and execution
- Support for built-in shell commands
- Environment variable management
- Input/output redirection and piping
- Signal handling and process management
### Not Supported
- ';', '&&', or '||'

## Prerequisites
- [GCC](https://gcc.gnu.org/) or C complier
- The readline library
  - Available on Linux, but use the Makefile to download

## Installation
1. Clone the repository  
  `git clone https://github.com/MariamElSahhar/minishell.git`  
2. Navigate to the directory  
  `cd minishell`  
3. Compile the minishell  
   `make`

## Usage
Start the minishell using the following command:  
`./minishell`  
This launches the minishell and displays a prompt where you can enter commands.
