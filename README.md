# Ensea in the Shell

## Table of Contents
- [Introduction](#introduction)
- [Objectives](#objectives)
- [Features](#features)
- [Code Overview](#code-overview)

## Introduction
**Ensea in the Shell** is a shell project developed as part of the 2nd-year Computer Science Major Synthesys Practical Work at ENSEA. The purpose of the project is to implement a tiny shell capable of executing commands and displaying information such as execution time and exit codes.

### What is a Microshell?
A microshell is a lightweight command-line interpreter that allows users to interact with the operating system by entering commands. Unlike a full-fledged shell, a microshell provides only basic functionality, focusing on simplicity and core features. It serves as an excellent educational project to learn about system calls, process management, and input/output handling.

This repository contains the code, documentation, and report for the project, completed by Kyle DOTTIN and Reem KHATER. 

### How to Run
1. Clone the repository.
2. Compile the code:
   ```
   gcc enseash.c -o enseash
   ```
3. Run the microshell:
   ```
   ./enseash
   ```
   
---

## Objectives
- Create a micro shell named `enseash`.
- Implement features progressively, starting with a welcome message and a prompt.
- Display exit codes and execution times for executed commands.
- Avoid using `printf`, relying instead on `write()` for outputs.
- Follow best practices in coding, including modular design and meaningful comments. 

---

## Features

1. **Welcome Message**: Displays a friendly introduction to the micro shell:
     ```
     Hello!
     Welcome to the Ensea micro shell. If you wish to quit, type 'exit'.
     Enseash>
     ```
     
2. **Prompt Display**: Shows the prompt `Enseash>` for user input.
   
3. **Command execution**:
   - The shell supports commands even with arguments.
   - Implements a REPL loop to:
     - Read the user input.
     - Execute the command (e.g., `hostname -i`, `date`).
     - Display the result and return to the prompt.
    
4. **Shell output**:
   - Exit Command: The shell handles the exit command and terminates the program with a friendly farewell message.
   - Ctrl+D Support: The shell properly exits when the user presses <Ctrl+D>.

5. **Exit Code and Signal Display**:
The shell displays the return code or signal from the previous command in the prompt.
This feature helps the user understand the outcome of the last executed command, whether it succeeded, failed, or was terminated by a signal.

6. **Command Execution Time Measurement**: The shell measures and displays the execution time of commands. 

---

## Code Overview
The current implementation is located in `enseash.c`. 

### Functionality:
- **Introduction and Prompt**:
  Displays a welcome message and continuously prompts for user input.
- **Command Execution**:
  - Complex commands such as `hostname -i` or `date` are executed.  
  - The shell returns the prompt after execution, following the REPL (Read-Eval-Print-Loop) pattern.
- **Shell Output**:
  - Exit Command Handling: The shell checks if the user types exit and displays a message before terminating.
  - Graceful Exit: The shell also exits gracefully when <Ctrl+D> is pressed, just as with the exit command.
- **Exit Code and Signal Display**:
The prompt dynamically updates and helps users debug commands and understand their outcomes.
- **Command Execution Time Measurement**:
Captures the start and end time of command execution and calculates and displays execution time in milliseconds in the prompt. This provides users with insights into command performance.

### Example Commands:
```bash
Enseash> date
Mon Dec 2 11:09:22 GMT+1 2024
Enseash [exit:0]|2ms> exit
See you next time ;)
```

