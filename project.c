    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <string.h>
    int countnumber(char str[1000]);
    void replacesubstring(char str1[1000]);
    int alphabet(char r[1000]);
    int words(char s[1000]);
    int spechar(char str[1000]);
    void wordfinder(char str2[1000]);
    int revstr(char s[1000]);
    void revwordstr(char str[1000]);
    char str[1000];
    int choice;
    void string()
    {
        printf("\n Enter the string : ");
        gets(str);
    }
    void work()
    {
        do
        {
            printf("\n***************************************************MENU*******************************************************");
            printf("\n\n Choose the task which you want to perform:");
            printf("\n\t\t\t\t1) Count the number of digits.");
            printf("\n\t\t\t\t2) Replace a particular word by a particular word.");
            printf("\n\t\t\t\t3) Count the number of vowels and consonants.");
            printf("\n\t\t\t\t4) Count the number of words.");
            printf("\n\t\t\t\t5) Count the number of special symbols.");
            printf("\n\t\t\t\t6) Find the particular word.");
            printf("\n\t\t\t\t7) To reverse the whole string.");
            printf("\n\t\t\t\t8) To reverse the words of the string.");
            printf("\n\t\t\t\t9) To exit. \n\t\t\t\t Choose- ");
            scanf("\n%d", &choice);
            switch (choice)
            {
            case 1:
                countnumber(str);
                break;
            case 2:
                replacesubstring(str);
                break;
            case 3:
                alphabet(str);
                break;
            case 4:
                words(str);
                break;
            case 5:
                spechar(str);
                break;
            case 6:
                wordfinder(str);
                break;
            case 7:
                revstr(str);
                break;
            case 8:
                revwordstr(str);
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("\n Oops! Bad Request,Try Again");
                work();
            }
     
        } while (choice >= 0 && choice <= 9);
    }
     
    int main()
    {
        string();
        work();
    }
     
    int countnumber(char str[1000])
    {
        //char str[1000];
        int count = 0, j = 0;
        // fgets(str,10000,stdin);
        for (j = 0; str[j] != '\0'; ++j)
        {
            if (str[j] == '0' || str[j] == '1' || str[j] == '2' || str[j] == '3' || str[j] == '4' || str[j] == '5' || str[j] == '6' || str[j] == '7' || str[j] == '8' || str[j] == '9')
            {
                count++;
            }
        }
        printf("Total number of digits are: %d", count);
        return count;
    }
     
    void replacesubstring(char str1[])
    {
        int i, j, flag = 0, len1, len2, replaceLen, start, end;
        char substr[100], replace[20], temp[120], str[1000];
        //gets();
        //printf("Enter a string\n");
        gets(str);
        strcpy(str, str1);
        printf("Enter String to replace:\n");
        gets(substr);
        printf("Enter a substring to be replaced with:\n");
        gets(replace);
     
        len1 = strlen(str);
        len2 = strlen(substr);
        replaceLen = strlen(replace);
        strcpy(temp, str);
        for (i = 0; i <= len1 - len2; i++)
        {
            start = i;
            for (j = i; j < i + len2; j++)
            {
                flag = 1;
                if (str[j] != substr[j - i])
                {
                    flag = 0;
                    break;
                }
                else
                {
                    end = j;
                }
            }
            if (flag == 1)
                break;
        }
        if (flag == 1)
        {
            int k = 0;
            if (len2 == replaceLen)
            {
                for (i = 0; i < len1; i++)
                {
                    if (i >= start && i <= end)
                    {
                        str[i] = replace[k];
                        k++;
                    }
                }
            }
            if (replaceLen - len2 > 0)
            {
                for (i = 0; i < len1; i++)
                {
                    if (i >= start && i <= end)
                    {
                        str[i] = replace[k];
                        k++;
                    }
                }
                k = 0;
                int x;
                //Storing for continuing copy o remaining string in the original one
                x = end + 1;
     
                //For adding the remaining string left in replace
                for (i = 0; i < len1 + (replaceLen - len2); i++)
                {
                    if (i <= end)
                    {
                        temp[i] = str[i];
                    }
                    //from end of the substring to length of extra string in replace
                    if (i > end && i <= end + (replaceLen - len2))
                    {
                        temp[i] = replace[len2 + k];
                        k++;
                    }
                    if (i > end + (replaceLen - len2))
                    {
                        temp[i] = str[x++];
                    }
                }
                temp[i] = '\0';
                strcpy(str, temp);
            }
     
            if (replaceLen - len2 < 0)
            {
                int rem = end + (replaceLen - len2);
                for (i = 0; i < len1; i++)
                {
                    if (i >= start && i <= rem)
                    {
                        str[i] = replace[k];
                        k++;
                    }
                }
                k = 0;
                int x;
                //Storing for continuing copy o remaining string in the original one
                x = end + 1;
     
                //For adding the remaining string left in replace
                for (i = 0; i < len1 + (replaceLen - len2); i++)
                {
                    if (i <= end)
                    {
                        temp[i] = str[i];
                    }
     
                    if (i > end + (replaceLen - len2))
                    {
                        temp[i] = str[x++];
                    }
                }
                temp[i] = '\0';
                strcpy(str, temp);
            }
            printf("String After replacing is:\n%s\n", str);
        }
        else
        {
            printf("Entered Substring not Found!\n");
        }
    }
     
    int words(char s[])
    {
        int w = 0, i = 0;
        while (s[i] != '\0')
        {
            if (s[i] == ' ')
            {
                w++;
            }
            i++;
        }
     
        printf("Total number of words are: %d", w + 1);
        return w + 1;
    }
     
    int alphabet(char r[])
    {
        int vowels = 0, consonants = 0, i = 0;
        while (r[i] != '\0')
        {
            if (r[i] == 'a' || r[i] == 'e' || r[i] == 'i' || r[i] == 'o' || r[i] == 'u' || r[i] == 'A' || r[i] == 'E' || r[i] == 'I' || r[i] == 'O' || r[i] == 'U')
            {
                vowels++;
            }
            else if (r[i] == 'b' || r[i] == 'c' || r[i] == 'd' || r[i] == 'f' || r[i] == 'g' || r[i] == 'j' || r[i] == 'k' || r[i] == 'l' || r[i] == 'p' || r[i] == 'q' || r[i] == 'r' || r[i] == 's' || r[i] == 't' || r[i] == 'v' || r[i] == 'w' || r[i] == 'x' || r[i] == 'y' || r[i] == 'z' || r[i] == 'n' || r[i] == 'm' || r[i] == 'h' || r[i] == 'B' || r[i] == 'C' || r[i] == 'D' || r[i] == 'F' || r[i] == 'G' || r[i] == 'J' || r[i] == 'K' || r[i] == 'L' || r[i] == 'P' || r[i] == 'Q' || r[i] == 'R' || r[i] == 'S' || r[i] == 'T' || r[i] == 'V' || r[i] == 'W' || r[i] == 'X' || r[i] == 'Y' || r[i] == 'Z' || r[i] == 'N' || r[i] == 'H' || r[i] == 'M')
            {
     
                //if(r[i]=='B'||r[i]=='C'||r[i]=='D'||r[i]=='F'||r[i]=='G'||r[i]=='J'||r[i]=='K'||r[i]=='L'||r[i]=='P'||r[i]=='Q'||r[i]=='R'||r[i]=='S'||r[i]=='T'||r[i]=='V'||r[i]=='W'||r[i]=='X'||r[i]=='Y'||r[i]=='Z'||r[i]=='N'||r[i]=='H'||r[i]=='M')
     
                consonants++;
            }
            i++;
        }
        printf("\n Total number of vowels  = %d", vowels);
        printf("\n Total number of consonants = %d", consonants);
        return 0;
    }
    int spechar(char str[1000])
    {
        // char str[100];
        //printf("enter a string:");
        //gets(str);
     
        int i = 0, counter = 0;
        while (str[i] != '\0')
        {
            if (str[i] == '{' || str[i] == '=' || str[i] == '+' || str[i] == '_' || str[i] == '-' || str[i] == ')' || str[i] == '(' || str[i] == '*' || str[i] == '&' || str[i] == '^' || str[i] == '%' || str[i] == '$' || str[i] == '#' || str[i] == '@' || str[i] == '}' || str[i] == '/' || str[i] == '.' || str[i] == ',' || str[i] == ':' || str[i] == ';' || str[i] == '`' || str[i] == '~' || str[i] == '?' || str[i] == '!')
            {
                counter++;
            }
            i++;
        }
        printf("Total number of special symbols are: %d", counter);
        return counter;
    }
    void wordfinder(char str2[1000])
    {
     
        char word[100], str[1000];
        int i, j, Flag;
        gets(str);
        strcpy(str, str2);
        //printf("\n Please Enter any String :  ");
        //gets(str);
     
        printf("\n Please Enter the Word that you want to Search for :  ");
        gets(word);
     
        for (i = 0; str[i] != '\0'; i++)
        {
            if (str[i] == word[0])
            {
                Flag = 1;
                for (j = 0; word[j] != '\0'; j++)
                {
                    if (str[i + j] != word[j])
                    {
                        Flag = 0;
                        break;
                    }
                }
            }
            if (Flag == 1)
            {
                break;
            }
        }
        if (Flag == 0)
        {
            printf("\n Bad Request! We haven't found the Word '%s' ", word);
        }
        else
        {
            printf("\n We found '%s' at position %d ", word, i + 1);
        }
    }
     
    void revwordstr(char str[1000])
    {
        int i, j = 0, k = 0, x, len;
        char str1[10][20], temp;
     
        for (i = 0; str[i] != '\0'; i++)
        {
            if (str[i] == ' ')
            {
                str1[k][j] = '\0';
                k++;
                j = 0;
            }
            else
            {
                str1[k][j] = str[i];
                j++;
            }
        }
        str1[k][j] = '\0';
     
        /* reverses each word of a given string */
        for (i = 0; i <= k; i++)
        {
            len = strlen(str1[i]);
            for (j = 0, x = len - 1; j < x; j++, x--)
            {
                temp = str1[i][j];
                str1[i][j] = str1[i][x];
                str1[i][x] = temp;
            }
        }
        for (i = 0; i <= k; i++)
        {
            printf("%s ", str1[i]);
        }
    }
     
    int revstr(char s[1000])
    {
     
        char r[1000];
        int begin, end, count = 0;
     
        // printf("Input a string\n");
        //gets(s);
     
        // Calculating string length
     
        while (s[count] != '\0')
            count++;
     
        end = count - 1;
     
        for (begin = 0; begin < count; begin++)
        {
            r[begin] = s[end];
            end--;
        }
     
        r[begin] = '\0';
     
        printf("String after reversing the whole string is %s\n", r);
        return r;
    }
     
