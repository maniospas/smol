@include std

service main()
    i = 0
    while(i<=10) 
        if(i==2) print("Even "+str:from(i)) --
        else print("Odd  "+str:from(i)) --
        i = i+1
        --
