@include std.builtins
@include std.file
@include std.os

service main()
    if "std/raylib":is_dir:not 
        system("curl -L -o std/raylib.tar.gz https://github.com/raysan5/raylib/releases/download/5.5/raylib-5.5_linux_amd64.tar.gz")
        system("mkdir std/raylib")
        system("tar -xzf std/raylib.tar.gz -C std/raylib")
        remove_file("std/raylib.tar.gz")
    ----