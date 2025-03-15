# demons

In multitasking computer operating systems, a daemon is a computer program that runs as a background process, rather than being under the direct control of an interactive user. Traditionally, the process names of a daemon end with the letter `d`, for clarification that the process is in fact a daemon, and for differentiation between a daemon and a normal computer program.

For example, `syslogd` is a daemon that implements system logging facility, and `sshd` is a daemon that serves incoming SSH connections.

In a Unix environment, the `parent process` of a daemon is often, but not always, the [init](./init.md) process.

A **daemon** is a background process in Unix-like systems. It is usually created in one of two ways:

1. A process **forks a child process**, then immediately **exits**, allowing the system's **init** process to take over the child process.
2. The **init process** directly launches the daemon.

When a daemon is created by forking, it often needs to perform extra steps, like:

- **Disconnecting** from any controlling terminal (tty).
- Other setup tasks to ensure it runs in the background.

These steps are often simplified using routines like **daemon(3)** in Unix.

The `daemon(3)` function in Unix is a system call used to create a **daemon** process. A daemon is a background process that runs independently of a user’s session. The `daemon(3)` function simplifies the process of turning a program into a daemon by handling tasks such as:

1. **Forking** the process to run in the background.
2. **Detaching** it from any controlling terminal, so it doesn't rely on a user’s input.
3. **Setting the process as a background service** managed by the system.

This makes it easier for developers to create daemon processes without needing to manually handle the setup steps.

---

<br>
<br>

# Daemons in Linux:

In Linux, a **daemon** is a background process that runs independently of the user's session and typically starts during system boot-up. Daemons are used to perform system-level tasks, such as handling network services, logging, or managing hardware. These processes usually run with elevated privileges to perform administrative tasks without user interaction. Common examples of daemons in Linux include **Apache** (web server), **sshd** (SSH server), and **cron** (task scheduler). Daemons typically detach themselves from the terminal, run in the background, and are often managed by the `init` system or other service managers like **systemd**. They usually don't have a user interface, and their output is often logged for system administrators to monitor.

# Daemons in Windows:

In Windows, the equivalent of daemons are called **services**. These are background processes that run in the background to perform tasks such as handling network requests, running scheduled tasks, or monitoring system health. Services in Windows are similar to Linux daemons but are managed through the **Service Control Manager (SCM)**. They typically run without user intervention and can start automatically when the system boots or be triggered by events. Examples of services in Windows include the **Windows Update Service**, **Print Spooler**, and **IIS (Internet Information Services)**. Like Linux daemons, Windows services can run with higher privileges and usually don't interact with the user directly. Services are managed through tools like **Services.msc** or the `sc` command.

Both systems can have applications running as daemons (or services) and regular background processes, with system-level services being more tightly managed in a structured way (Windows services through SCM, Linux services through systemd or init).

# list all the demons

## linux

we can see all the demons on the linux by using `ps` commmand

The `ps` (process status) command in Linux is used to display information about running processes on your system. It shows details about active processes, including their process IDs (PID), memory usage, CPU usage, and other information.

### Basic Syntax:

```bash
ps [options]
```

### Commonly Used Options:

1. **`ps`** – Without any options, this will show only the processes running in the current shell (your terminal session).

   ```bash
   ps
   ```

2. **`ps -e` or `ps -A`** – Shows all processes running on the system.

   ```bash
   ps -e
   ```

3. **`ps -u <username>`** – Shows all processes running by a specific user.

   ```bash
   ps -u kali
   ```

4. **`ps -f`** – Full listing, which provides additional details, including PPID (Parent Process ID), TTY (Terminal Type), start time, and more.

   ```bash
   ps -f
   ```

5. **`ps aux`** – A very commonly used command. This displays detailed information about all processes running on the system, including processes owned by other users. It also shows memory and CPU usage, as well as the command used to start each process.

   ```bash
   ps aux
   ```

6. **`ps -ef`** – Shows a full-format listing of all processes, similar to `ps aux`, but in a slightly different format.

   ```bash
   ps -ef
   ```

7. **`ps -e --sort=-%mem`** – Sort processes by memory usage, with the most memory-intensive processes at the top.

   ```bash
   ps -e --sort=-%mem
   ```

8. **`ps -p <PID>`** – Shows information about a specific process using its **PID**.

   ```bash
   ps -p 1234
   ```

9. **`ps -l`** – Displays a long-format listing that includes more information like flags, and the priority of each process.

   ```bash
   ps -l
   ```

10. **`ps -H`** – Displays processes in a hierarchical (tree-like) format, showing parent-child relationships.
    ```bash
    ps -H
    ```

### Explanation of Columns in `ps aux`:

- **USER**: The user who owns the process.
- **PID**: The Process ID of the process.
- **%CPU**: The percentage of CPU usage.
- **%MEM**: The percentage of memory usage.
- **VSZ**: Virtual memory size of the process.
- **RSS**: Resident Set Size (physical memory usage).
- **TTY**: The terminal associated with the process.
- **STAT**: The process status (e.g., S for sleeping, R for running).
- **START**: The time when the process started.
- **TIME**: The cumulative CPU time the process has used.
- **COMMAND**: The command that launched the process.

### Sorting Process Output:

- You can sort the output of `ps` by various criteria. For example, to sort by memory usage, you can use:
  ```bash
  ps aux --sort=-%mem
  ```
  To sort by CPU usage:
  ```bash
  ps aux --sort=-%cpu
  ```

