@include std

service main()
    i=0 while i<10 @next i = i+1
    j=0 while j<10 @next j = j+1
        i:str:add(" "):add(j:str):print()
        if 5==i+j
            print("done") 
            ->>>-
    ------
