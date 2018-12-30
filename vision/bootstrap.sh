#!/bin/sh

# Install required packages
sudo apt-get update
sudo apt-get install -y avahi-daemon libnss-mdns v4l-utils

# Add vision user and password
sudo adduser vision --disabled-password --gecos ""
sudo adduser vision sudo
sudo usermod --password curtinfrc vision

# Enable password-less sudo for everyone
echo "%sudo ALL=(ALL) NOPASSWD:ALL" | sudo tee -a /etc/sudoers

# Set hostname, user and password
echo curtinvision | sudo tee /etc/hostname

# Reboot to commit changes
sudo reboot