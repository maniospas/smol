@include std.core
@include std.mem
@include std.time
@include std.rand

def SortRange(u64 lo, u64 hi)
    return @args

def swap(@mut f64[] arr, u64 i, u64 j)
    tmp = arr[i]
    arr[i] = arr[j]
    arr[j] = tmp

def partition(@mut f64[] arr, u64 lo, u64 hi)
    pivot = arr[hi]
    @mut i = lo
    @mut j = lo
    while j < hi
        if arr[j] < pivot
            arr.swap(i, j)
            i = i + 1
        j = j + 1
    arr.swap(i, hi)
    return i

def quicksort(@mut SortRange[] stack, @mut f64[] arr)
    r = stack.pop()
    if r.lo >= r.hi
        return false
    p = arr.partition(r.lo, r.hi)

    @mut left_valid = false
    @mut left_lo = 0
    @mut left_hi = 0
    if p > r.lo
        left_lo = r.lo
        left_hi = p - 1
        left_valid = true

    @mut right_valid = false
    @mut right_lo = 0
    @mut right_hi = 0
    if p < r.hi
        right_lo = p + 1
        right_hi = r.hi
        right_valid = true

    left_size = algorithm
        if left_valid 
            return (left_hi+1) - left_lo
        return 0

    right_size = algorithm
        if right_valid
            return (right_hi + 1) - right_lo
        return 0

    if left_size < right_size
        if right_valid  stack = stack.push(SortRange(right_lo, right_hi))
        if left_valid   stack = stack.push(SortRange(left_lo, left_hi))
    else
        if left_valid   stack = stack.push(SortRange(left_lo, left_hi))
        if right_valid  stack = stack.push(SortRange(right_lo, right_hi))
        
    return true

service main()
    @mut noopt = 0.0
    @mut accum = 0.0
    rand = Rand()
    ITER = 100
    N = 100000
    range(ITER)
    .while next(@mut u64 repetitions)
        @mut arr = f64[]
        range(N)
        .while next(@mut u64 r)
            arr.push(rand.next())
        tic = time()

        @mut stack = SortRange[].push(SortRange(0, arr.len() - 1))
        while stack.len().bool()
            stack.quicksort(arr)
        accum = accum + time() - tic
        noopt = noopt + arr[0] // prevent optimizations
    
    printin(accum*1000.0/ITER.f64())
    print(" ms")