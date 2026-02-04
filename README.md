<div align="center">

![System & Kernel](https://img.shields.io/badge/System-brown?style=for-the-badge)
![Shell](https://img.shields.io/badge/Shell-Bash-blue?style=for-the-badge)
![Protocol Command](https://img.shields.io/badge/Protocol-Shell-green?style=for-the-badge)
![C Language](https://img.shields.io/badge/Language-C-red?style=for-the-badge)

*A basic Bash-style shell implementation*

</div>

<div align="center">
  <img src="/Minishell.png">
</div>

# Minishell

[README en Español](README_es.md)

`Minishell` is a `42 School` project that implements the basic features of a shell like `Bash`.  
This version includes all `mandatory` requirements, the `bonus`, and some `additional` features.

## ✨ Features

### 🔧 Core Functionality
- `Interactive command line`: Clean prompt with command history
- `Command execution`: PATH resolution, absolute/relative execution
- `Process management`: Fork/exec model with proper signal handling
- `Environment variables`: Full support for variable expansion and manipulation
- `I/O redirection`: Input/output redirection with append mode
- `Pipes`: Command chaining with pipe operators
- `Heredoc`: Advanced input redirection mechanisms
- `Syntax checking`: Detection and reporting of syntax errors

### 🚀 Advanced Features

#### **Improved parsing**
- `Command substitution`: `$()` for command substitution
- `Non-interactive mode`: `-c` option to run commands directly
- `Herestring`: `<<<` for direct string input
- `Heredoc expansion`: Variables and commands inside heredoc and herestring
- `Quote handling`: Advanced single and double quote processing
- `Character escaping`: Support for `\` (backslash)
- `Unclosed tokens`: Displays PS2 for line continuation

#### **Variables and expansion**
- `Shell variables`: Local variables in addition to environment variables
- `Special variables`:
  - `$$` - Shell PID
  - `$RANDOM` - Random number
  - `$TIME` - Current timestamp
  - `$_` - Last argument of the previous command
  - `$?` - Last exit code
- `Tilde expansion`: `~` expands to the home directory
- `Wildcard expansion`: `*`, `?`, and `[a-z]` with advanced patterns

#### **Logical operators and control**
- `Logical operators`: `&&` and `||` with parenthesis support for precedence
- `Subshells`: `()` for execution in subprocesses
- `Concurrent execution`: Handling of multiple processes

### 🛠️ Enhanced built-in commands

All built-ins include `--help` and `--version`:

- `echo` - With `-n` and `-e` options
- `cd` - With `cd -` support (previous directory)
- `pwd` - Current directory
- `export` - Environment variable management
- `unset` - Remove variables
- `env` - With `-s` to show shell variables
- `exit` - Exit the shell
- `history` - Command history management
- `help` - Built-in help system
- `banner` - Welcome message

## 🔧 Installation

```bash
git clone git@github.com:Kobayashi82/Minishell.git
cd minishell
make
```

## 🖥️ Usage

### Interactive mode
```bash
# Start minishell
./minishell

# Basic example
minishell$ echo "Hello World"
Hello World
```

### Non-interactive mode (-c option)
```bash
# Run commands directly
./minishell -c "echo 'Hello from the command line'"
./minishell -c "ls -la | grep '.c' | wc -l"
./minishell -c "export VAR=value && echo \$VAR"

# Complex commands with pipes and redirection
./minishell -c "cat /etc/passwd | grep root > users.txt"
```

### Common usage examples
```bash
# Pipe usage
minishell$ ls -la | grep ".c" | wc -l

# Redirection
minishell$ echo "content" > file.txt
minishell$ cat < file.txt

# Variables
minishell$ export VAR="value"
minishell$ echo $VAR

# Heredoc
minishell$ cat << EOF
> line 1
> line 2
> EOF
```

## 📚 Advanced examples

### Command substitution
```bash
minishell$ echo "Current date: $(date)"
Current date: Mon 26 May 2025 10:30:15 CEST

minishell$ files=$(ls *.c)
minishell$ echo $files
```

### Logical operators
```bash
minishell$ make && echo "Build succeeded" || echo "Build failed"

minishell$ (cd /tmp && pwd) && pwd
/tmp
/original/path
```

### Advanced wildcards
```bash
minishell$ ls *.c           # .c files
minishell$ ls file?.txt     # file1.txt, file2.txt, etc.
minishell$ ls [a-z]*.c      # .c files starting with lowercase
```

### Herestring
```bash
minishell$ cat <<< "This is a line of text"
This is a line of text

minishell$ bc <<< "2+2"
4
```

## 🧪 Technical highlights

### **Memory management**
- ✅ **No memory leaks**: Full heap cleanup
- ✅ **No open file descriptors**: Properly closes all FDs
- ✅ **Signal handling**: Robust handling of SIGINT, SIGQUIT, EOF

### **Bash compatibility**
- ✅ **Identical error handling**: Error codes and messages like Bash
- ✅ **Signal behavior**: Ctrl-C, Ctrl-D, Ctrl-\ like Bash
- ✅ **Special variables**: Identical behavior to Bash

### **Robust parsing**
- ✅ **Recursive parser**: Complete syntax parsing
- ✅ **Error handling**: Detailed error detection and reporting
- ✅ **Advanced tokenization**: Support for complex tokens

## 📄 License

This project is licensed under the WTFPL – [Do What the Fuck You Want to Public License](http://www.wtfpl.net/about/).

---

<div align="center">

**🐚 Developed as part of the 42 School curriculum 🐚**

*"In Minishell, the last feature is never really the last"*

</div>

<div align="center">
  <img src="/doc/MiniShell.jpg">
</div>
