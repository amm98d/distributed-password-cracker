# Distributed Password Cracker
### Combining OpenMP and MPICH for Brute Force in C

## About
This repository is a college semester project for the course "Parallel and Distributed Computing". Using OpenMp and MPICH libraries, this code attempts to brute force a password. The code was written and tested for Linux environment.

## Code Flow
- Input username
- Search for username:hashed-password combination in /etc/shadow file
- Brute force the obtained hash

## Limitations
- Maximum length for passwords -> 8 characters
- Only lower case alphabets (a-z)

## How To Run

- Compilation: ```mpicc -fopenmp main.c -lcrypt -o main```
- Execution: ```mpiexec -n x ./main``` [x can be any integer]

## How To Make mpiuser Sudoer
- before login to your mpiuser or YOUR_USER_NAME, 
- RUN the following commands

- sudo usermod -a -G YOUR_USER_NAME
- sudo nano /etc/sudoers

- NOW, add your username in the file like this:
- YOUR_USER_NAME ALL=(ALL)  ALL

- NOW, Login to mpiuser or YOUR_USER_NAME
- Compilation: ```mpicc -fopenmp main.c -lcrypt -o main```
- Execution: ```sudo mpiexec -n x ./main``` [x can be any integer]
- NOW YOU CAN ENJOY ALL THE SUDO PREVILIGES

## Contribution Guidelines
Each commit must have only atomic changes i.e. not more than 1 update. For example, it should not be the case that a single commit resolves an error and also implements a new function/feature.

The commit messages should follow the following pattern:
```
[<TYPE>] <DESCRIPTION>
    |
    ------> [Bug Fix] | [New Development] | [Refactor] | [Docs] 
```

**TYPE:** Explain the general purpose
  - Bug Fix: fixing some issue
  - New Development: new development/progress
  - Refactor: redesign of some portion of the code
  - Docs: documentation/code-commenting

**DESCRIPTION:** Explain the specific changes

**Examples**
```
[Bug Fix] Resolve INDEX OUT OF RANGE error
[New Development] Distribute combinations range between nodes
[Refactor] New approach for distribution
[Docs] Add docstrings for myFunc()
```
