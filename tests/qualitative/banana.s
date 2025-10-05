@include std.core


service main()
    @mut s = Split("Me? I like bananas!", " ")
    s.while next(@mut str word)
        printin("word: ")
        then print(word)
