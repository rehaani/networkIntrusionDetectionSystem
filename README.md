# Network Intrusion Detection System (NIDS)

---

## 🛠️ Summary

This repository contains a simple **Network Intrusion Detection System (NIDS)** designed to analyze IP addresses and detect suspicious activity. The program:
- Converts IP addresses between string and integer formats.
- Compares IPs against a predefined list of known malicious addresses.
- Logs suspicious activity while notifying the user.

The project includes all necessary code, utilities, and build instructions for easy compilation and usage. Ideal for learning or building upon network security concepts.

---

## Overview

The NIDS analyzes user-provided IP addresses, converting them into a machine-readable format, and checks if the IP is in a predefined list of known malicious addresses. If found, it logs the activity and alerts the user. The repository provides modular components for IP conversion and analysis.

---

## Project Structure

```
network-intrusion-detection/
├── networkAddress.c       # IP address conversion functions
├── networkAddress.h       # Header for IP address utilities
├── networkIntrusionDetection.c # Main NIDS implementation
├── Makefile               # For building the project
├── .gitignore             # Excludes unnecessary files from Git
└── README.md              # Project documentation
```

---

## Dependencies

- **Compiler**: GCC (GNU Compiler Collection)
- **Standard Libraries**: stdio, stdlib, string.h

Ensure GCC is installed on your system before proceeding.

---

## Build Instructions

To compile the project, use the provided `Makefile`:

1. Open a terminal in the project directory.
2. Run the following command:

```bash
make
```

This will generate an executable file named `nids` in the same directory.

---

## Usage

After building the project, you can run the program as follows:

1. Execute the program:

```bash
./nids
```

2. Enter an IP address when prompted.
3. The program will analyze the IP address and notify you if it is malicious or safe.

### Example

```bash
Enter IP address to analyze: 192.168.1.100
Suspicious activity detected from IP: 192.168.1.100
```

---

## Makefile

The provided Makefile simplifies compilation and cleanup tasks. Below is the included Makefile configuration:

```Makefile
CC = gcc
CFLAGS = -Wall -Wextra -pedantic

OBJ = networkAddress.o networkIntrusionDetection.o
TARGET = nids

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

networkAddress.o: networkAddress.c networkAddress.h
	$(CC) $(CFLAGS) -c $<

networkIntrusionDetection.o: networkIntrusionDetection.c networkAddress.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)
```

---

## How It Works

### Core Components

1. **IP Conversion Functions** (in `networkAddress.c`):
   - `ipToInt`: Converts an IP address from string format (e.g., `"192.168.0.1"`) to an unsigned integer for efficient storage and comparison.
   - `intToIp`: Converts an unsigned integer back into string format.

2. **Malicious IP Detection** (in `networkIntrusionDetection.c`):
   - Compares the provided IP against a predefined list of known malicious IP addresses (stored as integers).

3. **Logging**:
   - If an IP is found to be malicious, the program logs and displays an alert.

### Example Malicious IPs

The predefined list of malicious IPs includes:
- `192.168.1.100`
- `10.0.0.5`

Feel free to modify this list to customize detection.

---

## Contribution

Contributions are welcome! If you encounter any issues or have ideas for improvement:

1. Fork this repository.
2. Create a new branch for your changes.
3. Submit a pull request with detailed information about your updates.

---

## License

This project is open-source and available under the MIT License. See the `LICENSE` file for more details.

---

## Uploading to GitHub

### Step 1: Initialize the Repository

```bash
mkdir network-intrusion-detection
cd network-intrusion-detection
git init
```

### Step 2: Add Files
Move all project files into the `network-intrusion-detection` directory.

### Step 3: Add and Commit

```bash
git add .
git commit -m "Initial commit for Network Intrusion Detection System"
```

### Step 4: Push to GitHub

1. Create a new repository on GitHub.
2. Link it to your local repository:

```bash
git remote add origin <repository-url>
git branch -M main
git push -u origin main
```
