#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

int main(int argc, string argv[])
{
    // Key Validation
    
    if(argc < 2) //No Key Inserted
    {
        printf("Usage: ./substitution KEY\n");
        return 1; //Error
    }
    
    if(strlen(argv[1]) != 26) // Wrong Key Length
    {
        printf("Key must contain 26 characters\n");
        return 1; //Error
    }
    
    string key = argv[1]; //stablishing Key in other string
    
    for(int i = 0; i < 26; i++) 
    {
        if(isalpha(key[i]) == false) // Non Alphabetic Character Detection
        {
            printf("Key only contain alphabetic characters\n");
            return 1; //Error
        }
        
        for(int j = i+1; j < 26; j++) // Comparing the current character with the others
        {
            if(key[i] == key[j])
            {
                printf("Key must not contain repeated characters\n");
                return 1; //Error
            }
        }
        
        key[i] = toupper(key[i]); // converting the key to uppercase
    } // End of Key Validation
    
    // Enciphering
    
    string plain = get_string("Plaintext: ");
    string reference = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    printf("ciphertext: ");
    
    for(int k = 0; k < strlen(plain); k++)
    {
        if(isalpha(plain[k]))
        {
            for(int l = 0; l < 26; l++)
            { 
                if(toupper(plain[k]) == reference[l]) // comparing the current char to the reference
                {
                    if(isupper(plain[k])) //print the cipher code in uppercase
                    {
                        printf("%c", key[l]);
                    }
                    else // print the cipher code in lowercase
                    {
                        
                        printf("%c", key[l]+32);
                    }
                    
                }
            }
        }
        
        else 
        {
            printf("%c", plain[k]);
        }
    }
    
    printf("\n");
    return 0;
}