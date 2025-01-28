# Minishell

Minishell is a custom shell built in C, designed to replicate the functionality of the Unix shell. This project was developed as part of a group assignment and includes basic shell commands like `cd`, `pwd`, `export`, `unset`, and error handling. It provides a hands-on understanding of how shells work and how to interact with the system at a low level.

## Features

- **Built-in commands**: 
  - `echo` with `-n` option
  - `cd` with only a relative or absolute path
  - `pwd` with no options
  - `export` with no options
  - `unset` with no options
  - `env` with no options or arguments
  - `exit` with no options
  
- **Command parsing**: Parsing user input and handling simple commands with arguments.

- **Process management**: Using `fork()` and `execve()` to execute commands in separate processes.

- **Error handling**: Comprehensive error handling for invalid commands and system errors.

- **Redirections**: 
  - `<` for input redirection
  - `>` for output redirection
  - `<<` for input redirection with a delimiter
  - `>>` for output redirection in append mode

- **Pipes (`|`)**: The output of each command in the pipeline is connected to the input of the next command.

- **Environment variable handling**: Expanding `$` followed by characters to their respective values and handling `$?` for the exit status of the most recently executed foreground pipeline.

- **Signal handling**: Supports `ctrl-C`, `ctrl-D`, and `ctrl-\` like in bash:
  - `ctrl-C` displays a new prompt on a new line.
  - `ctrl-D` exits the shell.
  - `ctrl-\` does nothing.

## How to compile

To compile the project, run the following command in the project directory:

```bash
make
