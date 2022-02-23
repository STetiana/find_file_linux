#include "find_file.h"

void search(const std::string &path, std::string filename)
{
    DIR *directory;   // creating pointer of type dirent
    struct dirent *x;   // pointer represent directory stream 

    if ((directory= opendir (path.c_str())) != NULL) //check if directory open 
    {      
  
        while ((x = readdir (directory)) != NULL) {

            if (!x->d_name || x->d_name[0] == '.') 
            {
                continue;
            }
            
            if(x->d_type == DT_DIR)  
            {
                search(path+"/"+x->d_name, filename);

            } else if(filename == x->d_name)
            {
                std::cout << path << "/" << x->d_name << std::endl;
                break;
            }
        }
    }
 
    closedir (directory); //close directory
  
}
