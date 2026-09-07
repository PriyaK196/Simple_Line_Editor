# Simple Line Editor in C

## Project Description

A simple command-line line editor developed in C.

The editor allows users to create, view, modify, save, load, and search a small text document using commands in the terminal.

## Team Members

1. Priyadarshini
2. Priya k

## Features Implemented

### Core Features
- Insert a line
- Delete a line
- Display the document
- Save and load the document

### Bonus Feature
- Search for a word or phrase

### Other Commands
- Help
- Exit

## Data Structure

The document is stored using an array of strings.

```c
char lines[MAX_LINES][MAX_LENGTH];
| Command | Description                 |
| ------- | --------------------------- |
| insert  | Insert a new line           |
| delete  | Delete a line               |
| display | Display all lines           |
| save    | Save the document           |
| load    | Load the saved document     |
| search  | Search for a word or phrase |
| help    | Display available commands  |
| exit    | Exit the editor             |
