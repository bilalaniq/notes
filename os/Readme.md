# OS (Operating System)

An operating system acts as an intermediary between the user of a
computer and the computer hardware. The purpose of an operating
system is to provide an environment in which a user can execute
programs in a convenient and efficient manner.
An operating system is software that manages the computer hardware. The hardware must provide appropriate mechanisms to ensure the
correct operation of the computer system and to prevent user programs
from interfering with the proper operation of the system.
Internally, operating systems vary greatly in their makeup, since they
are organized along many different lines. The design of a new operating
system is a major task. It is important that the goals of the system be well
defined before the design begins. These goals form the basis for choices
among various algorithms and strategies.
Because an operating system is large and complex, it must be created
piece by piece. Each of these pieces should be a well-delineated portion
of the system, with carefully defined inputs, outputs, and functions.

### **Core Functions of an Operating System**

A computer system can be divided roughly into four
components:

- hardware
- operating system
- application programs,
- user

The hardware— the central processing unit (CPU), the memory, and the
input/output (I/O) devices—provides the basic computing resources for the
system. The application programs—such as word processors, spreadsheets,
compilers, and web browsers—define the ways in which these resources are
used to solve users’ computing problems. The operating system controls the
hardware and coordinates its use among the various application programs for
the various users.
We can also view a computer system as consisting of hardware, software,
and data. The operating system provides the means for proper use of these
resources in the operation of the computer system. An operating system is
similar to a government. Like a government, it performs no useful function
by itself. It simply provides an environment within which other programs can
do useful work.

Operating systems (OS) serve many functions across various types of computers, from toasters to spacecraft, and have evolved rapidly over time. Initially designed for military and government use, OSs expanded into general-purpose systems with the advent of mainframes. Moore's Law, predicting the doubling of transistors every 18 months, led to more powerful and compact computers.

An OS generally refers to software that manages hardware and makes it easier to use, executing programs and handling common tasks such as resource allocation and I/O device management. There is no universally accepted definition of what constitutes an OS, but it is commonly viewed as including the core program (kernel), system programs, and application programs. The exact features of an OS vary widely, from simple systems with minimal features to complex systems with extensive graphical capabilities.

The evolution of OSs was highlighted in legal cases like the 1998 U.S. lawsuit against Microsoft, where the company was accused of bundling too much functionality, stifling competition. In modern mobile OSs like iOS and Android, the OS includes not only a kernel but also middleware that aids app development.

In summary, the OS includes the always-running kernel, middleware for app development, and system programs for managing operations. The focus of this text is on the kernel of general-purpose OSs, though other components are discussed as necessary.

![os](https://encrypted-tbn2.gstatic.com/images?q=tbn:ANd9GcRoPce8JvqWBKm9lVMyp2O5_KIVxpf8fuvpgYnVeJhIkWkQczdY)

---

<br>
<br>

# Computer-System Organization

A modern general-purpose computer system consists of one or more CPUs and
a number of device controllers connected through a common bus that provides
access between components and shared memory . Each device
controller is in charge of a specific type of device (for example, a disk drive,
audio device, or graphics display). Depending on the controller, more than one
device may be attached. For instance, one system USB port can connect to a
USB hub, to which several devices can connect.

A device controller maintains

- Some local buffer storage
- A set of special-purpose registers.

The device controller is responsible for moving the data between the peripheral devices
that it controls and its local buffer storage.
Typically, operating systems have a device driver for each device controller. This device driver understands the device controller and provides the
rest of the operating system with a uniform interface to the device. The CPU and
the device controllers can execute in parallel, competing for memory cycles. To
ensure orderly access to the shared memory, a memory controller synchronizes
access to the memory.

![Computer-System Organization](https://images.slideplayer.com/36/10575294/slides/slide_9.jpg)

---

## Interrupts

if you want to learn about Interrupts click [here](./interrupts/Interrupts.md)

---

## Storage Structure

if you want to learn about Storage Structure click [here](./Storage_Structure/Storage_Structure.md)

---
