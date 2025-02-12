# Linux Commands Cheat Sheet

This is a quick reference guide for common Linux commands used in the terminal.

- # **`pwd`**: Print the current working directory
  ```bash
  pwd
  ```
- # **`ls`**: List directory contents

  ```bash
  ls          # list files and directories
  ls -l       # long listing (file permissions, owner, size, etc.)
  ls -a       # list all files (including hidden files)
  ls -lh      # human-readable file sizes
  ```

- # **`cd`**: Change directory

  ```bash
  cd /path/to/directory  # navigate to a specific directory
  cd ..                  # go up one directory level
  cd ~                   # go to the home directory
  ```

- # **`mkdir`**: Create a directory

  ```bash
  mkdir new_directory
  ```

- # **`rmdir`**: Remove an empty directory

  ```bash
  rmdir directory_name
  ```

- # **`rm`**: Remove a file or directory

  ```bash
  rm file_name          # remove a file
  rm -r directory_name  # remove a directory and its contents
  rm -rf directory_name # force removal without prompts
  ```

- # **`cp`**: Copy files or directories

  ```bash
  cp source_file destination_file  # copy a file
  cp -r source_directory destination_directory  # copy a directory
  ```

- **`mv`**: Move or rename files/directories

  ```bash
  mv source_file destination_file    # rename or move a file
  mv source_directory destination_directory  # move a directory
  ```

- # **`cat`**: Concatenate and display file contents

  ```bash
  cat file_name
  ```

- # **`less`**: View file contents page by page (useful for large files)

  ```bash
  less file_name
  ```

- # **`head`**: View the first few lines of a file

  ```bash
  head file_name
  head -n 10 file_name  # view the first 10 lines
  ```

- # **`tail`**: View the last few lines of a file

  ```bash
  tail file_name
  tail -n 10 file_name  # view the last 10 lines
  ```

- # **`grep`**: Search for patterns in a file

  ```bash
  grep "pattern" file_name
  grep -r "pattern" /path/to/directory  # search recursively
  ```

- # **`uname -r`**: Show kernel version

  ```bash
  uname -r
  ```

- # **`df -h`**: Display disk usage (human-readable format)

  ```bash
  df -h
  ```

- # **`free -h`**: Display memory usage (human-readable format)

  ```bash
  free -h
  ```

- # **`uptime`**: Show how long the system has been running

  ```bash
  uptime
  ```

- # **`hostname`**: Show or set the system hostname
  ```bash
  hostname
  ```

---

- # **`chmod`**: Change file permissions

  ```bash
  chmod 755 file_name  # set permissions to rwxr-xr-x
  chmod +x file_name   # add execute permission
  ```

- # **`chown`**: Change file owner and group

  ```bash
  chown user:group file_name  # change owner and group
  ```

- # **`chgrp`**: Change file group ownership
  ```bash
  chgrp group file_name
  ```

---

- # **`ping`**: Send ICMP echo requests to a network host

  ```bash
  ping hostname_or_ip
  ```

- # **`ifconfig`**: Display or configure network interfaces

  ```bash
  ifconfig
  ```

- # **`ip`**: A more modern tool to manage networking

  ```bash
  ip addr show    # show IP addresses
  ip link set eth0 up  # bring an interface up
  ```

- # **`netstat`**: Network statistics (deprecated in favor of `ss`)

  ```bash
  netstat -tuln  # display active network connections
  ```

- **`ss`**: Display socket statistics (alternative to `netstat`)
  ```bash
  ss -tuln
  ```

---

- # **`awk`**: Pattern scanning and processing language

  ```bash
  awk '{print $1}' file_name  # print the first column of the file
  ```

- # **`sed`**: Stream editor for modifying files

  ```bash
  sed 's/old_pattern/new_pattern/g' file_name  # replace text in a file
  ```

- # **`cut`**: Remove sections from each line of files

  ```bash
  cut -d ' ' -f 1 file_name  # cut out the first column
  ```

- # **`sort`**: Sort lines of text files

  ```bash
  sort file_name
  ```

