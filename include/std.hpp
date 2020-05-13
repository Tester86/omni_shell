#include <unistd.h>
#include <iostream>
#include <dirent.h>
#include <vector>
#include <sys/types.h>
#include <string>

using namespace std;

vector<string> listdir(){
  vector<string> names;
  string name;
  DIR *dp;
  struct dirent *ep;  
  dp = opendir ("./");

  if (dp != NULL)
  {
    while (ep = readdir (dp)){
      name = ep->d_name;
      if(name.rfind(".", 0)!=0){
      names.push_back(ep->d_name);
  }
}
    (void) closedir (dp);
  }
  return names;
}

int cd(char* path){

    int exit_code = chdir(path);
    
    if(exit_code == -1){
        printf("This directory does not exist: %s", path);
    }
}

void install_pkg(string pkg_link, string filename){

  string cmd = "./file_downloader " + pkg_link + " " + filename;
  if(cd("$HOME/.omni_shell/bin") == 0){
    system(cmd.c_str());
  } else{
    system("sudo mkdir $HOME/.omni_shell");
    system("sudo mkdir $HOME/.omni_shell/bin");
    system("cd $HOME/.omni_shell/bin");
    system("curl -L -o file_downloader https://raw.githubusercontent.com/Tester86/omni_shell_hosted/master/bin/file_downloader || sudo wget -L -o file_downloader https://raw.githubusercontent.com/Tester86/omni_shell_hosted/master/bin/file_downloader");
    system(cmd.c_str());
  }

}