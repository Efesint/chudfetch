import psutil
import os 
import platform
import socket
import subprocess
import shutil
import getpass

# hell yea i rewrite this shit in python

username = getpass.getuser()
gr = "\033[32m"
wh = "\033[0m"

print("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠿⠿⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿", username, "@",platform.node())
print("⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠻⠿⣿⣿⣿⣿","- - - -")
print("⣿⣿⣿⣿⣿⣿⣿⣿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⡀⠀⢀⠀⠙⣿⣿","hardware model:", )
print("⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⣠⣴⣶⣶⣶⣶⣿⣿⣿⣿⣿⣿⣿⣷⡌⣿⣿","kernel:", platform.release()) 
print("⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⣴⣿⣿⣿⣿⣿⣿⣻⣿⣿⣿⡿⣿⣿⣿⣿⡜⣿","cpu:")
print("⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⢀⣿⣿⣿⣿⣿⣿⣿⣷⢿⣿⣿⣇⣿⣿⣿⣿⣧⣿","ram:",)
print("⣿⣿⣿⣿⣿⣿⣿⡇⡆⠀⠀⣸⣿⣯⡉⠙⠛⠿⣿⣿⢺⣿⣿⡇⢿⡿⠿⠛⠉⣿","ip",)
print("⣿⣿⣿⣿⣿⣿⣿⢁⡟⣀⣘⣛⣛⡛⢩⣤⣤⣤⣤⣀⠻⠿⠿⡇⢊⣀⣐⣚⡃⢻","uptime:",)
print("⣿⣿⣿⣿⣿⣿⣿⠸⣧⣽⣿⣿⣿⡇⢼⠰⠀⠈⠙⣻⠆⣾⣷⡆⢘⡋⠉⣽⡇⢸","disk:",)
print("⣿⣿⣿⣿⣿⣿⣿⡅⣿⣿⣿⣿⣿⣧⣬⣉⣂⣚⣛⢋⣠⣿⣿⣿⢀⡐⢀⢛⡃⣸","load:")
print("⣿⣿⣿⣿⣿⣿⣿⣧⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⡘⣿⣿⣿⡇⣿","processes:",)
print("⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⠩⡿⠛⢿⠿⢃⣿⣿⡿⢣⣿","gpu:",)
print("⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⡿⣿⣿⣿⣿⣿⡿⣸⡷⠾⠿⣿⢶⡇⣿⡿⣡⣿⣿","shell:",)
print("⣿⣿⣿⣿⣿⣿⣿⡿⢸⣿⣿⡇⣿⣿⣿⣿⣿⢣⣁⠬⣽⣿⣒⠓⣁⠿⣡⣿⣿⣿","term:",)
print("⣿⣿⣿⣿⣿⣿⣿⠇⣿⣿⣿⣵⣿⣿⣿⣿⣿⣿⣿⣷⢖⣉⢱⣾⡟⣴⣿⣿⣿⣿","date:",)
print("⣿⣿⣿⣿⣿⣿⢏⣾⣿⣿⢟⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⣋⣭⣾⣿⣿⣿⣿⣿","arch:",)
print("⣿⣿⡿⢟⣛⣁⣾⣿⣟⣣⣿⣿⣿⣿⣿⣿⣿⣿⣯⣯⣥⣿⣬⣝⣛⣛⣛⣛⡻⠿","mac",) 
print("⣶⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣭⣝⠻⠟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿")   
print("                              ") 
