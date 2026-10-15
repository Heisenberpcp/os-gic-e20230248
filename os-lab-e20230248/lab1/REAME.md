# OS Lab1 Submission

---

- **Name:** CHEA Piseth
- **ID:** e20230248
- **Ubuntu username on the server:** i4gic-os 7.0.0-38-generic
- **My values**: file1=market, file2=silver, count=2

---

#### Task 1: Operating System Identification

The system is running Ubuntu Linux with a Linux kernel version: 7.0.0-38-generic and Distribution Version: 26.04

---

#### Task 2: Essential Linux File and Directory Commands

Menagement file in lunix is using command man for creating, copying, renaming and deleting files. it easy to menage file.
The last `ls` show

```
/home/gic-chea-piseth/oslab-work/lab1/task2_files
market.txt
silver.txt
market.txt
silver.txt
This is file market
This is file silver
market.txt
market_copy.txt
silver.txt
market.txt
market_copy.txt
silver_renamed.txt
market.txt
silver_renamed.txt

```

---

#### Task 3: Package Management Using APT

Explain the difference you observed between remove and purge.

• `Remove (apt remove )` : Uninstalls the program binaries and executable files, but leaves system-wide configuration files and logs behind. If you reinstall the software later, your old settings will still be there.

• `Purge (apt purge)`: Uninstalls the program binaries and deletes all system-wide configuration files. This is useful when an application is broken, and you want a completely clean slate.

---

#### Task 4: Programs vs Processe

Ruuning a background process is `&` in the end of command and find it by `ps`
The different between: -`Program` is a passive set of instructions, usually stored as a file on disk. -`Process` is a program in execution. When the operating system launches a program.

Before running the process:

The ps command showed only the active shell (bash) and the current command (ps) No new sleep process was running.

During the process execution:

After running sleep 30 & (and later sleep 300 &), the terminal displayed a job number and PID.
Running ps showed the sleep process in the process list alongside bash.
When two sleep 300 & commands were started, ps showed two separate sleep processes running simultaneously.

After the process finished:
The terminal displayed a message similar to:
`[3]+ Done sleep 30`

---

#### Task 5: Multitasking

`The multitasking` is doing multiple task in the same time
The are three ling of `sleep 300 &` ans 4 of line `ps` show

```
    PID TTY          TIME CMD
 113988 pts/5    00:00:00 bash
 114939 pts/5    00:00:00 sleep
 115299 pts/5    00:00:00 sleep
 115327 pts/5    00:00:00 ps
```
It shows
- bash: The shell that is running your commands.
- Two sleep processes: Programs that are paused for a specified amount of time.
- ps: The command used to display the process list.
- The PID of each process.
- The TTY (pts/5) indicating they are associated with the same terminal.
- The CPU time used (TIME), which is essentially zero for these processes.

It does not show about processor sharing
- It does not show how the CPU is being shared among processes.
- It does not show which process is currently running on the CPU.
- It does not show scheduling decisions, priorities, time slices, or context switches.
- It does not show CPU usage percentages or how much processor time each process receives relative to others.
  
  ---
#### Task 6: Virtualization and Hypervisor Detection

```
kvm
Hypervisor vendor:                       KVM
7.0.0-38-generic
i4gic-os
```

The system is running on a virtual machine because the command output identifies the hypervisor vendor as KVM, which means the operating system is being virtualized rather than running directly on physical hardware.
