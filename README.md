# smoλ

*A safe & fast low-level language.*

![logo](./docs/smol.png)

**Dependencies:** Make, GCC (can also work with other compilers like Clang or TCC)<br>
**Contact:** Emmanouil (Manios) Krasanakis<br>
**License:** Apache 2.0

## [Docs](https://smolambda.netlify.app/)

## Quickstart

Here's what smoλ programs look like. Syntax is indentation-based.
<ul>
<li><code class="language-smolambda">def</code> functions are inlined and could fail. Results are treated as both tuples and types.
</li><li><code class="language-smolambda">service</code> functions safely deallocate resources on internal failure (e.g., of called def or other services). Result errors can be checked or -if not- cascade into more failures.
</li><li><code class="language-smolambda">new</code> references types by name for safety (aka nominal typing).
</li><li><code class="language-smolambda">@on</code> automatically add as first argument (even before currying).
<li><code class="language-smolambda">@mut</code>, if prepended to the first declaration of a variable, indicates values that may change.</li>
</li><li><code class="language-smolambda">.</code> is element access, or passes the left-hand-side as the first argument into functions ("currying"). Currying into a loop passes the value into first call in the condition; in this case <code class="language-smolambda">next(@mut chunks, @mut str)</code> is called to progress the iteration.
</li>
</ul>

```rust
@include std.core
@include std.mem
@include std.file

def Stats(
    new, // new type (prevents structural matching)
    u64 lines, 
    u64 chars
)
    return @args // return all inputs

def print(file_stats stats)
    // @all to use printin (print without \n ending) to reduce expressions 
    // no commas in this syntax makes it look like string interpolation
    printin(@all stats.lines" lines, "stats.chars" bytes\n")

def file_reader(String path, @mut Memory memory) // for all String variations
    @mut stat_lines = 0
    @mut stat_chars = 0
    @mut file = ReadFile.open(path) // pass the ReadFile type as first argument
    endl = "\n".str().first
    @on memory.allocate(1.KB()).arena()
    file
    .while next_line(@mut str line)
        stat_lines = stat_lines + 1
        stat_chars = stat_chars + line:len
        printin("| ")
        print(line)
    return new.Stats(stat_lines, stat_chars)

service main()
    @mut memory = Stack.allocate(1.MB()).arena()
    stats = file_reader("README.md", memory)
    print(stats)
```


## Licenses

Different parts of this codebase are governed by different licenses:

- std/: CC0
- Prism.js: MIT License (see `vendor/prism/LICENSE`)
- Everything else: Apache2.0
