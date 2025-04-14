# Minishell

**Minishell** is a lightweight UNIX command interpreter written in C. It replicates essential functionalities of TCSH, enabling basic command execution, environment management, and built-in commands.

---

## Features

- **Prompt Display**: Displays `$>` as the default prompt.
- **Command Execution**:
  - Executes commands from `PATH` or direct paths (e.g., `/bin/ls`).
- **Built-in Commands**:
  - `cd`, `env`, `setenv`, `unsetenv`, and `exit`.
- **Environment Management**: Copies, modifies, and restores environment variables.
- **Error Handling**: Displays error messages and ensures clean termination.

---

## Installation

1. Clone the repository:

- `git clone https://github.com/AchiQuelloVero/Minishell.git`

- `cd minishell`

2. Compile with the Makefile:

- `make`

---

## Usage

Run the shell:

- `./mysh`

### Examples:
`$> pwd` --> Print working directory

`$> cd /tmp` --> Change directory

`$> setenv MY_VAR 42` --> Set an environment variable

`$> unsetenv MY_VAR` --> Unset an environment variable

`$> env` --> Display all environment variables

`$> exit 0` --> Exit the shell with status 0

---

## Project Structure

- src/ # Source files for main logic and built-ins

- include/ # Header files

- lib/my/ # Custom string manipulation C library

- Makefile # Build configuration

---

## Built-in Commands

- **`cd <directory>`**: Change the current directory.
- **`env`**: Display all environment variables.
- **`setenv <var> <value>`**: Set an environment variable.
- **`unsetenv <var>`**: Unset an environment variable.
- **`exit <status>`**: Exit the shell with an optional status code.

---

## Error Handling

- Invalid commands display: `command: Command not found.`
- Critical errors exit with code `84`.
