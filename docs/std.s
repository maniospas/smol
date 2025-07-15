@include std.builtins
@include std.math
@include std.rand
@include std.vec
@include std.time
@include std.mem
@include std.file
@include std.map
@include std.os

@about "This the documentation of smoλ's standard library. It is automatically kept up to date by periodically running the following command. "
       "That pulls from code annotations and overloaded implementations. <pre>./smol docs/std.s --task doc</pre>You may notice that lot of dependencies are marked as unsafe; this is "
       "not worrying but only indicates that extra trust should be placed on both the person writing the implementations because some of the language's "
       "safety features are turned off to bring to you low-level functionaltiy. "
       "<br><br>The following functionality that is ready to use without -or with minimal- external dependencies. It is organized into top-level "
       "files residing directly under <code>std/</code> and files under its subfolders. Do not import the latter by themselves to safe development speed. "
       "As a final remark, overloaded implementations are split per the file declaring them; foreign imports are not shown. Numbers in brackets "
       "indicate the number of structural primitive values."