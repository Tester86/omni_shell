#include <unistd.h>
#include <iostream>
#include <dirent.h>
#include <vector>
#include <sys/types.h>
#include <string>
#include <time.h>

using namespace std;

vector<string> listdir();
void install_pkg(string pkg_link, string filename);
const char* pwd();
void getTime(char* queries[]);

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

void install_pkg(string pkg_link, string filename){

  string cmd = "cd $HOME/.omni_shell/bin && sudo ./file_downloader " + pkg_link + " " + filename;
  string decompress = "sudo tar -zxvf " + filename + " sudo chmod +x " + filename;
  system(cmd.c_str());
  system(decompress.c_str());

}

const char* pwd(){
  string curdir(get_current_dir_name());
  curdir += " > ";
  return curdir.c_str();
}