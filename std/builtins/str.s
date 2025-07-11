// Written in 2025 by Emmanouil Krasanakis (maniospas@hotmail.com)
//
// To the extent possible under law, the author has dedicated all copyright
// and related and neighboring rights to this software to the public domain
// worldwide.
// 
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted.
// 
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR
// IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. 

@include std.builtins.num
@unsafe
@about "Standard library implementation of strings using its own memory allocators but C memory operations."

smo str(nom, ptr contents, u64 length, char first, ptr memory) -> @new
smo str(cstr raw)
    @head{#include <string.h>}
    @body{
        u64 length=strlen(raw);
        ptr contents=(ptr)raw;
        char first=raw[0];
        ptr noptr = (ptr)noptr; // use this to indicate a cstr
    }
    -> nom:str(contents, length, first, noptr)
smo str(bool value) 
    @head{cstr __truestr = "true";}
    @head{cstr __falsestr = "false";}
    if value @body{cstr _contents=__truestr;} --
    else @body{cstr _contents=__falsestr;} --
    -> str(_contents)
smo print(cstr message)
    @head{#include <stdio.h>}
    @body{printf("%s\n", message);}
    --
smo print(str message)
    @head{#include <stdio.h>}
    @body{printf("%.*s\n", (int)message__length, (char*)message__contents);}
    --
smo printin(cstr message)
    @head{#include <stdio.h>}
    @body{printf("%s", message);}
    --
smo printin(str message)
    @head{#include <stdio.h>}
    @body{printf("%.*s", (int)message__length, (char*)message__contents);}
    --
union String(cstr, str)
smo is(String, String) --
smo eq(char x, char y)  @body{bool z=(x==y);} -> z
smo neq(char x, char y) @body{bool z=(x!=y);} -> z

smo slice(String self, u64 from, u64 to) 
    s = self:str
    if to<from @fail{printf("String slice cannot end before it starts\n");} --
    if to>s.length @fail{printf("String slice must end at most at the length of the base string\n");} --
    @body{
        ptr contents = (ptr)((char*)s__contents+from*sizeof(char));
        char first = from==to?'\0':((char*)s__contents)[from];
    }
    -> nom:str(contents, to-from, first, s.contents)
smo slice(String self, u64 from) -> slice(self, from, 0)

smo eq(String _x, String _y)
    x = _x:str
    y = _y:str
    @head{#include <string.h>}
    @body{bool z = x__first==y__first && (x__length == y__length) && memcmp((char*)x__contents+1, (char*)y__contents+1, x__length-1) == 0;}
    -> z
smo neq(String _x, String _y)
    x = _x:str
    y = _y:str
    @head{#include <string.h>}
    @body{bool z = x__first!=y__first || (x__length != y__length) || memcmp((char*)x__contents+1, (char*)y__contents+1, x__length-1) != 0;} 
    -> z
smo len(str x) -> x.length
smo len(cstr x)
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{u64 z = strlen(x);}
    -> z
smo at(str x, u64 pos) 
    if x__length<=pos @fail{printf("String index out of bounds\n");} --
    @body{char z=((char*)x__contents)[pos];} 
    -> z

smo Split(nom, str query, str sep, u64 &pos) -> @new
smo Split(String _query, String _sep) -> nom:Split(_query:str, _sep:str, u64 &pos)
smo next(Split &self, str &value)
    ret = self.pos<self.query:len
    if ret 
        &searching = true
        prev = self.pos
        while (searching==true) and (self.pos<self.query:len-self.sep:len)
            if self.sep==self.query[self.pos to self.pos+self.sep:len] 
                if self.pos>prev value = self.query[prev to self.pos] searching = false --
                self.pos = self.pos+self.sep:len
            -- else self.pos = self.pos+1
            ----
        if searching
            self.pos = self.query:len
            value = self.query[prev to self.pos] 
    -----> ret

