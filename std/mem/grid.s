// Written in 2025 by Emmanouil Krasanakis (maniospas@hotmail.com)
//
// To the extent possible under law, the author has dedicated all copyright
// and related and neighboring rights to this software to the public domain
// worldwide.
// 
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted.
// 
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR
// IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. 

@include std.mem.arena

smo MemoryGrid (
        nom type,
        Memory& memory,
        Primitive,
        u64 size, 
        u64 squares
    )
    surface = memory:allocate(size*squares, Primitive)
    -> type, surface, size, squares

smo GridEntry (
        nom,
        MemoryGrid &grid,
        u64 id
    ) 
    -> @new

smo at(MemoryGrid &self, u64 id) 
    -> nom:GridEntry(self, id)

smo at(GridEntry self, u64 pos) 
    true_pos = pos
    :mul(self.grid.squares)
    :add(self.id)
    -> self.grid.surface[true_pos]

smo put(GridEntry &self, u64 pos, Primitive value)
    with 
        Primitive:is(self.MemoryGrid.Primitive) 
        --
    true_pos = pos
    :mul(self.grid.squares)
    :add(self.id)
    self.grid.surface:__unsafe_put(true_pos, value)
    --

smo len(GridEntry self) 
    -> self.grid.size

smo new_grid(Memory& memory, u64 size, u64 squares, Primitive)
    -> nom:MemoryGrid(memory, Primitive, size, squares)