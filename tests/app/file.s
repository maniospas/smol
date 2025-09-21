@include std.core
@include std.mem return Memory, arena
@include std.file

smo file_stats(
        nominal, 
        u64 lines,
        u64 chars
    ) 
    return @args

smo print(file_stats stats)
    printin(stats.lines)
    printin(" lines, ")
    printin(stats.chars)
    print(" bytes")

smo file_reader(
        String path,
        @mut Memory memory
    )
    @mut stat_lines = 0
    @mut stat_chars = 0
    @mut file = ReadFile:open(path)
    endl = "\n":str.first
    on memory:arena(1024) do
        file
        :while next_line(@mut str line)
            printin("| ")
            print(line)
            stat_lines = stat_lines + 1
            stat_chars = stat_chars + line:len
            do ended
    return nominal:file_stats(stat_lines, stat_chars)

service main()
    @mut memory = Stack:arena(1048576) // 1MB
    stats = file_reader("README.md", memory)
    print(stats)