lets see all the demon processes

A daemon is a background process that typically has no controlling terminal (TTY). daemons usually have a `?` under the TTY column, indicating they are not attached to any terminal session.

you can run the following command to list processes with no controlling terminal

```bash
ps -eo pid,tty,cmd | grep " ? "
```

```bash
┌──(kali㉿kali)-[~]
└─$ ps -eo pid,tty,cmd | grep " ? "

      1 ?        /sbin/init splash
      2 ?        [kthreadd]
      3 ?        [pool_workqueue_release]
      4 ?        [kworker/R-rcu_gp]
      5 ?        [kworker/R-sync_wq]
      6 ?        [kworker/R-slub_flushwq]
      7 ?        [kworker/R-netns]
      8 ?        [kworker/0:0-ata_sff]
     11 ?        [kworker/u8:0-ipv6_addrconf]
     12 ?        [kworker/R-mm_percpu_wq]
     13 ?        [rcu_tasks_kthread]
     14 ?        [rcu_tasks_rude_kthread]
     15 ?        [rcu_tasks_trace_kthread]
     16 ?        [ksoftirqd/0]
     17 ?        [rcu_preempt]
     18 ?        [rcu_exp_par_gp_kthread_worker/0]
     19 ?        [rcu_exp_gp_kthread_worker]
     20 ?        [migration/0]
     21 ?        [idle_inject/0]
     22 ?        [cpuhp/0]
     23 ?        [cpuhp/1]
     .......
     .....
     ...
     ..
     .
```

here you can see all the processes which are demons

here you can see that the first ever process to run is `/sbin/init splash`

`/sbin/init splash` is related to `systemd`

/sbin/init: This is the first process started by the Linux kernel after booting. In modern Linux distributions, this is typically a `Fsymlink` to `systemd`.

`splash`: This is a boot parameter that enables a graphical splash screen during startup, often provided by tools like Plymouth

Most modern Linux distributions (like Ubuntu, Fedora, Arch, and Debian) use systemd, and you can confirm this with:

```bash
┌──(kali㉿kali)-[~]
└─$ ls -l /sbin/init

lrwxrwxrwx 1 root root 22 Feb 13 14:54 /sbin/init -> ../lib/systemd/systemd

```

indicates that `/sbin/init` is a symbolic link pointing to `/lib/systemd/systemd`, meaning that when the system calls `/sbin/init`, it actually runs `/lib/systemd/systemd`.

you can also see the command that is used to create an process
by using this command

```bash
ps -p <pipid> -o comm=
```

where `comm=` option is used to display the name of the command that started the process. It provides only the basename of the executable (i.e., without the full path).

## windows

In Windows, **daemons** are usually referred to as **services**. These are background processes that perform essential system functions, like networking, hardware management, or running specific applications. To view and manage these services in Windows, you can use several methods.

Here are the ways to view all the services (daemons) running on a Windows system:

### 1. **Using Task Manager**:

Task Manager is a simple tool to see running processes and services.

- Press **`Ctrl` + `Shift` + `Esc`** or **`Ctrl` + `Alt` + `Del`** and select **Task Manager**.
- Go to the **Services** tab to see a list of all active services (daemons) running on your system.
- You can right-click on a service to **start**, **stop**, or **restart** it.

### 2. **Using Services Window**:

Windows has a built-in tool called **Services** to view and manage system services.

- Press **`Win + R`**, type **`services.msc`**, and press **Enter**.
- This opens the **Services** window, where you can see all services (daemons) listed by name, along with their status (running, stopped).
- You can right-click any service to start, stop, or configure its settings.

### 3. **Using Command Prompt (CMD)**:

You can also use the **Command Prompt** to list services.

- Open **Command Prompt** by searching for **cmd** in the Start menu.
- To see a list of all running services, type the following command:

  ```bash
  sc query
  ```

  This will list all services and their current status.

- For more detailed information, use:
  ```bash
  sc qc <ServiceName>
  ```
  Replace `<ServiceName>` with the name of a specific service to see detailed configuration.

### 4. **Using PowerShell**:

PowerShell provides advanced tools for managing services.

- Open **PowerShell** by searching for it in the Start menu.
- To list all services, use this command:

  ```bash
  Get-Service
  ```

  This will list all services, their statuses, and their names.

- You can also use additional parameters to filter services, for example, to see only the running services:
  ```bash
  Get-Service | Where-Object { $_.Status -eq 'Running' }
  ```

### 5. **Using `tasklist` Command**:

The **`tasklist`** command shows all running processes, including those that are services.

- Open **Command Prompt** and type:

  ```bash
  tasklist /svc
  ```

  This will list all processes, along with their associated services.

- **Task Manager**: Quick way to view services under the "Services" tab.
- **Services Window (`services.msc`)**: A dedicated window for managing and viewing services.
- **Command Prompt (`sc query`)**: Lists running services with more detailed control over them.
- **PowerShell (`Get-Service`)**: Advanced filtering and management of services.
- **`tasklist /svc`**: Lists all processes and associated services.

The first services to load in Windows are essential system processes like `SMSS.exe`, `csrss.exe`, and `lsass.exe`.
These processes set up the operating system environment and load subsequent services.

---

<br>
<br>

---

### example:

syslog is considered a daemon process in many Unix-like operating systems (including Linux). It operates as a system logging daemon that is responsible for collecting and storing log messages generated by various system components, applications, and services.

![example](https://notes.shichao.io/apue/figure_13.2.png)
