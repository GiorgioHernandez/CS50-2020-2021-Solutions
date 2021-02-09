#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //Check usage
    if(argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }
    
    //Open File
    FILE *file = fopen(argv[1], "r");
    if(!file)
    {
        return 1;
    }
    
    
    unsigned char bytes[512];
    int count = 0; //number of files created
    char filename[8]; //buffer for the filename
    

    sprintf(filename, "%03d.jpg", count);
    FILE *img = fopen(filename, "w");
    
    //Read the first 4 bytes
    while(fread(bytes, 512, 1, file) >= 1)//when fread returns less than 512 is the end of the file
    {
    //checking the first 4 bytes
    if(bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3] & 0xf0) == 0xe0)
    {
        if(count == 0) //the first jpeg founded
        {
            count++;
            fwrite(&bytes, 512, 1, img);
        }
        
        else //there was another jpeg before, but this is a new one
        {
            fclose(img);
            sprintf(filename, "%03i.jpg", count);
            count++;
            img = fopen(filename, "a");
            fwrite(&bytes, 512, 1, img);
            
        }
        
    }
    
    else
    {
        if(count > 0) //this is part of the jpeg founded before
        {
            fwrite(&bytes, 512, 1, img);
        }
    }
    
    }    
    
    fclose(img);
    fclose(file);
    
}
