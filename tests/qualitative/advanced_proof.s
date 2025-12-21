// ----- PEANO DEFINITION OF NATURALS ------

// predicates of discourse
@about EmptySet "The empty set with no elements. Serves also as the False predicate."
def EmptySet(new)
    return @args 

@about Zero "The first natural number."
def Zero(new) 
    return @args

@about Natural "A natural number."
def Natural(new) 
    return @args

@about Next "The next of a natural number. Since Naturals are lexically scoped in signatures, the Next refers to the unique natural number there."
def Next(new, Natural previous) 
    return @args

@about All "The set of all natural numbers."
def All(new, Natural set)
    return @args

@about Set "The category of all sets (just includes all defined sets here)."
union Set = EmptySet or Zero or Natural or Next or All

// properties (includes tautology within Set)
def is(Set, Set)
def is(Zero, Natural)

def is(Next next, Natural) 
    case next.previous.is(Natural)
    case @invalid "Modeling the next natural"
    qed

def in(Natural, All all)
    case all.set.is(Natural)
    case @invalid "Modeling only all naturals"
    qed

// state the rule of induction (rules return - we are interested in return type)
union AnotherSet = Set

def implies(new, Set prev, AnotherSet next)
    return @args
    
union AnotherImplies = implies
    
def induction(implies starting, AnotherImplies progress)
    case 
        starting.prev.is(EmptySet)
        starting.next.is(Zero)
        progress.prev.is(Natural)
        progress.next.previous.is(Natural)
        ret = new.All(Natural)
    case 
        ret = EmptySet
    qed
    return ret

// ----- PROOF THAT ALL NATURALS >= 0 ------

// define geq operation 
@about geq "Its value exists if the the first argument is greater than or equal to the second argument."
def geq(Zero, Zero)
    return new.implies(EmptySet, Zero)
    
def geq(Next lhs, Natural rhs)
    case lhs.previous.is(Natural)
    case @invalid "Modeling the next natural"
    qed
    return new.implies(rhs, lhs)

// prove that all naturals >= 0
service main()
    induction(
        geq(Zero, Zero), 
        geq(new.Next(Natural), Natural)
    ).is(new.All(Natural))
