# Project E - README

### Docker Compose

``` 
$ dockercompose up -d 
```

### Display Server Setup

To use SDL (Simple DirectMedia Layer) in a Docker container with WSL (Windows Subsystem for Linux) and Xming on Windows 11, you need to set up an environment where the Docker container can display graphical applications through Xming. Here’s a step-by-step guide:

### 1. Install Prerequisites
#### Install WSL 2 and Ubuntu:
- Make sure you have **WSL 2** installed and a Linux distribution like **Ubuntu** set up on your Windows 11 machine.
- You can install WSL from PowerShell (run as Administrator):
  ```powershell
  wsl --install
  ```
  Follow the instructions to install Ubuntu or any preferred Linux distribution.

#### Install Docker Desktop for Windows:
- Download and install [Docker Desktop for Windows](https://www.docker.com/products/docker-desktop) if you haven’t already. During the installation, make sure to enable **WSL 2 integration**.
  
#### Install Xming on Windows:
- Download and install **Xming** from [Xming's SourceForge page](https://sourceforge.net/projects/xming/).
- After installation, run **Xming** to start the X server, which allows graphical applications from WSL to display on Windows.
  
### 2. Setup Xming
- Start **Xming** and ensure that the X server is running. You should see an **Xming** icon in the system tray.
- Ensure that Xming is configured to allow connections from WSL. Typically, the default settings are fine, but if you face issues, check the **Xming** settings (e.g., disable access control).

### 3. Set Display Environment in WSL
To forward graphical applications from your WSL environment to Windows using Xming:

1. Open a WSL terminal (e.g., Ubuntu).
2. Set the `DISPLAY` environment variable in WSL to point to your Windows machine’s IP address:
   ```bash
   export DISPLAY=$(grep -oP '(?<=nameserver\s).+' /etc/resolv.conf):0
   ```
   This command extracts the Windows machine’s IP address from the WSL’s `resolv.conf` file and sets it as the display address for Xming.

   Alternatively, you can set it manually if you know your Windows IP (e.g., `export DISPLAY=localhost:0`).

3. To make this change permanent, you can add the `export DISPLAY=...` line to your `.bashrc` (or equivalent shell configuration) file:
   ```bash
   echo 'export DISPLAY=$(grep -oP "(?<=nameserver\s).+" /etc/resolv.conf):0' >> ~/.bashrc
   source ~/.bashrc
   ```