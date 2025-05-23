# **Operating-System Design and Implementation**

Designing and implementing an operating system is a complex task that involves making many important decisions based on goals, hardware, and the intended use of the system. There is no single "correct" way to design an operating system, as different systems have different needs. The diversity of existing operating systems—from lightweight real-time systems to full-featured server systems—demonstrates the variety of approaches that can be taken.

---

### **Design Goals**

The first major challenge in OS design is determining the goals and requirements. These are typically divided into two broad categories: **user goals** and **system goals**.

**User goals** reflect what end users expect from an operating system. Users want a system that is **easy to use**, **intuitive**, **reliable**, **secure**, and **fast**. These are high-level expectations that guide how user-facing features should behave. However, they are often difficult to measure precisely and don't translate directly into technical specifications, making them hard to implement without interpretation.

On the other hand, **system goals** represent what the developers and engineers expect from the system. The OS should be **easy to design, implement, test, and maintain**. It should also be **flexible**, allowing for future updates or changes; **reliable**, to prevent failures; and **efficient**, to make the best use of resources like CPU, memory, and storage. Like user goals, these requirements are also somewhat vague and open to interpretation.

---

### **Different Systems, Different Needs**

Not all operating systems have the same goals because they are built for different environments. For example, a **real-time embedded OS** like **VxWorks**—used in industrial systems, robots, or medical devices—must prioritize **predictability and quick response times**. In contrast, a system like **Windows Server** is designed to handle multiple users and high workloads, so its focus is on **scalability, stability, and resource management**.

This wide variation in design goals leads to very different implementations. The nature of the hardware, the type of users, and the purpose of the OS all influence the design decisions.

---

### **A Creative and Evolving Process**

Ultimately, designing an OS is a **creative process** that cannot be fully taught through textbooks. While there are general software engineering principles that help guide the process—such as modularity, abstraction, and simplicity—much of the work requires thoughtful decision-making, experience, and often trial and error. Each system has its own constraints and needs, and the design must be tailored to meet them.

---

we turn now to a discussion of some of these principles.

# Mechanisms and Policies

In operating system design, one of the most important principles is the **separation of mechanism and policy**. These two concepts play different roles in how the OS functions:

- A **mechanism** defines **how** something is done — the low-level implementation details.
- A **policy** defines **what** should be done — the rules or strategies guiding decisions.

For example, a **timer** in the operating system is a **mechanism**. It can interrupt the CPU after a set time, helping enforce CPU protection by preventing a single program from running forever. However, **how long** the timer is set for each user or task — that’s a **policy decision**.

---

### **Why the Separation Matters**

Separating policy from mechanism is crucial because it **increases flexibility and adaptability**. Policies often vary between different systems or can change over time based on new requirements or user needs. If a policy is hard-coded into a mechanism, then **every time a policy changes, the mechanism must also be rewritten** — which is inefficient and error-prone.

By designing mechanisms that are general-purpose and **policy-agnostic**, we can **reuse the same mechanism under different policies**. For example, a general mechanism to prioritize tasks can support different policies, such as:

- Giving **I/O-intensive tasks** higher priority.
- Or alternatively, giving **CPU-intensive tasks** higher priority.

By keeping the mechanism the same and only tweaking the policy rules, the system becomes much easier to maintain and customize.

---

### **Examples in Real Systems**

Different operating systems handle this separation in different ways.

- **Microkernel-based systems** (like Minix or early versions of Mach) push this principle to the extreme. They include only basic, low-level mechanisms in the kernel (like message passing or minimal scheduling), leaving the policy decisions to be implemented in **user-level modules**. This gives developers more freedom to define how the system behaves without modifying the core.

- **Commercial systems** like **Windows** or **macOS** tend to combine both **mechanism and policy** tightly. For example, Windows includes built-in interface behavior and system rules to maintain a consistent "look and feel" across all applications and devices. This makes the system easier to use for end-users, but harder to customize at the OS level.

---

### **Open-Source vs Commercial OS Policies**

This separation is also visible when comparing **open-source systems like Linux** with **commercial systems like Windows**:

- **Linux** includes mechanisms (like CPU schedulers) with default policies, but **anyone can modify or replace them**. This makes Linux highly customizable for specific use cases like servers, mobile devices, or embedded systems.

- **Windows**, in contrast, restricts such customization to maintain uniformity and security across devices.

---

### **Policy and Resource Allocation**

Every time the OS must decide **whether to allocate a resource or not**, it is making a **policy decision**. For example:

- Who gets the CPU next?
- Should a file be cached or not?
- Which process should be killed when memory runs out?

On the other hand, deciding **how to implement that resource allocation** — using queues, timers, priority levels, etc. — is a matter of **mechanism**.

---

<br>
<br>

# Implementation

Once the **design** of an operating system (OS) is ready, the next step is to actually **build it**—this is called **implementation**.

#### **Languages Used**

- **In the early days**, operating systems were written completely in **assembly language**, which is low-level and specific to the hardware. It gave programmers total control over the system, but it was hard to write and maintain.
- **Today**, most operating systems are written in **higher-level programming languages** like **C** or **C++**. These languages are easier to read, write, and debug. Only a small part—usually the very low-level code that interacts directly with hardware—is still written in **assembly language**.

#### **Example: Android**

- The **Android OS** is a good example:
  - Its **kernel** (core part) is written mainly in **C** with some assembly.
  - Its **system libraries** are in **C and C++**.
  - Its **app development framework** is in **Java**, which is even higher-level.

#### **Why Use High-Level Languages?**

- **Faster Development:** Programmers can write code more quickly.
- **Easier to Understand and Fix:** The code is easier to maintain.
- **Smaller Code Size:** High-level languages are more concise.
- **Easy to Port:** If the OS is written in a high-level language, it’s easier to move it to **different hardware** platforms (like from a laptop to a smartphone).
- **Better Compiler Support:** As compilers get better, they can **automatically improve** the OS code when it's recompiled.

#### **Any Downsides?**

- In theory, **high-level code might be slower or use more memory** than assembly.
- But modern compilers and CPUs are very powerful and can **optimize** the code better than most humans can. So the performance difference is usually very small.

#### **Focus on Performance**

- Not all OS code needs to be extremely fast.
- The parts that matter most for performance are:
  - **Interrupt handlers** (handle sudden hardware signals),
  - **I/O manager** (handles devices like disk and network),
  - **Memory manager**, and
  - **CPU scheduler**.
- After the OS is built and tested, developers can focus on making these specific parts faster if needed.

---

### **In Short:**

Modern operating systems are mostly written in C or C++, with a little assembly for hardware interaction. Using high-level languages makes development easier and more portable, and performance is still excellent thanks to modern compilers and processors. Only a small part of the code is truly performance-critical, and that can be fine-tuned later.
