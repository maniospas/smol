@include std.builtins.num
@include std.builtins.str

smo read(i64)
    @head{#include <stdio.h>}
    @body{
        i64 number = 0;
        char ch = 0;
        i64 result = scanf("%ld%c", &number, &ch);
        bool success = (result == 2 && ch == '\n');
    }
    if success:not @fail{printf("Error: invalid integer read\n");} --
    -> number

smo read(u64)
    @head{#include <stdio.h>}
    @body{
        u64 number = 0;
        char ch = 0;
        bool success = false;
        char first = getchar();
        if (first != '-' && first != EOF) {
            ungetc(first, stdin);
            i64 result = scanf("%lu%c", &number, &ch);
            success = (result == 2 && ch == '\n');
        }
    }
    if success:not @fail{printf("Error: invalid unsigned integer read\n");} --
    -> number

smo read(f64)
    @head{#include <stdio.h>}
    @body{
        f64 number = 0;
        char ch = 0;
        i64 result = scanf("%lf%c", &number, &ch);
        bool success = (result == 2 && ch == '\n');
    }
    if success:not @fail{printf("Error: invalid number read\n");} --
    -> number

smo read(str)
    @head{#include <stdio.h>}
    @head{#include <stdlib.h>}
    @body{
        ptr _contents = malloc(1024);
        if(_contents && fgets((char*)_contents, 1024, stdin)) {
            u64 length = strlen((char*)_contents);
            if(length > 0 && ((char*)_contents)[length - 1] == '\n') {
                length -= 1;
                ((char*)_contents)[length] = '\0';
                char first = ((char*)_contents)[0];
            }
        }
        else if(_contents) {free(_contents);_contents=0;}
    }
    @finally _contents {if(_contents)free(_contents);_contents=0;}
    if(_contents:exists:not) @fail{printf("Failed to read str of up to 1023 characters\n");} --
    -> nom:str(_contents, length, first, _contents)