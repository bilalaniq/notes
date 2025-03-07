# #include<elf.h>

The header file `<elf.h>` defines the format of ELF executable
binary files. Amongst these files are normal executable files,
relocatable object files, core files, and shared objects.

An executable file using the ELF file format consists of an `ELF header`, followed by a `program header table` or a
`section header table`, or both.

The ELF header is always at offset zero of the file. The program header table and the section header table's
offset in the file are defined in the ELF header. The two tables describe the rest of the particularities of the file.

This header file describes the above mentioned headers as C
structures and also includes structures for `dynamic sections`,
`relocation sections` and `symbol tables`.

## Basic types

The following types are used for N-bit architectures (N=32,64,
ElfN stands for Elf32 or Elf64, uintN_t stands for uint32_t or uint64_t):

- ElfN_Addr Unsigned program address, uintN_t
- ElfN_Off Unsigned file offset, uintN_t
- ElfN_Section Unsigned section index, uint16_t
- ElfN_Versym Unsigned version symbol information, uint16_t
- Elf_Byte unsigned char
- ElfN_Half uint16_t
- ElfN_Sword int32_t
- ElfN_Word uint32_t
- ElfN_Sxword int64_t
- ElfN_Xword uint64_t

### **📌 Explanation of Each Type in `elf.h`**

| **Type**           | **Definition**                       | **Usage in ELF Structures**                                                      |
| ------------------ | ------------------------------------ | -------------------------------------------------------------------------------- |
| **`ElfN_Addr`**    | Unsigned program address (`uintN_t`) | Used to store memory addresses (e.g., entry points, section addresses).          |
| **`ElfN_Off`**     | Unsigned file offset (`uintN_t`)     | Represents offsets within the ELF file (e.g., where sections start in the file). |
| **`ElfN_Section`** | Unsigned section index (`uint16_t`)  | Identifies sections in section headers.                                          |
| **`ElfN_Versym`**  | Unsigned version symbol (`uint16_t`) | Used in symbol versioning (determines which version of a function is used).      |
| **`Elf_Byte`**     | `unsigned char`                      | Represents individual bytes, often used in padding or flags.                     |
| **`ElfN_Half`**    | `uint16_t`                           | 16-bit values (e.g., ELF file type, machine type).                               |
| **`ElfN_Sword`**   | `int32_t`                            | Signed 32-bit integer (e.g., section types, relocations).                        |
| **`ElfN_Word`**    | `uint32_t`                           | Unsigned 32-bit integer (e.g., section sizes, flags).                            |
| **`ElfN_Sxword`**  | `int64_t`                            | Signed 64-bit integer (used in 64-bit ELF structures).                           |
| **`ElfN_Xword`**   | `uint64_t`                           | Unsigned 64-bit integer (used in 64-bit ELF structures).                         |

---

1️⃣ **ELF structures follow natural alignment** (e.g., 4-byte values are 4-byte aligned).  
2️⃣ **Padding bytes** are added when needed to maintain alignment.  
3️⃣ This ensures **consistent structure sizes** across platforms.  
4️⃣ **All structures are a multiple of 4 or 8 bytes** for efficiency.

---

<br>
<br>

# ELF header (Ehdr)

The ELF header is described by the type Elf32_Ehdr or Elf64_Ehdr:

```c
 #define EI_NIDENT 16

           typedef struct {
               unsigned char e_ident[EI_NIDENT];
               uint16_t      e_type;
               uint16_t      e_machine;
               uint32_t      e_version;
               ElfN_Addr     e_entry;
               ElfN_Off      e_phoff;
               ElfN_Off      e_shoff;
               uint32_t      e_flags;
               uint16_t      e_ehsize;
               uint16_t      e_phentsize;
               uint16_t      e_phnum;
               uint16_t      e_shentsize;
               uint16_t      e_shnum;
               uint16_t      e_shstrndx;
           } ElfN_Ehdr;
```

The fields have the following meanings:

- ## `e_ident`:

  This array of bytes specifies how to interpret the file,
  independent of the processor or the file's remaining
  contents.

  e_ident is a identifier at the start of an ELF file that defines its format, architecture, and compatibility. It includes the magic number (\x7FELF), class (32-bit/64-bit), endianness, version, and OS ABI info.

  Within this array everything is named by macros,
  which start with the prefix `EI_` and may contain values
  which start with the prefix `ELF`. The following macros are
  defined:

  - `EI_MAG0`:

    The first byte of the magic number. It must be
    filled with `ELFMAG0`. (0: 0x7f)

  - `EI_MAG1`:

    The second byte of the magic number. It must be
    filled with `ELFMAG1`. (1: 'E')

  - `EI_MAG2`:

    The third byte of the magic number. It must be
    filled with `ELFMAG2`. (2: 'L')

  - `EI_MAG3`:

    The fourth byte of the magic number. It must be
    filled with `ELFMAG3`. (3: 'F')

  - `EI_CLASS`:

    The fifth byte identifies the architecture for this
    binary:

    - **ELFCLASSNONE**: This class is invalid.
    - **ELFCLASS32**: This defines the 32-bit architecture. It
      supports machines with files and virtual
      address spaces up to 4 Gigabytes.
    - **ELFCLASS64**: This defines the 64-bit architecture.

  - `EI_DATA`:

    The sixth byte specifies the data encoding of the
    processor-specific data in the file. Currently,
    these encodings are supported:

    - **ELFDATANONE**: Unknown data format.
    - **ELFDATA2LSB**: Two's complement, little-endian
    - **ELFDATA2MSB**: Two's complement, big-endian.

  - `EI_VERSION`:

    The seventh byte is the version number of the ELF
    specification

    - **EV_NONE**: Invalid version.
    - **EV_CURRENT**: Current version.

    **ELF only has one valid version**, which is:

    **EV_CURRENT (1)** → The current and only valid ELF version.

    **EV_NONE (0)** → Invalid ELF version (should not be used).

    So, **all modern ELF files use EV_CURRENT (1), and there are no other versions** defined in the specification.

  - `EI_OSABI`:

    The **8th byte** in an ELF file tells which **operating system (OS)** and **ABI (Application Binary Interface)** the file is meant for.

    Some fields in other ELF structures have flags and values that have
    platform-specific meanings; the interpretation of
    those fields is determined by the value of this
    byte.
    It specifies which operating system and binary interface the ELF file is designed for (e.g., Linux, FreeBSD, Solaris).

    for example

    - **ELFOSABI_NONE / ELFOSABI_SYSV** → Standard UNIX System V ABI
    - **ELFOSABI_HPUX** → HP-UX operating system ABI
    - **ELFOSABI_NETBSD** → NetBSD operating system ABI
    - **ELFOSABI_LINUX** → Linux operating system ABI
    - **ELFOSABI_SOLARIS** → Solaris operating system ABI
    - **ELFOSABI_IRIX** → IRIX operating system ABI
    - **ELFOSABI_FREEBSD** → FreeBSD operating system ABI
    - **ELFOSABI_TRU64** → TRU64 UNIX operating system ABI
    - **ELFOSABI_ARM** → ARM architecture-specific ABI
    - **ELFOSABI_STANDALONE** → Standalone (embedded system) ABI

  - `EI_ABIVERSION`:

    The ninth byte identifies the version of the ABI to
    which the object is targeted. This field is used to
    distinguish among incompatible versions of an ABI.
    The interpretation of this version number is
    dependent on the ABI identified by the EI_OSABI
    field. Applications conforming to this
    specification use the value 0.

    ABI (**Application Binary Interface**) defines how programs interact with the operating system at the **binary level**. It specifies:

    1️⃣ **Calling Conventions** (how functions receive arguments & return values).  
    2️⃣ **Binary Format** (structure of ELF/PE files).
    3️⃣ **System Calls** (how programs request OS services).
    4️⃣ **Memory Layout** (stack, heap, registers).

    It ensures compatibility between compiled programs and the OS/kernel.

  - `EI_PAD`:

    Start of padding. These bytes are reserved and set
    to zero. Programs which read them should ignore
    them. The value for EI_PAD will change in the
    future if currently unused bytes are given meanings.

    for example:

    Originally, these bytes were ignored. But if a new ELF version requires an additional security field, one of the padding bytes could be redefined to store a security policy flag.
    Newer systems will recognize and use this flag, while older systems will still ignore it (ensuring compatibility).

  - `EI_NIDENT`:

    The size of the e_ident array. which is `#define EI_NIDENT 16`

- ## `e_type`:

  This member of the structure identifies the object file type:

  - **ET_NONE**:
    An unknown type.
  - **ET_REL**:
    A relocatable file.
  - **ET_EXEC**:
    An executable file.
  - **ET_DYN**:
    A shared object.
  - **ET_CORE**:
    A core file.

- ## `e_machine`:

  This member specifies the required architecture for an
  individual file. For example:

  - **EM_NONE**:
    An unknown machine
  - **EM_M32**:
    AT&T WE 32100
  - **EM_SPARC**:
    Sun Microsystems SPARC
  - **EM_386**:
    Intel 80386 (i386, 32-bit x86 architecture)
  - **EM_68K**:
    Motorola 68000
  - **EM_88K**:
    Motorola 88000
  - **EM_860**:
    Intel 80860
  - **EM_MIPS**:
    MIPS RS3000 (big-endian only)
  - **EM_PARISC**:
    HP/PA
  - **EM_SPARC32PLUS**:
    SPARC with enhanced instruction set
  - **EM_PPC**:
    PowerPC
  - **EM_PPC64**:
    PowerPC 64-bit
  - **EM_S390**:
    IBM S/390
  - **EM_ARM**:
    Advanced RISC Machines
  - **EM_SH**:
    Renesas SuperH
  - **EM_SPARCV9**:
    SPARC v9 64-bit
  - **EM_IA_64**:
    Intel Itanium
  - **EM_X86_64**:
    AMD x86-64
  - **EM_VAX**:
    DEC Vax

  ### **📌 Note: ELF `e_machine` for Intel x86-64**

  For **Intel x86-64** architecture, the correct `e_machine` value is:

  🔹 **`EM_X86_64`** → **AMD x86-64** (also used for Intel x86-64 CPUs).

  > Even though it is labeled **AMD x86-64**, this applies to **both AMD and Intel** 64-bit processors. This is because **AMD originally designed the x86-64 architecture**, which Intel later adopted as **Intel 64**.

  ### **🔹 Default `e_machine` Values in Linux**

  - **`EM_X86_64`** → Used by **64-bit** Linux systems (**AMD x86-64 / Intel x86-64**).
  - **`EM_386`** → Used by **32-bit** Linux systems (**Intel 80386 and compatible**).

  Most modern Linux distributions are **64-bit**, so **`EM_X86_64`** is the default.

- ## `e_version`:

  This member identifies the file version:

  - **EV_NONE**:
    Invalid version
  - **EV_CURRENT**:
    Current version
