// ------------------------------------------binary format-------------------------------------------
/*
Binary analysis is a crucial step within the broader process of reverse engineering. It involves examining a binary 
file (like an executable program) to understand its functionality, structure, and potential vulnerabilities.
so studing binary format is very crutial step towards lerning binay analysis





Binary format refers to a way of storing information using just two digits: 0 and 1.  
A binary file is a computer file where data is stored in this format.
Efficiency: Binary files are generally smaller than text files because they eliminate extra characters like spaces or punctuation. 
This makes them ideal for storing large amounts of data like images, videos, and executable programs.
Speed: Computers can process binary data much faster than text data, leading to quicker loading times and overall better performance
Binary files themselves are not directly human-readable. We need specific software or programs designed to interpret the binary code 
and display the information in a meaningful way.
While binary formats offer advantages in storage and processing, they are less flexible than text-based formats in terms of 
editing or manipulation.


------------------------------examples--------------------------------
>>>>> Executable files: These are programs that your computer can directly run, containing instructions and data encoded in binary for the processor to execute. Examples include:
Windows (.exe)
macOS (.app)
Linux (.bin)

>>>> Multimedia files: These store multimedia content like images, audio, and video. Each format uses a specific way to encode data for representing colors, sounds, or video frames. Examples include:
Images: JPEG, PNG, GIF, BMP
Audio: MP3, WAV, AAC
Video: MP4, AVI, MKV


>>>> Document files: These store formatted text and other elements like images or tables. While they may contain some text, the formatting information is often encoded in binary. Examples include:
Microsoft Word (.docx)
Adobe PDF (.pdf)
Rich Text Format (.rtf)

>>>> Compressed files: These use binary algorithms to reduce the size of other files by identifying and removing redundancies in the data. Examples include:
ZIP
RAR
7z

>>>> Data files: These store various types of structured data, often used in scientific, financial, or database applications. The data is organized following specific formats for efficient processing and analysis. Examples include:
CSV (Comma-Separated Values)
JSON (JavaScript Object Notation)
XML (Extensible Markup Language)


-----------------------types by structure-----------------

>>>> Flat binary files: These are simple files with no internal structure, just a continuous stream of bytes.
>>>> Hierarchical binary files: These have a well-defined structure with headers, data blocks, and potentially sub-blocks for organized information storage.


there are two formates of binary which are widely used in windows and linux 
ELF & PE binary format
if ou want to learn about them then click here
*/
#include"ELF_binary_format.cpp"
#include"PE_binary_format.cpp"