- # **`uniq`**: Report or omit repeated lines

  ```bash
  uniq file_name
  ```

- # **`echo`**: The echo command in Linux is used to display text or output the value of variables and is commonly used in shell scripts and terminal commands.

  ```bash
  echo "Hello, World!"
  # output : Hello, World!
  ```

  Display Variable Values: If you have a variable and want to print its value:

  ```bash
  my_variable="Linux Rocks!"
  echo $my_variable
  ```

  Suppress Newline at the End: You can use the -n option to prevent echo from adding a new line at the end:

  ```bash
  echo -n "Hello"
  echo "World"
  #output : HelloWorld
  ```

  Print Special Characters (Escape Sequences): Use the -e option to enable interpretation of special characters:

  ```bash
    echo -e "Line 1\nLine 2"
    #Line 1
    #Line 2
  ```

Common escape sequences:

- `\n` for newline
- `\t` for tab
- `\\` for a literal backslash
- `\b` for backspace

Redirect Output to a File: You can use echo to write to a file:

```bash
   echo "This is a test" > testfile.txt
```

This creates the file testfile.txt with the content "This is a test". If the file already exists, it will overwrite the content.

Append Output to a File: If you want to add content to the end of an existing file without overwriting it, use >>:

 ```bash
     echo "This is an appended line" >> testfile.txt
 ```

 Useful Options:

- `-n`: Do not output the trailing newline (no new line).
- `-e`: Enable interpretation of escape sequences (such as \n, \t).
- `-E`: Disable escape sequences (default behavior).
---
<br>
<br>


- # **`history`**: 
The `history` command in Linux is used to display the list of commands that have been executed in the current shell session. This can be helpful for reviewing previously run commands or reusing them.


### Common Uses of `history`:

1. **View Command History:**
   Simply typing `history` will show a list of all the commands executed in the current shell session.
   ```bash
   history
   ```
   Output:
   ```
   1  ls
   2  cd /home/user
   3  mkdir new_folder
   4  echo "Hello World"
   ```

2. **Show a Specific Number of Recent Commands:**
   You can specify how many recent commands you want to see. For example, to view the last 10 commands:
   ```bash
   history 10
   ```
   This will show the last 10 commands that were executed.

3. **Execute a Command from History:**
   You can rerun a command from your history by using `!` followed by the command's number in the history list. For example, to rerun the command numbered 3:
   ```bash
   !3
   ```
   This will execute the command with ID 3 (e.g., `mkdir new_folder`).

4. **Search for a Specific Command in History:**
   You can search for a command by using the `grep` command to filter the output of `history`:
   ```bash
   history | grep "mkdir"
   ```
   This will show all commands containing the word `mkdir` in the history.

5. **Clear Command History:**
   If you want to clear the history for the current session:
   ```bash
   history -c
   ```
   This clears the history in the current shell session.

6. **Save History to a File:**
   You can save your history to a file using the `history` command and redirecting the output to a file:
   ```bash
   history > my_history.txt
   ```

7. **Re-running the Last Command:**
   The `!!` command can be used to run the last command you executed. For example:
   ```bash
   !!
   ```
   This will rerun the last command executed.

8. **Use a Previous Command with Modifications:**
   You can repeat a previous command and modify it. For instance, to rerun the previous `echo` command and modify its argument:
   ```bash
   !echo:s/World/Linux/
   ```
   This will execute the previous `echo` command but replace `World` with `Linux`.

### Options for `history`:

- **`-c`**: Clear the history list.
- **`-d <n>`**: Delete the history entry at position `<n>`.
- **`-a`**: Append the current session's history to the history file.
- **`-r`**: Read the history from the history file.
- **`-w`**: Write the current history to the history file.

---
<br>
<br>


- # **`find`**: 
The `find` command in Linux is used to search for files and directories within the filesystem. It allows you to search based on a variety of criteria, such as filename, size, permissions, modification time, and more.

### Basic Syntax:
```bash
find [path] [expression]
```
- **`[path]`**: The directory where you want to start the search (e.g., `/`, `/home/user`, `.`).
- **`[expression]`**: The search criteria, which can be based on file name, type, size, etc.

