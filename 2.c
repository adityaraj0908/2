#include <stdio.h> 
#include <string.h> 
int main() { 
char filename[10],pattern[10],temp[200],res[100]; 
FILE *fp; 
printf("\n Enter file name:");  
scanf("%s",filename); 
printf("\n Enter the pattern:"); 
scanf("%s",pattern); 
fp=fopen(filename,"r");  
if(fp==NULL) 
{ 
  printf("\n Error opening file.\n"); 
  return 1;
} 

while(!feof(fp)) 
{ 
  fgets(temp,sizeof(temp),fp); 
  if(strstr(temp,pattern)) 

{
  printf("%s",temp); 
} 
}  
 
fclose(fp); 
return 0; 
} 
//ls 
#include <stdio.h> 
#include <stdlib.h> 
#include <dirent.h> 
int main(int argc, char *argv[]) { 
DIR *dir; 
struct dirent *entry; 
// Open the directory specified in the command-line argument or the current directory 
if (argc == 1) { 
dir = opendir("."); 
} else if (argc == 2) { 
dir = opendir(argv[1]); 
} else { 
printf("Usage: %s [directory]\n", argv[0]); 
return 1; 
} 
// Check if directory was opened successfully 
if (dir == NULL) {      
return 1; 
} 
  perror("Error"); 
// List directory contents 
printf("Contents of directory:\n"); 
while ((entry = readdir(dir )) != NULL) { 
printf("%s\n", entry->d_name); 
} 
// Close the directory 
closedir(dir); 
return 0; 
}
