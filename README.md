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
<li><code class="language-smolambda">smo</code> are inlined and could fail. Results are treated as both tuples and types.
</li><li><code class="language-smolambda">service</code> denotes functions that, on internal failure (e.g., of called smo or other services), safely deallocate resources. Result errors can be checked or -if not- cascade into more failures.
</li><li><code class="language-smolambda">nom</code> needed for calls whose results is attached to a specific name for safety (nominal type).
</li><li><code class="language-smolambda">:</code> passes the left-hand-side as the first argument ("currying"). <code class="language-smolambda">()</code> is ommitted. Currying into a loop passes the value into first call in the condition; in this case <code class="language-smolambda">next(chunks&, str&)</code> is called to progress the iteration.
</li>
<li><code class="language-smolambda">&</code> if prepended to the first variable assignment indicates mutable variables that can be overwriten.</li>
<li><code class="language-smolambda">--,-></code> are code block ends and returns respectively.</li>
</ul>

```rust
@include std.core
@include std.mem
@include std.file

smo Stats(
        nominal, // nominal type (prevents structural matching when used as argument)
        u64 lines, 
        u64 chars
    )
    -> @args // return all inputs

smo print(file_stats stats)
    printin(stats.lines)
    printin(" lines, ")
    printin(stats.chars)
    print(" bytes")
    --

smo file_reader(String path, @mut Memory memory)
    &stat_lines = 0
    &stat_chars = 0
    &file = ReadFile:open(path) // the ReadFile type as the first argument to open
    endl = "\n":str.first
    on memory:arena(1024)
        file
        :while next_line(str &line)
            printin("| ")
            print(line)
            stat_lines = stat_lines + 1
            stat_chars = stat_chars + line:len
    -- -- -> nominal:Stats(stat_lines, stat_chars)

service main()
    &memory = Stack.arena(1048576) // 1MB
    stats = file_reader("README.md", memory)
    print(stats)
    --
```


## Licenses

Different parts of this codebase are governed by different licenses:

- std/: CC0
- Prism.js: MIT License (see `vendor/prism/LICENSE`)
- Everything else: Apache2.0