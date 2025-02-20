# Tutorial: How to Create a Python Virtual Environment (Linux & Windows)

A Python virtual environment allows you to create isolated Python environments for different projects. This can help avoid dependency conflicts and ensure that your project has the exact versions of libraries it needs.

## Prerequisites

- Python 3 installed on your system. You can check if Python is installed by running:
  ```bash
  python3 --version
  ```

---

## 1. **Creating a Python Virtual Environment in Linux**

### **Step 1: Install `python3-venv` (if not already installed)**

There are many other pyhton tools used to create vm such as

- python3-venv
- conda
- pipenv
- poetry

but python3-venv build in with python so it is the most common one

On some Linux distributions, the `python3-venv` package may not be installed by default. Install it with:

```bash
sudo apt update
sudo apt install python3-venv
```

### **Step 2: Create the Virtual Environment**

Choose a directory where you want to store your virtual environments and navigate to it. For example:

```bash
cd ~/my_projects
```

Create a new virtual environment named `myenv` using the following command:

```bash
python3 -m venv myenv
```

This will create a new folder called `myenv` in your current directory, which will contain the virtual environment.

### **Step 3: Activate the Virtual Environment**

To activate the virtual environment, run:

```bash
source myenv/bin/activate
```

Once activated, your prompt will change, and it will show the name of the virtual environment, indicating that it’s active. For example:

```bash
(myenv) user@hostname:~/my_projects$
```

### **Step 4: Install Packages Inside the Virtual Environment**

Once the virtual environment is activated, you can install Python packages using `pip`. For example:

```bash
pip install requests
```

### **Step 5: Deactivate the Virtual Environment**

To deactivate the virtual environment, simply run:

```bash
deactivate
```

---

## 2. **Creating a Python Virtual Environment in Windows**

### **Step 1: Install Python (if not already installed)**

If Python is not already installed, download and install it from the [official website](https://www.python.org/downloads/). During installation, make sure to select the option to add Python to the `PATH`.

### **Step 2: Open Command Prompt or PowerShell**

Press `Win + R`, type `cmd` or `powershell`, and press Enter.

### **Step 3: Create the Virtual Environment**

Navigate to the directory where you want to create your virtual environment. For example:

```cmd
cd C:\Users\YourUsername\my_projects
```

Create a new virtual environment named `myenv`:

```cmd
python -m venv myenv
```

the only differnce is in linux you use python3 and in windows we only use python
this is because
On many Linux distributions (especially older ones), Python 2.x was the default version of Python. As Python 3 was introduced, there was a need to distinguish between the two versions
On Windows, when you install Python, Python 3.x is typically installed and configured to use the python command by default.

This will create a folder named `myenv` containing the virtual environment.

### **Step 4: Activate the Virtual Environment**

To activate the virtual environment, run the following command:

- For **Command Prompt**:

  ```cmd
  myenv\Scripts\activate
  ```

- For **PowerShell**:

  ```powershell
  .\myenv\Scripts\Activate.ps1
  ```

Once activated, your prompt will change, and you’ll see the name of the virtual environment:

```cmd
(myenv) C:\Users\YourUsername\my_projects>
```

### **Step 5: Install Packages Inside the Virtual Environment**

Now you can install Python packages using `pip`. For example:

```cmd
pip install requests
```

### **Step 6: Deactivate the Virtual Environment**

To deactivate the virtual environment, simply run:

```cmd
deactivate
```



## **pip list**

To see all the python libraries installed locally or globally(out side the virtul env) use this command

```bash
pip list
```

This will give you the list of lib installed


## **SAVING DEPENDENCIES**
now imagine that you have done some intense python development and have to push it to github 
what will you do upload all the python lib and dependencies no!! 
so what you will do is crete an `requirements.txt` which will have all the dependencies 
the pyhton-venv stores the dependencies requirements in the `freeze` file 

```bash 
echo freeze > requirements.txt
```

this will print all the dependencies in the requirements.txt file
and you will then upload the requirements.txt to your github and any one can then intall all these requirements by 
using this command

```bash 
pip install -r requirements.txt
```

so this will install all the dependencies

---
