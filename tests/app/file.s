@include std.core
@include std.mem
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
    @mut ContiguousMemory memory
)
    @mut stat_lines = 0
    @mut stat_chars = 0
    @mut file = ReadFile.open(path)
    endl = "\n".str().first
    @on memory.arena()
    while file.next_line(@mut str line)
        stat_lines = stat_lines + 1
        stat_chars = stat_chars + line.len()
        printin("| ") // print without ending line
        print(line)
    fstats = new.file_stats(stat_lines, stat_chars)
    return fstats, memory

service main()
    @mut memory = Stack.allocate(1.MB())
    @access @mut stats = file_reader("README.md", memory)
    @mut mem = stats.memory
    stats2 = file_reader("README.md", mem)
    print(stats.fstats)