### Common Uses of `find`:

1. **Search for Files by Name:**
   To find files by their name, use the `-name` option.
   ```bash
   find /path/to/search -name "filename.txt"
   ```
   Example:
   ```bash
   find /home/user/Documents -name "*.txt"
   ```
   This will search for all files with a `.txt` extension in the `/home/user/Documents` directory.

2. **Search for Files by Name (Case Insensitive):**
   To make the search case-insensitive, use the `-iname` option.
   ```bash
   find /path/to/search -iname "file*.txt"
   ```

3. **Search for Files by Type:**
   You can search for specific types of files using the `-type` option. For example:
   - **Search for files (`-type f`):**
     ```bash
     find /path/to/search -type f -name "*.txt"
     ```
   - **Search for directories (`-type d`):**
     ```bash
     find /path/to/search -type d -name "project"
     ```
   - **Search for symbolic links (`-type l`):**
     ```bash
     find /path/to/search -type l
     ```

4. **Search for Files Modified Recently:**
   The `-mtime` option allows you to search for files modified within a specific number of days:
   - **Files modified in the last 7 days:**
     ```bash
     find /path/to/search -mtime -7
     ```
   - **Files modified more than 30 days ago:**
     ```bash
     find /path/to/search -mtime +30
     ```

5. **Search by File Size:**
   The `-size` option allows you to search for files based on size:
   - **Files greater than 100MB:**
     ```bash
     find /path/to/search -size +100M
     ```
   - **Files smaller than 1KB:**
     ```bash
     find /path/to/search -size -1k
     ```

6. **Execute a Command on Found Files:**
   You can use `-exec` to execute a command on each file found. For example, to remove all `.log` files:
   ```bash
   find /path/to/search -name "*.log" -exec rm {} \;
   ```
   - The `{}` placeholder represents the current file found.
   - The `\;` at the end indicates the end of the `-exec` argument.

7. **Search for Files Based on Permissions:**
   The `-perm` option allows you to search for files based on their permissions:
   - **Files with exactly 755 permissions:**
     ```bash
     find /path/to/search -perm 755
     ```
   - **Files with permissions that match or are more permissive than 644:**
     ```bash
     find /path/to/search -perm -644
     ```

8. **Search for Empty Files or Directories:**
   To search for empty files or directories, use the `-empty` option:
   ```bash
   find /path/to/search -empty
   ```

9. **Search for Files Owned by a Specific User:**
   The `-user` option allows you to search for files owned by a specific user:
   ```bash
   find /path/to/search -user username
   ```

10. **Search for Files with Specific Permissions or Group Ownership:**
   You can also search by group (`-group`) or modify the file permissions:
   ```bash
   find /path/to/search -group groupname
   ```

### Examples:

1. **Find all `.txt` files in the current directory:**
   ```bash
   find . -name "*.txt"
   ```

2. **Find all directories named `backup`:**
   ```bash
   find / -type d -name "backup"
   ```

3. **Find and delete all `.log` files in the `/var/log` directory:**
   ```bash
   find /var/log -type f -name "*.log" -exec rm -f {} \;
   ```

4. **Find files modified in the last 10 days:**
   ```bash
   find /path/to/search -mtime -10
   ```

5. **Find files larger than 50MB:**
   ```bash
   find /path/to/search -size +50M
   ```

6. **Find all files owned by a user named `john`:**
   ```bash
   find /home -user john
   ```

### Useful Options:

- **`-name <pattern>`**: Search for files with a specific name or pattern (e.g., `*.txt`).
- **`-iname <pattern>`**: Case-insensitive name matching.
- **`-type`**: Search for files of a specific type (`f` for regular files, `d` for directories, `l` for symbolic links, etc.).
- **`-mtime <n>`**: Search for files modified within `n` days.
- **`-exec <command> {}`**: Execute a command on each file found.
- **`-size <n>`**: Search for files of a specific size.
- **`-empty`**: Search for empty files or directories.