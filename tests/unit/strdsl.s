@include std.core
@include std.mem

def StrDSL(nominal, str[] elements)
    if elements.len()>=8
        fail("Up to 8 base strings are allowed")
        end
    return @args

def Map(nominal, StrDSL dsl)
    @mut values = u64[].expect(512)
    return @args, values

def StrDSLString(nominal, StrDSL dsl, u64[] indexes)
    if indexes.len()>=4
        fail("String too complicated")
        end
    return @args

def str(StrDSL dsl, u64[] indexes)
    return nominal.StrDSLString(dsl, indexes)

def print(StrDSLString s)
    s
    .indexes
    .len()
    .range()
    .while next(@mut u64 i)
        printin(s.dsl.elements[s.indexes[i]])
        end
    print("")
    end


service main()
    dsl = nominal.StrDSL(str[]
        .push(str("my"))
        .push(str("name"))
        .push(str("is"))
        .push(str("manios"))
        .push(str("kate"))
        .push(str("who"))
        .push(str("?"))
        .push(str("."))
    )

    s = dsl.str(u64[].push(0).push(1).push(2).push(4))
    print(s.indexes.len())

    end