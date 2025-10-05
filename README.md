# smoλ

*A safe & fast low-level language.*

![logo](./docs/smol.png)

Declare zero-cost safe abstractions for structural and nominal data. Transpile to performant C.


**Dependencies:** GCC<br>
**Contact:** Emmanouil (Manios) Krasanakis<br>
**License:** Apache 2.0

## [Docs](https://smolambda.netlify.app/)

## Quickstart

Here's what smoλ programs look like.
<ul>
<li><code class="language-smolambda">def</code> functions are inlined and could fail. Results are treated as both tuples and types.
</li><li><code class="language-smolambda">service</code> functions safely deallocate resources on internal failure (e.g., of called def or other services). Result errors can be checked or -if not- cascade into more failures.
</li><li><code class="language-smolambda">nominal</code> references types by name for safety (aka nominally).
<li><code class="language-smolambda">@mut</code>, if prepended to the first declation of a variable, indicates values that may change.</li>
</li><li><code class="language-smolambda">.</code> is element access, or passes the left-hand-side as the first argument into functions ("currying"). Currying into a loop passes the value into first call in the condition; in this case <code class="language-smolambda">next(@mut chunks, @mut str)</code> is called to progress the iteration.
</li>
</ul>

```rust
@include std.core
@include std.mem
@include std.file

def Stats(
        nominal, // nominal type (prevents structural matching)
        u64 lines, 
        u64 chars
    )
    return @args // return all inputs

def print(file_stats stats)
    printin(stats.lines)
    printin(" lines, ")
    printin(stats.chars)
    print(" bytes")
    end

def file_reader(String path, @mut Memory memory) // for all String variations
    @mut stat_lines = 0
    @mut stat_chars = 0
    @mut file = ReadFile.open(path) // pass the ReadFile type as first argument
    endl = "\n".str().first
    on memory.arena(1024)
    file
    .while next_line(@mut str line)
        printin("| ")
        print(line)
        stat_lines = stat_lines + 1
        stat_chars = stat_chars + line:len
        end
    return nominal.Stats(stat_lines, stat_chars)

service main()
    @mut memory = Stack.arena(1048576) // 1MB
    stats = file_reader("README.md", memory)
    print(stats)
    end
```


## Licenses

Different parts of this codebase are governed by different licenses:

- std/: CC0
- Prism.js: MIT License (see `vendor/prism/LICENSE`)
- Everything else: Apache2.0