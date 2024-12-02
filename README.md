# Ensea in the Shell

## Introduction
**Ensea in the Shell** is a shell project developed as part of the 2nd-year Computer Science Major Synthesys Practical Work at ENSEA. The purpose of the project is to implement a tiny shell capable of executing commands and displaying information such as execution time and exit codes.

### What is Microshell?
A microshell is a lightweight command-line interpreter that allows users to interact with the operating system by entering commands. Unlike a full-fledged shell, a microshell provides only basic functionality, focusing on simplicity and core features. It serves as an excellent educational project to learn about system calls, process management, and input/output handling.

This repository contains the code, documentation, and report for the project, completed by Kyle DOTTIN and Reem KHATER. 

---

## Objectives
- Create a micro shell named `enseash`.
- Implement features progressively, starting with a welcome message and a prompt.
- Display exit codes and execution times for executed commands.
- Avoid using `printf`, relying instead on `write()` for outputs.
- Follow best practices in coding, including modular design and meaningful comments. 

---

## Features
### Completed Features:
1. **Welcome Message**: Displays a friendly introduction to the micro shell:
     ```
     Hello!
     Welcome to the Ensea micro shell. If you wish to quit, type 'exit'.
     ```
     
2. **Prompt Display**: Shows the prompt `Enseash>` for user input.
   
3. **Command execution**:
   - The shell supports simple command execution without arguments.
   - Implements a REPL loop to:
     - Read the user input.
     - Execute the command (e.g., `fortune`, `date`).
     - Display the result and return to the prompt.
    
4. **Shell output**:
   - Exit Command: The shell handles the exit command and terminates the program with a friendly farewell message.
   - Ctrl+D Support: The shell properly exits when the user presses <Ctrl+D>, which sends an EOF (End of File) signal.

---

## Code Overview
The current implementation is located in `enseash.c`. 

### Functionality:
- **Introduction and Prompt**: Displays a welcome message and continuously prompts for user input.
- **Command Execution**:
  - Simple commands such as `fortune` and `date` are executed.
  - The shell returns the prompt after execution, following the REPL (Read-Eval-Print-Loop) pattern.
- **Shell Output**:
  - Exit Command Handling: The shell checks if the user types exit and displays a message before terminating.
  - Graceful Exit: The shell also exits gracefully when <Ctrl+D> is pressed, just as with the exit command.

### Example Commands:
```bash
Enseash> fortune
Today is what happened to yesterday.

Enseash> date
Mon Dec 2 11:09:22 GMT+1 2024
