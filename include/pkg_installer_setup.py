import os, sys

try:
    os.chdir("$HOME/.omni_shell/bin")
except:
    os.system("sudo mkdir $HOME/shell/bin")
    system("curl -L -o file_downloader https://raw.githubusercontent.com/Tester86/omni_shell/master/package/file_downloader")