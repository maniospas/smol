@include std.core
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
       "As a final remark, overloaded implementations are split per the file declaring them; foreign imports are not shown. "
       "<br><br><code>@mut</code> indicates mutability. If this is absent, the language promises to not modify values "
       "- the standard library promises to respect that too when considering whether it is allowed to modify pointer contents.<br><br>"
       "<code>@access</code> indicates that arguments can view mutable fields, though not necessarily edit them. This marking also "
       "imports the runtype together with the argument's runtype, if these are found in the same import file. For example, the following "
       "snippet imports all numeric but not string operations from the standard library's core: <pre>@import std.core -> Number</pre>"