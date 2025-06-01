## ✅ **7.4 Lab – Reading Files in C**

**Environment**: GitHub Codespaces (with `gcc`)

---

### **Introduction**

Reading from a file in C is a fundamental operation used in programs that process data stored externally. Whether it’s a configuration file, log, or data archive, reading files allows a program to reuse information across sessions. In this lab, you’ll learn how to open a file, read its contents line by line, and process that data using `fopen()`, `fgets()`, and `fclose()`.

---

### **Objectives**

By the end of this lab, you will:

* Use `fopen()` to open a file for reading.
* Read content line-by-line using `fgets()`.
* Display each line in the terminal.
* Detect and handle file access errors.

---

## 🧪 Lab Steps

---

### **Step 1: Launch GitHub Codespaces**

1. Open your GitHub repository.
2. Click **Code > Codespaces > Create codespace on main**.
3. Wait for the editor to fully load.

---

### **Step 2: Create a Sample Text File**

Before writing the C program, let’s manually create a text file to read.

1. In the Explorer panel, click **New File** and name it: `data.txt`
2. Add the following content:

```
Alice,30
Bob,25
Charlie,22
Diana,27
```

This represents simple name-age records separated by commas.

---

### **Step 3: Create Your C Program**

1. In the Explorer panel, open the file named: `read_file.c`
2. Verify the following code:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    char line[100];

    // Open the file for reading
    file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    printf("Reading data from file:\n\n");

    while (fgets(line, sizeof(line), file)) {
        // Remove newline character
        line[strcspn(line, "\n")] = '\0';

        // Parse the line using strtok
        char *name = strtok(line, ",");
        char *ageStr = strtok(NULL, ",");

        if (name && ageStr) {
            printf("Name: %s, Age: %s\n", name, ageStr);
        }
    }

    fclose(file);
    return 0;
}
```

---

### **Step 4: Compile the Program**

Open the terminal in Codespaces and run:

```bash
gcc read_file.c -o read_file
```

---

### **Step 5: Run the Program**

```bash
./read_file
```

---

### 🔍 **Expected Output**

```
Reading data from file:

Name: Alice, Age: 30
Name: Bob, Age: 25
Name: Charlie, Age: 22
Name: Diana, Age: 27
```

---

### **Step 6: Experiment**

Try modifying `data.txt`:

* Add more entries.
* Use different delimiters and adjust `strtok()` if needed.
* Leave a blank line or add malformed lines to test error handling.

---

### **Summary**

In this lab, you:

* Opened and read a file using `fopen()` and `fgets()`.
* Processed text line-by-line.
* Split each line using `strtok()` to parse comma-separated values.
* Closed the file properly using `fclose()`.

This skill is essential for reading configuration files, logs, and structured data files in many real-world C programs.
