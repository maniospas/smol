@include std.core
@include std.mem 
    return Memory, arena, MB
@include std.file 
    return File

def file_stats(
    new, 
    u64 lines,
    u64 chars
) 
    return @args

def print(file_stats stats)
    printin(stats.lines)
    printin(" lines, ")
    printin(stats.chars)
    print(" bytes")

def file_reader(
    String path,
    @mut Memory memory
)
    @mut stat_lines = 0
    @mut stat_chars = 0
    @mut file = ReadFile.open(path)
    endl = "\n".str().first
    @on memory.allocate(1024).arena()
    while file.next_line(@mut str line) 
        stat_lines = stat_lines + 1
        stat_chars = stat_chars + line.len()
        printin("| ") // print without ending line
        print(line)
    return new.file_stats(stat_lines, stat_chars)

service main()
    @mut memory = Stack.allocate(1.MB()).arena() // 1MB
    stats = file_reader("README.md", memory)
    print(stats)
