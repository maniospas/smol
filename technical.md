# Smoλ implementation details

Since *smoλ* is a low-level language, there is a need for full understanding of implementation
details and the trade-offs of safe dynamic memory against unsafe code.

## Buffers

The buffer primitive implementation has a worst case overhead of adding an 1/16 overhead to total consumed memory compared to allocating data in the most efficient manner. This is because buffers keep track of the primitive types
of data stored inside in a shadow memory. This requires 4 bits to track each primitive type's internal id. Thanks to smoλ's inlining, it is often the case
that the shadow memory is optimized away.

Buffers are also tied to a default primitive type so that adding or removing
elements of that type does not incur any cost. The default type is that of the
first element. Type checks when popping from the front of buffers are only performed for other types of primitives.