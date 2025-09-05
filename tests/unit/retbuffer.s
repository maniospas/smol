@include std.builtins


smo strbuf(nom, str[] &ref)
    -> @struct

smo strbuf(String value)
    -> nom:strbuf(str[]:push(value:str))

smo put(strbuf &buf, String value)
    -> buf.ref:put(0, value:str)

smo str(strbuf &buf) 
    -> buf.ref[0]:str

service main()
    &boxes = strbuf[]  // must be mutable to grant mutable access
    :push("first element":strbuf)
    :push("second element":strbuf)
    &b = boxes[0]
    // the line bellow is fancier than b:put("overwritten element")
    on b 
        -> "overwritten element":put 
    print(b:str)
    --