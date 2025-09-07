# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Repository Overview

This repository contains QMK firmware keymaps for Keychron keyboards, specifically custom configurations for:
- **keychron_v1_max**: 83-key wireless keyboard with encoder knob (ISO layout)
- **keychron_k8_pro**: TKL wireless keyboard (ISO layout)

Each keyboard directory contains the standard QMK keymap files: `keymap.c`, `config.h`, `rules.mk`, and `README.md`.

## Build Commands

### Setup QMK Environment
```bash
# Install QMK CLI
sudo apt install -y python3-pip pipx
pipx install qmk
export PATH=$PATH:/home/claus/.local/bin

# Clone Keychron's QMK fork
cd ~/git
git clone -b wireless_playground --single-branch \
  git@github.com:Keychron/qmk_firmware.git

# Setup QMK
cd qmk_firmware
qmk setup
qmk hello
```

### Link Keymaps
```bash
# Link keymap directories to QMK firmware
ln -s ~/git/qmk-keymaps/keychron_k8_pro \
  keyboards/keychron/k8_pro/iso/rgb/keymaps/cloonix
ln -s ~/git/qmk-keymaps/keychron_v1_max \
  keyboards/keychron/v1_max/iso_encoder/keymaps/cloonix
```

### Build Keymaps
```bash
# Build K8 Pro keymap
make keychron/k8_pro/iso/rgb:cloonix

# Build V1 Max keymap  
make keychron/v1_max/iso_encoder:cloonix
```

## Architecture

### Layer Structure
Both keymaps use similar multi-layer architecture:
- `MAC_BASE` (0): Base macOS layout (DIP switch position dependent)
- `MAC_FN` (1): macOS function layer
- `WIN_BASE` (2): Base Windows layout 
- `WIN_FN` (3): Windows function layer
- `MAC_FN2` (4): Extended macOS functions
- `WIN_FN2` (5): Extended Windows functions
- `GAME` (6): Gaming layer (K8 Pro only)

### Key Features
- **Tap Dance**: Custom tap/hold behaviors for PRINT and SPACE keys
- **Leader Key**: QK_LEAD for command sequences
- **Layer Tap**: LCAG_T(KC_CAPS) for Caps Lock with modifier combo
- **RGB Control**: Extensive RGB matrix customization with most effects disabled for performance
- **Wireless Features**: Bluetooth host switching, battery level display

### Configuration Customizations
- Dynamic keymap layer counts: 6 layers (V1 Max), 8 layers (K8 Pro)
- RGB matrix effects mostly disabled except solid colors and select animations
- Leader key and tap dance features enabled
- LTO (Link Time Optimization) enabled for smaller firmware size

### File Structure
```
keyboard_name/
├── keymap.c     # Main keymap definition and tap dance logic
├── config.h     # RGB matrix and timing configurations  
├── rules.mk     # Build rules and feature enables
└── README.md    # Keyboard-specific documentation
```

The keymaps include advanced QMK features like tap dance state machines, leader key functionality, and extensive wireless keyboard support specific to Keychron's firmware fork.