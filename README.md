# QMK Keymaps

Custom QMK firmware keymaps for Keychron keyboards:
- **Keychron K8 Pro**: TKL wireless keyboard (ISO layout)
- **Keychron V1 Max**: 83-key wireless keyboard with encoder knob (ISO layout)

## Prerequisites & Installation

### macOS

Install Homebrew if you haven't already:
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

Install QMK and dependencies:
```bash
# Install QMK CLI
brew install qmk/qmk/qmk

# Install additional dependencies
brew install git python3 avr-gcc arm-none-eabi-gcc dfu-programmer dfu-util

# Verify installation
qmk --version
```

### Linux (Ubuntu/Debian)

Using Homebrew on Linux (recommended):
```bash
# Install Homebrew for Linux
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Add Homebrew to PATH
echo 'eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"' >> ~/.bashrc
eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"

# Install QMK and dependencies
brew install qmk/qmk/qmk
brew install avr-gcc arm-none-eabi-gcc dfu-programmer dfu-util
```

Alternative using system package manager:
```bash
# Install dependencies
sudo apt update
sudo apt install -y git python3-pip python3-venv gcc-avr binutils-avr avr-libc \
  gcc-arm-none-eabi binutils-arm-none-eabi libnewlib-arm-none-eabi \
  dfu-programmer dfu-util

# Install QMK CLI
python3 -m pip install --user qmk

# Add to PATH
echo 'export PATH=$PATH:~/.local/bin' >> ~/.bashrc
source ~/.bashrc
```

### Windows

Install using package managers:

**Option 1: Using Chocolatey (recommended)**
```powershell
# Install Chocolatey (run as Administrator)
Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))

# Install QMK and dependencies
choco install qmk-cli git python3
choco install qmk-toolbox  # Optional GUI for flashing
```

**Option 2: Using Scoop**
```powershell
# Install Scoop
Set-ExecutionPolicy RemoteSigned -Scope CurrentUser
irm get.scoop.sh | iex

# Install QMK and dependencies
scoop bucket add extras
scoop install qmk git python
```

**Option 3: Manual Installation**
1. Install [Python 3](https://www.python.org/downloads/)
2. Install [Git](https://git-scm.com/download/win)
3. Install QMK CLI: `pip install qmk`
4. Download [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases) for flashing

## Setup Instructions

### 1. Clone Keychron's QMK Fork

```bash
cd ~/git  # or your preferred directory
git clone -b wireless_playground --single-branch \
  https://github.com/Keychron/qmk_firmware.git
cd qmk_firmware
```

### 2. Setup QMK Environment

```bash
# Initialize QMK configuration
qmk setup

# Test installation
qmk hello
```

### 3. Link Keymap Directories

```bash
# Link your custom keymaps to QMK firmware
ln -s ~/git/qmk-keymaps/keychron_k8_pro \
  keyboards/keychron/k8_pro/iso/rgb/keymaps/cloonix

ln -s ~/git/qmk-keymaps/keychron_v1_max \
  keyboards/keychron/v1_max/iso_encoder/keymaps/cloonix
```

**Windows Note**: Use `mklink` instead of `ln -s`:
```cmd
mklink /D keyboards\keychron\k8_pro\iso\rgb\keymaps\cloonix C:\path\to\qmk-keymaps\keychron_k8_pro
mklink /D keyboards\keychron\v1_max\iso_encoder\keymaps\cloonix C:\path\to\qmk-keymaps\keychron_v1_max
```

## Building Firmware

### Compile Keymaps

```bash
# Build K8 Pro keymap
make keychron/k8_pro/iso/rgb:cloonix

# Build V1 Max keymap  
make keychron/v1_max/iso_encoder:cloonix

# Alternative: Use QMK CLI
qmk compile -kb keychron/k8_pro/iso/rgb -km cloonix
qmk compile -kb keychron/v1_max/iso_encoder -km cloonix
```

### Flash Firmware

**Method 1: Using make command**
```bash
# Put keyboard in bootloader mode (Fn+J+Z for 4 seconds), then:
make keychron/k8_pro/iso/rgb:cloonix:flash
make keychron/v1_max/iso_encoder:cloonix:flash
```

**Method 2: Using QMK CLI**
```bash
# Put keyboard in bootloader mode, then:
qmk flash -kb keychron/k8_pro/iso/rgb -km cloonix
qmk flash -kb keychron/v1_max/iso_encoder -km cloonix
```

**Method 3: Using QMK Toolbox (Windows/macOS GUI)**
1. Open QMK Toolbox
2. Load the compiled `.bin` file from `qmk_firmware/.build/`
3. Put keyboard in bootloader mode
4. Click "Flash"

## Entering Bootloader Mode

For Keychron keyboards:
1. **Fn + J + Z** for 4 seconds, or
2. **Reset button** on the back of the keyboard, or
3. **Boot magic**: Hold **Space + B** while plugging in

## Troubleshooting

### Permission Issues (Linux/macOS)
```bash
# Add udev rules for keyboard access
sudo cp util/udev/50-qmk.rules /etc/udev/rules.d/
sudo udevadm control --reload-rules
sudo udevadm trigger
```

### Path Issues
Make sure QMK CLI is in your PATH:
```bash
# Check if qmk is accessible
which qmk
qmk --version

# If not found, add to PATH (adjust path as needed)
export PATH=$PATH:~/.local/bin  # Linux
export PATH=$PATH:/usr/local/bin  # macOS
```

### Build Errors
```bash
# Clean build artifacts
make clean

# Update submodules
make git-submodules

# Verify QMK setup
qmk doctor
```
